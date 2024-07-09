/** @file cml_matrixCF32_get.c
 * 
 * @brief Get function for matrices holding cf32's.
 *
 * @author Sergio Madrid
 * @date 20/4/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/matrix/matrix.h"


cf32 cml_matrixCF32_get(u32 row, u32 column, const CML_Matrix *matrix, CML_Status *out) {
    if (matrix == NULL) {
        if (out != NULL) {
            *out = CML_ERR_NULL_PTR;
        }
        return MAX_F32 + MAX_F32*I;
    }

    if (row >= matrix->rows || column >= matrix->columns) {
        if (out != NULL) {
            *out = CML_ERR_INVALID_INDEX;
        }
        return MAX_F32 + MAX_F32*I;
    }

    if (matrix->type != CML_CF32) {
        if (out != NULL) {
            *out = CML_ERR_INCOMPATIBLE_TYPES;
        }
        return MAX_F32 + MAX_F32*I;
    }

    return matrix->cf64d[row*matrix->columns + column];
}

