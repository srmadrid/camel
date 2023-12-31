/******************************************************************************
 * Filename: cfmatrix.h
 * 
 * Description:
 *      Implementations for the compiled version of the fixed matrix manipulation 
 *      functions of CAMEL.
 * 
 * Author: Sergio Madrid
 * Created on: 26/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/

#include <math.h>

#include "../../../../include/algebra/linear/flinear/cfmatrix.h"


void cmlc_matrix2x2_add(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B, CML_Matrix2x2 *out) {
    out->m00 = A->m00 + B->m00;
    out->m01 = A->m01 + B->m01;
    out->m10 = A->m10 + B->m10;
    out->m11 = A->m11 + B->m11;
}


void cmlc_matrix2x2_sub(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B, CML_Matrix2x2 *out) {
    out->m00 = A->m00 - B->m00;
    out->m01 = A->m01 - B->m01;
    out->m10 = A->m10 - B->m10;
    out->m11 = A->m11 - B->m11;
}


void cmlc_matrix2x2_scale(const CML_Matrix2x2 *A, f32 t, CML_Matrix2x2 *out) {
    out->m00 = A->m00 * t;
    out->m01 = A->m01 * t;
    out->m10 = A->m10 * t;
    out->m11 = A->m11 * t;
}


void cmlc_matrix2x2_mult(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B, CML_Matrix2x2 *out) {
    f32 a00 = A->m00, a01 = A->m01, a10 = A->m10, a11 = A->m11;
    f32 b00 = B->m00, b01 = B->m01, b10 = B->m10, b11 = B->m11;

    out->m00 = a00*b00 + a01*b10;
    out->m01 = a00*b01 + a01*b11;
    out->m10 = a10*b00 + a11*b10;
    out->m11 = a10*b01 + a11*b11;
}


void cmlc_matrix2x2_mult_matrix2x3(const CML_Matrix2x2 *A, const CML_Matrix2x3 *B, CML_Matrix2x3 *out) {
    f32 a00 = A->m00, a01 = A->m01, a10 = A->m10, a11 = A->m11;
    f32 b00 = B->m00, b01 = B->m01, b02 = B->m02;
    f32 b10 = B->m10, b11 = B->m11, b12 = B->m12;

    out->m00 = a00*b00 + a01*b10;
    out->m01 = a00*b01 + a01*b11;
    out->m02 = a00*b02 + a01*b12;
    out->m10 = a10*b00 + a11*b10;
    out->m11 = a10*b01 + a11*b11;
    out->m12 = a10*b02 + a11*b12;
}


void cmlc_matrix2x2_mult_matrix2x4(const CML_Matrix2x2 *A, const CML_Matrix2x4 *B, CML_Matrix2x4 *out) {
    f32 a00 = A->m00, a01 = A->m01, a10 = A->m10, a11 = A->m11;
    f32 b00 = B->m00, b01 = B->m01, b02 = B->m02, b03 = B->m03;
    f32 b10 = B->m10, b11 = B->m11, b12 = B->m12, b13 = B->m13;

    out->m00 = a00*b00 + a01*b10;
    out->m01 = a00*b01 + a01*b11;
    out->m02 = a00*b02 + a01*b12;
    out->m03 = a00*b03 + a01*b13;
    out->m10 = a10*b00 + a11*b10;
    out->m11 = a10*b01 + a11*b11;
    out->m12 = a10*b02 + a11*b12;
    out->m13 = a10*b03 + a11*b13;
}


void cmlc_matrix2x2_mult_vector2(const CML_Matrix2x2 *A, const CML_Vector2 *v, CML_Vector2 *out) {
    f32 a00 = A->m00, a01 = A->m01, a10 = A->m10, a11 = A->m11;
    f32 v0 = v->x, v1 = v->y;

    out->x = a00*v0 + a01*v1;
    out->y = a10*v0 + a11*v1;
}


void cmlc_vector2_mult_matrix2x2(const CML_Vector2 *v, const CML_Matrix2x2 *A, CML_Vector2 *out) {
    f32 a00 = A->m00, a01 = A->m01, a10 = A->m10, a11 = A->m11;
    f32 v0 = v->x, v1 = v->y;

    out->x = a00*v0 + a10*v1;
    out->y = a01*v0 + a11*v1;
}


f32 cmlc_matrix2x2_det(const CML_Matrix2x2 *A) {
    f32 a00 = A->m00, a01 = A->m01, a10 = A->m10, a11 = A->m11;

    return a00*a11 - a01*a10;
}


CML_Status cmlc_matrix2x2_inv(const CML_Matrix2x2 *A, CML_Matrix2x2 *out) {
    f32 a00 = A->m00, a01 = A->m01, a10 = A->m10, a11 = A->m11;
    f32 det = (a00*a11 - a01*a10);

    if (det == 0.0f) {
        return CML_ERR_SINGULAR_MATRIX;
    }

    det = 1/det;

    out->m00 = a11*det;
    out->m01 = -a01*det;
    out->m10 = -a10*det;
    out->m11 = a00*det;

    return CML_SUCCESS;
}


void cmlc_matrix2x2_transpose(const CML_Matrix2x2 *A, CML_Matrix2x2 *out) {
    f32 a00 = A->m00, a01 = A->m01;
    f32 a10 = A->m10, a11 = A->m11;


    out->m00 = a00;
    out->m01 = a10;
    out->m10 = a01;
    out->m11 = a11;
}


f32 cmlc_matrix2x2_trace(const CML_Matrix2x2 *A) {
    return A->m00 + A->m11;
}


CML_Bool cmlc_matrix2x2_eq(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B) {
    if (!A || !B) {
        return CML_FALSE;
    }

    return (fabsf(A->m00 - B->m00) <= CML_EPSILON && fabsf(A->m01 - B->m01) <= CML_EPSILON && 
            fabsf(A->m10 - B->m10) <= CML_EPSILON && fabsf(A->m11 - B->m11) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}



char *cmlc_matrix2x2_debug(const CML_Matrix2x2 *expected, const CML_Matrix2x2 *got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    sprintf(debugMessage, "\t\tExpected:\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n", 
            expected->m00, expected->m01, 
            expected->m10, expected->m11, 
            got->m00, got->m01, 
            got->m10, got->m11);

    return debugMessage;
}



void cmlc_matrix3x3_add(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B, CML_Matrix3x3 *out) {
    out->m00 = A->m00 + B->m00;
    out->m01 = A->m01 + B->m01;
    out->m02 = A->m02 + B->m02;
    out->m10 = A->m10 + B->m10;
    out->m11 = A->m11 + B->m11;
    out->m12 = A->m12 + B->m12;
    out->m20 = A->m20 + B->m20;
    out->m21 = A->m21 + B->m21;
    out->m22 = A->m22 + B->m22;
}


void cmlc_matrix3x3_sub(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B, CML_Matrix3x3 *out) {
    out->m00 = A->m00 - B->m00;
    out->m01 = A->m01 - B->m01;
    out->m02 = A->m02 - B->m02;
    out->m10 = A->m10 - B->m10;
    out->m11 = A->m11 - B->m11;
    out->m12 = A->m12 - B->m12;
    out->m20 = A->m20 - B->m20;
    out->m21 = A->m21 - B->m21;
    out->m22 = A->m22 - B->m22;
}


void cmlc_matrix3x3_scale(const CML_Matrix3x3 *A, f32 t, CML_Matrix3x3 *out) {
    out->m00 = A->m00 * t;
    out->m01 = A->m01 * t;
    out->m02 = A->m02 * t;
    out->m10 = A->m10 * t;
    out->m11 = A->m11 * t;
    out->m12 = A->m12 * t;
    out->m20 = A->m20 * t;
    out->m21 = A->m21 * t;
    out->m22 = A->m22 * t;
}


void cmlc_matrix3x3_mult(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B, CML_Matrix3x3 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22;

    f32 b00 = B->m00, b01 = B->m01, b02 = B->m02;
    f32 b10 = B->m10, b11 = B->m11, b12 = B->m12;
    f32 b20 = B->m20, b21 = B->m21, b22 = B->m22;

    out->m00 = a00*b00 + a01*b10 + a02*b20;
    out->m01 = a00*b01 + a01*b11 + a02*b21;
    out->m02 = a00*b02 + a01*b12 + a02*b22;
    out->m10 = a10*b00 + a11*b10 + a12*b20;
    out->m11 = a10*b01 + a11*b11 + a12*b21;
    out->m12 = a10*b02 + a11*b12 + a12*b22;
    out->m20 = a20*b00 + a21*b10 + a22*b20;
    out->m21 = a20*b01 + a21*b11 + a22*b21;
    out->m22 = a20*b02 + a21*b12 + a22*b22;
}


void cmlc_matrix3x3_mult_matrix3x2(const CML_Matrix3x3 *A, const CML_Matrix3x2 *B, CML_Matrix3x2 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22;

    f32 b00 = B->m00, b01 = B->m01;
    f32 b10 = B->m10, b11 = B->m11;
    f32 b20 = B->m20, b21 = B->m21;

    out->m00 = a00*b00 + a01*b10 + a02*b20;
    out->m01 = a00*b01 + a01*b11 + a02*b21;
    out->m10 = a10*b00 + a11*b10 + a12*b20;
    out->m11 = a10*b01 + a11*b11 + a12*b21;
    out->m20 = a20*b00 + a21*b10 + a22*b20;
    out->m21 = a20*b01 + a21*b11 + a22*b21;
}


void cmlc_matrix3x3_mult_matrix3x4(const CML_Matrix3x3 *A, const CML_Matrix3x4 *B, CML_Matrix3x4 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22;

    f32 b00 = B->m00, b01 = B->m01, b02 = B->m02, b03 = B->m03;
    f32 b10 = B->m10, b11 = B->m11, b12 = B->m12, b13 = B->m13;
    f32 b20 = B->m20, b21 = B->m21, b22 = B->m22, b23 = B->m23;

    out->m00 = a00*b00 + a01*b10 + a02*b20;
    out->m01 = a00*b01 + a01*b11 + a02*b21;
    out->m02 = a00*b02 + a01*b12 + a02*b22;
    out->m03 = a00*b03 + a01*b13 + a02*b23;
    out->m10 = a10*b00 + a11*b10 + a12*b20;
    out->m11 = a10*b01 + a11*b11 + a12*b21;
    out->m12 = a10*b02 + a11*b12 + a12*b22;
    out->m13 = a10*b03 + a11*b13 + a12*b23;
    out->m20 = a20*b00 + a21*b10 + a22*b20;
    out->m21 = a20*b01 + a21*b11 + a22*b21;
    out->m22 = a20*b02 + a21*b12 + a22*b22;
    out->m23 = a20*b03 + a21*b13 + a22*b23;
}


void cmlc_matrix3x3_mult_vector3(const CML_Matrix3x3 *A, const CML_Vector3 *v, CML_Vector3 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22;

    f32 v0 = v->x, v1 = v->y, v2 = v->z;

    out->x = a00*v0 + a01*v1 + a02*v2;
    out->y = a10*v0 + a11*v1 + a12*v2;
    out->z = a20*v0 + a21*v1 + a22*v2;
}


void cmlc_vector3_mult_matrix3x3(const CML_Vector3 *v, const CML_Matrix3x3 *A, CML_Vector3 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22;

    f32 v0 = v->x, v1 = v->y, v2 = v->z;

    out->x = a00*v0 + a10*v1 + a20*v2;
    out->y = a01*v0 + a11*v1 + a21*v2;
    out->z = a02*v0 + a12*v1 + a22*v2;
}


f32 cmlc_matrix3x3_det(const CML_Matrix3x3 *A) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22;

    return a00*(a11*a22 - a12*a21) - a01*(a10*a22 - a12*a20) + a02*(a10*a21 - a11*a20);
}


CML_Status cmlc_matrix3x3_inv(const CML_Matrix3x3 *A, CML_Matrix3x3 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22;

    f32 det = a00*(a11*a22 - a12*a21) - a01*(a10*a22 - a12*a20) + a02*(a10*a21 - a11*a20);

    if (det == 0.0f) {
        return CML_ERR_SINGULAR_MATRIX;
    }

    det = 1/det;

    out->m00 = (a11*a22 - a12*a21)*det;
    out->m01 = -(a01*a22 - a02*a21)*det;
    out->m02 = (a01*a12 - a02*a11)*det;
    out->m10 = -(a10*a22 - a12*a20)*det;
    out->m11 = (a00*a22 - a02*a20)*det;
    out->m12 = -(a00*a12 - a02*a10)*det;
    out->m20 = (a10*a21 - a11*a20)*det;
    out->m21 = -(a00*a21 - a01*a20)*det;
    out->m22 = (a00*a11 - a01*a10)*det;

    return CML_SUCCESS;
}


void cmlc_matrix3x3_transpose(const CML_Matrix3x3 *A, CML_Matrix3x3 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22;

    out->m00 = a00;
    out->m01 = a10;
    out->m02 = a20;
    out->m10 = a01;
    out->m11 = a11;
    out->m12 = a21;
    out->m20 = a02;
    out->m21 = a12;
    out->m22 = a22;
}


f32 cmlc_matrix3x3_trace(const CML_Matrix3x3 *A) {
    return A->m00 + A->m11 + A->m22;
}


CML_Bool cmlc_matrix3x3_eq(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B) {
    if (!A || !B) {
        return CML_FALSE;
    }

    return (fabsf(A->m00 - B->m00) <= CML_EPSILON && fabsf(A->m01 - B->m01) <= CML_EPSILON && fabsf(A->m02 - B->m02) <= CML_EPSILON && 
            fabsf(A->m10 - B->m10) <= CML_EPSILON && fabsf(A->m11 - B->m11) <= CML_EPSILON && fabsf(A->m12 - B->m12) <= CML_EPSILON && 
            fabsf(A->m20 - B->m20) <= CML_EPSILON && fabsf(A->m21 - B->m21) <= CML_EPSILON && fabsf(A->m22 - B->m22) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cmlc_matrix3x3_debug(const CML_Matrix3x3 *expected, const CML_Matrix3x3 *got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    sprintf(debugMessage, "\t\tExpected:\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n", 
            expected->m00, expected->m01, expected->m02, 
            expected->m10, expected->m11, expected->m12, 
            expected->m20, expected->m21, expected->m22, 
            got->m00, got->m01, got->m02, 
            got->m10, got->m11, got->m12, 
            got->m20, got->m21, got->m22);

    return debugMessage;
}



void cmlc_matrix4x4_add(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B, CML_Matrix4x4 *out) {
    out->m00 = A->m00 + B->m00;
    out->m01 = A->m01 + B->m01;
    out->m02 = A->m02 + B->m02;
    out->m03 = A->m03 + B->m03;
    out->m10 = A->m10 + B->m10;
    out->m11 = A->m11 + B->m11;
    out->m12 = A->m12 + B->m12;
    out->m13 = A->m13 + B->m13;
    out->m20 = A->m20 + B->m20;
    out->m21 = A->m21 + B->m21;
    out->m22 = A->m22 + B->m22;
    out->m23 = A->m23 + B->m23;
    out->m30 = A->m30 + B->m30;
    out->m31 = A->m31 + B->m31;
    out->m32 = A->m32 + B->m32;
    out->m33 = A->m33 + B->m33;
}


void cmlc_matrix4x4_sub(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B, CML_Matrix4x4 *out) {
    out->m00 = A->m00 - B->m00;
    out->m01 = A->m01 - B->m01;
    out->m02 = A->m02 - B->m02;
    out->m03 = A->m03 - B->m03;
    out->m10 = A->m10 - B->m10;
    out->m11 = A->m11 - B->m11;
    out->m12 = A->m12 - B->m12;
    out->m13 = A->m13 - B->m13;
    out->m20 = A->m20 - B->m20;
    out->m21 = A->m21 - B->m21;
    out->m22 = A->m22 - B->m22;
    out->m23 = A->m23 - B->m23;
    out->m30 = A->m30 - B->m30;
    out->m31 = A->m31 - B->m31;
    out->m32 = A->m32 - B->m32;
    out->m33 = A->m33 - B->m33;
}


void cmlc_matrix4x4_scale(const CML_Matrix4x4 *A, f32 t, CML_Matrix4x4 *out) {
    out->m00 = A->m00 * t;
    out->m01 = A->m01 * t;
    out->m02 = A->m02 * t;
    out->m03 = A->m03 * t;
    out->m10 = A->m10 * t;
    out->m11 = A->m11 * t;
    out->m12 = A->m12 * t;
    out->m13 = A->m13 * t;
    out->m20 = A->m20 * t;
    out->m21 = A->m21 * t;
    out->m22 = A->m22 * t;
    out->m23 = A->m23 * t;
    out->m30 = A->m30 * t;
    out->m31 = A->m31 * t;
    out->m32 = A->m32 * t;
    out->m33 = A->m33 * t;
}


void cmlc_matrix4x4_mult(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B, CML_Matrix4x4 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22, a23 = A->m23;
    f32 a30 = A->m30, a31 = A->m31, a32 = A->m32, a33 = A->m33;

    f32 b00 = B->m00, b01 = B->m01, b02 = B->m02, b03 = B->m03;
    f32 b10 = B->m10, b11 = B->m11, b12 = B->m12, b13 = B->m13;
    f32 b20 = B->m20, b21 = B->m21, b22 = B->m22, b23 = B->m23;
    f32 b30 = B->m30, b31 = B->m31, b32 = B->m32, b33 = B->m33;

    out->m00 = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out->m01 = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out->m02 = a00*b02 + a01*b12 + a02*b22 + a03*b32;
    out->m03 = a00*b03 + a01*b13 + a02*b23 + a03*b33;
    out->m10 = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out->m11 = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out->m12 = a10*b02 + a11*b12 + a12*b22 + a13*b32;
    out->m13 = a10*b03 + a11*b13 + a12*b23 + a13*b33;
    out->m20 = a20*b00 + a21*b10 + a22*b20 + a23*b30;
    out->m21 = a20*b01 + a21*b11 + a22*b21 + a23*b31;
    out->m22 = a20*b02 + a21*b12 + a22*b22 + a23*b32;
    out->m23 = a20*b03 + a21*b13 + a22*b23 + a23*b33;
    out->m30 = a30*b00 + a31*b10 + a32*b20 + a33*b30;
    out->m31 = a30*b01 + a31*b11 + a32*b21 + a33*b31;
    out->m32 = a30*b02 + a31*b12 + a32*b22 + a33*b32;
    out->m33 = a30*b03 + a31*b13 + a32*b23 + a33*b33;
}


void cmlc_matrix4x4_mult_matrix4x2(const CML_Matrix4x4 *A, const CML_Matrix4x2 *B, CML_Matrix4x2 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22, a23 = A->m23;
    f32 a30 = A->m30, a31 = A->m31, a32 = A->m32, a33 = A->m33;

    f32 b00 = B->m00, b01 = B->m01;
    f32 b10 = B->m10, b11 = B->m11;
    f32 b20 = B->m20, b21 = B->m21;
    f32 b30 = B->m30, b31 = B->m31;

    out->m00 = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out->m01 = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out->m10 = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out->m11 = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out->m20 = a20*b00 + a21*b10 + a22*b20 + a23*b30;
    out->m21 = a20*b01 + a21*b11 + a22*b21 + a23*b31;
    out->m30 = a30*b00 + a31*b10 + a32*b20 + a33*b30;
    out->m31 = a30*b01 + a31*b11 + a32*b21 + a33*b31;
}


void cmlc_matrix4x4_mult_matrix4x3(const CML_Matrix4x4 *A, const CML_Matrix4x3 *B, CML_Matrix4x3 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22, a23 = A->m23;
    f32 a30 = A->m30, a31 = A->m31, a32 = A->m32, a33 = A->m33;

    f32 b00 = B->m00, b01 = B->m01, b02 = B->m02;
    f32 b10 = B->m10, b11 = B->m11, b12 = B->m12;
    f32 b20 = B->m20, b21 = B->m21, b22 = B->m22;
    f32 b30 = B->m30, b31 = B->m31, b32 = B->m32;

    out->m00 = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out->m01 = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out->m02 = a00*b02 + a01*b12 + a02*b22 + a03*b32;
    out->m10 = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out->m11 = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out->m12 = a10*b02 + a11*b12 + a12*b22 + a13*b32;
    out->m20 = a20*b00 + a21*b10 + a22*b20 + a23*b30;
    out->m21 = a20*b01 + a21*b11 + a22*b21 + a23*b31;
    out->m22 = a20*b02 + a21*b12 + a22*b22 + a23*b32;
    out->m30 = a30*b00 + a31*b10 + a32*b20 + a33*b30;
    out->m31 = a30*b01 + a31*b11 + a32*b21 + a33*b31;
    out->m32 = a30*b02 + a31*b12 + a32*b22 + a33*b32;
}


void cmlc_matrix4x4_mult_vector4(const CML_Matrix4x4 *A, const CML_Vector4 *v, CML_Vector4 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22, a23 = A->m23;
    f32 a30 = A->m30, a31 = A->m31, a32 = A->m32, a33 = A->m33;

    f32 v0 = v->x, v1 = v->y, v2 = v->z, v3 = v->w;

    out->x = a00*v0 + a01*v1 + a02*v2 + a03*v3;
    out->y = a10*v0 + a11*v1 + a12*v2 + a13*v3;
    out->z = a20*v0 + a21*v1 + a22*v2 + a23*v3;
    out->w = a30*v0 + a31*v1 + a32*v2 + a33*v3;
}


void cmlc_vector4_mult_matrix4x4(const CML_Vector4 *v, const CML_Matrix4x4 *A, CML_Vector4 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22, a23 = A->m23;
    f32 a30 = A->m30, a31 = A->m31, a32 = A->m32, a33 = A->m33;

    f32 v0 = v->x, v1 = v->y, v2 = v->z, v3 = v->w;

    out->x = a00*v0 + a10*v1 + a20*v2 + a30*v3;
    out->y = a01*v0 + a11*v1 + a21*v2 + a31*v3;
    out->z = a02*v0 + a12*v1 + a22*v2 + a32*v3;
    out->w = a03*v0 + a13*v1 + a23*v2 + a33*v3;
}


f32 cmlc_matrix4x4_det(const CML_Matrix4x4 *A) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22, a23 = A->m23;
    f32 a30 = A->m30, a31 = A->m31, a32 = A->m32, a33 = A->m33;

    return a03*a12*a21*a30 - a02*a13*a21*a30 - a03*a11*a22*a30 + a01*a13*a22*a30+
           a02*a11*a23*a30 - a01*a12*a23*a30 - a03*a12*a20*a31 + a02*a13*a20*a31+
           a03*a10*a22*a31 - a00*a13*a22*a31 - a02*a10*a23*a31 + a00*a12*a23*a31+
           a03*a11*a20*a32 - a01*a13*a20*a32 - a03*a10*a21*a32 + a00*a13*a21*a32+
           a01*a10*a23*a32 - a00*a11*a23*a32 - a02*a11*a20*a33 + a01*a12*a20*a33+
           a02*a10*a21*a33 - a00*a12*a21*a33 - a01*a10*a22*a33 + a00*a11*a22*a33;
}


CML_Status cmlc_matrix4x4_inv(const CML_Matrix4x4 *A, CML_Matrix4x4 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22, a23 = A->m23;
    f32 a30 = A->m30, a31 = A->m31, a32 = A->m32, a33 = A->m33;

    f32 det = a03*a12*a21*a30 - a02*a13*a21*a30 - a03*a11*a22*a30 + a01*a13*a22*a30+
              a02*a11*a23*a30 - a01*a12*a23*a30 - a03*a12*a20*a31 + a02*a13*a20*a31+
              a03*a10*a22*a31 - a00*a13*a22*a31 - a02*a10*a23*a31 + a00*a12*a23*a31+
              a03*a11*a20*a32 - a01*a13*a20*a32 - a03*a10*a21*a32 + a00*a13*a21*a32+
              a01*a10*a23*a32 - a00*a11*a23*a32 - a02*a11*a20*a33 + a01*a12*a20*a33+
              a02*a10*a21*a33 - a00*a12*a21*a33 - a01*a10*a22*a33 + a00*a11*a22*a33;

    if (det == 0.0f) {
        return CML_ERR_SINGULAR_MATRIX;
    }

    det = 1/det;

    out->m00 = (a12*a23*a31 - a13*a22*a31 + a13*a21*a32 - a11*a23*a32 - a12*a21*a33 + a11*a22*a33)*det;
    out->m01 = (a03*a22*a31 - a02*a23*a31 - a03*a21*a32 + a01*a23*a32 + a02*a21*a33 - a01*a22*a33)*det;
    out->m02 = (a02*a13*a31 - a03*a12*a31 + a03*a11*a32 - a01*a13*a32 - a02*a11*a33 + a01*a12*a33)*det;
    out->m03 = (a03*a12*a21 - a02*a13*a21 - a03*a11*a22 + a01*a13*a22 + a02*a11*a23 - a01*a12*a23)*det;
    out->m10 = (a13*a22*a30 - a12*a23*a30 - a13*a20*a32 + a10*a23*a32 + a12*a20*a33 - a10*a22*a33)*det;
    out->m11 = (a02*a23*a30 - a03*a22*a30 + a03*a20*a32 - a00*a23*a32 - a02*a20*a33 + a00*a22*a33)*det;
    out->m12 = (a03*a12*a30 - a02*a13*a30 - a03*a10*a32 + a00*a13*a32 + a02*a10*a33 - a00*a12*a33)*det;
    out->m13 = (a02*a13*a20 - a03*a12*a20 + a03*a10*a22 - a00*a13*a22 - a02*a10*a23 + a00*a12*a23)*det;
    out->m20 = (a11*a23*a30 - a13*a21*a30 + a13*a20*a31 - a10*a23*a31 - a11*a20*a33 + a10*a21*a33)*det;
    out->m21 = (a03*a21*a30 - a01*a23*a30 - a03*a20*a31 + a00*a23*a31 + a01*a20*a33 - a00*a21*a33)*det;
    out->m22 = (a01*a13*a30 - a03*a11*a30 + a03*a10*a31 - a00*a13*a31 - a01*a10*a33 + a00*a11*a33)*det;
    out->m23 = (a03*a11*a20 - a01*a13*a20 - a03*a10*a21 + a00*a13*a21 + a01*a10*a23 - a00*a11*a23)*det;
    out->m30 = (a12*a21*a30 - a11*a22*a30 - a12*a20*a31 + a10*a22*a31 + a11*a20*a32 - a10*a21*a32)*det;
    out->m31 = (a01*a22*a30 - a02*a21*a30 + a02*a20*a31 - a00*a22*a31 - a01*a20*a32 + a00*a21*a32)*det;
    out->m32 = (a02*a11*a30 - a01*a12*a30 - a02*a10*a31 + a00*a12*a31 + a01*a10*a32 - a00*a11*a32)*det;
    out->m33 = (a01*a12*a20 - a02*a11*a20 + a02*a10*a21 - a00*a12*a21 - a01*a10*a22 + a00*a11*a22)*det;

    return CML_SUCCESS;
}


void cmlc_matrix4x4_transpose(const CML_Matrix4x4 *A, CML_Matrix4x4 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22, a23 = A->m23;
    f32 a30 = A->m30, a31 = A->m31, a32 = A->m32, a33 = A->m33;

    out->m00 = a00;
    out->m01 = a10;
    out->m02 = a20;
    out->m03 = a30;
    out->m10 = a01;
    out->m11 = a11;
    out->m12 = a21;
    out->m13 = a31;
    out->m20 = a02;
    out->m21 = a12;
    out->m22 = a22;
    out->m23 = a32;
    out->m30 = a03;
    out->m31 = a13;
    out->m32 = a23;
    out->m33 = a33;
}


f32 cmlc_matrix4x4_trace(const CML_Matrix4x4 *A) {
    return A->m00 + A->m11 + A->m22 + A->m33;
}


CML_Bool cmlc_matrix4x4_eq(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B) {
    if (!A || !B) {
        return CML_FALSE;
    }

    return (fabsf(A->m00 - B->m00) <= CML_EPSILON && fabsf(A->m01 - B->m01) <= CML_EPSILON && 
            fabsf(A->m02 - B->m02) <= CML_EPSILON && fabsf(A->m03 - B->m03) <= CML_EPSILON && 
            fabsf(A->m10 - B->m10) <= CML_EPSILON && fabsf(A->m11 - B->m11) <= CML_EPSILON && 
            fabsf(A->m12 - B->m12) <= CML_EPSILON && fabsf(A->m13 - B->m13) <= CML_EPSILON && 
            fabsf(A->m20 - B->m20) <= CML_EPSILON && fabsf(A->m21 - B->m21) <= CML_EPSILON && 
            fabsf(A->m22 - B->m22) <= CML_EPSILON && fabsf(A->m23 - B->m23) <= CML_EPSILON && 
            fabsf(A->m30 - B->m30) <= CML_EPSILON && fabsf(A->m31 - B->m31) <= CML_EPSILON && 
            fabsf(A->m32 - B->m32) <= CML_EPSILON && fabsf(A->m33 - B->m33) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cmlc_matrix4x4_debug(const CML_Matrix4x4 *expected, const CML_Matrix4x4 *got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    sprintf(debugMessage, "\t\tExpected:\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n", 
            expected->m00, expected->m01, expected->m02, expected->m03, 
            expected->m10, expected->m11, expected->m12, expected->m13, 
            expected->m20, expected->m21, expected->m22, expected->m23, 
            expected->m30, expected->m31, expected->m32, expected->m33, 
            got->m00, got->m01, got->m02, got->m03, 
            got->m10, got->m11, got->m12, got->m13, 
            got->m20, got->m21, got->m22, got->m23, 
            got->m30, got->m31, got->m32, got->m33);

    return debugMessage;
}



void cmlc_matrix2x3_add(const CML_Matrix2x3 *A, const CML_Matrix2x3 *B, CML_Matrix2x3 *out) {
    out->m00 = A->m00 + B->m00;
    out->m01 = A->m01 + B->m01;
    out->m02 = A->m02 + B->m02;
    out->m10 = A->m10 + B->m10;
    out->m11 = A->m11 + B->m11;
    out->m12 = A->m12 + B->m12;
}


void cmlc_matrix2x3_sub(const CML_Matrix2x3 *A, const CML_Matrix2x3 *B, CML_Matrix2x3 *out) {
    out->m00 = A->m00 - B->m00;
    out->m01 = A->m01 - B->m01;
    out->m02 = A->m02 - B->m02;
    out->m10 = A->m10 - B->m10;
    out->m11 = A->m11 - B->m11;
    out->m12 = A->m12 - B->m12;
}


void cmlc_matrix2x3_scale(const CML_Matrix2x3 *A, f32 t, CML_Matrix2x3 *out) {
    out->m00 = A->m00 * t;
    out->m01 = A->m01 * t;
    out->m02 = A->m02 * t;
    out->m10 = A->m10 * t;
    out->m11 = A->m11 * t;
    out->m12 = A->m12 * t;
}


void cmlc_matrix2x3_mult_matrix3x2(const CML_Matrix2x3 *A, const CML_Matrix3x2 *B, CML_Matrix2x2 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;

    f32 b00 = B->m00, b01 = B->m01;
    f32 b10 = B->m10, b11 = B->m11;
    f32 b20 = B->m20, b21 = B->m21;

    out->m00 = a00*b00 + a01*b10 + a02*b20;
    out->m01 = a00*b01 + a01*b11 + a02*b21;
    out->m10 = a10*b00 + a11*b10 + a12*b20;
    out->m11 = a10*b01 + a11*b11 + a12*b21;
}


void cmlc_matrix2x3_mult_matrix3x3(const CML_Matrix2x3 *A, const CML_Matrix3x3 *B, CML_Matrix2x3 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;

    f32 b00 = B->m00, b01 = B->m01, b02 = B->m02;
    f32 b10 = B->m10, b11 = B->m11, b12 = B->m12;
    f32 b20 = B->m20, b21 = B->m21, b22 = B->m22;

    out->m00 = a00*b00 + a01*b10 + a02*b20;
    out->m01 = a00*b01 + a01*b11 + a02*b21;
    out->m02 = a00*b02 + a01*b12 + a02*b22;
    out->m10 = a10*b00 + a11*b10 + a12*b20;
    out->m11 = a10*b01 + a11*b11 + a12*b21;
    out->m12 = a10*b02 + a11*b12 + a12*b22;
}


void cmlc_matrix2x3_mult_matrix3x4(const CML_Matrix2x3 *A, const CML_Matrix3x4 *B, CML_Matrix2x4 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;

    f32 b00 = B->m00, b01 = B->m01, b02 = B->m02, b03 = B->m03;
    f32 b10 = B->m10, b11 = B->m11, b12 = B->m12, b13 = B->m13;
    f32 b20 = B->m20, b21 = B->m21, b22 = B->m22, b23 = B->m23;

    out->m00 = a00*b00 + a01*b10 + a02*b20;
    out->m01 = a00*b01 + a01*b11 + a02*b21;
    out->m02 = a00*b02 + a01*b12 + a02*b22;
    out->m03 = a00*b03 + a01*b13 + a02*b23;
    out->m10 = a10*b00 + a11*b10 + a12*b20;
    out->m11 = a10*b01 + a11*b11 + a12*b21;
    out->m12 = a10*b02 + a11*b12 + a12*b22;
    out->m13 = a10*b03 + a11*b13 + a12*b23;
}


void cmlc_matrix2x3_mult_vector3(const CML_Matrix2x3 *A, const CML_Vector3 *v, CML_Vector2 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;

    f32 v0 = v->x, v1 = v->y, v2 = v->z;

    out->x = a00*v0 + a01*v1 + a02*v2;
    out->y = a10*v0 + a11*v1 + a12*v2;
}


void cmlc_vector2_mult_matrix2x3(const CML_Vector2 *v, const CML_Matrix2x3 *A, CML_Vector3 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;

    f32 v0 = v->x, v1 = v->y;

    out->x = a00*v0 + a10*v1;
    out->y = a01*v0 + a11*v1;
    out->z = a02*v0 + a12*v1;
}


void cmlc_matrix2x3_transpose(const CML_Matrix2x3 *A, CML_Matrix3x2 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;

    out->m00 = a00;
    out->m01 = a10;
    out->m10 = a01;
    out->m11 = a11;
    out->m20 = a02;
    out->m21 = a12;
}


CML_Bool cmlc_matrix2x3_eq(const CML_Matrix2x3 *A, const CML_Matrix2x3 *B) {
    if (!A || !B) {
        return CML_FALSE;
    }

    return (fabsf(A->m00 - B->m00) <= CML_EPSILON && fabsf(A->m01 - B->m01) <= CML_EPSILON && 
            fabsf(A->m02 - B->m02) <= CML_EPSILON && fabsf(A->m10 - B->m10) <= CML_EPSILON && 
            fabsf(A->m11 - B->m11) <= CML_EPSILON && fabsf(A->m12 - B->m12) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cmlc_matrix2x3_debug(const CML_Matrix2x3 *expected, const CML_Matrix2x3 *got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    sprintf(debugMessage, "\t\tExpected:\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n", 
            expected->m00, expected->m01, expected->m02, 
            expected->m10, expected->m11, expected->m12, 
            got->m00, got->m01, got->m02, 
            got->m10, got->m11, got->m12);

    return debugMessage;
}



void cmlc_matrix2x4_add(const CML_Matrix2x4 *A, const CML_Matrix2x4 *B, CML_Matrix2x4 *out) {
    out->m00 = A->m00 + B->m00;
    out->m01 = A->m01 + B->m01;
    out->m02 = A->m02 + B->m02;
    out->m03 = A->m03 + B->m03;
    out->m10 = A->m10 + B->m10;
    out->m11 = A->m11 + B->m11;
    out->m12 = A->m12 + B->m12;
    out->m13 = A->m13 + B->m13;
}


void cmlc_matrix2x4_sub(const CML_Matrix2x4 *A, const CML_Matrix2x4 *B, CML_Matrix2x4 *out) {
    out->m00 = A->m00 - B->m00;
    out->m01 = A->m01 - B->m01;
    out->m02 = A->m02 - B->m02;
    out->m03 = A->m03 - B->m03;
    out->m10 = A->m10 - B->m10;
    out->m11 = A->m11 - B->m11;
    out->m12 = A->m12 - B->m12;
    out->m13 = A->m13 - B->m13;
}


void cmlc_matrix2x4_scale(const CML_Matrix2x4 *A, f32 t, CML_Matrix2x4 *out) {
    out->m00 = A->m00 * t;
    out->m01 = A->m01 * t;
    out->m02 = A->m02 * t;
    out->m03 = A->m03 * t;
    out->m10 = A->m10 * t;
    out->m11 = A->m11 * t;
    out->m12 = A->m12 * t;
    out->m13 = A->m13 * t;
}


void cmlc_matrix2x4_mult_matrix4x2(const CML_Matrix2x4 *A, const CML_Matrix4x2 *B, CML_Matrix2x2 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;

    f32 b00 = B->m00, b01 = B->m01;
    f32 b10 = B->m10, b11 = B->m11;
    f32 b20 = B->m20, b21 = B->m21;
    f32 b30 = B->m30, b31 = B->m31;

    out->m00 = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out->m01 = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out->m10 = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out->m11 = a10*b01 + a11*b11 + a12*b21 + a13*b31;
}


void cmlc_matrix2x4_mult_matrix4x3(const CML_Matrix2x4 *A, const CML_Matrix4x3 *B, CML_Matrix2x3 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;

    f32 b00 = B->m00, b01 = B->m01, b02 = B->m02;
    f32 b10 = B->m10, b11 = B->m11, b12 = B->m12;
    f32 b20 = B->m20, b21 = B->m21, b22 = B->m22;
    f32 b30 = B->m30, b31 = B->m31, b32 = B->m32;

    out->m00 = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out->m01 = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out->m02 = a00*b02 + a01*b12 + a02*b22 + a03*b32;
    out->m10 = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out->m11 = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out->m12 = a10*b02 + a11*b12 + a12*b22 + a13*b32;
}


void cmlc_matrix2x4_mult_matrix4x4(const CML_Matrix2x4 *A, const CML_Matrix4x4 *B, CML_Matrix2x4 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;

    f32 b00 = B->m00, b01 = B->m01, b02 = B->m02, b03 = B->m03;
    f32 b10 = B->m10, b11 = B->m11, b12 = B->m12, b13 = B->m13;
    f32 b20 = B->m20, b21 = B->m21, b22 = B->m22, b23 = B->m23;
    f32 b30 = B->m30, b31 = B->m31, b32 = B->m32, b33 = B->m33;

    out->m00 = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out->m01 = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out->m02 = a00*b02 + a01*b12 + a02*b22 + a03*b32;
    out->m03 = a00*b03 + a01*b13 + a02*b23 + a03*b33;
    out->m10 = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out->m11 = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out->m12 = a10*b02 + a11*b12 + a12*b22 + a13*b32;
    out->m13 = a10*b03 + a11*b13 + a12*b23 + a13*b33;
}


void cmlc_matrix2x4_mult_vector4(const CML_Matrix2x4 *A, const CML_Vector4 *v, CML_Vector2 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;

    f32 v0 = v->x, v1 = v->y, v2 = v->z, v3 = v->w;

    out->x = a00*v0 + a01*v1 + a02*v2 + a03*v3;
    out->y = a10*v0 + a11*v1 + a12*v2 + a13*v3;
}


void cmlc_vector2_mult_matrix2x4(const CML_Vector2 *v, const CML_Matrix2x4 *A, CML_Vector4 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;

    f32 v0 = v->x, v1 = v->y;

    out->x = a00*v0 + a10*v1;
    out->y = a01*v0 + a11*v1;
    out->z = a02*v0 + a12*v1;
    out->w = a03*v0 + a13*v1;
}


void cmlc_matrix2x4_transpose(const CML_Matrix2x4 *A, CML_Matrix4x2 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;

    out->m00 = a00;
    out->m01 = a10;
    out->m10 = a01;
    out->m11 = a11;
    out->m20 = a02;
    out->m21 = a12;
    out->m30 = a03;
    out->m31 = a13;
}


CML_Bool cmlc_matrix2x4_eq(const CML_Matrix2x4 *A, const CML_Matrix2x4 *B) {
    if (!A || !B) {
        return CML_FALSE;
    }

    return (fabsf(A->m00 - B->m00) <= CML_EPSILON && fabsf(A->m01 - B->m01) <= CML_EPSILON && 
            fabsf(A->m02 - B->m02) <= CML_EPSILON && fabsf(A->m03 - B->m03) <= CML_EPSILON && 
            fabsf(A->m10 - B->m10) <= CML_EPSILON && fabsf(A->m11 - B->m11) <= CML_EPSILON && 
            fabsf(A->m12 - B->m12) <= CML_EPSILON && fabsf(A->m13 - B->m13) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cmlc_matrix2x4_debug(const CML_Matrix2x4 *expected, const CML_Matrix2x4 *got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    sprintf(debugMessage, "\t\tExpected:\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n", 
            expected->m00, expected->m01, expected->m02, expected->m03, 
            expected->m10, expected->m11, expected->m12, expected->m13, 
            got->m00, got->m01, got->m02, got->m03, 
            got->m10, got->m11, got->m12, got->m13);

    return debugMessage;
}



void cmlc_matrix3x2_add(const CML_Matrix3x2 *A, const CML_Matrix3x2 *B, CML_Matrix3x2 *out) {
    out->m00 = A->m00 + B->m00;
    out->m01 = A->m01 + B->m01;
    out->m10 = A->m10 + B->m10;
    out->m11 = A->m11 + B->m11;
    out->m20 = A->m20 + B->m20;
    out->m21 = A->m21 + B->m21;
}


void cmlc_matrix3x2_sub(const CML_Matrix3x2 *A, const CML_Matrix3x2 *B, CML_Matrix3x2 *out) {
    out->m00 = A->m00 - B->m00;
    out->m01 = A->m01 - B->m01;
    out->m10 = A->m10 - B->m10;
    out->m11 = A->m11 - B->m11;
    out->m20 = A->m20 - B->m20;
    out->m21 = A->m21 - B->m21;
}


void cmlc_matrix3x2_scale(const CML_Matrix3x2 *A, f32 t, CML_Matrix3x2 *out) {
    out->m00 = A->m00 * t;
    out->m01 = A->m01 * t;
    out->m10 = A->m10 * t;
    out->m11 = A->m11 * t;
    out->m20 = A->m20 * t;
    out->m21 = A->m21 * t;
}


void cmlc_matrix3x2_mult_matrix2x2(const CML_Matrix3x2 *A, const CML_Matrix2x2 *B, CML_Matrix3x2 *out) {
    f32 a00 = A->m00, a01 = A->m01;
    f32 a10 = A->m10, a11 = A->m11;
    f32 a20 = A->m20, a21 = A->m21;

    f32 b00 = B->m00, b01 = B->m01;
    f32 b10 = B->m10, b11 = B->m11;

    out->m00 = a00*b00 + a01*b10;
    out->m01 = a00*b01 + a01*b11;
    out->m10 = a10*b00 + a11*b10;
    out->m11 = a10*b01 + a11*b11;
    out->m20 = a20*b00 + a21*b10;
    out->m21 = a20*b01 + a21*b11;
}


void cmlc_matrix3x2_mult_matrix2x3(const CML_Matrix3x2 *A, const CML_Matrix2x3 *B, CML_Matrix3x3 *out) {
    f32 a00 = A->m00, a01 = A->m01;
    f32 a10 = A->m10, a11 = A->m11;
    f32 a20 = A->m20, a21 = A->m21;

    f32 b00 = B->m00, b01 = B->m01, b02 = B->m02;
    f32 b10 = B->m10, b11 = B->m11, b12 = B->m12;

    out->m00 = a00*b00 + a01*b10;
    out->m01 = a00*b01 + a01*b11;
    out->m02 = a00*b02 + a01*b12;
    out->m10 = a10*b00 + a11*b10;
    out->m11 = a10*b01 + a11*b11;
    out->m12 = a10*b02 + a11*b12;
    out->m20 = a20*b00 + a21*b10;
    out->m21 = a20*b01 + a21*b11;
    out->m22 = a20*b02 + a21*b12;
}


void cmlc_matrix3x2_mult_matrix2x4(const CML_Matrix3x2 *A, const CML_Matrix2x4 *B, CML_Matrix3x4 *out) {
    f32 a00 = A->m00, a01 = A->m01;
    f32 a10 = A->m10, a11 = A->m11;
    f32 a20 = A->m20, a21 = A->m21;

    f32 b00 = B->m00, b01 = B->m01, b02 = B->m02, b03 = B->m03;
    f32 b10 = B->m10, b11 = B->m11, b12 = B->m12, b13 = B->m13;

    out->m00 = a00*b00 + a01*b10;
    out->m01 = a00*b01 + a01*b11;
    out->m02 = a00*b02 + a01*b12;
    out->m03 = a00*b03 + a01*b13;
    out->m10 = a10*b00 + a11*b10;
    out->m11 = a10*b01 + a11*b11;
    out->m12 = a10*b02 + a11*b12;
    out->m13 = a10*b03 + a11*b13;
    out->m20 = a20*b00 + a21*b10;
    out->m21 = a20*b01 + a21*b11;
    out->m22 = a20*b02 + a21*b12;
    out->m23 = a20*b03 + a21*b13;
}


void cmlc_matrix3x2_mult_vector2(const CML_Matrix3x2 *A, const CML_Vector2 *v, CML_Vector3 *out) {
    f32 a00 = A->m00, a01 = A->m01;
    f32 a10 = A->m10, a11 = A->m11;
    f32 a20 = A->m20, a21 = A->m21;

    f32 v0 = v->x, v1 = v->y;

    out->x = a00*v0 + a01*v1;
    out->y = a10*v0 + a11*v1;
    out->z = a20*v0 + a21*v1;
}


void cmlc_vector3_mult_matrix3x2(const CML_Vector3 *v, const CML_Matrix3x2 *A, CML_Vector2 *out) {
    f32 a00 = A->m00, a01 = A->m01;
    f32 a10 = A->m10, a11 = A->m11;
    f32 a20 = A->m20, a21 = A->m21;

    f32 v0 = v->x, v1 = v->y, v2 = v->z;

    out->x = a00*v0 + a10*v1 + a20*v2;
    out->y = a01*v0 + a11*v1 + a21*v2;
}


void cmlc_matrix3x2_transpose(const CML_Matrix3x2 *A, CML_Matrix2x3 *out) {
    f32 a00 = A->m00, a01 = A->m01;
    f32 a10 = A->m10, a11 = A->m11;
    f32 a20 = A->m20, a21 = A->m21;

    out->m00 = a00;
    out->m01 = a10;
    out->m02 = a20;
    out->m10 = a01;
    out->m11 = a11;
    out->m12 = a21;
}


CML_Bool cmlc_matrix3x2_eq(const CML_Matrix3x2 *A, const CML_Matrix3x2 *B) {
    if (!A || !B) {
        return CML_FALSE;
    }

    return (fabsf(A->m00 - B->m00) <= CML_EPSILON && fabsf(A->m01 - B->m01) <= CML_EPSILON && 
            fabsf(A->m10 - B->m10) <= CML_EPSILON && fabsf(A->m11 - B->m11) <= CML_EPSILON && 
            fabsf(A->m20 - B->m20) <= CML_EPSILON && fabsf(A->m21 - B->m21) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cmlc_matrix3x2_debug(const CML_Matrix3x2 *expected, const CML_Matrix3x2 *got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    sprintf(debugMessage, "\t\tExpected:\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n", 
            expected->m00, expected->m01, 
            expected->m10, expected->m11, 
            expected->m20, expected->m21, 
            got->m00, got->m01, 
            got->m10, got->m11, 
            got->m20, got->m21);

    return debugMessage;
}



void cmlc_matrix3x4_add(const CML_Matrix3x4 *A, const CML_Matrix3x4 *B, CML_Matrix3x4 *out) {
    out->m00 = A->m00 + B->m00;
    out->m01 = A->m01 + B->m01;
    out->m02 = A->m02 + B->m02;
    out->m03 = A->m03 + B->m03;
    out->m10 = A->m10 + B->m10;
    out->m11 = A->m11 + B->m11;
    out->m12 = A->m12 + B->m12;
    out->m13 = A->m13 + B->m13;
    out->m20 = A->m20 + B->m20;
    out->m21 = A->m21 + B->m21;
    out->m22 = A->m22 + B->m22;
    out->m23 = A->m23 + B->m23;
}


void cmlc_matrix3x4_sub(const CML_Matrix3x4 *A, const CML_Matrix3x4 *B, CML_Matrix3x4 *out) {
    out->m00 = A->m00 - B->m00;
    out->m01 = A->m01 - B->m01;
    out->m02 = A->m02 - B->m02;
    out->m03 = A->m03 - B->m03;
    out->m10 = A->m10 - B->m10;
    out->m11 = A->m11 - B->m11;
    out->m12 = A->m12 - B->m12;
    out->m13 = A->m13 - B->m13;
    out->m20 = A->m20 - B->m20;
    out->m21 = A->m21 - B->m21;
    out->m22 = A->m22 - B->m22;
    out->m23 = A->m23 - B->m23;
}


void cmlc_matrix3x4_scale(const CML_Matrix3x4 *A, f32 t, CML_Matrix3x4 *out) {
    out->m00 = A->m00 * t;
    out->m01 = A->m01 * t;
    out->m02 = A->m02 * t;
    out->m03 = A->m03 * t;
    out->m10 = A->m10 * t;
    out->m11 = A->m11 * t;
    out->m12 = A->m12 * t;
    out->m13 = A->m13 * t;
    out->m20 = A->m20 * t;
    out->m21 = A->m21 * t;
    out->m22 = A->m22 * t;
    out->m23 = A->m23 * t;
}


void cmlc_matrix3x4_mult_matrix4x2(const CML_Matrix3x4 *A, const CML_Matrix4x2 *B, CML_Matrix3x2 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22, a23 = A->m23;

    f32 b00 = B->m00, b01 = B->m01;
    f32 b10 = B->m10, b11 = B->m11;
    f32 b20 = B->m20, b21 = B->m21;
    f32 b30 = B->m30, b31 = B->m31;

    out->m00 = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out->m01 = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out->m10 = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out->m11 = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out->m20 = a20*b00 + a21*b10 + a22*b20 + a23*b30;
    out->m21 = a20*b01 + a21*b11 + a22*b21 + a23*b31;
}


void cmlc_matrix3x4_mult_matrix4x3(const CML_Matrix3x4 *A, const CML_Matrix4x3 *B, CML_Matrix3x3 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22, a23 = A->m23;

    f32 b00 = B->m00, b01 = B->m01, b02 = B->m02;
    f32 b10 = B->m10, b11 = B->m11, b12 = B->m12;
    f32 b20 = B->m20, b21 = B->m21, b22 = B->m22;
    f32 b30 = B->m30, b31 = B->m31, b32 = B->m32;

    out->m00 = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out->m01 = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out->m02 = a00*b02 + a01*b12 + a02*b22 + a03*b32;
    out->m10 = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out->m11 = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out->m12 = a10*b02 + a11*b12 + a12*b22 + a13*b32;
    out->m20 = a20*b00 + a21*b10 + a22*b20 + a23*b30;
    out->m21 = a20*b01 + a21*b11 + a22*b21 + a23*b31;
    out->m22 = a20*b02 + a21*b12 + a22*b22 + a23*b32;
}


void cmlc_matrix3x4_mult_matrix4x4(const CML_Matrix3x4 *A, const CML_Matrix4x4 *B, CML_Matrix3x4 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22, a23 = A->m23;

    f32 b00 = B->m00, b01 = B->m01, b02 = B->m02, b03 = B->m03;
    f32 b10 = B->m10, b11 = B->m11, b12 = B->m12, b13 = B->m13;
    f32 b20 = B->m20, b21 = B->m21, b22 = B->m22, b23 = B->m23;
    f32 b30 = B->m30, b31 = B->m31, b32 = B->m32, b33 = B->m33;

    out->m00 = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out->m01 = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out->m02 = a00*b02 + a01*b12 + a02*b22 + a03*b32;
    out->m03 = a00*b03 + a01*b13 + a02*b23 + a03*b33;
    out->m10 = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out->m11 = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out->m12 = a10*b02 + a11*b12 + a12*b22 + a13*b32;
    out->m13 = a10*b03 + a11*b13 + a12*b23 + a13*b33;
    out->m20 = a20*b00 + a21*b10 + a22*b20 + a23*b30;
    out->m21 = a20*b01 + a21*b11 + a22*b21 + a23*b31;
    out->m22 = a20*b02 + a21*b12 + a22*b22 + a23*b32;
    out->m23 = a20*b03 + a21*b13 + a22*b23 + a23*b33;
}


void cmlc_matrix3x4_mult_vector4(const CML_Matrix3x4 *A, const CML_Vector4 *v, CML_Vector3 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22, a23 = A->m23;

    f32 v0 = v->x, v1 = v->y, v2 = v->z, v3 = v->w;

    out->x = a00*v0 + a01*v1 + a02*v2 + a03*v3;
    out->y = a10*v0 + a11*v1 + a12*v2 + a13*v3;
    out->z = a20*v0 + a21*v1 + a22*v2 + a23*v3;
}


void cmlc_vector3_mult_matrix3x4(const CML_Vector3 *v, const CML_Matrix3x4 *A, CML_Vector4 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22, a23 = A->m23;

    f32 v0 = v->x, v1 = v->y, v2 = v->z;

    out->x = a00*v0 + a10*v1 + a20*v2;
    out->y = a01*v0 + a11*v1 + a21*v2;
    out->z = a02*v0 + a12*v1 + a22*v2;
    out->w = a03*v0 + a13*v1 + a23*v2;
}


void cmlc_matrix3x4_transpose(const CML_Matrix3x4 *A, CML_Matrix4x3 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02, a03 = A->m03;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12, a13 = A->m13;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22, a23 = A->m23;

    out->m00 = a00;
    out->m01 = a10;
    out->m02 = a20;
    out->m10 = a01;
    out->m11 = a11;
    out->m12 = a21;
    out->m20 = a02;
    out->m21 = a12;
    out->m22 = a22;
    out->m30 = a03;
    out->m31 = a13;
    out->m32 = a23;
}


CML_Bool cmlc_matrix3x4_eq(const CML_Matrix3x4 *A, const CML_Matrix3x4 *B) {
    if (!A || !B) {
        return CML_FALSE;
    }

    return (fabsf(A->m00 - B->m00) <= CML_EPSILON && fabsf(A->m01 - B->m01) <= CML_EPSILON && 
            fabsf(A->m02 - B->m02) <= CML_EPSILON && fabsf(A->m03 - B->m03) <= CML_EPSILON && 
            fabsf(A->m10 - B->m10) <= CML_EPSILON && fabsf(A->m11 - B->m11) <= CML_EPSILON && 
            fabsf(A->m12 - B->m12) <= CML_EPSILON && fabsf(A->m13 - B->m13) <= CML_EPSILON && 
            fabsf(A->m20 - B->m20) <= CML_EPSILON && fabsf(A->m21 - B->m21) <= CML_EPSILON && 
            fabsf(A->m22 - B->m22) <= CML_EPSILON && fabsf(A->m23 - B->m23) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cmlc_matrix3x4_debug(const CML_Matrix3x4 *expected, const CML_Matrix3x4 *got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    sprintf(debugMessage, "\t\tExpected:\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf, %lf]\n", 
            expected->m00, expected->m01, expected->m02, expected->m03, 
            expected->m10, expected->m11, expected->m12, expected->m13, 
            expected->m20, expected->m21, expected->m22, expected->m23, 
            got->m00, got->m01, got->m02, got->m03, 
            got->m10, got->m11, got->m12, got->m13, 
            got->m20, got->m21, got->m22, got->m23);

    return debugMessage;
}



void cmlc_matrix4x2_add(const CML_Matrix4x2 *A, const CML_Matrix4x2 *B, CML_Matrix4x2 *out) {
    out->m00 = A->m00 + B->m00;
    out->m01 = A->m01 + B->m01;
    out->m10 = A->m10 + B->m10;
    out->m11 = A->m11 + B->m11;
    out->m20 = A->m20 + B->m20;
    out->m21 = A->m21 + B->m21;
    out->m30 = A->m30 + B->m30;
    out->m31 = A->m31 + B->m31;
}


void cmlc_matrix4x2_sub(const CML_Matrix4x2 *A, const CML_Matrix4x2 *B, CML_Matrix4x2 *out) {
    out->m00 = A->m00 - B->m00;
    out->m01 = A->m01 - B->m01;
    out->m10 = A->m10 - B->m10;
    out->m11 = A->m11 - B->m11;
    out->m20 = A->m20 - B->m20;
    out->m21 = A->m21 - B->m21;
    out->m30 = A->m30 - B->m30;
    out->m31 = A->m31 - B->m31;
}


void cmlc_matrix4x2_scale(const CML_Matrix4x2 *A, f32 t, CML_Matrix4x2 *out) {
    out->m00 = A->m00 * t;
    out->m01 = A->m01 * t;
    out->m10 = A->m10 * t;
    out->m11 = A->m11 * t;
    out->m20 = A->m20 * t;
    out->m21 = A->m21 * t;
    out->m30 = A->m30 * t;
    out->m31 = A->m31 * t;
}


void cmlc_matrix4x2_mult_matrix2x2(const CML_Matrix4x2 *A, const CML_Matrix2x2 *B, CML_Matrix4x2 *out) {
    f32 a00 = A->m00, a01 = A->m01;
    f32 a10 = A->m10, a11 = A->m11;
    f32 a20 = A->m20, a21 = A->m21;
    f32 a30 = A->m30, a31 = A->m31;

    f32 b00 = B->m00, b01 = B->m01;
    f32 b10 = B->m10, b11 = B->m11;

    out->m00 = a00*b00 + a01*b10;
    out->m01 = a00*b01 + a01*b11;
    out->m10 = a10*b00 + a11*b10;
    out->m11 = a10*b01 + a11*b11;
    out->m20 = a20*b00 + a21*b10;
    out->m21 = a20*b01 + a21*b11;
    out->m30 = a30*b00 + a31*b10;
    out->m31 = a30*b01 + a31*b11;
}


void cmlc_matrix4x2_mult_matrix2x3(const CML_Matrix4x2 *A, const CML_Matrix2x3 *B, CML_Matrix4x3 *out) {
    f32 a00 = A->m00, a01 = A->m01;
    f32 a10 = A->m10, a11 = A->m11;
    f32 a20 = A->m20, a21 = A->m21;
    f32 a30 = A->m30, a31 = A->m31;

    f32 b00 = B->m00, b01 = B->m01, b02 = B->m02;
    f32 b10 = B->m10, b11 = B->m11, b12 = B->m12;

    out->m00 = a00*b00 + a01*b10;
    out->m01 = a00*b01 + a01*b11;
    out->m02 = a00*b02 + a01*b12;
    out->m10 = a10*b00 + a11*b10;
    out->m11 = a10*b01 + a11*b11;
    out->m12 = a10*b02 + a11*b12;
    out->m20 = a20*b00 + a21*b10;
    out->m21 = a20*b01 + a21*b11;
    out->m22 = a20*b02 + a21*b12;
    out->m30 = a30*b00 + a31*b10;
    out->m31 = a30*b01 + a31*b11;
    out->m32 = a30*b02 + a31*b12;
}


void cmlc_matrix4x2_mult_matrix2x4(const CML_Matrix4x2 *A, const CML_Matrix2x4 *B, CML_Matrix4x4 *out) {
    f32 a00 = A->m00, a01 = A->m01;
    f32 a10 = A->m10, a11 = A->m11;
    f32 a20 = A->m20, a21 = A->m21;
    f32 a30 = A->m30, a31 = A->m31;

    f32 b00 = B->m00, b01 = B->m01, b02 = B->m02, b03 = B->m03;
    f32 b10 = B->m10, b11 = B->m11, b12 = B->m12, b13 = B->m13;

    out->m00 = a00*b00 + a01*b10;
    out->m01 = a00*b01 + a01*b11;
    out->m02 = a00*b02 + a01*b12;
    out->m03 = a00*b03 + a01*b13;
    out->m10 = a10*b00 + a11*b10;
    out->m11 = a10*b01 + a11*b11;
    out->m12 = a10*b02 + a11*b12;
    out->m13 = a10*b03 + a11*b13;
    out->m20 = a20*b00 + a21*b10;
    out->m21 = a20*b01 + a21*b11;
    out->m22 = a20*b02 + a21*b12;
    out->m23 = a20*b03 + a21*b13;
    out->m30 = a30*b00 + a31*b10;
    out->m31 = a30*b01 + a31*b11;
    out->m32 = a30*b02 + a31*b12;
    out->m33 = a30*b03 + a31*b13;
}


void cmlc_matrix4x2_mult_vector2(const CML_Matrix4x2 *A, const CML_Vector2 *v, CML_Vector4 *out) {
    f32 a00 = A->m00, a01 = A->m01;
    f32 a10 = A->m10, a11 = A->m11;
    f32 a20 = A->m20, a21 = A->m21;
    f32 a30 = A->m30, a31 = A->m31;

    f32 v0 = v->x, v1 = v->y;

    out->x = a00*v0 + a01*v1;
    out->y = a10*v0 + a11*v1;
    out->z = a20*v0 + a21*v1;
    out->w = a30*v0 + a31*v1;
}


void cmlc_vector4_mult_matrix4x2(const CML_Vector4 *v, const CML_Matrix4x2 *A, CML_Vector2 *out) {
    f32 a00 = A->m00, a01 = A->m01;
    f32 a10 = A->m10, a11 = A->m11;
    f32 a20 = A->m20, a21 = A->m21;
    f32 a30 = A->m30, a31 = A->m31;

    f32 v0 = v->x, v1 = v->y, v2 = v->z, v3 = v->w;

    out->x = a00*v0 + a10*v1 + a20*v2 + a30*v3;
    out->y = a01*v0 + a11*v1 + a21*v2 + a31*v3;
}


void cmlc_matrix4x2_transpose(const CML_Matrix4x2 *A, CML_Matrix2x4 *out) {
    out->m00 = A->m00;
    out->m01 = A->m10;
    out->m02 = A->m20;
    out->m03 = A->m30;
    out->m10 = A->m01;
    out->m11 = A->m11;
    out->m12 = A->m21;
    out->m13 = A->m31;
}


CML_Bool cmlc_matrix4x2_eq(const CML_Matrix4x2 *A, const CML_Matrix4x2 *B) {
    if (!A || !B) {
        return CML_FALSE;
    }

    return (fabsf(A->m00 - B->m00) <= CML_EPSILON && fabsf(A->m01 - B->m01) <= CML_EPSILON && 
            fabsf(A->m10 - B->m10) <= CML_EPSILON && fabsf(A->m11 - B->m11) <= CML_EPSILON && 
            fabsf(A->m20 - B->m20) <= CML_EPSILON && fabsf(A->m21 - B->m21) <= CML_EPSILON && 
            fabsf(A->m30 - B->m30) <= CML_EPSILON && fabsf(A->m31 - B->m31) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cmlc_matrix4x2_debug(const CML_Matrix4x2 *expected, const CML_Matrix4x2 *got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    sprintf(debugMessage, "\t\tExpected:\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n\t\t\t[%lf, %lf]\n", 
        expected->m00, expected->m01,
        expected->m10, expected->m11,
        expected->m20, expected->m21,
        expected->m30, expected->m31,
        got->m00, got->m01,
        got->m10, got->m11,
        got->m20, got->m21,
        got->m30, got->m31);

    return debugMessage;
}



void cmlc_matrix4x3_add(const CML_Matrix4x3 *A, const CML_Matrix4x3 *B, CML_Matrix4x3 *out) {
    out->m00 = A->m00 + B->m00;
    out->m01 = A->m01 + B->m01;
    out->m02 = A->m02 + B->m02;
    out->m10 = A->m10 + B->m10;
    out->m11 = A->m11 + B->m11;
    out->m12 = A->m12 + B->m12;
    out->m20 = A->m20 + B->m20;
    out->m21 = A->m21 + B->m21;
    out->m22 = A->m22 + B->m22;
    out->m30 = A->m30 + B->m30;
    out->m31 = A->m31 + B->m31;
    out->m32 = A->m32 + B->m32;
}


void cmlc_matrix4x3_sub(const CML_Matrix4x3 *A, const CML_Matrix4x3 *B, CML_Matrix4x3 *out) {
    out->m00 = A->m00 - B->m00;
    out->m01 = A->m01 - B->m01;
    out->m02 = A->m02 - B->m02;
    out->m10 = A->m10 - B->m10;
    out->m11 = A->m11 - B->m11;
    out->m12 = A->m12 - B->m12;
    out->m20 = A->m20 - B->m20;
    out->m21 = A->m21 - B->m21;
    out->m22 = A->m22 - B->m22;
    out->m30 = A->m30 - B->m30;
    out->m31 = A->m31 - B->m31;
    out->m32 = A->m32 - B->m32;
}


void cmlc_matrix4x3_scale(const CML_Matrix4x3 *A, f32 t, CML_Matrix4x3 *out) {
    out->m00 = A->m00 * t;
    out->m01 = A->m01 * t;
    out->m02 = A->m02 * t;
    out->m10 = A->m10 * t;
    out->m11 = A->m11 * t;
    out->m12 = A->m12 * t;
    out->m20 = A->m20 * t;
    out->m21 = A->m21 * t;
    out->m22 = A->m22 * t;
    out->m30 = A->m30 * t;
    out->m31 = A->m31 * t;
    out->m32 = A->m32 * t;
}


void cmlc_matrix4x3_mult_matrix3x2(const CML_Matrix4x3 *A, const CML_Matrix3x2 *B, CML_Matrix4x2 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22;
    f32 a30 = A->m30, a31 = A->m31, a32 = A->m32;

    f32 b00 = B->m00, b01 = B->m01;
    f32 b10 = B->m10, b11 = B->m11;
    f32 b20 = B->m20, b21 = B->m21;

    out->m00 = a00*b00 + a01*b10 + a02*b20;
    out->m01 = a00*b01 + a01*b11 + a02*b21;
    out->m10 = a10*b00 + a11*b10 + a12*b20;
    out->m11 = a10*b01 + a11*b11 + a12*b21;
    out->m20 = a20*b00 + a21*b10 + a22*b20;
    out->m21 = a20*b01 + a21*b11 + a22*b21;
    out->m30 = a30*b00 + a31*b10 + a32*b20;
    out->m31 = a30*b01 + a31*b11 + a32*b21;
}


void cmlc_matrix4x3_mult_matrix3x3(const CML_Matrix4x3 *A, const CML_Matrix3x3 *B, CML_Matrix4x3 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22;
    f32 a30 = A->m30, a31 = A->m31, a32 = A->m32;

    f32 b00 = B->m00, b01 = B->m01, b02 = B->m02;
    f32 b10 = B->m10, b11 = B->m11, b12 = B->m12;
    f32 b20 = B->m20, b21 = B->m21, b22 = B->m22;

    out->m00 = a00*b00 + a01*b10 + a02*b20;
    out->m01 = a00*b01 + a01*b11 + a02*b21;
    out->m02 = a00*b02 + a01*b12 + a02*b22;
    out->m10 = a10*b00 + a11*b10 + a12*b20;
    out->m11 = a10*b01 + a11*b11 + a12*b21;
    out->m12 = a10*b02 + a11*b12 + a12*b22;
    out->m20 = a20*b00 + a21*b10 + a22*b20;
    out->m21 = a20*b01 + a21*b11 + a22*b21;
    out->m22 = a20*b02 + a21*b12 + a22*b22;
    out->m30 = a30*b00 + a31*b10 + a32*b20;
    out->m31 = a30*b01 + a31*b11 + a32*b21;
    out->m32 = a30*b02 + a31*b12 + a32*b22;
}


void cmlc_matrix4x3_mult_matrix3x4(const CML_Matrix4x3 *A, const CML_Matrix3x4 *B, CML_Matrix4x4 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22;
    f32 a30 = A->m30, a31 = A->m31, a32 = A->m32;

    f32 b00 = B->m00, b01 = B->m01, b02 = B->m02, b03 = B->m03;
    f32 b10 = B->m10, b11 = B->m11, b12 = B->m12, b13 = B->m13;
    f32 b20 = B->m20, b21 = B->m21, b22 = B->m22, b23 = B->m23;

    out->m00 = a00*b00 + a01*b10 + a02*b20;
    out->m01 = a00*b01 + a01*b11 + a02*b21;
    out->m02 = a00*b02 + a01*b12 + a02*b22;
    out->m03 = a00*b03 + a01*b13 + a02*b23;
    out->m10 = a10*b00 + a11*b10 + a12*b20;
    out->m11 = a10*b01 + a11*b11 + a12*b21;
    out->m12 = a10*b02 + a11*b12 + a12*b22;
    out->m13 = a10*b03 + a11*b13 + a12*b23;
    out->m20 = a20*b00 + a21*b10 + a22*b20;
    out->m21 = a20*b01 + a21*b11 + a22*b21;
    out->m22 = a20*b02 + a21*b12 + a22*b22;
    out->m23 = a20*b03 + a21*b13 + a22*b23;
    out->m30 = a30*b00 + a31*b10 + a32*b20;
    out->m31 = a30*b01 + a31*b11 + a32*b21;
    out->m32 = a30*b02 + a31*b12 + a32*b22;
    out->m33 = a30*b03 + a31*b13 + a32*b23;
}


void cmlc_matrix4x3_mult_vector3(const CML_Matrix4x3 *A, const CML_Vector3 *v, CML_Vector4 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22;
    f32 a30 = A->m30, a31 = A->m31, a32 = A->m32;

    f32 v0 = v->x, v1 = v->y, v2 = v->z;

    out->x = a00*v0 + a01*v1 + a02*v2;
    out->y = a10*v0 + a11*v1 + a12*v2;
    out->z = a20*v0 + a21*v1 + a22*v2;
    out->w = a30*v0 + a31*v1 + a32*v2;
}


void cmlc_vector4_mult_matrix4x3(const CML_Vector4 *v, const CML_Matrix4x3 *A, CML_Vector3 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22;
    f32 a30 = A->m30, a31 = A->m31, a32 = A->m32;

    f32 v0 = v->x, v1 = v->y, v2 = v->z, v3 = v->w;

    out->x = a00*v0 + a10*v1 + a20*v2 + a30*v3;
    out->y = a01*v0 + a11*v1 + a21*v2 + a31*v3;
    out->z = a02*v0 + a12*v1 + a22*v2 + a32*v3;
}


void cmlc_matrix4x3_transpose(const CML_Matrix4x3 *A, CML_Matrix3x4 *out) {
    f32 a00 = A->m00, a01 = A->m01, a02 = A->m02;
    f32 a10 = A->m10, a11 = A->m11, a12 = A->m12;
    f32 a20 = A->m20, a21 = A->m21, a22 = A->m22;
    f32 a30 = A->m30, a31 = A->m31, a32 = A->m32;

    out->m00 = a00;
    out->m01 = a10;
    out->m02 = a20;
    out->m03 = a30;
    out->m10 = a01;
    out->m11 = a11;
    out->m12 = a21;
    out->m13 = a31;
    out->m20 = a02;
    out->m21 = a12;
    out->m22 = a22;
    out->m23 = a32;
}


CML_Bool cmlc_matrix4x3_eq(const CML_Matrix4x3 *A, const CML_Matrix4x3 *B) {
    if (!A || !B) {
        return CML_FALSE;
    }

    return (fabsf(A->m00 - B->m00) <= CML_EPSILON && fabsf(A->m01 - B->m01) <= CML_EPSILON && fabsf(A->m02 - B->m02) <= CML_EPSILON && 
            fabsf(A->m10 - B->m10) <= CML_EPSILON && fabsf(A->m11 - B->m11) <= CML_EPSILON && fabsf(A->m12 - B->m12) <= CML_EPSILON && 
            fabsf(A->m20 - B->m20) <= CML_EPSILON && fabsf(A->m21 - B->m21) <= CML_EPSILON && fabsf(A->m22 - B->m22) <= CML_EPSILON && 
            fabsf(A->m30 - B->m30) <= CML_EPSILON && fabsf(A->m31 - B->m31) <= CML_EPSILON && fabsf(A->m32 - B->m32) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cmlc_matrix4x3_debug(const CML_Matrix4x3 *expected, const CML_Matrix4x3 *got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    sprintf(debugMessage, "\t\tExpected:\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n\t\t\t[%lf, %lf, %lf]\n", 
        expected->m00, expected->m01, expected->m02,
        expected->m10, expected->m11, expected->m12,
        expected->m20, expected->m21, expected->m22,
        expected->m30, expected->m31, expected->m32,
        got->m00, got->m01, got->m02,
        got->m10, got->m11, got->m12,
        got->m20, got->m21, got->m22,
        got->m30, got->m31, got->m32);

    return debugMessage;
}
