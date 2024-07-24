/** @file cml_matrixCMPLX_get.c
 * 
 * @brief Get function for matrices holding Complex's.
 *
 * @author Sergio Madrid
 * @date 20/4/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/matrix/matrix.h"


CML_Complex *cml_matrixCMPLX_get(u32 row, u32 column, const CML_Matrix *matrix, CML_Status *out) {
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

    if (matrix->type != CML_BIGINT) {
        if (out != NULL) {
            *out = CML_ERR_INCOMPATIBLE_TYPES;
        }
        return NULL;
    }

    return &matrix->complexd[row*matrix->columns + column];
}

