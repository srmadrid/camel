/******************************************************************************
 * Filename: cfvector.h
 * 
 * Description:
 *      Declarations for the compiled version of the fixed vector manipulation 
 *      functions of CAMEL.
 * 
 * Author: Sergio Madrid
 * Created on: 25/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/

#ifndef CAMEL_CFIXED_VECTOR
#define CAMEL_CFIXED_VECTOR


#include <stdlib.h>
#include <math.h>

#include "../../../core/core.h"
#include "fvector.h"


/******************************************************************************
 * Function: cmlc_vector2_add
 * 
 * Description:
 *      Adds two CML_Vector2 and writes the result to the out CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 *v   - The first vector operand.
 *      CML_Vector2 *w   - The second vector operand.
 *      CML_Vector2 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
CAMEL_API void cmlc_vector2_add(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out);


/******************************************************************************
 * Function: cmlc_vector2_sub
 * 
 * Description:
 *      Subtracts two CML_Vector2 and writes the result to the out CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 *v   - The first vector operand.
 *      CML_Vector2 *w   - The second vector operand.
 *      CML_Vector2 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
CAMEL_API void cmlc_vector2_sub(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out);


/******************************************************************************
 * Function: cmlc_vector2_scale
 * 
 * Description:
 *      Multiplies a CML_Vector2 by a scalar, and writes the result to the out 
 *      CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 *v   - The vector operand.
 *      double       t   - The scalar.
 *      CML_Vector2 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
CAMEL_API void cmlc_vector2_scale(const CML_Vector2 *v, f64 t, CML_Vector2 *out);


/******************************************************************************
 * Function: cmlc_vector2_mod
 * 
 * Description:
 *      Calculates the modulus of the input CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 *v - The input vector.
 * 
 * Returns:
 *      The modulus of the input CML_Vector2.
 *****************************************************************************/
CAMEL_API f64 cmlc_vector2_mod(const CML_Vector2 *v);


/******************************************************************************
 * Function: cmlc_vector2_mod2
 * 
 * Description:
 *      Calculates the squared modulus of the input CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 *v - The input vector.
 * 
 * Returns:
 *      The squared modulus of the input CML_Vector2.
 *****************************************************************************/
CAMEL_API f64 cmlc_vector2_mod2(const CML_Vector2 *v);


/******************************************************************************
 * Function: cmlc_vector2_norm
 * 
 * Description:
 *      Normalizes the input CML_Vector2 and writes it to the out CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 *v   - The input vector.
 *      CML_Vector2 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
CAMEL_API void cmlc_vector2_norm(const CML_Vector2 *v, CML_Vector2 *out);


/******************************************************************************
 * Function: cmlc_vector2_dot
 * 
 * Description:
 *      Calculates the dot product of the input CML_Vector2s.
 *
 * Parameters:
 *      CML_Vector2 *v   - The first input vector.
 *      CML_Vector2 *w   - The second input vector.
 * 
 * Returns:
 *      The dot product of the input vectors.
 *****************************************************************************/
CAMEL_API f64 cmlc_vector2_dot(const CML_Vector2 *v, const CML_Vector2 *w);


/******************************************************************************
 * Function: cmlc_vector2_eq
 * 
 * Description:
 *      Compares two CML_Vector4s for equality.
 * 
 * Parameters:
 *      CML_Vector2 *v - The first input vector.
 *      CML_Vector2 *w - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CAMEL_API CML_Bool cmlc_vector2_eq(const CML_Vector2 *v, const CML_Vector2 *w);


/******************************************************************************
 * Function: cmlc_vector2_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Vector2s.
 *
 * Parameters:
 *      CML_Vector2 *expected - Expected vector.
 *      CML_Vector2 *got - Result vector.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_API char *cmlc_vector2_debug(const CML_Vector2 *expected, const CML_Vector2 *got);



/******************************************************************************
 * Function: cmlc_vector3_add
 * 
 * Description:
 *      Adds two CML_Vector3 and writes the result to the out CML_Vector3.
 *
 * Parameters:
 *      CML_Vector3 *v   - The first vector operand.
 *      CML_Vector3 *w   - The second vector operand.
 *      CML_Vector3 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
CAMEL_API void cmlc_vector3_add(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out);


/******************************************************************************
 * Function: cmlc_vector3_sub
 * 
 * Description:
 *      Subtracts two CML_Vector3 and writes the result to the out CML_Vector3.
 *
 * Parameters:
 *      CML_Vector3 *v   - The first vector operand.
 *      CML_Vector3 *w   - The second vector operand.
 *      CML_Vector3 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
CAMEL_API void cmlc_vector3_sub(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out);


/******************************************************************************
 * Function: cmlc_vector3_scale
 * 
 * Description:
 *      Multiplies a CML_Vector3 by a scalar, and writes the result to the out 
 *      CML_Vector3.
 *
 * Parameters:
 *      CML_Vector3 *v   - The vector operand.
 *      double       t   - The scalar.
 *      CML_Vector3 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
CAMEL_API void cmlc_vector3_scale(const CML_Vector3 *v, f64 t, CML_Vector3 *out);


/******************************************************************************
 * Function: cmlc_vector3_mod
 * 
 * Description:
 *      Calculates the modulus of the input CML_Vector3.
 *
 * Parameters:
 *      CML_Vector3 *v - The input vector.
 * 
 * Returns:
 *      The modulus of the input CML_Vector3.
 *****************************************************************************/
CAMEL_API f64 cmlc_vector3_mod(const CML_Vector3 *v);


/******************************************************************************
 * Function: cmlc_vector3_mod2
 * 
 * Description:
 *      Calculates the squared modulus of the input CML_Vector3.
 *
 * Parameters:
 *      CML_Vector3 *v - The input vector.
 * 
 * Returns:
 *      The squared modulus of the input CML_Vector3.
 *****************************************************************************/
CAMEL_API f64 cmlc_vector3_mod2(const CML_Vector3 *v);


/******************************************************************************
 * Function: cmlc_vector3_norm
 * 
 * Description:
 *      Normalizes the input CML_Vector3 and writes it to the out CML_Vector3.
 *
 * Parameters:
 *      CML_Vector3 *v   - The input vector.
 *      CML_Vector3 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
CAMEL_API void cmlc_vector3_norm(const CML_Vector3 *v, CML_Vector3 *out);


/******************************************************************************
 * Function: cmlc_vector3_dot
 * 
 * Description:
 *      Calculates the dot product of the input CML_Vector3s.
 *
 * Parameters:
 *      CML_Vector3 *v   - The first input vector.
 *      CML_Vector3 *w   - The second input vector.
 * 
 * Returns:
 *      The dot product of the input vectors.
 *****************************************************************************/
CAMEL_API f64 cmlc_vector3_dot(const CML_Vector3 *v, const CML_Vector3 *w);


/******************************************************************************
 * Function: cmlc_vector3_cross
 * 
 * Description:
 *      Calculates the cross product of the input CML_Vector3s.
 *
 * Parameters:
 *      CML_Vector3 *v   - The first input vector.
 *      CML_Vector3 *w   - The second input vector.
 *      CML_Vector3 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
CAMEL_API void cmlc_vector3_cross(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out);


/******************************************************************************
 * Function: cmlc_vector3_eq
 * 
 * Description:
 *      Compares two CML_Vector4s for equality.
 * 
 * Parameters:
 *      CML_Vector3 *v - The first input vector.
 *      CML_Vector3 *w - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CAMEL_API CML_Bool cmlc_vector3_eq(const CML_Vector3 *v, const CML_Vector3 *w);


/******************************************************************************
 * Function: cmlc_vector3_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Vector3s.
 *
 * Parameters:
 *      CML_Vector3 *expected - Expected vector.
 *      CML_Vector3 *got - Result vector.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_API char *cmlc_vector3_debug(const CML_Vector3 *expected, const CML_Vector3 *got);



/******************************************************************************
 * Function: cmlc_vector4_add
 * 
 * Description:
 *      Adds two CML_Vector4 and writes the result to the out CML_Vector4.
 *
 * Parameters:
 *      CML_Vector4 *v   - The first vector operand.
 *      CML_Vector4 *w   - The second vector operand.
 *      CML_Vector4 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
CAMEL_API void cmlc_vector4_add(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out);


/******************************************************************************
 * Function: cmlc_vector4_sub
 * 
 * Description:
 *      Subtracts two CML_Vector4 and writes the result to the out CML_Vector4.
 *
 * Parameters:
 *      CML_Vector4 *v   - The first vector operand.
 *      CML_Vector4 *w   - The second vector operand.
 *      CML_Vector4 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
CAMEL_API void cmlc_vector4_sub(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out);


/******************************************************************************
 * Function: cmlc_vector4_scale
 * 
 * Description:
 *      Multiplies a CML_Vector4 by a scalar, and writes the result to the out 
 *      CML_Vector4.
 *
 * Parameters:
 *      CML_Vector4 *v   - The vector operand.
 *      double       t   - The scalar.
 *      CML_Vector4 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
CAMEL_API void cmlc_vector4_scale(const CML_Vector4 *v, f64 t, CML_Vector4 *out);


/******************************************************************************
 * Function: cmlc_vector4_mod
 * 
 * Description:
 *      Calculates the modulus of the input CML_Vector4.
 *
 * Parameters:
 *      CML_Vector4 *v - The input vector.
 * 
 * Returns:
 *      The modulus of the input CML_Vector4.
 *****************************************************************************/
CAMEL_API f64 cmlc_vector4_mod(const CML_Vector4 *v);


/******************************************************************************
 * Function: cmlc_vector4_mod2
 * 
 * Description:
 *      Calculates the squared modulus of the input CML_Vector4.
 *
 * Parameters:
 *      CML_Vector4 *v - The input vector.
 * 
 * Returns:
 *      The squared modulus of the input CML_Vector4.
 *****************************************************************************/
CAMEL_API f64 cmlc_vector4_mod2(const CML_Vector4 *v);


/******************************************************************************
 * Function: cmlc_vector4_norm
 * 
 * Description:
 *      Normalizes the input CML_Vector4 and writes it to the out CML_Vector4.
 *
 * Parameters:
 *      CML_Vector4 *v   - The input vector.
 *      CML_Vector4 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
CAMEL_API void cmlc_vector4_norm(const CML_Vector4 *v, CML_Vector4 *out);


/******************************************************************************
 * Function: cmlc_vector4_dot
 * 
 * Description:
 *      Calculates the dot product of the input CML_Vector4s.
 *
 * Parameters:
 *      CML_Vector4 *v   - The first input vector.
 *      CML_Vector4 *w   - The second input vector.
 * 
 * Returns:
 *      The dot product of the input vectors.
 *****************************************************************************/
CAMEL_API f64 cmlc_vector4_dot(const CML_Vector4 *v, const CML_Vector4 *w);


/******************************************************************************
 * Function: cmlc_vector4_eq
 * 
 * Description:
 *      Compares two CML_Vector4s for equality.
 * 
 * Parameters:
 *      CML_Vector4 *v - The first input vector.
 *      CML_Vector4 *w - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CAMEL_API CML_Bool cmlc_vector4_eq(const CML_Vector4 *v, const CML_Vector4 *w);


/******************************************************************************
 * Function: cmlc_vector4_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Vector4s.
 *
 * Parameters:
 *      CML_Vector4 *expected - Expected vector.
 *      CML_Vector4 *got - Result vector.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_API char *cmlc_vector4_debug(const CML_Vector4 *expected, const CML_Vector4 *got);


#endif /* CAMEL_CFIXED_VECTOR */
