/** @file cml_matrixMAT_divew.c
 * 
 * @brief Element-wise division function for matrices holding Matrix's.
 *
 * @author Sergio Madrid
 * @date 5/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/matrix/matrix.h"


CML_Status cml_matrixMAT_divew(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, CML_Matrix *out) {
    if (left == NULL || right == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (left->type != CML_MATRIX || right->type != CML_MATRIX) {
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

    // If allocator is NULL, out is initialized.
    if (allocator == NULL) {
        if (out->rows != outRows || out->columns != outColumns || 
            out->type != CML_MATRIX) {
            return CML_ERR_INVALID_SIZE;
        }
    } else {
        CML_Status result = cml_matrix_init0(allocator, outRows, outColumns, CML_MATRIX, out);
        if (result != CML_SUCCESS) {
            return result;
        }
    }

    u32 size = out->columns*out->rows;
    if (oneIsScalar) {
        CML_Matrix scalar;
        if (leftIsScalar) {
            scalar = left->matd[0];
            for (u32 i = 0; i < size; i++) {
                cml_matrix_divew(NULL, &scalar, &right->matd[i], &out->matd[i]);
            }
        } else  {
            scalar = right->matd[0];
            for (u32 i = 0; i < size; i++) {
                cml_matrix_divew(NULL, &left->matd[i], &scalar, &out->matd[i]);
            }
        }
    } else {
        for (u32 i = 0; i < size; i++) {
            cml_matrix_divew(NULL, &left->matd[i], &right->matd[i], &out->matd[i]);
        }
    }

    return CML_SUCCESS;
}

