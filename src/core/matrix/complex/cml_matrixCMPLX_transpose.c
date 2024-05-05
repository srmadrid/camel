/** @file cml_matrixCMPLX_transpose.c
 * 
 * @brief Transpose function for matrices holding Complex's.
 *
 * @author Sergio Madrid
 * @date 5/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/matrix/matrix.h"


CML_Status cml_matrixCMPLX_transpose(CML_Allocator *allocator, const CML_Matrix *A, CML_Matrix *out) {
    if (A == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (A->type != CML_COMPLEX) {
        // Maybe add type promotion in the future
        return CML_ERR_INCOMPATIBLE_TYPES;
    }

    // If allocator is NULL, out is initialized.
    if (allocator == NULL) {
        if (out->rows != A->columns || out->columns != A->rows || 
            out->type != CML_COMPLEX) {
            return CML_ERR_INVALID_SIZE;
        }
    } else {
        CML_Status result = cml_matrix_init0(allocator, A->columns, A->rows, CML_COMPLEX, out);
        if (result != CML_SUCCESS) {
            return result;
        }
    }

    for (u32 r = 0; r < out->rows; r++) {
        for (u32 c = 0; c < out->columns; c++) {
            //cml_complex_copy(NULL, &A->complexd[c*out->rows + r], &out->complexd[r*out->columns + c]);
        }
    }

    return CML_SUCCESS;
}

