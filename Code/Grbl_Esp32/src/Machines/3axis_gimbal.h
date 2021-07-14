/*
 * @Author: your name
 * @Date: 2021-05-24 13:44:38
 * @LastEditTime: 2021-05-24 14:02:06
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \testc:\Users\rocke\Downloads\ESP32-E-support-master\ESP32-E-support-master\Grbl_Esp32\src\Machines\3axis_gimbal.h
 */

#pragma once
// clang-format off

/*
    3axis_v4.h
    Part of Grbl_ESP32

    Pin assignments for the ESP32 Development Controller, v4.1 and later.
    https://github.com/bdring/Grbl_ESP32_Development_Controller
    https://www.tindie.com/products/33366583/grbl_esp32-cnc-development-board-v35/

    2018    - Bart Dring
    2020    - Mitch Bradley

    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/

#define MACHINE_NAME            "ESP32_gimbal"

#define X_STEP_PIN              GPIO_NUM_25    //D2
#define X_DIRECTION_PIN         GPIO_NUM_26    //D3
#define Y_STEP_PIN              GPIO_NUM_14    //D6
#define Y_DIRECTION_PIN         GPIO_NUM_13    //D7
#define Z_STEP_PIN              GPIO_NUM_16    //D11
#define Z_DIRECTION_PIN         GPIO_NUM_4     //D12

#define X_LIMIT_PIN             GPIO_NUM_36     //A0
#define Y_LIMIT_PIN             GPIO_NUM_39     //A1
#define Z_LIMIT_PIN             GPIO_NUM_34     //A2


// OK to comment out to use pin for other features
/*
#define STEPPERS_DISABLE_PIN    GPIO_NUM_13

#define SPINDLE_TYPE            SpindleType::PWM
#define SPINDLE_OUTPUT_PIN      GPIO_NUM_2   // labeled SpinPWM
#define SPINDLE_ENABLE_PIN      GPIO_NUM_22  // labeled SpinEnbl

#define COOLANT_MIST_PIN        GPIO_NUM_21  // labeled Mist
#define COOLANT_FLOOD_PIN       GPIO_NUM_25  // labeled Flood
#define PROBE_PIN               GPIO_NUM_32  // labeled Probe

*/

/*
#define CONTROL_SAFETY_DOOR_PIN GPIO_NUM_35  // labeled Door,  needs external pullup
#define CONTROL_RESET_PIN       GPIO_NUM_34  // labeled Reset, needs external pullup
#define CONTROL_FEED_HOLD_PIN   GPIO_NUM_36  // labeled Hold,  needs external pullup
#define CONTROL_CYCLE_START_PIN GPIO_NUM_39  // labeled Start, needs external pullup
*/

