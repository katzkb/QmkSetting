/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define SSD1306OLED

#define USE_SERIAL_PD2

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 27
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

//#define MOUSEKEY_MAX_SPEED 50
//#define MOUSEKEY_TIME_TO_MAX 1

#undef MOUSEKEY_DELAY
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_MOVE_DELTA
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_TIME_TO_MAX

#undef MOUSEKEY_WHEEL_MAX_SPEED
#undef MOUSEKEY_WHEEL_TIME_TO_MAX

#define MOUSEKEY_DELAY       0  // マウスの移動を開始するまでの時間 48
#define MOUSEKEY_INTERVAL    12 // マウス移動コマンドをPCに送信する頻度 24
#define MOUSEKEY_MOVE_DELTA  2  // 一度の移動コマンドで移動する単位距離 3, 5
#define MOUSEKEY_MAX_SPEED   8 // 押しっぱなしでどこまで加速するか 10
#define MOUSEKEY_TIME_TO_MAX 0 // 最大速度になるまでの所要時間 20

#define MOUSEKEY_WHEEL_DELAY      48 // スクロール移動を開始するまでの時間 48
#define MOUSEKEY_WHEEL_INTERVAL   48 // スクロール移動コマンドをPCに送信する頻度 24
#define MOUSEKEY_WHEEL_MOVE_DELTA 3  // 一度の移動コマンドで移動する単位距離 3, 5

#define MOUSEKEY_WHEEL_MAX_SPEED   1
#define MOUSEKEY_WHEEL_TIME_TO_MAX 1 //255
