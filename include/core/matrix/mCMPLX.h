/**
 * @file mCMPLX.h
 * 
 * @brief Declaration of Complex's type specific matrix functions.
 *
 * @author Sergio Madrid
 * @date 17/4/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_MCMPLX
#define CAMEL_MCMPLX


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
CML_Status cml_matrixCMPLX_set(CML_Complex *element, u32 row, u32 column, CML_Matrix *out);


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
CML_Complex *cml_matrixCMPLX_get(u32 row, u32 column, const CML_Matrix *matrix, CML_Status *out);


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
CML_Status cml_matrixCMPLX_add(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, CML_Matrix *out);


/**
 * @brief Adds two matrices in place (out += right) and stores the result in 
 *        the out matrix.
 *
 * @param right     The matrix on the right.
 * @param out       The matrix on the left.
 *
 * @return Status code.
 */
CML_Status cml_matrixCMPLX_add_inplace(const CML_Matrix *right, CML_Matrix *out);


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
CML_Status cml_matrixCMPLX_sub(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, CML_Matrix *out);


/**
 * @brief Subtracts two matrices in place (out -= right) and stores the result in 
 *        the out matrix.
 *
 * @param right     The matrix on the right.
 * @param out       The matrix on the left.
 *
 * @return Status code.
 */
CML_Status cml_matrixCMPLX_sub_inplace(const CML_Matrix *right, CML_Matrix *out);


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
CML_Status cml_matrixCMPLX_mult(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, CML_Matrix *out);


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
CML_Status cml_matrixCMPLX_multew(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, CML_Matrix *out);


/**
 * @brief Multiplies two matrices element by element, and stores the result in
 *        the out matrix out .*= right.
 *
 * @param right     The matrix on the right.
 * @param out       The matrix on the left.
 *
 * @return Status code.
 */
CML_Status cml_matrixCMPLX_multew_inplace(const CML_Matrix *right, CML_Matrix *out);


#endif /* CAMEL_MCMPLX */

