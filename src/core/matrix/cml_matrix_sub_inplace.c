/** @file cml_matrix_sub_inplace.c
 * 
 * @brief In-place subtract function for matrices.
 *
 * @author Sergio Madrid
 * @date 4/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/core/matrix/matrix.h"


CML_Status cml_matrix_sub_inplace(const CML_Matrix *right, CML_Matrix *out) {
    if (right == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (right->type != out->type) {
        // Maybe add type promotion in the future
        return CML_ERR_INCOMPATIBLE_TYPES;
    }

    switch (right->type) {
        case CML_U8:
            return cml_matrixU8_sub_inplace(right, out);

        case CML_U16:
            return cml_matrixU16_sub_inplace(right, out);

        case CML_U32:
            return cml_matrixU32_sub_inplace(right, out);

        case CML_U64:
            return cml_matrixU64_sub_inplace(right, out);

        case CML_I8:
            return cml_matrixI8_sub_inplace(right, out);

        case CML_I16:
            return cml_matrixI16_sub_inplace(right, out);

        case CML_I32:
            return cml_matrixI32_sub_inplace(right, out);

        case CML_I64:
            return cml_matrixI64_sub_inplace(right, out);

        case CML_F32:
            return cml_matrixF32_sub_inplace(right, out);

        case CML_F64:
            return cml_matrixF64_sub_inplace(right, out);

        case CML_CF32:
            return cml_matrixCF32_sub_inplace(right, out);

        case CML_CF64:
            return cml_matrixCF64_sub_inplace(right, out);

        case CML_BIGINT:
            return cml_matrixBINT_sub_inplace(right, out);

        case CML_FRACTION:
            return cml_matrixFRAC_sub_inplace(right, out);

        case CML_COMPLEX:
            return cml_matrixCMPLX_sub_inplace(right, out);

        case CML_EXPRESSION:
            return cml_matrixEXP_sub_inplace(right, out);

        case CML_MATRIX:
            return cml_matrixMAT_sub_inplace(right, out);
    }
}

