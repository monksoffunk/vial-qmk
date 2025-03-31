/* Copyright 2023 monksoffunk
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#include "quantum.h"

#if !(defined(MATRIX_REMAP_TABLE_SRC) && defined(MATRIX_REMAP_TABLE_DST))
#   error "Error: MATRIX_REMAP_TABLE_SRC and MATRIX_REMAP_TABLE_DST are required"
#endif

typedef struct {
    int col;
    int row;
} coord_t;

const coord_t remap_src[] = MATRIX_REMAP_TABLE_SRC;
const coord_t remap_dst[] = MATRIX_REMAP_TABLE_DST;
#define NUM_OF_MATRIX_REMAP (sizeof(remap_src) / sizeof(remap_src[0]))

/*
 * Function to remap the coordinates
 */
void matrix_remap(matrix_row_t* matrix) {
    for(int i = 0; i < NUM_OF_MATRIX_REMAP; i++) {
        if(matrix[remap_src[i].row] & (1 << remap_src[i].col)) {
            matrix[remap_dst[i].row] |= (1 << remap_dst[i].col);
            matrix[remap_src[i].row] &= ~(1 << remap_src[i].col);
        }
    }
}