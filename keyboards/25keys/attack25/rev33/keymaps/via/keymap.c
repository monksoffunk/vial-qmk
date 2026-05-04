/* Copyright 2020 monksoffunk
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "../../common/attack25_defaults.h"

// [_NUM] layer 0
#define __________NUM_1__________  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,  KC_ESC
#define __________NUM_2__________  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,  LT(_FN, KC_HOME)
#define __________NUM_3__________  KC_P4,    KC_P5,    KC_P6,    S(KC_TAB),LT(_RGB, KC_END)
#define __________NUM_4__________  KC_P1,    KC_P2,    KC_P3,    LT(_NUMOFF, KC_PENT),  LT(_BLED, KC_DEL)
#define __________NUM_5__________  KC_P0,    P00,      KC_PDOT,  LT(_NUMOFF, KC_PENT),  LT(_SP, KC_BSPC)

// [_NUMOFF] layer 1
#define _________NUMOFF_1________  _______,  _______,  _______,  _______,  EN_RST
#define _________NUMOFF_2________  KC_HOME,  KC_UP,    KC_PGUP,  _______,  _______
#define _________NUMOFF_3________  KC_LEFT,  XXXXXXX,  KC_RGHT,  _______,  _______
#define _________NUMOFF_4________  KC_END,   KC_DOWN,  KC_PGDN,  _______,  _______
#define _________NUMOFF_5________  KC_INS,   XXXXXXX,  KC_DEL,   _______,  _______

// [_FN] layer 2
#define ___________FN_1__________  KC_F10,   KC_F11,   KC_F12,   _______,  EN_FN
#define ___________FN_2__________  KC_F7,    KC_F8,    KC_F9,    _______,  XXXXXXX
#define ___________FN_3__________  KC_F4,    KC_F5,    KC_F6,    _______,  XXXXXXX
#define ___________FN_4__________  KC_F1,    KC_F2,    KC_F3,    _______,  WINMAC
#define ___________FN_5__________  XXXXXXX,  _______,  _______,  _______,  _______

// [_RGB] layer 3
#define __________RGB_1__________  UG_TOGG,  UG_NEXT,  UG_HUEU,  XXXXXXX,  EN_RGB
#define __________RGB_2__________  RGBRST,   UG_PREV,  UG_HUED,  XXXXXXX,  XXXXXXX
#define __________RGB_3__________  UG_VALU,  UG_SATU,  UG_SPDU,  XXXXXXX,  XXXXXXX
#define __________RGB_4__________  UG_VALD,  UG_SATD,  UG_SPDD,  XXXXXXX,  XXXXXXX
#define __________RGB_5__________  _______,  _______,  _______,  _______,  _______

// [_BLED] layer 4
#define __________BLED_1_________  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
#define __________BLED_2_________  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
#define __________BLED_3_________  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
#define __________BLED_4_________  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
#define __________BLED_5_________  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX

// [_SP] layer 5
#define ___________SP_1__________  CH_ENCR,  XXXXXXX,  XXXXXXX,  XXXXXXX,  EN_SP
#define ___________SP_2__________  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
#define ___________SP_3__________  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
#define ___________SP_4__________  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
#define ___________SP_5__________  QK_BOOT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [1] = { ENCODER_CCW_CW(UG_HUED, UG_HUEU) },
    [2] = { ENCODER_CCW_CW(UG_SATD, UG_SATU) },
    [3] = { ENCODER_CCW_CW(UG_VALD, UG_VALU) },
    [4] = { ENCODER_CCW_CW(UG_SPDD, UG_SPDU) },
    [5] = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) }
};
#endif

// #if defined(ENCODER_ENABLE)
// // keycodes setting for encoder         CCW         CW
// #    define __________NUM_E__________   S(KC_TAB),  KC_TAB
// #    define _________NUMOFF_E________   _______,    _______
// #    define ___________FN_E__________   KC_VOLD,    KC_VOLU
// #    define __________RGB_E__________   RGB_RMOD,   RGB_MOD
// #    define __________BLED_E_________   BL_DEC,     BL_INC
// #    define ___________SP_E__________   C(KC_Z),    C(KC_Y)
// #elif defined(ENCODER_MATRIX_ENABLE)
// #    define __________NUM_E0_________   KC_VOLD,    KC_VOLU
// #    define __________NUM_E1_________   RGB_RMOD,   RGB_MOD
// #    define __________NUM_E2_________   RGB_HUD,    RGB_HUI
// #    define __________NUM_E3_________   RGB_VAD,    RGB_VAI
// #    define __________NUM_E4_________   RGB_SAD,    RGB_SAI
// #    define _________NUMOFF_E0_______   _______,    _______
// #    define ___________FN_E0_________   KC_VOLD,    KC_VOLU
// #    define __________RGB_E0_________   RGB_RMOD,   RGB_MOD
// #    define __________BLED_E0________   BL_DEC,     BL_INC
// #    define ___________SP_E0_________   C(KC_Z),    C(KC_Y)
// #else
#    define __________NUM_E__________   XXXXXXX,    XXXXXXX
#    define _________NUMOFF_E________   XXXXXXX,    XXXXXXX
#    define ___________FN_E__________   XXXXXXX,    XXXXXXX
#    define __________RGB_E__________   XXXXXXX,    XXXXXXX
#    define __________BLED_E_________   XXXXXXX,    XXXXXXX
#    define ___________SP_E__________   XXXXXXX,    XXXXXXX
// #endif

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#ifdef attack25_rev3x
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NUM] = LAYOUT_wrapper(
        __________NUM_E__________,
        __________NUM_1__________,
        __________NUM_2__________,
        __________NUM_3__________,
        __________NUM_4__________,
        __________NUM_5__________),

    [_NUMOFF] = LAYOUT_wrapper(
        _________NUMOFF_E________,
        _________NUMOFF_1________,
        _________NUMOFF_2________,
        _________NUMOFF_3________,
        _________NUMOFF_4________,
        _________NUMOFF_5________),

    [_FN] = LAYOUT_wrapper(
        ___________FN_E__________,
        ___________FN_1__________,
        ___________FN_2__________,
        ___________FN_3__________,
        ___________FN_4__________,
        ___________FN_5__________),

    [_RGB] = LAYOUT_wrapper(
        __________RGB_E__________,
        __________RGB_1__________,
        __________RGB_2__________,
        __________RGB_3__________,
        __________RGB_4__________,
        __________RGB_5__________),

    [_BLED] = LAYOUT_wrapper(
        __________BLED_E_________,
        __________BLED_1_________,
        __________BLED_2_________,
        __________BLED_3_________,
        __________BLED_4_________,
        __________BLED_5_________),

    [_SP] = LAYOUT_wrapper(
        ___________SP_E__________,
        ___________SP_1__________,
        ___________SP_2__________,
        ___________SP_3__________,
        ___________SP_4__________,
        ___________SP_5__________)
};
#elif defined(attack25_rev1g) && defined(ENCODER_MATRIX_ENABLE)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NUM] = LAYOUT_wrapper(
        __________NUM_1__________,  __________NUM_E0_________,
        __________NUM_2__________,  __________NUM_E1_________,
        __________NUM_3__________,  __________NUM_E2_________,
        __________NUM_4__________,  __________NUM_E3_________,
        __________NUM_5__________,  __________NUM_E4_________),

    [_NUMOFF] = LAYOUT_wrapper(
        _________NUMOFF_1________,  _________NUMOFF_E0_______,
        _________NUMOFF_2________,  _________NUMOFF_E0_______,
        _________NUMOFF_3________,  _________NUMOFF_E0_______,
        _________NUMOFF_4________,  _________NUMOFF_E0_______,
        _________NUMOFF_5________,  _________NUMOFF_E0_______),

    [_FN] = LAYOUT_wrapper(
        ___________FN_1__________,  ___________FN_E0_________,
        ___________FN_2__________,  ___________FN_E0_________,
        ___________FN_3__________,  ___________FN_E0_________,
        ___________FN_4__________,  ___________FN_E0_________,
        ___________FN_5__________,  ___________FN_E0_________),

    [_RGB] = LAYOUT_wrapper(
        __________RGB_1__________,  __________RGB_E0_________,
        __________RGB_2__________,  __________RGB_E0_________,
        __________RGB_3__________,  __________RGB_E0_________,
        __________RGB_4__________,  __________RGB_E0_________,
        __________RGB_5__________,  __________RGB_E0_________),

    [_BLED] = LAYOUT_wrapper(
        __________BLED_1_________,  __________BLED_E0________,
        __________BLED_2_________,  __________BLED_E0________,
        __________BLED_3_________,  __________BLED_E0________,
        __________BLED_4_________,  __________BLED_E0________,
        __________BLED_5_________,  __________BLED_E0________),

    [_SP] = LAYOUT_wrapper(
        ___________SP_1__________,  ___________SP_E0_________,
        ___________SP_2__________,  ___________SP_E0_________,
        ___________SP_3__________,  ___________SP_E0_________,
        ___________SP_4__________,  ___________SP_E0_________,
        ___________SP_5__________,  ___________SP_E0_________)
};
#else // rev1
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NUM] = LAYOUT_wrapper(
        __________NUM_1__________,
        __________NUM_2__________,
        __________NUM_3__________,
        __________NUM_4__________,
        __________NUM_5__________),

    [_NUMOFF] = LAYOUT_wrapper(
        _________NUMOFF_1________,
        _________NUMOFF_2________,
        _________NUMOFF_3________,
        _________NUMOFF_4________,
        _________NUMOFF_5________),

    [_FN] = LAYOUT_wrapper(
        ___________FN_1__________,
        ___________FN_2__________,
        ___________FN_3__________,
        ___________FN_4__________,
        ___________FN_5__________),

    [_RGB] = LAYOUT_wrapper(
        __________RGB_1__________,
        __________RGB_2__________,
        __________RGB_3__________,
        __________RGB_4__________,
        __________RGB_5__________),

    [_BLED] = LAYOUT_wrapper(
        __________BLED_1_________,
        __________BLED_2_________,
        __________BLED_3_________,
        __________BLED_4_________,
        __________BLED_5_________),

    [_SP] = LAYOUT_wrapper(
        ___________SP_1__________,
        ___________SP_2__________,
        ___________SP_3__________,
        ___________SP_4__________,
        ___________SP_5__________)
};
#endif
