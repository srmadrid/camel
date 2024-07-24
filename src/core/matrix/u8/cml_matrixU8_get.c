/** @file cml_matrixU8_get.c
 * 
 * @brief Get function for matrices holding u8's.
 *
 * @author Sergio Madrid
 * @date 19/4/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/matrix/matrix.h"


u8 cml_matrixU8_get(u32 row, u32 column, const CML_Matrix *matrix, CML_Status *out) {
    if (matrix == NULL) {
        if (out != NULL) {
            *out = CML_ERR_NULL_PTR;
        }
        return MAX_U8;
    }

    if (row >= matrix->rows || column >= matrix->columns) {
        if (out != NULL) {
            *out = CML_ERR_INVALID_INDEX;
        }
        return MAX_U8;
    }

    if (matrix->type != CML_U8) {
        if (out != NULL) {
            *out = CML_ERR_INCOMPATIBLE_TYPES;
        }
        return MAX_U8;
    }

    return matrix->u8d[row*matrix->columns + column];
}

