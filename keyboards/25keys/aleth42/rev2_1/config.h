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
#    define SWAP_ENCODERS_PAD_A {GP19, GP13}
#    define SWAP_ENCODERS_PAD_B {GP2, GP14}
#    define SWAP_ENCODERS_COMMON {GP11, GP11}
#    define ENCODER_MATRIX_COL_PINS_A SWAP_ENCODERS_PAD_A
#    define ENCODER_MATRIX_COL_PINS_B SWAP_ENCODERS_PAD_B
#    define ENCODER_MATRIX_ROW_PINS SWAP_ENCODERS_COMMON
#    define ENCODER_RESOLUTION 2

#    define SWAP_ENCODERS_SW {{2, 4}, {10, 4}}
#    define SWAP_ENCODERS_SW_REMAP_DST {{3, 4}, {11, 4}}
#    define MATRIX_REMAP_TABLE_SRC {{2, 4}, {10, 4}}
#    define MATRIX_REMAP_TABLE_DST {{0, 0}, {10, 3}}
#endif