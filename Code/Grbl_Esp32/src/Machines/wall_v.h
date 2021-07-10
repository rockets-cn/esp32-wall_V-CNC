
#pragma once

#define MACHINE_NAME "WALL_V_CNC"

// This causes the custom code file to be included in the build
// via ../custom_code.cpp
#define CUSTOM_CODE_FILENAME "Custom/wall_v.cpp"

#define SPINDLE_TYPE SpindleType::NONE

#define LEFT_AXIS 0
#define RIGHT_AXIS 1

#define SEGMENT_LENGTH 0.5 // in mm