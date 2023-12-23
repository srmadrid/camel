/******************************************************************************
 * Filename: matrix.c
 * 
 * Description:
 *      Implementations for the matrix manipulation functions of CML.
 *
 * Author: Sergio Madrid
 * Created on: 9/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include "../../../include/algebra/linear/matrix.h"


CML_Status cml_matrix_init(CML_Matrix *A, size_t m, size_t n) {
    if (m <= 0 || n <= 0) {
        return CML_ERR_INVALID_SIZE;
    }

    if (A == NULL) {
        return CML_ERR_NULL_PTR;
    }

    A->data = (f64**)malloc(m * sizeof(double*));
    if (A->data == NULL) {
        A->m = 0;
        A->n = 0;
        return CML_ERR_NULL_PTR;
    }

    A->m = m;
    A->n = n;

    for (int i = 0; i < m; i++) {
        A->data[i] = (f64*)calloc(n, sizeof(double));
        if (A->data[i] == NULL) {
            for (size_t j = 0; j < i; j++) {
                free(A->data[j]);
            }
            free(A->data);
            A->m = 0;
            A->n = 0;
            return CML_ERR_NULL_PTR;
        }
    }

    for (int i = 0; i < fmin(m, n); i++) {
        A->data[i][i] = 1.0;
    }

    return CML_SUCCESS;
}


void cml_matrix_free(CML_Matrix *A) {
    if (A != NULL) {
        if (A->data != NULL) {
            for (int i = 0; i < A->m; i++) {
                if (A->data[i] != NULL) {
                    free(A->data[i]);
                }
            free(A->data);
            }
        }
        A->m = 0;
        A->n = 0;
    }
}


CML_Status cml_matrix_add(const CML_Matrix *A, const CML_Matrix *B, CML_Matrix *out) {
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


CML_Status cml_matrix_sub(const CML_Matrix *A, const CML_Matrix *B, CML_Matrix *out) {
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


CML_Status cml_matrix_scale(const CML_Matrix *A, f64 t, CML_Matrix *out) {
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


CML_Status cml_matrix_mult(const CML_Matrix *A, const CML_Matrix *B, CML_Matrix *out) {
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


// Also add debug functions
CML_Status cml_matrix2x2_add(const CML_Matrix2x2 A, const CML_Matrix2x2 B, CML_Matrix2x2 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] + B[0][0];
    out[0][1] = A[0][1] + B[0][1];
    out[1][0] = A[1][0] + B[1][0];
    out[1][1] = A[1][1] + B[1][1];

    return CML_SUCCESS;
}


CML_Status cml_matrix2x2_sub(const CML_Matrix2x2 A, const CML_Matrix2x2 B, CML_Matrix2x2 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] - B[0][0];
    out[0][1] = A[0][1] - B[0][1];
    out[1][0] = A[1][0] - B[1][0];
    out[1][1] = A[1][1] - B[1][1];

    return CML_SUCCESS;
}


CML_Status cml_matrix2x2_scale(const CML_Matrix2x2 A, f64 t, CML_Matrix2x2 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] * t;
    out[0][1] = A[0][1] * t;
    out[1][0] = A[1][0] * t;
    out[1][1] = A[1][1] * t;

    return CML_SUCCESS;
}


CML_Status cml_matrix2x2_mult(const CML_Matrix2x2 A, const CML_Matrix2x2 B, CML_Matrix2x2 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a10 = A[1][0], a11 = A[1][1];
    f64 b00 = B[0][0], b01 = B[0][1], b10 = B[1][0], b11 = B[1][1];

    out[0][0] = a00*b00 + a01*b10;
    out[0][1] = a00*b01 + a01*b11;
    out[1][0] = a10*b00 + a11*b10;
    out[1][1] = a10*b01 + a11*b11;

    return CML_SUCCESS;
}


CML_Status cml_matrix2x2_mult_vector2(const CML_Matrix2x2 A, const CML_Vector2 v, CML_Vector2 out) {
    if (!A || !v || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a10 = A[1][0], a11 = A[1][1];
    f64 v0 = v[0], v1 = v[1];

    out[0] = a00*v0 + a01*v1;
    out[1] = a10*v0 + a11*v1;

    return CML_SUCCESS;
}


CML_Status cml_vector2_mult_matrix2x2(const CML_Vector2 v, const CML_Matrix2x2 A, CML_Vector2 out) {
    if (!v || !A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a10 = A[1][0], a11 = A[1][1];
    f64 v0 = v[0], v1 = v[1];

    out[0] = a00*v0 + a10*v1;
    out[1] = a01*v0 + a11*v1;

    return CML_SUCCESS;
}


f64 cml_matrix2x2_det(const CML_Matrix2x2 A) {
    if (!A) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a10 = A[1][0], a11 = A[1][1];

    return a00*a11 - a01*a10;
}


CML_Status cml_matrix2x2_inv(const CML_Matrix2x2 A, CML_Matrix2x2 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a10 = A[1][0], a11 = A[1][1];
    f64 det = (a00*a11 - a01*a10);

    if (det == 0.0) {
        return CML_ERR_NULL_PTR; // TODO: Change to singular matrix error.
    }

    det = 1/det;

    out[0][0] = a11*det;
    out[0][1] = -a01*det;
    out[1][0] = -a10*det;
    out[1][1] = a00*det;

    return CML_SUCCESS;
}


CML_Status cml_matrix2x2_transpose(const CML_Matrix2x2 A, CML_Matrix2x2 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1];
    f64 a10 = A[1][0], a11 = A[1][1];


    out[0][0] = a00;
    out[0][1] = a10;
    out[1][0] = a01;
    out[1][1] = a11;

    return CML_SUCCESS;
}


f64 cml_matrix2x2_trace(const CML_Matrix2x2 A) {
    if (!A) {
        return CML_ERR_NULL_PTR;
    }

    return A[0][0] + A[1][1];
}


CML_Bool cml_matrix2x2_eq(const CML_Matrix2x2 A, const CML_Matrix2x2 B) {
    if (!A || !B) {
        return CML_FALSE;
    }

    return (fabs(A[0][0] - B[0][0]) <= CML_EPSILON && fabs(A[0][1] - B[0][1]) <= CML_EPSILON && 
            fabs(A[1][0] - B[1][0]) <= CML_EPSILON && fabs(A[1][1] - B[1][1]) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cml_matrix2x2_debug(const CML_Matrix2x2 expected, const CML_Matrix2x2 got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    sprintf(debugMessage, "\t\tExpected:\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n", 
            expected[0][0], expected[0][1], 
            expected[1][0], expected[1][1], 
            got[0][0], got[0][1], 
            got[1][0], got[1][1]);

    return debugMessage;
}



CML_Status cml_matrix3x3_add(const CML_Matrix3x3 A, const CML_Matrix3x3 B, CML_Matrix3x3 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] + B[0][0];
    out[0][1] = A[0][1] + B[0][1];
    out[0][2] = A[0][2] + B[0][2];
    out[1][0] = A[1][0] + B[1][0];
    out[1][1] = A[1][1] + B[1][1];
    out[1][2] = A[1][2] + B[1][2];
    out[2][0] = A[2][0] + B[2][0];
    out[2][1] = A[2][1] + B[2][1];
    out[2][2] = A[2][2] + B[2][2];

    return CML_SUCCESS;
}


CML_Status cml_matrix3x3_sub(const CML_Matrix3x3 A, const CML_Matrix3x3 B, CML_Matrix3x3 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] - B[0][0];
    out[0][1] = A[0][1] - B[0][1];
    out[0][2] = A[0][2] - B[0][2];
    out[1][0] = A[1][0] - B[1][0];
    out[1][1] = A[1][1] - B[1][1];
    out[1][2] = A[1][2] - B[1][2];
    out[2][0] = A[2][0] - B[2][0];
    out[2][1] = A[2][1] - B[2][1];
    out[2][2] = A[2][2] - B[2][2];

    return CML_SUCCESS;
}


CML_Status cml_matrix3x3_scale(const CML_Matrix3x3 A, f64 t, CML_Matrix3x3 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] * t;
    out[0][1] = A[0][1] * t;
    out[0][2] = A[0][2] * t;
    out[1][0] = A[1][0] * t;
    out[1][1] = A[1][1] * t;
    out[1][2] = A[1][2] * t;
    out[2][0] = A[2][0] * t;
    out[2][1] = A[2][1] * t;
    out[2][2] = A[2][2] * t;

    return CML_SUCCESS;
}


CML_Status cml_matrix3x3_mult(const CML_Matrix3x3 A, const CML_Matrix3x3 B, CML_Matrix3x3 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2];

    f64 b00 = B[0][0], b01 = B[0][1], b02 = B[0][2];
    f64 b10 = B[1][0], b11 = B[1][1], b12 = B[1][2];
    f64 b20 = B[2][0], b21 = B[2][1], b22 = B[2][2];

    out[0][0] = a00*b00 + a01*b10 + a02*b20;
    out[0][1] = a00*b01 + a01*b11 + a02*b21;
    out[0][2] = a00*b02 + a01*b12 + a02*b22;
    out[1][0] = a10*b00 + a11*b10 + a12*b20;
    out[1][1] = a10*b01 + a11*b11 + a12*b21;
    out[1][2] = a10*b02 + a11*b12 + a12*b22;
    out[2][0] = a20*b00 + a21*b10 + a22*b20;
    out[2][1] = a20*b01 + a21*b11 + a22*b21;
    out[2][2] = a20*b02 + a21*b12 + a22*b22;

    return CML_SUCCESS;
}


CML_Status cml_matrix3x3_mult_vector3(const CML_Matrix3x3 A, const CML_Vector3 v, CML_Vector3 out) {
    if (!A || !v || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2];

    f64 v0 = v[0], v1 = v[1], v2 = v[2];

    out[0] = a00*v0 + a01*v1 + a02*v2;
    out[1] = a10*v0 + a11*v1 + a12*v2;
    out[2] = a20*v0 + a21*v1 + a22*v2;

    return CML_SUCCESS;
}


CML_Status cml_vector3_mult_matrix3x3(const CML_Vector3 v, const CML_Matrix3x3 A, CML_Vector3 out) {
    if (!v || !A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2];

    f64 v0 = v[0], v1 = v[1], v2 = v[2];

    out[0] = a00*v0 + a10*v1 + a20*v2;
    out[1] = a01*v0 + a11*v1 + a21*v2;
    out[2] = a02*v0 + a12*v1 + a22*v2;

    return CML_SUCCESS;
}


f64 cml_matrix3x3_det(const CML_Matrix3x3 A) {
    if (!A) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2];

    return a00*(a11*a22 - a12*a21) - a01*(a10*a22 - a12*a20) + a02*(a10*a21 - a11*a20);
}


CML_Status cml_matrix3x3_inv(const CML_Matrix3x3 A, CML_Matrix3x3 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2];

    f64 det = a00*(a11*a22 - a12*a21) - a01*(a10*a22 - a12*a20) + a02*(a10*a21 - a11*a20);

    if (det == 0.0) {
        return CML_ERR_NULL_PTR; // TODO: Change to singular matrix error.
    }

    det = 1/det;

    out[0][0] = (a11*a22 - a12*a21)*det;
    out[0][1] = -(a01*a22 - a02*a21)*det;
    out[0][2] = (a01*a12 - a02*a11)*det;
    out[1][0] = -(a10*a22 - a12*a20)*det;
    out[1][1] = (a00*a22 - a02*a20)*det;
    out[1][2] = -(a00*a12 - a02*a10)*det;
    out[2][0] = (a10*a21 - a11*a20)*det;
    out[2][1] = -(a00*a21 - a01*a20)*det;
    out[2][2] = (a00*a11 - a01*a10)*det;

    return CML_SUCCESS;
}


CML_Status cml_matrix3x3_transpose(const CML_Matrix3x3 A, CML_Matrix3x3 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2];

    out[0][0] = a00;
    out[0][1] = a10;
    out[0][2] = a20;
    out[1][0] = a01;
    out[1][1] = a11;
    out[1][2] = a21;
    out[2][0] = a02;
    out[2][1] = a12;
    out[2][2] = a22;

    return CML_SUCCESS;
}


f64 cml_matrix3x3_trace(const CML_Matrix3x3 A) {
    if (!A) {
        return CML_ERR_NULL_PTR;
    }

    return A[0][0] + A[1][1] + A[2][2];
}


CML_Bool cml_matrix3x3_eq(const CML_Matrix3x3 A, const CML_Matrix3x3 B) {
    if (!A || !B) {
        return CML_FALSE;
    }

    return (fabs(A[0][0] - B[0][0]) <= CML_EPSILON && fabs(A[0][1] - B[0][1]) <= CML_EPSILON && fabs(A[0][2] - B[0][2]) <= CML_EPSILON && 
            fabs(A[1][0] - B[1][0]) <= CML_EPSILON && fabs(A[1][1] - B[1][1]) <= CML_EPSILON && fabs(A[1][2] - B[1][2]) <= CML_EPSILON && 
            fabs(A[2][0] - B[2][0]) <= CML_EPSILON && fabs(A[2][1] - B[2][1]) <= CML_EPSILON && fabs(A[2][2] - B[2][2]) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cml_matrix3x3_debug(const CML_Matrix3x3 expected, const CML_Matrix3x3 got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    sprintf(debugMessage, "\t\tExpected:\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n", 
            expected[0][0], expected[0][1], expected[0][2], 
            expected[1][0], expected[1][1], expected[1][2], 
            expected[2][0], expected[2][1], expected[2][2], 
            got[0][0], got[0][1], got[0][2], 
            got[1][0], got[1][1], got[1][2], 
            got[2][0], got[2][1], got[2][2]);

    return debugMessage;
}



CML_Status cml_matrix4x4_add(const CML_Matrix4x4 A, const CML_Matrix4x4 B, CML_Matrix4x4 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] + B[0][0];
    out[0][1] = A[0][1] + B[0][1];
    out[0][2] = A[0][2] + B[0][2];
    out[0][3] = A[0][3] + B[0][3];
    out[1][0] = A[1][0] + B[1][0];
    out[1][1] = A[1][1] + B[1][1];
    out[1][2] = A[1][2] + B[1][2];
    out[1][3] = A[1][3] + B[1][3];
    out[2][0] = A[2][0] + B[2][0];
    out[2][1] = A[2][1] + B[2][1];
    out[2][2] = A[2][2] + B[2][2];
    out[2][3] = A[2][3] + B[2][3];
    out[3][0] = A[3][0] + B[3][0];
    out[3][1] = A[3][1] + B[3][1];
    out[3][2] = A[3][2] + B[3][2];
    out[3][3] = A[3][3] + B[3][3];

    return CML_SUCCESS;
}


CML_Status cml_matrix4x4_sub(const CML_Matrix4x4 A, const CML_Matrix4x4 B, CML_Matrix4x4 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] - B[0][0];
    out[0][1] = A[0][1] - B[0][1];
    out[0][2] = A[0][2] - B[0][2];
    out[0][3] = A[0][3] - B[0][3];
    out[1][0] = A[1][0] - B[1][0];
    out[1][1] = A[1][1] - B[1][1];
    out[1][2] = A[1][2] - B[1][2];
    out[1][3] = A[1][3] - B[1][3];
    out[2][0] = A[2][0] - B[2][0];
    out[2][1] = A[2][1] - B[2][1];
    out[2][2] = A[2][2] - B[2][2];
    out[2][3] = A[2][3] - B[2][3];
    out[3][0] = A[3][0] - B[3][0];
    out[3][1] = A[3][1] - B[3][1];
    out[3][2] = A[3][2] - B[3][2];
    out[3][3] = A[3][3] - B[3][3];

    return CML_SUCCESS;
}


CML_Status cml_matrix4x4_scale(const CML_Matrix4x4 A, f64 t, CML_Matrix4x4 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] * t;
    out[0][1] = A[0][1] * t;
    out[0][2] = A[0][2] * t;
    out[0][3] = A[0][3] * t;
    out[1][0] = A[1][0] * t;
    out[1][1] = A[1][1] * t;
    out[1][2] = A[1][2] * t;
    out[1][3] = A[1][3] * t;
    out[2][0] = A[2][0] * t;
    out[2][1] = A[2][1] * t;
    out[2][2] = A[2][2] * t;
    out[2][3] = A[2][3] * t;
    out[3][0] = A[3][0] * t;
    out[3][1] = A[3][1] * t;
    out[3][2] = A[3][2] * t;
    out[3][3] = A[3][3] * t;

    return CML_SUCCESS;
}


CML_Status cml_matrix4x4_mult(const CML_Matrix4x4 A, const CML_Matrix4x4 B, CML_Matrix4x4 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2], a03 = A[0][3];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2], a13 = A[1][3];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2], a23 = A[2][3];
    f64 a30 = A[3][0], a31 = A[3][1], a32 = A[3][2], a33 = A[3][3];

    f64 b00 = B[0][0], b01 = B[0][1], b02 = B[0][2], b03 = B[0][3];
    f64 b10 = B[1][0], b11 = B[1][1], b12 = B[1][2], b13 = B[1][3];
    f64 b20 = B[2][0], b21 = B[2][1], b22 = B[2][2], b23 = B[2][3];
    f64 b30 = B[3][0], b31 = B[3][1], b32 = B[3][2], b33 = B[3][3];

    out[0][0] = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out[0][1] = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out[0][2] = a00*b02 + a01*b12 + a02*b22 + a03*b32;
    out[0][3] = a00*b03 + a01*b13 + a02*b23 + a03*b33;
    out[1][0] = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out[1][1] = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out[1][2] = a10*b02 + a11*b12 + a12*b22 + a13*b32;
    out[1][3] = a10*b03 + a11*b13 + a12*b23 + a13*b33;
    out[2][0] = a20*b00 + a21*b10 + a22*b20 + a23*b30;
    out[2][1] = a20*b01 + a21*b11 + a22*b21 + a23*b31;
    out[2][2] = a20*b02 + a21*b12 + a22*b22 + a23*b32;
    out[2][3] = a20*b03 + a21*b13 + a22*b23 + a23*b33;
    out[3][0] = a30*b00 + a31*b10 + a32*b20 + a33*b30;
    out[3][1] = a30*b01 + a31*b11 + a32*b21 + a33*b31;
    out[3][2] = a30*b02 + a31*b12 + a32*b22 + a33*b32;
    out[3][3] = a30*b03 + a31*b13 + a32*b23 + a33*b33;

    return CML_SUCCESS;
}


CML_Status cml_matrix4x4_mult_vector4(const CML_Matrix4x4 A, const CML_Vector4 v, CML_Vector4 out) {
    if (!A || !v || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2], a03 = A[0][3];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2], a13 = A[1][3];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2], a23 = A[2][3];
    f64 a30 = A[3][0], a31 = A[3][1], a32 = A[3][2], a33 = A[3][3];

    f64 v0 = v[0], v1 = v[1], v2 = v[2], v3 = v[3];

    out[0] = a00*v0 + a01*v1 + a02*v2 + a03*v3;
    out[1] = a10*v0 + a11*v1 + a12*v2 + a13*v3;
    out[2] = a20*v0 + a21*v1 + a22*v2 + a23*v3;
    out[3] = a30*v0 + a31*v1 + a32*v2 + a33*v3;

    return CML_SUCCESS;
}


CML_Status cml_vector4_mult_matrix4x4(const CML_Vector4 v, const CML_Matrix4x4 A, CML_Vector4 out) {
    if (!v || !A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2], a03 = A[0][3];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2], a13 = A[1][3];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2], a23 = A[2][3];
    f64 a30 = A[3][0], a31 = A[3][1], a32 = A[3][2], a33 = A[3][3];

    f64 v0 = v[0], v1 = v[1], v2 = v[2], v3 = v[3];

    out[0] = a00*v0 + a10*v1 + a20*v2 + a30*v3;
    out[1] = a01*v0 + a11*v1 + a21*v2 + a31*v3;
    out[2] = a02*v0 + a12*v1 + a22*v2 + a32*v3;
    out[3] = a03*v0 + a13*v1 + a23*v2 + a33*v3;

    return CML_SUCCESS;
}


f64 cml_matrix4x4_det(const CML_Matrix4x4 A) {
    if (!A) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2], a03 = A[0][3];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2], a13 = A[1][3];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2], a23 = A[2][3];
    f64 a30 = A[3][0], a31 = A[3][1], a32 = A[3][2], a33 = A[3][3];

    return a03*a12*a21*a30 - a02*a13*a21*a30 - a03*a11*a22*a30 + a01*a13*a22*a30+
           a02*a11*a23*a30 - a01*a12*a23*a30 - a03*a12*a20*a31 + a02*a13*a20*a31+
           a03*a10*a22*a31 - a00*a13*a22*a31 - a02*a10*a23*a31 + a00*a12*a23*a31+
           a03*a11*a20*a32 - a01*a13*a20*a32 - a03*a10*a21*a32 + a00*a13*a21*a32+
           a01*a10*a23*a32 - a00*a11*a23*a32 - a02*a11*a20*a33 + a01*a12*a20*a33+
           a02*a10*a21*a33 - a00*a12*a21*a33 - a01*a10*a22*a33 + a00*a11*a22*a33;
}


CML_Status cml_matrix4x4_inv(const CML_Matrix4x4 A, CML_Matrix4x4 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2], a03 = A[0][3];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2], a13 = A[1][3];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2], a23 = A[2][3];
    f64 a30 = A[3][0], a31 = A[3][1], a32 = A[3][2], a33 = A[3][3];

    f64 det = a03*a12*a21*a30 - a02*a13*a21*a30 - a03*a11*a22*a30 + a01*a13*a22*a30+
              a02*a11*a23*a30 - a01*a12*a23*a30 - a03*a12*a20*a31 + a02*a13*a20*a31+
              a03*a10*a22*a31 - a00*a13*a22*a31 - a02*a10*a23*a31 + a00*a12*a23*a31+
              a03*a11*a20*a32 - a01*a13*a20*a32 - a03*a10*a21*a32 + a00*a13*a21*a32+
              a01*a10*a23*a32 - a00*a11*a23*a32 - a02*a11*a20*a33 + a01*a12*a20*a33+
              a02*a10*a21*a33 - a00*a12*a21*a33 - a01*a10*a22*a33 + a00*a11*a22*a33;

    if (det == 0.0) {
        return CML_ERR_NULL_PTR; // TODO: Change to singular matrix error.
    }

    det = 1/det;

    out[0][0] = (a12*a23*a31 - a13*a22*a31 + a13*a21*a32 - a11*a23*a32 - a12*a21*a33 + a11*a22*a33)*det;
    out[0][1] = (a03*a22*a31 - a02*a23*a31 - a03*a21*a32 + a01*a23*a32 + a02*a21*a33 - a01*a22*a33)*det;
    out[0][2] = (a02*a13*a31 - a03*a12*a31 + a03*a11*a32 - a01*a13*a32 - a02*a11*a33 + a01*a12*a33)*det;
    out[0][3] = (a03*a12*a21 - a02*a13*a21 - a03*a11*a22 + a01*a13*a22 + a02*a11*a23 - a01*a12*a23)*det;
    out[1][0] = (a13*a22*a30 - a12*a23*a30 - a13*a20*a32 + a10*a23*a32 + a12*a20*a33 - a10*a22*a33)*det;
    out[1][1] = (a02*a23*a30 - a03*a22*a30 + a03*a20*a32 - a00*a23*a32 - a02*a20*a33 + a00*a22*a33)*det;
    out[1][2] = (a03*a12*a30 - a02*a13*a30 - a03*a10*a32 + a00*a13*a32 + a02*a10*a33 - a00*a12*a33)*det;
    out[1][3] = (a02*a13*a20 - a03*a12*a20 + a03*a10*a22 - a00*a13*a22 - a02*a10*a23 + a00*a12*a23)*det;
    out[2][0] = (a11*a23*a30 - a13*a21*a30 + a13*a20*a31 - a10*a23*a31 - a11*a20*a33 + a10*a21*a33)*det;
    out[2][1] = (a03*a21*a30 - a01*a23*a30 - a03*a20*a31 + a00*a23*a31 + a01*a20*a33 - a00*a21*a33)*det;
    out[2][2] = (a01*a13*a30 - a03*a11*a30 + a03*a10*a31 - a00*a13*a31 - a01*a10*a33 + a00*a11*a33)*det;
    out[2][3] = (a03*a11*a20 - a01*a13*a20 - a03*a10*a21 + a00*a13*a21 + a01*a10*a23 - a00*a11*a23)*det;
    out[3][0] = (a12*a21*a30 - a11*a22*a30 - a12*a20*a31 + a10*a22*a31 + a11*a20*a32 - a10*a21*a32)*det;
    out[3][1] = (a01*a22*a30 - a02*a21*a30 + a02*a20*a31 - a00*a22*a31 - a01*a20*a32 + a00*a21*a32)*det;
    out[3][2] = (a02*a11*a30 - a01*a12*a30 - a02*a10*a31 + a00*a12*a31 + a01*a10*a32 - a00*a11*a32)*det;
    out[3][3] = (a01*a12*a20 - a02*a11*a20 + a02*a10*a21 - a00*a12*a21 - a01*a10*a22 + a00*a11*a22)*det;

    return CML_SUCCESS;
}


CML_Status cml_matrix4x4_transpose(const CML_Matrix4x4 A, CML_Matrix4x4 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2], a03 = A[0][3];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2], a13 = A[1][3];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2], a23 = A[2][3];
    f64 a30 = A[3][0], a31 = A[3][1], a32 = A[3][2], a33 = A[3][3];

    out[0][0] = a00;
    out[0][1] = a10;
    out[0][2] = a20;
    out[0][3] = a30;
    out[1][0] = a01;
    out[1][1] = a11;
    out[1][2] = a21;
    out[1][3] = a31;
    out[2][0] = a02;
    out[2][1] = a12;
    out[2][2] = a22;
    out[2][3] = a32;
    out[3][0] = a03;
    out[3][1] = a13;
    out[3][2] = a23;
    out[3][3] = a33;

    return CML_SUCCESS;
}


f64 cml_matrix4x4_trace(const CML_Matrix4x4 A) {
    if (!A) {
        return CML_ERR_NULL_PTR;
    }

    return A[0][0] + A[1][1] + A[2][2] + A[3][3];
}


CML_Bool cml_matrix4x4_eq(const CML_Matrix4x4 A, const CML_Matrix4x4 B) {
    if (!A || !B) {
        return CML_FALSE;
    }

    return (fabs(A[0][0] - B[0][0]) <= CML_EPSILON && fabs(A[0][1] - B[0][1]) <= CML_EPSILON && 
            fabs(A[0][2] - B[0][2]) <= CML_EPSILON && fabs(A[0][3] - B[0][3]) <= CML_EPSILON && 
            fabs(A[1][0] - B[1][0]) <= CML_EPSILON && fabs(A[1][1] - B[1][1]) <= CML_EPSILON && 
            fabs(A[1][2] - B[1][2]) <= CML_EPSILON && fabs(A[1][3] - B[1][3]) <= CML_EPSILON && 
            fabs(A[2][0] - B[2][0]) <= CML_EPSILON && fabs(A[2][1] - B[2][1]) <= CML_EPSILON && 
            fabs(A[2][2] - B[2][2]) <= CML_EPSILON && fabs(A[2][3] - B[2][3]) <= CML_EPSILON && 
            fabs(A[3][0] - B[3][0]) <= CML_EPSILON && fabs(A[3][1] - B[3][1]) <= CML_EPSILON && 
            fabs(A[3][2] - B[3][2]) <= CML_EPSILON && fabs(A[3][3] - B[3][3]) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cml_matrix4x4_debug(const CML_Matrix4x4 expected, const CML_Matrix4x4 got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    sprintf(debugMessage, "\t\tExpected:\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n", 
            expected[0][0], expected[0][1], expected[0][2], expected[0][3], 
            expected[1][0], expected[1][1], expected[1][2], expected[1][3], 
            expected[2][0], expected[2][1], expected[2][2], expected[2][3], 
            expected[3][0], expected[3][1], expected[3][2], expected[3][3], 
            got[0][0], got[0][1], got[0][2], got[0][3], 
            got[1][0], got[1][1], got[1][2], got[1][3], 
            got[2][0], got[2][1], got[2][2], got[2][3], 
            got[3][0], got[3][1], got[3][2], got[3][3]);

    return debugMessage;
}



CML_Status cml_matrix2x3_add(const CML_Matrix2x3 A, const CML_Matrix2x3 B, CML_Matrix2x3 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] + B[0][0];
    out[0][1] = A[0][1] + B[0][1];
    out[0][2] = A[0][2] + B[0][2];
    out[1][0] = A[1][0] + B[1][0];
    out[1][1] = A[1][1] + B[1][1];
    out[1][2] = A[1][2] + B[1][2];

    return CML_SUCCESS;
}


CML_Status cml_matrix2x3_sub(const CML_Matrix2x3 A, const CML_Matrix2x3 B, CML_Matrix2x3 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] - B[0][0];
    out[0][1] = A[0][1] - B[0][1];
    out[0][2] = A[0][2] - B[0][2];
    out[1][0] = A[1][0] - B[1][0];
    out[1][1] = A[1][1] - B[1][1];
    out[1][2] = A[1][2] - B[1][2];

    return CML_SUCCESS;
}


CML_Status cml_matrix2x3_scale(const CML_Matrix2x3 A, f64 t, CML_Matrix2x3 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] * t;
    out[0][1] = A[0][1] * t;
    out[0][2] = A[0][2] * t;
    out[1][0] = A[1][0] * t;
    out[1][1] = A[1][1] * t;
    out[1][2] = A[1][2] * t;

    return CML_SUCCESS;
}


CML_Status cml_matrix2x3_mult_matrix3x2(const CML_Matrix2x3 A, const CML_Matrix3x2 B, CML_Matrix2x2 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2];

    f64 b00 = B[0][0], b01 = B[0][1];
    f64 b10 = B[1][0], b11 = B[1][1];
    f64 b20 = B[2][0], b21 = B[2][1];

    out[0][0] = a00*b00 + a01*b10 + a02*b20;
    out[0][1] = a00*b01 + a01*b11 + a02*b21;
    out[1][0] = a10*b00 + a11*b10 + a12*b20;
    out[1][1] = a10*b01 + a11*b11 + a12*b21;

    return CML_SUCCESS;
}


CML_Status cml_matrix2x3_mult_matrix3x3(const CML_Matrix2x3 A, const CML_Matrix3x3 B, CML_Matrix2x3 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2];

    f64 b00 = B[0][0], b01 = B[0][1], b02 = B[0][2];
    f64 b10 = B[1][0], b11 = B[1][1], b12 = B[1][2];
    f64 b20 = B[2][0], b21 = B[2][1], b22 = B[2][2];

    out[0][0] = a00*b00 + a01*b10 + a02*b20;
    out[0][1] = a00*b01 + a01*b11 + a02*b21;
    out[0][2] = a00*b02 + a01*b12 + a02*b22;
    out[1][0] = a10*b00 + a11*b10 + a12*b20;
    out[1][1] = a10*b01 + a11*b11 + a12*b21;
    out[1][2] = a10*b02 + a11*b12 + a12*b22;

    return CML_SUCCESS;
}


CML_Status cml_matrix2x3_mult_matrix3x4(const CML_Matrix2x3 A, const CML_Matrix3x4 B, CML_Matrix2x4 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2];

    f64 b00 = B[0][0], b01 = B[0][1], b02 = B[0][2], b03 = B[0][3];
    f64 b10 = B[1][0], b11 = B[1][1], b12 = B[1][2], b13 = B[1][3];
    f64 b20 = B[2][0], b21 = B[2][1], b22 = B[2][2], b23 = B[2][3];

    out[0][0] = a00*b00 + a01*b10 + a02*b20;
    out[0][1] = a00*b01 + a01*b11 + a02*b21;
    out[0][2] = a00*b02 + a01*b12 + a02*b22;
    out[0][3] = a00*b03 + a01*b13 + a02*b23;
    out[1][0] = a10*b00 + a11*b10 + a12*b20;
    out[1][1] = a10*b01 + a11*b11 + a12*b21;
    out[1][2] = a10*b02 + a11*b12 + a12*b22;
    out[1][3] = a10*b03 + a11*b13 + a12*b23;

    return CML_SUCCESS;
}


CML_Status cml_matrix2x3_mult_vector3(const CML_Matrix2x3 A, const CML_Vector3 v, CML_Vector2 out) {
    if (!A || !v || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2];

    f64 v0 = v[0], v1 = v[1], v2 = v[2];

    out[0] = a00*v0 + a01*v1 + a02*v2;
    out[1] = a10*v0 + a11*v1 + a12*v2;

    return CML_SUCCESS;
}


CML_Status cml_vector2_mult_matrix2x3(const CML_Vector2 v, const CML_Matrix2x3 A, CML_Vector3 out) {
    if (!v || !A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2];

    f64 v0 = v[0], v1 = v[1];

    out[0] = a00*v0 + a10*v1;
    out[1] = a01*v0 + a11*v1;
    out[2] = a02*v0 + a12*v1;

    return CML_SUCCESS;
}


CML_Status cml_matrix2x3_transpose(const CML_Matrix2x3 A, CML_Matrix3x2 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2];

    out[0][0] = a00;
    out[0][1] = a10;
    out[1][0] = a01;
    out[1][1] = a11;
    out[2][0] = a02;
    out[2][1] = a12;

    return CML_SUCCESS;
}


CML_Bool cml_matrix2x3_eq(const CML_Matrix2x3 A, const CML_Matrix2x3 B) {
    if (!A || !B) {
        return CML_FALSE;
    }

    return (fabs(A[0][0] - B[0][0]) <= CML_EPSILON && fabs(A[0][1] - B[0][1]) <= CML_EPSILON && 
            fabs(A[0][2] - B[0][2]) <= CML_EPSILON && fabs(A[1][0] - B[1][0]) <= CML_EPSILON && 
            fabs(A[1][1] - B[1][1]) <= CML_EPSILON && fabs(A[1][2] - B[1][2]) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cml_matrix2x3_debug(const CML_Matrix2x3 expected, const CML_Matrix2x3 got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    sprintf(debugMessage, "\t\tExpected:\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n", 
            expected[0][0], expected[0][1], expected[0][2], 
            expected[1][0], expected[1][1], expected[1][2], 
            got[0][0], got[0][1], got[0][2], 
            got[1][0], got[1][1], got[1][2]);

    return debugMessage;
}



CML_Status cml_matrix2x4_add(const CML_Matrix2x4 A, const CML_Matrix2x4 B, CML_Matrix2x4 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] + B[0][0];
    out[0][1] = A[0][1] + B[0][1];
    out[0][2] = A[0][2] + B[0][2];
    out[0][3] = A[0][3] + B[0][3];
    out[1][0] = A[1][0] + B[1][0];
    out[1][1] = A[1][1] + B[1][1];
    out[1][2] = A[1][2] + B[1][2];
    out[1][3] = A[1][3] + B[1][3];

    return CML_SUCCESS;
}


CML_Status cml_matrix2x4_sub(const CML_Matrix2x4 A, const CML_Matrix2x4 B, CML_Matrix2x4 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] - B[0][0];
    out[0][1] = A[0][1] - B[0][1];
    out[0][2] = A[0][2] - B[0][2];
    out[0][3] = A[0][3] - B[0][3];
    out[1][0] = A[1][0] - B[1][0];
    out[1][1] = A[1][1] - B[1][1];
    out[1][2] = A[1][2] - B[1][2];
    out[1][3] = A[1][3] - B[1][3];

    return CML_SUCCESS;
}


CML_Status cml_matrix2x4_scale(const CML_Matrix2x4 A, f64 t, CML_Matrix2x4 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] * t;
    out[0][1] = A[0][1] * t;
    out[0][2] = A[0][2] * t;
    out[0][3] = A[0][3] * t;
    out[1][0] = A[1][0] * t;
    out[1][1] = A[1][1] * t;
    out[1][2] = A[1][2] * t;
    out[1][3] = A[1][3] * t;

    return CML_SUCCESS;
}


CML_Status cml_matrix2x4_mult_matrix4x2(const CML_Matrix2x4 A, const CML_Matrix4x2 B, CML_Matrix2x2 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2], a03 = A[0][3];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2], a13 = A[1][3];

    f64 b00 = B[0][0], b01 = B[0][1];
    f64 b10 = B[1][0], b11 = B[1][1];
    f64 b20 = B[2][0], b21 = B[2][1];
    f64 b30 = B[3][0], b31 = B[3][1];

    out[0][0] = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out[0][1] = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out[1][0] = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out[1][1] = a10*b01 + a11*b11 + a12*b21 + a13*b31;

    return CML_SUCCESS;
}


CML_Status cml_matrix2x4_mult_matrix4x3(const CML_Matrix2x4 A, const CML_Matrix4x3 B, CML_Matrix2x3 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2], a03 = A[0][3];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2], a13 = A[1][3];

    f64 b00 = B[0][0], b01 = B[0][1], b02 = B[0][2];
    f64 b10 = B[1][0], b11 = B[1][1], b12 = B[1][2];
    f64 b20 = B[2][0], b21 = B[2][1], b22 = B[2][2];
    f64 b30 = B[3][0], b31 = B[3][1], b32 = B[3][2];

    out[0][0] = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out[0][1] = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out[0][2] = a00*b02 + a01*b12 + a02*b22 + a03*b32;
    out[1][0] = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out[1][1] = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out[1][2] = a10*b02 + a11*b12 + a12*b22 + a13*b32;

    return CML_SUCCESS;
}


CML_Status cml_matrix2x4_mult_matrix4x4(const CML_Matrix2x4 A, const CML_Matrix4x4 B, CML_Matrix2x4 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2], a03 = A[0][3];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2], a13 = A[1][3];

    f64 b00 = B[0][0], b01 = B[0][1], b02 = B[0][2], b03 = B[0][3];
    f64 b10 = B[1][0], b11 = B[1][1], b12 = B[1][2], b13 = B[1][3];
    f64 b20 = B[2][0], b21 = B[2][1], b22 = B[2][2], b23 = B[2][3];
    f64 b30 = B[3][0], b31 = B[3][1], b32 = B[3][2], b33 = B[3][3];

    out[0][0] = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out[0][1] = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out[0][2] = a00*b02 + a01*b12 + a02*b22 + a03*b32;
    out[0][3] = a00*b03 + a01*b13 + a02*b23 + a03*b33;
    out[1][0] = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out[1][1] = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out[1][2] = a10*b02 + a11*b12 + a12*b22 + a13*b32;
    out[1][3] = a10*b03 + a11*b13 + a12*b23 + a13*b33;

    return CML_SUCCESS;
}


CML_Status cml_matrix2x4_mult_vector4(const CML_Matrix2x4 A, const CML_Vector4 v, CML_Vector2 out) {
    if (!A || !v || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2], a03 = A[0][3];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2], a13 = A[1][3];

    f64 v0 = v[0], v1 = v[1], v2 = v[2], v3 = v[3];

    out[0] = a00*v0 + a01*v1 + a02*v2 + a03*v3;
    out[1] = a10*v0 + a11*v1 + a12*v2 + a13*v3;

    return CML_SUCCESS;
}


CML_Status cml_vector2_mult_matrix2x4(const CML_Vector2 v, const CML_Matrix2x4 A, CML_Vector4 out) {
    if (!v || !A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2], a03 = A[0][3];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2], a13 = A[1][3];

    f64 v0 = v[0], v1 = v[1];

    out[0] = a00*v0 + a10*v1;
    out[1] = a01*v0 + a11*v1;
    out[2] = a02*v0 + a12*v1;
    out[3] = a03*v0 + a13*v1;

    return CML_SUCCESS;
}


CML_Status cml_matrix2x4_transpose(const CML_Matrix2x4 A, CML_Matrix4x2 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2], a03 = A[0][3];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2], a13 = A[1][3];

    out[0][0] = a00;
    out[0][1] = a10;
    out[1][0] = a01;
    out[1][1] = a11;
    out[2][0] = a02;
    out[2][1] = a12;
    out[3][0] = a03;
    out[3][1] = a13;

    return CML_SUCCESS;
}


CML_Bool cml_matrix2x4_eq(const CML_Matrix2x4 A, const CML_Matrix2x4 B) {
    if (!A || !B) {
        return CML_FALSE;
    }

    return (fabs(A[0][0] - B[0][0]) <= CML_EPSILON && fabs(A[0][1] - B[0][1]) <= CML_EPSILON && 
            fabs(A[0][2] - B[0][2]) <= CML_EPSILON && fabs(A[0][3] - B[0][3]) <= CML_EPSILON && 
            fabs(A[1][0] - B[1][0]) <= CML_EPSILON && fabs(A[1][1] - B[1][1]) <= CML_EPSILON && 
            fabs(A[1][2] - B[1][2]) <= CML_EPSILON && fabs(A[1][3] - B[1][3]) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cml_matrix2x4_debug(const CML_Matrix2x4 expected, const CML_Matrix2x4 got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    sprintf(debugMessage, "\t\tExpected:\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n", 
            expected[0][0], expected[0][1], expected[0][2], expected[0][3], 
            expected[1][0], expected[1][1], expected[1][2], expected[1][3], 
            got[0][0], got[0][1], got[0][2], got[0][3], 
            got[1][0], got[1][1], got[1][2], got[1][3]);

    return debugMessage;
}



CML_Status cml_matrix3x2_add(const CML_Matrix3x2 A, const CML_Matrix3x2 B, CML_Matrix3x2 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] + B[0][0];
    out[0][1] = A[0][1] + B[0][1];
    out[1][0] = A[1][0] + B[1][0];
    out[1][1] = A[1][1] + B[1][1];
    out[2][0] = A[2][0] + B[2][0];
    out[2][1] = A[2][1] + B[2][1];

    return CML_SUCCESS;
}


CML_Status cml_matrix3x2_sub(const CML_Matrix3x2 A, const CML_Matrix3x2 B, CML_Matrix3x2 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] - B[0][0];
    out[0][1] = A[0][1] - B[0][1];
    out[1][0] = A[1][0] - B[1][0];
    out[1][1] = A[1][1] - B[1][1];
    out[2][0] = A[2][0] - B[2][0];
    out[2][1] = A[2][1] - B[2][1];

    return CML_SUCCESS;
}


CML_Status cml_matrix3x2_scale(const CML_Matrix3x2 A, f64 t, CML_Matrix3x2 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] * t;
    out[0][1] = A[0][1] * t;
    out[1][0] = A[1][0] * t;
    out[1][1] = A[1][1] * t;
    out[2][0] = A[2][0] * t;
    out[2][1] = A[2][1] * t;

    return CML_SUCCESS;
}


CML_Status cml_matrix3x2_mult_matrix2x2(const CML_Matrix3x2 A, const CML_Matrix2x2 B, CML_Matrix3x2 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1];
    f64 a10 = A[1][0], a11 = A[1][1];
    f64 a20 = A[2][0], a21 = A[2][1];

    f64 b00 = B[0][0], b01 = B[0][1];
    f64 b10 = B[1][0], b11 = B[1][1];

    out[0][0] = a00*b00 + a01*b10;
    out[0][1] = a00*b01 + a01*b11;
    out[1][0] = a10*b00 + a11*b10;
    out[1][1] = a10*b01 + a11*b11;
    out[2][0] = a20*b00 + a21*b10;
    out[2][1] = a20*b01 + a21*b11;

    return CML_SUCCESS;
}


CML_Status cml_matrix3x2_mult_matrix2x3(const CML_Matrix3x2 A, const CML_Matrix2x3 B, CML_Matrix3x3 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1];
    f64 a10 = A[1][0], a11 = A[1][1];
    f64 a20 = A[2][0], a21 = A[2][1];

    f64 b00 = B[0][0], b01 = B[0][1], b02 = B[0][2];
    f64 b10 = B[1][0], b11 = B[1][1], b12 = B[1][2];

    out[0][0] = a00*b00 + a01*b10;
    out[0][1] = a00*b01 + a01*b11;
    out[0][2] = a00*b02 + a01*b12;
    out[1][0] = a10*b00 + a11*b10;
    out[1][1] = a10*b01 + a11*b11;
    out[1][2] = a10*b02 + a11*b12;
    out[2][0] = a20*b00 + a21*b10;
    out[2][1] = a20*b01 + a21*b11;
    out[2][2] = a20*b02 + a21*b12;

    return CML_SUCCESS;
}


CML_Status cml_matrix3x2_mult_matrix2x4(const CML_Matrix3x2 A, const CML_Matrix2x4 B, CML_Matrix3x4 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1];
    f64 a10 = A[1][0], a11 = A[1][1];
    f64 a20 = A[2][0], a21 = A[2][1];

    f64 b00 = B[0][0], b01 = B[0][1], b02 = B[0][2], b03 = B[0][3];
    f64 b10 = B[1][0], b11 = B[1][1], b12 = B[1][2], b13 = B[1][3];

    out[0][0] = a00*b00 + a01*b10;
    out[0][1] = a00*b01 + a01*b11;
    out[0][2] = a00*b02 + a01*b12;
    out[0][3] = a00*b03 + a01*b13;
    out[1][0] = a10*b00 + a11*b10;
    out[1][1] = a10*b01 + a11*b11;
    out[1][2] = a10*b02 + a11*b12;
    out[1][3] = a10*b03 + a11*b13;
    out[2][0] = a20*b00 + a21*b10;
    out[2][1] = a20*b01 + a21*b11;
    out[2][2] = a20*b02 + a21*b12;
    out[2][3] = a20*b03 + a21*b13;

    return CML_SUCCESS;
}


CML_Status cml_matrix3x2_mult_vector2(const CML_Matrix3x2 A, const CML_Vector2 v, CML_Vector3 out) {
    if (!A || !v || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1];
    f64 a10 = A[1][0], a11 = A[1][1];
    f64 a20 = A[2][0], a21 = A[2][1];

    f64 v0 = v[0], v1 = v[1];

    out[0] = a00*v0 + a01*v1;
    out[1] = a10*v0 + a11*v1;
    out[2] = a20*v0 + a21*v1;

    return CML_SUCCESS;
}


CML_Status cml_vector3_mult_matrix3x2(const CML_Vector3 v, const CML_Matrix3x2 A, CML_Vector2 out) {
    if (!v || !A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1];
    f64 a10 = A[1][0], a11 = A[1][1];
    f64 a20 = A[2][0], a21 = A[2][1];

    f64 v0 = v[0], v1 = v[1], v2 = v[2];

    out[0] = a00*v0 + a10*v1 + a20*v2;
    out[1] = a01*v0 + a11*v1 + a21*v2;

    return CML_SUCCESS;
}


CML_Status cml_matrix3x2_transpose(const CML_Matrix3x2 A, CML_Matrix2x3 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1];
    f64 a10 = A[1][0], a11 = A[1][1];
    f64 a20 = A[2][0], a21 = A[2][1];

    out[0][0] = a00;
    out[0][1] = a10;
    out[0][2] = a20;
    out[1][0] = a01;
    out[1][1] = a11;
    out[1][2] = a21;
    
    return CML_SUCCESS;
}


CML_Bool cml_matrix3x2_eq(const CML_Matrix3x2 A, const CML_Matrix3x2 B) {
    if (!A || !B) {
        return CML_FALSE;
    }

    return (fabs(A[0][0] - B[0][0]) <= CML_EPSILON && fabs(A[0][1] - B[0][1]) <= CML_EPSILON && 
            fabs(A[1][0] - B[1][0]) <= CML_EPSILON && fabs(A[1][1] - B[1][1]) <= CML_EPSILON && 
            fabs(A[2][0] - B[2][0]) <= CML_EPSILON && fabs(A[2][1] - B[2][1]) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cml_matrix3x2_debug(const CML_Matrix3x2 expected, const CML_Matrix3x2 got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    sprintf(debugMessage, "\t\tExpected:\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n", 
            expected[0][0], expected[0][1], 
            expected[1][0], expected[1][1], 
            expected[2][0], expected[2][1], 
            got[0][0], got[0][1], 
            got[1][0], got[1][1], 
            got[2][0], got[2][1]);

    return debugMessage;
}



CML_Status cml_matrix3x4_add(const CML_Matrix3x4 A, const CML_Matrix3x4 B, CML_Matrix3x4 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] + B[0][0];
    out[0][1] = A[0][1] + B[0][1];
    out[0][2] = A[0][2] + B[0][2];
    out[0][3] = A[0][3] + B[0][3];
    out[1][0] = A[1][0] + B[1][0];
    out[1][1] = A[1][1] + B[1][1];
    out[1][2] = A[1][2] + B[1][2];
    out[1][3] = A[1][3] + B[1][3];
    out[2][0] = A[2][0] + B[2][0];
    out[2][1] = A[2][1] + B[2][1];
    out[2][2] = A[2][2] + B[2][2];
    out[2][3] = A[2][3] + B[2][3];

    return CML_SUCCESS;
}


CML_Status cml_matrix3x4_sub(const CML_Matrix3x4 A, const CML_Matrix3x4 B, CML_Matrix3x4 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] - B[0][0];
    out[0][1] = A[0][1] - B[0][1];
    out[0][2] = A[0][2] - B[0][2];
    out[0][3] = A[0][3] - B[0][3];
    out[1][0] = A[1][0] - B[1][0];
    out[1][1] = A[1][1] - B[1][1];
    out[1][2] = A[1][2] - B[1][2];
    out[1][3] = A[1][3] - B[1][3];
    out[2][0] = A[2][0] - B[2][0];
    out[2][1] = A[2][1] - B[2][1];
    out[2][2] = A[2][2] - B[2][2];
    out[2][3] = A[2][3] - B[2][3];

    return CML_SUCCESS;
}


CML_Status cml_matrix3x4_scale(const CML_Matrix3x4 A, f64 t, CML_Matrix3x4 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] * t;
    out[0][1] = A[0][1] * t;
    out[0][2] = A[0][2] * t;
    out[0][3] = A[0][3] * t;
    out[1][0] = A[1][0] * t;
    out[1][1] = A[1][1] * t;
    out[1][2] = A[1][2] * t;
    out[1][3] = A[1][3] * t;
    out[2][0] = A[2][0] * t;
    out[2][1] = A[2][1] * t;
    out[2][2] = A[2][2] * t;
    out[2][3] = A[2][3] * t;

    return CML_SUCCESS;
}


CML_Status cml_matrix3x4_mult_matrix4x2(const CML_Matrix3x4 A, const CML_Matrix4x2 B, CML_Matrix3x2 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2], a03 = A[0][3];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2], a13 = A[1][3];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2], a23 = A[2][3];

    f64 b00 = B[0][0], b01 = B[0][1];
    f64 b10 = B[1][0], b11 = B[1][1];
    f64 b20 = B[2][0], b21 = B[2][1];
    f64 b30 = B[3][0], b31 = B[3][1];

    out[0][0] = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out[0][1] = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out[1][0] = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out[1][1] = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out[2][0] = a20*b00 + a21*b10 + a22*b20 + a23*b30;
    out[2][1] = a20*b01 + a21*b11 + a22*b21 + a23*b31;

    return CML_SUCCESS;
}


CML_Status cml_matrix3x4_mult_matrix4x3(const CML_Matrix3x4 A, const CML_Matrix4x3 B, CML_Matrix3x3 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2], a03 = A[0][3];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2], a13 = A[1][3];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2], a23 = A[2][3];

    f64 b00 = B[0][0], b01 = B[0][1], b02 = B[0][2];
    f64 b10 = B[1][0], b11 = B[1][1], b12 = B[1][2];
    f64 b20 = B[2][0], b21 = B[2][1], b22 = B[2][2];
    f64 b30 = B[3][0], b31 = B[3][1], b32 = B[3][2];

    out[0][0] = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out[0][1] = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out[0][2] = a00*b02 + a01*b12 + a02*b22 + a03*b32;
    out[1][0] = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out[1][1] = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out[1][2] = a10*b02 + a11*b12 + a12*b22 + a13*b32;
    out[2][0] = a20*b00 + a21*b10 + a22*b20 + a23*b30;
    out[2][1] = a20*b01 + a21*b11 + a22*b21 + a23*b31;
    out[2][2] = a20*b02 + a21*b12 + a22*b22 + a23*b32;

    return CML_SUCCESS;
}


CML_Status cml_matrix3x4_mult_matrix4x4(const CML_Matrix3x4 A, const CML_Matrix4x4 B, CML_Matrix3x4 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2], a03 = A[0][3];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2], a13 = A[1][3];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2], a23 = A[2][3];

    f64 b00 = B[0][0], b01 = B[0][1], b02 = B[0][2], b03 = B[0][3];
    f64 b10 = B[1][0], b11 = B[1][1], b12 = B[1][2], b13 = B[1][3];
    f64 b20 = B[2][0], b21 = B[2][1], b22 = B[2][2], b23 = B[2][3];
    f64 b30 = B[3][0], b31 = B[3][1], b32 = B[3][2], b33 = B[3][3];

    out[0][0] = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out[0][1] = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out[0][2] = a00*b02 + a01*b12 + a02*b22 + a03*b32;
    out[0][3] = a00*b03 + a01*b13 + a02*b23 + a03*b33;
    out[1][0] = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out[1][1] = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out[1][2] = a10*b02 + a11*b12 + a12*b22 + a13*b32;
    out[1][3] = a10*b03 + a11*b13 + a12*b23 + a13*b33;
    out[2][0] = a20*b00 + a21*b10 + a22*b20 + a23*b30;
    out[2][1] = a20*b01 + a21*b11 + a22*b21 + a23*b31;
    out[2][2] = a20*b02 + a21*b12 + a22*b22 + a23*b32;
    out[2][3] = a20*b03 + a21*b13 + a22*b23 + a23*b33;

    return CML_SUCCESS;
}


CML_Status cml_matrix3x4_mult_vector4(const CML_Matrix3x4 A, const CML_Vector4 v, CML_Vector3 out) {
    if (!A || !v || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2], a03 = A[0][3];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2], a13 = A[1][3];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2], a23 = A[2][3];

    f64 v0 = v[0], v1 = v[1], v2 = v[2], v3 = v[3];

    out[0] = a00*v0 + a01*v1 + a02*v2 + a03*v3;
    out[1] = a10*v0 + a11*v1 + a12*v2 + a13*v3;
    out[2] = a20*v0 + a21*v1 + a22*v2 + a23*v3;

    return CML_SUCCESS;
}


CML_Status cml_vector3_mult_matrix3x4(const CML_Vector3 v, const CML_Matrix3x4 A, CML_Vector4 out) {
    if (!v || !A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2], a03 = A[0][3];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2], a13 = A[1][3];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2], a23 = A[2][3];

    f64 v0 = v[0], v1 = v[1], v2 = v[2];

    out[0] = a00*v0 + a10*v1 + a20*v2;
    out[1] = a01*v0 + a11*v1 + a21*v2;
    out[2] = a02*v0 + a12*v1 + a22*v2;
    out[3] = a03*v0 + a13*v1 + a23*v2;

    return CML_SUCCESS;
}


CML_Status cml_matrix3x4_transpose(const CML_Matrix3x4 A, CML_Matrix4x3 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2], a03 = A[0][3];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2], a13 = A[1][3];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2], a23 = A[2][3];

    out[0][0] = a00;
    out[0][1] = a10;
    out[0][2] = a20;
    out[1][0] = a01;
    out[1][1] = a11;
    out[1][2] = a21;
    out[2][0] = a02;
    out[2][1] = a12;
    out[2][2] = a22;
    out[3][0] = a03;
    out[3][1] = a13;
    out[3][2] = a23;

    return CML_SUCCESS;
}


CML_Bool cml_matrix3x4_eq(const CML_Matrix3x4 A, const CML_Matrix3x4 B) {
    if (!A || !B) {
        return CML_FALSE;
    }

    return (fabs(A[0][0] - B[0][0]) <= CML_EPSILON && fabs(A[0][1] - B[0][1]) <= CML_EPSILON && 
            fabs(A[0][2] - B[0][2]) <= CML_EPSILON && fabs(A[0][3] - B[0][3]) <= CML_EPSILON && 
            fabs(A[1][0] - B[1][0]) <= CML_EPSILON && fabs(A[1][1] - B[1][1]) <= CML_EPSILON && 
            fabs(A[1][2] - B[1][2]) <= CML_EPSILON && fabs(A[1][3] - B[1][3]) <= CML_EPSILON && 
            fabs(A[2][0] - B[2][0]) <= CML_EPSILON && fabs(A[2][1] - B[2][1]) <= CML_EPSILON && 
            fabs(A[2][2] - B[2][2]) <= CML_EPSILON && fabs(A[2][3] - B[2][3]) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cml_matrix3x4_debug(const CML_Matrix3x4 expected, const CML_Matrix3x4 got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    sprintf(debugMessage, "\t\tExpected:\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n", 
            expected[0][0], expected[0][1], expected[0][2], expected[0][3], 
            expected[1][0], expected[1][1], expected[1][2], expected[1][3], 
            expected[2][0], expected[2][1], expected[2][2], expected[2][3], 
            got[0][0], got[0][1], got[0][2], got[0][3], 
            got[1][0], got[1][1], got[1][2], got[1][3], 
            got[2][0], got[2][1], got[2][2], got[2][3]);

    return debugMessage;
}



CML_Status cml_matrix4x2_add(const CML_Matrix4x2 A, const CML_Matrix4x2 B, CML_Matrix4x2 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] + B[0][0];
    out[0][1] = A[0][1] + B[0][1];
    out[1][0] = A[1][0] + B[1][0];
    out[1][1] = A[1][1] + B[1][1];
    out[2][0] = A[2][0] + B[2][0];
    out[2][1] = A[2][1] + B[2][1];
    out[3][0] = A[3][0] + B[3][0];
    out[3][1] = A[3][1] + B[3][1];

    return CML_SUCCESS;
}


CML_Status cml_matrix4x2_sub(const CML_Matrix4x2 A, const CML_Matrix4x2 B, CML_Matrix4x2 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] - B[0][0];
    out[0][1] = A[0][1] - B[0][1];
    out[1][0] = A[1][0] - B[1][0];
    out[1][1] = A[1][1] - B[1][1];
    out[2][0] = A[2][0] - B[2][0];
    out[2][1] = A[2][1] - B[2][1];
    out[3][0] = A[3][0] - B[3][0];
    out[3][1] = A[3][1] - B[3][1];

    return CML_SUCCESS;
}


CML_Status cml_matrix4x2_scale(const CML_Matrix4x2 A, f64 t, CML_Matrix4x2 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] * t;
    out[0][1] = A[0][1] * t;
    out[1][0] = A[1][0] * t;
    out[1][1] = A[1][1] * t;
    out[2][0] = A[2][0] * t;
    out[2][1] = A[2][1] * t;
    out[3][0] = A[3][0] * t;
    out[3][1] = A[3][1] * t;

    return CML_SUCCESS;
}


CML_Status cml_matrix4x2_mult_matrix2x2(const CML_Matrix4x2 A, const CML_Matrix2x2 B, CML_Matrix4x2 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1];
    f64 a10 = A[1][0], a11 = A[1][1];
    f64 a20 = A[2][0], a21 = A[2][1];
    f64 a30 = A[3][0], a31 = A[3][1];

    f64 b00 = B[0][0], b01 = B[0][1];
    f64 b10 = B[1][0], b11 = B[1][1];

    out[0][0] = a00*b00 + a01*b10;
    out[0][1] = a00*b01 + a01*b11;
    out[1][0] = a10*b00 + a11*b10;
    out[1][1] = a10*b01 + a11*b11;
    out[2][0] = a20*b00 + a21*b10;
    out[2][1] = a20*b01 + a21*b11;
    out[3][0] = a30*b00 + a31*b10;
    out[3][1] = a30*b01 + a31*b11;

    return CML_SUCCESS;
}


CML_Status cml_matrix4x2_mult_matrix2x3(const CML_Matrix4x2 A, const CML_Matrix2x3 B, CML_Matrix4x3 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1];
    f64 a10 = A[1][0], a11 = A[1][1];
    f64 a20 = A[2][0], a21 = A[2][1];
    f64 a30 = A[3][0], a31 = A[3][1];

    f64 b00 = B[0][0], b01 = B[0][1], b02 = B[0][2];
    f64 b10 = B[1][0], b11 = B[1][1], b12 = B[1][2];

    out[0][0] = a00*b00 + a01*b10;
    out[0][1] = a00*b01 + a01*b11;
    out[0][2] = a00*b02 + a01*b12;
    out[1][0] = a10*b00 + a11*b10;
    out[1][1] = a10*b01 + a11*b11;
    out[1][2] = a10*b02 + a11*b12;
    out[2][0] = a20*b00 + a21*b10;
    out[2][1] = a20*b01 + a21*b11;
    out[2][2] = a20*b02 + a21*b12;
    out[3][0] = a30*b00 + a31*b10;
    out[3][1] = a30*b01 + a31*b11;
    out[3][2] = a30*b02 + a31*b12;

    return CML_SUCCESS;
}


CML_Status cml_matrix4x2_mult_matrix2x4(const CML_Matrix4x2 A, const CML_Matrix2x4 B, CML_Matrix4x4 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1];
    f64 a10 = A[1][0], a11 = A[1][1];
    f64 a20 = A[2][0], a21 = A[2][1];
    f64 a30 = A[3][0], a31 = A[3][1];

    f64 b00 = B[0][0], b01 = B[0][1], b02 = B[0][2], b03 = B[0][3];
    f64 b10 = B[1][0], b11 = B[1][1], b12 = B[1][2], b13 = B[1][3];

    out[0][0] = a00*b00 + a01*b10;
    out[0][1] = a00*b01 + a01*b11;
    out[0][2] = a00*b02 + a01*b12;
    out[0][3] = a00*b03 + a01*b13;
    out[1][0] = a10*b00 + a11*b10;
    out[1][1] = a10*b01 + a11*b11;
    out[1][2] = a10*b02 + a11*b12;
    out[1][3] = a10*b03 + a11*b13;
    out[2][0] = a20*b00 + a21*b10;
    out[2][1] = a20*b01 + a21*b11;
    out[2][2] = a20*b02 + a21*b12;
    out[2][3] = a20*b03 + a21*b13;
    out[3][0] = a30*b00 + a31*b10;
    out[3][1] = a30*b01 + a31*b11;
    out[3][2] = a30*b02 + a31*b12;
    out[3][3] = a30*b03 + a31*b13;

    return CML_SUCCESS;
}


CML_Status cml_matrix4x2_mult_vector2(const CML_Matrix4x2 A, const CML_Vector2 v, CML_Vector4 out) {
    if (!A || !v || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1];
    f64 a10 = A[1][0], a11 = A[1][1];
    f64 a20 = A[2][0], a21 = A[2][1];
    f64 a30 = A[3][0], a31 = A[3][1];

    f64 v0 = v[0], v1 = v[1];

    out[0] = a00*v0 + a01*v1;
    out[1] = a10*v0 + a11*v1;
    out[2] = a20*v0 + a21*v1;
    out[3] = a30*v0 + a31*v1;

    return CML_SUCCESS;
}


CML_Status cml_vector4_mult_matrix4x2(const CML_Vector4 v, const CML_Matrix4x2 A, CML_Vector2 out) {
    if (!v || !A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1];
    f64 a10 = A[1][0], a11 = A[1][1];
    f64 a20 = A[2][0], a21 = A[2][1];
    f64 a30 = A[3][0], a31 = A[3][1];

    f64 v0 = v[0], v1 = v[1], v2 = v[2], v3 = v[3];

    out[0] = a00*v0 + a10*v1 + a20*v2 + a30*v3;
    out[1] = a01*v0 + a11*v1 + a21*v2 + a31*v3;

    return CML_SUCCESS;
}


CML_Status cml_matrix4x2_transpose(const CML_Matrix4x2 A, CML_Matrix2x4 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0];
    out[0][1] = A[1][0];
    out[0][2] = A[2][0];
    out[0][3] = A[3][0];
    out[1][0] = A[0][1];
    out[1][1] = A[1][1];
    out[1][2] = A[2][1];
    out[1][3] = A[3][1];

    return CML_SUCCESS;
}


CML_Bool cml_matrix4x2_eq(const CML_Matrix4x2 A, const CML_Matrix4x2 B) {
    if (!A || !B) {
        return CML_FALSE;
    }

    return (fabs(A[0][0] - B[0][0]) <= CML_EPSILON && fabs(A[0][1] - B[0][1]) <= CML_EPSILON && 
            fabs(A[1][0] - B[1][0]) <= CML_EPSILON && fabs(A[1][1] - B[1][1]) <= CML_EPSILON && 
            fabs(A[2][0] - B[2][0]) <= CML_EPSILON && fabs(A[2][1] - B[2][1]) <= CML_EPSILON && 
            fabs(A[3][0] - B[3][0]) <= CML_EPSILON && fabs(A[3][1] - B[3][1]) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cml_matrix4x2_debug(const CML_Matrix4x2 expected, const CML_Matrix4x2 got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    sprintf(debugMessage, "\t\tExpected:\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n", 
        expected[0][0], expected[0][1],
        expected[1][0], expected[1][1],
        expected[2][0], expected[2][1],
        expected[3][0], expected[3][1],
        got[0][0], got[0][1],
        got[1][0], got[1][1],
        got[2][0], got[2][1],
        got[3][0], got[3][1]);

    return debugMessage;
}



CML_Status cml_matrix4x3_add(const CML_Matrix4x3 A, const CML_Matrix4x3 B, CML_Matrix4x3 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] + B[0][0];
    out[0][1] = A[0][1] + B[0][1];
    out[0][2] = A[0][2] + B[0][2];
    out[1][0] = A[1][0] + B[1][0];
    out[1][1] = A[1][1] + B[1][1];
    out[1][2] = A[1][2] + B[1][2];
    out[2][0] = A[2][0] + B[2][0];
    out[2][1] = A[2][1] + B[2][1];
    out[2][2] = A[2][2] + B[2][2];
    out[3][0] = A[3][0] + B[3][0];
    out[3][1] = A[3][1] + B[3][1];
    out[3][2] = A[3][2] + B[3][2];

    return CML_SUCCESS;
}


CML_Status cml_matrix4x3_sub(const CML_Matrix4x3 A, const CML_Matrix4x3 B, CML_Matrix4x3 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] - B[0][0];
    out[0][1] = A[0][1] - B[0][1];
    out[0][2] = A[0][2] - B[0][2];
    out[1][0] = A[1][0] - B[1][0];
    out[1][1] = A[1][1] - B[1][1];
    out[1][2] = A[1][2] - B[1][2];
    out[2][0] = A[2][0] - B[2][0];
    out[2][1] = A[2][1] - B[2][1];
    out[2][2] = A[2][2] - B[2][2];
    out[3][0] = A[3][0] - B[3][0];
    out[3][1] = A[3][1] - B[3][1];
    out[3][2] = A[3][2] - B[3][2];

    return CML_SUCCESS;
}


CML_Status cml_matrix4x3_scale(const CML_Matrix4x3 A, f64 t, CML_Matrix4x3 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0][0] = A[0][0] * t;
    out[0][1] = A[0][1] * t;
    out[0][2] = A[0][2] * t;
    out[1][0] = A[1][0] * t;
    out[1][1] = A[1][1] * t;
    out[1][2] = A[1][2] * t;
    out[2][0] = A[2][0] * t;
    out[2][1] = A[2][1] * t;
    out[2][2] = A[2][2] * t;
    out[3][0] = A[3][0] * t;
    out[3][1] = A[3][1] * t;
    out[3][2] = A[3][2] * t;

    return CML_SUCCESS;
}


CML_Status cml_matrix4x3_mult_matrix3x2(const CML_Matrix4x3 A, const CML_Matrix3x2 B, CML_Matrix4x2 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2];
    f64 a30 = A[3][0], a31 = A[3][1], a32 = A[3][2];

    f64 b00 = B[0][0], b01 = B[0][1];
    f64 b10 = B[1][0], b11 = B[1][1];
    f64 b20 = B[2][0], b21 = B[2][1];

    out[0][0] = a00*b00 + a01*b10 + a02*b20;
    out[0][1] = a00*b01 + a01*b11 + a02*b21;
    out[1][0] = a10*b00 + a11*b10 + a12*b20;
    out[1][1] = a10*b01 + a11*b11 + a12*b21;
    out[2][0] = a20*b00 + a21*b10 + a22*b20;
    out[2][1] = a20*b01 + a21*b11 + a22*b21;
    out[3][0] = a30*b00 + a31*b10 + a32*b20;
    out[3][1] = a30*b01 + a31*b11 + a32*b21;

    return CML_SUCCESS;
}


CML_Status cml_matrix4x3_mult_matrix3x3(const CML_Matrix4x3 A, const CML_Matrix3x3 B, CML_Matrix4x3 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2];
    f64 a30 = A[3][0], a31 = A[3][1], a32 = A[3][2];

    f64 b00 = B[0][0], b01 = B[0][1], b02 = B[0][2];
    f64 b10 = B[1][0], b11 = B[1][1], b12 = B[1][2];
    f64 b20 = B[2][0], b21 = B[2][1], b22 = B[2][2];

    out[0][0] = a00*b00 + a01*b10 + a02*b20;
    out[0][1] = a00*b01 + a01*b11 + a02*b21;
    out[0][2] = a00*b02 + a01*b12 + a02*b22;
    out[1][0] = a10*b00 + a11*b10 + a12*b20;
    out[1][1] = a10*b01 + a11*b11 + a12*b21;
    out[1][2] = a10*b02 + a11*b12 + a12*b22;
    out[2][0] = a20*b00 + a21*b10 + a22*b20;
    out[2][1] = a20*b01 + a21*b11 + a22*b21;
    out[2][2] = a20*b02 + a21*b12 + a22*b22;
    out[3][0] = a30*b00 + a31*b10 + a32*b20;
    out[3][1] = a30*b01 + a31*b11 + a32*b21;
    out[3][2] = a30*b02 + a31*b12 + a32*b22;

    return CML_SUCCESS;
}


CML_Status cml_matrix4x3_mult_matrix3x4(const CML_Matrix4x3 A, const CML_Matrix3x4 B, CML_Matrix4x4 out) {
    if (!A || !B || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2];
    f64 a30 = A[3][0], a31 = A[3][1], a32 = A[3][2];

    f64 b00 = B[0][0], b01 = B[0][1], b02 = B[0][2], b03 = B[0][3];
    f64 b10 = B[1][0], b11 = B[1][1], b12 = B[1][2], b13 = B[1][3];
    f64 b20 = B[2][0], b21 = B[2][1], b22 = B[2][2], b23 = B[2][3];

    out[0][0] = a00*b00 + a01*b10 + a02*b20;
    out[0][1] = a00*b01 + a01*b11 + a02*b21;
    out[0][2] = a00*b02 + a01*b12 + a02*b22;
    out[0][3] = a00*b03 + a01*b13 + a02*b23;
    out[1][0] = a10*b00 + a11*b10 + a12*b20;
    out[1][1] = a10*b01 + a11*b11 + a12*b21;
    out[1][2] = a10*b02 + a11*b12 + a12*b22;
    out[1][3] = a10*b03 + a11*b13 + a12*b23;
    out[2][0] = a20*b00 + a21*b10 + a22*b20;
    out[2][1] = a20*b01 + a21*b11 + a22*b21;
    out[2][2] = a20*b02 + a21*b12 + a22*b22;
    out[2][3] = a20*b03 + a21*b13 + a22*b23;
    out[3][0] = a30*b00 + a31*b10 + a32*b20;
    out[3][1] = a30*b01 + a31*b11 + a32*b21;
    out[3][2] = a30*b02 + a31*b12 + a32*b22;
    out[3][3] = a30*b03 + a31*b13 + a32*b23;

    return CML_SUCCESS;
}


CML_Status cml_matrix4x3_mult_vector3(const CML_Matrix4x3 A, const CML_Vector3 v, CML_Vector4 out) {
    if (!A || !v || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2];
    f64 a30 = A[3][0], a31 = A[3][1], a32 = A[3][2];

    f64 v0 = v[0], v1 = v[1], v2 = v[2];

    out[0] = a00*v0 + a01*v1 + a02*v2;
    out[1] = a10*v0 + a11*v1 + a12*v2;
    out[2] = a20*v0 + a21*v1 + a22*v2;
    out[3] = a30*v0 + a31*v1 + a32*v2;

    return CML_SUCCESS;
}


CML_Status cml_vector4_mult_matrix4x3(const CML_Vector4 v, const CML_Matrix4x3 A, CML_Vector3 out) {
    if (!v || !A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2];
    f64 a30 = A[3][0], a31 = A[3][1], a32 = A[3][2];

    f64 v0 = v[0], v1 = v[1], v2 = v[2], v3 = v[3];

    out[0] = a00*v0 + a10*v1 + a20*v2 + a30*v3;
    out[1] = a01*v0 + a11*v1 + a21*v2 + a31*v3;
    out[2] = a02*v0 + a12*v1 + a22*v2 + a32*v3;

    return CML_SUCCESS;
}


CML_Status cml_matrix4x3_transpose(const CML_Matrix4x3 A, CML_Matrix3x4 out) {
    if (!A || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 a00 = A[0][0], a01 = A[0][1], a02 = A[0][2];
    f64 a10 = A[1][0], a11 = A[1][1], a12 = A[1][2];
    f64 a20 = A[2][0], a21 = A[2][1], a22 = A[2][2];
    f64 a30 = A[3][0], a31 = A[3][1], a32 = A[3][2];

    out[0][0] = A[0][0];
    out[0][1] = A[1][0];
    out[0][2] = A[2][0];
    out[0][3] = A[3][0];
    out[1][0] = A[0][1];
    out[1][1] = A[1][1];
    out[1][2] = A[2][1];
    out[1][3] = A[3][1];
    out[2][0] = A[0][2];
    out[2][1] = A[1][2];
    out[2][2] = A[2][2];
    out[2][3] = A[3][2];

    return CML_SUCCESS;
}


CML_Bool cml_matrix4x3_eq(const CML_Matrix4x3 A, const CML_Matrix4x3 B) {
    if (!A || !B) {
        return CML_FALSE;
    }

    return (fabs(A[0][0] - B[0][0]) <= CML_EPSILON && fabs(A[0][1] - B[0][1]) <= CML_EPSILON && fabs(A[0][2] - B[0][2]) <= CML_EPSILON && 
            fabs(A[1][0] - B[1][0]) <= CML_EPSILON && fabs(A[1][1] - B[1][1]) <= CML_EPSILON && fabs(A[1][2] - B[1][2]) <= CML_EPSILON && 
            fabs(A[2][0] - B[2][0]) <= CML_EPSILON && fabs(A[2][1] - B[2][1]) <= CML_EPSILON && fabs(A[2][2] - B[2][2]) <= CML_EPSILON && 
            fabs(A[3][0] - B[3][0]) <= CML_EPSILON && fabs(A[3][1] - B[3][1]) <= CML_EPSILON && fabs(A[3][2] - B[3][2]) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cml_matrix4x3_debug(const CML_Matrix4x3 expected, const CML_Matrix4x3 got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    sprintf(debugMessage, "\t\tExpected:\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n", 
        expected[0][0], expected[0][1], expected[0][2],
        expected[1][0], expected[1][1], expected[1][2],
        expected[2][0], expected[2][1], expected[2][2],
        expected[3][0], expected[3][1], expected[3][2],
        got[0][0], got[0][1], got[0][2],
        got[1][0], got[1][1], got[1][2],
        got[2][0], got[2][1], got[2][2],
        got[3][0], got[3][1], got[3][2]);

    return debugMessage;
}
