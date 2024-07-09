/**
 * @file cfmatrix.h
 * 
 * @brief Declarations for the compiled version of the fixed matrix manipulation
 *        functions of CAMEL.
 * 
 * @author Sergio Madrid
 * @date 26/12/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_CFIXED_MATRIX
#define CAMEL_CFIXED_MATRIX


#include <stdlib.h>
#include <math.h>

#include "../../../core/macros.h"
#include "../../../core/err.h"
#include "../../../core/constants.h"
#include "fmatrix.h"


/**
 * @brief Adds two CML_Matrix2x2 and writes the result to the out CML_Matrix2x2.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix2x2_add(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B, CML_Matrix2x2 *out);


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
void cmlc_matrix2x2_sub(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B, CML_Matrix2x2 *out);


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
void cmlc_matrix2x2_scale(const CML_Matrix2x2 *A, f32 t, CML_Matrix2x2 *out);


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
void cmlc_matrix2x2_mult(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B, CML_Matrix2x2 *out);


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
void cmlc_matrix2x2_mult_matrix2x3(const CML_Matrix2x2 *A, const CML_Matrix2x3 *B, CML_Matrix2x3 *out);


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
void cmlc_matrix2x2_mult_matrix2x4(const CML_Matrix2x2 *A, const CML_Matrix2x4 *B, CML_Matrix2x4 *out);


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
void cmlc_matrix2x2_mult_vector2(const CML_Matrix2x2 *A, const CML_Vector2 *v, CML_Vector2 *out);


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
void cmlc_vector2_mult_matrix2x2(const CML_Vector2 *v, const CML_Matrix2x2 *A, CML_Vector2 *out);


/**
 * @brief Calculates the determinant of a CML_Matrix2x2.
 * 
 * @param A The matrix operand.
 * 
 * @return The determinant of the matrix.
 */
f32 cmlc_matrix2x2_det(const CML_Matrix2x2 *A);


/**
 * @brief Calculates the inverse of a CML_Matrix2x2 and writes the result to
 *        the out CML_Matrix2x2.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return Success or error code if the matrix is invertible.
 */
CML_Status cmlc_matrix2x2_inv(const CML_Matrix2x2 *A, CML_Matrix2x2 *out);


/**
 * @brief Calculates the transpose of a CML_Matrix2x2 and writes the result to
 *        the out CML_Matrix2x2.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix2x2_transpose(const CML_Matrix2x2 *A, CML_Matrix2x2 *out);


/**
 * @brief Calculates the trace of a CML_Matrix2x2.
 * 
 * @param A The matrix operand.
 * 
 * @return The trace of the matrix.
 */
f32 cmlc_matrix2x2_trace(const CML_Matrix2x2 *A);


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
void cmlc_matrix2x2_gen_scale(f32 x, f32 y, CML_Matrix2x2 *out);


/**
 * @brief Generates the inverse of a scale matrix and writes the result to the
 *        out CML_Matrix2x2.
 * 
 * @param scale The input scale matrix.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix2x2_gen_invscale(const CML_Matrix2x2 *scale, CML_Matrix2x2 *out);


/**
 * @brief Generates the shear matrix along the x axis and writes the result to
 *        the out CML_Matrix2x2.
 * 
 * @param x   The x shear.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix2x2_gen_shearx(f32 x, CML_Matrix2x2 *out);


/**
 * @brief Generates the shear matrix along the y axis and writes the result to
 *        the out CML_Matrix2x2.
 * 
 * @param y   The y shear.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix2x2_gen_sheary(f32 y, CML_Matrix2x2 *out);


/**
 * @brief Generates the inverse of a shear matrix and writes the result to the
 *        out CML_Matrix2x2.
 * 
 * @param shear The input shear matrix.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix2x2_gen_invshear(const CML_Matrix2x2 *shear, CML_Matrix2x2 *out);


/**
 * @brief Generates the left-handed rotation matrix (clockwise) and writes the
 *        result to the out CML_Matrix2x2.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix2x2_genlh_rotation(f32 angle, CML_Matrix2x2 *out);


/**
 * @brief Generates the right-handed rotation matrix (counter clockwise) and
 *        writes the result to the out CML_Matrix2x2.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix2x2_genrh_rotation(f32 angle, CML_Matrix2x2 *out);


/**
 * @brief Generates the inverse of a rotation matrix and writes the result to
 *        the out CML_Matrix2x2.
 * 
 * @param rotation The input rotation matrix.
 * @param out      The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix2x2_gen_invrotation(const CML_Matrix2x2 *rotation, CML_Matrix2x2 *out);


/**
 * @brief Compares two CML_Matrix2x2s for equality.
 * 
 * @param A The left matrix operand.
 * @param B The right matrix operand.
 * 
 * @return Boolean value indicating whether the matrices are equal.
 */
b8 cmlc_matrix2x2_eq(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B);


/**
 * @brief Returns a debug message comparing the input CML_Matrix2x2s.
 *
 * @param expected The expected matrix.
 * @param got      The result matrix.
 * 
 * @return A string containing the debug message.
 */
char *cmlc_matrix2x2_debug(const CML_Matrix2x2 *expected, const CML_Matrix2x2 *got);



/**
 * @brief Adds two CML_Matrix3x3 and writes the result to the out CML_Matrix3x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix3x3_add(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B, CML_Matrix3x3 *out);


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
void cmlc_matrix3x3_sub(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B, CML_Matrix3x3 *out);


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
void cmlc_matrix3x3_scale(const CML_Matrix3x3 *A, f32 t, CML_Matrix3x3 *out);


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
void cmlc_matrix3x3_mult(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B, CML_Matrix3x3 *out);


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
void cmlc_matrix3x3_mult_matrix3x2(const CML_Matrix3x3 *A, const CML_Matrix3x2 *B, CML_Matrix3x2 *out);


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
void cmlc_matrix3x3_mult_matrix3x4(const CML_Matrix3x3 *A, const CML_Matrix3x4 *B, CML_Matrix3x4 *out);


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
void cmlc_matrix3x3_mult_vector3(const CML_Matrix3x3 *A, const CML_Vector3 *v, CML_Vector3 *out);


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
void cmlc_vector3_mult_matrix3x3(const CML_Vector3 *v, const CML_Matrix3x3 *A, CML_Vector3 *out);


/**
 * @brief Calculates the determinant of a CML_Matrix3x3.
 * 
 * @param A The matrix operand.
 * 
 * @return The determinant of the matrix.
 */
f32 cmlc_matrix3x3_det(const CML_Matrix3x3 *A);


/**
 * @brief Calculates the inverse of a CML_Matrix3x3 and writes the result to
 *        the out CML_Matrix3x3.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return Success or error code if the matrix is invertible.
 */
CML_Status cmlc_matrix3x3_inv(const CML_Matrix3x3 *A, CML_Matrix3x3 *out);


/**
 * @brief Calculates the transpose of a CML_Matrix3x3 and writes the result to
 *        the out CML_Matrix3x3.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix3x3_transpose(const CML_Matrix3x3 *A, CML_Matrix3x3 *out);


/**
 * @brief Calculates the trace of a CML_Matrix3x3.
 * 
 * @param A The matrix operand.
 * 
 * @return The trace of the matrix.
 */
f32 cmlc_matrix3x3_trace(const CML_Matrix3x3 *A);


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
void cmlc_matrix3x3_gen_scale(f32 x, f32 y, f32 z, CML_Matrix3x3 *out);


/**
 * @brief Generates the inverse of a scale matrix and writes the result to the
 *        out CML_Matrix3x3.
 * 
 * @param scale The input scale matrix.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix3x3_gen_invscale(const CML_Matrix3x3 *scale, CML_Matrix3x3 *out);


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
void cmlc_matrix3x3_gen_shearx(f32 y, f32 z, CML_Matrix3x3 *out);


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
void cmlc_matrix3x3_gen_sheary(f32 x, f32 z, CML_Matrix3x3 *out);


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
void cmlc_matrix3x3_gen_shearz(f32 x, f32 y, CML_Matrix3x3 *out);


/**
 * @brief Generates the inverse of a shear matrix and writes the result to the
 *        out CML_Matrix3x3.
 * 
 * @param shear The input shear matrix.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix3x3_gen_invshear(const CML_Matrix3x3 *shear, CML_Matrix3x3 *out);


/**
 * @brief Generates the left-handed rotation matrix (clockwise) along the x 
 *        axis and writes the result to the out CML_Matrix3x3.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix3x3_genlh_rotationx(f32 angle, CML_Matrix3x3 *out);


/**
 * @brief Generates the left-handed rotation matrix (clockwise) along the y 
 *        axis and writes the result to the out CML_Matrix3x3.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix3x3_genlh_rotationy(f32 angle, CML_Matrix3x3 *out);


/**
 * @brief Generates the left-handed rotation matrix (clockwise) along the z 
 *        axis and writes the result to the out CML_Matrix3x3.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix3x3_genlh_rotationz(f32 angle, CML_Matrix3x3 *out);


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
void cmlc_matrix3x3_genlh_rotation(f32 angle, const CML_Vector3 *axis, CML_Matrix3x3 *out);


/**
 * @brief Generates the right-handed rotation matrix (counter clockwise) along 
 *        the x axis and writes the result to the out CML_Matrix3x3.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix3x3_genrh_rotationx(f32 angle, CML_Matrix3x3 *out);


/**
 * @brief Generates the right-handed rotation matrix (counter clockwise) along 
 *        the y axis and writes the result to the out CML_Matrix3x3.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix3x3_genrh_rotationy(f32 angle, CML_Matrix3x3 *out);


/**
 * @brief Generates the right-handed rotation matrix (counter clockwise) along 
 *        the z axis and writes the result to the out CML_Matrix3x3.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix3x3_genrh_rotationz(f32 angle, CML_Matrix3x3 *out);


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
void cmlc_matrix3x3_genrh_rotation(f32 angle, const CML_Vector3 *axis, CML_Matrix3x3 *out);


/**
 * @brief Generates the inverse of a rotation matrix and writes the result to
 *        the out CML_Matrix3x3.
 * 
 * @param rotation The input rotation matrix.
 * @param out      The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix3x3_gen_invrotation(const CML_Matrix3x3 *rotation, CML_Matrix3x3 *out);


/**
 * @brief Compares two CML_Matrix3x3s for equality.
 * 
 * @param A The left matrix operand.
 * @param B The right matrix operand.
 * 
 * @return Boolean value indicating whether the matrices are equal.
 */
b8 cmlc_matrix3x3_eq(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B);


/**
 * @brief Returns a debug message comparing the input CML_Matrix3x3s.
 *
 * @param expected The expected matrix.
 * @param got      The result matrix.
 * 
 * @return A string containing the debug message.
 */
char *cmlc_matrix3x3_debug(const CML_Matrix3x3 *expected, const CML_Matrix3x3 *got);



/**
 * @brief Adds two CML_Matrix4x4 and writes the result to the out CML_Matrix4x4.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix4x4_add(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B, CML_Matrix4x4 *out);


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
void cmlc_matrix4x4_sub(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B, CML_Matrix4x4 *out);


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
void cmlc_matrix4x4_scale(const CML_Matrix4x4 *A, f32 t, CML_Matrix4x4 *out);


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
void cmlc_matrix4x4_mult(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B, CML_Matrix4x4 *out);


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
void cmlc_matrix4x4_mult_matrix4x2(const CML_Matrix4x4 *A, const CML_Matrix4x2 *B, CML_Matrix4x2 *out);


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
void cmlc_matrix4x4_mult_matrix4x3(const CML_Matrix4x4 *A, const CML_Matrix4x3 *B, CML_Matrix4x3 *out);


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
void cmlc_matrix4x4_mult_vector4(const CML_Matrix4x4 *A, const CML_Vector4 *v, CML_Vector4 *out);


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
void cmlc_vector4_mult_matrix4x4(const CML_Vector4 *v, const CML_Matrix4x4 *A, CML_Vector4 *out);


/**
 * @brief Calculates the determinant of a CML_Matrix4x4.
 * 
 * @param A The matrix operand.
 * 
 * @return The determinant of the matrix.
 */
f32 cmlc_matrix4x4_det(const CML_Matrix4x4 *A);


/**
 * @brief Calculates the inverse of a CML_Matrix4x4 and writes the result to
 *        the out CML_Matrix4x4.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return Success or error code if the matrix is invertible.
 */
CML_Status cmlc_matrix4x4_inv(const CML_Matrix4x4 *A, CML_Matrix4x4 *out);


/**
 * @brief Calculates the transpose of a CML_Matrix4x4 and writes the result to
 *        the out CML_Matrix4x4.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix4x4_transpose(const CML_Matrix4x4 *A, CML_Matrix4x4 *out);


/**
 * @brief Calculates the trace of a CML_Matrix4x4.
 * 
 * @param A The matrix operand.
 * 
 * @return The trace of the matrix.
 */
f32 cmlc_matrix4x4_trace(const CML_Matrix4x4 *A);


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
void cmlc_matrix4x4_gen_scale(f32 x, f32 y, f32 z, CML_Matrix4x4 *out);


/**
 * @brief Generates the inverse of a scale matrix and writes the result to the
 *        out CML_Matrix4x4.
 * 
 * @param scale The input scale matrix.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix4x4_gen_invscale(const CML_Matrix4x4 *scale, CML_Matrix4x4 *out);


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
void cmlc_matrix4x4_gen_shearx(f32 y, f32 z, CML_Matrix4x4 *out);


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
void cmlc_matrix4x4_gen_sheary(f32 x, f32 z, CML_Matrix4x4 *out);


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
void cmlc_matrix4x4_gen_shearz(f32 x, f32 y, CML_Matrix4x4 *out);


/**
 * @brief Generates the inverse of a shear matrix and writes the result to the
 *        out CML_Matrix4x4.
 * 
 * @param shear The input shear matrix.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix4x4_gen_invshear(const CML_Matrix4x4 *shear, CML_Matrix4x4 *out);


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
void cmlc_matrix4x4_gen_translation(f32 x, f32 y, f32 z, CML_Matrix4x4 *out);


/**
 * @brief Generates the inverse of a translation matrix and writes the result 
 *        to the out CML_Matrix4x4.
 * 
 * @param translation The input translation matrix.
 * @param out         The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix4x4_gen_invtranslation(const CML_Matrix4x4 *translation, CML_Matrix4x4 *out);


/**
 * @brief Generates the left-handed rotation matrix (clockwise) along the x 
 *        axis and writes the result to the out CML_Matrix4x4.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix4x4_genlh_rotationx(f32 angle, CML_Matrix4x4 *out);


/**
 * @brief Generates the left-handed rotation matrix (clockwise) along the y 
 *        axis and writes the result to the out CML_Matrix4x4.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix4x4_genlh_rotationy(f32 angle, CML_Matrix4x4 *out);


/**
 * @brief Generates the left-handed rotation matrix (clockwise) along the z 
 *        axis and writes the result to the out CML_Matrix4x4.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix4x4_genlh_rotationz(f32 angle, CML_Matrix4x4 *out);


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
void cmlc_matrix4x4_genlh_rotation(f32 angle, const CML_Vector3 *axis, CML_Matrix4x4 *out);


/**
 * @brief Generates the right-handed rotation matrix (counter clockwise) along 
 *        the x axis and writes the result to the out CML_Matrix4x4.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix4x4_genrh_rotationx(f32 angle, CML_Matrix4x4 *out);


/**
 * @brief Generates the right-handed rotation matrix (counter clockwise) along 
 *        the y axis and writes the result to the out CML_Matrix4x4.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix4x4_genrh_rotationy(f32 angle, CML_Matrix4x4 *out);


/**
 * @brief Generates the right-handed rotation matrix (counter clockwise) along 
 *        the z axis and writes the result to the out CML_Matrix4x4.
 * 
 * @param angle The angle of rotation in radians.
 * @param out   The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix4x4_genrh_rotationz(f32 angle, CML_Matrix4x4 *out);


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
void cmlc_matrix4x4_genrh_rotation(f32 angle, const CML_Vector3 *axis, CML_Matrix4x4 *out);


/**
 * @brief Generates the inverse of a rotation matrix and writes the result to
 *        the out CML_Matrix4x4.
 * 
 * @param rotation The input rotation matrix.
 * @param out      The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix4x4_gen_invrotation(const CML_Matrix4x4 *rotation, CML_Matrix4x4 *out);


/**
 * @brief Compares two CML_Matrix4x4s for equality.
 * 
 * @param A The left matrix operand.
 * @param B The right matrix operand.
 * 
 * @return Boolean value indicating whether the matrices are equal.
 */
b8 cmlc_matrix4x4_eq(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B);


/**
 * @brief Returns a debug message comparing the input CML_Matrix4x4s.
 *
 * @param expected The expected matrix.
 * @param got      The result matrix.
 * 
 * @return A string containing the debug message.
 */
char *cmlc_matrix4x4_debug(const CML_Matrix4x4 *expected, const CML_Matrix4x4 *got);



/**
 * @brief Adds two CML_Matrix2x3 and writes the result to the out CML_Matrix2x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix2x3_add(const CML_Matrix2x3 *A, const CML_Matrix2x3 *B, CML_Matrix2x3 *out);


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
void cmlc_matrix2x3_sub(const CML_Matrix2x3 *A, const CML_Matrix2x3 *B, CML_Matrix2x3 *out);


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
void cmlc_matrix2x3_scale(const CML_Matrix2x3 *A, f32 t, CML_Matrix2x3 *out);


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
void cmlc_matrix2x3_mult_matrix3x2(const CML_Matrix2x3 *A, const CML_Matrix3x2 *B, CML_Matrix2x2 *out);


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
void cmlc_matrix2x3_mult_matrix3x3(const CML_Matrix2x3 *A, const CML_Matrix3x3 *B, CML_Matrix2x3 *out);


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
void cmlc_matrix2x3_mult_matrix3x4(const CML_Matrix2x3 *A, const CML_Matrix3x4 *B, CML_Matrix2x4 *out);


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
void cmlc_matrix2x3_mult_vector3(const CML_Matrix2x3 *A, const CML_Vector3 *v, CML_Vector2 *out);


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
void cmlc_vector2_mult_matrix2x3(const CML_Vector2 *v, const CML_Matrix2x3 *A, CML_Vector3 *out);


/**
 * @brief Calculates the transpose of a CML_Matrix2x3 and writes the result to
 *        the out CML_Matrix3x2.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix2x3_transpose(const CML_Matrix2x3 *A, CML_Matrix3x2 *out);


/**
 * @brief Compares two CML_Matrix2x3s for equality.
 * 
 * @param A The left matrix operand.
 * @param B The right matrix operand.
 * 
 * @return Boolean value indicating whether the matrices are equal.
 */
b8 cmlc_matrix2x3_eq(const CML_Matrix2x3 *A, const CML_Matrix2x3 *B);


/**
 * @brief Returns a debug message comparing the input CML_Matrix2x3s.
 *
 * @param expected Expected matrix.
 * @param got      Result matrix.
 * 
 * @return A string containing the debug message.
 */
char *cmlc_matrix2x3_debug(const CML_Matrix2x3 *expected, const CML_Matrix2x3 *got);



/**
 * @brief Adds two CML_Matrix2x4 and writes the result to the out CML_Matrix2x4.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix2x4_add(const CML_Matrix2x4 *A, const CML_Matrix2x4 *B, CML_Matrix2x4 *out);


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
void cmlc_matrix2x4_sub(const CML_Matrix2x4 *A, const CML_Matrix2x4 *B, CML_Matrix2x4 *out);


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
void cmlc_matrix2x4_scale(const CML_Matrix2x4 *A, f32 t, CML_Matrix2x4 *out);


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
void cmlc_matrix2x4_mult_matrix4x2(const CML_Matrix2x4 *A, const CML_Matrix4x2 *B, CML_Matrix2x2 *out);


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
void cmlc_matrix2x4_mult_matrix4x3(const CML_Matrix2x4 *A, const CML_Matrix4x3 *B, CML_Matrix2x3 *out);


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
void cmlc_matrix2x4_mult_matrix4x4(const CML_Matrix2x4 *A, const CML_Matrix4x4 *B, CML_Matrix2x4 *out);


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
void cmlc_matrix2x4_mult_vector4(const CML_Matrix2x4 *A, const CML_Vector4 *v, CML_Vector2 *out);


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
void cmlc_vector2_mult_matrix2x4(const CML_Vector2 *v, const CML_Matrix2x4 *A, CML_Vector4 *out);


/**
 * @brief Calculates the transpose of a CML_Matrix2x4 and writes the result to
 *        the out CML_Matrix4x2.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix2x4_transpose(const CML_Matrix2x4 *A, CML_Matrix4x2 *out);


/**
 * @brief Compares two CML_Matrix2x4s for equality.
 * 
 * @param A The left matrix operand.
 * @param B The right matrix operand.
 * 
 * @return Boolean value indicating whether the matrices are equal.
 */
b8 cmlc_matrix2x4_eq(const CML_Matrix2x4 *A, const CML_Matrix2x4 *B);


/**
 * @brief Returns a debug message comparing the input CML_Matrix2x4s.
 *
 * @param expected Expected matrix.
 * @param got      Result matrix.
 * 
 * @return A string containing the debug message.
 */
char *cmlc_matrix2x4_debug(const CML_Matrix2x4 *expected, const CML_Matrix2x4 *got);



/**
 * @brief Adds two CML_Matrix3x2 and writes the result to the out CML_Matrix3x2.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix3x2_add(const CML_Matrix3x2 *A, const CML_Matrix3x2 *B, CML_Matrix3x2 *out);


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
void cmlc_matrix3x2_sub(const CML_Matrix3x2 *A, const CML_Matrix3x2 *B, CML_Matrix3x2 *out);


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
void cmlc_matrix3x2_scale(const CML_Matrix3x2 *A, f32 t, CML_Matrix3x2 *out);


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
void cmlc_matrix3x2_mult_matrix2x2(const CML_Matrix3x2 *A, const CML_Matrix2x2 *B, CML_Matrix3x2 *out);


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
void cmlc_matrix3x2_mult_matrix2x3(const CML_Matrix3x2 *A, const CML_Matrix2x3 *B, CML_Matrix3x3 *out);


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
void cmlc_matrix3x2_mult_matrix2x4(const CML_Matrix3x2 *A, const CML_Matrix2x4 *B, CML_Matrix3x4 *out);


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
void cmlc_matrix3x2_mult_vector2(const CML_Matrix3x2 *A, const CML_Vector2 *v, CML_Vector3 *out);


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
void cmlc_vector3_mult_matrix3x2(const CML_Vector3 *v, const CML_Matrix3x2 *A, CML_Vector2 *out);


/**
 * @brief Calculates the transpose of a CML_Matrix3x2 and writes the result to
 *        the out CML_Matrix2x3.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix3x2_transpose(const CML_Matrix3x2 *A, CML_Matrix2x3 *out);


/**
 * @brief Compares two CML_Matrix3x2s for equality.
 * 
 * @param A The left matrix operand.
 * @param B The right matrix operand.
 * 
 * @return Boolean value indicating whether the matrices are equal.
 */
b8 cmlc_matrix3x2_eq(const CML_Matrix3x2 *A, const CML_Matrix3x2 *B);


/**
 * @brief Returns a debug message comparing the input CML_Matrix3x2s.
 *
 * @param expected Expected matrix.
 * @param got      Result matrix.
 * 
 * @return A string containing the debug message.
 */
char *cmlc_matrix3x2_debug(const CML_Matrix3x2 *expected, const CML_Matrix3x2 *got);



/**
 * @brief Adds two CML_Matrix3x4 and writes the result to the out CML_Matrix3x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix3x4_add(const CML_Matrix3x4 *A, const CML_Matrix3x4 *B, CML_Matrix3x4 *out);


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
void cmlc_matrix3x4_sub(const CML_Matrix3x4 *A, const CML_Matrix3x4 *B, CML_Matrix3x4 *out);


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
void cmlc_matrix3x4_scale(const CML_Matrix3x4 *A, f32 t, CML_Matrix3x4 *out);


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
void cmlc_matrix3x4_mult_matrix4x2(const CML_Matrix3x4 *A, const CML_Matrix4x2 *B, CML_Matrix3x2 *out);


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
void cmlc_matrix3x4_mult_matrix4x3(const CML_Matrix3x4 *A, const CML_Matrix4x3 *B, CML_Matrix3x3 *out);


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
void cmlc_matrix3x4_mult_matrix4x4(const CML_Matrix3x4 *A, const CML_Matrix4x4 *B, CML_Matrix3x4 *out);


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
void cmlc_matrix3x4_mult_vector4(const CML_Matrix3x4 *A, const CML_Vector4 *v, CML_Vector3 *out);


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
void cmlc_vector3_mult_matrix3x4(const CML_Vector3 *v, const CML_Matrix3x4 *A, CML_Vector4 *out);


/**
 * @brief Calculates the transpose of a CML_Matrix3x4 and writes the result to
 *        the out CML_Matrix4x3.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix3x4_transpose(const CML_Matrix3x4 *A, CML_Matrix4x3 *out);


/**
 * @brief Compares two CML_Matrix3x4s for equality.
 * 
 * @param A The left matrix operand.
 * @param B The right matrix operand.
 * 
 * @return Boolean value indicating whether the matrices are equal.
 */
b8 cmlc_matrix3x4_eq(const CML_Matrix3x4 *A, const CML_Matrix3x4 *B);


/**
 * @brief Returns a debug message comparing the input CML_Matrix3x4s.
 *
 * @param expected Expected matrix.
 * @param got      Result matrix.
 * 
 * @return A string containing the debug message.
 */
char *cmlc_matrix3x4_debug(const CML_Matrix3x4 *expected, const CML_Matrix3x4 *got);



/**
 * @brief Adds two CML_Matrix4x2 and writes the result to the out CML_Matrix4x2.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix4x2_add(const CML_Matrix4x2 *A, const CML_Matrix4x2 *B, CML_Matrix4x2 *out);


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
void cmlc_matrix4x2_sub(const CML_Matrix4x2 *A, const CML_Matrix4x2 *B, CML_Matrix4x2 *out);


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
void cmlc_matrix4x2_scale(const CML_Matrix4x2 *A, f32 t, CML_Matrix4x2 *out);


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
void cmlc_matrix4x2_mult_matrix2x2(const CML_Matrix4x2 *A, const CML_Matrix2x2 *B, CML_Matrix4x2 *out);


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
void cmlc_matrix4x2_mult_matrix2x3(const CML_Matrix4x2 *A, const CML_Matrix2x3 *B, CML_Matrix4x3 *out);


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
void cmlc_matrix4x2_mult_matrix2x4(const CML_Matrix4x2 *A, const CML_Matrix2x4 *B, CML_Matrix4x4 *out);


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
void cmlc_matrix4x2_mult_vector2(const CML_Matrix4x2 *A, const CML_Vector2 *v, CML_Vector4 *out);


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
void cmlc_vector4_mult_matrix4x2(const CML_Vector4 *v, const CML_Matrix4x2 *A, CML_Vector2 *out);


/**
 * @brief Calculates the transpose of a CML_Matrix4x2 and writes the result to
 *        the out CML_Matrix2x4.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix4x2_transpose(const CML_Matrix4x2 *A, CML_Matrix2x4 *out);


/**
 * @brief Compares two CML_Matrix4x2s for equality.
 * 
 * @param A The left matrix operand.
 * @param B The right matrix operand.
 * 
 * @return Boolean value indicating whether the matrices are equal.
 */
b8 cmlc_matrix4x2_eq(const CML_Matrix4x2 *A, const CML_Matrix4x2 *B);


/**
 * @brief Returns a debug message comparing the input CML_Matrix4x2s.
 *
 * @param expected Expected matrix.
 * @param got      Result matrix.
 * 
 * @return A string containing the debug message.
 */
char *cmlc_matrix4x2_debug(const CML_Matrix4x2 *expected, const CML_Matrix4x2 *got);



/**
 * @brief Adds two CML_Matrix4x3 and writes the result to the out CML_Matrix4x3.
 * 
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix4x3_add(const CML_Matrix4x3 *A, const CML_Matrix4x3 *B, CML_Matrix4x3 *out);


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
void cmlc_matrix4x3_sub(const CML_Matrix4x3 *A, const CML_Matrix4x3 *B, CML_Matrix4x3 *out);


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
void cmlc_matrix4x3_scale(const CML_Matrix4x3 *A, f32 t, CML_Matrix4x3 *out);


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
void cmlc_matrix4x3_mult_matrix3x2(const CML_Matrix4x3 *A, const CML_Matrix3x2 *B, CML_Matrix4x2 *out);


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
void cmlc_matrix4x3_mult_matrix3x3(const CML_Matrix4x3 *A, const CML_Matrix3x3 *B, CML_Matrix4x3 *out);


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
void cmlc_matrix4x3_mult_matrix3x4(const CML_Matrix4x3 *A, const CML_Matrix3x4 *B, CML_Matrix4x4 *out);


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
void cmlc_matrix4x3_mult_vector3(const CML_Matrix4x3 *A, const CML_Vector3 *v, CML_Vector4 *out);


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
void cmlc_vector4_mult_matrix4x3(const CML_Vector4 *v, const CML_Matrix4x3 *A, CML_Vector3 *out);


/**
 * @brief Calculates the transpose of a CML_Matrix4x3 and writes the result to
 *        the out CML_Matrix3x4.
 * 
 * @param A   The matrix operand.
 * @param out The output matrix.
 * 
 * @return void.
 */
void cmlc_matrix4x3_transpose(const CML_Matrix4x3 *A, CML_Matrix3x4 *out);


/**
 * @brief Compares two CML_Matrix4x3s for equality.
 * 
 * @param A The left matrix operand.
 * @param B The right matrix operand.
 * 
 * @return Boolean value indicating whether the matrices are equal.
 */
b8 cmlc_matrix4x3_eq(const CML_Matrix4x3 *A, const CML_Matrix4x3 *B);


/**
 * @brief Returns a debug message comparing the input CML_Matrix4x3s.
 *
 * @param expected Expected matrix.
 * @param got      Result matrix.
 * 
 * @return A string containing the debug message.
 */
char *cmlc_matrix4x3_debug(const CML_Matrix4x3 *expected, const CML_Matrix4x3 *got);


#endif /* CAMEL_CFIXED_MATRIX */
