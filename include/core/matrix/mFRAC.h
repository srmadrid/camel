/**
 * @file mFRAC.h
 * 
 * @brief Declaration of Fraction's type specific matrix functions.
 *
 * @author Sergio Madrid
 * @date 17/4/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_MFRAC
#define CAMEL_MFRAC


#include "m.h"


/**
 * @brief Sets the element at the specified location to the input value. Takes
 *        ownership of the object.
 *
 * @param element Value to insert in the matrix.
 * @param row     Row of the element.
 * @param column  Column of the element.
 * @param out     The matrix.
 *
 * @return Status code.
 */
CML_Status cml_matrixFRAC_set(CML_Fraction *element, u32 row, u32 column, CML_Matrix *out);


/**
 * @brief Gets the element at the input location of a CML_Matrix.
 * 
 * @param row   Row of the element to be retrieved.
 * @param column Column of the element to be retrieved.
 * @param matrix The CML_Matrix to be retrieved from.
 * @param out Optional error checking parameter.
 * 
 * @return The element.
 */
CML_Fraction *cml_matrixFRAC_get(u32 row, u32 column, const CML_Matrix *matrix, CML_Status *out);


/**
 * @brief Adds two matrices and stores the result in the out matrix.
 *
 * @param allocator Allocator for the new matrix.
 * @param left      The matrix on the left.
 * @param right     The matrix on the right.
 * @param out       Output matrix.
 *
 * @return Status code.
 */
CML_Status cml_matrixFRAC_add(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, CML_Matrix *out);


/**
 * @brief Subtracts two matrices and stores the result in the out matrix.
 *
 * @param allocator Allocator for the new matrix.
 * @param left      The matrix on the left.
 * @param right     The matrix on the right.
 * @param out       Output matrix.
 *
 * @return Status code.
 */
CML_Status cml_matrixFRAC_sub(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, CML_Matrix *out);


/**
 * @brief Multiplies two matrices and stores the result in the out matrix.
 *
 * @param allocator Allocator for the new matrix.
 * @param left      The matrix on the left.
 * @param right     The matrix on the right.
 * @param out       Output matrix.
 *
 * @return Status code.
 */
CML_Status cml_matrixFRAC_mult(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, CML_Matrix *out);


/**
 * @brief Multiplies two matrices element by element, and stores the result in
 *        out.
 *
 * @param allocator Allocator for the new matrix.
 * @param left      The matrix on the left.
 * @param right     The matrix on the right.
 * @param out       Output matrix.
 *
 * @return Status code.
 */
CML_Status cml_matrixFRAC_multew(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, CML_Matrix *out);


/**
 * @brief Divides two matrices element by element, and stores the result in
 *        out.
 *
 * @param allocator Allocator for the new matrix.
 * @param left      The matrix on the left.
 * @param right     The matrix on the right.
 * @param out       Output matrix.
 *
 * @return Status code.
 */
CML_Status cml_matrixFRAC_divew(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, CML_Matrix *out);


/**
 * @brief Transposes a matrix and stores the result in the out matrix.
 *
 * @param allocator Allocator for the new matrix.
 * @param A         Matrix to be transposed.
 * @param out       Output matrix.
 *
 * @return Status code.
 */
CML_Status cml_matrixFRAC_transpose(CML_Allocator *allocator, const CML_Matrix *A, CML_Matrix *out);


/**
 * @brief Prints the input matrix.
 *
 * @param allocator Allocator for the temporary array.
 * @param matrix The matrix to be printed.
 *
 * @return Status code. */
CML_Status cml_matrixFRAC_print(CML_Allocator *allocator, const CML_Matrix *matrix);


#endif /* CAMEL_MFRAC */

