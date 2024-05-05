/** @file cml_matrixF64_transpose.c
 * 
 * @brief Transpose function for matrices holding f64's.
 *
 * @author Sergio Madrid
 * @date 5/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/matrix/matrix.h"


CML_Status cml_matrixF64_transpose(CML_Allocator *allocator, const CML_Matrix *A, CML_Matrix *out) {
    if (A == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (A->type != CML_F64) {
        // Maybe add type promotion in the future
        return CML_ERR_INCOMPATIBLE_TYPES;
    }

    // If allocator is NULL, out is initialized.
    if (allocator == NULL) {
        if (out->rows != A->columns || out->columns != A->rows || 
            out->type != CML_F64) {
            return CML_ERR_INVALID_SIZE;
        }
    } else {
        CML_Status result = cml_matrix_init(allocator, A->columns, A->rows, CML_F64, out);
        if (result != CML_SUCCESS) {
            return result;
        }
    }

    for (u32 r = 0; r < out->rows; r++) {
        for (u32 c = 0; c < out->columns; c++) {
            out->f64d[r*out->columns + c] = A->f64d[c*out->rows + r];
        }
    }

    return CML_SUCCESS;
}

