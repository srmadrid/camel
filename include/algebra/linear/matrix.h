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


#include <stdlib.h>
#include <math.h>

#include "../../core/core.h"
#include "vector.h"


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
 *      f64 **data - A pointer to the dynamically allocated array of components.
 *
 * Notes:
 *      The 'data' pointer should be managed using cml_matrix_init and
 *      cml_matrix_free functions to ensure proper memory management. 'MxN'
 *      should always reflect the number of allocated elements in 'data'.
 *****************************************************************************/
typedef struct {
    size_t m;
    size_t n;
    f64 **data;
} CML_Matrix;


/******************************************************************************
 * Function: cml_matrix_init
 * 
 * Description:
 *      Initializes a matrix of size 'MxN' to 0.
 *
 * Parameters:
 *      CML_Matrix *A - The matrix to be allocated.
 *      size_t m      - Number of rows of the matrix.
 *      size_t n      - Number of columns of the matrix.
 * 
 * Returns:
 *      A pointer to the allocated CML_Matrix.
 *****************************************************************************/
CAMEL_API CML_Status cml_matrix_init(CML_Matrix *A, size_t m, size_t n);


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
CAMEL_API void cml_matrix_free(CML_Matrix *A);


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
CAMEL_API CML_Status cml_matrix_add(const CML_Matrix *A, const CML_Matrix *B, CML_Matrix *out);


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
CAMEL_API CML_Status cml_matrix_sub(const CML_Matrix *A, const CML_Matrix *B, CML_Matrix *out);


/******************************************************************************
 * Function: cml_matrix_scale
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
CAMEL_API CML_Status cml_matrix_scale(const CML_Matrix *A, f64 t, CML_Matrix *out);


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
CAMEL_API CML_Status cml_matrix_mult(const CML_Matrix *A, const CML_Matrix *B, CML_Matrix *out);


// TODO: Implement other matrix operations.



/******************************************************************************
 * Type: CML_Matrix2x2
 * 
 * Description:
 *      Represents a 2x2 matrix.
 *
 * Notes:
 *      The object is directly an array of CML_Vector2.
 *****************************************************************************/
typedef CML_Vector2 CML_Matrix2x2[2];


/******************************************************************************
 * Macro: CML_MATRIX2X2_ZERO
 * 
 * Description:
 *      Initializes a CML_Matrix2x2 to the zero matrix.
 *****************************************************************************/
#define CML_MATRIX2X2_ZERO {CML_VECTOR2_ZERO, CML_VECTOR2_ZERO}


/******************************************************************************
 * Macro: CML_MATRIX2X2_IDENTITY
 * 
 * Description:
 *      Initializes a CML_Matrix2x2 to the identity matrix.
 *****************************************************************************/
#define CML_MATRIX2X2_IDENTITY {CML_VECTOR2_I, CML_VECTOR2_J}


/******************************************************************************
 * Macro: CML_MATRIX2X2_ONE
 * 
 * Description:
 *      Initializes a CML_Matrix2x2 to the one matrix.
 *****************************************************************************/
#define CML_MATRIX2X2_ONE {CML_VECTOR2_ONE, CML_VECTOR2_ONE}



/******************************************************************************
 * Type: CML_Matrix3x3
 * 
 * Description:
 *      Represents a 3x3 matrix.
 *
 * Notes:
 *      The object is directly an array of CML_Vector3.
 *****************************************************************************/
typedef CML_Vector3 CML_Matrix3x3[3];


/******************************************************************************
 * Macro: CML_MATRIX3X3_ZERO
 * 
 * Description:
 *      Initializes a CML_Matrix3x3 to the zero matrix.
 *****************************************************************************/
#define CML_MATRIX3X3_ZERO {CML_VECTOR3_ZERO, CML_VECTOR3_ZERO, CML_VECTOR3_ZERO}


/******************************************************************************
 * Macro: CML_MATRIX3X3_IDENTITY
 * 
 * Description:
 *      Initializes a CML_Matrix3x3 to the identity matrix.
 *****************************************************************************/
#define CML_MATRIX3X3_IDENTITY {CML_VECTOR3_I, CML_VECTOR3_J, CML_VECTOR3_K}


/******************************************************************************
 * Macro: CML_MATRIX3X3_ONE
 * 
 * Description:
 *      Initializes a CML_Matrix3x3 to the one matrix.
 *****************************************************************************/
#define CML_MATRIX3X3_ONE {CML_VECTOR3_ONE, CML_VECTOR3_ONE, CML_VECTOR3_ONE}



/******************************************************************************
 * Type: CML_Matrix4x4
 * 
 * Description:
 *      Represents a 4x4 matrix.
 *
 * Notes:
 *      The object is directly an array of CML_Vector4.
 *****************************************************************************/
typedef CML_Vector4 CML_Matrix4x4[4];


/******************************************************************************
 * Macro: CML_MATRIX4X4_ZERO
 * 
 * Description:
 *      Initializes a CML_Matrix4x4 to the zero matrix.
 *****************************************************************************/
#define CML_MATRIX4X4_ZERO {CML_VECTOR4_ZERO, CML_VECTOR4_ZERO, CML_VECTOR4_ZERO, CML_VECTOR4_ZERO}


/******************************************************************************
 * Macro: CML_MATRIX4X4_IDENTITY
 * 
 * Description:
 *      Initializes a CML_Matrix4x4 to the identity matrix.
 *****************************************************************************/
#define CML_MATRIX4X4_IDENTITY {CML_VECTOR4_I, CML_VECTOR4_J, CML_VECTOR4_K, CML_VECTOR4_L}


/******************************************************************************
 * Macro: CML_MATRIX4X4_ONE
 * 
 * Description:
 *      Initializes a CML_Matrix4x4 to the one matrix.
 *****************************************************************************/
#define CML_MATRIX4X4_ONE {CML_VECTOR4_ONE, CML_VECTOR4_ONE, CML_VECTOR4_ONE, CML_VECTOR4_ONE}



/******************************************************************************
 * Type: CML_Matrix2x3
 * 
 * Description:
 *      Represents a 2x3 matrix.
 *
 * Notes:
 *      The object is directly an array of CML_Vector2.
 *****************************************************************************/
typedef CML_Vector2 CML_Matrix2x3[3];


/******************************************************************************
 * Macro: CML_MATRIX2X3_ZERO
 * 
 * Description:
 *      Initializes a CML_Matrix2x3 to the zero matrix.
 *****************************************************************************/
#define CML_MATRIX2X3_ZERO {CML_VECTOR2_ZERO, CML_VECTOR2_ZERO, CML_VECTOR2_ZERO}


/******************************************************************************
 * Macro: CML_MATRIX2X3_IDENTITY
 * 
 * Description:
 *      Initializes a CML_Matrix2x3 to the identity matrix.
 *****************************************************************************/
#define CML_MATRIX2X3_IDENTITY {CML_VECTOR2_I, CML_VECTOR2_J, CML_VECTOR2_ZERO}


/******************************************************************************
 * Macro: CML_MATRIX2X3_ONE
 * 
 * Description:
 *      Initializes a CML_Matrix2x3 to the one matrix.
 *****************************************************************************/
#define CML_MATRIX2X3_ONE {CML_VECTOR2_ONE, CML_VECTOR2_ONE, CML_VECTOR2_ONE}



/******************************************************************************
 * Type: CML_Matrix2x4
 * 
 * Description:
 *      Represents a 2x4 matrix.
 *
 * Notes:
 *      The object is directly an array of CML_Vector2.
 *****************************************************************************/
typedef CML_Vector2 CML_Matrix2x4[4];


/******************************************************************************
 * Macro: CML_MATRIX2X4_ZERO
 * 
 * Description:
 *      Initializes a CML_Matrix2x4 to the zero matrix.
 *****************************************************************************/
#define CML_MATRIX2X4_ZERO {CML_VECTOR2_ZERO, CML_VECTOR2_ZERO, CML_VECTOR2_ZERO, CML_VECTOR2_ZERO}


/******************************************************************************
 * Macro: CML_MATRIX2X4_IDENTITY
 * 
 * Description:
 *      Initializes a CML_Matrix2x4 to the identity matrix.
 *****************************************************************************/
#define CML_MATRIX2X4_IDENTITY {CML_VECTOR2_I, CML_VECTOR2_J, CML_VECTOR2_ZERO, CML_VECTOR2_ZERO}


/******************************************************************************
 * Macro: CML_MATRIX2X4_ONE
 * 
 * Description:
 *      Initializes a CML_Matrix2x4 to the one matrix.
 *****************************************************************************/
#define CML_MATRIX2X4_ONE {CML_VECTOR2_ONE, CML_VECTOR2_ONE, CML_VECTOR2_ONE, CML_VECTOR2_ONE}



/******************************************************************************
 * Type: CML_Matrix3x2
 * 
 * Description:
 *      Represents a 3x2 matrix.
 *
 * Notes:
 *      The object is directly an array of CML_Vector3.
 *****************************************************************************/
typedef CML_Vector3 CML_Matrix3x2[2];


/******************************************************************************
 * Macro: CML_MATRIX3X2_ZERO
 * 
 * Description:
 *      Initializes a CML_Matrix3x2 to the zero matrix.
 *****************************************************************************/
#define CML_MATRIX3X2_ZERO {CML_VECTOR3_ZERO, CML_VECTOR3_ZERO}


/******************************************************************************
 * Macro: CML_MATRIX3X2_IDENTITY
 * 
 * Description:
 *      Initializes a CML_Matrix3x2 to the identity matrix.
 *****************************************************************************/
#define CML_MATRIX3X2_IDENTITY {CML_VECTOR3_I, CML_VECTOR3_J}


/******************************************************************************
 * Macro: CML_MATRIX3X2_ONE
 * 
 * Description:
 *      Initializes a CML_Matrix3x2 to the one matrix.
 *****************************************************************************/
#define CML_MATRIX3X2_ONE {CML_VECTOR3_ONE, CML_VECTOR3_ONE}



/******************************************************************************
 * Type: CML_Matrix3x4
 * 
 * Description:
 *      Represents a 3x4 matrix.
 *
 * Notes:
 *      The object is directly an array of CML_Vector3.
 *****************************************************************************/
typedef CML_Vector3 CML_Matrix3x4[4];


/******************************************************************************
 * Macro: CML_MATRIX3X4_ZERO
 * 
 * Description:
 *      Initializes a CML_Matrix3x4 to the zero matrix.
 *****************************************************************************/
#define CML_MATRIX3X4_ZERO {CML_VECTOR3_ZERO, CML_VECTOR3_ZERO, CML_VECTOR3_ZERO, CML_VECTOR3_ZERO}


/******************************************************************************
 * Macro: CML_MATRIX3X4_IDENTITY
 * 
 * Description:
 *      Initializes a CML_Matrix3x4 to the identity matrix.
 *****************************************************************************/
#define CML_MATRIX3X4_IDENTITY {CML_VECTOR3_I, CML_VECTOR3_J, CML_VECTOR3_K, CML_VECTOR3_ZERO}


/******************************************************************************
 * Macro: CML_MATRIX3X4_ONE
 * 
 * Description:
 *      Initializes a CML_Matrix3x4 to the one matrix.
 *****************************************************************************/
#define CML_MATRIX3X4_ONE {CML_VECTOR3_ONE, CML_VECTOR3_ONE, CML_VECTOR3_ONE, CML_VECTOR3_ONE}



/******************************************************************************
 * Type: CML_Matrix4x2
 * 
 * Description:
 *      Represents a 4x2 matrix.
 *
 * Notes:
 *      The object is directly an array of CML_Vector4.
 *****************************************************************************/
typedef CML_Vector4 CML_Matrix4x2[2];


/******************************************************************************
 * Macro: CML_MATRIX4X2_ZERO
 * 
 * Description:
 *      Initializes a CML_Matrix4x2 to the zero matrix.
 *****************************************************************************/
#define CML_MATRIX4X2_ZERO {CML_VECTOR4_ZERO, CML_VECTOR4_ZERO}


/******************************************************************************
 * Macro: CML_MATRIX4X2_IDENTITY
 * 
 * Description:
 *      Initializes a CML_Matrix4x2 to the identity matrix.
 *****************************************************************************/
#define CML_MATRIX4X2_IDENTITY {CML_VECTOR4_I, CML_VECTOR4_J}


/******************************************************************************
 * Macro: CML_MATRIX4X2_ONE
 * 
 * Description:
 *      Initializes a CML_Matrix4x2 to the one matrix.
 *****************************************************************************/
#define CML_MATRIX4X2_ONE {CML_VECTOR4_ONE, CML_VECTOR4_ONE}



/******************************************************************************
 * Type: CML_Matrix4x3
 * 
 * Description:
 *      Represents a 4x3 matrix.
 *
 * Notes:
 *      The object is directly an array of CML_Vector4.
 *****************************************************************************/
typedef CML_Vector4 CML_Matrix4x3[3];


/******************************************************************************
 * Macro: CML_MATRIX4X3_ZERO
 * 
 * Description:
 *      Initializes a CML_Matrix4x3 to the zero matrix.
 *****************************************************************************/
#define CML_MATRIX4X3_ZERO {CML_VECTOR4_ZERO, CML_VECTOR4_ZERO, CML_VECTOR4_ZERO}


/******************************************************************************
 * Macro: CML_MATRIX4X3_IDENTITY
 * 
 * Description:
 *      Initializes a CML_Matrix4x3 to the identity matrix.
 *****************************************************************************/
#define CML_MATRIX4X3_IDENTITY {CML_VECTOR4_I, CML_VECTOR4_J, CML_VECTOR4_K}


/******************************************************************************
 * Macro: CML_MATRIX4X3_ONE
 * 
 * Description:
 *      Initializes a CML_Matrix4x3 to the one matrix.
 *****************************************************************************/
#define CML_MATRIX4X3_ONE {CML_VECTOR4_ONE, CML_VECTOR4_ONE, CML_VECTOR4_ONE}



/******************************************************************************
 * Type: CML_Matrix4x3
 * 
 * Description:
 *      Represents a 4x3 matrix.
 *
 * Notes:
 *      The object is directly an array of CML_Vector4.
 *****************************************************************************/
typedef CML_Vector4 CML_Matrix4x3[3];


/******************************************************************************
 * Macro: CML_MATRIX4X3_ZERO
 * 
 * Description:
 *      Initializes a CML_Matrix4x3 to the zero matrix.
 *****************************************************************************/
#define CML_MATRIX4X3_ZERO {CML_VECTOR4_ZERO, CML_VECTOR4_ZERO, CML_VECTOR4_ZERO}


/******************************************************************************
 * Macro: CML_MATRIX4X3_IDENTITY
 * 
 * Description:
 *      Initializes a CML_Matrix4x3 to the identity matrix.
 *****************************************************************************/
#define CML_MATRIX4X3_IDENTITY {CML_VECTOR4_I, CML_VECTOR4_J, CML_VECTOR4_K}


/******************************************************************************
 * Macro: CML_MATRIX4X3_ONE
 * 
 * Description:
 *      Initializes a CML_Matrix4x3 to the one matrix.
 *****************************************************************************/
#define CML_MATRIX4X3_ONE {CML_VECTOR4_ONE, CML_VECTOR4_ONE, CML_VECTOR4_ONE}



/******************************************************************************
 * Function: cml_matrix2x2_add
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
CAMEL_API CML_Status cml_matrix2x2_add(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cml_matrix2x2_sub
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
CAMEL_API CML_Status cml_matrix2x2_sub(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cml_matrix2x2_scale
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
CAMEL_API CML_Status cml_matrix2x2_scale(const CML_Matrix2x2 *A, f64 t, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cml_matrix2x2_mult
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
CAMEL_API CML_Status cml_matrix2x2_mult(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cml_matrix2x2_mult_vector2
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
CAMEL_API CML_Status cml_matrix2x2_mult_vector2(const CML_Matrix2x2 *A, const CML_Vector2 *v, CML_Vector2 *out);


/******************************************************************************
 * Function: cml_vec2_mult_matrix2x2
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
CAMEL_API CML_Status cml_vector2_mult_matrix2x2(const CML_Vector2 *v, const CML_Matrix2x2 *A, CML_Vector2 *out);


/******************************************************************************
 * Function: cml_matrix2x2_det
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
CAMEL_API f64 cml_matrix2x2_det(const CML_Matrix2x2 *A);


/******************************************************************************
 * Function: cml_matrix2x2_inv
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
CAMEL_API CML_Status cml_matrix2x2_inv(const CML_Matrix2x2 *A, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cml_matrix2x2_transpose
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
CAMEL_API CML_Status cml_matrix2x2_transpose(const CML_Matrix2x2 *A, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cml_matrix2x2_trace
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
CAMEL_API f64 cml_matrix2x2_trace(const CML_Matrix2x2 *A);


/******************************************************************************
 * Function: cml_matrix2x2_compare
 * 
 * Description:
 *      Compares two CML_Matrix2x2s for equality.
 * 
 * Parameters:
 *      CML_Matrix2x2 *v - The first input vector.
 *      CML_Matrix2x2 *w - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CAMEL_API CML_Bool cml_matrix2x2_compare(const CML_Matrix2x2 *A, const CML_Matrix2x2 *B);



/******************************************************************************
 * Function: cml_matrix3x3_add
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
CAMEL_API CML_Status cml_matrix3x3_add(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cml_matrix3x3_sub
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
CAMEL_API CML_Status cml_matrix3x3_sub(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cml_matrix3x3_scale
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
CAMEL_API CML_Status cml_matrix3x3_scale(const CML_Matrix3x3 *A, f64 t, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cml_matrix3x3_mult
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
CAMEL_API CML_Status cml_matrix3x3_mult(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cml_matrix3x3_mult_vector3
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
CAMEL_API CML_Status cml_matrix3x3_mult_vector3(const CML_Matrix3x3 *A, const CML_Vector3 *v, CML_Vector3 *out);


/******************************************************************************
 * Function: cml_vector3_mult_matrix3x3
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
CAMEL_API CML_Status cml_vector3_mult_matrix3x3(const CML_Vector3 *v, const CML_Matrix3x3 *A, CML_Vector3 *out);


/******************************************************************************
 * Function: cml_matrix3x3_det
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
CAMEL_API f64 cml_matrix3x3_det(const CML_Matrix3x3 *A);


/******************************************************************************
 * Function: cml_matrix3x3_inv
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
CAMEL_API CML_Status cml_matrix3x3_inv(const CML_Matrix3x3 *A, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cml_matrix3x3_transpose
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
CAMEL_API CML_Status cml_matrix3x3_transpose(const CML_Matrix3x3 *A, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cml_matrix3x3_trace
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
CAMEL_API f64 cml_matrix3x3_trace(const CML_Matrix3x3 *A);


/******************************************************************************
 * Function: cml_matrix3x3_compare
 * 
 * Description:
 *      Compares two CML_Matrix3x3s for equality.
 * 
 * Parameters:
 *      CML_Matrix3x3 *v - The first input vector.
 *      CML_Matrix3x3 *w - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CAMEL_API CML_Bool cml_matrix3x3_compare(const CML_Matrix3x3 *A, const CML_Matrix3x3 *B);



/******************************************************************************
 * Function: cml_matrix4x4_add
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
CAMEL_API CML_Status cml_matrix4x4_add(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cml_matrix4x4_sub
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
CAMEL_API CML_Status cml_matrix4x4_sub(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cml_matrix4x4_scale
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
CAMEL_API CML_Status cml_matrix4x4_scale(const CML_Matrix4x4 *A, f64 t, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cml_matrix4x4_mult
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
CAMEL_API CML_Status cml_matrix4x4_mult(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cml_matrix4x4_mult_vector4
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
CAMEL_API CML_Status cml_matrix4x4_mult_vector4(const CML_Matrix4x4 *A, const CML_Vector4 *v, CML_Vector4 *out);


/******************************************************************************
 * Function: cml_vector4_mult_matrix4x4
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
CAMEL_API CML_Status cml_vector4_mult_matrix4x4(const CML_Vector4 *v, const CML_Matrix4x4 *A, CML_Vector4 *out);


/******************************************************************************
 * Function: cml_matrix4x4_det
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
CAMEL_API f64 cml_matrix4x4_det(const CML_Matrix4x4 *A);


/******************************************************************************
 * Function: cml_matrix4x4_inv
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
CAMEL_API CML_Status cml_matrix4x4_inv(const CML_Matrix4x4 *A, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cml_matrix4x4_transpose
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
CAMEL_API CML_Status cml_matrix4x4_transpose(const CML_Matrix4x4 *A, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cml_matrix4x4_trace
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
CAMEL_API f64 cml_matrix4x4_trace(const CML_Matrix4x4 *A);


/******************************************************************************
 * Function: cml_matrix4x4_compare
 * 
 * Description:
 *      Compares two CML_Matrix4x4s for equality.
 * 
 * Parameters:
 *      CML_Matrix4x4 *v - The first input vector.
 *      CML_Matrix4x4 *w - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CAMEL_API CML_Bool cml_matrix4x4_compare(const CML_Matrix4x4 *A, const CML_Matrix4x4 *B);



/******************************************************************************
 * Function: cml_matrix2x3_add
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
CAMEL_API CML_Status cml_matrix2x3_add(const CML_Matrix2x3 *A, const CML_Matrix2x3 *B, CML_Matrix2x3 *out);


/******************************************************************************
 * Function: cml_matrix2x3_sub
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
CAMEL_API CML_Status cml_matrix2x3_sub(const CML_Matrix2x3 *A, const CML_Matrix2x3 *B, CML_Matrix2x3 *out);


/******************************************************************************
 * Function: cml_matrix2x3_scale
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
CAMEL_API CML_Status cml_matrix2x3_scale(const CML_Matrix2x3 *A, f64 t, CML_Matrix2x3 *out);


/******************************************************************************
 * Function: cml_matrix2x3_mult_matrix3x2
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
CAMEL_API CML_Status cml_matrix2x3_mult_matrix3x2(const CML_Matrix2x3 *A, const CML_Matrix3x2 *B, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cml_matrix2x3_mult_matrix3x3
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
CAMEL_API CML_Status cml_matrix2x3_mult_matrix3x3(const CML_Matrix2x3 *A, const CML_Matrix3x3 *B, CML_Matrix2x3 *out);


/******************************************************************************
 * Function: cml_matrix2x3_mult_matrix3x4
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
CAMEL_API CML_Status cml_matrix2x3_mult_matrix3x4(const CML_Matrix2x3 *A, const CML_Matrix3x4 *B, CML_Matrix2x4 *out);


/******************************************************************************
 * Function: cml_matrix2x3_mult_vector3
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
CAMEL_API CML_Status cml_matrix2x3_mult_vector3(const CML_Matrix2x3 *A, const CML_Vector3 *v, CML_Vector2 *out);


/******************************************************************************
 * Function: cml_vector2_mult_matrix2x3
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
CAMEL_API CML_Status cml_vector2_mult_matrix2x3(const CML_Vector2 *v, const CML_Matrix2x3 *A, CML_Vector3 *out);


/******************************************************************************
 * Function: cml_matrix2x3_inv
 * 
 * Description:
 *     Calculates the inverse of a CML_Matrix2x3.
 * 
 * Parameters:
 *      CML_Matrix2x3 *A   - The matrix operand.
 *      CML_Matrix2x3 *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_matrix2x3_inv(const CML_Matrix2x3 *A, CML_Matrix2x3 *out);


/******************************************************************************
 * Function: cml_matrix2x3_transpose
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
CAMEL_API CML_Status cml_matrix2x3_transpose(const CML_Matrix2x3 *A, CML_Matrix3x2 *out);


/******************************************************************************
 * Function: cml_matrix2x3_compare
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
CAMEL_API CML_Bool cml_matrix2x3_compare(const CML_Matrix2x3 *A, const CML_Matrix2x3 *B);



/******************************************************************************
 * Function: cml_matrix2x4_add
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
CAMEL_API CML_Status cml_matrix2x4_add(const CML_Matrix2x4 *A, const CML_Matrix2x4 *B, CML_Matrix2x4 *out);


/******************************************************************************
 * Function: cml_matrix2x4_sub
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
CAMEL_API CML_Status cml_matrix2x4_sub(const CML_Matrix2x4 *A, const CML_Matrix2x4 *B, CML_Matrix2x4 *out);


/******************************************************************************
 * Function: cml_matrix2x4_scale
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
CAMEL_API CML_Status cml_matrix2x4_scale(const CML_Matrix2x4 *A, f64 t, CML_Matrix2x4 *out);


/******************************************************************************
 * Function: cml_matrix2x4_mult_matrix4x2
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
CAMEL_API CML_Status cml_matrix2x4_mult_matrix4x2(const CML_Matrix2x4 *A, const CML_Matrix4x2 *B, CML_Matrix2x2 *out);


/******************************************************************************
 * Function: cml_matrix2x4_mult_matrix4x3
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
CAMEL_API CML_Status cml_matrix2x4_mult_matrix4x3(const CML_Matrix2x4 *A, const CML_Matrix4x3 *B, CML_Matrix2x3 *out);


/******************************************************************************
 * Function: cml_matrix2x4_mult_matrix4x4
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
CAMEL_API CML_Status cml_matrix2x4_mult_matrix4x4(const CML_Matrix2x4 *A, const CML_Matrix4x4 *B, CML_Matrix2x4 *out);


/******************************************************************************
 * Function: cml_matrix2x4_mult_vector4
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
CAMEL_API CML_Status cml_matrix2x4_mult_vector4(const CML_Matrix2x4 *A, const CML_Vector4 *v, CML_Vector2 *out);


/******************************************************************************
 * Function: cml_vector2_mult_matrix2x4
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
CAMEL_API CML_Status cml_vector2_mult_matrix2x4(const CML_Vector2 *v, const CML_Matrix2x4 *A, CML_Vector4 *out);


/******************************************************************************
 * Function: cml_matrix2x4_inv
 * 
 * Description:
 *     Calculates the inverse of a CML_Matrix2x4.
 * 
 * Parameters:
 *      CML_Matrix2x4 *A   - The matrix operand.
 *      CML_Matrix2x4 *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_matrix2x4_inv(const CML_Matrix2x4 *A, CML_Matrix2x4 *out);


/******************************************************************************
 * Function: cml_matrix2x4_transpose
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
CAMEL_API CML_Status cml_matrix2x4_transpose(const CML_Matrix2x4 *A, CML_Matrix4x2 *out);


/******************************************************************************
 * Function: cml_matrix2x4_compare
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
CAMEL_API CML_Bool cml_matrix2x4_compare(const CML_Matrix2x4 *A, const CML_Matrix2x4 *B);



/******************************************************************************
 * Function: cml_matrix3x2_add
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
CAMEL_API CML_Status cml_matrix3x2_add(const CML_Matrix3x2 *A, const CML_Matrix3x2 *B, CML_Matrix3x2 *out);


/******************************************************************************
 * Function: cml_matrix3x2_sub
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
CAMEL_API CML_Status cml_matrix3x2_sub(const CML_Matrix3x2 *A, const CML_Matrix3x2 *B, CML_Matrix3x2 *out);


/******************************************************************************
 * Function: cml_matrix3x2_scale
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
CAMEL_API CML_Status cml_matrix3x2_scale(const CML_Matrix3x2 *A, f64 t, CML_Matrix3x2 *out);


/******************************************************************************
 * Function: cml_matrix3x2_mult_matrix2x2
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
CAMEL_API CML_Status cml_matrix3x2_mult_matrix2x2(const CML_Matrix3x2 *A, const CML_Matrix2x2 *B, CML_Matrix3x2 *out);


/******************************************************************************
 * Function: cml_matrix3x2_mult_matrix2x3
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
CAMEL_API CML_Status cml_matrix3x2_mult_matrix2x3(const CML_Matrix3x2 *A, const CML_Matrix2x3 *B, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cml_matrix3x2_mult_matrix2x4
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
CAMEL_API CML_Status cml_matrix3x2_mult_matrix2x4(const CML_Matrix3x2 *A, const CML_Matrix2x4 *B, CML_Matrix3x4 *out);


/******************************************************************************
 * Function: cml_matrix3x2_mult_vector2
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
CAMEL_API CML_Status cml_matrix3x2_mult_vector2(const CML_Matrix3x2 *A, const CML_Vector2 *v, CML_Vector3 *out);


/******************************************************************************
 * Function: cml_vector3_mult_matrix3x2
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
CAMEL_API CML_Status cml_vector3_mult_matrix3x2(const CML_Vector3 *v, const CML_Matrix3x2 *A, CML_Vector2 *out);


/******************************************************************************
 * Function: cml_matrix3x2_inv
 * 
 * Description:
 *     Calculates the inverse of a CML_Matrix3x2.
 * 
 * Parameters:
 *      CML_Matrix3x2 *A   - The matrix operand.
 *      CML_Matrix3x2 *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_matrix3x2_inv(const CML_Matrix3x2 *A, CML_Matrix3x2 *out);


/******************************************************************************
 * Function: cml_matrix3x2_transpose
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
CAMEL_API CML_Status cml_matrix3x2_transpose(const CML_Matrix3x2 *A, CML_Matrix2x3 *out);


/******************************************************************************
 * Function: cml_matrix3x2_compare
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
CAMEL_API CML_Bool cml_matrix3x2_compare(const CML_Matrix3x2 *A, const CML_Matrix3x2 *B);



/******************************************************************************
 * Function: cml_matrix3x4_add
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
CAMEL_API CML_Status cml_matrix3x4_add(const CML_Matrix3x4 *A, const CML_Matrix3x4 *B, CML_Matrix3x4 *out);


/******************************************************************************
 * Function: cml_matrix3x4_sub
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
CAMEL_API CML_Status cml_matrix3x4_sub(const CML_Matrix3x4 *A, const CML_Matrix3x4 *B, CML_Matrix3x4 *out);


/******************************************************************************
 * Function: cml_matrix3x4_scale
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
CAMEL_API CML_Status cml_matrix3x4_scale(const CML_Matrix3x4 *A, f64 t, CML_Matrix3x4 *out);


/******************************************************************************
 * Function: cml_matrix3x4_mult_matrix4x2
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
CAMEL_API CML_Status cml_matrix3x4_mult_matrix4x2(const CML_Matrix3x4 *A, const CML_Matrix4x2 *B, CML_Matrix3x2 *out);


/******************************************************************************
 * Function: cml_matrix3x4_mult_matrix4x3
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
CAMEL_API CML_Status cml_matrix3x4_mult_matrix4x3(const CML_Matrix3x4 *A, const CML_Matrix4x3 *B, CML_Matrix3x3 *out);


/******************************************************************************
 * Function: cml_matrix3x4_mult_matrix4x4
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
CAMEL_API CML_Status cml_matrix3x4_mult_matrix4x4(const CML_Matrix3x4 *A, const CML_Matrix4x4 *B, CML_Matrix3x4 *out);


/******************************************************************************
 * Function: cml_matrix3x4_mult_vector4
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
CAMEL_API CML_Status cml_matrix3x4_mult_vector4(const CML_Matrix3x4 *A, const CML_Vector4 *v, CML_Vector3 *out);


/******************************************************************************
 * Function: cml_vector3_mult_matrix3x4
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
CAMEL_API CML_Status cml_vector3_mult_matrix3x4(const CML_Vector3 *v, const CML_Matrix3x4 *A, CML_Vector4 *out);


/******************************************************************************
 * Function: cml_matrix3x4_inv
 * 
 * Description:
 *     Calculates the inverse of a CML_Matrix3x4.
 * 
 * Parameters:
 *      CML_Matrix3x4 *A   - The matrix operand.
 *      CML_Matrix3x4 *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_matrix3x4_inv(const CML_Matrix3x4 *A, CML_Matrix3x4 *out);


/******************************************************************************
 * Function: cml_matrix3x4_transpose
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
CAMEL_API CML_Status cml_matrix3x4_transpose(const CML_Matrix3x4 *A, CML_Matrix4x3 *out);


/******************************************************************************
 * Function: cml_matrix3x4_compare
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
CAMEL_API CML_Bool cml_matrix3x4_compare(const CML_Matrix3x4 *A, const CML_Matrix3x4 *B);



/******************************************************************************
 * Function: cml_matrix4x2_add
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
CAMEL_API CML_Status cml_matrix4x2_add(const CML_Matrix4x2 *A, const CML_Matrix4x2 *B, CML_Matrix4x2 *out);


/******************************************************************************
 * Function: cml_matrix4x2_sub
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
CAMEL_API CML_Status cml_matrix4x2_sub(const CML_Matrix4x2 *A, const CML_Matrix4x2 *B, CML_Matrix4x2 *out);


/******************************************************************************
 * Function: cml_matrix4x2_scale
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
CAMEL_API CML_Status cml_matrix4x2_scale(const CML_Matrix4x2 *A, f64 t, CML_Matrix4x2 *out);


/******************************************************************************
 * Function: cml_matrix4x2_mult_matrix2x2
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
CAMEL_API CML_Status cml_matrix4x2_mult_matrix2x2(const CML_Matrix4x2 *A, const CML_Matrix2x2 *B, CML_Matrix4x2 *out);


/******************************************************************************
 * Function: cml_matrix4x2_mult_matrix2x3
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
CAMEL_API CML_Status cml_matrix4x2_mult_matrix2x3(const CML_Matrix4x2 *A, const CML_Matrix2x3 *B, CML_Matrix4x3 *out);


/******************************************************************************
 * Function: cml_matrix4x2_mult_matrix2x4
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
CAMEL_API CML_Status cml_matrix4x2_mult_matrix2x4(const CML_Matrix4x2 *A, const CML_Matrix2x4 *B, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cml_matrix4x2_mult_vector2
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
CAMEL_API CML_Status cml_matrix4x2_mult_vector2(const CML_Matrix4x2 *A, const CML_Vector2 *v, CML_Vector4 *out);


/******************************************************************************
 * Function: cml_vector4_mult_matrix4x2
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
CAMEL_API CML_Status cml_vector4_mult_matrix4x2(const CML_Vector4 *v, const CML_Matrix4x2 *A, CML_Vector2 *out);


/******************************************************************************
 * Function: cml_matrix4x2_inv
 * 
 * Description:
 *     Calculates the inverse of a CML_Matrix4x2.
 * 
 * Parameters:
 *      CML_Matrix4x2 *A   - The matrix operand.
 *      CML_Matrix4x2 *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_matrix4x2_inv(const CML_Matrix4x2 *A, CML_Matrix4x2 *out);


/******************************************************************************
 * Function: cml_matrix4x2_transpose
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
CAMEL_API CML_Status cml_matrix4x2_transpose(const CML_Matrix4x2 *A, CML_Matrix2x4 *out);


/******************************************************************************
 * Function: cml_matrix4x2_compare
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
CAMEL_API CML_Bool cml_matrix4x2_compare(const CML_Matrix4x2 *A, const CML_Matrix4x2 *B);



/******************************************************************************
 * Function: cml_matrix4x3_add
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
CAMEL_API CML_Status cml_matrix4x3_add(const CML_Matrix4x3 *A, const CML_Matrix4x3 *B, CML_Matrix4x3 *out);


/******************************************************************************
 * Function: cml_matrix4x3_sub
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
CAMEL_API CML_Status cml_matrix4x3_sub(const CML_Matrix4x3 *A, const CML_Matrix4x3 *B, CML_Matrix4x3 *out);


/******************************************************************************
 * Function: cml_matrix4x3_scale
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
CAMEL_API CML_Status cml_matrix4x3_scale(const CML_Matrix4x3 *A, f64 t, CML_Matrix4x3 *out);


/******************************************************************************
 * Function: cml_matrix4x3_mult_matrix3x2
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
CAMEL_API CML_Status cml_matrix4x3_mult_matrix3x2(const CML_Matrix4x3 *A, const CML_Matrix3x2 *B, CML_Matrix4x2 *out);


/******************************************************************************
 * Function: cml_matrix4x3_mult_matrix3x3
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
CAMEL_API CML_Status cml_matrix4x3_mult_matrix3x3(const CML_Matrix4x3 *A, const CML_Matrix3x3 *B, CML_Matrix4x3 *out);


/******************************************************************************
 * Function: cml_matrix4x3_mult_matrix3x4
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
CAMEL_API CML_Status cml_matrix4x3_mult_matrix3x4(const CML_Matrix4x3 *A, const CML_Matrix3x4 *B, CML_Matrix4x4 *out);


/******************************************************************************
 * Function: cml_matrix4x3_mult_vector3
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
CAMEL_API CML_Status cml_matrix4x3_mult_vector3(const CML_Matrix4x3 *A, const CML_Vector3 *v, CML_Vector4 *out);


/******************************************************************************
 * Function: cml_vector4_mult_matrix4x3
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
CAMEL_API CML_Status cml_vector4_mult_matrix4x3(const CML_Vector4 *v, const CML_Matrix4x3 *A, CML_Vector3 *out);


/******************************************************************************
 * Function: cml_matrix4x3_inv
 * 
 * Description:
 *     Calculates the inverse of a CML_Matrix4x3.
 * 
 * Parameters:
 *      CML_Matrix4x3 *A   - The matrix operand.
 *      CML_Matrix4x3 *out - The output matrix.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_matrix4x3_inv(const CML_Matrix4x3 *A, CML_Matrix4x3 *out);


/******************************************************************************
 * Function: cml_matrix4x3_transpose
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
CAMEL_API CML_Status cml_matrix4x3_transpose(const CML_Matrix4x3 *A, CML_Matrix3x4 *out);


/******************************************************************************
 * Function: cml_matrix4x3_compare
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
CAMEL_API CML_Bool cml_matrix4x3_compare(const CML_Matrix4x3 *A, const CML_Matrix4x3 *B);


#endif /* CAMEL_MATRIX */
