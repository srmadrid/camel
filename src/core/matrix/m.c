/** @file m.h
 * 
 * @brief Implementation of CAMEL's basic type, the matrix.
 *
 * @author Sergio Madrid
 * @date 2/3/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/core/matrix/matrix.h"


CML_Status cml_matrix_divew_inplace(const CML_Matrix *right, CML_Matrix *out) {
    if (right == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (right->type != out->type) {
        // Maybe add type promotion in the future
        return CML_ERR_INCOMPATIBLE_TYPES;
    }

    b8 rightIsScalar;
    if (right->rows != out->rows || right->columns != out->columns) {
        if (right->rows == 1 && right->columns == 1) {
            rightIsScalar = true;
        } else {
        return CML_ERR_INCOMPATIBLE_SIZE;
        }
    } else {
        rightIsScalar = false;
    }

    switch (out->type) {
        case CML_U8:
            if (rightIsScalar) {
                u8 scalar = *(u8*)right->data;
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(u8*)cml_matrix_get(r, c, out) /= scalar;
                    }
                }
            } else {
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(u8*)cml_matrix_get(r, c, out) /= *(u8*)cml_matrix_get(r, c, right);
                    }
                }
            }
            break;

        case CML_U16:
            if (rightIsScalar) {
                u16 scalar = *(u16*)right->data;
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(u16*)cml_matrix_get(r, c, out) /= scalar;
                    }
                }
            } else {
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(u16*)cml_matrix_get(r, c, out) /= *(u16*)cml_matrix_get(r, c, right);
                    }
                }
            }
            break;

        case CML_U32:
            if (rightIsScalar) {
                u32 scalar = *(u32*)right->data;
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(u32*)cml_matrix_get(r, c, out) /= scalar;
                    }
                }
            } else {
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(u32*)cml_matrix_get(r, c, out) /= *(u32*)cml_matrix_get(r, c, right);
                    }
                }
            }
            break;

        case CML_U64:
            if (rightIsScalar) {
                u64 scalar = *(u64*)right->data;
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(u64*)cml_matrix_get(r, c, out) /= scalar;
                    }
                }
            } else {
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(u64*)cml_matrix_get(r, c, out) /= *(u64*)cml_matrix_get(r, c, right);
                    }
                }
            }
            break;

        case CML_I8:
            if (rightIsScalar) {
                i8 scalar = *(i8*)right->data;
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(i8*)cml_matrix_get(r, c, out) /= scalar;
                    }
                }
            } else {
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(i8*)cml_matrix_get(r, c, out) /= *(i8*)cml_matrix_get(r, c, right);
                    }
                }
            }
            break;

        case CML_I16:
            if (rightIsScalar) {
                i16 scalar = *(i16*)right->data;
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(i16*)cml_matrix_get(r, c, out) /= scalar;
                    }
                }
            } else {
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(i16*)cml_matrix_get(r, c, out) /= *(i16*)cml_matrix_get(r, c, right);
                    }
                }
            }
            break;

        case CML_I32:
            if (rightIsScalar) {
                i32 scalar = *(i32*)right->data;
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(i32*)cml_matrix_get(r, c, out) /= scalar;
                    }
                }
            } else {
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(i32*)cml_matrix_get(r, c, out) /= *(i32*)cml_matrix_get(r, c, right);
                    }
                }
            }
            break;

        case CML_I64:
            if (rightIsScalar) {
                i64 scalar = *(i64*)right->data;
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(i64*)cml_matrix_get(r, c, out) /= scalar;
                    }
                }
            } else {
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(i64*)cml_matrix_get(r, c, out) /= *(i64*)cml_matrix_get(r, c, right);
                    }
                }
            }
            break;

        case CML_F32:
            if (rightIsScalar) {
                f32 scalar = *(f32*)right->data;
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(f32*)cml_matrix_get(r, c, out) /= scalar;
                    }
                }
            } else {
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(f32*)cml_matrix_get(r, c, out) /= *(f32*)cml_matrix_get(r, c, right);
                    }
                }
            }
            break;

        case CML_F64:
            if (rightIsScalar) {
                f64 scalar = *(f64*)right->data;
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(f64*)cml_matrix_get(r, c, out) /= scalar;
                    }
                }
            } else {
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(f64*)cml_matrix_get(r, c, out) /= *(f64*)cml_matrix_get(r, c, right);
                    }
                }
            }
            break;

        case CML_COMPLEXF32:
            if (rightIsScalar) {
                cf32 scalar = *(cf32*)right->data;
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(cf32*)cml_matrix_get(r, c, out) /= scalar;
                    }
                }
            } else {
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(cf32*)cml_matrix_get(r, c, out) /= *(cf32*)cml_matrix_get(r, c, right);
                    }
                }
            }
            break;

        case CML_COMPLEXF64:
            if (rightIsScalar) {
                cf64 scalar = *(cf64*)right->data;
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(cf64*)cml_matrix_get(r, c, out) /= scalar;
                    }
                }
            } else {
                for (u32 r = 0; r < out->rows; r++) {
                    for (u32 c = 0; c < out->columns; c++) {
                        *(cf64*)cml_matrix_get(r, c, out) /= *(cf64*)cml_matrix_get(r, c, right);
                    }
                }
            }
            break;

        case CML_BIGINT:
            break;

        case CML_FRACTION:
            break;

        case CML_COMPLEX:
        case CML_EXPRESSION:
        case CML_MATRIX:
            break;
    }

    return CML_SUCCESS;
}


CML_Status cml_matrix_transpose(CML_Allocator *allocator, const CML_Matrix *A, CML_Matrix *out) {
    if (A == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (allocator == NULL) {
        allocator = A->allocator;
    }

    CML_Status result = cml_matrix_init(allocator, A->columns, A->rows, A->type, out);
    if (result != CML_SUCCESS) {
        return result;
    }

    for (u32 r = 0; r < out->rows; r++) {
        for (u32 c = 0; c < out->columns; c++) {
            switch(out->type) {
                case CML_BIGINT:
                    break;

                case CML_FRACTION:
                    break;

                case CML_COMPLEX:
                    break;

                default:
                    cml_matrix_set(cml_matrix_get(c, r, A), r, c, out);
                    break;
            }
        }
    }

    return CML_SUCCESS;

}


CML_Status cml_matrix_print(const CML_Matrix *matrix) {
    if (matrix == NULL) {
        return CML_ERR_NULL_PTR;
    }

    u32 maxDigits = 0;
    u32 size = matrix->rows*matrix->columns; 
    u32 *digits = matrix->allocator->malloc(sizeof(u32)*size, matrix->allocator->context);
    if (digits == NULL) {
        return CML_ERR_MALLOC;
    }
    u32 stride = cml_numerictype_size(matrix->type);
    switch(matrix->type) {
        case CML_U8:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                u8 number = *((u8*)matrix->data + i*stride);
                if (number == 0) count++;
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    u8 number = *(u8*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    length = digits[r*matrix->columns + c];
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%u ", number);
                }
                printf("\n");
            }
            break;

        case CML_U16:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                u16 number = *((u16*)((u8*)matrix->data + i*stride));
                if (number == 0) count++;
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    u16 number = *(u16*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    length = digits[r*matrix->columns + c];
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%u ", number);
                }
                printf("\n");
            }
            break;

        case CML_U32:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                u32 number = *((u32*)((u8*)matrix->data + i*stride));
                if (number == 0) count++;
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    u32 number = *(u32*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    length = digits[r*matrix->columns + c];
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%u ", number);
                }
                printf("\n");
            }
            break;

        case CML_U64:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                u64 number = *((u64*)((u8*)matrix->data + i*stride));
                if (number == 0) count++;
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    u64 number = *(u64*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    length = digits[r*matrix->columns + c];
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%lu ", number);
                }
                printf("\n");
            }
            break;

        case CML_I8:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                i8 number = *((i8*)((u8*)matrix->data + i*stride));
                if (number < 0)
                    count++;
                if (number == 0) count++;
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    i8 number = *(i8*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    length = digits[r*matrix->columns + c];
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%d ", number);
                }
                printf("\n");
            }
            break;

        case CML_I16:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                i16 number = *((i16*)((u8*)matrix->data + i*stride));
                if (number < 0)
                    count++;
                if (number == 0) count++;
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    i16 number = *(i16*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    length = digits[r*matrix->columns + c];
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%d ", number);
                }
                printf("\n");
            }
            break;

        case CML_I32:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                i32 number = *((i32*)((u8*)matrix->data + i*stride));
                if (number < 0)
                    count++;
                if (number == 0) count++;
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    i32 number = *(i32*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    length = digits[r*matrix->columns + c];
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%d ", number);
                }
                printf("\n");
            }
            break;

        case CML_I64:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                i64 number = *((i64*)((u8*)matrix->data + i*stride));
                if (number < 0)
                    count++;
                if (number == 0) count++;
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    i64 number = *(i64*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    length = digits[r*matrix->columns + c];
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%ld ", number);
                }
                printf("\n");
            }
            break;

        case CML_F32:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                f32 number = *((f32*)((u8*)matrix->data + i*stride));
                i32 numberi = number;
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
                    f32 number = *(f32*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    length = digits[r*matrix->columns + c];
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%0.6f ", number);
                }
                printf("\n");
            }
            break;

        case CML_F64:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                f64 number = *((f64*)((u8*)matrix->data + i*stride));
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
                    f64 number = *(f64*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    length = digits[r*matrix->columns + c];
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%0.6f ", number);
                }
                printf("\n");
            }
            break;

        case CML_COMPLEXF32:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                cf32 number = *((cf32*)((u8*)matrix->data + i*stride));
                f32 a = crealf(number);
                f32 b = cimagf(number);
                i32 ai = a;
                i32 bi = b;
                if (a < 0)
                    count++;
                count += 7; // a decimals and .
                if (ai == 0) count++;
                while (ai != 0) {
                    ai /= 10;
                    count++;
                }
                count += 9; // b decimals, ., i and +/-
                if (bi == 0) count++;
                while (bi != 0) {
                    bi /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    cf32 number = *(cf32*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    length = digits[r*matrix->columns + c];
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    if (cimagf(number) >= 0) {
                        printf("%0.6f+%0.6fi ", crealf(number), cimagf(number));
                    } else {
                        printf("%0.6f-%0.6fi ", crealf(number), fabs(cimagf(number)));
                    }
                }
                printf("\n");
            }
            break;

        case CML_COMPLEXF64:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                cf64 number = *((cf64*)((u8*)matrix->data + i*stride));
                f64 a = crealf(number);
                f64 b = cimagf(number);
                i64 ai = a;
                i64 bi = b;
                if (a < 0)
                    count++;
                count += 7; // a decimals and .
                if (ai == 0) count++;
                while (ai != 0) {
                    ai /= 10;
                    count++;
                }
                count += 9; // b decimals, ., i and +/-
                if (bi == 0) count++;
                while (bi != 0) {
                    bi /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                printf("\t");
                for (u32 c = 0; c < matrix->columns; c++) {
                    cf64 number = *(cf64*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    length = digits[r*matrix->columns + c];
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    if (cimagf(number) >= 0) {
                        printf("%0.6f+%0.6fi ", creal(number), cimag(number));
                    } else {
                        printf("%0.6f-%0.6fi ", creal(number), fabs(cimag(number)));
                    }
                }
                printf("\n");
            }
            break;

        default: // Todo the arbitrary precision types once they are implemented
            break;
    }

    matrix->allocator->free(digits, matrix->allocator->context);
    return CML_SUCCESS;
}

