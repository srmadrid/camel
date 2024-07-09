/** @file cml_matrixBINT_set.c
 * 
 * @brief Set function for matrices holding Bigint's.
 *
 * @author Sergio Madrid
 * @date 19/4/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/matrix/matrix.h"


CML_Status cml_matrixBINT_set(CML_BigInt *element, u32 row, u32 column, CML_Matrix *out) {
    if (out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (row >= out->rows || column >= out->columns) {
        return CML_ERR_INVALID_INDEX;
    }

    if (out->type != CML_BIGINT) {
        return CML_ERR_INCOMPATIBLE_TYPES;
    }

    out->bigintd[row*out->columns + column] = *element;

    return CML_SUCCESS;
}

