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
#    define ENCODER_RESOLUTION 2
#    define ENCODER_DIRECTION_FLIP

#    define SWAP_ENCODERS_SW {{11, 0}, {12, 0}}
#    define SWAP_ENCODERS_SW_REMAP_DST {{0, 0}, {10, 3}}
#    define MATRIX_REMAP_TABLE_SRC SWAP_ENCODERS_SW
#    define MATRIX_REMAP_TABLE_DST SWAP_ENCODERS_SW_REMAP_DST
#endif