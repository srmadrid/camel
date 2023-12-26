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

#include "../../../core/core.h"
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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x2_add(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B, CML_Matrix2x2 *out);

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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x2_sub(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cmlc_matrix2x2_scale
 * 
 * Description:
 *     Multiplies a CML_Matrix2x2 by a scalar, and writes the result to the out 
 *     CML_Matrix2x2.
 * 
 * Parameters:
 *      CML_Matrix2x2 *A   - The matrix operand.
 *      double         t   - The scalar.
 *      CML_Matrix2x2 *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x2_scale(const CML_Matrix2x2 *A, f64 t, CML_Matrix2x2 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x2_mult(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B, CML_Matrix2x2 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x2_mult_vector2(const CML_Matrix2x2 *A, const CML_Vector2 *v, CML_Vector2 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_vector2_mult_matrix2x2(const CML_Vector2 *v, const CML_Matrix2x2 *A, CML_Vector2 *out);


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
CAMEL_API f64 cmlc_matrix2x2_det(const CML_Matrix2x2 *A);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x2_inv(const CML_Matrix2x2 *A, CML_Matrix2x2 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x2_transpose(const CML_Matrix2x2 *A, CML_Matrix2x2 *out);


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
CAMEL_API f64 cmlc_matrix2x2_trace(const CML_Matrix2x2 *A);


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
CAMEL_API CML_Bool cmlc_matrix2x2_eq(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B);


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
CAMEL_API char *cmlc_matrix2x2_debug(const CML_Matrix2x2 *expected, const CML_Matrix2x2 *got);



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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x3_add(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B, CML_Matrix3x3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x3_sub(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cmlc_matrix3x3_scale
 * 
 * Description:
 *     Multiplies a CML_Matrix3x3 by a scalar, and writes the result to the out 
 *     CML_Matrix3x3.
 * 
 * Parameters:
 *      CML_Matrix3x3 *A   - The matrix operand.
 *      double         t   - The scalar.
 *      CML_Matrix3x3 *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x3_scale(const CML_Matrix3x3 *A, f64 t, CML_Matrix3x3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x3_mult(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B, CML_Matrix3x3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x3_mult_vector3(const CML_Matrix3x3 *A, const CML_Vector3 *v, CML_Vector3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_vector3_mult_matrix3x3(const CML_Vector3 *v, const CML_Matrix3x3 *A, CML_Vector3 *out);


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
CAMEL_API f64 cmlc_matrix3x3_det(const CML_Matrix3x3 *A);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x3_inv(const CML_Matrix3x3 *A, CML_Matrix3x3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x3_transpose(const CML_Matrix3x3 *A, CML_Matrix3x3 *out);


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
CAMEL_API f64 cmlc_matrix3x3_trace(const CML_Matrix3x3 *A);


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
CAMEL_API CML_Bool cmlc_matrix3x3_eq(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B);


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
CAMEL_API char *cmlc_matrix3x3_debug(const CML_Matrix3x3 *expected, const CML_Matrix3x3 *got);



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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x4_add(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B, CML_Matrix4x4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x4_sub(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cmlc_matrix4x4_scale
 * 
 * Description:
 *     Multiplies a CML_Matrix4x4 by a scalar, and writes the result to the out 
 *     CML_Matrix4x4.
 * 
 * Parameters:
 *      CML_Matrix4x4 *A   - The matrix operand.
 *      double         t   - The scalar.
 *      CML_Matrix4x4 *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x4_scale(const CML_Matrix4x4 *A, f64 t, CML_Matrix4x4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x4_mult(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B, CML_Matrix4x4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x4_mult_vector4(const CML_Matrix4x4 *A, const CML_Vector4 *v, CML_Vector4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_vector4_mult_matrix4x4(const CML_Vector4 *v, const CML_Matrix4x4 *A, CML_Vector4 *out);


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
CAMEL_API f64 cmlc_matrix4x4_det(const CML_Matrix4x4 *A);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x4_inv(const CML_Matrix4x4 *A, CML_Matrix4x4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x4_transpose(const CML_Matrix4x4 *A, CML_Matrix4x4 *out);


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
CAMEL_API f64 cmlc_matrix4x4_trace(const CML_Matrix4x4 *A);


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
CAMEL_API CML_Bool cmlc_matrix4x4_eq(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B);


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
CAMEL_API char *cmlc_matrix4x4_debug(const CML_Matrix4x4 *expected, const CML_Matrix4x4 *got);



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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x3_add(const CML_Matrix2x3 *A, const CML_Matrix2x3 *B, CML_Matrix2x3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x3_sub(const CML_Matrix2x3 *A, const CML_Matrix2x3 *B, CML_Matrix2x3 *out);


/******************************************************************************
 * Function: cmlc_matrix2x3_scale
 * 
 * Description:
 *     Multiplies a CML_Matrix2x3 by a scalar, and writes the result to the out 
 *     CML_Matrix2x3.
 * 
 * Parameters:
 *      CML_Matrix2x3 *A   - The matrix operand.
 *      double         t   - The scalar.
 *      CML_Matrix2x3 *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x3_scale(const CML_Matrix2x3 *A, f64 t, CML_Matrix2x3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x3_mult_matrix3x2(const CML_Matrix2x3 *A, const CML_Matrix3x2 *B, CML_Matrix2x2 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x3_mult_matrix3x3(const CML_Matrix2x3 *A, const CML_Matrix3x3 *B, CML_Matrix2x3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x3_mult_matrix3x4(const CML_Matrix2x3 *A, const CML_Matrix3x4 *B, CML_Matrix2x4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x3_mult_vector3(const CML_Matrix2x3 *A, const CML_Vector3 *v, CML_Vector2 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_vector2_mult_matrix2x3(const CML_Vector2 *v, const CML_Matrix2x3 *A, CML_Vector3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x3_transpose(const CML_Matrix2x3 *A, CML_Matrix3x2 *out);


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
CAMEL_API CML_Bool cmlc_matrix2x3_eq(const CML_Matrix2x3 *A, const CML_Matrix2x3 *B);


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
CAMEL_API char *cmlc_matrix2x3_debug(const CML_Matrix2x3 *expected, const CML_Matrix2x3 *got);



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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x4_add(const CML_Matrix2x4 *A, const CML_Matrix2x4 *B, CML_Matrix2x4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x4_sub(const CML_Matrix2x4 *A, const CML_Matrix2x4 *B, CML_Matrix2x4 *out);


/******************************************************************************
 * Function: cmlc_matrix2x4_scale
 * 
 * Description:
 *     Multiplies a CML_Matrix2x4 by a scalar, and writes the result to the out 
 *     CML_Matrix2x4.
 * 
 * Parameters:
 *      CML_Matrix2x4 *A   - The matrix operand.
 *      double         t   - The scalar.
 *      CML_Matrix2x4 *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x4_scale(const CML_Matrix2x4 *A, f64 t, CML_Matrix2x4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x4_mult_matrix4x2(const CML_Matrix2x4 *A, const CML_Matrix4x2 *B, CML_Matrix2x2 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x4_mult_matrix4x3(const CML_Matrix2x4 *A, const CML_Matrix4x3 *B, CML_Matrix2x3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x4_mult_matrix4x4(const CML_Matrix2x4 *A, const CML_Matrix4x4 *B, CML_Matrix2x4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x4_mult_vector4(const CML_Matrix2x4 *A, const CML_Vector4 *v, CML_Vector2 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_vector2_mult_matrix2x4(const CML_Vector2 *v, const CML_Matrix2x4 *A, CML_Vector4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix2x4_transpose(const CML_Matrix2x4 *A, CML_Matrix4x2 *out);


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
CAMEL_API CML_Bool cmlc_matrix2x4_eq(const CML_Matrix2x4 *A, const CML_Matrix2x4 *B);


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
CAMEL_API char *cmlc_matrix2x4_debug(const CML_Matrix2x4 *expected, const CML_Matrix2x4 *got);



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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x2_add(const CML_Matrix3x2 *A, const CML_Matrix3x2 *B, CML_Matrix3x2 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x2_sub(const CML_Matrix3x2 *A, const CML_Matrix3x2 *B, CML_Matrix3x2 *out);


/******************************************************************************
 * Function: cmlc_matrix3x2_scale
 * 
 * Description:
 *     Multiplies a CML_Matrix3x2 by a scalar, and writes the result to the out 
 *     CML_Matrix3x2.
 * 
 * Parameters:
 *      CML_Matrix3x2 *A   - The matrix operand.
 *      double         t   - The scalar.
 *      CML_Matrix3x2 *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x2_scale(const CML_Matrix3x2 *A, f64 t, CML_Matrix3x2 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x2_mult_matrix2x2(const CML_Matrix3x2 *A, const CML_Matrix2x2 *B, CML_Matrix3x2 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x2_mult_matrix2x3(const CML_Matrix3x2 *A, const CML_Matrix2x3 *B, CML_Matrix3x3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x2_mult_matrix2x4(const CML_Matrix3x2 *A, const CML_Matrix2x4 *B, CML_Matrix3x4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x2_mult_vector2(const CML_Matrix3x2 *A, const CML_Vector2 *v, CML_Vector3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_vector3_mult_matrix3x2(const CML_Vector3 *v, const CML_Matrix3x2 *A, CML_Vector2 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x2_transpose(const CML_Matrix3x2 *A, CML_Matrix2x3 *out);


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
CAMEL_API CML_Bool cmlc_matrix3x2_eq(const CML_Matrix3x2 *A, const CML_Matrix3x2 *B);


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
CAMEL_API char *cmlc_matrix3x2_debug(const CML_Matrix3x2 *expected, const CML_Matrix3x2 *got);



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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x4_add(const CML_Matrix3x4 *A, const CML_Matrix3x4 *B, CML_Matrix3x4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x4_sub(const CML_Matrix3x4 *A, const CML_Matrix3x4 *B, CML_Matrix3x4 *out);


/******************************************************************************
 * Function: cmlc_matrix3x4_scale
 * 
 * Description:
 *     Multiplies a CML_Matrix3x4 by a scalar, and writes the result to the out 
 *     CML_Matrix3x4.
 * 
 * Parameters:
 *      CML_Matrix3x4 *A   - The matrix operand.
 *      double         t   - The scalar.
 *      CML_Matrix3x4 *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x4_scale(const CML_Matrix3x4 *A, f64 t, CML_Matrix3x4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x4_mult_matrix4x2(const CML_Matrix3x4 *A, const CML_Matrix4x2 *B, CML_Matrix3x2 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x4_mult_matrix4x3(const CML_Matrix3x4 *A, const CML_Matrix4x3 *B, CML_Matrix3x3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x4_mult_matrix4x4(const CML_Matrix3x4 *A, const CML_Matrix4x4 *B, CML_Matrix3x4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x4_mult_vector4(const CML_Matrix3x4 *A, const CML_Vector4 *v, CML_Vector3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_vector3_mult_matrix3x4(const CML_Vector3 *v, const CML_Matrix3x4 *A, CML_Vector4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix3x4_transpose(const CML_Matrix3x4 *A, CML_Matrix4x3 *out);


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
CAMEL_API CML_Bool cmlc_matrix3x4_eq(const CML_Matrix3x4 *A, const CML_Matrix3x4 *B);


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
CAMEL_API char *cmlc_matrix3x4_debug(const CML_Matrix3x4 *expected, const CML_Matrix3x4 *got);



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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x2_add(const CML_Matrix4x2 *A, const CML_Matrix4x2 *B, CML_Matrix4x2 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x2_sub(const CML_Matrix4x2 *A, const CML_Matrix4x2 *B, CML_Matrix4x2 *out);


/******************************************************************************
 * Function: cmlc_matrix4x2_scale
 * 
 * Description:
 *     Multiplies a CML_Matrix4x2 by a scalar, and writes the result to the out 
 *     CML_Matrix4x2.
 * 
 * Parameters:
 *      CML_Matrix4x2 *A   - The matrix operand.
 *      double         t   - The scalar.
 *      CML_Matrix4x2 *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x2_scale(const CML_Matrix4x2 *A, f64 t, CML_Matrix4x2 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x2_mult_matrix2x2(const CML_Matrix4x2 *A, const CML_Matrix2x2 *B, CML_Matrix4x2 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x2_mult_matrix2x3(const CML_Matrix4x2 *A, const CML_Matrix2x3 *B, CML_Matrix4x3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x2_mult_matrix2x4(const CML_Matrix4x2 *A, const CML_Matrix2x4 *B, CML_Matrix4x4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x2_mult_vector2(const CML_Matrix4x2 *A, const CML_Vector2 *v, CML_Vector4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_vector4_mult_matrix4x2(const CML_Vector4 *v, const CML_Matrix4x2 *A, CML_Vector2 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x2_transpose(const CML_Matrix4x2 *A, CML_Matrix2x4 *out);


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
CAMEL_API CML_Bool cmlc_matrix4x2_eq(const CML_Matrix4x2 *A, const CML_Matrix4x2 *B);


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
CAMEL_API char *cmlc_matrix4x2_debug(const CML_Matrix4x2 *expected, const CML_Matrix4x2 *got);



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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x3_add(const CML_Matrix4x3 *A, const CML_Matrix4x3 *B, CML_Matrix4x3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x3_sub(const CML_Matrix4x3 *A, const CML_Matrix4x3 *B, CML_Matrix4x3 *out);


/******************************************************************************
 * Function: cmlc_matrix4x3_scale
 * 
 * Description:
 *     Multiplies a CML_Matrix4x3 by a scalar, and writes the result to the out 
 *     CML_Matrix4x3.
 * 
 * Parameters:
 *      CML_Matrix4x3 *A   - The matrix operand.
 *      double         t   - The scalar.
 *      CML_Matrix4x3 *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x3_scale(const CML_Matrix4x3 *A, f64 t, CML_Matrix4x3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x3_mult_matrix3x2(const CML_Matrix4x3 *A, const CML_Matrix3x2 *B, CML_Matrix4x2 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x3_mult_matrix3x3(const CML_Matrix4x3 *A, const CML_Matrix3x3 *B, CML_Matrix4x3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x3_mult_matrix3x4(const CML_Matrix4x3 *A, const CML_Matrix3x4 *B, CML_Matrix4x4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x3_mult_vector3(const CML_Matrix4x3 *A, const CML_Vector3 *v, CML_Vector4 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_vector4_mult_matrix4x3(const CML_Vector4 *v, const CML_Matrix4x3 *A, CML_Vector3 *out);


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
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cmlc_matrix4x3_transpose(const CML_Matrix4x3 *A, CML_Matrix3x4 *out);


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
CAMEL_API CML_Bool cmlc_matrix4x3_eq(const CML_Matrix4x3 *A, const CML_Matrix4x3 *B);


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
CAMEL_API char *cmlc_matrix4x3_debug(const CML_Matrix4x3 *expected, const CML_Matrix4x3 *got);


#endif /* CAMEL_CFIXED_MATRIX */
