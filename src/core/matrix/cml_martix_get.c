/** @file cml_matrix_get.c
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


void *cml_matrix_get(u32 row, u32 column, const CML_Matrix *matrix, CML_Status *out) {
    if (matrix == NULL) {
        if (out != NULL) {
            *out = CML_ERR_NULL_PTR;
        }
        return NULL;
    }

    if (row >= matrix->rows || column >= matrix->columns) {
        if (out != NULL) {
            *out = CML_ERR_INVALID_INDEX;
        }
        return NULL;
    }

    u32 stride = cml_numerictype_size(matrix->type);
    void *element;
    element = &matrix->u8d[stride*(row*matrix->columns + column)];

    return element;
}

