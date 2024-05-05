/** @file cml_matrix_transpose.c
 * 
 * @brief Transpose function for matrices.
 *
 * @author Sergio Madrid
 * @date 5/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/core/matrix/matrix.h"


CML_Status cml_matrix_transpose(CML_Allocator *allocator, const CML_Matrix *A, CML_Matrix *out) {
    if (A == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    switch (A->type) {
        case CML_U8:
            return cml_matrixU8_transpose(allocator, A, out);

        case CML_U16:
            return cml_matrixU16_transpose(allocator, A, out);

        case CML_U32:
            return cml_matrixU32_transpose(allocator, A, out);

        case CML_U64:
            return cml_matrixU64_transpose(allocator, A, out);

        case CML_I8:
            return cml_matrixI8_transpose(allocator, A, out);

        case CML_I16:
            return cml_matrixI16_transpose(allocator, A, out);

        case CML_I32:
            return cml_matrixI32_transpose(allocator, A, out);

        case CML_I64:
            return cml_matrixI64_transpose(allocator, A, out);

        case CML_F32:
            return cml_matrixF32_transpose(allocator, A, out);

        case CML_F64:
            return cml_matrixF64_transpose(allocator, A, out);

        case CML_CF32:
            return cml_matrixCF32_transpose(allocator, A, out);

        case CML_CF64:
            return cml_matrixCF64_transpose(allocator, A, out);

        case CML_BIGINT:
            return cml_matrixBINT_transpose(allocator, A, out);

        case CML_FRACTION:
            return cml_matrixFRAC_transpose(allocator, A, out);

        case CML_COMPLEX:
            return cml_matrixCMPLX_transpose(allocator, A, out);

        case CML_EXPRESSION:
            return cml_matrixEXP_transpose(allocator, A, out);

        case CML_MATRIX:
            return cml_matrixMAT_transpose(allocator, A, out);
    }
}

