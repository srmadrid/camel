/**
 * @file mI16.h
 * 
 * @brief Declaration of i16's type specific matrix functions.
 *
 * @author Sergio Madrid
 * @date 17/4/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_MI16
#define CAMEL_MI16


#include "m.h"


/**
 * @brief Sets the element at the specified location to the input value.
 *
 * @param element Value to insert in the matrix.
 * @param row     Row of the element.
 * @param column  Column of the element.
 * @param out     The matrix.
 *
 * @return Status code.
 */
CML_Status cml_matrixI16_set(i16 element, u32 row, u32 column, CML_Matrix *out);


#endif /* CAMEL_MI16 */
