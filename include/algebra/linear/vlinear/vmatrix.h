/**
 * @file vmatrix.h
 * 
 * @brief Declarations for the variable matrix manipulation functions of CAMEL.
 * 
 * @author Sergio Madrid
 * @date 25/12/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_VARIABLE_MATRIX
#define CAMEL_VARIABLE_MATRIX


#include <stdlib.h>
#include <math.h>

#include "../../../core/macros.h"
#include "../../../core/err.h"
#include "vvector.h"


/**
 * @brief Represents a matrix of customizable size.
 *
 * @note The matrix is represented as a 2D array of doubles.
 */
typedef struct CML_Matrix {
    u32 m;
    u32 n;
    f64 **data;
} CML_Matrix;


/**
 * @brief Initializes a matrix of size 'MxN' to 0.
 *
 * @param m      Number of rows of the matrix.
 * @param n      Number of columns of the matrix.
 * @param matrix The matrix to be initialized.
 * 
 * @return Success or error code.
 */
CML_Status cml_matrix_init(u32 m, u32 n, CML_Matrix *matrix);


/**
 * @brief Frees the memory allocated for a matrix.
 *
 * @param matrix The matrix to be freed.
 * 
 * @return void.
 */
void cml_matrix_free(CML_Matrix *matrix);


/**
 * @brief Adds two CML_Matrix and writes the result to the out CML_Matrix. Both 
 *        intput and out CML_Matrix must have the same size.
 *
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return Success or error code.
 */
CML_Status cml_matrix_add(const CML_Matrix *A, const CML_Matrix *B, CML_Matrix *out);


/**
 * @brief Subtracts two CML_Matrix and writes the result to the out CML_Matrix. 
 *        Both intput and out CML_Matrix must have the same size.
 *
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return Success or error code.
 */
CML_Status cml_matrix_sub(const CML_Matrix *A, const CML_Matrix *B, CML_Matrix *out);


/**
 * @brief Multiplies a CML_Matrix by a scalar and writes the result to the out 
 *        CML_Matrix. Both intput and out CML_Matrix must have the same size.
 *
 * @param A   The matrix operand.
 * @param t   The scalar operand.
 * @param out The output matrix.
 * 
 * @return Success or error code.
 */
CML_Status cml_matrix_scale(const CML_Matrix *A, f64 t, CML_Matrix *out);


/**
 * @brief Multiplies two CML_Matrix and writes the result to the out CML_Matrix. 
 *        Both intput and out CML_Matrix must have the correct sizes.
 *
 * @param A   The left matrix operand.
 * @param B   The right matrix operand.
 * @param out The output matrix.
 * 
 * @return Success or error code.
 */
CML_Status cml_matrix_mult(const CML_Matrix *A, const CML_Matrix *B, CML_Matrix *out);


// TODO: Implement other matrix operations.


#endif /* CAMEL_VARIABLE_MATRIX */
