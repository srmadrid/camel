/** @file cml_matrix_destroy.h
 * 
 * @brief Destroy function for matrices.
 *
 * @author Sergio Madrid
 * @date 17/4/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/core/matrix/matrix.h"


void cml_matrix_destroy(void *matrix) {
    CML_Matrix *mat = (CML_Matrix*)matrix;
    if (mat != NULL) {
        u32 size = mat->rows*mat->columns;
        switch (mat->type) {
            case CML_BIGINT:
                for (u32 i = 0; i < size; i++) {
                    cml_bigint_destroy(&mat->bigintd[i]);
                }
                break;

            case CML_FRACTION:
                for (u32 i = 0; i < size; i++) {
                    cml_bigint_destroy(&mat->bigintd[i]);
                }
                break;

            case CML_COMPLEX:
                for (u32 i = 0; i < size; i++) {
                    //cml_complex_destroy(&mat->complexd[i]);
                }
                break;

            case CML_EXPRESSION:
                for (u32 i = 0; i < size; i++) {
                    //cml_expression_destroy(&mat->expd[i]);
                }
                break;

            case CML_MATRIX:
                for (u32 i = 0; i < size; i++) {
                    cml_matrix_destroy(&mat->matd[i]);
                }
                break;

            default:
                break;
        }

        mat->allocator->free(mat->u8d, mat->allocator->context);
        mat->u8d = NULL;
        mat->allocator = NULL;
        mat->rows = 0;
        mat->columns = 0;
    }
}

