/** @file cml_matrixU8_sub_inplace.c
 * 
 * @brief In-place subtract function for matrices holding u8's.
 *
 * @author Sergio Madrid
 * @date 4/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/matrix/matrix.h"


CML_Status cml_matrixU8_sub_inplace(const CML_Matrix *right, CML_Matrix *out) {
    if (right == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (right->type != CML_U8 || out->type != CML_U8) {
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
        u8 scalar = right->u8d[0];
        for (u32 i = 0; i < size; i++) {
            out->u8d[i] -= scalar;
        }
    } else {
        for (u32 i = 0; i < size; i++) {
            out->u8d[i] -= right->u8d[i];
        }
    }

    return CML_SUCCESS;
}

