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


CML_Status cml_matrix_init(CML_Allocator *allocator, u32 rows, u32 columns, CML_NumericType type, CML_Matrix *matrix) {
    if (allocator == NULL || matrix == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (rows == 0 || columns == 0) {
        return CML_ERR_INVALID_SIZE;
    }

    u32 stride = cml_numerictype_size(type);

    matrix->u8d = allocator->calloc(rows*columns, stride, allocator->context);
    if (matrix->u8d == NULL) {
        return CML_ERR_CALLOC;
    }

    matrix->allocator = allocator;
    matrix->type = type;
    matrix->rows = rows;
    matrix->columns = columns;

    return CML_SUCCESS;
}

