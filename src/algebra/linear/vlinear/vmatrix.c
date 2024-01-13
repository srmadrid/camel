/**
 * @file vmatrix.c
 * 
 * @brief Implementations for the variable matrix manipulation functions of CAMEL.
 * 
 * @author Sergio Madrid
 * @date  25/12/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/algebra/linear/vlinear/vmatrix.h"


CML_Status cml_matrix_init(u32 m, u32 n, CML_Matrix *matrix) {
    if (m <= 0 || n <= 0) {
        return CML_ERR_INVALID_SIZE;
    }

    if (matrix == NULL) {
        return CML_ERR_NULL_PTR;
    }

    matrix->data = (f64**)malloc(m * sizeof(double*));
    if (matrix->data == NULL) {
        matrix->m = 0;
        matrix->n = 0;
        return CML_ERR_NULL_PTR;
    }

    matrix->m = m;
    matrix->n = n;

    for (u32 i = 0; i < m; i++) {
        matrix->data[i] = (f64*)calloc(n, sizeof(double));
        if (matrix->data[i] == NULL) {
            for (size_t j = 0; j < i; j++) {
                free(matrix->data[j]);
            }
            free(matrix->data);
            matrix->m = 0;
            matrix->n = 0;
            return CML_ERR_NULL_PTR;
        }
    }

    for (int i = 0; i < fmin(m, n); i++) {
        matrix->data[i][i] = 1.0;
    }

    return CML_SUCCESS;
}


void cml_matrix_free(CML_Matrix *matrix) {
    if (matrix != NULL) {
        if (matrix->data != NULL) {
            for (u32 i = 0; i < matrix->m; i++) {
                if (matrix->data[i] != NULL) {
                    free(matrix->data[i]);
                }
            free(matrix->data);
            }
        }
        matrix->m = 0;
        matrix->n = 0;
    }
}


CML_Status cml_matrix_add(const CML_Matrix *A, const CML_Matrix *B, CML_Matrix *out) {
    if (!A || !B || !out || 
        !A->m || !A->n || !A->data || 
        !B->m || !B->n || !B->data || 
        !out->m || !out->n || !out->data) {
        return CML_ERR_NULL_PTR;
    }

    if (A->m != B->m || A->n != B->n || A->m != out->m || A->n != out->n) {
        return CML_ERR_INVALID_SIZE;
    }

    for (u32 i = 0; i < A->m; i++) {
        for (u32 j = 0; j < A->n; j++) {
            out->data[i][j] = A->data[i][j] + B->data[i][j];
        }
    }

    return CML_SUCCESS;
}


CML_Status cml_matrix_sub(const CML_Matrix *A, const CML_Matrix *B, CML_Matrix *out) {
    if (!A || !B || !out || 
        !A->m || !A->n || !A->data || 
        !B->m || !B->n || !B->data || 
        !out->m || !out->n || !out->data) {
        return CML_ERR_NULL_PTR;
    }

    if (A->m != B->m || A->n != B->n || A->m != out->m || A->n != out->n) {
        return CML_ERR_INVALID_SIZE;
    }

    for (u32 i = 0; i < A->m; i++) {
        for (u32 j = 0; j < A->n; j++) {
            out->data[i][j] = A->data[i][j] - B->data[i][j];
        }
    }

    return CML_SUCCESS;
}


CML_Status cml_matrix_scale(const CML_Matrix *A, f64 t, CML_Matrix *out) {
    if (!A || !out || 
    !A->m || !A->n || !A->data || 
    !out->m || !out->n || !out->data) {
        return CML_ERR_NULL_PTR;
    }

    if (A->m != out->m || A->n != out->n) {
        return CML_ERR_INVALID_SIZE;
    }

    for (u32 i = 0; i < A->m; i++) {
        for (u32 j = 0; j < A->n; j++) {
            out->data[i][j] = A->data[i][j] * t;
        }
    }

    return CML_SUCCESS;
}


CML_Status cml_matrix_mult(const CML_Matrix *A, const CML_Matrix *B, CML_Matrix *out) {
    if (!A || !B || !out || 
        !A->m || !A->n || !A->data || 
        !B->m || !B->n || !B->data || 
        !out->m || !out->n || !out->data) {
        return CML_ERR_NULL_PTR;
    }

    if (A->m != out->m || B->n != out->n || A->n != B->m) {
        return CML_ERR_INVALID_SIZE;
    }

    double aux;

    for (u32 i = 0; i < A->m; i++) {
        for (u32 j = 0; j < B->n; j++) {
            aux = 0.0;
            for (u32 k = 0; k < A->n; k++) {
                aux += A->data[i][k]*B->data[k][j];
            }
            out->data[i][j] = aux;
        }
    }

    return CML_SUCCESS;
}
