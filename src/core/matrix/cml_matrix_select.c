/** @file cml_matrix_select.c
 * 
 * @brief Select function for matrices.
 *
 * @author Sergio Madrid
 * @date 28/4/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/core/matrix/matrix.h"


CML_Status cml_matrix_select(CML_Allocator *allocator, const CML_Matrix *A, CML_Matrix *p, CML_Matrix *q, CML_Matrix *out) {
    if (A == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    // If allocator is NULL, out is already initialized. If p or q are NULL,
    // use out's allocator.
    if (allocator == NULL) {
        allocator = out->allocator;
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
                    u8 number = p->u8d[i];
                    if (number >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_U16:
                for (u32 i = 0; i < plength; i++) {
                    u16 number = p->u16d[i];
                    if (number >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_U32:
                for (u32 i = 0; i < plength; i++) {
                    u32 number = p->u32d[i];
                    if (number >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_U64:
                for (u32 i = 0; i < plength; i++) {
                    u64 number = p->u64d[i];
                    if (number >= A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_I8:
                for (u32 i = 0; i < plength; i++) {
                    i8 number = p->i8d[i];
                    if (number < 0 || number >= (i64)A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_I16:
                for (u32 i = 0; i < plength; i++) {
                    i16 number = p->i16d[i];
                    if (number < 0 || number >= (i64)A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_I32:
                for (u32 i = 0; i < plength; i++) {
                    i32 number = p->i32d[i];
                    if (number < 0 || number >= (i64)A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_I64:
                for (u32 i = 0; i < plength; i++) {
                    i64 number = p->i64d[i];
                    if (number < 0 || number >= (i64)A->rows) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            default:
                return CML_ERR_INCOMPATIBLE_TYPES;
        }
    } else {
        pcreated = true;
        plength = A->rows;
        pstride = sizeof(u32);
        CML_Status result = cml_matrix_init(allocator, A->rows, 1, CML_U32, p);
        if (result != CML_SUCCESS)
            return result;
        for (u32 i = 0; i < A->rows; i++) {
            p->u32d[i] = i;
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
                    u8 number = q->u8d[i];
                    if (number >= A->columns) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_U16:
                for (u32 i = 0; i < qlength; i++) {
                    u16 number = q->u16d[i];
                    if (number >= A->columns) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_U32:
                for (u32 i = 0; i < qlength; i++) {
                    u32 number = q->u32d[i];
                    if (number >= A->columns) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_U64:
                for (u32 i = 0; i < qlength; i++) {
                    u64 number = q->u64d[i];
                    if (number >= A->columns) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_I8:
                for (u32 i = 0; i < qlength; i++) {
                    i8 number = q->i8d[i];
                    if (number < 0 || number >= (i64)A->columns) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_I16:
                for (u32 i = 0; i < qlength; i++) {
                    i16 number = q->i16d[i];
                    if (number < 0 || number >= (i64)A->columns) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_I32:
                for (u32 i = 0; i < qlength; i++) {
                    i32 number = q->i32d[i];
                    if (number < 0 || number >= (i64)A->columns) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            case CML_I64:
                for (u32 i = 0; i < qlength; i++) {
                    i64 number = q->i64d[i];
                    if (number < 0 || number >= (i64)A->columns) {
                        return CML_ERR_INVALID_PERMUTATION;
                    }
                }
                break;

            default:
                if (pcreated) {
                    cml_matrix_destroy(p);
                    return CML_ERR_INCOMPATIBLE_TYPES;
                }
        }
    } else {
        qcreated = true;
        qlength = A->columns;
        qstride = sizeof(u32);
        CML_Status result = cml_matrix_init(allocator, A->columns, 1, CML_U32, q);
        if (result != CML_SUCCESS) {
            if (pcreated)
                cml_matrix_destroy(p);
            return result;
        }
        for (u32 i = 0; i < A->columns; i++) {
            q->u32d[i] = i;
        }
    }

    // Initialize out if not initialized
    if (allocator != NULL) {
        CML_Status result = cml_matrix_init0(allocator, plength, qlength, A->type, out);
        if (result != CML_SUCCESS) {
            if (pcreated) {
                cml_matrix_destroy(p);
            }
            if (qcreated) {
                cml_matrix_destroy(q);
            }
            return result;
        }
    }
    // Set out's elements
    for (u32 r = 0; r < out->rows; r++) {
        for (u32 c = 0; c < out->columns; c++) {
            switch(out->type) {
                // Copy complex structures, not take ownership. Set structures or have to initiallize them?
                case CML_BIGINT:
                    break;

                case CML_FRACTION:
                    break;

                case CML_COMPLEX:
                    break;

                case CML_EXPRESSION:
                    break;

                case CML_MATRIX:
                    break;

                default:
                    cml_matrix_set(cml_matrix_get(*(u32*)(p->u8d + r*pstride),
                                                  *(u32*)(q->u8d + c*qstride), 
                                                  A, NULL), 
                                   r, 
                                   c, 
                                   out);
                    break;
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

