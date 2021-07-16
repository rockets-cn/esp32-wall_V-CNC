
#pragma once

#define MACHINE_NAME "WALL_V_CNC"

// This causes the custom code file to be included in the build
// via ../custom_code.cpp
#define CUSTOM_CODE_FILENAME "Custom/wall_v.cpp"

#define SPINDLE_TYPE SpindleType::NONE

#define LEFT_AXIS 0
#define RIGHT_AXIS 1

// 左右固定点坐标 
#define LEFT_ANCHOR_X -400
#define RIGHT_ANCHOR_X 400
#define LEFT_ANCHOR_Y 300
#define RIGHT_ANCHOR_Y 300

#define SEGMENT_LENGTH 10 // in mm

#define X_STEP_PIN              GPIO_NUM_25
#define X_DIRECTION_PIN         GPIO_NUM_26
#define Y_STEP_PIN              GPIO_NUM_14
#define Y_DIRECTION_PIN         GPIO_NUM_13
#define Z_STEP_PIN              GPIO_NUM_16
#define Z_DIRECTION_PIN         GPIO_NUM_4


#define STEPPERS_DISABLE_PIN    GPIO_NUM_17

// #define Z_SERVO_PIN             GPIO_NUM_16

//#define X_LIMIT_PIN             GPIO_NUM_36
//#define Y_LIMIT_PIN             GPIO_NUM_39
//#define Z_LIMIT_PIN             GPIO_NUM_34


#define SPINDLE_TYPE SpindleType::NONE

#ifndef ENABLE_CONTROL_SW_DEBOUNCE
    #define ENABLE_CONTROL_SW_DEBOUNCE
#endif

#ifdef CONTROL_SW_DEBOUNCE_PERIOD
    #undef CONTROL_SW_DEBOUNCE_PERIOD
#endif
#define CONTROL_SW_DEBOUNCE_PERIOD 100 // really long debounce

#ifdef INVERT_CONTROL_PIN_MASK
    #undef INVERT_CONTROL_PIN_MASK
#endif
#define INVERT_CONTROL_PIN_MASK B11111111
/*
#define MACRO_BUTTON_0_PIN      GPIO_NUM_13
#define MACRO_BUTTON_1_PIN      GPIO_NUM_12
#define MACRO_BUTTON_2_PIN      GPIO_NUM_14
*/

// ============= End CPU MAP ==================

// ============= Begin Default Settings ================
#define DEFAULT_STEP_PULSE_MICROSECONDS 3
#define DEFAULT_STEPPER_IDLE_LOCK_TIME 255 // stay on

#define DEFAULT_STEPPING_INVERT_MASK 0 // uint8_t
#define DEFAULT_DIRECTION_INVERT_MASK 2 // uint8_t
#define DEFAULT_INVERT_ST_ENABLE 0 // boolean
#define DEFAULT_INVERT_LIMIT_PINS 1 // boolean
#define DEFAULT_INVERT_PROBE_PIN 0 // boolean

#define DEFAULT_STATUS_REPORT_MASK 2 // MPos enabled

#define DEFAULT_JUNCTION_DEVIATION 0.01 // mm
#define DEFAULT_ARC_TOLERANCE 0.002 // mm
#define DEFAULT_REPORT_INCHES 0 // false

#define DEFAULT_SOFT_LIMIT_ENABLE 0 // false
#define DEFAULT_HARD_LIMIT_ENABLE 0  // false

#define DEFAULT_HOMING_ENABLE 1
#define DEFAULT_HOMING_DIR_MASK 0 // move positive dir Z, negative X,Y
#define DEFAULT_HOMING_FEED_RATE 200.0 // mm/min
#define DEFAULT_HOMING_SEEK_RATE 1000.0 // mm/min
#define DEFAULT_HOMING_DEBOUNCE_DELAY 250 // msec (0-65k)
#define DEFAULT_HOMING_PULLOFF 3.0 // mm

#define DEFAULT_SPINDLE_RPM_MAX 1000.0 // rpm
#define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm

#define DEFAULT_LASER_MODE 0 // false

#define DEFAULT_X_STEPS_PER_MM 200 * 4 * 49 / (8 * 3.14)
#define DEFAULT_Y_STEPS_PER_MM 200 * 4 * 49 / (8 * 3.14)
#define DEFAULT_Z_STEPS_PER_MM 200.0 // This is percent in servo mode

#define DEFAULT_X_MAX_RATE 5000.0 // mm/min
#define DEFAULT_Y_MAX_RATE 5000.0 // mm/min
#define DEFAULT_Z_MAX_RATE 3000.0 // mm/min

#define DEFAULT_X_ACCELERATION 200.0 // mm/sec^2. 200 mm/sec^2 = 720000 mm/min^2
#define DEFAULT_Y_ACCELERATION 200.0 // mm/sec^2
#define DEFAULT_Z_ACCELERATION 50.0 // mm/sec^2

#define DEFAULT_X_MAX_TRAVEL 900.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Y_MAX_TRAVEL 900.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Z_MAX_TRAVEL 5.0 // This is percent in servo mode

#define DEFAULT_Z_HOMING_MPOS DEFAULT_Z_MAX_TRAVEL // stays up after homing
