static float last_l  = 0;
static float last_r = 0;

const float LEFT_NORM = LEFT_ANCHOR_X * LEFT_ANCHOR_X + LEFT_ANCHOR_Y * LEFT_ANCHOR_Y;
const float RIGHT_NORM = RIGHT_ANCHOR_X * RIGHT_ANCHOR_X + RIGHT_ANCHOR_Y * RIGHT_ANCHOR_Y;
const float LEFT_TO_RIGHT = RIGHT_ANCHOR_X - LEFT_ANCHOR_X;


/*
This function is used as a one time setup for your machine.
*/
void machine_init() {}

/*
This is used to initialize a display.
*/
void display_init() {}

/*
  limitsCheckTravel() is called to check soft limits
  It returns true if the motion is outside the limit values
*/
bool limitsCheckTravel() {
    return false;
}

/*
  user_defined_homing(uint8_t cycle_mask) is called at the begining of the normal Grbl_ESP32 homing
  sequence.  If user_defined_homing(uint8_t cycle_mask) returns false, the rest of normal Grbl_ESP32
  homing is skipped if it returns false, other normal homing continues.  For
  example, if you need to manually prep the machine for homing, you could implement
  user_defined_homing(uint8_t cycle_mask) to wait for some button to be pressed, then return true.
*/
bool user_defined_homing(uint8_t cycle_mask) {
    // True = done with homing, false = continue with normal Grbl_ESP32 homing
    return true;
}

/*
  Inverse Kinematics converts X,Y,Z cartesian coordinate to the steps
  on your "joint" motors.  It requires the following three functions:
*/

/*
  cartesian_to_motors() converts from cartesian coordinates to motor space.

  Grbl_ESP32 processes arcs by converting them into tiny little line segments.
  Kinematics in Grbl_ESP32 works the same way. Search for this function across
  Grbl_ESP32 for examples. You are basically converting cartesian X,Y,Z... targets to

    target = an N_AXIS array of target positions (where the move is supposed to go)
    pl_data = planner data (see the definition of this type to see what it is)
    position = an N_AXIS array of where the machine is starting from for this move
*/
bool cartesian_to_motors(float* target, plan_line_data_t* pl_data, float* position) {
    grbl_sendf(CLIENT_SERIAL, "cartesian_to_motors\r\n");

    float    dx, dy, dz;          // distances in each cartesian axis
    float    p_dx, p_dy, p_dz;    // distances in each polar axis
    uint32_t segment_count;       // number of segments the move will be broken in to.
    float    wall[N_AXIS];       // target location in polar coordinates

    // offset from machine coordinate system
    float    x_offset = gc_state.coord_system[X_AXIS] + gc_state.coord_offset[X_AXIS];  
    float    y_offset = gc_state.coord_system[Y_AXIS] + gc_state.coord_offset[Y_AXIS];  
    float    z_offset = gc_state.coord_system[Z_AXIS] + gc_state.coord_offset[Z_AXIS];  

    grbl_sendf(CLIENT_SERIAL, "Position: (%4.2f %4.2f %4.2f) \r\n", position[X_AXIS], position[Y_AXIS], position[Z_AXIS]);
    grbl_sendf(CLIENT_SERIAL, "Target: (%4.2f %4.2f %4.2f) \r\n", target[X_AXIS], target[Y_AXIS], target[Z_AXIS]);
    
    // calculate cartesian move distance for each axis
    dx = target[X_AXIS] - position[X_AXIS];
    dy = target[Y_AXIS] - position[Y_AXIS];
    dz = target[Z_AXIS] - position[Z_AXIS];

    // calculate the total X,Y axis move distance
    // Z axis is the same in both coord systems, so it is ignored
    float dist = sqrt((dx * dx) + (dy * dy) + (dz * dz));
    if (pl_data->motion.rapidMotion) {
        segment_count = 1;  // rapid G0 motion is not used to draw, so skip the segmentation
    } else {
        segment_count = ceil(dist / SEGMENT_LENGTH);  // determine the number of segments we need	... round up so there is at least 1
    }
    
    dist /= segment_count;  // segment distance
    for (uint32_t segment = 1; segment <= segment_count; segment++) {
        // determine this segment's target
        float seg_x = position[X_AXIS] + (dx / float(segment_count) * segment);
        float seg_y = position[Y_AXIS] + (dy / float(segment_count) * segment);
        float seg_z = position[Z_AXIS] + (dz / float(segment_count) * segment);

        // seg_x -= x_offset;
        // seg_y -= y_offset;
        seg_z -= z_offset;

        float seg_r = seg_x * seg_x + seg_y * seg_y;

        wall[LEFT_AXIS] = sqrt(seg_r + LEFT_NORM - 2 * LEFT_ANCHOR_X * seg_x - 2 * LEFT_ANCHOR_Y * seg_y);
        wall[RIGHT_AXIS] = sqrt(seg_r + RIGHT_NORM - 2 * RIGHT_ANCHOR_X * seg_x - 2 * RIGHT_ANCHOR_Y * seg_y);
        wall[Z_AXIS] = seg_z;
        grbl_sendf(CLIENT_SERIAL, "Wall Axis: (%4.2f %4.2f)\r\n", wall[LEFT_AXIS], wall[RIGHT_AXIS]);

        // begin determining new feed rate
        // calculate move distance for each axis
        p_dx = wall[LEFT_AXIS] - last_l;
        p_dy = wall[RIGHT_AXIS] - last_r;
        p_dz = dz;

        // feed_rate
        float wall_rate_multiply = 1.0;     
            if ((p_dx == 0 && p_dy == 0) || dist == 0) {
            // prevent 0 feed rate and division by 0
            wall_rate_multiply = 1.0;  // default to same feed rate
        } else {
            // calc a feed rate multiplier
            wall_rate_multiply = (p_dx + p_dy) / (2 * dist);
            if (wall_rate_multiply < 0.5) {
                // prevent much slower speed
                wall_rate_multiply = 0.5;
            }
        }
        pl_data->feed_rate *= wall_rate_multiply;  // apply the distance ratio between coord systems

        // end determining new feed rate
        // wall[LEFT_AXIS] += x_offset;
        // wall[RIGHT_AXIS] += y_offset;
        wall[Z_AXIS] += z_offset;

        // mc_line() returns false if a jog is cancelled.
        // In that case we stop sending segments to the planner.
        if (!mc_line(wall, pl_data)) {
            return false;
        }

        //
        last_l = wall[LEFT_AXIS];
        last_r  = wall[RIGHT_AXIS];
    }
    // TO DO don't need a feedrate for rapids
    return true;
}

/*
  kinematics_pre_homing() is called before normal homing
  You can use it to do special homing or just to set stuff up

  cycle_mask is a bit mask of the axes being homed this time.
*/
bool kinematics_pre_homing(uint8_t cycle_mask) {
    return false;  // finish normal homing cycle
}

/*
  kinematics_post_homing() is called at the end of normal homing
*/
void kinematics_post_homing() {
    grbl_sendf(CLIENT_SERIAL, "kinematics_post_homing\r\n");

    last_l = 0;
    last_r = 0;
}

/*
  The status command uses motors_to_cartesian() to convert
  your motor positions to cartesian X,Y,Z... coordinates.

  Convert the N_AXIS array of motor positions to cartesian in your code.
*/
void motors_to_cartesian(float* cartesian, float* motors, int n_axis) {
    float ml = motors[LEFT_AXIS];
    float mr = motors[RIGHT_AXIS];

    grbl_sendf(CLIENT_SERIAL, "cartesian_to_motors: (%4.2f, %4.2f)\r\n", ml, mr);


    float sl = LEFT_TO_RIGHT / 2  - (mr * mr + ml * ml) / (2 * LEFT_TO_RIGHT);

    cartesian[X_AXIS] = LEFT_ANCHOR_X + sl;
    cartesian[Y_AXIS] = LEFT_ANCHOR_Y - sqrt(ml * ml - sl * sl);

    grbl_sendf(CLIENT_SERIAL, "cartesian: (%4.2f, %4.2f)\r\n", cartesian[X_AXIS], cartesian[Y_AXIS]);
}

/*
  user_tool_change() is called when tool change gcode is received,
  to perform appropriate actions for your machine.
*/
void user_tool_change(uint8_t new_tool) {}

/*
  options.  user_defined_macro() is called with the button number to
  perform whatever actions you choose.
*/
void user_defined_macro(uint8_t index) {}

/*
  user_m30() is called when an M30 gcode signals the end of a gcode file.
*/
void user_m30() {}

// If you add any additional functions specific to your machine that
// require calls from common code, guard their calls in the common code with
// #ifdef USE_WHATEVER and add function prototypes (also guarded) to grbl.h
