/** @file cml_matrix_set.c
 * 
 * @brief Get function for matrices.
 *
 * @author Sergio Madrid
 * @date 17/4/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/core/matrix/matrix.h"


void *cml_matrix_get(u32 row, u32 column, const CML_Matrix *out) {
    if (out == NULL) {
        return NULL;
    }

    if (row >= out->rows || column >= out->columns) {
        return NULL;
    }

    u32 stride = cml_numerictype_size(out->type);
    void *element;
    element = &out->u8d[stride*(row*out->columns + column)];

    return element;
}

