/** @file cml_matrixCMPLX_set.c
 * 
 * @brief Set function for matrices holding Complex's.
 *
 * @author Sergio Madrid
 * @date 19/4/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/matrix/matrix.h"


CML_Status cml_matrixCMPLX_set(CML_Complex *element, u32 row, u32 column, CML_Matrix *out) {
    if (out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (row >= out->rows || column >= out->columns) {
        return CML_ERR_INVALID_INDEX;
    }

    if (out->type != CML_COMPLEX) {
        return CML_ERR_INCOMPATIBLE_TYPES;
    }

    out->complexd[row*out->columns + column] = *element;

    return CML_SUCCESS;
}

