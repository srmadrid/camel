/******************************************************************************
 * Filename: vvector.h
 * 
 * Description:
 *      Declarations for the variable vector manipulation functions of CAMEL.
 * 
 * Author: Sergio Madrid
 * Created on: 25/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/

#ifndef CAMEL_VARIABLE_VECTOR
#define CAMEL_VARIABLE_VECTOR


#include <stdlib.h>
#include <math.h>

#include "../../../core/core.h"


/******************************************************************************
 * Struct: CML_Vector
 * 
 * Description:
 *      Represents a mathematical vector with components stored in a 
 *      dynamically allocated array. This struct is used throughout the CAMEL
 *      library to represent vectors in N-dimensional space.
 *
 * Fields:
 *      size_t n - The number of elements in the vector.
 *      f64 *data - A pointer to the dynamically allocated array of components.
 *
 * Notes:
 *      The 'data' pointer should be managed using cml_vector_init and
 *      cml_vector_free functions to ensure proper memory management. The 'n'
 *      should always reflect the number of allocated elements in 'data'.
 *****************************************************************************/
typedef struct {
    size_t n;
    f64 *data;
} CML_Vector;


/******************************************************************************
 * Function: cml_vector_init
 * 
 * Description:
 *      Initializes a vector of size 'n' to 0.
 *
 * Parameters:
 *      CML_Vector *v - The vector to be initialized.
 *      size_t n      - Size of the vector.
 * 
 * Returns:
 *      A pointer to the allocated CML_Vector.
 *****************************************************************************/
CAMEL_API CML_Status clm_vector_init(CML_Vector *v, size_t n);


/******************************************************************************
 * Function: cml_vector_free
 * 
 * Description:
 *      Frees the memory of the input CML_Vector.
 *
 * Parameters:
 *      CML_Vector *v - The pointer to the CML_Vector you want to free.
 * 
 * Returns:
 *      Void.
 *****************************************************************************/
CAMEL_API void sm_vector_free(CML_Vector *v);


/******************************************************************************
 * Function: cml_vector_add
 * 
 * Description:
 *      Adds two CML_Vector and writes the result to the out CML_Vector. Both 
 *      intput CML_Vector must have the same number of elements.
 *
 * Parameters:
 *      CML_Vector *v   - The first vector operand.
 *      CML_Vector *w   - The second vector operand.
 *      CML_Vector *out - The output vector.
 * 
 * Returns:
 *      Success (0) or error (<0) code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector_add(const CML_Vector *v, const CML_Vector *w, CML_Vector *out);


/******************************************************************************
 * Function: cml_vector_sub
 * 
 * Description:
 *      Subtracts two CML_Vector and writes the result to the out CML_Vector. Both 
 *      intput CML_Vector must have the same number of elements.
 *
 * Parameters:
 *      CML_Vector *v   - The first vector operand.
 *      CML_Vector *w   - The second vector operand.
 *      CML_Vector *out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector_sub(const CML_Vector *v, const CML_Vector *w, CML_Vector *out);


/******************************************************************************
 * Function: cml_vector_scale
 * 
 * Description:
 *      Multiplies a CML_Vector by a scalar, and writes the result to the out 
 *      CML_Vector.
 *
 * Parameters:
 *      CML_Vector *v   - The vector operand.
 *      double      t   - The scalar.
 *      CML_Vector *out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector_scale(const CML_Vector *v, f64 t, CML_Vector *out);


/******************************************************************************
 * Function: cml_vector_mod
 * 
 * Description:
 *      Calculates the modulus of the input CML_Vector.
 *
 * Parameters:
 *      CML_Vector *v - The input vector.
 * 
 * Returns:
 *      The modulus of the input CML_Vector.
 *****************************************************************************/
CAMEL_API f64 cml_vector_mod(const CML_Vector *v);


/******************************************************************************
 * Function: cml_vector_norm
 * 
 * Description:
 *      Normalizes the input CML_Vector and writes it to the out CML_Vector.
 *
 * Parameters:
 *      CML_Vector *v   - The input vector.
 *      CML_Vector *out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector_norm(const CML_Vector *v, CML_Vector *out);


/******************************************************************************
 * Function: cml_vector_dot
 * 
 * Description:
 *      Normalizes the input CML_Vector and writes it to the out CML_Vector.
 *
 * Parameters:
 *      CML_Vector *v   - The first input vector.
 *      CML_Vector *w   - The second input vector.
 * 
 * Returns:
 *      The dot product of the input vectors.
 *****************************************************************************/
CAMEL_API f64 cml_vector_dot(const CML_Vector *v, const CML_Vector *w);


#endif /* CAMEL_VARIABLE_VECTOR */
