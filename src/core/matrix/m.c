/**
 * @file m.h
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


CML_Status cml_matrix_init(CML_Allocator *allocator, u32 rows, u32 columns, b8 rowmajor, CML_NumericType type, CML_Matrix *matrix) {
    if (allocator == NULL || matrix == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (rows == 0 || columns == 0) {
        return CML_ERR_INVALID_SIZE;
    }

    u32 stride = cml_numerictype_size_lookup[type];

    matrix->data = allocator->calloc(rows*columns, stride, allocator->context);
    if (matrix->data == NULL) {
        return CML_ERR_CALLOC;
    }

    matrix->allocator = allocator;
    matrix->type = type;
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->rowmajor = rowmajor;

    return CML_SUCCESS;
}


CML_Status cml_matrix_init0(CML_Allocator *allocator, u32 rows, u32 columns, b8 rowmajor, CML_NumericType type, CML_Matrix *matrix) {
    if (allocator == NULL || matrix == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (rows == 0 || columns == 0) {
        return CML_ERR_INVALID_SIZE;
    }

    u32 stride = cml_numerictype_size_lookup[type];
    u32 size = rows*columns;

    matrix->data = allocator->calloc(size, stride, allocator->context);
    if (matrix->data == NULL) {
        return CML_ERR_MALLOC;
    }

    switch(type) {
        case CML_BIGINT:
            for (u32 i = 0; i < size; i++) {
                CML_BigInt aux;
                CML_Status result = cml_bigint_init(allocator, 0, &aux);
                if (result != CML_SUCCESS) {
                    for (u32 j = 0; j < i - 1; j++) {
                        cml_bigint_destroy(((u8*)matrix->data) + stride*i);
                    }
                    return result;
                }
            }
            break;
/*
        case CML_FRACTION:
            for (u32 i = 0; i < size; i++) {
                CML_Fraction aux;
                CML_Status result = cml_fraction_init(allocator, 0, &aux);
                if (result != CML_SUCCESS) {
                    for (u32 j = 0; j < i - 1; j++) {
                        cml_fraction_destroy(((u8*)matrix->data) + stride*i);
                    }
                    return result;
                }
            }
            break;

        case CML_COMPLEX:
            for (u32 i = 0; i < size; i++) {
                CML_Complex aux;
                CML_Status result = cml_complex_init(allocator, 0, &aux);
                if (result != CML_SUCCESS) {
                    for (u32 j = 0; j < i - 1; j++) {
                        cml_complex_destroy(((u8*)matrix->data) + stride*i);
                    }
                    return result;
                }
            }
            break; */

        default:
            break;
    }

    matrix->allocator = allocator;
    matrix->type = type;
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->rowmajor = rowmajor;

    return CML_SUCCESS;
}


void cml_matrix_destroy(void *matrix) {
    CML_Matrix *mat = (CML_Matrix*)matrix;
    if (mat != NULL) {
        u32 stride = cml_numerictype_size_lookup[mat->type];
        u32 size = mat->rows*mat->columns;
        switch (mat->type) {
            case CML_BIGINT:
                for (u32 i = 0; i < size; i++) {
                    cml_bigint_destroy((u8*)mat->data + i*stride);
                }
                break;

            case CML_FRACTION:
                for (u32 i = 0; i < size; i++) {
                    //cml_fraction_destroy((u8*)mat->data + i*stride);
                }
                break;

            case CML_COMPLEX:
                for (u32 i = 0; i < size; i++) {
                    //cml_complex_destroy((u8*)mat->data + i*stride);
                }
                break;

            default:
                break;
        }
        mat->allocator->free(mat->data, mat->allocator->context);
        mat->data = NULL;
        mat->allocator = NULL;
        mat->rows = 0;
        mat->columns = 0;
    }
}


CML_Status cml_matrix_set(void *element, u32 row, u32 column, CML_Matrix *out) {
    if (out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (row >= out->rows || column >= out->columns) {
        return CML_ERR_INVALID_INDEX;
    }

    u32 stride = cml_numerictype_size_lookup[out->type];
    void *location;
    if (out->rowmajor) {
        location = ((u8*)out->data) + row*stride*out->columns + column*stride;
    } else {
        location = ((u8*)out->data) + row*stride + column*stride*out->rows;
    }

    switch(out->type) {
        case CML_U8:
            *(u8*)location = *(u8*)element;
            break;

        case CML_U16:
            *(u16*)location = *(u16*)element;
            break;

        case CML_U32:
            *(u32*)location = *(u32*)element;
            break;

        case CML_U64:
            *(u64*)location = *(u64*)element;
            break;

        case CML_I8:
            *(i8*)location = *(i8*)element;
            break;

        case CML_I16:
            *(i16*)location = *(i16*)element;
            break;

        case CML_I32:
            *(i32*)location = *(i32*)element;
            break;

        case CML_I64:
            *(i64*)location = *(i64*)element;
            break;

        case CML_F32:
            *(f32*)location = *(f32*)element;
            break;

        case CML_F64:
            *(f64*)location = *(f64*)element;
            break;

        case CML_COMPLEXF32:
            *(cf32*)location = *(cf32*)element;
            break;
        
        case CML_COMPLEXF64:
            *(cf64*)location = *(cf64*)element;
            break;

        case CML_BIGINT:
        case CML_FRACTION:
        case CML_COMPLEX:
            memcpy(location, element, stride);
            break;
    }

    return CML_SUCCESS;
}


void *cml_matrix_get(u32 row, u32 column, const CML_Matrix *out) {
    if (out == NULL) {
        return NULL;
    }

    if (row >= out->rows || column >= out->columns) {
        return NULL;
    }

    u32 stride = cml_numerictype_size_lookup[out->type];
    void *element;
    if (out->rowmajor) {
        element = ((u8*)out->data) + row*stride*out->columns + column*stride;
    } else {
        element = ((u8*)out->data) + row*stride + column*stride*out->rows;
    }
    return element;
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
    u32 stride = cml_numerictype_size_lookup[matrix->type];
    switch(matrix->type) {
        case CML_U8:
            for (u32 i = 0; i < size; i++) {
                u32 count = 0;
                u8 number = *((u8*)matrix->data + i*stride);
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                for (u32 c = 0; c < matrix->rows; c++) {
                    u8 number = *(u8*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
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
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                for (u32 c = 0; c < matrix->rows; c++) {
                    u16 number = *(u16*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
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
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                for (u32 c = 0; c < matrix->rows; c++) {
                    u32 number = *(u32*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
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
                printf("Number %d: %lu\n", i, number);
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                for (u32 c = 0; c < matrix->rows; c++) {
                    u64 number = *(u64*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
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
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                for (u32 c = 0; c < matrix->rows; c++) {
                    i8 number = *(i8*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
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
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                for (u32 c = 0; c < matrix->rows; c++) {
                    i16 number = *(i16*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
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
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                for (u32 c = 0; c < matrix->rows; c++) {
                    i32 number = *(i32*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
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
                while (number != 0) {
                    number /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                for (u32 c = 0; c < matrix->rows; c++) {
                    i64 number = *(i64*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
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
                if (number != 0 && numberi == 0) count++;
                while (numberi != 0) {
                    numberi /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                count += 7;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                for (u32 c = 0; c < matrix->rows; c++) {
                    f32 number = *(f32*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%0.6f", number);
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
                if (number != 0 && numberi == 0) count++;
                while (numberi != 0) {
                    numberi /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                count += 7;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                for (u32 c = 0; c < matrix->rows; c++) {
                    f64 number = *(f64*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    printf("%0.6f", number);
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
                if (a != 0) count += 7; // a decimals and .
                if (a != 0 && ai == 0) count++;
                while (ai != 0) {
                    ai /= 10;
                    count++;
                }
                if (b != 0) count += 11; // b decimals, ., i and +/-
                if (b != 0 && bi == 0) count++;
                while (bi != 0) {
                    bi /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                for (u32 c = 0; c < matrix->rows; c++) {
                    cf32 number = *(cf32*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    if (cimagf(number) >= 0) {
                        printf("%0.6f + %0.6fi", crealf(number), cimagf(number));
                    } else {
                        printf("%0.6f - %0.6fi", crealf(number), fabs(cimagf(number)));
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
                if (a != 0) count += 7; // a decimals and .
                if (a != 0 && ai == 0) count++;
                while (ai != 0) {
                    ai /= 10;
                    count++;
                }
                if (b != 0) count += 11; // b decimals, ., i and +/-
                if (b != 0 && bi == 0) count++;
                while (bi != 0) {
                    bi /= 10;
                    count++;
                }
                if (maxDigits < count)
                    maxDigits = count;
                digits[i] = count;
            }

            for (u32 r = 0; r < matrix->rows; r++) {
                for (u32 c = 0; c < matrix->rows; c++) {
                    cf64 number = *(cf64*)cml_matrix_get(r, c, matrix);
                    u32 length;
                    if (matrix->rowmajor) {
                        length = digits[r*matrix->columns + c];
                    } else {
                        length = digits[r + c*matrix->rows];
                    }
                    for (u32 i = 0; i < maxDigits - length; i++) {
                        printf(" ");
                    }
                    if (cimagf(number) >= 0) {
                        printf("%0.6f + %0.6fi", creal(number), cimag(number));
                    } else {
                        printf("%0.6f - %0.6fi", creal(number), fabs(cimag(number)));
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

