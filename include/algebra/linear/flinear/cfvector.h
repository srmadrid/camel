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

#include "../../../core/macros.h"
#include "../../../core/err.h"
#include "../../../core/constants.h"
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
void cmlc_vector2_add(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out);


/******************************************************************************
 * Function: cmlc_vector2_add_f32
 * 
 * Description:
 *      Adds a scalar to all CML_Vector2 and writes the result to the out
 *      CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 *v   - The first vector operand.
 *      f32          t   - The scalar.
 *      CML_Vector2 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector2_add_f32(const CML_Vector2 *v, f32 t, CML_Vector2 *out);


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
void cmlc_vector2_sub(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out);


/******************************************************************************
 * Function: cmlc_vector2_sub_scalar
 * 
 * Description:
 *      Subtracts a scalar to all CML_Vector2 and writes the result to the out
 *      CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 *v   - The first vector operand.
 *      f32          t   - The scalar.
 *      CML_Vector2 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector2_sub_scalar(const CML_Vector2 *v, f32 t, CML_Vector2 *out);


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
void cmlc_vector2_scale(const CML_Vector2 *v, f32 t, CML_Vector2 *out);


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
f32 cmlc_vector2_mod(const CML_Vector2 *v);


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
f32 cmlc_vector2_mod2(const CML_Vector2 *v);


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
void cmlc_vector2_norm(const CML_Vector2 *v, CML_Vector2 *out);


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
f32 cmlc_vector2_dot(const CML_Vector2 *v, const CML_Vector2 *w);


/******************************************************************************
 * Function: cmlc_vector2_distance
 * 
 * Description:
 *      Calculates the distance between two CML_Vector2s.
 *
 * Parameters:
 *      CML_Vector2 *v   - The first input vector.
 *      CML_Vector2 *w   - The second input vector.
 * 
 * Returns:
 *      The distance between the input vectors.
 *****************************************************************************/
f32 cmlc_vector2_distance(const CML_Vector2 *v, const CML_Vector2 *w);


/******************************************************************************
 * Function: cmlc_vector2_distance2
 * 
 * Description:
 *      Calculates the squared distance between two CML_Vector2s.
 *
 * Parameters:
 *      CML_Vector2 *v   - The first input vector.
 *      CML_Vector2 *w   - The second input vector.
 * 
 * Returns:
 *      The squared distance between the input vectors.
 *****************************************************************************/
f32 cmlc_vector2_distance2(const CML_Vector2 *v, const CML_Vector2 *w);


/******************************************************************************
 * Function: cmlc_vector2_angle
 * 
 * Description:
 *      Calculates the angle between two CML_Vector2s in radians.
 *
 * Parameters:
 *      CML_Vector2 *v   - The first input vector.
 *      CML_Vector2 *w   - The second input vector.
 * 
 * Returns:
 *      The angle between the input vectors in radians.
 *****************************************************************************/
f32 cmlc_vector2_angle(const CML_Vector2 *v, const CML_Vector2 *w);


/******************************************************************************
 * Function: cmlc_vector2_project
 * 
 * Description:
 *      Projects the first CML_Vector2 onto the second CML_Vector2 and writes
 *      the result to the out CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 *v   - The vector operand.
 *      CML_Vector2 *w   - The vector to project onto.
 *      CML_Vector2 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector2_project(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out);


/******************************************************************************
 * Function: cmlc_vector2_reflect
 * 
 * Description:
 *      Reflects the first CML_Vector2 across the second CML_Vector2 and writes
 *      the result to the out CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 *v   - The vector operand.
 *      CML_Vector2 *normal   - The normal of the surface to reflect across.
 *      CML_Vector2 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector2_reflect(const CML_Vector2 *v, const CML_Vector2 *normal, CML_Vector2 *out);


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
CML_Bool cmlc_vector2_eq(const CML_Vector2 *v, const CML_Vector2 *w);


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
char *cmlc_vector2_debug(const CML_Vector2 *expected, const CML_Vector2 *got);



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
void cmlc_vector3_add(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out);


/******************************************************************************
 * Function: cmlc_vector3_add_f32
 * 
 * Description:
 *      Adds a scalar to all CML_Vector3 and writes the result to the out.
 *
 * Parameters:
 *      CML_Vector3 *v   - The first vector operand.
 *      CML_Vector3 *w   - The second vector operand.
 *      CML_Vector3 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector3_add_f32(const CML_Vector3 *v, f32 t, CML_Vector3 *out);


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
void cmlc_vector3_sub(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out);


/******************************************************************************
 * Function: cmlc_vector3_sub_scalar
 * 
 * Description:
 *      Subtracts a scalar to all CML_Vector3 and writes the result to the out.
 *
 * Parameters:
 *      CML_Vector3 *v   - The first vector operand.
 *      f32          t   - The scalar.
 *      CML_Vector3 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector3_sub_scalar(const CML_Vector3 *v, f32 t, CML_Vector3 *out);


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
void cmlc_vector3_scale(const CML_Vector3 *v, f32 t, CML_Vector3 *out);


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
f32 cmlc_vector3_mod(const CML_Vector3 *v);


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
f32 cmlc_vector3_mod2(const CML_Vector3 *v);


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
void cmlc_vector3_norm(const CML_Vector3 *v, CML_Vector3 *out);


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
f32 cmlc_vector3_dot(const CML_Vector3 *v, const CML_Vector3 *w);


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
void cmlc_vector3_cross(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out);


/******************************************************************************
 * Function: cmlc_vector3_distance
 * 
 * Description:
 *      Calculates the distance between two CML_Vector3s.
 *
 * Parameters:
 *      CML_Vector3 *v   - The first input vector.
 *      CML_Vector3 *w   - The second input vector.
 * 
 * Returns:
 *      The distance between the input vectors.
 *****************************************************************************/
f32 cmlc_vector3_distance(const CML_Vector3 *v, const CML_Vector3 *w);


/******************************************************************************
 * Function: cmlc_vector3_distance2
 * 
 * Description:
 *      Calculates the squared distance between two CML_Vector3s.
 *
 * Parameters:
 *      CML_Vector3 *v   - The first input vector.
 *      CML_Vector3 *w   - The second input vector.
 * 
 * Returns:
 *      The squared distance between the input vectors.
 *****************************************************************************/
f32 cmlc_vector3_distance2(const CML_Vector3 *v, const CML_Vector3 *w);


/******************************************************************************
 * Function: cmlc_vector3_angle
 * 
 * Description:
 *      Calculates the angle between two CML_Vector3s in radians.
 *
 * Parameters:
 *      CML_Vector3 *v   - The first input vector.
 *      CML_Vector3 *w   - The second input vector.
 * 
 * Returns:
 *      The angle between the input vectors in radians.
 *****************************************************************************/
f32 cmlc_vector3_angle(const CML_Vector3 *v, const CML_Vector3 *w);


/******************************************************************************
 * Function: cmlc_vector3_project
 * 
 * Description:
 *      Projects the first CML_Vector3 onto the second CML_Vector3 and writes
 *      the result to the out CML_Vector3.
 *
 * Parameters:
 *      CML_Vector3 *v   - The vector operand.
 *      CML_Vector3 *w   - The vector to project onto.
 *      CML_Vector3 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector3_project(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out);


/******************************************************************************
 * Function: cmlc_vector3_reflect
 * 
 * Description:
 *      Reflects the first CML_Vector3 across the surface defined by the normal
 *      CML_Vector3 and writes the result to the out CML_Vector3.
 *
 * Parameters:
 *      CML_Vector3 *v   - The vector operand.
 *      CML_Vector3 *normal   - The normal of the surface to reflect across.
 *      CML_Vector3 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector3_reflect(const CML_Vector3 *v, const CML_Vector3 *normal, CML_Vector3 *out);


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
CML_Bool cmlc_vector3_eq(const CML_Vector3 *v, const CML_Vector3 *w);


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
char *cmlc_vector3_debug(const CML_Vector3 *expected, const CML_Vector3 *got);



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
void cmlc_vector4_add(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out);


/******************************************************************************
 * Function: cmlc_vector4_add_f32
 * 
 * Description:
 *      Adds a scalar to all CML_Vector4 and writes the result to the out
 *
 * Parameters:
 *      CML_Vector4 *v   - The first vector operand.
 *      f32          t   - The scalar.
 *      CML_Vector4 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector4_add_f32(const CML_Vector4 *v, f32 t, CML_Vector4 *out);


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
void cmlc_vector4_sub(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out);


/******************************************************************************
 * Function: cmlc_vector4_sub_scalar
 * 
 * Description:
 *      Subtracts a scalar to all CML_Vector4 and writes the result to the out
 *
 * Parameters:
 *      CML_Vector4 *v   - The first vector operand.
 *      f32          t   - The scalar.
 *      CML_Vector4 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector4_sub_scalar(const CML_Vector4 *v, f32 t, CML_Vector4 *out);


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
void cmlc_vector4_scale(const CML_Vector4 *v, f32 t, CML_Vector4 *out);


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
f32 cmlc_vector4_mod(const CML_Vector4 *v);


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
f32 cmlc_vector4_mod2(const CML_Vector4 *v);


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
void cmlc_vector4_norm(const CML_Vector4 *v, CML_Vector4 *out);


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
f32 cmlc_vector4_dot(const CML_Vector4 *v, const CML_Vector4 *w);


/******************************************************************************
 * Function: cmlc_vector4_distance
 * 
 * Description:
 *      Calculates the distance between two CML_Vector4s.
 *
 * Parameters:
 *      CML_Vector4 *v   - The first input vector.
 *      CML_Vector4 *w   - The second input vector.
 * 
 * Returns:
 *      The distance between the input vectors.
 *****************************************************************************/
f32 cmlc_vector4_distance(const CML_Vector4 *v, const CML_Vector4 *w);


/******************************************************************************
 * Function: cmlc_vector4_distance2
 * 
 * Description:
 *      Calculates the squared distance between two CML_Vector4s.
 *
 * Parameters:
 *      CML_Vector4 *v   - The first input vector.
 *      CML_Vector4 *w   - The second input vector.
 * 
 * Returns:
 *      The squared distance between the input vectors.
 *****************************************************************************/
f32 cmlc_vector4_distance2(const CML_Vector4 *v, const CML_Vector4 *w);


/******************************************************************************
 * Function: cmlc_vector4_angle
 * 
 * Description:
 *      Calculates the angle between two CML_Vector4s in radians.
 *
 * Parameters:
 *      CML_Vector4 *v   - The first input vector.
 *      CML_Vector4 *w   - The second input vector.
 * 
 * Returns:
 *      The angle between the input vectors in radians.
 *****************************************************************************/
f32 cmlc_vector4_angle(const CML_Vector4 *v, const CML_Vector4 *w);


/******************************************************************************
 * Function: cmlc_vector4_project
 * 
 * Description:
 *      Projects the first CML_Vector4 onto the second CML_Vector4 and writes
 *      the result to the out CML_Vector4.
 *
 * Parameters:
 *      CML_Vector4 *v   - The vector operand.
 *      CML_Vector4 *w   - The vector to project onto.
 *      CML_Vector4 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector4_project(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out);


/******************************************************************************
 * Function: cmlc_vector4_reflect
 * 
 * Description:
 *      Reflects the first CML_Vector4 across the surface defined by the normal
 *      CML_Vector4 and writes the result to the out CML_Vector4.
 *
 * Parameters:
 *      CML_Vector4 *v   - The vector operand.
 *      CML_Vector4 *normal   - The normal of the surface to reflect across.
 *      CML_Vector4 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
void cmlc_vector4_reflect(const CML_Vector4 *v, const CML_Vector4 *normal, CML_Vector4 *out);


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
CML_Bool cmlc_vector4_eq(const CML_Vector4 *v, const CML_Vector4 *w);


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
char *cmlc_vector4_debug(const CML_Vector4 *expected, const CML_Vector4 *got);


#endif /* CAMEL_CFIXED_VECTOR */
