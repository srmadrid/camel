/**
 * @file m.h
 * 
 * @brief Implementation of CAMEL's basic type, the matrix.
 *
 * @author Sergio Madrid
 * @date 2/3/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/core/matrix/matrix.h"


CML_Status cml_matrix_init(CML_Allocator *allocator, u32 rows, u32 columns, b8 rowmajor, CML_NumericType type, CML_Matrix *matrix) {
    if (allocator == NULL || matrix == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (rows == 0 || columns == 0) {
        return CML_ERR_INVALID_SIZE;
    }

    u32 stride = cml_numerictype_size(type);

    matrix->data = allocator->calloc(rows*columns, stride, allocator->context);
    if (matrix->data == NULL) {
        return CML_ERR_CALLOC;
    }

    matrix->allocator = allocator;
    matrix->type = type;
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->rowmajor = rowmajor;

    return CML_SUCCESS;
}


CML_Status cml_matrix_init0(CML_Allocator *allocator, u32 rows, u32 columns, b8 rowmajor, CML_NumericType type, CML_Matrix *matrix) {
    if (allocator == NULL || matrix == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (rows == 0 || columns == 0) {
        return CML_ERR_INVALID_SIZE;
    }

    u32 stride = cml_numerictype_size(type);
    u32 size = rows*columns;

    matrix->data = allocator->calloc(size, stride, allocator->context);
    if (matrix->data == NULL) {
        return CML_ERR_MALLOC;
    }

    switch(type) {
        case CML_BIGINT:
            for (u32 i = 0; i < size; i++) {
                CML_BigInt aux;
                CML_Status result = cml_bigint_init(allocator, 0, &aux);
                if (result != CML_SUCCESS) {
                    for (u32 j = 0; j < i - 1; j++) {
                        cml_bigint_destroy(((u8*)matrix->data) + stride*i);
                    }
                    return result;
                }
            }
            break;
/*
        case CML_FRACTION:
            for (u32 i = 0; i < size; i++) {
                CML_Fraction aux;
                CML_Status result = cml_fraction_init(allocator, 0, &aux);
                if (result != CML_SUCCESS) {
                    for (u32 j = 0; j < i - 1; j++) {
                        cml_fraction_destroy(((u8*)matrix->data) + stride*i);
                    }
                    return result;
                }
            }
            break;

        case CML_COMPLEX:
            for (u32 i = 0; i < size; i++) {
                CML_Complex aux;
                CML_Status result = cml_complex_init(allocator, 0, &aux);
                if (result != CML_SUCCESS) {
                    for (u32 j = 0; j < i - 1; j++) {
                        cml_complex_destroy(((u8*)matrix->data) + stride*i);
                    }
                    return result;
                }
            }
            break; */

        default:
            break;
    }

    matrix->allocator = allocator;
    matrix->type = type;
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->rowmajor = rowmajor;

    return CML_SUCCESS;
}


void cml_matrix_destroy(void *matrix) {
    CML_Matrix *mat = (CML_Matrix*)matrix;
    if (mat != NULL) {
        u32 stride = cml_numerictype_size(mat->type);
        u32 size = mat->rows*mat->columns;
        switch (mat->type) {
            case CML_BIGINT:
                for (u32 i = 0; i < size; i++) {
                    cml_bigint_destroy((u8*)mat->data + i*stride);
                }
                break;

            case CML_FRACTION:
                for (u32 i = 0; i < size; i++) {
                    //cml_fraction_destroy((u8*)mat->data + i*stride);
                }
                break;

            case CML_COMPLEX:
                for (u32 i = 0; i < size; i++) {
                    //cml_complex_destroy((u8*)mat->data + i*stride);
                }
                break;

            default:
                break;
        }
        mat->allocator->free(mat->data, mat->allocator->context);
        mat->data = NULL;
        mat->allocator = NULL;
        mat->rows = 0;
        mat->columns = 0;
    }
}


CML_Status cml_matrix_set(void *element, u32 row, u32 column, CML_Matrix *out) {
    if (out == NULL || element == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (row >= out->rows || column >= out->columns) {
        return CML_ERR_INVALID_INDEX;
    }

    u32 stride = cml_numerictype_size(out->type);
    void *location;
    if (out->rowmajor) {
        location = ((u8*)out->data) + row*stride*out->columns + column*stride;
    } else {
        location = ((u8*)out->data) + row*stride + column*stride*out->rows;
    }

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

        case CML_COMPLEXF32:
            *(cf32*)location = *(cf32*)element;
            break;
        
        case CML_COMPLEXF64:
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


CML_Status cml_matrix_select(CML_Allocator *allocator, const CML_Matrix *A, CML_Matrix *p, CML_Matrix *q, b8 rowmajor, CML_Matrix *out) {
    if (A == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (allocator == NULL) {
        allocator = A->allocator;
    }

    // Check if p and q are vectors if they are not NULL.
    if ((p != NULL && (p->rows != 1 && p->columns != 1)) || 
        (q != NULL && (q->rows != 1 && q->columns != 1))) {
        return CML_ERR_EXPECTED_VECTOR;
    }
    // If p is not null, check all the elements are positive integers, and no 
    // bigger than the respective A dimensions
    b8 pcreated;
    u32 plength;
    u32 pstride;
    if (p != NULL) {
        pcreated = false;
        plength = p->rows > p->columns ? p->rows : p->columns;
        pstride = cml_numerictype_size(p->type);
        switch(p->type) {
            case CML_U8:
                for (u32 i = 0; i < plength; i++) {
                    u8 number = *((u8*)p->data + i*pstride);
                    if (number >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_U16:
                for (u32 i = 0; i < plength; i++) {
                    u16 number = *((u16*)((u8*)p->data + i*pstride));
                    if (number >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_U32:
                for (u32 i = 0; i < plength; i++) {
                    u32 number = *((u32*)((u8*)p->data + i*pstride));
                    if (number >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_U64:
                for (u32 i = 0; i < plength; i++) {
                    u64 number = *((u64*)((u8*)p->data + i*pstride));
                    if (number >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_I8:
                for (u32 i = 0; i < plength; i++) {
                    i8 number = *((i8*)((u8*)p->data + i*pstride));
                    if (number < 0 || number >= (i64)A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_I16:
                for (u32 i = 0; i < plength; i++) {
                    i16 number = *((i16*)((u8*)p->data + i*pstride));
                    if (number < 0 || number >= (i64)A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_I32:
                for (u32 i = 0; i < plength; i++) {
                    i32 number = *((i32*)((u8*)p->data + i*pstride));
                    if (number < 0 || number >= (i64)A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_I64:
                for (u32 i = 0; i < plength; i++) {
                    i64 number = *((i64*)((u8*)p->data + i*pstride));
                    if (number < 0 || number >= (i64)A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_F32:
                for (u32 i = 0; i < plength; i++) {
                    f32 number = *((f32*)((u8*)p->data + i*pstride));
                    if (rintf(number) != number || number < 0 || number >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_F64:
                for (u32 i = 0; i < plength; i++) {
                    f64 number = *((f64*)((u8*)p->data + i*pstride));
                    if (rint(number) != number || number < 0 || number >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_COMPLEXF32:
                for (u32 i = 0; i < plength; i++) {
                    cf32 number = *((cf32*)((u8*)p->data + i*pstride));
                    if (cimagf(number) != 0 || 
                        rintf(crealf(number)) != crealf(number) || 
                        crealf(number) < 0 || crealf(number) >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_COMPLEXF64:
                for (u32 i = 0; i < plength; i++) {
                    cf64 number = *((cf64*)((u8*)p->data + i*pstride));
                    if (cimag(number) != 0 || 
                        rint(creal(number)) != creal(number) || 
                        creal(number) < 0 || creal(number) >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_BIGINT:
                break;

            case CML_FRACTION:
                break;

            case CML_COMPLEX:
            case CML_EXPRESSION:
            case CML_MATRIX:
                break;

        }
    } else {
        pcreated = true;
        plength = A->rows;
        pstride = cml_numerictype_size(CML_U32);
        CML_Status result = cml_matrix_init(allocator, A->rows, 1, true, CML_U32, p);
        if (result != CML_SUCCESS)
            return result;
        for (u32 i = 0; i < A->rows; i++) {
            *((u32*)p->data + i) = i;
        }
    }
    // If q is not null, check all the elements are positive integers, and no 
    // bigger than the respective A dimensions
    b8 qcreated;
    u32 qlength;
    u32 qstride;
    if (q != NULL) {
        qcreated = false;
        qlength = q->rows > q->columns ? q->rows : q->columns;
        qstride = cml_numerictype_size(q->type);
        switch(q->type) {
            case CML_U8:
                for (u32 i = 0; i < qlength; i++) {
                    u8 number = *((u8*)q->data + i*qstride);
                    if (number >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_U16:
                for (u32 i = 0; i < qlength; i++) {
                    u16 number = *((u16*)((u8*)q->data + i*qstride));
                    if (number >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_U32:
                for (u32 i = 0; i < qlength; i++) {
                    u32 number = *((u32*)((u8*)q->data + i*qstride));
                    if (number >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_U64:
                for (u32 i = 0; i < qlength; i++) {
                    u64 number = *((u64*)((u8*)q->data + i*qstride));
                    if (number >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_I8:
                for (u32 i = 0; i < qlength; i++) {
                    i8 number = *((i8*)((u8*)q->data + i*qstride));
                    if (number < 0 || number >= (i64)A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_I16:
                for (u32 i = 0; i < qlength; i++) {
                    i16 number = *((i16*)((u8*)q->data + i*qstride));
                    if (number < 0 || number >= (i64)A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_I32:
                for (u32 i = 0; i < qlength; i++) {
                    i32 number = *((i32*)((u8*)q->data + i*qstride));
                    if (number < 0 || number >= (i64)A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_I64:
                for (u32 i = 0; i < qlength; i++) {
                    i64 number = *((i64*)((u8*)q->data + i*qstride));
                    if (number < 0 || number >= (i64)A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_F32:
                for (u32 i = 0; i < qlength; i++) {
                    f32 number = *((f32*)((u8*)q->data + i*qstride));
                    if (rintf(number) != number || number < 0 || number >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_F64:
                for (u32 i = 0; i < qlength; i++) {
                    f64 number = *((f64*)((u8*)q->data + i*qstride));
                    if (rint(number) != number || number < 0 || number >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_COMPLEXF32:
                for (u32 i = 0; i < qlength; i++) {
                    cf32 number = *((cf32*)((u8*)q->data + i*qstride));
                    if (cimagf(number) != 0 || 
                        rintf(crealf(number)) != crealf(number) || 
                        crealf(number) < 0 || crealf(number) >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_COMPLEXF64:
                for (u32 i = 0; i < qlength; i++) {
                    cf64 number = *((cf64*)((u8*)q->data + i*qstride));
                    if (cimag(number) != 0 || 
                        rint(creal(number)) != creal(number) || 
                        creal(number) < 0 || creal(number) >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_BIGINT:
                break;

            case CML_FRACTION:
                break;

            case CML_COMPLEX:
            case CML_EXPRESSION:
            case CML_MATRIX:
                break;

        }
    } else {
        qcreated = true;
        qlength = A->columns;
        qstride = cml_numerictype_size(CML_U32);
        CML_Status result = cml_matrix_init(allocator, A->columns, 1, true, CML_U32, q);
        if (result != CML_SUCCESS)
            return result;
        for (u32 i = 0; i < A->columns; i++) {
            *((u32*)q->data + i) = i;
        }
    }

    // Initialize out
    cml_matrix_init(allocator, plength, qlength, rowmajor, A->type, out);
    // Set out's elements
    if (rowmajor) {
        for (u32 r = 0; r < out->rows; r++) {
            for (u32 c = 0; c < out->columns; c++) {
                switch(out->type) {
                    case CML_BIGINT:
                        break;

                    case CML_FRACTION:
                        break;

                    case CML_COMPLEX:
                        break;

                    default:
                        cml_matrix_set(cml_matrix_get(*(u32*)((u8*)p->data + r*pstride), *(u32*)((u8*)q->data + c*qstride), A), r, c, out);
                        break;
                }
            }
        }
    } else {
        for (u32 c = 0; c < out->columns; c++) {
            for (u32 r = 0; r < out->rows; r++) {
                switch(out->type) {
                    case CML_BIGINT:
                        break;

                    case CML_FRACTION:
                        break;

                    case CML_COMPLEX:
                        break;

                    default:
                        cml_matrix_set(cml_matrix_get(*(u32*)((u8*)p->data + r*pstride), *(u32*)((u8*)q->data + c*qstride), A), r, c, out);
                        break;
                }
            }
        }
    }

    if (pcreated) {
        cml_matrix_destroy(p);
    }
    if (qcreated) {
        cml_matrix_destroy(q);
    }
    return CML_SUCCESS;
}


void *cml_matrix_get(u32 row, u32 column, const CML_Matrix *out) {
    if (out == NULL) {
        return NULL;
    }

    if (row >= out->rows || column >= out->columns) {
        return NULL;
    }

    u32 stride = cml_numerictype_size(out->type);
    void *element;
    if (out->rowmajor) {
        element = ((u8*)out->data) + row*stride*out->columns + column*stride;
    } else {
        element = ((u8*)out->data) + row*stride + column*stride*out->rows;
    }
    return element;
}


CML_Status cml_matrix_add(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, b8 rowmajor, CML_Matrix *out) {
    if (left == NULL || right == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (left->type != right->type) {
        // Maybe add type promotion in the future
        return CML_ERR_INCOMPATIBLE_TYPES;
    }

    b8 oneIsScalar;
    b8 leftIsScalar;
    u32 outRows;
    u32 outColumns;
    if (left->rows != right->rows || left->columns != right->columns) {
        if ((left->rows == 1 && left->columns == 1) || 
            (right->rows == 1 && right->columns == 1)) {
            oneIsScalar = true;
            outRows = left->rows > right->rows ? left->rows : right->rows;
            outColumns = left->columns > right->columns ? left->columns : right->columns;
            leftIsScalar = left->rows == 1 ? true : false;
        } else {
        return CML_ERR_INCOMPATIBLE_SIZE;
        }
    } else {
        oneIsScalar = false;
        outRows = left->rows;
        outColumns = left->columns;
    }

    if (allocator == NULL) {
        allocator = left->allocator;
    }

    CML_Status result = cml_matrix_init(allocator, outRows, outColumns, rowmajor, left->type, out);
    if (result != CML_SUCCESS) {
        return result;
    }

    switch (out->type) {
        case CML_U8:
            if (oneIsScalar) {
                u8 scalar;
                if (leftIsScalar) {
                    scalar = *(u8*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u8 number = *(u8*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u8 number = *(u8*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(u8*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u8 number = *(u8*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u8 number = *(u8*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            u8 number = *(u8*)cml_matrix_get(r, c, left);
                            number += *(u8*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            u8 number = *(u8*)cml_matrix_get(r, c, left);
                            number += *(u8*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_U16:
            if (oneIsScalar) {
                u16 scalar;
                if (leftIsScalar) {
                    scalar = *(u16*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u16 number = *(u16*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u16 number = *(u16*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(u16*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u16 number = *(u16*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u16 number = *(u16*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            u16 number = *(u16*)cml_matrix_get(r, c, left);
                            number += *(u16*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            u16 number = *(u16*)cml_matrix_get(r, c, left);
                            number += *(u16*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_U32:
            if (oneIsScalar) {
                u32 scalar;
                if (leftIsScalar) {
                    scalar = *(u32*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u32 number = *(u32*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u32 number = *(u32*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(u32*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u32 number = *(u32*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u32 number = *(u32*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            u32 number = *(u32*)cml_matrix_get(r, c, left);
                            number += *(u32*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            u32 number = *(u32*)cml_matrix_get(r, c, left);
                            number += *(u32*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_U64:
            if (oneIsScalar) {
                u64 scalar;
                if (leftIsScalar) {
                    scalar = *(u64*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u64 number = *(u64*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u64 number = *(u64*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(u64*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u64 number = *(u64*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u64 number = *(u64*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            u64 number = *(u64*)cml_matrix_get(r, c, left);
                            number += *(u64*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            u64 number = *(u64*)cml_matrix_get(r, c, left);
                            number += *(u64*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_I8:
            if (oneIsScalar) {
                i8 scalar;
                if (leftIsScalar) {
                    scalar = *(i8*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i8 number = *(i8*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i8 number = *(i8*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(i8*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i8 number = *(i8*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i8 number = *(i8*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            i8 number = *(i8*)cml_matrix_get(r, c, left);
                            number += *(i8*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            i8 number = *(i8*)cml_matrix_get(r, c, left);
                            number += *(i8*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_I16:
            if (oneIsScalar) {
                i16 scalar;
                if (leftIsScalar) {
                    scalar = *(i16*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i16 number = *(i16*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i16 number = *(i16*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(i16*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i16 number = *(i16*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i16 number = *(i16*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            i16 number = *(i16*)cml_matrix_get(r, c, left);
                            number += *(i16*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            i16 number = *(i16*)cml_matrix_get(r, c, left);
                            number += *(i16*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_I32:
            if (oneIsScalar) {
                i32 scalar;
                if (leftIsScalar) {
                    scalar = *(i32*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i32 number = *(i32*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i32 number = *(i32*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(i32*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i32 number = *(i32*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i32 number = *(i32*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            i32 number = *(i32*)cml_matrix_get(r, c, left);
                            number += *(i32*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            i32 number = *(i32*)cml_matrix_get(r, c, left);
                            number += *(i32*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_I64:
            if (oneIsScalar) {
                i64 scalar;
                if (leftIsScalar) {
                    scalar = *(i64*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i64 number = *(i64*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i64 number = *(i64*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(i64*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i64 number = *(i64*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i64 number = *(i64*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            i64 number = *(i64*)cml_matrix_get(r, c, left);
                            number += *(i64*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            i64 number = *(i64*)cml_matrix_get(r, c, left);
                            number += *(i64*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_F32:
            if (oneIsScalar) {
                f32 scalar;
                if (leftIsScalar) {
                    scalar = *(f32*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                f32 number = *(f32*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                f32 number = *(f32*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(f32*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                f32 number = *(f32*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                f32 number = *(f32*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            f32 number = *(f32*)cml_matrix_get(r, c, left);
                            number += *(f32*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            f32 number = *(f32*)cml_matrix_get(r, c, left);
                            number += *(f32*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_F64:
            if (oneIsScalar) {
                f64 scalar;
                if (leftIsScalar) {
                    scalar = *(f64*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                f64 number = *(f64*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                f64 number = *(f64*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(f64*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                f64 number = *(f64*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                f64 number = *(f64*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            f64 number = *(f64*)cml_matrix_get(r, c, left);
                            number += *(f64*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            f64 number = *(f64*)cml_matrix_get(r, c, left);
                            number += *(f64*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_COMPLEXF32:
            if (oneIsScalar) {
                cf32 scalar;
                if (leftIsScalar) {
                    scalar = *(cf32*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                cf32 number = *(cf32*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                cf32 number = *(cf32*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(cf32*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                cf32 number = *(cf32*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                cf32 number = *(cf32*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            cf32 number = *(cf32*)cml_matrix_get(r, c, left);
                            number += *(cf32*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            cf32 number = *(cf32*)cml_matrix_get(r, c, left);
                            number += *(cf32*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_COMPLEXF64:
            if (oneIsScalar) {
                cf64 scalar;
                if (leftIsScalar) {
                    scalar = *(cf64*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                cf64 number = *(cf64*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                cf64 number = *(cf64*)cml_matrix_get(r, c, right);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(cf64*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                cf64 number = *(cf64*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                cf64 number = *(cf64*)cml_matrix_get(r, c, left);
                                number += scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            cf64 number = *(cf64*)cml_matrix_get(r, c, left);
                            number += *(cf64*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            cf64 number = *(cf64*)cml_matrix_get(r, c, left);
                            number += *(cf64*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_BIGINT:
            break;

        case CML_FRACTION:
            break;

        case CML_COMPLEX:
        case CML_EXPRESSION:
        case CML_MATRIX:
            break;
    }

    return CML_SUCCESS;
}


CML_Status cml_matrix_add_inplace(const CML_Matrix *right, CML_Matrix *out) {
    if (right == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (right->type != out->type) {
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

    switch (out->type) {
        case CML_U8:
            if (rightIsScalar) {
                u8 scalar = *(u8*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(u8*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(u8*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(u8*)cml_matrix_get(r, c, out) += *(u8*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(u8*)cml_matrix_get(r, c, out) += *(u8*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_U16:
            if (rightIsScalar) {
                u16 scalar = *(u16*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(u16*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(u16*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(u16*)cml_matrix_get(r, c, out) += *(u16*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(u16*)cml_matrix_get(r, c, out) += *(u16*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_U32:
            if (rightIsScalar) {
                u32 scalar = *(u32*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(u32*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(u32*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(u32*)cml_matrix_get(r, c, out) += *(u32*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(u32*)cml_matrix_get(r, c, out) += *(u32*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_U64:
            if (rightIsScalar) {
                u64 scalar = *(u64*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(u64*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(u64*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(u64*)cml_matrix_get(r, c, out) += *(u64*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(u64*)cml_matrix_get(r, c, out) += *(u64*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_I8:
            if (rightIsScalar) {
                i8 scalar = *(i8*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(i8*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(i8*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(i8*)cml_matrix_get(r, c, out) += *(i8*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(i8*)cml_matrix_get(r, c, out) += *(i8*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_I16:
            if (rightIsScalar) {
                i16 scalar = *(i16*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(i16*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(i16*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(i16*)cml_matrix_get(r, c, out) += *(i16*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(i16*)cml_matrix_get(r, c, out) += *(i16*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_I32:
            if (rightIsScalar) {
                i32 scalar = *(i32*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(i32*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(i32*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(i32*)cml_matrix_get(r, c, out) += *(i32*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(i32*)cml_matrix_get(r, c, out) += *(i32*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_I64:
            if (rightIsScalar) {
                i64 scalar = *(i64*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(i64*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(i64*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(i64*)cml_matrix_get(r, c, out) += *(i64*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(i64*)cml_matrix_get(r, c, out) += *(i64*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_F32:
            if (rightIsScalar) {
                f32 scalar = *(f32*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(f32*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(f32*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(f32*)cml_matrix_get(r, c, out) += *(f32*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(f32*)cml_matrix_get(r, c, out) += *(f32*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_F64:
            if (rightIsScalar) {
                f64 scalar = *(f64*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(f64*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(f64*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(f64*)cml_matrix_get(r, c, out) += *(f64*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(f64*)cml_matrix_get(r, c, out) += *(f64*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_COMPLEXF32:
            if (rightIsScalar) {
                cf32 scalar = *(cf32*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(cf32*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(cf32*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(cf32*)cml_matrix_get(r, c, out) += *(cf32*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(cf32*)cml_matrix_get(r, c, out) += *(cf32*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_COMPLEXF64:
            if (rightIsScalar) {
                cf64 scalar = *(cf64*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(cf64*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(cf64*)cml_matrix_get(r, c, out) += scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(cf64*)cml_matrix_get(r, c, out) += *(cf64*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(cf64*)cml_matrix_get(r, c, out) += *(cf64*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_BIGINT:
            break;

        case CML_FRACTION:
            break;

        case CML_COMPLEX:
        case CML_EXPRESSION:
        case CML_MATRIX:
            break;
    }

    return CML_SUCCESS;
}


CML_Status cml_matrix_sub(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, b8 rowmajor, CML_Matrix *out) {
    if (left == NULL || right == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (left->type != right->type) {
        // Maybe add type promotion in the future
        return CML_ERR_INCOMPATIBLE_TYPES;
    }

    b8 oneIsScalar;
    b8 leftIsScalar;
    u32 outRows;
    u32 outColumns;
    if (left->rows != right->rows || left->columns != right->columns) {
        if ((left->rows == 1 && left->columns == 1) || 
            (right->rows == 1 && right->columns == 1)) {
            oneIsScalar = true;
            outRows = left->rows > right->rows ? left->rows : right->rows;
            outColumns = left->columns > right->columns ? left->columns : right->columns;
            leftIsScalar = left->rows == 1 ? true : false;
        } else {
        return CML_ERR_INCOMPATIBLE_SIZE;
        }
    } else {
        oneIsScalar = false;
        outRows = left->rows;
        outColumns = left->columns;
    }

    if (allocator == NULL) {
        allocator = left->allocator;
    }

    CML_Status result = cml_matrix_init(allocator, outRows, outColumns, rowmajor, left->type, out);
    if (result != CML_SUCCESS) {
        return result;
    }

    switch (out->type) {
        case CML_U8:
            if (oneIsScalar) {
                u8 scalar;
                if (leftIsScalar) {
                    scalar = *(u8*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u8 number = *(u8*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u8 number = *(u8*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(u8*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u8 number = *(u8*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u8 number = *(u8*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            u8 number = *(u8*)cml_matrix_get(r, c, left);
                            number -= *(u8*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            u8 number = *(u8*)cml_matrix_get(r, c, left);
                            number -= *(u8*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_U16:
            if (oneIsScalar) {
                u16 scalar;
                if (leftIsScalar) {
                    scalar = *(u16*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u16 number = *(u16*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u16 number = *(u16*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(u16*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u16 number = *(u16*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u16 number = *(u16*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            u16 number = *(u16*)cml_matrix_get(r, c, left);
                            number -= *(u16*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            u16 number = *(u16*)cml_matrix_get(r, c, left);
                            number -= *(u16*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_U32:
            if (oneIsScalar) {
                u32 scalar;
                if (leftIsScalar) {
                    scalar = *(u32*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u32 number = *(u32*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u32 number = *(u32*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(u32*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u32 number = *(u32*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u32 number = *(u32*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            u32 number = *(u32*)cml_matrix_get(r, c, left);
                            number -= *(u32*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            u32 number = *(u32*)cml_matrix_get(r, c, left);
                            number -= *(u32*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_U64:
            if (oneIsScalar) {
                u64 scalar;
                if (leftIsScalar) {
                    scalar = *(u64*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u64 number = *(u64*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u64 number = *(u64*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(u64*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u64 number = *(u64*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u64 number = *(u64*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            u64 number = *(u64*)cml_matrix_get(r, c, left);
                            number -= *(u64*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            u64 number = *(u64*)cml_matrix_get(r, c, left);
                            number -= *(u64*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_I8:
            if (oneIsScalar) {
                i8 scalar;
                if (leftIsScalar) {
                    scalar = *(i8*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i8 number = *(i8*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i8 number = *(i8*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(i8*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i8 number = *(i8*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i8 number = *(i8*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            i8 number = *(i8*)cml_matrix_get(r, c, left);
                            number -= *(i8*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            i8 number = *(i8*)cml_matrix_get(r, c, left);
                            number -= *(i8*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_I16:
            if (oneIsScalar) {
                i16 scalar;
                if (leftIsScalar) {
                    scalar = *(i16*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i16 number = *(i16*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i16 number = *(i16*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(i16*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i16 number = *(i16*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i16 number = *(i16*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            i16 number = *(i16*)cml_matrix_get(r, c, left);
                            number -= *(i16*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            i16 number = *(i16*)cml_matrix_get(r, c, left);
                            number -= *(i16*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_I32:
            if (oneIsScalar) {
                i32 scalar;
                if (leftIsScalar) {
                    scalar = *(i32*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i32 number = *(i32*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i32 number = *(i32*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(i32*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i32 number = *(i32*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i32 number = *(i32*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            i32 number = *(i32*)cml_matrix_get(r, c, left);
                            number -= *(i32*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            i32 number = *(i32*)cml_matrix_get(r, c, left);
                            number -= *(i32*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_I64:
            if (oneIsScalar) {
                i64 scalar;
                if (leftIsScalar) {
                    scalar = *(i64*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i64 number = *(i64*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i64 number = *(i64*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(i64*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i64 number = *(i64*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i64 number = *(i64*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            i64 number = *(i64*)cml_matrix_get(r, c, left);
                            number -= *(i64*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            i64 number = *(i64*)cml_matrix_get(r, c, left);
                            number -= *(i64*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_F32:
            if (oneIsScalar) {
                f32 scalar;
                if (leftIsScalar) {
                    scalar = *(f32*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                f32 number = *(f32*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                f32 number = *(f32*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(f32*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                f32 number = *(f32*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                f32 number = *(f32*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            f32 number = *(f32*)cml_matrix_get(r, c, left);
                            number -= *(f32*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            f32 number = *(f32*)cml_matrix_get(r, c, left);
                            number -= *(f32*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_F64:
            if (oneIsScalar) {
                f64 scalar;
                if (leftIsScalar) {
                    scalar = *(f64*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                f64 number = *(f64*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                f64 number = *(f64*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(f64*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                f64 number = *(f64*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                f64 number = *(f64*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            f64 number = *(f64*)cml_matrix_get(r, c, left);
                            number -= *(f64*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            f64 number = *(f64*)cml_matrix_get(r, c, left);
                            number -= *(f64*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_COMPLEXF32:
            if (oneIsScalar) {
                cf32 scalar;
                if (leftIsScalar) {
                    scalar = *(cf32*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                cf32 number = *(cf32*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                cf32 number = *(cf32*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(cf32*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                cf32 number = *(cf32*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                cf32 number = *(cf32*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            cf32 number = *(cf32*)cml_matrix_get(r, c, left);
                            number -= *(cf32*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            cf32 number = *(cf32*)cml_matrix_get(r, c, left);
                            number -= *(cf32*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_COMPLEXF64:
            if (oneIsScalar) {
                cf64 scalar;
                if (leftIsScalar) {
                    scalar = *(cf64*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                cf64 number = *(cf64*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                cf64 number = *(cf64*)cml_matrix_get(r, c, right);
                                scalar -= number;
                                cml_matrix_set(&scalar, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(cf64*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                cf64 number = *(cf64*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                cf64 number = *(cf64*)cml_matrix_get(r, c, left);
                                number -= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            cf64 number = *(cf64*)cml_matrix_get(r, c, left);
                            number -= *(cf64*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            cf64 number = *(cf64*)cml_matrix_get(r, c, left);
                            number -= *(cf64*)cml_matrix_get(r, c, right);
                            cml_matrix_set(&number, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_BIGINT:
            break;

        case CML_FRACTION:
            break;

        case CML_COMPLEX:
        case CML_EXPRESSION:
        case CML_MATRIX:
            break;
    }

    return CML_SUCCESS;
}


CML_Status cml_matrix_sub_inplace(const CML_Matrix *right, CML_Matrix *out) {
    if (right == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (right->type != out->type) {
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

    switch (out->type) {
        case CML_U8:
            if (rightIsScalar) {
                u8 scalar = *(u8*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(u8*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(u8*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(u8*)cml_matrix_get(r, c, out) -= *(u8*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(u8*)cml_matrix_get(r, c, out) -= *(u8*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_U16:
            if (rightIsScalar) {
                u16 scalar = *(u16*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(u16*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(u16*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(u16*)cml_matrix_get(r, c, out) -= *(u16*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(u16*)cml_matrix_get(r, c, out) -= *(u16*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_U32:
            if (rightIsScalar) {
                u32 scalar = *(u32*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(u32*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(u32*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(u32*)cml_matrix_get(r, c, out) -= *(u32*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(u32*)cml_matrix_get(r, c, out) -= *(u32*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_U64:
            if (rightIsScalar) {
                u64 scalar = *(u64*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(u64*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(u64*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(u64*)cml_matrix_get(r, c, out) -= *(u64*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(u64*)cml_matrix_get(r, c, out) -= *(u64*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_I8:
            if (rightIsScalar) {
                i8 scalar = *(i8*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(i8*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(i8*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(i8*)cml_matrix_get(r, c, out) -= *(i8*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(i8*)cml_matrix_get(r, c, out) -= *(i8*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_I16:
            if (rightIsScalar) {
                i16 scalar = *(i16*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(i16*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(i16*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(i16*)cml_matrix_get(r, c, out) -= *(i16*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(i16*)cml_matrix_get(r, c, out) -= *(i16*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_I32:
            if (rightIsScalar) {
                i32 scalar = *(i32*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(i32*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(i32*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(i32*)cml_matrix_get(r, c, out) -= *(i32*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(i32*)cml_matrix_get(r, c, out) -= *(i32*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_I64:
            if (rightIsScalar) {
                i64 scalar = *(i64*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(i64*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(i64*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(i64*)cml_matrix_get(r, c, out) -= *(i64*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(i64*)cml_matrix_get(r, c, out) -= *(i64*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_F32:
            if (rightIsScalar) {
                f32 scalar = *(f32*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(f32*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(f32*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(f32*)cml_matrix_get(r, c, out) -= *(f32*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(f32*)cml_matrix_get(r, c, out) -= *(f32*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_F64:
            if (rightIsScalar) {
                f64 scalar = *(f64*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(f64*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(f64*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(f64*)cml_matrix_get(r, c, out) -= *(f64*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(f64*)cml_matrix_get(r, c, out) -= *(f64*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_COMPLEXF32:
            if (rightIsScalar) {
                cf32 scalar = *(cf32*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(cf32*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(cf32*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(cf32*)cml_matrix_get(r, c, out) -= *(cf32*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(cf32*)cml_matrix_get(r, c, out) -= *(cf32*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_COMPLEXF64:
            if (rightIsScalar) {
                cf64 scalar = *(cf64*)right->data;
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(cf64*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(cf64*)cml_matrix_get(r, c, out) -= scalar;
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            *(cf64*)cml_matrix_get(r, c, out) -= *(cf64*)cml_matrix_get(r, c, right);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            *(cf64*)cml_matrix_get(r, c, out) -= *(cf64*)cml_matrix_get(r, c, right);
                        }
                    }
                }
            }
            break;

        case CML_BIGINT:
            break;

        case CML_FRACTION:
            break;

        case CML_COMPLEX:
        case CML_EXPRESSION:
        case CML_MATRIX:
            break;
    }

    return CML_SUCCESS;
}


CML_Status cml_matrix_mult(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, b8 rowmajor, CML_Matrix *out) {
    if (left == NULL || right == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (left->type != right->type) {
        // Maybe add type promotion in the future
        return CML_ERR_INCOMPATIBLE_TYPES;
    }

    b8 oneIsScalar;
    b8 leftIsScalar;
    u32 outRows;
    u32 outColumns;
    if (left->columns != right->rows) {
        if ((left->rows == 1 && left->columns == 1) || 
            (right->rows == 1 && right->columns == 1)) {
            oneIsScalar = true;
            outRows = left->rows > right->rows ? left->rows : right->rows;
            outColumns = left->columns > right->columns ? left->columns : right->columns;
            leftIsScalar = left->rows == 1 ? true : false;
        } else {
        return CML_ERR_INCOMPATIBLE_SIZE;
        }
    } else {
        oneIsScalar = false;
        outRows = left->rows;
        outColumns = right->columns;
    }

    if (allocator == NULL) {
        allocator = left->allocator;
    }

    CML_Status result = cml_matrix_init(allocator, outRows, outColumns, rowmajor, left->type, out);
    if (result != CML_SUCCESS) {
        return result;
    }

    switch (out->type) {
        case CML_U8:
            if (oneIsScalar) {
                u8 scalar;
                if (leftIsScalar) {
                    scalar = *(u8*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u8 number = *(u8*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u8 number = *(u8*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(u8*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u8 number = *(u8*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u8 number = *(u8*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            u8 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                u8 number = *(u8*)cml_matrix_get(r, k, left);
                                number *= *(u8*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            u8 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                u8 number = *(u8*)cml_matrix_get(r, k, left);
                                number *= *(u8*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_U16:
            if (oneIsScalar) {
                u16 scalar;
                if (leftIsScalar) {
                    scalar = *(u16*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u16 number = *(u16*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u16 number = *(u16*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(u16*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u16 number = *(u16*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u16 number = *(u16*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            u16 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                u16 number = *(u16*)cml_matrix_get(r, k, left);
                                number *= *(u16*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            u16 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                u16 number = *(u16*)cml_matrix_get(r, k, left);
                                number *= *(u16*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_U32:
            if (oneIsScalar) {
                u32 scalar;
                if (leftIsScalar) {
                    scalar = *(u32*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u32 number = *(u32*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u32 number = *(u32*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(u32*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u32 number = *(u32*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u32 number = *(u32*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            u32 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                u32 number = *(u32*)cml_matrix_get(r, k, left);
                                number *= *(u32*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            u32 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                u32 number = *(u32*)cml_matrix_get(r, k, left);
                                number *= *(u32*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_U64:
            if (oneIsScalar) {
                u64 scalar;
                if (leftIsScalar) {
                    scalar = *(u64*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u64 number = *(u64*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u64 number = *(u64*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(u64*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                u64 number = *(u64*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                u64 number = *(u64*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            u64 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                u64 number = *(u64*)cml_matrix_get(r, k, left);
                                number *= *(u64*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            u64 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                u64 number = *(u64*)cml_matrix_get(r, k, left);
                                number *= *(u64*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_I8:
            if (oneIsScalar) {
                i8 scalar;
                if (leftIsScalar) {
                    scalar = *(i8*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i8 number = *(i8*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i8 number = *(i8*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(i8*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i8 number = *(i8*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i8 number = *(i8*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            i8 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                i8 number = *(i8*)cml_matrix_get(r, k, left);
                                number *= *(i8*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            i8 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                i8 number = *(i8*)cml_matrix_get(r, k, left);
                                number *= *(i8*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_I16:
            if (oneIsScalar) {
                i16 scalar;
                if (leftIsScalar) {
                    scalar = *(i16*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i16 number = *(i16*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i16 number = *(i16*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(i16*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i16 number = *(i16*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i16 number = *(i16*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            i16 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                i16 number = *(i16*)cml_matrix_get(r, k, left);
                                number *= *(i16*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            i16 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                i16 number = *(i16*)cml_matrix_get(r, k, left);
                                number *= *(i16*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_I32:
            if (oneIsScalar) {
                i32 scalar;
                if (leftIsScalar) {
                    scalar = *(i32*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i32 number = *(i32*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i32 number = *(i32*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(i32*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i32 number = *(i32*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i32 number = *(i32*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            i32 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                i32 number = *(i32*)cml_matrix_get(r, k, left);
                                number *= *(i32*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            i32 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                i32 number = *(i32*)cml_matrix_get(r, k, left);
                                number *= *(i32*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_I64:
            if (oneIsScalar) {
                i64 scalar;
                if (leftIsScalar) {
                    scalar = *(i64*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i64 number = *(i64*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i64 number = *(i64*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(i64*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                i64 number = *(i64*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                i64 number = *(i64*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            i64 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                i64 number = *(i64*)cml_matrix_get(r, k, left);
                                number *= *(i64*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            i64 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                i64 number = *(i64*)cml_matrix_get(r, k, left);
                                number *= *(i64*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_F32:
            if (oneIsScalar) {
                f32 scalar;
                if (leftIsScalar) {
                    scalar = *(f32*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                f32 number = *(f32*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                f32 number = *(f32*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(f32*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                f32 number = *(f32*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                f32 number = *(f32*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            f32 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                f32 number = *(f32*)cml_matrix_get(r, k, left);
                                number *= *(f32*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            f32 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                f32 number = *(f32*)cml_matrix_get(r, k, left);
                                number *= *(f32*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_F64:
            if (oneIsScalar) {
                f64 scalar;
                if (leftIsScalar) {
                    scalar = *(f64*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                f64 number = *(f64*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                f64 number = *(f64*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(f64*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                f64 number = *(f64*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                f64 number = *(f64*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            f64 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                f64 number = *(f64*)cml_matrix_get(r, k, left);
                                number *= *(f64*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            f64 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                f64 number = *(f64*)cml_matrix_get(r, k, left);
                                number *= *(f64*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_COMPLEXF32:
            if (oneIsScalar) {
                cf32 scalar;
                if (leftIsScalar) {
                    scalar = *(cf32*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                cf32 number = *(cf32*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                cf32 number = *(cf32*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(cf32*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                cf32 number = *(cf32*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                cf32 number = *(cf32*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            cf32 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                cf32 number = *(cf32*)cml_matrix_get(r, k, left);
                                number *= *(cf32*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            cf32 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                cf32 number = *(cf32*)cml_matrix_get(r, k, left);
                                number *= *(cf32*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_COMPLEXF64:
            if (oneIsScalar) {
                cf64 scalar;
                if (leftIsScalar) {
                    scalar = *(cf64*)left->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                cf64 number = *(cf64*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                cf64 number = *(cf64*)cml_matrix_get(r, c, right);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                } else  {
                    scalar = *(cf64*)right->data;
                    if (out->rowmajor) {
                        for (u32 r = 0; r < out->rows; r++) {
                            for (u32 c = 0; c < out->columns; c++) {
                                cf64 number = *(cf64*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    } else {
                        for (u32 c = 0; c < out->columns; c++) {
                            for (u32 r = 0; r < out->rows; r++) {
                                cf64 number = *(cf64*)cml_matrix_get(r, c, left);
                                number *= scalar;
                                cml_matrix_set(&number, r, c, out);
                            }
                        }
                    }
                }
            } else {
                if (out->rowmajor) {
                    for (u32 r = 0; r < out->rows; r++) {
                        for (u32 c = 0; c < out->columns; c++) {
                            cf64 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                cf64 number = *(cf64*)cml_matrix_get(r, k, left);
                                number *= *(cf64*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                } else {
                    for (u32 c = 0; c < out->columns; c++) {
                        for (u32 r = 0; r < out->rows; r++) {
                            cf64 element = 0;
                            for (u32 k = 0; k < left->columns; k++) {
                                cf64 number = *(cf64*)cml_matrix_get(r, k, left);
                                number *= *(cf64*)cml_matrix_get(k, c, right);
                                element += number;
                            }
                            cml_matrix_set(&element, r, c, out);
                        }
                    }
                }
            }
            break;

        case CML_BIGINT:
        case CML_FRACTION:
        case CML_COMPLEX:
        case CML_EXPRESSION:
        case CML_MATRIX:
            break;
    }

    return CML_SUCCESS;
}


CML_Status cml_matrix_print(const CML_Matrix *matrix) {
    if (matrix == NULL) {
        return CML_ERR_NULL_PTR;
    }

    u32 maxDigits = 0;
    u32 size = matrix->rows*matrix->columns; 
    u32 *digits = matrix->allocator->malloc(sizeof(u32)*size, matrix->allocator->context);
    if (digits == NULL) {
        return CML_ERR_MALLOC;
    }
    u32 stride = cml_numerictype_size(matrix->type);
    switch(matrix->type) {
        case CML_U8:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                u8 number = *((u8*)matrix->data + i*stride);
                if (number == 0) count++;
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    u8 number = *(u8*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%u ", number);
                }
                printf("\n");
            }
            break;

        case CML_U16:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                u16 number = *((u16*)((u8*)matrix->data + i*stride));
                if (number == 0) count++;
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    u16 number = *(u16*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%u ", number);
                }
                printf("\n");
            }
            break;

        case CML_U32:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                u32 number = *((u32*)((u8*)matrix->data + i*stride));
                if (number == 0) count++;
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    u32 number = *(u32*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%u ", number);
                }
                printf("\n");
            }
            break;

        case CML_U64:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                u64 number = *((u64*)((u8*)matrix->data + i*stride));
                if (number == 0) count++;
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    u64 number = *(u64*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%lu ", number);
                }
                printf("\n");
            }
            break;

        case CML_I8:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                i8 number = *((i8*)((u8*)matrix->data + i*stride));
                if (number < 0)
                    count++;
                if (number == 0) count++;
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    i8 number = *(i8*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%d ", number);
                }
                printf("\n");
            }
            break;

        case CML_I16:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                i16 number = *((i16*)((u8*)matrix->data + i*stride));
                if (number < 0)
                    count++;
                if (number == 0) count++;
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    i16 number = *(i16*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%d ", number);
                }
                printf("\n");
            }
            break;

        case CML_I32:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                i32 number = *((i32*)((u8*)matrix->data + i*stride));
                if (number < 0)
                    count++;
                if (number == 0) count++;
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    i32 number = *(i32*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%d ", number);
                }
                printf("\n");
            }
            break;

        case CML_I64:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                i64 number = *((i64*)((u8*)matrix->data + i*stride));
                if (number < 0)
                    count++;
                if (number == 0) count++;
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    i64 number = *(i64*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%ld ", number);
                }
                printf("\n");
            }
            break;

        case CML_F32:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                f32 number = *((f32*)((u8*)matrix->data + i*stride));
                i32 numberi = number;
                if (number < 0)
                    count++;
                if (numberi == 0) count++;
                while (numberi != 0) {
                    numberi /= 10;
                    count++;
                }
                count += 7;
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    f32 number = *(f32*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%0.6f ", number);
                }
                printf("\n");
            }
            break;

        case CML_F64:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                f64 number = *((f64*)((u8*)matrix->data + i*stride));
                i64 numberi = number;
                if (number < 0)
                    count++;
                if (numberi == 0) count++;
                while (numberi != 0) {
                    numberi /= 10;
                    count++;
                }
                count += 7;
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    f64 number = *(f64*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%0.6f ", number);
                }
                printf("\n");
            }
            break;

        case CML_COMPLEXF32:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                cf32 number = *((cf32*)((u8*)matrix->data + i*stride));
                f32 a = crealf(number);
                f32 b = cimagf(number);
                i32 ai = a;
                i32 bi = b;
                if (a < 0)
                    count++;
                count += 7; // a decimals and .
                if (ai == 0) count++;
                while (ai != 0) {
                    ai /= 10;
                    count++;
                }
                count += 9; // b decimals, ., i and +/-
                if (bi == 0) count++;
                while (bi != 0) {
                    bi /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    cf32 number = *(cf32*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    if (cimagf(number) >= 0) {
                        printf("%0.6f+%0.6fi ", crealf(number), cimagf(number));
                    } else {
                        printf("%0.6f-%0.6fi ", crealf(number), fabs(cimagf(number)));
                    }
                }
                printf("\n");
            }
            break;

        case CML_COMPLEXF64:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                cf64 number = *((cf64*)((u8*)matrix->data + i*stride));
                f64 a = crealf(number);
                f64 b = cimagf(number);
                i64 ai = a;
                i64 bi = b;
                if (a < 0)
                    count++;
                count += 7; // a decimals and .
                if (ai == 0) count++;
                while (ai != 0) {
                    ai /= 10;
                    count++;
                }
                count += 9; // b decimals, ., i and +/-
                if (bi == 0) count++;
                while (bi != 0) {
                    bi /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    cf64 number = *(cf64*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    if (cimagf(number) >= 0) {
                        printf("%0.6f+%0.6fi ", creal(number), cimag(number));
                    } else {
                        printf("%0.6f-%0.6fi ", creal(number), fabs(cimag(number)));
                    }
                }
                printf("\n");
            }
            break;

        default: // Todo the arbitrary precision types once they are implemented
            break;
    }

    matrix->allocator->free(digits, matrix->allocator->context);
    return CML_SUCCESS;
}

