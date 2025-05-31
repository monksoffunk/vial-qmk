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

#pragma once

// place overrides here
// #define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define VIAL_KEYBOARD_UID {0x52, 0x71, 0x0C, 0x94, 0x42, 0x5D, 0xF2, 0x49}

#define DYNAMIC_KEYMAP_LAYER_COUNT 10

// VIAL unlock combo Q -> P
#define VIAL_UNLOCK_COMBO_ROWS {0, 0} 
#define VIAL_UNLOCK_COMBO_COLS {1, 10}

#ifdef ENCODER_HOT_SWAP_ENABLE
# define ENCODER_DIRECTION_FLIP
#endif