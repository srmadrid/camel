/** @file cml_matrix_init0.h
 * 
 * @brief Init0 function for matrices.
 *
 * @author Sergio Madrid
 * @date 17/4/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/core/matrix/matrix.h"


CML_Status cml_matrix_init0(CML_Allocator *allocator, u32 rows, u32 columns, CML_NumericType type, CML_Matrix *matrix) {
    if (allocator == NULL || matrix == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (rows == 0 || columns == 0) {
        return CML_ERR_INVALID_SIZE;
    }

    u32 stride = cml_numerictype_size(type);
    u32 size = rows*columns;

    matrix->u8d = allocator->calloc(size, stride, allocator->context);
    if (matrix->u8d == NULL) {
        return CML_ERR_MALLOC;
    }

    switch(type) {
        case CML_BIGINT:
            for (u32 i = 0; i < size; i++) {
                CML_Status result = cml_bigint_init(allocator, 0, &matrix->bigintd[i]);
                if (result != CML_SUCCESS) {
                    for (u32 j = 0; j < i - 1; j++) {
                        cml_bigint_destroy(&matrix->bigintd[i]);
                    }
                    return result;
                }
            }
            break;

        case CML_FRACTION:
            for (u32 i = 0; i < size; i++) {/*
                CML_Status result = cml_fraction_init(allocator, 0, &matrix->fracd[i]);
                if (result != CML_SUCCESS) {
                    for (u32 j = 0; j < i - 1; j++) {
                        cml_fraction_destroy(&matrix->fracd[i]);
                    }
                    return result;
                }*/
            }
            break;

        case CML_COMPLEX:
            for (u32 i = 0; i < size; i++) {/*
                CML_Status result = cml_complex_init(allocator, 0, &matrix->complexd[i]);
                if (result != CML_SUCCESS) {
                    for (u32 j = 0; j < i - 1; j++) {
                        cml_complex_destroy(&matrix->complexd[i]);
                    }
                    return result;
                }*/
            }
            break;

        case CML_EXPRESSION:
            for (u32 i = 0; i < size; i++) {/*
                CML_Status result = cml_expression_init(allocator, 0, &matrix->expd[i]);
                if (result != CML_SUCCESS) {
                    for (u32 j = 0; j < i - 1; j++) {
                        cml_expression_destroy(&matrix->expd[i]);
                    }
                    return result;
                }*/
            }
            break;

        case CML_MATRIX:
            for (u32 i = 0; i < size; i++) {
                CML_Status result = cml_matrix_init0(allocator, 0, 0, CML_MATRIX, &matrix->matd[i]);
                if (result != CML_SUCCESS) {
                    for (u32 j = 0; j < i - 1; j++) {
                        cml_matrix_destroy(&matrix->matd[i]);
                    }
                    return result;
                }
            }
            break;

        default:
            break;
    }

    matrix->allocator = allocator;
    matrix->type = type;
    matrix->rows = rows;
    matrix->columns = columns;

    return CML_SUCCESS;
}

