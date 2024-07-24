/** @file cml_matrixU16_get.c
 * 
 * @brief Get function for matrices holding u16's.
 *
 * @author Sergio Madrid
 * @date 20/4/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/matrix/matrix.h"


u16 cml_matrixU16_get(u32 row, u32 column, const CML_Matrix *matrix, CML_Status *out) {
    if (matrix == NULL) {
        if (out != NULL) {
            *out = CML_ERR_NULL_PTR;
        }
        return MAX_U16;
    }

    if (row >= matrix->rows || column >= matrix->columns) {
        if (out != NULL) {
            *out = CML_ERR_INVALID_INDEX;
        }
        return MAX_U16;
    }

    if (matrix->type != CML_U16) {
        if (out != NULL) {
            *out = CML_ERR_INCOMPATIBLE_TYPES;
        }
        return MAX_U16;
    }

    return matrix->u16d[row*matrix->columns + column];
}

