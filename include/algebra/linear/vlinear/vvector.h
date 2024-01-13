/**
 * @file vvector.h
 * 
 * @brief Declarations for the variable vector manipulation functions of CAMEL.
 * 
 * @author Sergio Madrid
 * @date 25/12/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_VARIABLE_VECTOR
#define CAMEL_VARIABLE_VECTOR


#include <stdlib.h>
#include <math.h>

#include "../../../core/macros.h"
#include "../../../core/err.h"


/**
 * @brief Represents a vector of customizable size.
 *
 * @note The vector is represented as a 1D array of doubles.
 */
typedef struct CML_Vector {
    u32 n;
    f64 *data;
} CML_Vector;


/**
 * @brief Initializes a vector of size 'n' to 0.
 *
 * @param n      Size of the vector.
 * @param vector The vector to be initialized.
 * 
 * @return Success or error code.
 */
CML_Status clm_vector_init(u32 n, CML_Vector *vector);


/**
 * @brief Frees the memory allocated for a vector.
 *
 * @param vector The vector to be freed.
 * 
 * @return void.
 */
void cml_vector_free(CML_Vector *vector);


/**
 * @brief Adds two CML_Vector and writes the result to the out CML_Vector. Both 
 *        intput and out CML_Vector must have the same size.
 *
 * @param v   The left vector operand.
 * @param w   The right vector operand.
 * @param out The output vector.
 * 
 * @return Success or error code.
 */
CML_Status cml_vector_add(const CML_Vector *v, const CML_Vector *w, CML_Vector *out);


/**
 * @brief Subtracts two CML_Vector and writes the result to the out CML_Vector. 
 *        Both intput and out CML_Vector must have the same size.
 *
 * @param v   The left vector operand.
 * @param w   The right vector operand.
 * @param out The output vector.
 * 
 * @return Success or error code.
 */
CML_Status cml_vector_sub(const CML_Vector *v, const CML_Vector *w, CML_Vector *out);


/**
 * @brief Multiplies a CML_Vector by a scalar and writes the result to the out 
 *        CML_Vector. Both intput and out CML_Vector must have the same size.
 *
 * @param A   The Vector operand.
 * @param t   The scalar operand.
 * @param out The output vector.
 * 
 * @return Success or error code.
 */
CML_Status cml_vector_scale(const CML_Vector *v, f64 t, CML_Vector *out);


/**
 * @brief Computes the modulus of a CML_Vector.
 *
 * @param v The input vector.
 * 
 * @return The modulus of the input vector.
 */
f64 cml_vector_mod(const CML_Vector *v);


/**
 * @brief Normalizes the input CML_Vector and writes it to the out CML_Vector.
 *
 * @param v   The input vector.
 * @param out The output vector.
 * 
 * @return Success or error code.
 */
CML_Status cml_vector_norm(const CML_Vector *v, CML_Vector *out);


/**
 * @brief Computes the dot product of two CML_Vector.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The dot product of the two input vectors.
 */
f64 cml_vector_dot(const CML_Vector *v, const CML_Vector *w);


#endif /* CAMEL_VARIABLE_VECTOR */
