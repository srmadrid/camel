/** @file cml_matrixCMPLX_multew.c
 * 
 * @brief Element-wise multiplication function for matrices holding Complex's.
 *
 * @author Sergio Madrid
 * @date 4/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/matrix/matrix.h"


CML_Status cml_matrixCMPLX_multew(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, CML_Matrix *out) {
    if (left == NULL || right == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (left->type != CML_COMPLEX || right->type != CML_COMPLEX) {
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
            out->type != CML_COMPLEX) {
            return CML_ERR_INVALID_SIZE;
        }
    } else {
        CML_Status result = cml_matrix_init0(allocator, outRows, outColumns, CML_COMPLEX, out);
        if (result != CML_SUCCESS) {
            return result;
        }
    }

    u32 size = out->columns*out->rows;
    if (oneIsScalar) {
        //CML_Complex scalar;
        if (leftIsScalar) {
            //scalar = left->complexd[0];
            for (u32 i = 0; i < size; i++) {
                //cml_complex_mult(NULL, &scalar, &right->complexd[i], &out->complexd[i]);
            }
        } else  {
            //scalar = right->complexd[0];
            for (u32 i = 0; i < size; i++) {
                //cml_complex_mult(NULL, &left->complexd[i], &scalar, &out->complexd[i]);
            }
        }
    } else {
        for (u32 i = 0; i < size; i++) {
            //cml_complex_mult(NULL, &left->complexd[i], &right->complexd[i], &out->complexd[i]);
        }
    }

    return CML_SUCCESS;
}

