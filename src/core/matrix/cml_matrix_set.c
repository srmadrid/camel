/** @file cml_matrix_init.h
 * 
 * @brief Init function for matrices.
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
            return cml_matrixU8_set(*(u8*)element, row, column, out);

        case CML_U16:
            return cml_matrixU16_set(*(u16*)element, row, column, out);

        case CML_U32:
            return cml_matrixU32_set(*(u32*)element, row, column, out);

        case CML_U64:
            return cml_matrixU64_set(*(u64*)element, row, column, out);

        case CML_I8:
            return cml_matrixI8_set(*(i8*)element, row, column, out);

        case CML_I16:
            return cml_matrixI16_set(*(i16*)element, row, column, out);

        case CML_I32:
            return cml_matrixI32_set(*(i32*)element, row, column, out);

        case CML_I64:
            return cml_matrixI64_set(*(i64*)element, row, column, out);

        case CML_F32:
            return cml_matrixF32_set(*(f32*)element, row, column, out);

        case CML_F64:
            return cml_matrixF64_set(*(f64*)element, row, column, out);

        case CML_CF32:
            return cml_matrixCF32_set(*(cf32*)element, row, column, out);

        case CML_CF64:
            return cml_matrixCF64_set(*(cf64*)element, row, column, out);

        case CML_BIGINT:
            return cml_matrixBINT_set(element, row, column, out);

        case CML_FRACTION:
            return cml_matrixFRAC_set(element, row, column, out);

        case CML_COMPLEX:
            return cml_matrixCMPLX_set(element, row, column, out);

        case CML_EXPRESSION:
            return cml_matrixEXP_set(element, row, column, out);

        case CML_MATRIX:
            return cml_matrixMAT_set(element, row, column, out);
    }

    u32 stride = cml_numerictype_size(out->type);
    void *location;
    //location = &(((u8*)out->data)[row*stride*out->columns + column*stride]);
    location = ((u8*)out->data) + row*stride*out->columns + column*stride;

    switch(out->type) {
        case CML_U8:
            *(u8*)location = *(u8*)element;
            break;

        case CML_U16:
            *(u16*)location = *(u16*)element;
            break;

        case CML_U32:
            *(u32*)location = *(u32*)element;
            break;

        case CML_U64:
            *(u64*)location = *(u64*)element;
            break;

        case CML_I8:
            *(i8*)location = *(i8*)element;
            break;

        case CML_I16:
            *(i16*)location = *(i16*)element;
            break;

        case CML_I32:
            *(i32*)location = *(i32*)element;
            break;

        case CML_I64:
            *(i64*)location = *(i64*)element;
            break;

        case CML_F32:
            *(f32*)location = *(f32*)element;
            break;

        case CML_F64:
            *(f64*)location = *(f64*)element;
            break;

        case CML_CF32:
            *(cf32*)location = *(cf32*)element;
            break;
        
        case CML_CF64:
            *(cf64*)location = *(cf64*)element;
            break;

        case CML_BIGINT:
        case CML_FRACTION:
        case CML_COMPLEX:
        case CML_EXPRESSION:
        case CML_MATRIX:
            memcpy(location, element, stride);
            break;
    }

    return CML_SUCCESS;
}

