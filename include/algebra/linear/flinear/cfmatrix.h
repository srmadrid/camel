/******************************************************************************
 * Filename: cfmatrix.h
 * 
 * Description:
 *      Declarations for the compiled version of the fixed matrix manipulation 
 *      functions of CAMEL.
 * 
 * Author: Sergio Madrid
 * Created on: 26/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/

#ifndef CAMEL_CFIXED_MATRIX
#define CAMEL_CFIXED_MATRIX


#include <stdlib.h>
#include <math.h>

#include "../../../core/macros.h"
#include "../../../core/err.h"
#include "../../../core/constants.h"
#include "fmatrix.h"


/******************************************************************************
 * Function: cmlc_matrix2x2_add
 * 
 * Description:
 *     Adds two CML_Matrix2x2 and writes the result to the out CML_Matrix2x2.
 * 
 * Parameters:
 *      CML_Matrix2x2 *A   - The first matrix operand.
 *      CML_Matrix2x2 *B   - The second matrix operand.
 *      CML_Matrix2x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x2_add(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B, CML_Matrix2x2 *out);

/******************************************************************************
 * Function: cmlc_matrix2x2_sub
 * 
 * Description:
 *     Subtracts two CML_Matrix2x2 and writes the result to the out 
 *     CML_Matrix2x2.
 * 
 * Parameters:
 *      CML_Matrix2x2 *A   - The first matrix operand.
 *      CML_Matrix2x2 *B   - The second matrix operand.
 *      CML_Matrix2x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x2_sub(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x2_scale
 * 
 * Description:
 *     Multiplies a CML_Matrix2x2 by a scalar, and writes the result to the out 
 *     CML_Matrix2x2.
 * 
 * Parameters:
 *      CML_Matrix2x2 *A   - The matrix operand.
 *      f32         t   - The scalar.
 *      CML_Matrix2x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x2_scale(const CML_Matrix2x2 *A, f32 t, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x2_mult
 * 
 * Description:
 *     Multiplies two CML_Matrix2x2, and writes the result to the out 
 *     CML_Matrix2x2.
 * 
 * Parameters:
 *      CML_Matrix2x2 *A   - The first matrix operand.
 *      CML_Matrix2x2 *B   - The second matrix operand.
 *      CML_Matrix2x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x2_mult(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x2_mult_matrix2x3
 * 
 * Description:
 *      Multiplies a CML_Matrix2x2 by a CML_Matrix2x3, and writes the result to 
 *      the out CML_Matrix2x3.
 * 
 * Parameters:
 *      CML_Matrix2x2 *A   - The first matrix operand.
 *      CML_Matrix2x3 *B   - The second matrix operand.
 *      CML_Matrix2x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x2_mult_matrix2x3(const CML_Matrix2x2 *A, const CML_Matrix2x3 *B, CML_Matrix2x3 *out);


/******************************************************************************
 * Function: cmlc_matrix2x2_mult_matrix2x4
 * 
 * Description:
 *      Multiplies a CML_Matrix2x2 by a CML_Matrix2x4, and writes the result to 
 *      the out CML_Matrix2x4.
 * 
 * Parameters:
 *      CML_Matrix2x2 *A   - The first matrix operand.
 *      CML_Matrix2x4 *B   - The second matrix operand.
 *      CML_Matrix2x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x2_mult_matrix2x4(const CML_Matrix2x2 *A, const CML_Matrix2x4 *B, CML_Matrix2x4 *out);


/******************************************************************************
 * Function: cmlc_matrix2x2_mult_vector2
 * 
 * Description:
 *     Multiplies a CML_Matrix2x2 by a CML_Vector2, and writes the result to 
 *     the out CML_Vector2.
 * 
 * Parameters:
 *      CML_Matrix2x2 *A   - The matrix operand.
 *      CML_Vector2   *v   - The vector operand.
 *      CML_Vector2   *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x2_mult_vector2(const CML_Matrix2x2 *A, const CML_Vector2 *v, CML_Vector2 *out);


/******************************************************************************
 * Function: cmlc_vector2_mult_matrix2x2
 * 
 * Description:
 *     Multiplies a CML_Vector2 by a CML_Matrix2x2, and writes the result to 
 *     the out CML_Vector2.
 * 
 * Parameters:
 *      CML_Vector2   *v   - The vector operand.
 *      CML_Matrix2x2 *A   - The matrix operand.
 *      CML_Vector2   *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector2_mult_matrix2x2(const CML_Vector2 *v, const CML_Matrix2x2 *A, CML_Vector2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x2_det
 * 
 * Description:
 *     Calculates the determinant of a CML_Matrix2x2.
 * 
 * Parameters:
 *      CML_Matrix2x2 *A - The matrix operand.
 * 
 * Returns:
 *      The determinant of the matrix.
 *****************************************************************************/
f32 cmlc_matrix2x2_det(const CML_Matrix2x2 *A);


/******************************************************************************
 * Function: cmlc_matrix2x2_inv
 * 
 * Description:
 *     Calculates the inverse of a CML_Matrix2x2.
 * 
 * Parameters:
 *      CML_Matrix2x2 *A   - The matrix operand.
 *      CML_Matrix2x2 *out - The output matrix.
 * 
 * Returns:
 *      Success or error code if the matrix is invertible.
 *****************************************************************************/
CML_Status cmlc_matrix2x2_inv(const CML_Matrix2x2 *A, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x2_transpose
 * 
 * Description:
 *     Calculates the transpose of a CML_Matrix2x2.
 * 
 * Parameters:
 *      CML_Matrix2x2 *A   - The matrix operand.
 *      CML_Matrix2x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x2_transpose(const CML_Matrix2x2 *A, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x2_trace
 * 
 * Description:
 *     Calculates the trace of a CML_Matrix2x2.
 * 
 * Parameters:
 *      CML_Matrix2x2 *A - The matrix operand.
 * 
 * Returns:
 *      The trace of the matrix.
 *****************************************************************************/
f32 cmlc_matrix2x2_trace(const CML_Matrix2x2 *A);


/******************************************************************************
 * Function: cmlc_matrix2x2_gen_scale
 * 
 * Description:
 *      Generates a scale matrix.
 * 
 * Parameters:
 *      f32 x - The x scale.
 *      f32 y - The y scale.
 *      CML_Matrix2x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x2_gen_scale(f32 x, f32 y, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x2_gen_invscale
 * 
 * Description:
 *      Generates the inverse of a scale matrix.
 * 
 * Parameters:
 *      CML_Matrix2x2 *scale - The scale matrix.
 *      CML_Matrix2x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x2_gen_invscale(const CML_Matrix2x2 *scale, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x2_gen_shearx
 * 
 * Description:
 *      Generates the shear matrix along the x axis.
 * 
 * Parameters:
 *      f32 x - The x shear.
 *      CML_Matrix2x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x2_gen_shearx(f32 x, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x2_gen_sheary
 * 
 * Description:
 *      Generates the shear matrix along the y axis.
 * 
 * Parameters:
 *      f32 x - The y shear.
 *      CML_Matrix2x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x2_gen_sheary(f32 y, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x2_gen_invshear
 * 
 * Description:
 *      Generates the inverse of a shear matrix.
 * 
 * Parameters:
 *      CML_Matrix2x2 *shear - The shear matrix.
 *      CML_Matrix2x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x2_gen_invshear(const CML_Matrix2x2 *shear, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x2_genlh_rotation
 * 
 * Description:
 *      Generates the left-handed rotation matrix (clockwise).
 * 
 * Parameters:
 *      f32 angle - The angle of rotation in radians.
 *      CML_Matrix2x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x2_genlh_rotation(f32 angle, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x2_genrh_rotation
 * 
 * Description:
 *      Generates the right-handed rotation matrix (counter-clockwise).
 * 
 * Parameters:
 *      f32 angle - The angle of rotation in radians.
 *      CML_Matrix2x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x2_genrh_rotation(f32 angle, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x2_gen_invrotation
 * 
 * Description:
 *      Generates the inverse rotation matrix.
 * 
 * Parameters:
 *      CML_Matrix2x2 *rotation - The rotation matrix.
 *      CML_Matrix2x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x2_gen_invrotation(const CML_Matrix2x2 *rotation, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x2_eq
 * 
 * Description:
 *      Compares two CML_Matrix2x2s for equality.
 * 
 * Parameters:
 *      CML_Matrix2x2 *A - The first input vector.
 *      CML_Matrix2x2 *B - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CML_Bool cmlc_matrix2x2_eq(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B);


/******************************************************************************
 * Function: cmlc_matrix2x2_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Matrix2x2s.
 *
 * Parameters:
 *      CML_Matrix2x2 *expected - Expected matrix.
 *      CML_Matrix2x2 *got - Result matrix.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
char *cmlc_matrix2x2_debug(const CML_Matrix2x2 *expected, const CML_Matrix2x2 *got);



/******************************************************************************
 * Function: cmlc_matrix3x3_add
 * 
 * Description:
 *     Adds two CML_Matrix3x3 and writes the result to the out CML_Matrix3x3.
 * 
 * Parameters:
 *      CML_Matrix3x3 *A   - The first matrix operand.
 *      CML_Matrix3x3 *B   - The second matrix operand.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_add(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_sub
 * 
 * Description:
 *     Subtracts two CML_Matrix3x3 and writes the result to the out 
 *     CML_Matrix3x3.
 * 
 * Parameters:
 *      CML_Matrix3x3 *A   - The first matrix operand.
 *      CML_Matrix3x3 *B   - The second matrix operand.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_sub(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_scale
 * 
 * Description:
 *     Multiplies a CML_Matrix3x3 by a scalar, and writes the result to the out 
 *     CML_Matrix3x3.
 * 
 * Parameters:
 *      CML_Matrix3x3 *A   - The matrix operand.
 *      f32         t   - The scalar.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_scale(const CML_Matrix3x3 *A, f32 t, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_mult
 * 
 * Description:
 *     Multiplies two CML_Matrix3x3, and writes the result to the out 
 *     CML_Matrix3x3.
 * 
 * Parameters:
 *      CML_Matrix3x3 *A   - The first matrix operand.
 *      CML_Matrix3x3 *B   - The second matrix operand.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_mult(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_mult_matrix3x2
 * 
 * Description:
 *     Multiplies a CML_Matrix3x3 by a CML_Matrix3x2, and writes the result to the out 
 *     CML_Matrix3x2.
 * 
 * Parameters:
 *      CML_Matrix3x3 *A   - The first matrix operand.
 *      CML_Matrix3x2 *B   - The second matrix operand.
 *      CML_Matrix3x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_mult_matrix3x2(const CML_Matrix3x3 *A, const CML_Matrix3x2 *B, CML_Matrix3x2 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_mult_matrix3x4
 * 
 * Description:
 *     Multiplies a CML_Matrix3x3 by a CML_Matrix3x4, and writes the result to the out 
 *     CML_Matrix3x4.
 * 
 * Parameters:
 *      CML_Matrix3x3 *A   - The first matrix operand.
 *      CML_Matrix3x4 *B   - The second matrix operand.
 *      CML_Matrix3x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_mult_matrix3x4(const CML_Matrix3x3 *A, const CML_Matrix3x4 *B, CML_Matrix3x4 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_mult_vector3
 * 
 * Description:
 *     Multiplies a CML_Matrix3x3 by a CML_Vector3, and writes the result to 
 *     the out CML_Vector3.
 * 
 * Parameters:
 *      CML_Matrix3x3 *A   - The matrix operand.
 *      CML_Vector3   *v   - The vector operand.
 *      CML_Vector3   *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_mult_vector3(const CML_Matrix3x3 *A, const CML_Vector3 *v, CML_Vector3 *out);


/******************************************************************************
 * Function: cmlc_vector3_mult_matrix3x3
 * 
 * Description:
 *     Multiplies a CML_Vector3 by a CML_Matrix3x3, and writes the result to 
 *     the out CML_Vector3.
 * 
 * Parameters:
 *      CML_Vector3   *v   - The vector operand.
 *      CML_Matrix3x3 *A   - The matrix operand.
 *      CML_Vector3   *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector3_mult_matrix3x3(const CML_Vector3 *v, const CML_Matrix3x3 *A, CML_Vector3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_det
 * 
 * Description:
 *     Calculates the determinant of a CML_Matrix3x3.
 * 
 * Parameters:
 *      CML_Matrix3x3 *A - The matrix operand.
 * 
 * Returns:
 *      The determinant of the matrix.
 *****************************************************************************/
f32 cmlc_matrix3x3_det(const CML_Matrix3x3 *A);


/******************************************************************************
 * Function: cmlc_matrix3x3_inv
 * 
 * Description:
 *     Calculates the inverse of a CML_Matrix3x3.
 * 
 * Parameters:
 *      CML_Matrix3x3 *A   - The matrix operand.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      Success or error code if the matrix is invertible.
 *****************************************************************************/
CML_Status cmlc_matrix3x3_inv(const CML_Matrix3x3 *A, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_transpose
 * 
 * Description:
 *     Calculates the transpose of a CML_Matrix3x3.
 * 
 * Parameters:
 *      CML_Matrix3x3 *A   - The matrix operand.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_transpose(const CML_Matrix3x3 *A, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_trace
 * 
 * Description:
 *     Calculates the trace of a CML_Matrix3x3.
 * 
 * Parameters:
 *      CML_Matrix3x3 *A - The matrix operand.
 * 
 * Returns:
 *      The trace of the matrix.
 *****************************************************************************/
f32 cmlc_matrix3x3_trace(const CML_Matrix3x3 *A);


/******************************************************************************
 * Function: cmlc_matrix3x3_gen_scale
 * 
 * Description:
 *      Generates a scale matrix.
 * 
 * Parameters:
 *      f32 x - The x scale.
 *      f32 y - The y scale.
 *      f32 z - The z scale.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      The trace of the matrix.
 *****************************************************************************/
void cmlc_matrix3x3_gen_scale(f32 x, f32 y, f32 z, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_gen_invscale
 * 
 * Description:
 *      Generates the inverse of a scale matrix.
 * 
 * Parameters:
 *      CML_Matrix3x3 *scale - The scale matrix.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_gen_invscale(const CML_Matrix3x3 *scale, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_gen_shearx
 * 
 * Description:
 *      Generates the shear matrix along the x axis.
 * 
 * Parameters:
 *      f32 x - The x shear.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_gen_shearx(f32 y, f32 z, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_gen_sheary
 * 
 * Description:
 *      Generates the shear matrix along the y axis.
 * 
 * Parameters:
 *      f32 x - The x shear.
 *      f32 z - The z shear.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_gen_sheary(f32 x, f32 z, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_gen_shearz
 * 
 * Description:
 *      Generates the shear matrix along the z axis.
 * 
 * Parameters:
 *      f32 x - The x shear.
 *      f32 y - The y shear.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_gen_shearz(f32 x, f32 y, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_gen_invshear
 * 
 * Description:
 *      Generates the inverse of a shear matrix.
 * 
 * Parameters:
 *      CML_Matrix3x3 *shear - The shear matrix.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_gen_invshear(const CML_Matrix3x3 *shear, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_genlh_rotationx
 * 
 * Description:
 *      Generates the left handed rotation matrix (clockwise) along the x axis.
 * 
 * Parameters:
 *      f32 angle - The angle of rotation in radians.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_genlh_rotationx(f32 angle, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_genlh_rotationy
 * 
 * Description:
 *      Generates the left handed rotation matrix (clockwise) along the y axis.
 * 
 * Parameters:
 *      f32 angle - The angle of rotation in radians.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_genlh_rotationy(f32 angle, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_genlh_rotationz
 * 
 * Description:
 *      Generates the left handed rotation matrix (clockwise) along the z axis.
 * 
 * Parameters:
 *      f32 angle - The angle of rotation in radians.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_genlh_rotationz(f32 angle, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_genlh_rotation
 * 
 * Description:
 *      Generates the left handed rotation matrix (clockwise) along an 
 *      arbitrary axis.
 * 
 * Parameters:
 *      f32 angle - The angle of rotation in radians.
 *      CML_Vector3 *axis - The axis of rotation.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_genlh_rotation(f32 angle, const CML_Vector3 *axis, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_genrh_rotationx
 * 
 * Description:
 *      Generates the right handed rotation matrix (counter clockwise) along 
 *      the x axis.
 * 
 * Parameters:
 *      f32 angle - The angle of rotation in radians.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_genrh_rotationx(f32 angle, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_genrh_rotationy
 * 
 * Description:
 *      Generates the right handed rotation matrix (counter clockwise) along 
 *      the y axis.
 * 
 * Parameters:
 *      f32 angle - The angle of rotation in radians.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_genrh_rotationy(f32 angle, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_genrh_rotationz
 * 
 * Description:
 *      Generates the right handed rotation matrix (counter clockwise) along 
 *      the z axis.
 * 
 * Parameters:
 *      f32 angle - The angle of rotation in radians.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_genrh_rotationz(f32 angle, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_genrh_rotation
 * 
 * Description:
 *      Generates the right handed rotation matrix (counter clockwise) along 
 *      an arbitrary axis.
 * 
 * Parameters:
 *      f32 angle - The angle of rotation in radians.
 *      CML_Vector3 *axis - The axis of rotation.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_genrh_rotation(f32 angle, const CML_Vector3 *axis, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_gen_invrotation
 * 
 * Description:
 *      Generates the inverse of a rotation matrix.
 * 
 * Parameters:
 *      CML_Matrix3x3 *rotation - The rotation matrix.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x3_gen_invrotation(const CML_Matrix3x3 *rotation, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_eq
 * 
 * Description:
 *      Compares two CML_Matrix3x3s for equality.
 * 
 * Parameters:
 *      CML_Matrix3x3 *A - The first input vector.
 *      CML_Matrix3x3 *B - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CML_Bool cmlc_matrix3x3_eq(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B);


/******************************************************************************
 * Function: cmlc_matrix3x3_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Matrix3x3s.
 *
 * Parameters:
 *      CML_Matrix3x3 *expected - Expected matrix.
 *      CML_Matrix3x3 *got - Result matrix.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
char *cmlc_matrix3x3_debug(const CML_Matrix3x3 *expected, const CML_Matrix3x3 *got);



/******************************************************************************
 * Function: cmlc_matrix4x4_add
 * 
 * Description:
 *     Adds two CML_Matrix4x4 and writes the result to the out CML_Matrix4x4.
 * 
 * Parameters:
 *      CML_Matrix4x4 *A   - The first matrix operand.
 *      CML_Matrix4x4 *B   - The second matrix operand.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_add(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_sub
 * 
 * Description:
 *     Subtracts two CML_Matrix4x4 and writes the result to the out 
 *     CML_Matrix4x4.
 * 
 * Parameters:
 *      CML_Matrix4x4 *A   - The first matrix operand.
 *      CML_Matrix4x4 *B   - The second matrix operand.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_sub(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_scale
 * 
 * Description:
 *     Multiplies a CML_Matrix4x4 by a scalar, and writes the result to the out 
 *     CML_Matrix4x4.
 * 
 * Parameters:
 *      CML_Matrix4x4 *A   - The matrix operand.
 *      f32         t   - The scalar.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_scale(const CML_Matrix4x4 *A, f32 t, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_mult
 * 
 * Description:
 *     Multiplies two CML_Matrix4x4, and writes the result to the out 
 *     CML_Matrix4x4.
 * 
 * Parameters:
 *      CML_Matrix4x4 *A   - The first matrix operand.
 *      CML_Matrix4x4 *B   - The second matrix operand.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_mult(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_mult_matrix4x2
 * 
 * Description:
 *      Multiplies a CML_Matrix4x4 by a CML_Matrix4x2, and writes the result to 
 *      the out CML_Matrix4x2.
 * 
 * Parameters:
 *      CML_Matrix4x4 *A   - The first matrix operand.
 *      CML_Matrix4x2 *B   - The second matrix operand.
 *      CML_Matrix4x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_mult_matrix4x2(const CML_Matrix4x4 *A, const CML_Matrix4x2 *B, CML_Matrix4x2 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_mult_matrix4x3
 * 
 * Description:
 *      Multiplies a CML_Matrix4x4 by a CML_Matrix4x3, and writes the result to 
 *      the out CML_Matrix4x3.
 * 
 * Parameters:
 *      CML_Matrix4x4 *A   - The first matrix operand.
 *      CML_Matrix4x3 *B   - The second matrix operand.
 *      CML_Matrix4x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_mult_matrix4x3(const CML_Matrix4x4 *A, const CML_Matrix4x3 *B, CML_Matrix4x3 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_mult_vector4
 * 
 * Description:
 *     Multiplies a CML_Matrix4x4 by a CML_Vector4, and writes the result to 
 *     the out CML_Vector4.
 * 
 * Parameters:
 *      CML_Matrix4x4 *A   - The matrix operand.
 *      CML_Vector4   *v   - The vector operand.
 *      CML_Vector4   *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_mult_vector4(const CML_Matrix4x4 *A, const CML_Vector4 *v, CML_Vector4 *out);


/******************************************************************************
 * Function: cmlc_vector4_mult_matrix4x4
 * 
 * Description:
 *     Multiplies a CML_Vector4 by a CML_Matrix4x4, and writes the result to 
 *     the out CML_Vector4.
 * 
 * Parameters:
 *      CML_Vector4   *v   - The vector operand.
 *      CML_Matrix4x4 *A   - The matrix operand.
 *      CML_Vector4   *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector4_mult_matrix4x4(const CML_Vector4 *v, const CML_Matrix4x4 *A, CML_Vector4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_det
 * 
 * Description:
 *     Calculates the determinant of a CML_Matrix4x4.
 * 
 * Parameters:
 *      CML_Matrix4x4 *A - The matrix operand.
 * 
 * Returns:
 *      The determinant of the matrix.
 *****************************************************************************/
f32 cmlc_matrix4x4_det(const CML_Matrix4x4 *A);


/******************************************************************************
 * Function: cmlc_matrix4x4_inv
 * 
 * Description:
 *     Calculates the inverse of a CML_Matrix4x4.
 * 
 * Parameters:
 *      CML_Matrix4x4 *A   - The matrix operand.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      Success or error code if the matrix is invertible.
 *****************************************************************************/
CML_Status cmlc_matrix4x4_inv(const CML_Matrix4x4 *A, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_transpose
 * 
 * Description:
 *     Calculates the transpose of a CML_Matrix4x4.
 * 
 * Parameters:
 *      CML_Matrix4x4 *A   - The matrix operand.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_transpose(const CML_Matrix4x4 *A, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_trace
 * 
 * Description:
 *     Calculates the trace of a CML_Matrix4x4.
 * 
 * Parameters:
 *      CML_Matrix4x4 *A - The matrix operand.
 * 
 * Returns:
 *      The trace of the matrix.
 *****************************************************************************/
f32 cmlc_matrix4x4_trace(const CML_Matrix4x4 *A);


/******************************************************************************
 * Function: cmlc_matrix4x4_gen_scale
 * 
 * Description:
 *      Generates a scale matrix.
 * 
 * Parameters:
 *      f32 x - The x scale.
 *      f32 y - The y scale.
 *      f32 z - The z scale.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_gen_scale(f32 x, f32 y, f32 z, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_gen_invscale
 * 
 * Description:
 *      Generates an inverse scale matrix.
 * 
 * Parameters:
 *      CML_Matrix4x4 *scale - The input matrix.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_gen_invscale(const CML_Matrix4x4 *scale, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_gen_shearx
 * 
 * Description:
 *      Generates a shear matrix along the x axis.
 * 
 * Parameters:
 *      f32 y - The y shear.
 *      f32 z - The z shear.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_gen_shearx(f32 y, f32 z, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_gen_sheary
 * 
 * Description:
 *      Generates a shear matrix along the y axis.
 * 
 * Parameters:
 *      f32 x - The x shear.
 *      f32 z - The z shear.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_gen_sheary(f32 x, f32 z, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_gen_shearz
 * 
 * Description:
 *      Generates a shear matrix along the z axis.
 * 
 * Parameters:
 *      f32 x - The x shear.
 *      f32 y - The y shear.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_gen_shearz(f32 x, f32 y, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_gen_invshear
 * 
 * Description:
 *      Generates an inverse shear matrix.
 * 
 * Parameters:
 *      CML_Matrix4x4 *shear - The shear matrix.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_gen_invshear(const CML_Matrix4x4 *shear, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_gen_translation
 * 
 * Description:
 *      Generates a translation matrix.
 * 
 * Parameters:
 *      f32 x - The x translation.
 *      f32 y - The y translation.
 *      f32 z - The z translation.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_gen_translation(f32 x, f32 y, f32 z, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_gen_invtranslation
 * 
 * Description:
 *      Generates an inverse translation matrix.
 * 
 * Parameters:
 *      CML_Matrix4x4 *translation - The translation matrix.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_gen_invtranslation(const CML_Matrix4x4 *translation, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_genlh_rotationx
 * 
 * Description:
 *      Generates the left handed rotation matrix (clockwise) along the x axis.
 * 
 * Parameters:
 *      f32 angle - The angle of rotation in radians.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_genlh_rotationx(f32 angle, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_genlh_rotationy
 * 
 * Description:
 *      Generates the left handed rotation matrix (clockwise) along 
 *      the y axis.
 * 
 * Parameters:
 *      f32 angle - The angle of rotation in radians.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_genlh_rotationy(f32 angle, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_genlh_rotationz
 * 
 * Description:
 *      Generates the left handed rotation matrix (clockwise) along 
 *      the z axis.
 * 
 * Parameters:
 *      f32 angle - The angle of rotation in radians.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_genlh_rotationz(f32 angle, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_genlh_rotation
 * 
 * Description:
 *      Generates the left handed rotation matrix (clockwise) along
 *      an arbitrary axis.
 * 
 * Parameters:
 *      f32 angle - The angle of rotation in radians.
 *      CML_Vector3 *axis - The axis of rotation.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_genlh_rotation(f32 angle, const CML_Vector3 *axis, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_genrh_rotationx
 * 
 * Description:
 *      Generates the right handed rotation matrix (counter-clockwise) along 
 *      the x axis.
 * 
 * Parameters:
 *      f32 angle - The angle of rotation in radians.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_genrh_rotationx(f32 angle, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_genrh_rotationy
 * 
 * Description:
 *      Generates the right handed rotation matrix (counter-clockwise) along 
 *      the y axis.
 * 
 * Parameters:
 *      f32 angle - The angle of rotation in radians.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_genrh_rotationy(f32 angle, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_genrh_rotationz
 * 
 * Description:
 *      Generates the right handed rotation matrix (counter-clockwise) along 
 *      the z axis.
 * 
 * Parameters:
 *      f32 angle - The angle of rotation in radians.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_genrh_rotationz(f32 angle, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_genrh_rotation
 * 
 * Description:
 *      Generates the right handed rotation matrix (counter-clockwise) along
 *      an arbitrary axis.
 * 
 * Parameters:
 *      f32 angle - The angle of rotation in radians.
 *      CML_Vector3 *axis - The axis of rotation.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_genrh_rotation(f32 angle, const CML_Vector3 *axis, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_gen_invrotation
 * 
 * Description:
 *      Generates the inverse of a rotation matrix.
 * 
 * Parameters:
 *      CML_Matrix4x4 *rotation - The rotation matrix.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x4_gen_invrotation(const CML_Matrix4x4 *rotation, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_eq
 * 
 * Description:
 *      Compares two CML_Matrix4x4s for equality.
 * 
 * Parameters:
 *      CML_Matrix4x4 *A - The first input vector.
 *      CML_Matrix4x4 *B - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CML_Bool cmlc_matrix4x4_eq(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B);


/******************************************************************************
 * Function: cmlc_matrix4x4_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Matrix4x4s.
 *
 * Parameters:
 *      CML_Matrix4x4 *expected - Expected matrix.
 *      CML_Matrix4x4 *got - Result matrix.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
char *cmlc_matrix4x4_debug(const CML_Matrix4x4 *expected, const CML_Matrix4x4 *got);



/******************************************************************************
 * Function: cmlc_matrix2x3_add
 * 
 * Description:
 *     Adds two CML_Matrix2x3 and writes the result to the out CML_Matrix2x3.
 * 
 * Parameters:
 *      CML_Matrix2x3 *A   - The first matrix operand.
 *      CML_Matrix2x3 *B   - The second matrix operand.
 *      CML_Matrix2x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x3_add(const CML_Matrix2x3 *A, const CML_Matrix2x3 *B, CML_Matrix2x3 *out);


/******************************************************************************
 * Function: cmlc_matrix2x3_sub
 * 
 * Description:
 *     Subtracts two CML_Matrix2x3 and writes the result to the out 
 *     CML_Matrix2x3.
 * 
 * Parameters:
 *      CML_Matrix2x3 *A   - The first matrix operand.
 *      CML_Matrix2x3 *B   - The second matrix operand.
 *      CML_Matrix2x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x3_sub(const CML_Matrix2x3 *A, const CML_Matrix2x3 *B, CML_Matrix2x3 *out);


/******************************************************************************
 * Function: cmlc_matrix2x3_scale
 * 
 * Description:
 *     Multiplies a CML_Matrix2x3 by a scalar, and writes the result to the out 
 *     CML_Matrix2x3.
 * 
 * Parameters:
 *      CML_Matrix2x3 *A   - The matrix operand.
 *      f32         t   - The scalar.
 *      CML_Matrix2x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x3_scale(const CML_Matrix2x3 *A, f32 t, CML_Matrix2x3 *out);


/******************************************************************************
 * Function: cmlc_matrix2x3_mult_matrix3x2
 * 
 * Description:
 *     Multiplies a CML_Matrix2x3 by a CML_Matrix3x2, and writes the result to 
 *     the out CML_Matrix2x2.
 * 
 * Parameters:
 *      CML_Matrix2x3 *A   - The first matrix operand.
 *      CML_Matrix3x3 *B   - The second vector operand.
 *      CML_Matrix2x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x3_mult_matrix3x2(const CML_Matrix2x3 *A, const CML_Matrix3x2 *B, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x3_mult_matrix3x3
 * 
 * Description:
 *     Multiplies a CML_Matrix2x3 by a CML_Matrix3x3, and writes the result to 
 *     the out CML_Matrix2x3.
 * 
 * Parameters:
 *      CML_Matrix2x3 *A   - The first matrix operand.
 *      CML_Matrix3x3 *B   - The second vector operand.
 *      CML_Matrix2x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x3_mult_matrix3x3(const CML_Matrix2x3 *A, const CML_Matrix3x3 *B, CML_Matrix2x3 *out);


/******************************************************************************
 * Function: cmlc_matrix2x3_mult_matrix3x4
 * 
 * Description:
 *     Multiplies a CML_Matrix2x3 by a CML_Matrix3x4, and writes the result to 
 *     the out CML_Matrix2x4.
 * 
 * Parameters:
 *      CML_Matrix2x3 *A   - The first matrix operand.
 *      CML_Matrix3x3 *B   - The second vector operand.
 *      CML_Matrix2x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x3_mult_matrix3x4(const CML_Matrix2x3 *A, const CML_Matrix3x4 *B, CML_Matrix2x4 *out);


/******************************************************************************
 * Function: cmlc_matrix2x3_mult_vector3
 * 
 * Description:
 *     Multiplies a CML_Matrix2x3 by a CML_Vector3, and writes the result to 
 *     the out CML_Vector2.
 * 
 * Parameters:
 *      CML_Matrix2x3 *A   - The matrix operand.
 *      CML_Vector3   *v   - The vector operand.
 *      CML_Vector2   *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x3_mult_vector3(const CML_Matrix2x3 *A, const CML_Vector3 *v, CML_Vector2 *out);


/******************************************************************************
 * Function: cmlc_vector2_mult_matrix2x3
 * 
 * Description:
 *     Multiplies a CML_Vector2 by a CML_Matrix2x3, and writes the result to 
 *     the out CML_Vector3.
 * 
 * Parameters:
 *      CML_Vector2   *v   - The vector operand.
 *      CML_Matrix2x3 *A   - The matrix operand.
 *      CML_Vector3   *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector2_mult_matrix2x3(const CML_Vector2 *v, const CML_Matrix2x3 *A, CML_Vector3 *out);


/******************************************************************************
 * Function: cmlc_matrix2x3_transpose
 * 
 * Description:
 *     Calculates the transpose of a CML_Matrix2x3.
 * 
 * Parameters:
 *      CML_Matrix2x3 *A   - The matrix operand.
 *      CML_Matrix3x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x3_transpose(const CML_Matrix2x3 *A, CML_Matrix3x2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x3_eq
 * 
 * Description:
 *      Compares two CML_Matrix2x3s for equality.
 * 
 * Parameters:
 *      CML_Matrix2x3 *A - The first input vector.
 *      CML_Matrix2x3 *B - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CML_Bool cmlc_matrix2x3_eq(const CML_Matrix2x3 *A, const CML_Matrix2x3 *B);


/******************************************************************************
 * Function: cmlc_matrix2x3_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Matrix2x3s.
 *
 * Parameters:
 *      CML_Matrix2x3 *expected - Expected matrix.
 *      CML_Matrix2x3 *got - Result matrix.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
char *cmlc_matrix2x3_debug(const CML_Matrix2x3 *expected, const CML_Matrix2x3 *got);



/******************************************************************************
 * Function: cmlc_matrix2x4_add
 * 
 * Description:
 *     Adds two CML_Matrix2x4 and writes the result to the out CML_Matrix2x4.
 * 
 * Parameters:
 *      CML_Matrix2x4 *A   - The first matrix operand.
 *      CML_Matrix2x4 *B   - The second matrix operand.
 *      CML_Matrix2x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x4_add(const CML_Matrix2x4 *A, const CML_Matrix2x4 *B, CML_Matrix2x4 *out);


/******************************************************************************
 * Function: cmlc_matrix2x4_sub
 * 
 * Description:
 *     Subtracts two CML_Matrix2x4 and writes the result to the out 
 *     CML_Matrix2x4.
 * 
 * Parameters:
 *      CML_Matrix2x4 *A   - The first matrix operand.
 *      CML_Matrix2x4 *B   - The second matrix operand.
 *      CML_Matrix2x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x4_sub(const CML_Matrix2x4 *A, const CML_Matrix2x4 *B, CML_Matrix2x4 *out);


/******************************************************************************
 * Function: cmlc_matrix2x4_scale
 * 
 * Description:
 *     Multiplies a CML_Matrix2x4 by a scalar, and writes the result to the out 
 *     CML_Matrix2x4.
 * 
 * Parameters:
 *      CML_Matrix2x4 *A   - The matrix operand.
 *      f32         t   - The scalar.
 *      CML_Matrix2x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x4_scale(const CML_Matrix2x4 *A, f32 t, CML_Matrix2x4 *out);


/******************************************************************************
 * Function: cmlc_matrix2x4_mult_matrix4x2
 * 
 * Description:
 *     Multiplies a CML_Matrix2x4 by a CML_Matrix4x2, and writes the result to 
 *     the out CML_Matrix2x2.
 * 
 * Parameters:
 *      CML_Matrix2x4 *A   - The first matrix operand.
 *      CML_Matrix4x2 *B   - The second vector operand.
 *      CML_Matrix2x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x4_mult_matrix4x2(const CML_Matrix2x4 *A, const CML_Matrix4x2 *B, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x4_mult_matrix4x3
 * 
 * Description:
 *     Multiplies a CML_Matrix2x4 by a CML_Matrix4x3, and writes the result to 
 *     the out CML_Matrix2x3.
 * 
 * Parameters:
 *      CML_Matrix2x4 *A   - The first matrix operand.
 *      CML_Matrix4x3 *B   - The second vector operand.
 *      CML_Matrix2x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x4_mult_matrix4x3(const CML_Matrix2x4 *A, const CML_Matrix4x3 *B, CML_Matrix2x3 *out);


/******************************************************************************
 * Function: cmlc_matrix2x4_mult_matrix4x4
 * 
 * Description:
 *     Multiplies a CML_Matrix2x4 by a CML_Matrix4x4, and writes the result to 
 *     the out CML_Matrix2x4.
 * 
 * Parameters:
 *      CML_Matrix2x4 *A   - The first matrix operand.
 *      CML_Matrix4x4 *B   - The second vector operand.
 *      CML_Matrix2x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x4_mult_matrix4x4(const CML_Matrix2x4 *A, const CML_Matrix4x4 *B, CML_Matrix2x4 *out);


/******************************************************************************
 * Function: cmlc_matrix2x4_mult_vector4
 * 
 * Description:
 *     Multiplies a CML_Matrix2x4 by a CML_Vector4, and writes the result to 
 *     the out CML_Vector2.
 * 
 * Parameters:
 *      CML_Matrix2x4 *A   - The matrix operand.
 *      CML_Vector4   *v   - The vector operand.
 *      CML_Vector2   *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x4_mult_vector4(const CML_Matrix2x4 *A, const CML_Vector4 *v, CML_Vector2 *out);


/******************************************************************************
 * Function: cmlc_vector2_mult_matrix2x4
 * 
 * Description:
 *     Multiplies a CML_Vector2 by a CML_Matrix2x4, and writes the result to 
 *     the out CML_Vector4.
 * 
 * Parameters:
 *      CML_Vector2   *v   - The vector operand.
 *      CML_Matrix2x4 *A   - The matrix operand.
 *      CML_Vector4   *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector2_mult_matrix2x4(const CML_Vector2 *v, const CML_Matrix2x4 *A, CML_Vector4 *out);


/******************************************************************************
 * Function: cmlc_matrix2x4_transpose
 * 
 * Description:
 *     Calculates the transpose of a CML_Matrix2x4.
 * 
 * Parameters:
 *      CML_Matrix2x4 *A   - The matrix operand.
 *      CML_Matrix4x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix2x4_transpose(const CML_Matrix2x4 *A, CML_Matrix4x2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x4_eq
 * 
 * Description:
 *      Compares two CML_Matrix2x4s for equality.
 * 
 * Parameters:
 *      CML_Matrix2x4 *A - The first input vector.
 *      CML_Matrix2x4 *B - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CML_Bool cmlc_matrix2x4_eq(const CML_Matrix2x4 *A, const CML_Matrix2x4 *B);


/******************************************************************************
 * Function: cmlc_matrix2x4_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Matrix2x4s.
 *
 * Parameters:
 *      CML_Matrix2x4 *expected - Expected matrix.
 *      CML_Matrix2x4 *got - Result matrix.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
char *cmlc_matrix2x4_debug(const CML_Matrix2x4 *expected, const CML_Matrix2x4 *got);



/******************************************************************************
 * Function: cmlc_matrix3x2_add
 * 
 * Description:
 *     Adds two CML_Matrix3x2 and writes the result to the out CML_Matrix3x2.
 * 
 * Parameters:
 *      CML_Matrix3x2 *A   - The first matrix operand.
 *      CML_Matrix3x2 *B   - The second matrix operand.
 *      CML_Matrix3x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x2_add(const CML_Matrix3x2 *A, const CML_Matrix3x2 *B, CML_Matrix3x2 *out);


/******************************************************************************
 * Function: cmlc_matrix3x2_sub
 * 
 * Description:
 *     Subtracts two CML_Matrix3x2 and writes the result to the out 
 *     CML_Matrix3x2.
 * 
 * Parameters:
 *      CML_Matrix3x2 *A   - The first matrix operand.
 *      CML_Matrix3x2 *B   - The second matrix operand.
 *      CML_Matrix3x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x2_sub(const CML_Matrix3x2 *A, const CML_Matrix3x2 *B, CML_Matrix3x2 *out);


/******************************************************************************
 * Function: cmlc_matrix3x2_scale
 * 
 * Description:
 *     Multiplies a CML_Matrix3x2 by a scalar, and writes the result to the out 
 *     CML_Matrix3x2.
 * 
 * Parameters:
 *      CML_Matrix3x2 *A   - The matrix operand.
 *      f32         t   - The scalar.
 *      CML_Matrix3x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x2_scale(const CML_Matrix3x2 *A, f32 t, CML_Matrix3x2 *out);


/******************************************************************************
 * Function: cmlc_matrix3x2_mult_matrix2x2
 * 
 * Description:
 *     Multiplies a CML_Matrix3x2 by a CML_Matrix2x2, and writes the result to 
 *     the out CML_Matrix3x2.
 * 
 * Parameters:
 *      CML_Matrix3x2 *A   - The first matrix operand.
 *      CML_Matrix2x2 *B   - The second vector operand.
 *      CML_Matrix3x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x2_mult_matrix2x2(const CML_Matrix3x2 *A, const CML_Matrix2x2 *B, CML_Matrix3x2 *out);


/******************************************************************************
 * Function: cmlc_matrix3x2_mult_matrix2x3
 * 
 * Description:
 *     Multiplies a CML_Matrix3x2 by a CML_Matrix2x3, and writes the result to 
 *     the out CML_Matrix3x3.
 * 
 * Parameters:
 *      CML_Matrix3x2 *A   - The first matrix operand.
 *      CML_Matrix2x3 *B   - The second vector operand.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x2_mult_matrix2x3(const CML_Matrix3x2 *A, const CML_Matrix2x3 *B, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x2_mult_matrix2x4
 * 
 * Description:
 *     Multiplies a CML_Matrix3x2 by a CML_Matrix2x4, and writes the result to 
 *     the out CML_Matrix3x4.
 * 
 * Parameters:
 *      CML_Matrix3x2 *A   - The first matrix operand.
 *      CML_Matrix2x4 *B   - The second vector operand.
 *      CML_Matrix3x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x2_mult_matrix2x4(const CML_Matrix3x2 *A, const CML_Matrix2x4 *B, CML_Matrix3x4 *out);


/******************************************************************************
 * Function: cmlc_matrix3x2_mult_vector2
 * 
 * Description:
 *     Multiplies a CML_Matrix3x2 by a CML_Vector2, and writes the result to 
 *     the out CML_Vector3.
 * 
 * Parameters:
 *      CML_Matrix3x2 *A   - The matrix operand.
 *      CML_Vector2   *v   - The vector operand.
 *      CML_Vector3   *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x2_mult_vector2(const CML_Matrix3x2 *A, const CML_Vector2 *v, CML_Vector3 *out);


/******************************************************************************
 * Function: cmlc_vector3_mult_matrix3x2
 * 
 * Description:
 *     Multiplies a CML_Vector3 by a CML_Matrix3x2, and writes the result to 
 *     the out CML_Vector2.
 * 
 * Parameters:
 *      CML_Vector3   *v   - The vector operand.
 *      CML_Matrix3x2 *A   - The matrix operand.
 *      CML_Vector2   *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector3_mult_matrix3x2(const CML_Vector3 *v, const CML_Matrix3x2 *A, CML_Vector2 *out);


/******************************************************************************
 * Function: cmlc_matrix3x2_transpose
 * 
 * Description:
 *     Calculates the transpose of a CML_Matrix3x2.
 * 
 * Parameters:
 *      CML_Matrix3x2 *A   - The matrix operand.
 *      CML_Matrix2x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x2_transpose(const CML_Matrix3x2 *A, CML_Matrix2x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x2_eq
 * 
 * Description:
 *      Compares two CML_Matrix3x2s for equality.
 * 
 * Parameters:
 *      CML_Matrix3x2 *A - The first input vector.
 *      CML_Matrix3x2 *B - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CML_Bool cmlc_matrix3x2_eq(const CML_Matrix3x2 *A, const CML_Matrix3x2 *B);


/******************************************************************************
 * Function: cmlc_matrix3x2_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Matrix3x2s.
 *
 * Parameters:
 *      CML_Matrix3x2 *expected - Expected matrix.
 *      CML_Matrix3x2 *got - Result matrix.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
char *cmlc_matrix3x2_debug(const CML_Matrix3x2 *expected, const CML_Matrix3x2 *got);



/******************************************************************************
 * Function: cmlc_matrix3x4_add
 * 
 * Description:
 *     Adds two CML_Matrix3x4 and writes the result to the out CML_Matrix3x4.
 * 
 * Parameters:
 *      CML_Matrix3x4 *A   - The first matrix operand.
 *      CML_Matrix3x4 *B   - The second matrix operand.
 *      CML_Matrix3x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x4_add(const CML_Matrix3x4 *A, const CML_Matrix3x4 *B, CML_Matrix3x4 *out);


/******************************************************************************
 * Function: cmlc_matrix3x4_sub
 * 
 * Description:
 *     Subtracts two CML_Matrix3x4 and writes the result to the out 
 *     CML_Matrix3x4.
 * 
 * Parameters:
 *      CML_Matrix3x4 *A   - The first matrix operand.
 *      CML_Matrix3x4 *B   - The second matrix operand.
 *      CML_Matrix3x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x4_sub(const CML_Matrix3x4 *A, const CML_Matrix3x4 *B, CML_Matrix3x4 *out);


/******************************************************************************
 * Function: cmlc_matrix3x4_scale
 * 
 * Description:
 *     Multiplies a CML_Matrix3x4 by a scalar, and writes the result to the out 
 *     CML_Matrix3x4.
 * 
 * Parameters:
 *      CML_Matrix3x4 *A   - The matrix operand.
 *      f32         t   - The scalar.
 *      CML_Matrix3x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x4_scale(const CML_Matrix3x4 *A, f32 t, CML_Matrix3x4 *out);


/******************************************************************************
 * Function: cmlc_matrix3x4_mult_matrix4x2
 * 
 * Description:
 *     Multiplies a CML_Matrix3x4 by a CML_Matrix4x2, and writes the result to 
 *     the out CML_Matrix3x2.
 * 
 * Parameters:
 *      CML_Matrix3x4 *A   - The first matrix operand.
 *      CML_Matrix4x2 *B   - The second vector operand.
 *      CML_Matrix3x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x4_mult_matrix4x2(const CML_Matrix3x4 *A, const CML_Matrix4x2 *B, CML_Matrix3x2 *out);


/******************************************************************************
 * Function: cmlc_matrix3x4_mult_matrix4x3
 * 
 * Description:
 *     Multiplies a CML_Matrix3x4 by a CML_Matrix4x3, and writes the result to 
 *     the out CML_Matrix3x3.
 * 
 * Parameters:
 *      CML_Matrix3x4 *A   - The first matrix operand.
 *      CML_Matrix4x3 *B   - The second vector operand.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x4_mult_matrix4x3(const CML_Matrix3x4 *A, const CML_Matrix4x3 *B, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x4_mult_matrix4x4
 * 
 * Description:
 *     Multiplies a CML_Matrix3x4 by a CML_Matrix4x4, and writes the result to 
 *     the out CML_Matrix3x4.
 * 
 * Parameters:
 *      CML_Matrix3x4 *A   - The first matrix operand.
 *      CML_Matrix4x4 *B   - The second vector operand.
 *      CML_Matrix3x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x4_mult_matrix4x4(const CML_Matrix3x4 *A, const CML_Matrix4x4 *B, CML_Matrix3x4 *out);


/******************************************************************************
 * Function: cmlc_matrix3x4_mult_vector4
 * 
 * Description:
 *     Multiplies a CML_Matrix3x4 by a CML_Vector4, and writes the result to 
 *     the out CML_Vector3.
 * 
 * Parameters:
 *      CML_Matrix3x4 *A   - The matrix operand.
 *      CML_Vector4   *v   - The vector operand.
 *      CML_Vector3   *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x4_mult_vector4(const CML_Matrix3x4 *A, const CML_Vector4 *v, CML_Vector3 *out);


/******************************************************************************
 * Function: cmlc_vector3_mult_matrix3x4
 * 
 * Description:
 *     Multiplies a CML_Vector3 by a CML_Matrix3x4, and writes the result to 
 *     the out CML_Vector4.
 * 
 * Parameters:
 *      CML_Vector3   *v   - The vector operand.
 *      CML_Matrix3x4 *A   - The matrix operand.
 *      CML_Vector4   *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector3_mult_matrix3x4(const CML_Vector3 *v, const CML_Matrix3x4 *A, CML_Vector4 *out);


/******************************************************************************
 * Function: cmlc_matrix3x4_transpose
 * 
 * Description:
 *     Calculates the transpose of a CML_Matrix3x4.
 * 
 * Parameters:
 *      CML_Matrix3x4 *A   - The matrix operand.
 *      CML_Matrix4x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix3x4_transpose(const CML_Matrix3x4 *A, CML_Matrix4x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x4_eq
 * 
 * Description:
 *      Compares two CML_Matrix3x4s for equality.
 * 
 * Parameters:
 *      CML_Matrix3x4 *A - The first input vector.
 *      CML_Matrix3x4 *B - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CML_Bool cmlc_matrix3x4_eq(const CML_Matrix3x4 *A, const CML_Matrix3x4 *B);


/******************************************************************************
 * Function: cmlc_matrix3x4_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Matrix3x4s.
 *
 * Parameters:
 *      CML_Matrix3x4 *expected - Expected matrix.
 *      CML_Matrix3x4 *got - Result matrix.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
char *cmlc_matrix3x4_debug(const CML_Matrix3x4 *expected, const CML_Matrix3x4 *got);



/******************************************************************************
 * Function: cmlc_matrix4x2_add
 * 
 * Description:
 *     Adds two CML_Matrix4x2 and writes the result to the out CML_Matrix4x2.
 * 
 * Parameters:
 *      CML_Matrix4x2 *A   - The first matrix operand.
 *      CML_Matrix4x2 *B   - The second matrix operand.
 *      CML_Matrix4x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x2_add(const CML_Matrix4x2 *A, const CML_Matrix4x2 *B, CML_Matrix4x2 *out);


/******************************************************************************
 * Function: cmlc_matrix4x2_sub
 * 
 * Description:
 *     Subtracts two CML_Matrix4x2 and writes the result to the out 
 *     CML_Matrix4x2.
 * 
 * Parameters:
 *      CML_Matrix4x2 *A   - The first matrix operand.
 *      CML_Matrix4x2 *B   - The second matrix operand.
 *      CML_Matrix4x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x2_sub(const CML_Matrix4x2 *A, const CML_Matrix4x2 *B, CML_Matrix4x2 *out);


/******************************************************************************
 * Function: cmlc_matrix4x2_scale
 * 
 * Description:
 *     Multiplies a CML_Matrix4x2 by a scalar, and writes the result to the out 
 *     CML_Matrix4x2.
 * 
 * Parameters:
 *      CML_Matrix4x2 *A   - The matrix operand.
 *      f32         t   - The scalar.
 *      CML_Matrix4x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x2_scale(const CML_Matrix4x2 *A, f32 t, CML_Matrix4x2 *out);


/******************************************************************************
 * Function: cmlc_matrix4x2_mult_matrix2x2
 * 
 * Description:
 *     Multiplies a CML_Matrix4x2 by a CML_Matrix2x2, and writes the result to 
 *     the out CML_Matrix4x2.
 * 
 * Parameters:
 *      CML_Matrix4x2 *A   - The first matrix operand.
 *      CML_Matrix2x2 *B   - The second vector operand.
 *      CML_Matrix4x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x2_mult_matrix2x2(const CML_Matrix4x2 *A, const CML_Matrix2x2 *B, CML_Matrix4x2 *out);


/******************************************************************************
 * Function: cmlc_matrix4x2_mult_matrix2x3
 * 
 * Description:
 *     Multiplies a CML_Matrix4x2 by a CML_Matrix2x3, and writes the result to 
 *     the out CML_Matrix4x3.
 * 
 * Parameters:
 *      CML_Matrix4x2 *A   - The first matrix operand.
 *      CML_Matrix2x3 *B   - The second vector operand.
 *      CML_Matrix4x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x2_mult_matrix2x3(const CML_Matrix4x2 *A, const CML_Matrix2x3 *B, CML_Matrix4x3 *out);


/******************************************************************************
 * Function: cmlc_matrix4x2_mult_matrix2x4
 * 
 * Description:
 *     Multiplies a CML_Matrix4x2 by a CML_Matrix2x4, and writes the result to 
 *     the out CML_Matrix4x4.
 * 
 * Parameters:
 *      CML_Matrix4x2 *A   - The first matrix operand.
 *      CML_Matrix2x4 *B   - The second vector operand.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x2_mult_matrix2x4(const CML_Matrix4x2 *A, const CML_Matrix2x4 *B, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x2_mult_vector2
 * 
 * Description:
 *     Multiplies a CML_Matrix4x2 by a CML_Vector2, and writes the result to 
 *     the out CML_Vector4.
 * 
 * Parameters:
 *      CML_Matrix4x2 *A   - The matrix operand.
 *      CML_Vector2   *v   - The vector operand.
 *      CML_Vector4   *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x2_mult_vector2(const CML_Matrix4x2 *A, const CML_Vector2 *v, CML_Vector4 *out);


/******************************************************************************
 * Function: cmlc_vector4_mult_matrix4x2
 * 
 * Description:
 *     Multiplies a CML_Vector4 by a CML_Matrix4x2, and writes the result to 
 *     the out CML_Vector2.
 * 
 * Parameters:
 *      CML_Vector4   *v   - The vector operand.
 *      CML_Matrix4x2 *A   - The matrix operand.
 *      CML_Vector2   *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector4_mult_matrix4x2(const CML_Vector4 *v, const CML_Matrix4x2 *A, CML_Vector2 *out);


/******************************************************************************
 * Function: cmlc_matrix4x2_transpose
 * 
 * Description:
 *     Calculates the transpose of a CML_Matrix4x2.
 * 
 * Parameters:
 *      CML_Matrix4x2 *A   - The matrix operand.
 *      CML_Matrix2x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x2_transpose(const CML_Matrix4x2 *A, CML_Matrix2x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x2_eq
 * 
 * Description:
 *      Compares two CML_Matrix4x2s for equality.
 * 
 * Parameters:
 *      CML_Matrix4x2 *A - The first input vector.
 *      CML_Matrix4x2 *B - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CML_Bool cmlc_matrix4x2_eq(const CML_Matrix4x2 *A, const CML_Matrix4x2 *B);


/******************************************************************************
 * Function: cmlc_matrix4x2_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Matrix4x2s.
 *
 * Parameters:
 *      CML_Matrix4x2 *expected - Expected matrix.
 *      CML_Matrix4x2 *got - Result matrix.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
char *cmlc_matrix4x2_debug(const CML_Matrix4x2 *expected, const CML_Matrix4x2 *got);



/******************************************************************************
 * Function: cmlc_matrix4x3_add
 * 
 * Description:
 *     Adds two CML_Matrix4x3 and writes the result to the out CML_Matrix4x3.
 * 
 * Parameters:
 *      CML_Matrix4x3 *A   - The first matrix operand.
 *      CML_Matrix4x3 *B   - The second matrix operand.
 *      CML_Matrix4x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x3_add(const CML_Matrix4x3 *A, const CML_Matrix4x3 *B, CML_Matrix4x3 *out);


/******************************************************************************
 * Function: cmlc_matrix4x3_sub
 * 
 * Description:
 *     Subtracts two CML_Matrix4x3 and writes the result to the out 
 *     CML_Matrix4x3.
 * 
 * Parameters:
 *      CML_Matrix4x3 *A   - The first matrix operand.
 *      CML_Matrix4x3 *B   - The second matrix operand.
 *      CML_Matrix4x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x3_sub(const CML_Matrix4x3 *A, const CML_Matrix4x3 *B, CML_Matrix4x3 *out);


/******************************************************************************
 * Function: cmlc_matrix4x3_scale
 * 
 * Description:
 *     Multiplies a CML_Matrix4x3 by a scalar, and writes the result to the out 
 *     CML_Matrix4x3.
 * 
 * Parameters:
 *      CML_Matrix4x3 *A   - The matrix operand.
 *      f32         t   - The scalar.
 *      CML_Matrix4x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x3_scale(const CML_Matrix4x3 *A, f32 t, CML_Matrix4x3 *out);


/******************************************************************************
 * Function: cmlc_matrix4x3_mult_matrix3x2
 * 
 * Description:
 *     Multiplies a CML_Matrix4x3 by a CML_Matrix3x2, and writes the result to 
 *     the out CML_Matrix4x2.
 * 
 * Parameters:
 *      CML_Matrix4x3 *A   - The first matrix operand.
 *      CML_Matrix3x2 *B   - The second vector operand.
 *      CML_Matrix4x2 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x3_mult_matrix3x2(const CML_Matrix4x3 *A, const CML_Matrix3x2 *B, CML_Matrix4x2 *out);


/******************************************************************************
 * Function: cmlc_matrix4x3_mult_matrix3x3
 * 
 * Description:
 *     Multiplies a CML_Matrix4x3 by a CML_Matrix3x3, and writes the result to 
 *     the out CML_Matrix4x3.
 * 
 * Parameters:
 *      CML_Matrix4x3 *A   - The first matrix operand.
 *      CML_Matrix3x3 *B   - The second vector operand.
 *      CML_Matrix4x3 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x3_mult_matrix3x3(const CML_Matrix4x3 *A, const CML_Matrix3x3 *B, CML_Matrix4x3 *out);


/******************************************************************************
 * Function: cmlc_matrix4x3_mult_matrix3x4
 * 
 * Description:
 *     Multiplies a CML_Matrix4x3 by a CML_Matrix3x4, and writes the result to 
 *     the out CML_Matrix4x4.
 * 
 * Parameters:
 *      CML_Matrix4x3 *A   - The first matrix operand.
 *      CML_Matrix3x4 *B   - The second vector operand.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x3_mult_matrix3x4(const CML_Matrix4x3 *A, const CML_Matrix3x4 *B, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x3_mult_vector3
 * 
 * Description:
 *     Multiplies a CML_Matrix4x3 by a CML_Vector3, and writes the result to 
 *     the out CML_Vector4.
 * 
 * Parameters:
 *      CML_Matrix4x3 *A   - The matrix operand.
 *      CML_Vector3   *v   - The vector operand.
 *      CML_Vector4   *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x3_mult_vector3(const CML_Matrix4x3 *A, const CML_Vector3 *v, CML_Vector4 *out);


/******************************************************************************
 * Function: cmlc_vector4_mult_matrix4x3
 * 
 * Description:
 *     Multiplies a CML_Vector4 by a CML_Matrix4x3, and writes the result to 
 *     the out CML_Vector3.
 * 
 * Parameters:
 *      CML_Vector4   *v   - The vector operand.
 *      CML_Matrix4x3 *A   - The matrix operand.
 *      CML_Vector3   *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector4_mult_matrix4x3(const CML_Vector4 *v, const CML_Matrix4x3 *A, CML_Vector3 *out);


/******************************************************************************
 * Function: cmlc_matrix4x3_transpose
 * 
 * Description:
 *     Calculates the transpose of a CML_Matrix4x3.
 * 
 * Parameters:
 *      CML_Matrix4x3 *A   - The matrix operand.
 *      CML_Matrix3x4 *out - The output matrix.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_matrix4x3_transpose(const CML_Matrix4x3 *A, CML_Matrix3x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x3_eq
 * 
 * Description:
 *      Compares two CML_Matrix4x3s for equality.
 * 
 * Parameters:
 *      CML_Matrix4x3 *A - The first input vector.
 *      CML_Matrix4x3 *B - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CML_Bool cmlc_matrix4x3_eq(const CML_Matrix4x3 *A, const CML_Matrix4x3 *B);


/******************************************************************************
 * Function: cmlc_matrix4x3_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Matrix4x3s.
 *
 * Parameters:
 *      CML_Matrix4x3 *expected - Expected matrix.
 *      CML_Matrix4x3 *got - Result matrix.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
char *cmlc_matrix4x3_debug(const CML_Matrix4x3 *expected, const CML_Matrix4x3 *got);


#endif /* CAMEL_CFIXED_MATRIX */
