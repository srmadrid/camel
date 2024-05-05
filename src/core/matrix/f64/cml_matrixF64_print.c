/** @file cml_matrixF64_print.c
 * 
 * @brief Print function for matrices holding f64's.
 *
 * @author Sergio Madrid
 * @date 5/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/matrix/matrix.h"


CML_Status cml_matrixF64_print(CML_Allocator *allocator, const CML_Matrix *matrix) {
    if (matrix == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (matrix->type != CML_F64) {
        // Maybe add type promotion in the future
        return CML_ERR_INCOMPATIBLE_TYPES;
    }

    if (allocator == NULL) {
        allocator = matrix->allocator;
    }

    u32 maxDigits = 0;
    u32 size = matrix->rows*matrix->columns; 
    u32 *digits = matrix->allocator->malloc(sizeof(u32)*size, matrix->allocator->context);
    if (digits == NULL) {
        return CML_ERR_MALLOC;
    }

    for (u32 i = 0; i < size; i++) {
        u32 count = 0;
        f64 number = matrix->f64d[i];
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
            f64 number = matrix->f64d[r*matrix->columns + c];
            u32 length;
            length = digits[r*matrix->columns + c];
            for (u32 i = 0; i < maxDigits - length; i++) {
                printf(" ");
            }
            printf("%0.6f ", number);
        }
        printf("\n");
    }

    allocator->free(digits, matrix->allocator->context);
    return CML_SUCCESS;
}

