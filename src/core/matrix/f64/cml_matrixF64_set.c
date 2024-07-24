/** @file cml_matrixF64_set.h
 * 
 * @brief Set function for matrices holding f64's.
 *
 * @author Sergio Madrid
 * @date 19/4/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/matrix/matrix.h"


CML_Status cml_matrixF64_set(f64 element, u32 row, u32 column, CML_Matrix *out) {
    if (out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (row >= out->rows || column >= out->columns) {
        return CML_ERR_INVALID_INDEX;
    }

    if (out->type != CML_F64) {
        return CML_ERR_INCOMPATIBLE_TYPES;
    }

    out->f64d[row*out->columns + column] = element;

    return CML_SUCCESS;
}

