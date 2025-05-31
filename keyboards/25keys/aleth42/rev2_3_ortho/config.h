/*
Copyright 2023 monksoffunk

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

#ifdef ENCODER_HOT_SWAP_ENABLE
#    define ENCODER_MATRIX_ENABLE
#    define SWAP_ENCODERS_PAD_A {GP0, GP0, GP0, GP0, GP0, GP0, GP0, GP0, GP0, GP0, GP0, GP0}
#    define SWAP_ENCODERS_PAD_B {GP1, GP1, GP1, GP1, GP1, GP1, GP1, GP1, GP1, GP1, GP1, GP1}
#    define ENCODER_MATRIX_ROW_PINS_A SWAP_ENCODERS_PAD_A
#    define ENCODER_MATRIX_ROW_PINS_B SWAP_ENCODERS_PAD_B
#    define ENCODER_MATRIX_COL_PINS_A MATRIX_COL_PINS
#    define ENCODER_MATRIX_COL_PINS_B MATRIX_COL_PINS
//#    define ENCODER_MATRIX_ROW_PINS MATRIX_ROW_PINS
#    define ENCODER_RESOLUTION 2

#    define SWAP_ENCODERS_SW {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}, {7, 4}, {8, 4}, {9, 4}, {10, 4}, {11, 4}}
#    define SWAP_ENCODERS_SW_REMAP_DST {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {1, 3}, {2, 3}, {11, 0}, {11, 1}, {11, 2}, {11, 3}, {10, 3}, {9, 3}}
#    define MATRIX_REMAP_TABLE_SRC SWAP_ENCODERS_SW
#    define MATRIX_REMAP_TABLE_DST SWAP_ENCODERS_SW_REMAP_DST
#endif
