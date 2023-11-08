/******************************************************************************
 * Filename: matrix.h
 * 
 * Description:
 *      Declarations for the matrix manipulation functions of CAMEL.
 *
 * Author: Sergio Madrid
 * Created on: 8/11/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/

#ifndef CAMEL_MATRIX
#define CAMEL_MATRIX


#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#include "../../core/core.h"


/******************************************************************************
 * Struct: CML_Matrix
 * 
 * Description:
 *      Represents a mathematical matric with components stored in a 
 *      dynamically allocated 2 dimensional array. This struct is used 
 *      throughout the CAMEL library to represent matrices in MxN-dimensional 
 *      space.
 *
 * Fields:
 *      size_t m - The number of rows of the matrix.
 *      size_t n - The number of columns of the matrix.
 *      double** data - A pointer to the dynamically allocated array of components.
 *
 * Notes:
 *      The 'data' pointer should be managed using cml_matrix_init and
 *      cml_matrix_free functions to ensure proper memory management. 'MxN'
 *      should always reflect the number of allocated elements in 'data'.
 *****************************************************************************/
typedef struct {
    size_t m;
    size_t n;
    double **data;
} CML_Matrix;


/******************************************************************************
 * Function: cml_matrix_init
 * 
 * Description:
 *      Initializes a matrix of size 'MxN' to 0.
 *
 * Parameters:
 *      size_t m - Number of rows of the matrix.
 *      size_t n - Number of columns of the matrix.
 * 
 * Returns:
 *      A pointer to the allocated CML_Matrix.
 *****************************************************************************/
CAMEL_API CML_Matrix *cml_matrix_init(size_t m, size_t n) {
    if (m <= 0 || n <= 0) {
        return NULL;
    }

    CML_Matrix *out = (CML_Matrix*)malloc(sizeof(CML_Matrix));
    if (out == NULL) {
        return NULL;
    }

    out->data = (double**)malloc(m * sizeof(double*));
    if (out->data == NULL) {
        free(out);
        return NULL;
    }

    out->m = m;
    out->n = n;

    for (int i = 0; i < m; i++) {
        out->data[i] = (double*)malloc(n * sizeof(double));
        if (out->data[i] == NULL) {
            for (size_t j = 0; j < i; j++) {
                free(out->data[j]);
            }
            free(out->data);
            free(out);
            return NULL;
        }

        for (int j = 0; j < n; j++) {
            out->data[i][j] = 0.0;
        }
    }

    return out;
}


/******************************************************************************
 * Function: cml_matrix_free
 * 
 * Description:
 *      Frees the memory of the input CML_Matrix.
 *
 * Parameters:
 *      CML_Matrix *A - The pointer to the CML_Matrix you want to free.
 * 
 * Returns:
 *      Void.
 *****************************************************************************/
CAMEL_API void cml_matrix_free(CML_Matrix *A) {
    if (A != NULL) {
        if (A->data != NULL) {
            for (int i = 0; i < A->m; i++) {
                if (A->data[i] != NULL) {
                    free(A->data[i]);
                }
            free(A->data);
        }
        free(A);
    }
}


/******************************************************************************
 * Function: cml_matrix_add
 * 
 * Description:
 *      Adds two CML_Matrix and writes the result to the out CML_Matrix. Both 
 *      intput CML_Matrix must have the same size.
 *
 * Parameters:
 *      CML_Matrix *A   - The first matrix operand.
 *      CML_Matrix *B   - The second matrix operand.
 *      CML_Matrix *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API int cml_matrix_add(const CML_Matrix *A, const CML_Matrix *B, CML_Matrix *out) {
    if (!A || !B || !out || !A->m || !A->n || !A->data || !B->m || !B->n || !B->data || !out->m || !out->n || !out->data) {
        return CML_ERR_NULL_PTR;
    }

    if (A->m != B->m || A->n != B->n || A->m != out->m || A->n != out->n) {
        return CML_ERR_INVALID_SIZE;
    }

    for (int i = 0; i < A->m; i++) {
        for (int j = 0; j < A->n; j++) {
            out->data[i][j] = A->data[i][j] + B->data[i][j];
        }
    }

    return CML_SUCCESS;
}


/******************************************************************************
 * Function: cml_matrix_sub
 * 
 * Description:
 *      Subtracts two CML_Matrix and writes the result to the out CML_Matrix. 
 *      Both intput CML_Matrix must have the same dimension.
 *
 * Parameters:
 *      CML_Matrix *A   - The first matrix operand.
 *      CML_Matrix *B   - The second matrix operand.
 *      CML_Matrix *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API int cml_matrix_sub(const CML_Matrix *A, const CML_Matrix *B, CML_Matrix *out) {
    if (!A || !B || !out || !A->m || !A->n || !A->data || !B->m || !B->n || !B->data || !out->m || !out->n || !out->data) {
        return CML_ERR_NULL_PTR;
    }

    if (A->m != B->m || A->n != B->n || A->m != out->m || A->n != out->n) {
        return CML_ERR_INVALID_SIZE;
    }

    for (int i = 0; i < A->m; i++) {
        for (int j = 0; j < A->n; j++) {
            out->data[i][j] = A->data[i][j] - B->data[i][j];
        }
    }

    return CML_SUCCESS;
}


/******************************************************************************
 * Function: cml_matrix_scalar_mult
 * 
 * Description:
 *      Multiplies a CML_Matrix by a scalar, and writes the result to the out 
 *      CML_Matrix.
 *
 * Parameters:
 *      CML_Matrix *A   - The matrix operand.
 *      double      t   - The scalar.
 *      CML_Matrix *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API int cml_matrix_scalar_mult(const CML_Matrix *A, double t, CML_Matrix *out) {
    if (!A || !out || !A->m || !A->n || !A->data || !out->m || !out->n || !out->data) {
        return CML_ERR_NULL_PTR;
    }

    if (A->m != out->m || A->n != out->n) {
        return CML_ERR_INVALID_SIZE;
    }

    for (int i = 0; i < A->m; i++) {
        for (int j = 0; j < A->n; j++) {
            out->data[i][j] = A->data[i][j] * t;
        }
    }

    return CML_SUCCESS;
}


/******************************************************************************
 * Function: cml_matrix_mult
 * 
 * Description:
 *      Multiplies two CML_Matrix, and writes the result to the out 
 *      CML_Matrix.
 *
 * Parameters:
 *      CML_Matrix *A   - The first matrix operand.
 *      CML_Matrix *B   - The second matrix operand.
 *      CML_Matrix *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API int cml_matrix_mult(const CML_Matrix *A, const CML_Matrix *B, CML_Matrix *out) {
    if (!A || !B || !out || !A->m || !A->n || !A->data || !B->m || !B->n || !B->data || !out->m || !out->n || !out->data) {
        return CML_ERR_NULL_PTR;
    }

    if (A->m != out->m || B->n != out->n || A->n != B->m) {
        return CML_ERR_INVALID_SIZE;
    }

    double aux;

    for (int i = 0; i < A->m; i++) {
        for (int j = 0; j < B->n; j++) {
            aux = 0.0;
            for (int k = 0; k < A->n; k++) {
                aux += A->data[i][k]*B->data[k][j];
            }
            out->data[i][j] = aux;
        }
    }

    return CML_SUCCESS;
}


#endif /* CAMEL_MATRIX */
