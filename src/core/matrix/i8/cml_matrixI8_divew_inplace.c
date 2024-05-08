/** @file cml_matrixI8_divew_inplace.c
 * 
 * @brief In-place element-wise division function for matrices holding 
 *        i8's.
 *
 * @author Sergio Madrid
 * @date 5/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/matrix/matrix.h"


CML_Status cml_matrixI8_divew_inplace(const CML_Matrix *right, CML_Matrix *out) {
    if (right == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (right->type != CML_I8 || out->type != CML_I8) {
        // Maybe add type promotion in the future
        return CML_ERR_INCOMPATIBLE_TYPES;
    }

    b8 rightIsScalar;
    if (right->rows != out->rows || right->columns != out->columns) {
        if (right->rows == 1 && right->columns == 1) {
            rightIsScalar = true;
        } else {
            return CML_ERR_INCOMPATIBLE_SIZE;
        }
    } else {
        rightIsScalar = false;
    }

    u32 size = out->columns*out->rows;
    if (rightIsScalar) {
        i8 scalar = right->i8d[0];
        for (u32 i = 0; i < size; i++) {
            out->i8d[i] /= scalar;
        }
    } else {
        for (u32 i = 0; i < size; i++) {
            out->i8d[i] /= right->i8d[i];
        }
    }

    return CML_SUCCESS;
}

