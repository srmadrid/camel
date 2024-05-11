/** @file cml_matrixBINT_sub_inplace.c
 * 
 * @brief In-place subtract function for matrices holding Bigint's.
 *
 * @author Sergio Madrid
 * @date 4/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/matrix/matrix.h"


CML_Status cml_matrixBINT_sub_inplace(const CML_Matrix *right, CML_Matrix *out) {
    if (right == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (right->type != CML_BIGINT || out->type != CML_BIGINT) {
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
        //CML_BigInt scalar = right->bigintd[0];
        for (u32 i = 0; i < size; i++) {
            //cml_bigint_sub_inplace(&scalar, &out->bigintd[i]);
        }
    } else {
        for (u32 i = 0; i < size; i++) {
            //cml_bigint_sub_inplace(&right->bigintd[i], &out->bigintd[i]);
        }
    }

    return CML_SUCCESS;
}
