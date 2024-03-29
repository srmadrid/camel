/**
 * @file fmatrix.h
 * 
 * @brief Declarations and implementations for the fixed matrix manipulation 
 *        functions of CAMEL.
 * 
 * @note This module is header only. Matrices are column major.
 *
 * @author Sergio Madrid
 * @date 8/11/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_FIXED_MATRIX
#define CAMEL_FIXED_MATRIX


#include <stdlib.h>
#include <math.h>

#include "../../../core/macros.h"
#include "../../../core/err.h"
#include "../../../core/constants.h"
#include "fvector.h"


/**
 * @brief Represents a 2x2 matrix.
 * 
 * @note The matrix is stored in column major order.
 */
typedef union CML_Matrix2x2 {
    struct {
        /** @brief The element at row 0, column 0. */
        f32 m00;
        /** @brief The element at row 1, column 0. */
        f32 m10;
        /** @brief The element at row 0, column 1. */
        f32 m01;
        /** @brief The element at row 1, column 1. */
        f32 m11;
    };
    /** @brief The matrix as an array of 4 elements. */
    f32 array[4];
} CML_Matrix2x2;


/**
 * @brief Initializes a CML_Matrix2x2 to the zero matrix.
 */
#define CML_MATRIX2X2_ZERO {{0.0f, 0.0f, \
                             0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Matrix2x2 to the identity matrix.
 */
#define CML_MATRIX2X2_IDENTITY {{1.0f, 0.0f, \
                                 0.0f, 1.0f}}


/**
 * @brief Initializes a CML_Matrix2x2 to the one matrix.
 */
#define CML_MATRIX2X2_ONE {{1.0f, 1.0f, \
                            1.0f, 1.0f}}


/**
 * @brief Initializes a CML_Matrix2x2 to the given values.
 * 
 * @note The matrix is stored in column major order, but the parameters are
 *       given in row major order for convenience.
 * 
 * @param m00 The element at row 0, column 0.
 * @param m01 The element at row 0, column 1.
 * @param m10 The element at row 1, column 0.
 * @param m11 The element at row 1, column 1.
 */
#define CML_MATRIX2X2(m00, m01, m10, m11) {{m00, m10, \
                                            m01, m11}}



/**
 * @brief Represents a 3x3 matrix.
 * 
 * @note The matrix is stored in column major order.
 */
typedef union CML_Matrix3x3 {
    struct {
        /** @brief The element at row 0, column 0. */
        f32 m00;
        /** @brief The element at row 1, column 0. */
        f32 m10;
        /** @brief The element at row 2, column 0. */
        f32 m20;
        /** @brief The element at row 0, column 1. */
        f32 m01;
        /** @brief The element at row 1, column 1. */
        f32 m11;
        /** @brief The element at row 2, column 1. */
        f32 m21;
        /** @brief The element at row 0, column 2. */
        f32 m02;
        /** @brief The element at row 1, column 2. */
        f32 m12;
        /** @brief The element at row 2, column 2. */
        f32 m22;
    };
    /** @brief The matrix as an array of 9 elements. */
    f32 array[9];
} CML_Matrix3x3;


/**
 * @brief Initializes a CML_Matrix3x3 to the zero matrix.
 */
#define CML_MATRIX3X3_ZERO {{0.0f, 0.0f, 0.0f, \
                             0.0f, 0.0f, 0.0f, \
                             0.0f, 0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Matrix3x3 to the identity matrix.
 */
#define CML_MATRIX3X3_IDENTITY {{1.0f, 0.0f, 0.0f, \
                                 0.0f, 1.0f, 0.0f, \
                                 0.0f, 0.0f, 1.0f}}


/**
 * @brief Initializes a CML_Matrix3x3 to the one matrix.
 */
#define CML_MATRIX3X3_ONE {{1.0f, 1.0f, 1.0f, \
                            1.0f, 1.0f, 1.0f, \
                            1.0f, 1.0f, 1.0f}}


/**
 * @brief Initializes a CML_Matrix3x3 to the given values.
 * 
 * @note The matrix is stored in column major order, but the parameters are
 *       given in row major order for convenience.
 * 
 * @param m00 The element at row 0, column 0.
 * @param m01 The element at row 0, column 1.
 * @param m02 The element at row 0, column 2.
 * @param m10 The element at row 1, column 0.
 * @param m11 The element at row 1, column 1.
 * @param m12 The element at row 1, column 2.
 * @param m20 The element at row 2, column 0.
 * @param m21 The element at row 2, column 1.
 * @param m22 The element at row 2, column 2.
 */
#define CML_MATRIX3X3(m00, m01, m02, \
                      m10, m11, m12, \
                      m20, m21, m22) {{m00, m10, m20, \
                                       m01, m11, m21, \
                                       m02, m12, m22}}



/**
 * @brief Represents a 4x4 matrix.
 * 
 * @note The matrix is stored in column major order.
 */
typedef union CML_Matrix4x4 {
    struct {
        /** @brief The element at row 0, column 0. */
        f32 m00;
        /** @brief The element at row 1, column 0. */
        f32 m10;
        /** @brief The element at row 2, column 0. */
        f32 m20;
        /** @brief The element at row 3, column 0. */
        f32 m30;
        /** @brief The element at row 0, column 1. */
        f32 m01;
        /** @brief The element at row 1, column 1. */
        f32 m11;
        /** @brief The element at row 2, column 1. */
        f32 m21;
        /** @brief The element at row 3, column 1. */
        f32 m31;
        /** @brief The element at row 0, column 2. */
        f32 m02;
        /** @brief The element at row 1, column 2. */
        f32 m12;
        /** @brief The element at row 2, column 2. */
        f32 m22;
        /** @brief The element at row 3, column 2. */
        f32 m32;
        /** @brief The element at row 0, column 3. */
        f32 m03;
        /** @brief The element at row 1, column 3. */
        f32 m13;
        /** @brief The element at row 2, column 3. */
        f32 m23;
        /** @brief The element at row 3, column 3. */
        f32 m33;
    };
    /** @brief The matrix as an array of 16 elements. */
    f32 array[16];
} CML_Matrix4x4;


/**
 * @brief Initializes a CML_Matrix4x4 to the zero matrix.
 */
#define CML_MATRIX4X4_ZERO {{0.0f, 0.0f, 0.0f, 0.0f, \
                             0.0f, 0.0f, 0.0f, 0.0f, \
                             0.0f, 0.0f, 0.0f, 0.0f, \
                             0.0f, 0.0f, 0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Matrix4x4 to the identity matrix.
 */
#define CML_MATRIX4X4_IDENTITY {{1.0f, 0.0f, 0.0f, 0.0f, \
                                 0.0f, 1.0f, 0.0f, 0.0f, \
                                 0.0f, 0.0f, 1.0f, 0.0f, \
                                 0.0f, 0.0f, 0.0f, 1.0f}}


/**
 * @brief Initializes a CML_Matrix4x4 to the one matrix.
 */
#define CML_MATRIX4X4_ONE {{1.0f, 1.0f, 1.0f, 1.0f, \
                            1.0f, 1.0f, 1.0f, 1.0f, \
                            1.0f, 1.0f, 1.0f, 1.0f, \
                            1.0f, 1.0f, 1.0f, 1.0f}}


/**
 * @brief Initializes a CML_Matrix4x4 to the given values.
 * 
 * @note The matrix is stored in column major order, but the parameters are
 *       given in row major order for convenience.
 * 
 * @param m00 The element at row 0, column 0.
 * @param m01 The element at row 0, column 1.
 * @param m02 The element at row 0, column 2.
 * @param m03 The element at row 0, column 3.
 * @param m10 The element at row 1, column 0.
 * @param m11 The element at row 1, column 1.
 * @param m12 The element at row 1, column 2.
 * @param m13 The element at row 1, column 3.
 * @param m20 The element at row 2, column 0.
 * @param m21 The element at row 2, column 1.
 * @param m22 The element at row 2, column 2.
 * @param m23 The element at row 2, column 3.
 * @param m30 The element at row 3, column 0.
 * @param m31 The element at row 3, column 1.
 * @param m32 The element at row 3, column 2.
 * @param m33 The element at row 3, column 3.
 */
#define CML_MATRIX4X4(m00, m01, m02, m03, \
                      m10, m11, m12, m13, \
                      m20, m21, m22, m23, \
                      m30, m31, m32, m33) {{m00, m10, m20, m30, \
                                            m01, m11, m21, m31, \
                                            m02, m12, m22, m32, \
                                            m03, m13, m23, m33}}



/**
 * @brief Represents a 2x3 matrix.
 * 
 * @note The matrix is stored in column major order.
 */
typedef union CML_Matrix2x3 {
    struct {
        /** @brief The element at row 0, column 0. */
        f32 m00;
        /** @brief The element at row 1, column 0. */
        f32 m10;
        /** @brief The element at row 0, column 1. */
        f32 m01;
        /** @brief The element at row 1, column 1. */
        f32 m11;
        /** @brief The element at row 0, column 2. */
        f32 m02;
        /** @brief The element at row 1, column 2. */
        f32 m12;
    };
    /** @brief The matrix as an array of 6 elements. */
    f32 array[6];
} CML_Matrix2x3;


/**
 * @brief Initializes a CML_Matrix2x3 to the zero matrix.
 */
#define CML_MATRIX2X3_ZERO {{0.0f, 0.0f, \
                             0.0f, 0.0f, \
                             0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Matrix2x3 to the identity matrix.
 */
#define CML_MATRIX2X3_IDENTITY {{1.0f, 0.0f, \
                                 0.0f, 1.0f, \
                                 0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Matrix2x3 to the one matrix.
 */
#define CML_MATRIX2X3_ONE {{1.0f, 1.0f, \
                            1.0f, 1.0f, \
                            1.0f, 1.0f}}


/**
 * @brief Initializes a CML_Matrix2x3 to the given values.
 * 
 * @note The matrix is stored in column major order, but the parameters are
 *       given in row major order for convenience.
 * 
 * @param m00 The element at row 0, column 0.
 * @param m01 The element at row 0, column 1.
 * @param m02 The element at row 0, column 2.
 * @param m10 The element at row 1, column 0.
 * @param m11 The element at row 1, column 1.
 * @param m12 The element at row 1, column 2.
 */
#define CML_MATRIX2X3(m00, m01, m02, \
                      m10, m11, m12) {{m00, m10, \
                                       m01, m11, \
                                       m02, m12}}



/**
 * @brief Represents a 2x4 matrix.
 * 
 * @note The matrix is stored in column major order.
 */
typedef union CML_Matrix2x4 {
    struct {
        /** @brief The element at row 0, column 0. */
        f32 m00;
        /** @brief The element at row 1, column 0. */
        f32 m10;
        /** @brief The element at row 0, column 1. */
        f32 m01;
        /** @brief The element at row 1, column 1. */
        f32 m11;
        /** @brief The element at row 0, column 2. */
        f32 m02;
        /** @brief The element at row 1, column 2. */
        f32 m12;
        /** @brief The element at row 0, column 3. */
        f32 m03;
        /** @brief The element at row 1, column 3. */
        f32 m13;
    };
    /** @brief The matrix as an array of 8 elements. */
    f32 array[8];
} CML_Matrix2x4;


/**
 * @brief Initializes a CML_Matrix2x4 to the zero matrix.
 */
#define CML_MATRIX2X4_ZERO {{0.0f, 0.0f, \
                             0.0f, 0.0f, \
                             0.0f, 0.0f, \
                             0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Matrix2x4 to the identity matrix.
 */
#define CML_MATRIX2X4_IDENTITY {{1.0f, 0.0f, \
                                 0.0f, 1.0f, \
                                 0.0f, 0.0f, \
                                 0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Matrix2x4 to the one matrix.
 */
#define CML_MATRIX2X4_ONE {{1.0f, 1.0f, \
                            1.0f, 1.0f, \
                            1.0f, 1.0f, \
                            1.0f, 1.0f}}


/**
 * @brief Initializes a CML_Matrix2x4 to the given values.
 * 
 * @note The matrix is stored in column major order, but the parameters are
 *       given in row major order for convenience.
 * 
 * @param m00 The element at row 0, column 0.
 * @param m01 The element at row 0, column 1.
 * @param m02 The element at row 0, column 2.
 * @param m03 The element at row 0, column 3.
 * @param m10 The element at row 1, column 0.
 * @param m11 The element at row 1, column 1.
 * @param m12 The element at row 1, column 2.
 * @param m13 The element at row 1, column 3.
 */
#define CML_MATRIX2X4(m00, m01, m02, m03, \
                      m10, m11, m12, m13) {{m00, m10, \
                                            m01, m11, \
                                            m02, m12, \
                                            m03, m13}}



/**
 * @brief Represents a 3x2 matrix.
 * 
 * @note The matrix is stored in column major order.
 */
typedef union CML_Matrix3x2 {
    struct {
        /** @brief The element at row 0, column 0. */
        f32 m00;
        /** @brief The element at row 1, column 0. */
        f32 m10;
        /** @brief The element at row 2, column 0. */
        f32 m20;
        /** @brief The element at row 0, column 1. */
        f32 m01;
        /** @brief The element at row 1, column 1. */
        f32 m11;
        /** @brief The element at row 2, column 1. */
        f32 m21;
    };
    /** @brief The matrix as an array of 6 elements. */
    f32 array[6];
} CML_Matrix3x2;


/**
 * @brief Initializes a CML_Matrix3x2 to the zero matrix.
 */
#define CML_MATRIX3X2_ZERO {{0.0f, 0.0f, 0.0f, \
                             0.0f, 0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Matrix3x2 to the identity matrix.
 */
#define CML_MATRIX3X2_IDENTITY {{1.0f, 0.0f, 0.0f, \
                                 0.0f, 1.0f, 0.0f}}


/**
 * @brief Initializes a CML_Matrix3x2 to the one matrix.
 */
#define CML_MATRIX3X2_ONE {{1.0f, 1.0f, 1.0f, \
                            1.0f, 1.0f, 1.0f}}


/**
 * @brief Initializes a CML_Matrix3x2 to the given values.
 * 
 * @note The matrix is stored in column major order, but the parameters are
 *       given in row major order for convenience.
 * 
 * @param m00 The element at row 0, column 0.
 * @param m01 The element at row 0, column 1.
 * @param m10 The element at row 1, column 0.
 * @param m11 The element at row 1, column 1.
 * @param m20 The element at row 2, column 0.
 * @param m21 The element at row 2, column 1.
 */
#define CML_MATRIX3X2(m00, m01, \
                      m10, m11, \
                      m20, m21) {{m00, m10, m20, \
                                  m01, m11, m21}} 



/**
 * @brief Represents a 3x4 matrix.
 * 
 * @note The matrix is stored in column major order.
 */
typedef union CML_Matrix3x4 {
    struct {
        /** @brief The element at row 0, column 0. */
        f32 m00;
        /** @brief The element at row 1, column 0. */
        f32 m10;
        /** @brief The element at row 2, column 0. */
        f32 m20;
        /** @brief The element at row 0, column 1. */
        f32 m01;
        /** @brief The element at row 1, column 1. */
        f32 m11;
        /** @brief The element at row 2, column 1. */
        f32 m21;
        /** @brief The element at row 0, column 2. */
        f32 m02;
        /** @brief The element at row 1, column 2. */
        f32 m12;
        /** @brief The element at row 2, column 2. */
        f32 m22;
        /** @brief The element at row 0, column 3. */
        f32 m03;
        /** @brief The element at row 1, column 3. */
        f32 m13;
        /** @brief The element at row 2, column 3. */
        f32 m23;
    };
    /** @brief The matrix as an array of 12 elements. */
    f32 array[12];
} CML_Matrix3x4;


/**
 * @brief Initializes a CML_Matrix3x4 to the zero matrix.
 */
#define CML_MATRIX3X4_ZERO {{0.0f, 0.0f, 0.0f, \
                             0.0f, 0.0f, 0.0f, \
                             0.0f, 0.0f, 0.0f, \
                             0.0f, 0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Matrix3x4 to the identity matrix.
 */
#define CML_MATRIX3X4_IDENTITY {{1.0f, 0.0f, 0.0f, \
                                 0.0f, 1.0f, 0.0f, \
                                 0.0f, 0.0f, 1.0f, \
                                 0.0f, 0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Matrix3x4 to the one matrix.
 */
#define CML_MATRIX3X4_ONE {{1.0f, 1.0f, 1.0f, \
                            1.0f, 1.0f, 1.0f, \
                            1.0f, 1.0f, 1.0f, \
                            1.0f, 1.0f, 1.0f}}


/**
 * @brief Initializes a CML_Matrix3x4 to the given values.
 * 
 * @note The matrix is stored in column major order, but the parameters are
 *       given in row major order for convenience.
 * 
 * @param m00 The element at row 0, column 0.
 * @param m01 The element at row 0, column 1.
 * @param m02 The element at row 0, column 2.
 * @param m03 The element at row 0, column 3.
 * @param m10 The element at row 1, column 0.
 * @param m11 The element at row 1, column 1.
 * @param m12 The element at row 1, column 2.
 * @param m13 The element at row 1, column 3.
 * @param m20 The element at row 2, column 0.
 * @param m21 The element at row 2, column 1.
 * @param m22 The element at row 2, column 2.
 * @param m23 The element at row 2, column 3.
 */
#define CML_MATRIX3X4(m00, m01, m02, m03, \
                      m10, m11, m12, m13, \
                      m20, m21, m22, m23) {{m00, m10, m20, \
                                            m01, m11, m21, \
                                            m02, m12, m22, \
                                            m03, m13, m23}}



/**
 * @brief Represents a 4x2 matrix.
 * 
 * @note The matrix is stored in column major order.
 */
typedef union CML_Matrix4x2 {
    struct {
        /** @brief The element at row 0, column 0. */
        f32 m00;
        /** @brief The element at row 1, column 0. */
        f32 m10;
        /** @brief The element at row 2, column 0. */
        f32 m20;
        /** @brief The element at row 3, column 0. */
        f32 m30;
        /** @brief The element at row 0, column 1. */
        f32 m01;
        /** @brief The element at row 1, column 1. */
        f32 m11;
        /** @brief The element at row 2, column 1. */
        f32 m21;
        /** @brief The element at row 3, column 1. */
        f32 m31;
    };
    /** @brief The matrix as an array of 8 elements. */
    f32 array[8];
} CML_Matrix4x2;


/**
 * @brief Initializes a CML_Matrix4x2 to the zero matrix.
 */
#define CML_MATRIX4X2_ZERO {{0.0f, 0.0f, 0.0f, 0.0f, \
                             0.0f, 0.0f, 0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Matrix4x2 to the identity matrix.
 */
#define CML_MATRIX4X2_IDENTITY {{1.0f, 0.0f, 0.0f, 0.0f, \
                                 0.0f, 1.0f, 0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Matrix4x2 to the one matrix.
 */
#define CML_MATRIX4X2_ONE {{1.0f, 1.0f, 1.0f, 1.0f, \
                            1.0f, 1.0f, 1.0f, 1.0f}}


/**
 * @brief Initializes a CML_Matrix4x2 to the given values.
 * 
 * @note The matrix is stored in column major order, but the parameters are
 *       given in row major order for convenience.
 * 
 * @param m00 The element at row 0, column 0.
 * @param m01 The element at row 0, column 1.
 * @param m10 The element at row 1, column 0.
 * @param m11 The element at row 1, column 1.
 * @param m20 The element at row 2, column 0.
 * @param m21 The element at row 2, column 1.
 * @param m30 The element at row 3, column 0.
 * @param m31 The element at row 3, column 1.
 */
#define CML_MATRIX4X2(m00, m01, \
                      m10, m11, \
                      m20, m21, \
                      m30, m31) {{m00, m10, m20, m30, \
                                  m01, m11, m21, m31}}



/**
 * @brief Represents a 4x3 matrix.
 * 
 * @note The matrix is stored in column major order.
 */
typedef union CML_Matrix4x3 {
    struct {
        /** @brief The element at row 0, column 0. */
        f32 m00;
        /** @brief The element at row 1, column 0. */
        f32 m10;
        /** @brief The element at row 2, column 0. */
        f32 m20;
        /** @brief The element at row 3, column 0. */
        f32 m30;
        /** @brief The element at row 0, column 1. */
        f32 m01;
        /** @brief The element at row 1, column 1. */
        f32 m11;
        /** @brief The element at row 2, column 1. */
        f32 m21;
        /** @brief The element at row 3, column 1. */
        f32 m31;
        /** @brief The element at row 0, column 2. */
        f32 m02;
        /** @brief The element at row 1, column 2. */
        f32 m12;
        /** @brief The element at row 2, column 2. */
        f32 m22;
        /** @brief The element at row 3, column 2. */
        f32 m32;
    };
    /** @brief The matrix as an array of 12 elements. */
    f32 array[12];
} CML_Matrix4x3;


/**
 * @brief Initializes a CML_Matrix4x3 to the zero matrix.
 */
#define CML_MATRIX4X3_ZERO {{0.0f, 0.0f, 0.0f, 0.0f, \
                             0.0f, 0.0f, 0.0f, 0.0f, \
                             0.0f, 0.0f, 0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Matrix4x3 to the identity matrix.
 */
#define CML_MATRIX4X3_IDENTITY {{1.0f, 0.0f, 0.0f, 0.0f, \
                                 0.0f, 1.0f, 0.0f, 0.0f, \
                                 0.0f, 0.0f, 1.0f, 0.0f}}


/**
 * @brief Initializes a CML_Matrix4x3 to the one matrix.
 */
#define CML_MATRIX4X3_ONE {{1.0f, 1.0f, 1.0f, 1.0f, \
                            1.0f, 1.0f, 1.0f, 1.0f, \
                            1.0f, 1.0f, 1.0f, 1.0f}}


/**
 * @brief Initializes a CML_Matrix4x3 to the given values.
 * 
 * @note The matrix is stored in column major order, but the parameters are
 *       given in row major order for convenience.
 * 
 * @param m00 The element at row 0, column 0.
 * @param m01 The element at row 0, column 1.
 * @param m02 The element at row 0, column 2.
 * @param m10 The element at row 1, column 0.
 * @param m11 The element at row 1, column 1.
 * @param m12 The element at row 1, column 2.
 * @param m20 The element at row 2, column 0.
 * @param m21 The element at row 2, column 1.
 * @param m22 The element at row 2, column 2.
 * @param m30 The element at row 3, column 0.
 * @param m31 The element at row 3, column 1.
 * @param m32 The element at row 3, column 2.
 */
#define CML_MATRIX4X3(m00, m01, m02, \
                      m10, m11, m12, \
                      m20, m21, m22, \
                      m30, m31, m32) {{m00, m10, m20, m30, \
                                       m01, m11, m21, m31, \
                                       m02, m12, m22, m32}}



/**
 * @brief Adds two CML_Matrix2x2 and writes the result to the out CML_Matrix2x2.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x2_add(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B, CML_Matrix2x2 *out) {
    out->m00 = A->m00 + B->m00;
    out->m10 = A->m10 + B->m10;
    out->m01 = A->m01 + B->m01;
    out->m11 = A->m11 + B->m11;
}


/**
 * @brief Subtracts two CML_Matrix2x2 and writes the result to the out 
 *        CML_Matrix2x2.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x2_sub(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B, CML_Matrix2x2 *out) {
    out->m00 = A->m00 - B->m00;
    out->m10 = A->m10 - B->m10;
    out->m01 = A->m01 - B->m01;
    out->m11 = A->m11 - B->m11;
}


/**
 * @brief Multiplies a CML_Matrix2x2 by a scalar, and writes the result to the 
 *        out CML_Matrix2x2.
 * 
 * @param A   The matrix operand.
 * @param t   The scalar.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x2_scale(const CML_Matrix2x2 *A, f32 t, CML_Matrix2x2 *out) {
    out->m00 = A->m00 * t;
    out->m10 = A->m10 * t;
    out->m01 = A->m01 * t;
    out->m11 = A->m11 * t;
}


/**
 * @brief Multiplies two CML_Matrix2x2, and writes the result to the out 
 *        CML_Matrix2x2.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x2_mult(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B, CML_Matrix2x2 *out) {
    f32 a00 = A->m00, a10 = A->m10, a01 = A->m01, a11 = A->m11;
    f32 b00 = B->m00, b10 = B->m10, b01 = B->m01, b11 = B->m11;

    out->m00 = a00*b00 + a01*b10;
    out->m10 = a10*b00 + a11*b10;
    out->m01 = a00*b01 + a01*b11;
    out->m11 = a10*b01 + a11*b11;
}


/**
 * @brief Multiplies a CML_Matrix2x2 by a CML_Matrix2x3, and writes the result 
 *        to the out CML_Matrix2x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x2_mult_matrix2x3(const CML_Matrix2x2 *A, const CML_Matrix2x3 *B, CML_Matrix2x3 *out) {
    f32 a00 = A->m00, a10 = A->m10, a01 = A->m01, a11 = A->m11;

    f32 b00 = B->m00, b10 = B->m10;
    f32 b01 = B->m01, b11 = B->m11;
    f32 b02 = B->m02, b12 = B->m12;

    out->m00 = a00*b00 + a01*b10;
    out->m10 = a10*b00 + a11*b10;
    out->m01 = a00*b01 + a01*b11;
    out->m11 = a10*b01 + a11*b11;
    out->m02 = a00*b02 + a01*b12;
    out->m12 = a10*b02 + a11*b12;
}


/**
 * @brief Multiplies a CML_Matrix2x2 by a CML_Matrix2x4, and writes the result 
 *        to the out CML_Matrix2x4.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x2_mult_matrix2x4(const CML_Matrix2x2 *A, const CML_Matrix2x4 *B, CML_Matrix2x4 *out) {
    f32 a00 = A->m00, a10 = A->m10, a01 = A->m01, a11 = A->m11;

    f32 b00 = B->m00, b10 = B->m10;
    f32 b01 = B->m01, b11 = B->m11;
    f32 b02 = B->m02, b12 = B->m12;
    f32 b03 = B->m03, b13 = B->m13;

    out->m00 = a00*b00 + a01*b10;
    out->m10 = a10*b00 + a11*b10;
    out->m01 = a00*b01 + a01*b11;
    out->m11 = a10*b01 + a11*b11;
    out->m02 = a00*b02 + a01*b12;
    out->m12 = a10*b02 + a11*b12;
    out->m03 = a00*b03 + a01*b13;
    out->m13 = a10*b03 + a11*b13;
}


/**
 * @brief Multiplies a CML_Matrix2x2 by a CML_Vector2, and writes the result to 
 *        the out CML_Vector2.
 * 
 * @param A   The left matrix operand.
 * @param v   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x2_mult_vector2(const CML_Matrix2x2 *A, const CML_Vector2 *v, CML_Vector2 *out) {
    f32 a00 = A->m00, a10 = A->m10, a01 = A->m01, a11 = A->m11;

    f32 v0 = v->x, v1 = v->y;

    out->x = a00*v0 + a01*v1;
    out->y = a10*v0 + a11*v1;
}


/**
 * @brief Multiplies a CML_Vector2 by a CML_Matrix2x2, and writes the result to 
 *        the out CML_Vector2.
 * 
 * @param v   The left transposed vector operand.
 * @param A   The right matrix operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_vector2_mult_matrix2x2(const CML_Vector2 *v, const CML_Matrix2x2 *A, CML_Vector2 *out) {
    f32 a00 = A->m00, a10 = A->m10, a01 = A->m01, a11 = A->m11;
    
    f32 v0 = v->x, v1 = v->y;

    out->x = a00*v0 + a10*v1;
    out->y = a01*v0 + a11*v1;
}


/**
 * @brief Calculates the determinant of a CML_Matrix2x2.
 * 
 * @param A The matrix operand.
 * 
 * @return The determinant of the matrix.
 */
CAMEL_STATIC CAMEL_API f32 cml_matrix2x2_det(const CML_Matrix2x2 *A) {
    return A->m00*A->m11 - A->m01*A->m10;
}


/**
 * @brief Calculates the inverse of a CML_Matrix2x2 and writes the result to
 *        the out CML_Matrix2x2.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return Success or error code if the matrix is invertible.
 */
CAMEL_STATIC CAMEL_API CML_Status cml_matrix2x2_inv(const CML_Matrix2x2 *A, CML_Matrix2x2 *out) {
    f32 a00 = A->m00, a10 = A->m10, a01 = A->m01, a11 = A->m11;

    f32 det = (a00*a11 - a01*a10);

    if (det == 0.0f) {
        return CML_ERR_SINGULAR_MATRIX;
    }

    det = 1/det;

    out->m00 = a11*det;
    out->m10 = -a10*det;
    out->m01 = -a01*det;
    out->m11 = a00*det;

    return CML_SUCCESS;
}


/**
 * @brief Calculates the transpose of a CML_Matrix2x2 and writes the result to
 *        the out CML_Matrix2x2.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x2_transpose(const CML_Matrix2x2 *A, CML_Matrix2x2 *out) {
    f32 a00 = A->m00, a10 = A->m10, a01 = A->m01, a11 = A->m11;

    out->m00 = a00;
    out->m01 = a10;
    out->m10 = a01;
    out->m11 = a11;
}


/**
 * @brief Calculates the trace of a CML_Matrix2x2.
 * 
 * @param A The matrix operand.
 * 
 * @return The trace of the matrix.
 */
CAMEL_STATIC CAMEL_API f32 cml_matrix2x2_trace(const CML_Matrix2x2 *A) {
    return A->m00 + A->m11;
}


/**
 * @brief Generates a scale matrix and writes the result to the out
 *        CML_Matrix2x2.
 * 
 * @param x   The x scale.
 * @param y   The y scale.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x2_gen_scale(f32 x, f32 y, CML_Matrix2x2 *out) {
    out->m00 = x;
    out->m10 = 0.0f;
    out->m01 = 0.0f;
    out->m11 = y;
}


/**
 * @brief Generates the inverse of a scale matrix and writes the result to the
 *        out CML_Matrix2x2.
 * 
 * @param scale The input scale matrix.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x2_gen_invscale(const CML_Matrix2x2 *scale, CML_Matrix2x2 *out) {
    out->m00 = 1.0f/scale->m00;
    out->m10 = 0.0f;
    out->m01 = 0.0f;
    out->m11 = 1.0f/scale->m11;
}


/**
 * @brief Generates the shear matrix along the x axis and writes the result to
 *        the out CML_Matrix2x2.
 * 
 * @param x   The x shear.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x2_gen_shearx(f32 x, CML_Matrix2x2 *out) {
    out->m00 = 1.0f;
    out->m10 = 0.0f;
    out->m01 = x;
    out->m11 = 1.0f;
}


/**
 * @brief Generates the shear matrix along the y axis and writes the result to
 *        the out CML_Matrix2x2.
 * 
 * @param y   The y shear.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x2_gen_sheary(f32 y, CML_Matrix2x2 *out) {
    out->m00 = 1.0f;
    out->m10 = y;
    out->m01 = 0.0f;
    out->m11 = 1.0f;
}


/**
 * @brief Generates the inverse of a shear matrix and writes the result to the
 *        out CML_Matrix2x2.
 * 
 * @param shear The input shear matrix.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x2_gen_invshear(const CML_Matrix2x2 *shear, CML_Matrix2x2 *out) {
    out->m00 = 1.0f;
    out->m10 = -shear->m10;
    out->m01 = -shear->m01;
    out->m11 = 1.0f;
}


/**
 * @brief Generates the left-handed rotation matrix (clockwise) and writes the
 *        result to the out CML_Matrix2x2.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x2_genlh_rotation(f32 angle, CML_Matrix2x2 *out) {
    f32 c = cosf(-angle);
    f32 s = sinf(-angle);

    out->m00 = c;
    out->m10 = s;
    out->m01 = -s;
    out->m11 = c;
}


/**
 * @brief Generates the right-handed rotation matrix (counter clockwise) and
 *        writes the result to the out CML_Matrix2x2.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x2_genrh_rotation(f32 angle, CML_Matrix2x2 *out) {
    f32 c = cosf(angle);
    f32 s = sinf(angle);

    out->m00 = c;
    out->m10 = s;
    out->m01 = -s;
    out->m11 = c;
}


/**
 * @brief Generates the inverse of a rotation matrix and writes the result to
 *        the out CML_Matrix2x2.
 * 
 * @param rotation The input rotation matrix.
 * @param out      The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x2_gen_invrotation(const CML_Matrix2x2 *rotation, CML_Matrix2x2 *out) {
    out->m00 = rotation->m00;
    out->m10 = -rotation->m10;
    out->m01 = -rotation->m01;
    out->m11 = rotation->m11;
}


/**
 * @brief Compares two CML_Matrix2x2s for equality.
 * 
 * @param A The left matrix operand.
 * @param B The right matrix operand.
 * 
 * @return Boolean value indicating whether the matrices are equal.
 */
CAMEL_STATIC CAMEL_API b8 cml_matrix2x2_eq(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B) {
    if (!A || !B) {
        return false;
    }

    return (fabsf(A->m00 - B->m00) <= CML_EPSILON && fabsf(A->m10 - B->m10) <= CML_EPSILON && 
            fabsf(A->m01 - B->m01) <= CML_EPSILON && fabsf(A->m11 - B->m11) <= CML_EPSILON)? true : false;
}



/**
 * @brief Returns a debug message comparing the input CML_Matrix2x2s.
 *
 * @param expected The expected matrix.
 * @param got      The result matrix.
 * 
 * @return A string containing the debug message.
 */
CAMEL_STATIC CAMEL_API char *cml_matrix2x2_debug(const CML_Matrix2x2 *expected, const CML_Matrix2x2 *got) {
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



/**
 * @brief Adds two CML_Matrix3x3 and writes the result to the out CML_Matrix3x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_add(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B, CML_Matrix3x3 *out) {
    out->m00 = A->m00 + B->m00;
    out->m10 = A->m10 + B->m10;
    out->m20 = A->m20 + B->m20;
    out->m01 = A->m01 + B->m01;
    out->m11 = A->m11 + B->m11;
    out->m21 = A->m21 + B->m21;
    out->m02 = A->m02 + B->m02;
    out->m12 = A->m12 + B->m12;
    out->m22 = A->m22 + B->m22;
}


/**
 * @brief Subtracts two CML_Matrix3x3 and writes the result to the out 
 *        CML_Matrix3x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_sub(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B, CML_Matrix3x3 *out) {
    out->m00 = A->m00 - B->m00;
    out->m10 = A->m10 - B->m10;
    out->m20 = A->m20 - B->m20;
    out->m01 = A->m01 - B->m01;
    out->m11 = A->m11 - B->m11;
    out->m21 = A->m21 - B->m21;
    out->m02 = A->m02 - B->m02;
    out->m12 = A->m12 - B->m12;
    out->m22 = A->m22 - B->m22;
}


/**
 * @brief Multiplies a CML_Matrix3x3 by a scalar, and writes the result to the 
 *        out CML_Matrix3x3.
 * 
 * @param A   The matrix operand.
 * @param t   The scalar.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_scale(const CML_Matrix3x3 *A, f32 t, CML_Matrix3x3 *out) {
    out->m00 = A->m00 * t;
    out->m10 = A->m10 * t;
    out->m20 = A->m20 * t;
    out->m01 = A->m01 * t;
    out->m11 = A->m11 * t;
    out->m21 = A->m21 * t;
    out->m02 = A->m02 * t;
    out->m12 = A->m12 * t;
    out->m22 = A->m22 * t;
}


/**
 * @brief Multiplies two CML_Matrix3x3, and writes the result to the out 
 *        CML_Matrix3x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_mult(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B, CML_Matrix3x3 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22;

    f32 b00 = B->m00, b10 = B->m10, b20 = B->m20;
    f32 b01 = B->m01, b11 = B->m11, b21 = B->m21;
    f32 b02 = B->m02, b12 = B->m12, b22 = B->m22;

    out->m00 = a00*b00 + a01*b10 + a02*b20;
    out->m10 = a10*b00 + a11*b10 + a12*b20;
    out->m20 = a20*b00 + a21*b10 + a22*b20;
    out->m01 = a00*b01 + a01*b11 + a02*b21;
    out->m11 = a10*b01 + a11*b11 + a12*b21;
    out->m21 = a20*b01 + a21*b11 + a22*b21;
    out->m02 = a00*b02 + a01*b12 + a02*b22;
    out->m12 = a10*b02 + a11*b12 + a12*b22;
    out->m22 = a20*b02 + a21*b12 + a22*b22;
}


/**
 * @brief Multiplies a CML_Matrix3x3 by a CML_Matrix3x2, and writes the result 
 *        to the out CML_Matrix3x2.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_mult_matrix3x2(const CML_Matrix3x3 *A, const CML_Matrix3x2 *B, CML_Matrix3x2 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22;

    f32 b00 = B->m00, b10 = B->m10, b20 = B->m20;
    f32 b01 = B->m01, b11 = B->m11, b21 = B->m21;

    out->m00 = a00*b00 + a01*b10 + a02*b20;
    out->m10 = a10*b00 + a11*b10 + a12*b20;
    out->m20 = a20*b00 + a21*b10 + a22*b20;
    out->m01 = a00*b01 + a01*b11 + a02*b21;
    out->m11 = a10*b01 + a11*b11 + a12*b21;
    out->m21 = a20*b01 + a21*b11 + a22*b21;
}


/**
 * @brief Multiplies a CML_Matrix3x3 by a CML_Matrix3x4, and writes the result 
 *        to the out CML_Matrix3x4.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_mult_matrix3x4(const CML_Matrix3x3 *A, const CML_Matrix3x4 *B, CML_Matrix3x4 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22;

    f32 b00 = B->m00, b10 = B->m10, b20 = B->m20;
    f32 b01 = B->m01, b11 = B->m11, b21 = B->m21;
    f32 b02 = B->m02, b12 = B->m12, b22 = B->m22;
    f32 b03 = B->m03, b13 = B->m13, b23 = B->m23;

    out->m00 = a00*b00 + a01*b10 + a02*b20;
    out->m10 = a10*b00 + a11*b10 + a12*b20;
    out->m20 = a20*b00 + a21*b10 + a22*b20;
    out->m01 = a00*b01 + a01*b11 + a02*b21;
    out->m11 = a10*b01 + a11*b11 + a12*b21;
    out->m21 = a20*b01 + a21*b11 + a22*b21;
    out->m02 = a00*b02 + a01*b12 + a02*b22;
    out->m12 = a10*b02 + a11*b12 + a12*b22;
    out->m22 = a20*b02 + a21*b12 + a22*b22;
    out->m03 = a00*b03 + a01*b13 + a02*b23;
    out->m13 = a10*b03 + a11*b13 + a12*b23;
    out->m23 = a20*b03 + a21*b13 + a22*b23;
}


/**
 * @brief Multiplies a CML_Matrix3x3 by a CML_Vector3, and writes the result to 
 *        the out CML_Vector3.
 * 
 * @param A   The left matrix operand.
 * @param v   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_mult_vector3(const CML_Matrix3x3 *A, const CML_Vector3 *v, CML_Vector3 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22;

    f32 v0 = v->x, v1 = v->y, v2 = v->z;

    out->x = a00*v0 + a01*v1 + a02*v2;
    out->y = a10*v0 + a11*v1 + a12*v2;
    out->z = a20*v0 + a21*v1 + a22*v2;
}


/**
 * @brief Multiplies a CML_Vector3 by a CML_Matrix3x3, and writes the result to 
 *        the out CML_Vector3.
 * 
 * @param v   The left transposed vector operand.
 * @param A   The right matrix operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_vector3_mult_matrix3x3(const CML_Vector3 *v, const CML_Matrix3x3 *A, CML_Vector3 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22;

    f32 v0 = v->x, v1 = v->y, v2 = v->z;

    out->x = a00*v0 + a10*v1 + a20*v2;
    out->y = a01*v0 + a11*v1 + a21*v2;
    out->z = a02*v0 + a12*v1 + a22*v2;
}


/**
 * @brief Calculates the determinant of a CML_Matrix3x3.
 * 
 * @param A The matrix operand.
 * 
 * @return The determinant of the matrix.
 */
CAMEL_STATIC CAMEL_API f32 cml_matrix3x3_det(const CML_Matrix3x3 *A) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22;

    return a00*(a11*a22 - a12*a21) - a01*(a10*a22 - a12*a20) + a02*(a10*a21 - a11*a20);
}


/**
 * @brief Calculates the inverse of a CML_Matrix3x3 and writes the result to
 *        the out CML_Matrix3x3.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return Success or error code if the matrix is invertible.
 */
CAMEL_STATIC CAMEL_API CML_Status cml_matrix3x3_inv(const CML_Matrix3x3 *A, CML_Matrix3x3 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22;

    f32 det = a00*(a11*a22 - a12*a21) - a01*(a10*a22 - a12*a20) + a02*(a10*a21 - a11*a20);

    if (det == 0.0f) {
        return CML_ERR_SINGULAR_MATRIX;
    }

    det = 1/det;

    out->m00 = (a11*a22 - a12*a21)*det;
    out->m10 = -(a10*a22 - a12*a20)*det;
    out->m20 = (a10*a21 - a11*a20)*det;
    out->m01 = -(a01*a22 - a02*a21)*det;
    out->m11 = (a00*a22 - a02*a20)*det;
    out->m21 = -(a00*a21 - a01*a20)*det;
    out->m02 = (a01*a12 - a02*a11)*det;
    out->m12 = -(a00*a12 - a02*a10)*det;
    out->m22 = (a00*a11 - a01*a10)*det;

    return CML_SUCCESS;
}


/**
 * @brief Calculates the transpose of a CML_Matrix3x3 and writes the result to
 *        the out CML_Matrix3x3.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_transpose(const CML_Matrix3x3 *A, CML_Matrix3x3 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22;

    out->m00 = a00;
    out->m10 = a01;
    out->m20 = a02;
    out->m01 = a10;
    out->m11 = a11;
    out->m21 = a12;
    out->m02 = a20;
    out->m12 = a21;
    out->m22 = a22;
}


/**
 * @brief Calculates the trace of a CML_Matrix3x3.
 * 
 * @param A The matrix operand.
 * 
 * @return The trace of the matrix.
 */
CAMEL_STATIC CAMEL_API f32 cml_matrix3x3_trace(const CML_Matrix3x3 *A) {
    return A->m00 + A->m11 + A->m22;
}


/**
 * @brief Generates a scale matrix and writes the result to the out
 *        CML_Matrix3x3.
 * 
 * @param x   The x scale.
 * @param y   The y scale.
 * @param z   The z scale.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_gen_scale(f32 x, f32 y, f32 z, CML_Matrix3x3 *out) {
    out->m00 = x;
    out->m10 = 0.0f;
    out->m20 = 0.0f;
    out->m01 = 0.0f;
    out->m11 = y;
    out->m21 = 0.0f;
    out->m02 = 0.0f;
    out->m12 = 0.0f;
    out->m22 = z;
}


/**
 * @brief Generates the inverse of a scale matrix and writes the result to the
 *        out CML_Matrix3x3.
 * 
 * @param scale The input scale matrix.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_gen_invscale(const CML_Matrix3x3 *scale, CML_Matrix3x3 *out) {
    out->m00 = 1.0f/scale->m00;
    out->m10 = 0.0f;
    out->m20 = 0.0f;
    out->m01 = 0.0f;
    out->m11 = 1.0f/scale->m11;
    out->m21 = 0.0f;
    out->m02 = 0.0f;
    out->m12 = 0.0f;
    out->m22 = 1.0f/scale->m22;
}


/**
 * @brief Generates the shear matrix along the x axis and writes the result to
 *        the out CML_Matrix3x3.
 * 
 * @param y   The y shear.
 * @param z   The z shear.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_gen_shearx(f32 y, f32 z, CML_Matrix3x3 *out) {
    out->m00 = 1.0f;
    out->m10 = 0.0f;
    out->m20 = 0.0f;
    out->m01 = y;
    out->m11 = 1.0f;
    out->m21 = 0.0f;
    out->m02 = z;
    out->m12 = 0.0f;
    out->m22 = 1.0f;
}


/**
 * @brief Generates the shear matrix along the y axis and writes the result to
 *        the out CML_Matrix3x3.
 * 
 * @param x   The x shear.
 * @param z   The z shear.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_gen_sheary(f32 x, f32 z, CML_Matrix3x3 *out) {
    out->m00 = 1.0f;
    out->m10 = x;
    out->m20 = 0.0f;
    out->m01 = 0.0f;
    out->m11 = 1.0f;
    out->m21 = 0.0f;
    out->m02 = 0.0f;
    out->m12 = z;
    out->m22 = 1.0f;
}


/**
 * @brief Generates the shear matrix along the z axis and writes the result to
 *        the out CML_Matrix3x3.
 * 
 * @param x   The x shear.
 * @param y   The y shear.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_gen_shearz(f32 x, f32 y, CML_Matrix3x3 *out) {
    out->m00 = 1.0f;
    out->m10 = 0.0f;
    out->m20 = x;
    out->m01 = 0.0f;
    out->m11 = 1.0f;
    out->m21 = y;
    out->m02 = 0.0f;
    out->m12 = 0.0f;
    out->m22 = 1.0f;
}


/**
 * @brief Generates the inverse of a shear matrix and writes the result to the
 *        out CML_Matrix3x3.
 * 
 * @param shear The input shear matrix.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_gen_invshear(const CML_Matrix3x3 *shear, CML_Matrix3x3 *out) {
    out->m00 = 1.0f;
    out->m10 = -shear->m10;
    out->m20 = -shear->m20;
    out->m01 = -shear->m01;
    out->m11 = 1.0f;
    out->m21 = -shear->m21;
    out->m02 = -shear->m02;
    out->m12 = -shear->m12;
    out->m22 = 1.0f;
}


/**
 * @brief Generates the left-handed rotation matrix (clockwise) along the x 
 *        axis and writes the result to the out CML_Matrix3x3.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_genlh_rotationx(f32 angle, CML_Matrix3x3 *out) {
    f32 c = cosf(-angle);
    f32 s = sinf(-angle);

    out->m00 = 1.0f;
    out->m10 = 0.0f;
    out->m20 = 0.0f;
    out->m01 = 0.0f;
    out->m11 = c;
    out->m21 = s;
    out->m02 = 0.0f;
    out->m12 = -s;
    out->m22 = c;
}


/**
 * @brief Generates the left-handed rotation matrix (clockwise) along the y 
 *        axis and writes the result to the out CML_Matrix3x3.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_genlh_rotationy(f32 angle, CML_Matrix3x3 *out) {
    f32 c = cosf(-angle);
    f32 s = sinf(-angle);

    out->m00 = c;
    out->m10 = 0.0f;
    out->m20 = -s;
    out->m01 = 0.0f;
    out->m11 = 1.0f;
    out->m21 = 0.0f;
    out->m02 = s;
    out->m12 = 0.0f;
    out->m22 = c;
}


/**
 * @brief Generates the left-handed rotation matrix (clockwise) along the z 
 *        axis and writes the result to the out CML_Matrix3x3.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_genlh_rotationz(f32 angle, CML_Matrix3x3 *out) {
    f32 c = cosf(-angle);
    f32 s = sinf(-angle);

    out->m00 = c;
    out->m10 = s;
    out->m20 = 0.0f;
    out->m01 = -s;
    out->m11 = c;
    out->m21 = 0.0f;
    out->m02 = 0.0f;
    out->m12 = 0.0f;
    out->m22 = 1.0f;
}


/**
 * @brief Generates the left-handed rotation matrix (clockwise) along an 
 *        arbitrary axis and writes the result to the out CML_Matrix3x3.
 * 
 * @param angle The angle of rotation in radians.
 * @param axis  The axis of rotation.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_genlh_rotation(f32 angle, const CML_Vector3 *axis, CML_Matrix3x3 *out) {
    f32 c = cosf(angle);
    f32 s = sinf(angle);
    f32 t = 1.0f - c;

    f32 mag = 1/sqrtf(axis->x*axis->x + axis->y*axis->y + axis->z*axis->z);
    f32 x = axis->x * mag;
    f32 y = axis->y * mag;
    f32 z = axis->z * mag;

    out->m00 = t*x*x + c;
    out->m10 = t*x*y + s*z;
    out->m20 = t*x*z - s*y;
    out->m01 = t*x*y - s*z;
    out->m11 = t*y*y + c;
    out->m21 = t*y*z + s*x;
    out->m02 = t*x*z + s*y;
    out->m12 = t*y*z - s*x;
    out->m22 = t*z*z + c;
}


/**
 * @brief Generates the right-handed rotation matrix (counter clockwise) along 
 *        the x axis and writes the result to the out CML_Matrix3x3.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_genrh_rotationx(f32 angle, CML_Matrix3x3 *out) {
    f32 c = cosf(angle);
    f32 s = sinf(angle);

    out->m00 = 1.0f;
    out->m10 = 0.0f;
    out->m20 = 0.0f;
    out->m01 = 0.0f;
    out->m11 = c;
    out->m21 = s;
    out->m02 = 0.0f;
    out->m12 = -s;
    out->m22 = c;
}


/**
 * @brief Generates the right-handed rotation matrix (counter clockwise) along 
 *        the y axis and writes the result to the out CML_Matrix3x3.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_genrh_rotationy(f32 angle, CML_Matrix3x3 *out) {
    f32 c = cosf(angle);
    f32 s = sinf(angle);

    out->m00 = c;
    out->m10 = 0.0f;
    out->m20 = -s;
    out->m01 = 0.0f;
    out->m11 = 1.0f;
    out->m21 = 0.0f;
    out->m02 = s;
    out->m12 = 0.0f;
    out->m22 = c;
}


/**
 * @brief Generates the right-handed rotation matrix (counter clockwise) along 
 *        the z axis and writes the result to the out CML_Matrix3x3.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_genrh_rotationz(f32 angle, CML_Matrix3x3 *out) {
    f32 c = cosf(angle);
    f32 s = sinf(angle);

    out->m00 = c;
    out->m10 = s;
    out->m20 = 0.0f;
    out->m01 = -s;
    out->m11 = c;
    out->m21 = 0.0f;
    out->m02 = 0.0f;
    out->m12 = 0.0f;
    out->m22 = 1.0f;
}


/**
 * @brief Generates the right-handed rotation matrix (counter clockwise) along 
 *        an arbitrary axis and writes the result to the out CML_Matrix3x3.
 * 
 * @param angle The angle of rotation in radians.
 * @param axis  The axis of rotation.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_genrh_rotation(f32 angle, const CML_Vector3 *axis, CML_Matrix3x3 *out) {
    f32 c = cosf(angle);
    f32 s = sinf(angle);
    f32 t = 1.0f - c;

    f32 mag = 1/sqrtf(axis->x*axis->x + axis->y*axis->y + axis->z*axis->z);
    f32 x = axis->x * mag;
    f32 y = axis->y * mag;
    f32 z = axis->z * mag;

    out->m00 = t*x*x + c;
    out->m10 = t*x*y + s*z;
    out->m20 = t*x*z - s*y;
    out->m01 = t*x*y - s*z;
    out->m11 = t*y*y + c;
    out->m21 = t*y*z + s*x;
    out->m02 = t*x*z + s*y;
    out->m12 = t*y*z - s*x;
    out->m22 = t*z*z + c;
}


/**
 * @brief Generates the inverse of a rotation matrix and writes the result to
 *        the out CML_Matrix3x3.
 * 
 * @param rotation The input rotation matrix.
 * @param out      The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x3_gen_invrotation(const CML_Matrix3x3 *rotation, CML_Matrix3x3 *out) {
    f32 r00 = rotation->m00, r10 = rotation->m10, r20 = rotation->m20;
    f32 r01 = rotation->m01, r11 = rotation->m11, r21 = rotation->m21;
    f32 r02 = rotation->m02, r12 = rotation->m12, r22 = rotation->m22;

    out->m00 = r00;
    out->m10 = r01;
    out->m20 = r02;
    out->m01 = r10;
    out->m11 = r11;
    out->m21 = r12;
    out->m02 = r20;
    out->m12 = r21;
    out->m22 = r22;
}


/**
 * @brief Compares two CML_Matrix3x3s for equality.
 * 
 * @param A The left matrix operand.
 * @param B The right matrix operand.
 * 
 * @return Boolean value indicating whether the matrices are equal.
 */
CAMEL_STATIC CAMEL_API b8 cml_matrix3x3_eq(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B) {
    if (!A || !B) {
        return false;
    }

    return (fabsf(A->m00 - B->m00) <= CML_EPSILON && fabsf(A->m10 - B->m10) <= CML_EPSILON && fabsf(A->m20 - B->m20) <= CML_EPSILON && 
            fabsf(A->m01 - B->m01) <= CML_EPSILON && fabsf(A->m11 - B->m11) <= CML_EPSILON && fabsf(A->m21 - B->m21) <= CML_EPSILON && 
            fabsf(A->m02 - B->m02) <= CML_EPSILON && fabsf(A->m12 - B->m12) <= CML_EPSILON && fabsf(A->m22 - B->m22) <= CML_EPSILON)? true : false;
}


/**
 * @brief Returns a debug message comparing the input CML_Matrix3x3s.
 *
 * @param expected The expected matrix.
 * @param got      The result matrix.
 * 
 * @return A string containing the debug message.
 */
CAMEL_STATIC CAMEL_API char *cml_matrix3x3_debug(const CML_Matrix3x3 *expected, const CML_Matrix3x3 *got) {
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



/**
 * @brief Adds two CML_Matrix4x4 and writes the result to the out CML_Matrix4x4.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_add(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B, CML_Matrix4x4 *out) {
    out->m00 = A->m00 + B->m00;
    out->m10 = A->m10 + B->m10;
    out->m20 = A->m20 + B->m20;
    out->m30 = A->m30 + B->m30;
    out->m01 = A->m01 + B->m01;
    out->m11 = A->m11 + B->m11;
    out->m21 = A->m21 + B->m21;
    out->m31 = A->m31 + B->m31;
    out->m02 = A->m02 + B->m02;
    out->m12 = A->m12 + B->m12;
    out->m22 = A->m22 + B->m22;
    out->m32 = A->m32 + B->m32;
    out->m03 = A->m03 + B->m03;
    out->m13 = A->m13 + B->m13;
    out->m23 = A->m23 + B->m23;
    out->m33 = A->m33 + B->m33;
}


/**
 * @brief Subtracts two CML_Matrix4x4 and writes the result to the out 
 *        CML_Matrix4x4.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_sub(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B, CML_Matrix4x4 *out) {
    out->m00 = A->m00 - B->m00;
    out->m10 = A->m10 - B->m10;
    out->m20 = A->m20 - B->m20;
    out->m30 = A->m30 - B->m30;
    out->m01 = A->m01 - B->m01;
    out->m11 = A->m11 - B->m11;
    out->m21 = A->m21 - B->m21;
    out->m31 = A->m31 - B->m31;
    out->m02 = A->m02 - B->m02;
    out->m12 = A->m12 - B->m12;
    out->m22 = A->m22 - B->m22;
    out->m32 = A->m32 - B->m32;
    out->m03 = A->m03 - B->m03;
    out->m13 = A->m13 - B->m13;
    out->m23 = A->m23 - B->m23;
    out->m33 = A->m33 - B->m33;
}


/**
 * @brief Multiplies a CML_Matrix4x4 by a scalar, and writes the result to the 
 *        out CML_Matrix4x4.
 * 
 * @param A   The matrix operand.
 * @param t   The scalar.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_scale(const CML_Matrix4x4 *A, f32 t, CML_Matrix4x4 *out) {
    out->m00 = A->m00 * t;
    out->m10 = A->m10 * t;
    out->m20 = A->m20 * t;
    out->m30 = A->m30 * t;
    out->m01 = A->m01 * t;
    out->m11 = A->m11 * t;
    out->m21 = A->m21 * t;
    out->m31 = A->m31 * t;
    out->m02 = A->m02 * t;
    out->m12 = A->m12 * t;
    out->m22 = A->m22 * t;
    out->m32 = A->m32 * t;
    out->m03 = A->m03 * t;
    out->m13 = A->m13 * t;
    out->m23 = A->m23 * t;
    out->m33 = A->m33 * t;
}


/**
 * @brief Multiplies two CML_Matrix4x4, and writes the result to the out 
 *        CML_Matrix4x4.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_mult(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B, CML_Matrix4x4 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22, a32 = A->m32;
    f32 a03 = A->m03, a13 = A->m13, a23 = A->m23, a33 = A->m33;

    f32 b00 = B->m00, b10 = B->m10, b20 = B->m20, b30 = B->m30;
    f32 b01 = B->m01, b11 = B->m11, b21 = B->m21, b31 = B->m31;
    f32 b02 = B->m02, b12 = B->m12, b22 = B->m22, b32 = B->m32;
    f32 b03 = B->m03, b13 = B->m13, b23 = B->m23, b33 = B->m33;

    out->m00 = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out->m10 = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out->m20 = a20*b00 + a21*b10 + a22*b20 + a23*b30;
    out->m30 = a30*b00 + a31*b10 + a32*b20 + a33*b30;
    out->m01 = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out->m11 = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out->m21 = a20*b01 + a21*b11 + a22*b21 + a23*b31;
    out->m31 = a30*b01 + a31*b11 + a32*b21 + a33*b31;
    out->m02 = a00*b02 + a01*b12 + a02*b22 + a03*b32;
    out->m12 = a10*b02 + a11*b12 + a12*b22 + a13*b32;
    out->m22 = a20*b02 + a21*b12 + a22*b22 + a23*b32;
    out->m32 = a30*b02 + a31*b12 + a32*b22 + a33*b32;
    out->m03 = a00*b03 + a01*b13 + a02*b23 + a03*b33;
    out->m13 = a10*b03 + a11*b13 + a12*b23 + a13*b33;
    out->m23 = a20*b03 + a21*b13 + a22*b23 + a23*b33;
    out->m33 = a30*b03 + a31*b13 + a32*b23 + a33*b33;
}


/**
 * @brief Multiplies a CML_Matrix4x4 by a CML_Matrix4x2, and writes the result 
 *        to the out CML_Matrix4x2.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_mult_matrix4x2(const CML_Matrix4x4 *A, const CML_Matrix4x2 *B, CML_Matrix4x2 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22, a32 = A->m32;
    f32 a03 = A->m03, a13 = A->m13, a23 = A->m23, a33 = A->m33;

    f32 b00 = B->m00, b10 = B->m10, b20 = B->m20, b30 = B->m30;
    f32 b01 = B->m01, b11 = B->m11, b21 = B->m21, b31 = B->m31;

    out->m00 = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out->m10 = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out->m20 = a20*b00 + a21*b10 + a22*b20 + a23*b30;
    out->m30 = a30*b00 + a31*b10 + a32*b20 + a33*b30;
    out->m01 = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out->m11 = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out->m21 = a20*b01 + a21*b11 + a22*b21 + a23*b31;
    out->m31 = a30*b01 + a31*b11 + a32*b21 + a33*b31;
}


/**
 * @brief Multiplies a CML_Matrix4x4 by a CML_Matrix4x3, and writes the result 
 *        to the out CML_Matrix4x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_mult_matrix4x3(const CML_Matrix4x4 *A, const CML_Matrix4x3 *B, CML_Matrix4x3 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22, a32 = A->m32;
    f32 a03 = A->m03, a13 = A->m13, a23 = A->m23, a33 = A->m33;

    f32 b00 = B->m00, b10 = B->m10, b20 = B->m20, b30 = B->m30;
    f32 b01 = B->m01, b11 = B->m11, b21 = B->m21, b31 = B->m31;
    f32 b02 = B->m02, b12 = B->m12, b22 = B->m22, b32 = B->m32;

    out->m00 = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out->m10 = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out->m20 = a20*b00 + a21*b10 + a22*b20 + a23*b30;
    out->m30 = a30*b00 + a31*b10 + a32*b20 + a33*b30;
    out->m01 = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out->m11 = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out->m21 = a20*b01 + a21*b11 + a22*b21 + a23*b31;
    out->m31 = a30*b01 + a31*b11 + a32*b21 + a33*b31;
    out->m02 = a00*b02 + a01*b12 + a02*b22 + a03*b32;
    out->m12 = a10*b02 + a11*b12 + a12*b22 + a13*b32;
    out->m22 = a20*b02 + a21*b12 + a22*b22 + a23*b32;
    out->m32 = a30*b02 + a31*b12 + a32*b22 + a33*b32;
}


/**
 * @brief Multiplies a CML_Matrix4x4 by a CML_Vector4, and writes the result to 
 *        the out CML_Vector4.
 * 
 * @param A   The left matrix operand.
 * @param v   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_mult_vector4(const CML_Matrix4x4 *A, const CML_Vector4 *v, CML_Vector4 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22, a32 = A->m32;
    f32 a03 = A->m03, a13 = A->m13, a23 = A->m23, a33 = A->m33;

    f32 v0 = v->x, v1 = v->y, v2 = v->z, v3 = v->w;

    out->x = a00*v0 + a01*v1 + a02*v2 + a03*v3;
    out->y = a10*v0 + a11*v1 + a12*v2 + a13*v3;
    out->z = a20*v0 + a21*v1 + a22*v2 + a23*v3;
    out->w = a30*v0 + a31*v1 + a32*v2 + a33*v3;
}


/**
 * @brief Multiplies a CML_Vector4 by a CML_Matrix4x4, and writes the result to 
 *        the out CML_Vector4.
 * 
 * @param v   The left transposed vector operand.
 * @param A   The right matrix operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_vector4_mult_matrix4x4(const CML_Vector4 *v, const CML_Matrix4x4 *A, CML_Vector4 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22, a32 = A->m32;
    f32 a03 = A->m03, a13 = A->m13, a23 = A->m23, a33 = A->m33;

    f32 v0 = v->x, v1 = v->y, v2 = v->z, v3 = v->w;

    out->x = a00*v0 + a10*v1 + a20*v2 + a30*v3;
    out->y = a01*v0 + a11*v1 + a21*v2 + a31*v3;
    out->z = a02*v0 + a12*v1 + a22*v2 + a32*v3;
    out->w = a03*v0 + a13*v1 + a23*v2 + a33*v3;
}


/**
 * @brief Calculates the determinant of a CML_Matrix4x4.
 * 
 * @param A The matrix operand.
 * 
 * @return The determinant of the matrix.
 */
CAMEL_STATIC CAMEL_API f32 cml_matrix4x4_det(const CML_Matrix4x4 *A) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22, a32 = A->m32;
    f32 a03 = A->m03, a13 = A->m13, a23 = A->m23, a33 = A->m33;

    return a03*a12*a21*a30 - a02*a13*a21*a30 - a03*a11*a22*a30 + a01*a13*a22*a30+
           a02*a11*a23*a30 - a01*a12*a23*a30 - a03*a12*a20*a31 + a02*a13*a20*a31+
           a03*a10*a22*a31 - a00*a13*a22*a31 - a02*a10*a23*a31 + a00*a12*a23*a31+
           a03*a11*a20*a32 - a01*a13*a20*a32 - a03*a10*a21*a32 + a00*a13*a21*a32+
           a01*a10*a23*a32 - a00*a11*a23*a32 - a02*a11*a20*a33 + a01*a12*a20*a33+
           a02*a10*a21*a33 - a00*a12*a21*a33 - a01*a10*a22*a33 + a00*a11*a22*a33;
}


/**
 * @brief Calculates the inverse of a CML_Matrix4x4 and writes the result to
 *        the out CML_Matrix4x4.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return Success or error code if the matrix is invertible.
 */
CAMEL_STATIC CAMEL_API CML_Status cml_matrix4x4_inv(const CML_Matrix4x4 *A, CML_Matrix4x4 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22, a32 = A->m32;
    f32 a03 = A->m03, a13 = A->m13, a23 = A->m23, a33 = A->m33;

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
    out->m10 = (a13*a22*a30 - a12*a23*a30 - a13*a20*a32 + a10*a23*a32 + a12*a20*a33 - a10*a22*a33)*det;
    out->m20 = (a11*a23*a30 - a13*a21*a30 + a13*a20*a31 - a10*a23*a31 - a11*a20*a33 + a10*a21*a33)*det;
    out->m30 = (a12*a21*a30 - a11*a22*a30 - a12*a20*a31 + a10*a22*a31 + a11*a20*a32 - a10*a21*a32)*det;
    out->m01 = (a03*a22*a31 - a02*a23*a31 - a03*a21*a32 + a01*a23*a32 + a02*a21*a33 - a01*a22*a33)*det;
    out->m11 = (a02*a23*a30 - a03*a22*a30 + a03*a20*a32 - a00*a23*a32 - a02*a20*a33 + a00*a22*a33)*det;
    out->m21 = (a03*a21*a30 - a01*a23*a30 - a03*a20*a31 + a00*a23*a31 + a01*a20*a33 - a00*a21*a33)*det;
    out->m31 = (a01*a22*a30 - a02*a21*a30 + a02*a20*a31 - a00*a22*a31 - a01*a20*a32 + a00*a21*a32)*det;
    out->m02 = (a02*a13*a31 - a03*a12*a31 + a03*a11*a32 - a01*a13*a32 - a02*a11*a33 + a01*a12*a33)*det;
    out->m12 = (a03*a12*a30 - a02*a13*a30 - a03*a10*a32 + a00*a13*a32 + a02*a10*a33 - a00*a12*a33)*det;
    out->m22 = (a01*a13*a30 - a03*a11*a30 + a03*a10*a31 - a00*a13*a31 - a01*a10*a33 + a00*a11*a33)*det;
    out->m32 = (a02*a11*a30 - a01*a12*a30 - a02*a10*a31 + a00*a12*a31 + a01*a10*a32 - a00*a11*a32)*det;
    out->m03 = (a03*a12*a21 - a02*a13*a21 - a03*a11*a22 + a01*a13*a22 + a02*a11*a23 - a01*a12*a23)*det;
    out->m13 = (a02*a13*a20 - a03*a12*a20 + a03*a10*a22 - a00*a13*a22 - a02*a10*a23 + a00*a12*a23)*det;
    out->m23 = (a03*a11*a20 - a01*a13*a20 - a03*a10*a21 + a00*a13*a21 + a01*a10*a23 - a00*a11*a23)*det;
    out->m33 = (a01*a12*a20 - a02*a11*a20 + a02*a10*a21 - a00*a12*a21 - a01*a10*a22 + a00*a11*a22)*det;

    return CML_SUCCESS;
}


/**
 * @brief Calculates the transpose of a CML_Matrix4x4 and writes the result to
 *        the out CML_Matrix4x4.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_transpose(const CML_Matrix4x4 *A, CML_Matrix4x4 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22, a32 = A->m32;
    f32 a03 = A->m03, a13 = A->m13, a23 = A->m23, a33 = A->m33;

    out->m00 = a00;
    out->m10 = a01;
    out->m20 = a02;
    out->m30 = a03;
    out->m01 = a10;
    out->m11 = a11;
    out->m21 = a12;
    out->m31 = a13;
    out->m02 = a20;
    out->m12 = a21;
    out->m22 = a22;
    out->m32 = a23;
    out->m03 = a30;
    out->m13 = a31;
    out->m23 = a32;
    out->m33 = a33;
}


/**
 * @brief Calculates the trace of a CML_Matrix4x4.
 * 
 * @param A The matrix operand.
 * 
 * @return The trace of the matrix.
 */
CAMEL_STATIC CAMEL_API f32 cml_matrix4x4_trace(const CML_Matrix4x4 *A) {
    return A->m00 + A->m11 + A->m22 + A->m33;
}


/**
 * @brief Generates a scale matrix and writes the result to the out
 *        CML_Matrix4x4.
 * 
 * @param x   The x scale.
 * @param y   The y scale.
 * @param z   The z scale.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_gen_scale(f32 x, f32 y, f32 z, CML_Matrix4x4 *out) {
    out->m00 = x;
    out->m10 = 0.0f;
    out->m20 = 0.0f;
    out->m30 = 0.0f;
    out->m01 = 0.0f;
    out->m11 = y;
    out->m21 = 0.0f;
    out->m31 = 0.0f;
    out->m02 = 0.0f;
    out->m12 = 0.0f;
    out->m22 = z;
    out->m32 = 0.0f;
    out->m03 = 0.0f;
    out->m13 = 0.0f;
    out->m23 = 0.0f;
    out->m33 = 1.0f;
}


/**
 * @brief Generates the inverse of a scale matrix and writes the result to the
 *        out CML_Matrix4x4.
 * 
 * @param scale The input scale matrix.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_gen_invscale(const CML_Matrix4x4 *scale, CML_Matrix4x4 *out) {
    out->m00 = 1.0f/scale->m00;
    out->m10 = 0.0f;
    out->m20 = 0.0f;
    out->m30 = 0.0f;
    out->m01 = 0.0f;
    out->m11 = 1.0f/scale->m11;
    out->m21 = 0.0f;
    out->m31 = 0.0f;
    out->m02 = 0.0f;
    out->m12 = 0.0f;
    out->m22 = 1.0f/scale->m22;
    out->m32 = 0.0f;
    out->m03 = 0.0f;
    out->m13 = 0.0f;
    out->m23 = 0.0f;
    out->m33 = 1.0f;
}


/**
 * @brief Generates the shear matrix along the x axis and writes the result to
 *        the out CML_Matrix4x4.
 * 
 * @param y   The y shear.
 * @param z   The z shear.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_gen_shearx(f32 y, f32 z, CML_Matrix4x4 *out) {
    out->m00 = 1.0f;
    out->m10 = 0.0f;
    out->m20 = 0.0f;
    out->m30 = 0.0f;
    out->m01 = y;
    out->m11 = 1.0f;
    out->m21 = 0.0f;
    out->m31 = 0.0f;
    out->m02 = z;
    out->m12 = 0.0f;
    out->m22 = 1.0f;
    out->m32 = 0.0f;
    out->m03 = 0.0f;
    out->m13 = 0.0f;
    out->m23 = 0.0f;
    out->m33 = 1.0f;
}


/**
 * @brief Generates the shear matrix along the y axis and writes the result to
 *        the out CML_Matrix4x4.
 * 
 * @param x   The x shear.
 * @param z   The z shear.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_gen_sheary(f32 x, f32 z, CML_Matrix4x4 *out) {
    out->m00 = 1.0f;
    out->m10 = x;
    out->m20 = 0.0f;
    out->m30 = 0.0f;
    out->m01 = 0.0f;
    out->m11 = 1.0f;
    out->m21 = 0.0f;
    out->m31 = 0.0f;
    out->m02 = 0.0f;
    out->m12 = z;
    out->m22 = 1.0f;
    out->m32 = 0.0f;
    out->m03 = 0.0f;
    out->m13 = 0.0f;
    out->m23 = 0.0f;
    out->m33 = 1.0f;
}


/**
 * @brief Generates the shear matrix along the z axis and writes the result to
 *        the out CML_Matrix4x4.
 * 
 * @param x   The x shear.
 * @param y   The y shear.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_gen_shearz(f32 x, f32 y, CML_Matrix4x4 *out) {
    out->m00 = 1.0f;
    out->m10 = 0.0f;
    out->m20 = x;
    out->m30 = 0.0f;
    out->m01 = 0.0f;
    out->m11 = 1.0f;
    out->m21 = y;
    out->m31 = 0.0f;
    out->m02 = 0.0f;
    out->m12 = 0.0f;
    out->m22 = 1.0f;
    out->m32 = 0.0f;
    out->m03 = 0.0f;
    out->m13 = 0.0f;
    out->m23 = 0.0f;
    out->m33 = 1.0f;
}


/**
 * @brief Generates the inverse of a shear matrix and writes the result to the
 *        out CML_Matrix4x4.
 * 
 * @param shear The input shear matrix.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_gen_invshear(const CML_Matrix4x4 *shear, CML_Matrix4x4 *out) {
    out->m00 = 1.0f;
    out->m10 = -shear->m10;
    out->m20 = -shear->m20;
    out->m30 = 0.0f;
    out->m01 = -shear->m01;
    out->m11 = 1.0f;
    out->m21 = -shear->m21;
    out->m31 = 0.0f;
    out->m02 = -shear->m02;
    out->m12 = -shear->m12;
    out->m22 = 1.0f;
    out->m32 = 0.0f;
    out->m03 = 0.0f;
    out->m13 = 0.0f;
    out->m23 = 0.0f;
    out->m33 = 1.0f;
}


/**
 * @brief Generates a translation matrix and writes the result to the out
 *        CML_Matrix4x4.
 * 
 * @param x   The x translation.
 * @param y   The y translation.
 * @param z   The z translation.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_gen_translation(f32 x, f32 y, f32 z, CML_Matrix4x4 *out) {
    out->m00 = 1.0f;
    out->m10 = 0.0f;
    out->m20 = 0.0f;
    out->m30 = 0.0f;
    out->m01 = 0.0f;
    out->m11 = 1.0f;
    out->m21 = 0.0f;
    out->m31 = 0.0f;
    out->m02 = 0.0f;
    out->m12 = 0.0f;
    out->m22 = 1.0f;
    out->m32 = 0.0f;
    out->m03 = x;
    out->m13 = y;
    out->m23 = z;
    out->m33 = 1.0f;
}


/**
 * @brief Generates the inverse of a translation matrix and writes the result 
 *        to the out CML_Matrix4x4.
 * 
 * @param translation The input translation matrix.
 * @param out         The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_gen_invtranslation(const CML_Matrix4x4 *translation, CML_Matrix4x4 *out) {
    out->m00 = 1.0f;
    out->m10 = 0.0f;
    out->m20 = 0.0f;
    out->m30 = 0.0f;
    out->m01 = 0.0f;
    out->m11 = 1.0f;
    out->m21 = 0.0f;
    out->m31 = 0.0f;
    out->m02 = 0.0f;
    out->m12 = 0.0f;
    out->m22 = 1.0f;
    out->m32 = 0.0f;
    out->m03 = -translation->m03;
    out->m13 = -translation->m13;
    out->m23 = -translation->m23;
    out->m33 = 1.0f;
}


/**
 * @brief Generates the left-handed rotation matrix (clockwise) along the x 
 *        axis and writes the result to the out CML_Matrix4x4.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_genlh_rotationx(f32 angle, CML_Matrix4x4 *out) {
    f32 c = cosf(-angle);
    f32 s = sinf(-angle);

    out->m00 = 1.0f;
    out->m10 = 0.0f;
    out->m20 = 0.0f;
    out->m30 = 0.0f;
    out->m01 = 0.0f;
    out->m11 = c;
    out->m21 = s;
    out->m31 = 0.0f;
    out->m02 = 0.0f;
    out->m12 = -s;
    out->m22 = c;
    out->m32 = 0.0f;
    out->m03 = 0.0f;
    out->m13 = 0.0f;
    out->m23 = 0.0f;
    out->m33 = 1.0f;
}


/**
 * @brief Generates the left-handed rotation matrix (clockwise) along the y 
 *        axis and writes the result to the out CML_Matrix4x4.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_genlh_rotationy(f32 angle, CML_Matrix4x4 *out) {
    f32 c = cosf(-angle);
    f32 s = sinf(-angle);

    out->m00 = c;
    out->m10 = 0.0f;
    out->m20 = -s;
    out->m30 = 0.0f;
    out->m01 = 0.0f;
    out->m11 = 1.0f;
    out->m21 = 0.0f;
    out->m31 = 0.0f;
    out->m02 = s;
    out->m12 = 0.0f;
    out->m22 = c;
    out->m32 = 0.0f;
    out->m03 = 0.0f;
    out->m13 = 0.0f;
    out->m23 = 0.0f;
    out->m33 = 1.0f;
}


/**
 * @brief Generates the left-handed rotation matrix (clockwise) along the z 
 *        axis and writes the result to the out CML_Matrix4x4.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_genlh_rotationz(f32 angle, CML_Matrix4x4 *out) {
    f32 c = cosf(-angle);
    f32 s = sinf(-angle);

    out->m00 = c;
    out->m10 = s;
    out->m20 = 0.0f;
    out->m30 = 0.0f;
    out->m01 = -s;
    out->m11 = c;
    out->m21 = 0.0f;
    out->m31 = 0.0f;
    out->m02 = 0.0f;
    out->m12 = 0.0f;
    out->m22 = 1.0f;
    out->m32 = 0.0f;
    out->m03 = 0.0f;
    out->m13 = 0.0f;
    out->m23 = 0.0f;
    out->m33 = 1.0f;
}


/**
 * @brief Generates the left-handed rotation matrix (clockwise) along an 
 *        arbitrary axis and writes the result to the out CML_Matrix4x4.
 * 
 * @param angle The angle of rotation in radians.
 * @param axis  The axis of rotation.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_genlh_rotation(f32 angle, const CML_Vector3 *axis, CML_Matrix4x4 *out) {
    f32 c = cosf(-angle);
    f32 s = sinf(-angle);
    f32 t = 1.0f - c;

    f32 mag = 1/sqrtf(axis->x*axis->x + axis->y*axis->y + axis->z*axis->z);
    f32 x = axis->x * mag;
    f32 y = axis->y * mag;
    f32 z = axis->z * mag;

    out->m00 = t*x*x + c;
    out->m10 = t*x*y + s*z;
    out->m20 = t*x*z - s*y;
    out->m30 = 0.0f;
    out->m01 = t*x*y - s*z;
    out->m11 = t*y*y + c;
    out->m21 = t*y*z + s*x;
    out->m31 = 0.0f;
    out->m02 = t*x*z + s*y;
    out->m12 = t*y*z - s*x;
    out->m22 = t*z*z + c;
    out->m32 = 0.0f;
    out->m03 = 0.0f;
    out->m13 = 0.0f;
    out->m23 = 0.0f;
    out->m33 = 1.0f;
}


/**
 * @brief Generates the right-handed rotation matrix (counter clockwise) along 
 *        the x axis and writes the result to the out CML_Matrix4x4.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_genrh_rotationx(f32 angle, CML_Matrix4x4 *out) {
    f32 c = cosf(angle);
    f32 s = sinf(angle);

    out->m00 = 1.0f;
    out->m10 = 0.0f;
    out->m20 = 0.0f;
    out->m30 = 0.0f;
    out->m01 = 0.0f;
    out->m11 = c;
    out->m21 = s;
    out->m31 = 0.0f;
    out->m02 = 0.0f;
    out->m12 = -s;
    out->m22 = c;
    out->m32 = 0.0f;
    out->m03 = 0.0f;
    out->m13 = 0.0f;
    out->m23 = 0.0f;
    out->m33 = 1.0f;
}


/**
 * @brief Generates the right-handed rotation matrix (counter clockwise) along 
 *        the y axis and writes the result to the out CML_Matrix4x4.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_genrh_rotationy(f32 angle, CML_Matrix4x4 *out) {
    f32 c = cosf(angle);
    f32 s = sinf(angle);

    out->m00 = c;
    out->m10 = 0.0f;
    out->m20 = -s;
    out->m30 = 0.0f;
    out->m01 = 0.0f;
    out->m11 = 1.0f;
    out->m21 = 0.0f;
    out->m31 = 0.0f;
    out->m02 = s;
    out->m12 = 0.0f;
    out->m22 = c;
    out->m32 = 0.0f;
    out->m03 = 0.0f;
    out->m13 = 0.0f;
    out->m23 = 0.0f;
    out->m33 = 1.0f;
}


/**
 * @brief Generates the right-handed rotation matrix (counter clockwise) along 
 *        the z axis and writes the result to the out CML_Matrix4x4.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_genrh_rotationz(f32 angle, CML_Matrix4x4 *out) {
    f32 c = cosf(angle);
    f32 s = sinf(angle);

    out->m00 = c;
    out->m10 = s;
    out->m20 = 0.0f;
    out->m30 = 0.0f;
    out->m01 = -s;
    out->m11 = c;
    out->m21 = 0.0f;
    out->m31 = 0.0f;
    out->m02 = 0.0f;
    out->m12 = 0.0f;
    out->m22 = 1.0f;
    out->m32 = 0.0f;
    out->m03 = 0.0f;
    out->m13 = 0.0f;
    out->m23 = 0.0f;
    out->m33 = 1.0f;
}


/**
 * @brief Generates the right-handed rotation matrix (counter clockwise) along 
 *        an arbitrary axis and writes the result to the out CML_Matrix4x4.
 * 
 * @param angle The angle of rotation in radians.
 * @param axis  The axis of rotation.
 * @param out   The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_genrh_rotation(f32 angle, const CML_Vector3 *axis, CML_Matrix4x4 *out) {
    f32 c = cosf(angle);
    f32 s = sinf(angle);
    f32 t = 1.0f - c;

    f32 mag = 1/sqrtf(axis->x*axis->x + axis->y*axis->y + axis->z*axis->z);
    f32 x = axis->x * mag;
    f32 y = axis->y * mag;
    f32 z = axis->z * mag;

    out->m00 = t*x*x + c;
    out->m10 = t*x*y + s*z;
    out->m20 = t*x*z - s*y;
    out->m30 = 0.0f;
    out->m01 = t*x*y - s*z;
    out->m11 = t*y*y + c;
    out->m21 = t*y*z + s*x;
    out->m31 = 0.0f;
    out->m02 = t*x*z + s*y;
    out->m12 = t*y*z - s*x;
    out->m22 = t*z*z + c;
    out->m32 = 0.0f;
    out->m03 = 0.0f;
    out->m13 = 0.0f;
    out->m23 = 0.0f;
    out->m33 = 1.0f;
}


/**
 * @brief Generates the inverse of a rotation matrix and writes the result to
 *        the out CML_Matrix4x4.
 * 
 * @param rotation The input rotation matrix.
 * @param out      The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x4_gen_invrotation(const CML_Matrix4x4 *rotation, CML_Matrix4x4 *out) {
    f64 r00 = rotation->m00, r10 = rotation->m10, r20 = rotation->m20, r30 = rotation->m30;
    f64 r01 = rotation->m01, r11 = rotation->m11, r21 = rotation->m21, r31 = rotation->m31;
    f64 r02 = rotation->m02, r12 = rotation->m12, r22 = rotation->m22, r32 = rotation->m32;
    f64 r03 = rotation->m03, r13 = rotation->m13, r23 = rotation->m23, r33 = rotation->m33;

    out->m00 = r00;
    out->m10 = r01;
    out->m20 = r02;
    out->m30 = r03;
    out->m01 = r10;
    out->m11 = r11;
    out->m21 = r12;
    out->m31 = r13;
    out->m02 = r20;
    out->m12 = r21;
    out->m22 = r22;
    out->m32 = r23;
    out->m03 = r30;
    out->m13 = r31;
    out->m23 = r32;
    out->m33 = r33;
}


/**
 * @brief Compares two CML_Matrix4x4s for equality.
 * 
 * @param A The left matrix operand.
 * @param B The right matrix operand.
 * 
 * @return Boolean value indicating whether the matrices are equal.
 */
CAMEL_STATIC CAMEL_API b8 cml_matrix4x4_eq(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B) {
    if (!A || !B) {
        return false;
    }

    return (fabsf(A->m00 - B->m00) <= CML_EPSILON && fabsf(A->m10 - B->m10) <= CML_EPSILON && 
            fabsf(A->m20 - B->m20) <= CML_EPSILON && fabsf(A->m30 - B->m30) <= CML_EPSILON && 
            fabsf(A->m01 - B->m01) <= CML_EPSILON && fabsf(A->m11 - B->m11) <= CML_EPSILON && 
            fabsf(A->m21 - B->m21) <= CML_EPSILON && fabsf(A->m31 - B->m31) <= CML_EPSILON && 
            fabsf(A->m02 - B->m02) <= CML_EPSILON && fabsf(A->m12 - B->m12) <= CML_EPSILON && 
            fabsf(A->m22 - B->m22) <= CML_EPSILON && fabsf(A->m32 - B->m32) <= CML_EPSILON && 
            fabsf(A->m03 - B->m03) <= CML_EPSILON && fabsf(A->m13 - B->m13) <= CML_EPSILON && 
            fabsf(A->m23 - B->m23) <= CML_EPSILON && fabsf(A->m33 - B->m33) <= CML_EPSILON)? true : false;
}


/**
 * @brief Returns a debug message comparing the input CML_Matrix4x4s.
 *
 * @param expected The expected matrix.
 * @param got      The result matrix.
 * 
 * @return A string containing the debug message.
 */
CAMEL_STATIC CAMEL_API char *cml_matrix4x4_debug(const CML_Matrix4x4 *expected, const CML_Matrix4x4 *got) {
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



/**
 * @brief Adds two CML_Matrix2x3 and writes the result to the out CML_Matrix2x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x3_add(const CML_Matrix2x3 *A, const CML_Matrix2x3 *B, CML_Matrix2x3 *out) {
    out->m00 = A->m00 + B->m00;
    out->m10 = A->m10 + B->m10;
    out->m01 = A->m01 + B->m01;
    out->m11 = A->m11 + B->m11;
    out->m02 = A->m02 + B->m02;
    out->m12 = A->m12 + B->m12;
}


/**
 * @brief Subtracts two CML_Matrix2x3 and writes the result to the out 
 *        CML_Matrix2x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x3_sub(const CML_Matrix2x3 *A, const CML_Matrix2x3 *B, CML_Matrix2x3 *out) {
    out->m00 = A->m00 - B->m00;
    out->m10 = A->m10 - B->m10;
    out->m01 = A->m01 - B->m01;
    out->m11 = A->m11 - B->m11;
    out->m02 = A->m02 - B->m02;
    out->m12 = A->m12 - B->m12;
}


/**
 * @brief Multiplies a CML_Matrix2x3 by a scalar, and writes the result to the 
 *        out CML_Matrix2x3.
 * 
 * @param A   The matrix operand.
 * @param t   The scalar.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x3_scale(const CML_Matrix2x3 *A, f32 t, CML_Matrix2x3 *out) {
    out->m00 = A->m00 * t;
    out->m10 = A->m10 * t;
    out->m01 = A->m01 * t;
    out->m11 = A->m11 * t;
    out->m02 = A->m02 * t;
    out->m12 = A->m12 * t;
}


/**
 * @brief Multiplies a CML_Matrix2x3 by a CML_Matrix3x2, and writes the result 
 *        to the out CML_Matrix2x2.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x3_mult_matrix3x2(const CML_Matrix2x3 *A, const CML_Matrix3x2 *B, CML_Matrix2x2 *out) {
    f32 a00 = A->m00, a10 = A->m10;
    f32 a01 = A->m01, a11 = A->m11;
    f32 a02 = A->m02, a12 = A->m12;

    f32 b00 = B->m00, b10 = B->m10, b20 = B->m20;
    f32 b01 = B->m01, b11 = B->m11, b21 = B->m21;

    out->m00 = a00*b00 + a01*b10 + a02*b20;
    out->m10 = a10*b00 + a11*b10 + a12*b20;
    out->m01 = a00*b01 + a01*b11 + a02*b21;
    out->m11 = a10*b01 + a11*b11 + a12*b21;
}


/**
 * @brief Multiplies a CML_Matrix2x3 by a CML_Matrix3x3, and writes the result 
 *        to the out CML_Matrix2x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x3_mult_matrix3x3(const CML_Matrix2x3 *A, const CML_Matrix3x3 *B, CML_Matrix2x3 *out) {
    f32 a00 = A->m00, a10 = A->m10;
    f32 a01 = A->m01, a11 = A->m11;
    f32 a02 = A->m02, a12 = A->m12;

    f32 b00 = B->m00, b10 = B->m10, b20 = B->m20;
    f32 b01 = B->m01, b11 = B->m11, b21 = B->m21;
    f32 b02 = B->m02, b12 = B->m12, b22 = B->m22;

    out->m00 = a00*b00 + a01*b10 + a02*b20;
    out->m10 = a10*b00 + a11*b10 + a12*b20;
    out->m01 = a00*b01 + a01*b11 + a02*b21;
    out->m11 = a10*b01 + a11*b11 + a12*b21;
    out->m02 = a00*b02 + a01*b12 + a02*b22;
    out->m12 = a10*b02 + a11*b12 + a12*b22;
}


/**
 * @brief Multiplies a CML_Matrix2x3 by a CML_Matrix3x4, and writes the result 
 *        to the out CML_Matrix2x4.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x3_mult_matrix3x4(const CML_Matrix2x3 *A, const CML_Matrix3x4 *B, CML_Matrix2x4 *out) {
    f32 a00 = A->m00, a10 = A->m10;
    f32 a01 = A->m01, a11 = A->m11;
    f32 a02 = A->m02, a12 = A->m12;

    f32 b00 = B->m00, b10 = B->m10, b20 = B->m20;
    f32 b01 = B->m01, b11 = B->m11, b21 = B->m21;
    f32 b02 = B->m02, b12 = B->m12, b22 = B->m22;
    f32 b03 = B->m03, b13 = B->m13, b23 = B->m23;

    out->m00 = a00*b00 + a01*b10 + a02*b20;
    out->m10 = a10*b00 + a11*b10 + a12*b20;
    out->m01 = a00*b01 + a01*b11 + a02*b21;
    out->m11 = a10*b01 + a11*b11 + a12*b21;
    out->m02 = a00*b02 + a01*b12 + a02*b22;
    out->m12 = a10*b02 + a11*b12 + a12*b22;
    out->m03 = a00*b03 + a01*b13 + a02*b23;
    out->m13 = a10*b03 + a11*b13 + a12*b23;
}


/**
 * @brief Multiplies a CML_Matrix2x3 by a CML_Vector3, and writes the result to 
 *        the out CML_Vector2.
 * 
 * @param A   The left matrix operand.
 * @param v   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x3_mult_vector3(const CML_Matrix2x3 *A, const CML_Vector3 *v, CML_Vector2 *out) {
    f32 a00 = A->m00, a10 = A->m10;
    f32 a01 = A->m01, a11 = A->m11;
    f32 a02 = A->m02, a12 = A->m12;

    f32 v0 = v->x, v1 = v->y, v2 = v->z;

    out->x = a00*v0 + a01*v1 + a02*v2;
    out->y = a10*v0 + a11*v1 + a12*v2;
}


/**
 * @brief Multiplies a CML_Vector2 by a CML_Matrix2x3, and writes the result to 
 *        the out CML_Vector3.
 * 
 * @param v   The left transposed vector operand.
 * @param A   The right matrix operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_vector2_mult_matrix2x3(const CML_Vector2 *v, const CML_Matrix2x3 *A, CML_Vector3 *out) {
    f32 a00 = A->m00, a10 = A->m10;
    f32 a01 = A->m01, a11 = A->m11;
    f32 a02 = A->m02, a12 = A->m12;

    f32 v0 = v->x, v1 = v->y;

    out->x = a00*v0 + a10*v1;
    out->y = a01*v0 + a11*v1;
    out->z = a02*v0 + a12*v1;
}


/**
 * @brief Calculates the transpose of a CML_Matrix2x3 and writes the result to
 *        the out CML_Matrix3x2.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x3_transpose(const CML_Matrix2x3 *A, CML_Matrix3x2 *out) {
    f32 a00 = A->m00, a10 = A->m10;
    f32 a01 = A->m01, a11 = A->m11;
    f32 a02 = A->m02, a12 = A->m12;

    out->m00 = a00;
    out->m10 = a01;
    out->m20 = a02;
    out->m01 = a10;
    out->m11 = a11;
    out->m21 = a12;
}


/**
 * @brief Compares two CML_Matrix2x3s for equality.
 * 
 * @param A The left matrix operand.
 * @param B The right matrix operand.
 * 
 * @return Boolean value indicating whether the matrices are equal.
 */
CAMEL_STATIC CAMEL_API b8 cml_matrix2x3_eq(const CML_Matrix2x3 *A, const CML_Matrix2x3 *B) {
    if (!A || !B) {
        return false;
    }

    return (fabsf(A->m00 - B->m00) <= CML_EPSILON && fabsf(A->m10 - B->m10) <= CML_EPSILON && 
            fabsf(A->m01 - B->m01) <= CML_EPSILON && fabsf(A->m11 - B->m11) <= CML_EPSILON && 
            fabsf(A->m02 - B->m02) <= CML_EPSILON && fabsf(A->m12 - B->m12) <= CML_EPSILON)? true : false;
}


/**
 * @brief Returns a debug message comparing the input CML_Matrix2x3s.
 *
 * @param expected Expected matrix.
 * @param got      Result matrix.
 * 
 * @return A string containing the debug message.
 */
CAMEL_STATIC CAMEL_API char *cml_matrix2x3_debug(const CML_Matrix2x3 *expected, const CML_Matrix2x3 *got) {
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



/**
 * @brief Adds two CML_Matrix2x4 and writes the result to the out CML_Matrix2x4.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x4_add(const CML_Matrix2x4 *A, const CML_Matrix2x4 *B, CML_Matrix2x4 *out) {
    out->m00 = A->m00 + B->m00;
    out->m10 = A->m10 + B->m10;
    out->m01 = A->m01 + B->m01;
    out->m11 = A->m11 + B->m11;
    out->m02 = A->m02 + B->m02;
    out->m12 = A->m12 + B->m12;
    out->m03 = A->m03 + B->m03;
    out->m13 = A->m13 + B->m13;
}


/**
 * @brief Subtracts two CML_Matrix2x4 and writes the result to the out 
 *        CML_Matrix2x4.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x4_sub(const CML_Matrix2x4 *A, const CML_Matrix2x4 *B, CML_Matrix2x4 *out) {
    out->m00 = A->m00 - B->m00;
    out->m10 = A->m10 - B->m10;
    out->m01 = A->m01 - B->m01;
    out->m11 = A->m11 - B->m11;
    out->m02 = A->m02 - B->m02;
    out->m12 = A->m12 - B->m12;
    out->m03 = A->m03 - B->m03;
    out->m13 = A->m13 - B->m13;
}


/**
 * @brief Multiplies a CML_Matrix2x4 by a scalar, and writes the result to the 
 *        out CML_Matrix2x4.
 * 
 * @param A   The matrix operand.
 * @param t   The scalar.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x4_scale(const CML_Matrix2x4 *A, f32 t, CML_Matrix2x4 *out) {
    out->m00 = A->m00 * t;
    out->m10 = A->m10 * t;
    out->m01 = A->m01 * t;
    out->m11 = A->m11 * t;
    out->m02 = A->m02 * t;
    out->m12 = A->m12 * t;
    out->m03 = A->m03 * t;
    out->m13 = A->m13 * t;
}


/**
 * @brief Multiplies a CML_Matrix2x4 by a CML_Matrix4x2, and writes the result 
 *        to the out CML_Matrix2x2.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x4_mult_matrix4x2(const CML_Matrix2x4 *A, const CML_Matrix4x2 *B, CML_Matrix2x2 *out) {
    f32 a00 = A->m00, a10 = A->m10;
    f32 a01 = A->m01, a11 = A->m11;
    f32 a02 = A->m02, a12 = A->m12;
    f32 a03 = A->m03, a13 = A->m13;

    f32 b00 = B->m00, b10 = B->m10, b20 = B->m20, b30 = B->m30;
    f32 b01 = B->m01, b11 = B->m11, b21 = B->m21, b31 = B->m31;

    out->m00 = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out->m10 = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out->m01 = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out->m11 = a10*b01 + a11*b11 + a12*b21 + a13*b31;
}


/**
 * @brief Multiplies a CML_Matrix2x4 by a CML_Matrix4x3, and writes the result 
 *        to the out CML_Matrix2x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x4_mult_matrix4x3(const CML_Matrix2x4 *A, const CML_Matrix4x3 *B, CML_Matrix2x3 *out) {
    f32 a00 = A->m00, a10 = A->m10;
    f32 a01 = A->m01, a11 = A->m11;
    f32 a02 = A->m02, a12 = A->m12;
    f32 a03 = A->m03, a13 = A->m13;

    f32 b00 = B->m00, b10 = B->m10, b20 = B->m20, b30 = B->m30;
    f32 b01 = B->m01, b11 = B->m11, b21 = B->m21, b31 = B->m31;
    f32 b02 = B->m02, b12 = B->m12, b22 = B->m22, b32 = B->m32;

    out->m00 = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out->m10 = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out->m01 = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out->m11 = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out->m02 = a00*b02 + a01*b12 + a02*b22 + a03*b32;
    out->m12 = a10*b02 + a11*b12 + a12*b22 + a13*b32;
}


/**
 * @brief Multiplies a CML_Matrix2x4 by a CML_Matrix4x4, and writes the result 
 *        to the out CML_Matrix2x4.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x4_mult_matrix4x4(const CML_Matrix2x4 *A, const CML_Matrix4x4 *B, CML_Matrix2x4 *out) {
    f32 a00 = A->m00, a10 = A->m10;
    f32 a01 = A->m01, a11 = A->m11;
    f32 a02 = A->m02, a12 = A->m12;
    f32 a03 = A->m03, a13 = A->m13;

    f32 b00 = B->m00, b10 = B->m10, b20 = B->m20, b30 = B->m30;
    f32 b01 = B->m01, b11 = B->m11, b21 = B->m21, b31 = B->m31;
    f32 b02 = B->m02, b12 = B->m12, b22 = B->m22, b32 = B->m32;
    f32 b03 = B->m03, b13 = B->m13, b23 = B->m23, b33 = B->m33;

    out->m00 = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out->m10 = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out->m01 = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out->m11 = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out->m02 = a00*b02 + a01*b12 + a02*b22 + a03*b32;
    out->m12 = a10*b02 + a11*b12 + a12*b22 + a13*b32;
    out->m03 = a00*b03 + a01*b13 + a02*b23 + a03*b33;
    out->m13 = a10*b03 + a11*b13 + a12*b23 + a13*b33;
}


/**
 * @brief Multiplies a CML_Matrix2x4 by a CML_Vector4, and writes the result to 
 *        the out CML_Vector2.
 * 
 * @param A   The left matrix operand.
 * @param v   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x4_mult_vector4(const CML_Matrix2x4 *A, const CML_Vector4 *v, CML_Vector2 *out) {
    f32 a00 = A->m00, a10 = A->m10;
    f32 a01 = A->m01, a11 = A->m11;
    f32 a02 = A->m02, a12 = A->m12;
    f32 a03 = A->m03, a13 = A->m13;

    f32 v0 = v->x, v1 = v->y, v2 = v->z, v3 = v->w;

    out->x = a00*v0 + a01*v1 + a02*v2 + a03*v3;
    out->y = a10*v0 + a11*v1 + a12*v2 + a13*v3;
}


/**
 * @brief Multiplies a CML_Vector2 by a CML_Matrix2x4, and writes the result to 
 *        the out CML_Vector4.
 * 
 * @param v   The left transposed vector operand.
 * @param A   The right matrix operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_vector2_mult_matrix2x4(const CML_Vector2 *v, const CML_Matrix2x4 *A, CML_Vector4 *out) {
    f32 a00 = A->m00, a10 = A->m10;
    f32 a01 = A->m01, a11 = A->m11;
    f32 a02 = A->m02, a12 = A->m12;
    f32 a03 = A->m03, a13 = A->m13;

    f32 v0 = v->x, v1 = v->y;

    out->x = a00*v0 + a10*v1;
    out->y = a01*v0 + a11*v1;
    out->z = a02*v0 + a12*v1;
    out->w = a03*v0 + a13*v1;
}


/**
 * @brief Calculates the transpose of a CML_Matrix2x4 and writes the result to
 *        the out CML_Matrix4x2.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix2x4_transpose(const CML_Matrix2x4 *A, CML_Matrix4x2 *out) {
    f32 a00 = A->m00, a10 = A->m10;
    f32 a01 = A->m01, a11 = A->m11;
    f32 a02 = A->m02, a12 = A->m12;
    f32 a03 = A->m03, a13 = A->m13;

    out->m00 = a00;
    out->m10 = a01;
    out->m20 = a02;
    out->m30 = a03;
    out->m01 = a10;
    out->m11 = a11;
    out->m21 = a12;
    out->m31 = a13;
}


/**
 * @brief Compares two CML_Matrix2x4s for equality.
 * 
 * @param A The left matrix operand.
 * @param B The right matrix operand.
 * 
 * @return Boolean value indicating whether the matrices are equal.
 */
CAMEL_STATIC CAMEL_API b8 cml_matrix2x4_eq(const CML_Matrix2x4 *A, const CML_Matrix2x4 *B) {
    if (!A || !B) {
        return false;
    }

    return (fabsf(A->m00 - B->m00) <= CML_EPSILON && fabsf(A->m10 - B->m10) <= CML_EPSILON && 
            fabsf(A->m01 - B->m01) <= CML_EPSILON && fabsf(A->m11 - B->m11) <= CML_EPSILON && 
            fabsf(A->m02 - B->m02) <= CML_EPSILON && fabsf(A->m12 - B->m12) <= CML_EPSILON && 
            fabsf(A->m03 - B->m03) <= CML_EPSILON && fabsf(A->m13 - B->m13) <= CML_EPSILON)? true : false;
}


/**
 * @brief Returns a debug message comparing the input CML_Matrix2x4s.
 *
 * @param expected Expected matrix.
 * @param got      Result matrix.
 * 
 * @return A string containing the debug message.
 */
CAMEL_STATIC CAMEL_API char *cml_matrix2x4_debug(const CML_Matrix2x4 *expected, const CML_Matrix2x4 *got) {
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



/**
 * @brief Adds two CML_Matrix3x2 and writes the result to the out CML_Matrix3x2.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x2_add(const CML_Matrix3x2 *A, const CML_Matrix3x2 *B, CML_Matrix3x2 *out) {
    out->m00 = A->m00 + B->m00;
    out->m10 = A->m10 + B->m10;
    out->m20 = A->m20 + B->m20;
    out->m01 = A->m01 + B->m01;
    out->m11 = A->m11 + B->m11;
    out->m21 = A->m21 + B->m21;
}


/**
 * @brief Subtracts two CML_Matrix3x2 and writes the result to the out 
 *        CML_Matrix3x2.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x2_sub(const CML_Matrix3x2 *A, const CML_Matrix3x2 *B, CML_Matrix3x2 *out) {
    out->m00 = A->m00 - B->m00;
    out->m10 = A->m10 - B->m10;
    out->m20 = A->m20 - B->m20;
    out->m01 = A->m01 - B->m01;
    out->m11 = A->m11 - B->m11;
    out->m21 = A->m21 - B->m21;
}


/**
 * @brief Multiplies a CML_Matrix3x2 by a scalar, and writes the result to the 
 *        out CML_Matrix3x2.
 * 
 * @param A   The matrix operand.
 * @param t   The scalar.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x2_scale(const CML_Matrix3x2 *A, f32 t, CML_Matrix3x2 *out) {
    out->m00 = A->m00 * t;
    out->m10 = A->m10 * t;
    out->m20 = A->m20 * t;
    out->m01 = A->m01 * t;
    out->m11 = A->m11 * t;
    out->m21 = A->m21 * t;
}


/**
 * @brief Multiplies a CML_Matrix3x2 by a CML_Matrix2x2, and writes the result
 *        to the out CML_Matrix3x2.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x2_mult_matrix2x2(const CML_Matrix3x2 *A, const CML_Matrix2x2 *B, CML_Matrix3x2 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;

    f32 b00 = B->m00, b10 = B->m10;
    f32 b01 = B->m01, b11 = B->m11;

    out->m00 = a00*b00 + a01*b10;
    out->m10 = a10*b00 + a11*b10;
    out->m20 = a20*b00 + a21*b10;
    out->m01 = a00*b01 + a01*b11;
    out->m11 = a10*b01 + a11*b11;
    out->m21 = a20*b01 + a21*b11;
}


/**
 * @brief Multiplies a CML_Matrix3x2 by a CML_Matrix2x3, and writes the result
 *        to the out CML_Matrix3x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x2_mult_matrix2x3(const CML_Matrix3x2 *A, const CML_Matrix2x3 *B, CML_Matrix3x3 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;

    f32 b00 = B->m00, b10 = B->m10;
    f32 b01 = B->m01, b11 = B->m11;
    f32 b02 = B->m02, b12 = B->m12;

    out->m00 = a00*b00 + a01*b10;
    out->m10 = a10*b00 + a11*b10;
    out->m20 = a20*b00 + a21*b10;
    out->m01 = a00*b01 + a01*b11;
    out->m11 = a10*b01 + a11*b11;
    out->m21 = a20*b01 + a21*b11;
    out->m02 = a00*b02 + a01*b12;
    out->m12 = a10*b02 + a11*b12;
    out->m22 = a20*b02 + a21*b12;
}


/**
 * @brief Multiplies a CML_Matrix3x2 by a CML_Matrix2x4, and writes the result
 *        to the out CML_Matrix3x4.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x2_mult_matrix2x4(const CML_Matrix3x2 *A, const CML_Matrix2x4 *B, CML_Matrix3x4 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;

    f32 b00 = B->m00, b10 = B->m10;
    f32 b01 = B->m01, b11 = B->m11;
    f32 b02 = B->m02, b12 = B->m12;
    f32 b03 = B->m03, b13 = B->m13;

    out->m00 = a00*b00 + a01*b10;
    out->m10 = a10*b00 + a11*b10;
    out->m20 = a20*b00 + a21*b10;
    out->m01 = a00*b01 + a01*b11;
    out->m11 = a10*b01 + a11*b11;
    out->m21 = a20*b01 + a21*b11;
    out->m02 = a00*b02 + a01*b12;
    out->m12 = a10*b02 + a11*b12;
    out->m22 = a20*b02 + a21*b12;
    out->m03 = a00*b03 + a01*b13;
    out->m13 = a10*b03 + a11*b13;
    out->m23 = a20*b03 + a21*b13;
}


/**
 * @brief Multiplies a CML_Matrix3x2 by a CML_Vector2, and writes the result to
 *        the out CML_Vector3.
 * 
 * @param A   The left matrix operand.
 * @param v   The right vector operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x2_mult_vector2(const CML_Matrix3x2 *A, const CML_Vector2 *v, CML_Vector3 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;

    f32 v0 = v->x, v1 = v->y;

    out->x = a00*v0 + a01*v1;
    out->y = a10*v0 + a11*v1;
    out->z = a20*v0 + a21*v1;
}


/**
 * @brief Multiplies a CML_Vector3 by a CML_Matrix3x2, and writes the result to
 *        the out CML_Vector2.
 * 
 * @param v   The left transposed vector operand.
 * @param A   The right matrix operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_vector3_mult_matrix3x2(const CML_Vector3 *v, const CML_Matrix3x2 *A, CML_Vector2 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;

    f32 v0 = v->x, v1 = v->y, v2 = v->z;

    out->x = a00*v0 + a10*v1 + a20*v2;
    out->y = a01*v0 + a11*v1 + a21*v2;
}


/**
 * @brief Calculates the transpose of a CML_Matrix3x2 and writes the result to
 *        the out CML_Matrix2x3.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x2_transpose(const CML_Matrix3x2 *A, CML_Matrix2x3 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;

    out->m00 = a00;
    out->m10 = a01;
    out->m01 = a10;
    out->m11 = a11;
    out->m02 = a20;
    out->m12 = a21;
}


/**
 * @brief Compares two CML_Matrix3x2s for equality.
 * 
 * @param A The left matrix operand.
 * @param B The right matrix operand.
 * 
 * @return Boolean value indicating whether the matrices are equal.
 */
CAMEL_STATIC CAMEL_API b8 cml_matrix3x2_eq(const CML_Matrix3x2 *A, const CML_Matrix3x2 *B) {
    if (!A || !B) {
        return false;
    }

    return (fabsf(A->m00 - B->m00) <= CML_EPSILON && fabsf(A->m10 - B->m10) <= CML_EPSILON && 
            fabsf(A->m20 - B->m20) <= CML_EPSILON && fabsf(A->m01 - B->m01) <= CML_EPSILON && 
            fabsf(A->m11 - B->m11) <= CML_EPSILON && fabsf(A->m21 - B->m21) <= CML_EPSILON)? true : false;
}


/**
 * @brief Returns a debug message comparing the input CML_Matrix3x2s.
 *
 * @param expected Expected matrix.
 * @param got      Result matrix.
 * 
 * @return A string containing the debug message.
 */
CAMEL_STATIC CAMEL_API char *cml_matrix3x2_debug(const CML_Matrix3x2 *expected, const CML_Matrix3x2 *got) {
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



/**
 * @brief Adds two CML_Matrix3x4 and writes the result to the out CML_Matrix3x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x4_add(const CML_Matrix3x4 *A, const CML_Matrix3x4 *B, CML_Matrix3x4 *out) {
    out->m00 = A->m00 + B->m00;
    out->m10 = A->m10 + B->m10;
    out->m20 = A->m20 + B->m20;
    out->m01 = A->m01 + B->m01;
    out->m11 = A->m11 + B->m11;
    out->m21 = A->m21 + B->m21;
    out->m02 = A->m02 + B->m02;
    out->m12 = A->m12 + B->m12;
    out->m22 = A->m22 + B->m22;
    out->m03 = A->m03 + B->m03;
    out->m13 = A->m13 + B->m13;
    out->m23 = A->m23 + B->m23;
}


/**
 * @brief Subtracts two CML_Matrix3x4 and writes the result to the out 
 *        CML_Matrix3x4.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x4_sub(const CML_Matrix3x4 *A, const CML_Matrix3x4 *B, CML_Matrix3x4 *out) {
    out->m00 = A->m00 - B->m00;
    out->m10 = A->m10 - B->m10;
    out->m20 = A->m20 - B->m20;
    out->m01 = A->m01 - B->m01;
    out->m11 = A->m11 - B->m11;
    out->m21 = A->m21 - B->m21;
    out->m02 = A->m02 - B->m02;
    out->m12 = A->m12 - B->m12;
    out->m22 = A->m22 - B->m22;
    out->m03 = A->m03 - B->m03;
    out->m13 = A->m13 - B->m13;
    out->m23 = A->m23 - B->m23;
}


/**
 * @brief Multiplies a CML_Matrix3x4 by a scalar, and writes the result to the 
 *        out CML_Matrix3x4.
 * 
 * @param A   The matrix operand.
 * @param t   The scalar.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x4_scale(const CML_Matrix3x4 *A, f32 t, CML_Matrix3x4 *out) {
    out->m00 = A->m00 * t;
    out->m10 = A->m10 * t;
    out->m20 = A->m20 * t;
    out->m01 = A->m01 * t;
    out->m11 = A->m11 * t;
    out->m21 = A->m21 * t;
    out->m02 = A->m02 * t;
    out->m12 = A->m12 * t;
    out->m22 = A->m22 * t;
    out->m03 = A->m03 * t;
    out->m13 = A->m13 * t;
    out->m23 = A->m23 * t;
}


/**
 * @brief Multiplies a CML_Matrix3x4 by a CML_Matrix4x2, and writes the result 
 *        to the out CML_Matrix3x2.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x4_mult_matrix4x2(const CML_Matrix3x4 *A, const CML_Matrix4x2 *B, CML_Matrix3x2 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22;
    f32 a03 = A->m03, a13 = A->m13, a23 = A->m23;

    f32 b00 = B->m00, b10 = B->m10, b20 = B->m20, b30 = B->m30;
    f32 b01 = B->m01, b11 = B->m11, b21 = B->m21, b31 = B->m31;

    out->m00 = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out->m10 = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out->m20 = a20*b00 + a21*b10 + a22*b20 + a23*b30;
    out->m01 = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out->m11 = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out->m21 = a20*b01 + a21*b11 + a22*b21 + a23*b31;
}


/**
 * @brief Multiplies a CML_Matrix3x4 by a CML_Matrix4x3, and writes the result 
 *        to the out CML_Matrix3x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x4_mult_matrix4x3(const CML_Matrix3x4 *A, const CML_Matrix4x3 *B, CML_Matrix3x3 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22;
    f32 a03 = A->m03, a13 = A->m13, a23 = A->m23;

    f32 b00 = B->m00, b10 = B->m10, b20 = B->m20, b30 = B->m30;
    f32 b01 = B->m01, b11 = B->m11, b21 = B->m21, b31 = B->m31;
    f32 b02 = B->m02, b12 = B->m12, b22 = B->m22, b32 = B->m32;

    out->m00 = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out->m10 = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out->m20 = a20*b00 + a21*b10 + a22*b20 + a23*b30;
    out->m01 = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out->m11 = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out->m21 = a20*b01 + a21*b11 + a22*b21 + a23*b31;
    out->m02 = a00*b02 + a01*b12 + a02*b22 + a03*b32;
    out->m12 = a10*b02 + a11*b12 + a12*b22 + a13*b32;
    out->m22 = a20*b02 + a21*b12 + a22*b22 + a23*b32;
}


/**
 * @brief Multiplies a CML_Matrix3x4 by a CML_Matrix4x4, and writes the result 
 *        to the out CML_Matrix3x4.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x4_mult_matrix4x4(const CML_Matrix3x4 *A, const CML_Matrix4x4 *B, CML_Matrix3x4 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22;
    f32 a03 = A->m03, a13 = A->m13, a23 = A->m23;

    f32 b00 = B->m00, b10 = B->m10, b20 = B->m20, b30 = B->m30;
    f32 b01 = B->m01, b11 = B->m11, b21 = B->m21, b31 = B->m31;
    f32 b02 = B->m02, b12 = B->m12, b22 = B->m22, b32 = B->m32;
    f32 b03 = B->m03, b13 = B->m13, b23 = B->m23, b33 = B->m33;

    out->m00 = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    out->m10 = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    out->m20 = a20*b00 + a21*b10 + a22*b20 + a23*b30;
    out->m01 = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    out->m11 = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    out->m21 = a20*b01 + a21*b11 + a22*b21 + a23*b31;
    out->m02 = a00*b02 + a01*b12 + a02*b22 + a03*b32;
    out->m12 = a10*b02 + a11*b12 + a12*b22 + a13*b32;
    out->m22 = a20*b02 + a21*b12 + a22*b22 + a23*b32;
    out->m03 = a00*b03 + a01*b13 + a02*b23 + a03*b33;
    out->m13 = a10*b03 + a11*b13 + a12*b23 + a13*b33;
    out->m23 = a20*b03 + a21*b13 + a22*b23 + a23*b33;
}


/**
 * @brief Multiplies a CML_Matrix3x4 by a CML_Vector4, and writes the result to 
 *        the out CML_Vector3.
 * 
 * @param A   The left matrix operand.
 * @param v   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x4_mult_vector4(const CML_Matrix3x4 *A, const CML_Vector4 *v, CML_Vector3 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22;
    f32 a03 = A->m03, a13 = A->m13, a23 = A->m23;

    f32 v0 = v->x, v1 = v->y, v2 = v->z, v3 = v->w;

    out->x = a00*v0 + a01*v1 + a02*v2 + a03*v3;
    out->y = a10*v0 + a11*v1 + a12*v2 + a13*v3;
    out->z = a20*v0 + a21*v1 + a22*v2 + a23*v3;
}


/**
 * @brief Multiplies a CML_Vector3 by a CML_Matrix3x4, and writes the result to 
 *        the out CML_Vector4.
 * 
 * @param v   The left transposed vector operand.
 * @param A   The right matrix operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_vector3_mult_matrix3x4(const CML_Vector3 *v, const CML_Matrix3x4 *A, CML_Vector4 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22;
    f32 a03 = A->m03, a13 = A->m13, a23 = A->m23;

    f32 v0 = v->x, v1 = v->y, v2 = v->z;

    out->x = a00*v0 + a10*v1 + a20*v2;
    out->y = a01*v0 + a11*v1 + a21*v2;
    out->z = a02*v0 + a12*v1 + a22*v2;
    out->w = a03*v0 + a13*v1 + a23*v2;
}


/**
 * @brief Calculates the transpose of a CML_Matrix3x4 and writes the result to
 *        the out CML_Matrix4x3.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix3x4_transpose(const CML_Matrix3x4 *A, CML_Matrix4x3 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22;
    f32 a03 = A->m03, a13 = A->m13, a23 = A->m23;

    out->m00 = a00;
    out->m10 = a01;
    out->m20 = a02;
    out->m30 = a03;
    out->m01 = a10;
    out->m11 = a11;
    out->m21 = a12;
    out->m31 = a13;
    out->m02 = a20;
    out->m12 = a21;
    out->m22 = a22;
    out->m32 = a23;
}


/**
 * @brief Compares two CML_Matrix3x4s for equality.
 * 
 * @param A The left matrix operand.
 * @param B The right matrix operand.
 * 
 * @return Boolean value indicating whether the matrices are equal.
 */
CAMEL_STATIC CAMEL_API b8 cml_matrix3x4_eq(const CML_Matrix3x4 *A, const CML_Matrix3x4 *B) {
    if (!A || !B) {
        return false;
    }

    return (fabsf(A->m00 - B->m00) <= CML_EPSILON && fabsf(A->m10 - B->m10) <= CML_EPSILON && 
            fabsf(A->m20 - B->m20) <= CML_EPSILON && fabsf(A->m01 - B->m01) <= CML_EPSILON && 
            fabsf(A->m11 - B->m11) <= CML_EPSILON && fabsf(A->m21 - B->m21) <= CML_EPSILON && 
            fabsf(A->m02 - B->m02) <= CML_EPSILON && fabsf(A->m12 - B->m12) <= CML_EPSILON && 
            fabsf(A->m22 - B->m22) <= CML_EPSILON && fabsf(A->m03 - B->m03) <= CML_EPSILON && 
            fabsf(A->m13 - B->m13) <= CML_EPSILON && fabsf(A->m23 - B->m23) <= CML_EPSILON)? true : false;
}


/**
 * @brief Returns a debug message comparing the input CML_Matrix3x4s.
 *
 * @param expected Expected matrix.
 * @param got      Result matrix.
 * 
 * @return A string containing the debug message.
 */
CAMEL_STATIC CAMEL_API char *cml_matrix3x4_debug(const CML_Matrix3x4 *expected, const CML_Matrix3x4 *got) {
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



/**
 * @brief Adds two CML_Matrix4x2 and writes the result to the out CML_Matrix4x2.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x2_add(const CML_Matrix4x2 *A, const CML_Matrix4x2 *B, CML_Matrix4x2 *out) {
    out->m00 = A->m00 + B->m00;
    out->m10 = A->m10 + B->m10;
    out->m20 = A->m20 + B->m20;
    out->m30 = A->m30 + B->m30;
    out->m01 = A->m01 + B->m01;
    out->m11 = A->m11 + B->m11;
    out->m21 = A->m21 + B->m21;
    out->m31 = A->m31 + B->m31;
}


/**
 * @brief Subtracts two CML_Matrix4x2 and writes the result to the out 
 *        CML_Matrix4x2.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x2_sub(const CML_Matrix4x2 *A, const CML_Matrix4x2 *B, CML_Matrix4x2 *out) {
    out->m00 = A->m00 - B->m00;
    out->m10 = A->m10 - B->m10;
    out->m20 = A->m20 - B->m20;
    out->m30 = A->m30 - B->m30;
    out->m01 = A->m01 - B->m01;
    out->m11 = A->m11 - B->m11;
    out->m21 = A->m21 - B->m21;
    out->m31 = A->m31 - B->m31;
}


/**
 * @brief Multiplies a CML_Matrix4x2 by a scalar, and writes the result to the 
 *        out CML_Matrix4x2.
 * 
 * @param A   The matrix operand.
 * @param t   The scalar.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x2_scale(const CML_Matrix4x2 *A, f32 t, CML_Matrix4x2 *out) {
    out->m00 = A->m00 * t;
    out->m10 = A->m10 * t;
    out->m20 = A->m20 * t;
    out->m30 = A->m30 * t;
    out->m01 = A->m01 * t;
    out->m11 = A->m11 * t;
    out->m21 = A->m21 * t;
    out->m31 = A->m31 * t;
}


/**
 * @brief Multiplies a CML_Matrix4x2 by a CML_Matrix2x2, and writes the result 
 *        to the out CML_Matrix4x2.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x2_mult_matrix2x2(const CML_Matrix4x2 *A, const CML_Matrix2x2 *B, CML_Matrix4x2 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;

    f32 b00 = B->m00, b10 = B->m10;
    f32 b01 = B->m01, b11 = B->m11;

    out->m00 = a00*b00 + a01*b10;
    out->m10 = a10*b00 + a11*b10;
    out->m20 = a20*b00 + a21*b10;
    out->m30 = a30*b00 + a31*b10;
    out->m01 = a00*b01 + a01*b11;
    out->m11 = a10*b01 + a11*b11;
    out->m21 = a20*b01 + a21*b11;
    out->m31 = a30*b01 + a31*b11;
}


/**
 * @brief Multiplies a CML_Matrix4x2 by a CML_Matrix2x3, and writes the result 
 *        to the out CML_Matrix4x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x2_mult_matrix2x3(const CML_Matrix4x2 *A, const CML_Matrix2x3 *B, CML_Matrix4x3 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;

    f32 b00 = B->m00, b10 = B->m10;
    f32 b01 = B->m01, b11 = B->m11;
    f32 b02 = B->m02, b12 = B->m12;

    out->m00 = a00*b00 + a01*b10;
    out->m10 = a10*b00 + a11*b10;
    out->m20 = a20*b00 + a21*b10;
    out->m30 = a30*b00 + a31*b10;
    out->m01 = a00*b01 + a01*b11;
    out->m11 = a10*b01 + a11*b11;
    out->m21 = a20*b01 + a21*b11;
    out->m31 = a30*b01 + a31*b11;
    out->m02 = a00*b02 + a01*b12;
    out->m12 = a10*b02 + a11*b12;
    out->m22 = a20*b02 + a21*b12;
    out->m32 = a30*b02 + a31*b12;
}


/**
 * @brief Multiplies a CML_Matrix4x2 by a CML_Matrix2x4, and writes the result 
 *        to the out CML_Matrix4x4.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x2_mult_matrix2x4(const CML_Matrix4x2 *A, const CML_Matrix2x4 *B, CML_Matrix4x4 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;

    f32 b00 = B->m00, b10 = B->m10;
    f32 b01 = B->m01, b11 = B->m11;
    f32 b02 = B->m02, b12 = B->m12;
    f32 b03 = B->m03, b13 = B->m13;

    out->m00 = a00*b00 + a01*b10;
    out->m10 = a10*b00 + a11*b10;
    out->m20 = a20*b00 + a21*b10;
    out->m30 = a30*b00 + a31*b10;
    out->m01 = a00*b01 + a01*b11;
    out->m11 = a10*b01 + a11*b11;
    out->m21 = a20*b01 + a21*b11;
    out->m31 = a30*b01 + a31*b11;
    out->m02 = a00*b02 + a01*b12;
    out->m12 = a10*b02 + a11*b12;
    out->m22 = a20*b02 + a21*b12;
    out->m32 = a30*b02 + a31*b12;
    out->m03 = a00*b03 + a01*b13;
    out->m13 = a10*b03 + a11*b13;
    out->m23 = a20*b03 + a21*b13;
    out->m33 = a30*b03 + a31*b13;
}


/**
 * @brief Multiplies a CML_Matrix4x2 by a CML_Vector2, and writes the result to 
 *        the out CML_Vector4.
 * 
 * @param A   The left matrix operand.
 * @param v   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x2_mult_vector2(const CML_Matrix4x2 *A, const CML_Vector2 *v, CML_Vector4 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;

    f32 v0 = v->x, v1 = v->y;

    out->x = a00*v0 + a01*v1;
    out->y = a10*v0 + a11*v1;
    out->z = a20*v0 + a21*v1;
    out->w = a30*v0 + a31*v1;
}


/**
 * @brief Multiplies a CML_Vector4 by a CML_Matrix4x2, and writes the result to 
 *        the out CML_Vector2.
 * 
 * @param v   The left transposed vector operand.
 * @param A   The right matrix operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_vector4_mult_matrix4x2(const CML_Vector4 *v, const CML_Matrix4x2 *A, CML_Vector2 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;

    f32 v0 = v->x, v1 = v->y, v2 = v->z, v3 = v->w;

    out->x = a00*v0 + a10*v1 + a20*v2 + a30*v3;
    out->y = a01*v0 + a11*v1 + a21*v2 + a31*v3;
}


/**
 * @brief Calculates the transpose of a CML_Matrix4x2 and writes the result to
 *        the out CML_Matrix2x4.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x2_transpose(const CML_Matrix4x2 *A, CML_Matrix2x4 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;

    out->m00 = a00;
    out->m10 = a01;
    out->m01 = a10;
    out->m11 = a11;
    out->m02 = a20;
    out->m12 = a21;
    out->m03 = a30;
    out->m13 = a31;
}


/**
 * @brief Compares two CML_Matrix4x2s for equality.
 * 
 * @param A The left matrix operand.
 * @param B The right matrix operand.
 * 
 * @return Boolean value indicating whether the matrices are equal.
 */
CAMEL_STATIC CAMEL_API b8 cml_matrix4x2_eq(const CML_Matrix4x2 *A, const CML_Matrix4x2 *B) {
    if (!A || !B) {
        return false;
    }

    return (fabsf(A->m00 - B->m00) <= CML_EPSILON && fabsf(A->m10 - B->m10) <= CML_EPSILON && 
            fabsf(A->m20 - B->m20) <= CML_EPSILON && fabsf(A->m30 - B->m30) <= CML_EPSILON && 
            fabsf(A->m01 - B->m01) <= CML_EPSILON && fabsf(A->m11 - B->m11) <= CML_EPSILON && 
            fabsf(A->m21 - B->m21) <= CML_EPSILON && fabsf(A->m31 - B->m31) <= CML_EPSILON)? true : false;
}


/**
 * @brief Returns a debug message comparing the input CML_Matrix4x2s.
 *
 * @param expected Expected matrix.
 * @param got      Result matrix.
 * 
 * @return A string containing the debug message.
 */
CAMEL_STATIC CAMEL_API char *cml_matrix4x2_debug(const CML_Matrix4x2 *expected, const CML_Matrix4x2 *got) {
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



/**
 * @brief Adds two CML_Matrix4x3 and writes the result to the out CML_Matrix4x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x3_add(const CML_Matrix4x3 *A, const CML_Matrix4x3 *B, CML_Matrix4x3 *out) {
    out->m00 = A->m00 + B->m00;
    out->m10 = A->m10 + B->m10;
    out->m20 = A->m20 + B->m20;
    out->m30 = A->m30 + B->m30;
    out->m01 = A->m01 + B->m01;
    out->m11 = A->m11 + B->m11;
    out->m21 = A->m21 + B->m21;
    out->m31 = A->m31 + B->m31;
    out->m02 = A->m02 + B->m02;
    out->m12 = A->m12 + B->m12;
    out->m22 = A->m22 + B->m22;
    out->m32 = A->m32 + B->m32;
}


/**
 * @brief Subtracts two CML_Matrix4x3 and writes the result to the out 
 *        CML_Matrix4x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x3_sub(const CML_Matrix4x3 *A, const CML_Matrix4x3 *B, CML_Matrix4x3 *out) {
    out->m00 = A->m00 - B->m00;
    out->m10 = A->m10 - B->m10;
    out->m20 = A->m20 - B->m20;
    out->m30 = A->m30 - B->m30;
    out->m01 = A->m01 - B->m01;
    out->m11 = A->m11 - B->m11;
    out->m21 = A->m21 - B->m21;
    out->m31 = A->m31 - B->m31;
    out->m02 = A->m02 - B->m02;
    out->m12 = A->m12 - B->m12;
    out->m22 = A->m22 - B->m22;
    out->m32 = A->m32 - B->m32;
}


/**
 * @brief Multiplies a CML_Matrix4x3 by a scalar, and writes the result to the 
 *        out CML_Matrix4x3.
 * 
 * @param A   The matrix operand.
 * @param t   The scalar.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x3_scale(const CML_Matrix4x3 *A, f32 t, CML_Matrix4x3 *out) {
    out->m00 = A->m00 * t;
    out->m10 = A->m10 * t;
    out->m20 = A->m20 * t;
    out->m30 = A->m30 * t;
    out->m01 = A->m01 * t;
    out->m11 = A->m11 * t;
    out->m21 = A->m21 * t;
    out->m31 = A->m31 * t;
    out->m02 = A->m02 * t;
    out->m12 = A->m12 * t;
    out->m22 = A->m22 * t;
    out->m32 = A->m32 * t;
}


/**
 * @brief Multiplies a CML_Matrix4x3 by a CML_Matrix3x2, and writes the result 
 *        to the out CML_Matrix4x2.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x3_mult_matrix3x2(const CML_Matrix4x3 *A, const CML_Matrix3x2 *B, CML_Matrix4x2 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22, a32 = A->m32;

    f32 b00 = B->m00, b10 = B->m10, b20 = B->m20;
    f32 b01 = B->m01, b11 = B->m11, b21 = B->m21;

    out->m00 = a00*b00 + a01*b10 + a02*b20;
    out->m10 = a10*b00 + a11*b10 + a12*b20;
    out->m20 = a20*b00 + a21*b10 + a22*b20;
    out->m30 = a30*b00 + a31*b10 + a32*b20;
    out->m01 = a00*b01 + a01*b11 + a02*b21;
    out->m11 = a10*b01 + a11*b11 + a12*b21;
    out->m21 = a20*b01 + a21*b11 + a22*b21;
    out->m31 = a30*b01 + a31*b11 + a32*b21;
}


/**
 * @brief Multiplies a CML_Matrix4x3 by a CML_Matrix3x3, and writes the result 
 *        to the out CML_Matrix4x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x3_mult_matrix3x3(const CML_Matrix4x3 *A, const CML_Matrix3x3 *B, CML_Matrix4x3 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22, a32 = A->m32;

    f32 b00 = B->m00, b10 = B->m10, b20 = B->m20;
    f32 b01 = B->m01, b11 = B->m11, b21 = B->m21;
    f32 b02 = B->m02, b12 = B->m12, b22 = B->m22;

    out->m00 = a00*b00 + a01*b10 + a02*b20;
    out->m10 = a10*b00 + a11*b10 + a12*b20;
    out->m20 = a20*b00 + a21*b10 + a22*b20;
    out->m30 = a30*b00 + a31*b10 + a32*b20;
    out->m01 = a00*b01 + a01*b11 + a02*b21;
    out->m11 = a10*b01 + a11*b11 + a12*b21;
    out->m21 = a20*b01 + a21*b11 + a22*b21;
    out->m31 = a30*b01 + a31*b11 + a32*b21;
    out->m02 = a00*b02 + a01*b12 + a02*b22;
    out->m12 = a10*b02 + a11*b12 + a12*b22;
    out->m22 = a20*b02 + a21*b12 + a22*b22;
    out->m32 = a30*b02 + a31*b12 + a32*b22;
}


/**
 * @brief Multiplies a CML_Matrix4x3 by a CML_Matrix3x4, and writes the result 
 *        to the out CML_Matrix4x4.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x3_mult_matrix3x4(const CML_Matrix4x3 *A, const CML_Matrix3x4 *B, CML_Matrix4x4 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22, a32 = A->m32;

    f32 b00 = B->m00, b10 = B->m10, b20 = B->m20;
    f32 b01 = B->m01, b11 = B->m11, b21 = B->m21;
    f32 b02 = B->m02, b12 = B->m12, b22 = B->m22;
    f32 b03 = B->m03, b13 = B->m13, b23 = B->m23;

    out->m00 = a00*b00 + a01*b10 + a02*b20;
    out->m10 = a10*b00 + a11*b10 + a12*b20;
    out->m20 = a20*b00 + a21*b10 + a22*b20;
    out->m30 = a30*b00 + a31*b10 + a32*b20;
    out->m01 = a00*b01 + a01*b11 + a02*b21;
    out->m11 = a10*b01 + a11*b11 + a12*b21;
    out->m21 = a20*b01 + a21*b11 + a22*b21;
    out->m31 = a30*b01 + a31*b11 + a32*b21;
    out->m02 = a00*b02 + a01*b12 + a02*b22;
    out->m12 = a10*b02 + a11*b12 + a12*b22;
    out->m22 = a20*b02 + a21*b12 + a22*b22;
    out->m32 = a30*b02 + a31*b12 + a32*b22;
    out->m03 = a00*b03 + a01*b13 + a02*b23;
    out->m13 = a10*b03 + a11*b13 + a12*b23;
    out->m23 = a20*b03 + a21*b13 + a22*b23;
    out->m33 = a30*b03 + a31*b13 + a32*b23;
}


/**
 * @brief Multiplies a CML_Matrix4x3 by a CML_Vector3, and writes the result to 
 *        the out CML_Vector4.
 * 
 * @param A   The left matrix operand.
 * @param v   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x3_mult_vector3(const CML_Matrix4x3 *A, const CML_Vector3 *v, CML_Vector4 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22, a32 = A->m32;

    f32 v0 = v->x, v1 = v->y, v2 = v->z;

    out->x = a00*v0 + a01*v1 + a02*v2;
    out->y = a10*v0 + a11*v1 + a12*v2;
    out->z = a20*v0 + a21*v1 + a22*v2;
    out->w = a30*v0 + a31*v1 + a32*v2;
}


/**
 * @brief Multiplies a CML_Vector4 by a CML_Matrix4x3, and writes the result to 
 *        the out CML_Vector3.
 * 
 * @param v   The left transposed vector operand.
 * @param A   The right matrix operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_vector4_mult_matrix4x3(const CML_Vector4 *v, const CML_Matrix4x3 *A, CML_Vector3 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22, a32 = A->m32;

    f32 v0 = v->x, v1 = v->y, v2 = v->z, v3 = v->w;

    out->x = a00*v0 + a10*v1 + a20*v2 + a30*v3;
    out->y = a01*v0 + a11*v1 + a21*v2 + a31*v3;
    out->z = a02*v0 + a12*v1 + a22*v2 + a32*v3;
}


/**
 * @brief Calculates the transpose of a CML_Matrix4x3 and writes the result to
 *        the out CML_Matrix3x4.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_matrix4x3_transpose(const CML_Matrix4x3 *A, CML_Matrix3x4 *out) {
    f32 a00 = A->m00, a10 = A->m10, a20 = A->m20, a30 = A->m30;
    f32 a01 = A->m01, a11 = A->m11, a21 = A->m21, a31 = A->m31;
    f32 a02 = A->m02, a12 = A->m12, a22 = A->m22, a32 = A->m32;

    out->m00 = a00;
    out->m10 = a01;
    out->m20 = a02;
    out->m01 = a10;
    out->m11 = a11;
    out->m21 = a12;
    out->m02 = a20;
    out->m12 = a21;
    out->m22 = a22;
    out->m03 = a30;
    out->m13 = a31;
    out->m23 = a32;
}


/**
 * @brief Compares two CML_Matrix4x3s for equality.
 * 
 * @param A The left matrix operand.
 * @param B The right matrix operand.
 * 
 * @return Boolean value indicating whether the matrices are equal.
 */
CAMEL_STATIC CAMEL_API b8 cml_matrix4x3_eq(const CML_Matrix4x3 *A, const CML_Matrix4x3 *B) {
    if (!A || !B) {
        return false;
    }

    return (fabsf(A->m00 - B->m00) <= CML_EPSILON && fabsf(A->m10 - B->m10) <= CML_EPSILON && 
            fabsf(A->m20 - B->m20) <= CML_EPSILON && fabsf(A->m30 - B->m30) <= CML_EPSILON && 
            fabsf(A->m01 - B->m01) <= CML_EPSILON && fabsf(A->m11 - B->m11) <= CML_EPSILON && 
            fabsf(A->m21 - B->m21) <= CML_EPSILON && fabsf(A->m31 - B->m31) <= CML_EPSILON && 
            fabsf(A->m02 - B->m02) <= CML_EPSILON && fabsf(A->m12 - B->m12) <= CML_EPSILON && 
            fabsf(A->m22 - B->m22) <= CML_EPSILON && fabsf(A->m32 - B->m32) <= CML_EPSILON)? true : false;
}


/**
 * @brief Returns a debug message comparing the input CML_Matrix4x3s.
 *
 * @param expected Expected matrix.
 * @param got      Result matrix.
 * 
 * @return A string containing the debug message.
 */
CAMEL_STATIC CAMEL_API char *cml_matrix4x3_debug(const CML_Matrix4x3 *expected, const CML_Matrix4x3 *got) {
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


#endif /* CAMEL_MATRIX */
