/** @file cml_matrixEXP_print.c
 * 
 * @brief Print function for matrices holding Expression's.
 *
 * @author Sergio Madrid
 * @date 5/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/matrix/matrix.h"


CML_Status cml_matrixEXP_print(CML_Allocator *allocator, const CML_Matrix *matrix) {
    if (matrix == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (matrix->type != CML_EXPRESSION) {
        // Maybe add type promotion in the future
        return CML_ERR_INCOMPATIBLE_TYPES;
    }

    if (allocator == NULL) {
        allocator = matrix->allocator;
    }

    printf("IN DEVELOPMENT.\n");

    return CML_SUCCESS;
}

