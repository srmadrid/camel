/** @file cml_matrix_print.c
 * 
 * @brief Print function for matrices.
 *
 * @author Sergio Madrid
 * @date 5/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/core/matrix/matrix.h"


CML_Status cml_matrix_print(CML_Allocator *allocator, const CML_Matrix *matrix) {
    if (matrix == NULL) {
        return CML_ERR_NULL_PTR;
    }

    switch (matrix->type) {
        case CML_U8:
            return cml_matrixU8_print(allocator, matrix);

        case CML_U16:
            return cml_matrixU16_print(allocator, matrix);

        case CML_U32:
            return cml_matrixU32_print(allocator, matrix);

        case CML_U64:
            return cml_matrixU64_print(allocator, matrix);

        case CML_I8:
            return cml_matrixI8_print(allocator, matrix);

        case CML_I16:
            return cml_matrixI16_print(allocator, matrix);

        case CML_I32:
            return cml_matrixI32_print(allocator, matrix);

        case CML_I64:
            return cml_matrixI64_print(allocator, matrix);

        case CML_F32:
            return cml_matrixF32_print(allocator, matrix);

        case CML_F64:
            return cml_matrixF64_print(allocator, matrix);

        case CML_CF32:
            return cml_matrixCF32_print(allocator, matrix);

        case CML_CF64:
            return cml_matrixCF64_print(allocator, matrix);

        case CML_BIGINT:
            return cml_matrixBINT_print(allocator, matrix);

        case CML_FRACTION:
            return cml_matrixFRAC_print(allocator, matrix);

        case CML_COMPLEX:
            return cml_matrixCMPLX_print(allocator, matrix);

        case CML_EXPRESSION:
            return cml_matrixEXP_print(allocator, matrix);

        case CML_MATRIX:
            return cml_matrixMAT_print(allocator, matrix);
    }

    return CML_ERR_INVALID_ENUM_MEMBER;
}

