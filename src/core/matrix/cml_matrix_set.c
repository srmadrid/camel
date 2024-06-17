/** @file cml_matrix_set.c
 * 
 * @brief Set function for matrices.
 *
 * @author Sergio Madrid
 * @date 17/4/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/core/matrix/matrix.h"


CML_Status cml_matrix_set(void *element, u32 row, u32 column, CML_Matrix *out) {
    if (out == NULL || element == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (row >= out->rows || column >= out->columns) {
        return CML_ERR_INVALID_INDEX;
    }

    switch (out->type) {
        case CML_U8:
            out->u8d[row*out->columns + column] = *(u8*)element;
            break;

        case CML_U16:
            out->u16d[row*out->columns + column] = *(u16*)element;
            break;

        case CML_U32:
            out->u32d[row*out->columns + column] = *(u32*)element;
            break;

        case CML_U64:
            out->u64d[row*out->columns + column] = *(u64*)element;
            break;

        case CML_I8:
            out->i8d[row*out->columns + column] = *(i8*)element;
            break;

        case CML_I16:
            out->u16d[row*out->columns + column] = *(i16*)element;
            break;

        case CML_I32:
            out->i32d[row*out->columns + column] = *(i32*)element;
            break;

        case CML_I64:
            out->i64d[row*out->columns + column] = *(i64*)element;
            break;

        case CML_F32:
            out->f32d[row*out->columns + column] = *(f32*)element;
            break;

        case CML_F64:
            out->f64d[row*out->columns + column] = *(f64*)element;
            break;

        case CML_CF32:
            out->cf32d[row*out->columns + column] = *(cf32*)element;
            break;

        case CML_CF64:
            out->cf64d[row*out->columns + column] = *(cf64*)element;
            break;

        case CML_BIGINT:
            memcpy(&out->bigintd, element, sizeof(CML_BigInt));
            break;

        case CML_FRACTION:
            memcpy(&out->fracd, element, sizeof(CML_Fraction));
            break;

        case CML_COMPLEX:
            memcpy(&out->complexd, element, sizeof(CML_Complex));
            break;

        case CML_EXPRESSION:
            memcpy(&out->expd, element, sizeof(CML_Expression));
            break;

        case CML_MATRIX:
            memcpy(&out->matd, element, sizeof(CML_Matrix));
            break;

        default:
            return CML_ERR_INVALID_ENUM_MEMBER;
    }

    return CML_SUCCESS;
}

