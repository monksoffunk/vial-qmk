/* Copyright 2025 monksoffunk
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
#include "../../common/40_ortho_keymap.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _EXTRA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_wrapper(
        __________40_ORTHO_DEFAULT_1__________,
        __________40_ORTHO_DEFAULT_2__________,
        __________40_ORTHO_DEFAULT_3__________,
        __________40_ORTHO_DEFAULT_4__________),

    [_LOWER] = LAYOUT_wrapper(
        ___________40_ORTHO_LOWER_1___________,
        ___________40_ORTHO_LOWER_2___________,
        ___________40_ORTHO_LOWER_3___________,
        ___________40_ORTHO_LOWER_4___________),

    [_RAISE] = LAYOUT_wrapper(
        ___________40_ORTHO_RAISE_1___________,
        ___________40_ORTHO_RAISE_2___________,
        ___________40_ORTHO_RAISE_3___________,
        ___________40_ORTHO_RAISE_4___________),

    [_ADJUST] = LAYOUT_wrapper(
        __________40_ORTHO_ADJUST_1___________,
        __________40_ORTHO_ADJUST_2___________,
        __________40_ORTHO_ADJUST_3___________,
        __________40_ORTHO_ADJUST_4___________),

    [_EXTRA] = LAYOUT_wrapper(
        __________40_ORTHO_EXTRA_1___________,
        __________40_ORTHO_EXTRA_2___________,
        __________40_ORTHO_EXTRA_3___________,
        __________40_ORTHO_EXTRA_4___________)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   ENCODER_CCW_CW_0,
    [1] =   ENCODER_CCW_CW_1,
    [2] =   ENCODER_CCW_CW_2,
    [3] =   ENCODER_CCW_CW_3,
    [4] =   ENCODER_CCW_CW_4
};
#endif