/******************************************************************************
 * Filename: vmatrix.h
 * 
 * Description:
 *      Declarations for the variable matrix manipulation functions of CAMEL.
 * 
 * Author: Sergio Madrid
 * Created on: 25/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/

#ifndef CAMEL_VARIABLE_MATRIX
#define CAMEL_VARIABLE_MATRIX


#include <stdlib.h>
#include <math.h>

#include "../../../core/macros.h"
#include "../../../core/err.h"
#include "vvector.h"


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
    u32 m;
    u32 n;
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
CML_Status cml_matrix_init(CML_Matrix *A, u32 m, u32 n);


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
void cml_matrix_free(CML_Matrix *A);


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
CML_Status cml_matrix_add(const CML_Matrix *A, const CML_Matrix *B, CML_Matrix *out);


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
CML_Status cml_matrix_sub(const CML_Matrix *A, const CML_Matrix *B, CML_Matrix *out);


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
CML_Status cml_matrix_scale(const CML_Matrix *A, f64 t, CML_Matrix *out);


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
CML_Status cml_matrix_mult(const CML_Matrix *A, const CML_Matrix *B, CML_Matrix *out);


// TODO: Implement other matrix operations.


#endif /* CAMEL_VARIABLE_MATRIX */
