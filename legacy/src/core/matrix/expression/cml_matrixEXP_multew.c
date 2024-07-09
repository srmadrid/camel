/** @file cml_matrixEXP_multew.c
 * 
 * @brief Element-wise multiplication function for matrices holding Expression's.
 *
 * @author Sergio Madrid
 * @date 4/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/matrix/matrix.h"


CML_Status cml_matrixEXP_multew(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, CML_Matrix *out) {
    if (left == NULL || right == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (left->type != CML_EXPRESSION || right->type != CML_EXPRESSION) {
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
            out->type != CML_EXPRESSION) {
            return CML_ERR_INVALID_SIZE;
        }
    } else {
        CML_Status result = cml_matrix_init0(allocator, outRows, outColumns, CML_EXPRESSION, out);
        if (result != CML_SUCCESS) {
            return result;
        }
    }

    u32 size = out->columns*out->rows;
    if (oneIsScalar) {
        //CML_Expression scalar;
        if (leftIsScalar) {
            //scalar = left->expd[0];
            for (u32 i = 0; i < size; i++) {
                //cml_expression_mult(NULL, &scalar, &right->expd[i], &out->expd[i]);
            }
        } else  {
            //scalar = right->expd[0];
            for (u32 i = 0; i < size; i++) {
                //cml_expression_mult(NULL, &left->expd[i], &scalar, &out->expd[i]);
            }
        }
    } else {
        for (u32 i = 0; i < size; i++) {
            //cml_expression_mult(NULL, &left->expd[i], &right->expd[i], &out->expd[i]);
        }
    }

    return CML_SUCCESS;
}

