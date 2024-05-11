/** @file cml_matrixCF32_mult.c
 * 
 * @brief Multiplication function for matrices holding cf32's.
 *
 * @author Sergio Madrid
 * @date 4/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/matrix/matrix.h"


CML_Status cml_matrixCF32_mult(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, CML_Matrix *out) {
    if (left == NULL || right == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (left->type != CML_CF32 || right->type != CML_CF32) {
        // Maybe add type promotion in the future
        return CML_ERR_INCOMPATIBLE_TYPES;
    }

    b8 oneIsScalar;
    b8 leftIsScalar;
    u32 outRows;
    u32 outColumns;
    if (left->rows != right->columns) {
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

    // If allocator is NULL, out is initialized.
    if (allocator == NULL) {
        if (out->rows != outRows || out->columns != outColumns || 
            out->type != CML_CF32) {
            return CML_ERR_INVALID_SIZE;
        }
    } else {
        CML_Status result = cml_matrix_init(allocator, outRows, outColumns, CML_CF32, out);
        if (result != CML_SUCCESS) {
            return result;
        }
    }

    if (oneIsScalar) {
        cf32 scalar;
        if (leftIsScalar) {
            scalar = left->cf32d[0];
            for (u32 r = 0; r < out->rows; r++) {
                for (u32 c = 0; c < out->columns; c++) {
                    out->cf32d[r*out->columns + c] = scalar*right->cf32d[r*out->columns + c];
                }
            }
        } else  {
            scalar = right->cf32d[0];
            for (u32 r = 0; r < out->rows; r++) {
                for (u32 c = 0; c < out->columns; c++) {
                    out->cf32d[r*out->columns + c] = left->cf32d[r*out->columns + c]*scalar;
                }
            }
        }
    } else {
        for (u32 r = 0; r < out->rows; r++) {
                for (u32 k = 0; k < left->columns; k++) {
            for (u32 c = 0; c < out->columns; c++) {
                    out->cf32d[r*out->columns + c] += left->cf32d[r*left->columns + k]*right->cf32d[k*right->columns + c];
                }
            }
        }
    }

    return CML_SUCCESS;
}
