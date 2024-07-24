/**
 * @file cfvector.h
 * 
 * @brief Declarations for the compiled version of the fixed vector manipulation 
 *        functions of CAMEL.
 * 
 * @author Sergio Madrid
 * @date 25/12/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_CFIXED_VECTOR
#define CAMEL_CFIXED_VECTOR


#include <stdlib.h>
#include <math.h>

#include "../../../core/macros.h"
#include "../../../core/err.h"
#include "../../../core/constants.h"
#include "fvector.h"


/**
 * @brief Adds two CML_Vector2 and writes the result to the out CML_Vector2.
 *
 * @param v   The left vector operand.
 * @param w   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector2_add(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out);


/**
 * @brief Adds a scalar to all CML_Vector2 and writes the result to the out
 *        CML_Vector2.
 *
 * @param v   The vector operand.
 * @param t   The scalar.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector2_add_f32(const CML_Vector2 *v, f32 t, CML_Vector2 *out);


/**
 * @brief Subtracts two CML_Vector2 and writes the result to the out 
 *        CML_Vector2.
 *
 * @param v   The left vector operand.
 * @param w   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector2_sub(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out);


/**
 * @brief Subtracts a scalar to all CML_Vector2 and writes the result to the out
 *        CML_Vector2.
 *
 * @param v   The vector operand.
 * @param t   The scalar.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector2_sub_f32(const CML_Vector2 *v, f32 t, CML_Vector2 *out);


/**
 * @brief Multiplies a CML_Vector2 by a scalar, and writes the result to the out 
 *        CML_Vector2.
 *
 * @param v   The vector operand.
 * @param t   The scalar.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector2_scale(const CML_Vector2 *v, f32 t, CML_Vector2 *out);


/**
 * @brief Calculates the modulus of the input CML_Vector2.
 *
 * @param v The input vector.
 * 
 * @return The modulus of the input CML_Vector2.
 */
f32 cmlc_vector2_mod(const CML_Vector2 *v);


/**
 * @brief Calculates the squared modulus of the input CML_Vector2.
 *
 * @param v The input vector.
 * 
 * @return The squared modulus of the input CML_Vector2.
 */
f32 cmlc_vector2_mod2(const CML_Vector2 *v);


/**
 * @brief Normalizes the input CML_Vector2 and writes it to the out CML_Vector2.
 *
 * @param v   The input vector.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector2_norm(const CML_Vector2 *v, CML_Vector2 *out);


/**
 * @brief Calculates the dot product of the input CML_Vector2s.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The dot product of the input vectors.
 */
f32 cmlc_vector2_dot(const CML_Vector2 *v, const CML_Vector2 *w);


/**
 * @brief Calculates the distance between two CML_Vector2s.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The distance between the input vectors.
 */
f32 cmlc_vector2_distance(const CML_Vector2 *v, const CML_Vector2 *w);


/**
 * @brief Calculates the squared distance between two CML_Vector2s.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The squared distance between the input vectors.
 */
f32 cmlc_vector2_distance2(const CML_Vector2 *v, const CML_Vector2 *w);


/**
 * @brief Calculates the angle between two CML_Vector2s in radians.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The angle between the input vectors in radians.
 */
f32 cmlc_vector2_angle(const CML_Vector2 *v, const CML_Vector2 *w);


/**
 * @brief Projects the first CML_Vector2 onto the second CML_Vector2 and writes
 *        the result to the out CML_Vector2.
 *
 * @param v   The vector operand.
 * @param w   The vector to project onto.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector2_project(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out);


/**
 * @brief Reflects the first CML_Vector2 across the surface defined by the 
 *        normal CML_Vector2 and writes the result to the out CML_Vector2.
 *
 * @param v      The vector operand.
 * @param normal The normal of the surface to reflect across.
 * @param out    The output vector.
 * 
 * @return void.
 */
void cmlc_vector2_reflect(const CML_Vector2 *v, const CML_Vector2 *normal, CML_Vector2 *out);


/**
 * @brief Compares two CML_Vector2s for equality.
 * 
 * @param v The left input vector.
 * @param w The right input vector.
 * 
 * @return Boolean value indicating whether the vectors are equal.
 */
b8 cmlc_vector2_eq(const CML_Vector2 *v, const CML_Vector2 *w);


/**
 * @brief Returns a debug message comparing the input CML_Vector2s.
 *
 * @param expected Expected vector.
 * @param got      Result vector.
 * 
 * @return A string containing the debug message.
 */
char *cmlc_vector2_debug(const CML_Vector2 *expected, const CML_Vector2 *got);



/**
 * @brief Adds two CML_Vector3 and writes the result to the out CML_Vector3.
 *
 * @param v   The left vector operand.
 * @param w   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector3_add(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out);


/**
 * @brief Adds a scalar to all CML_Vector3 and writes the result to the out
 *        CML_Vector3.
 *
 * @param v   The vector operand.
 * @param t   The scalar.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector3_add_f32(const CML_Vector3 *v, f32 t, CML_Vector3 *out);


/**
 * @brief Subtracts two CML_Vector3 and writes the result to the out 
 *        CML_Vector3.
 *
 * @param v   The left vector operand.
 * @param w   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector3_sub(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out);


/**
 * @brief Subtracts a scalar to all CML_Vector3 and writes the result to the out
 *        CML_Vector3.
 *
 * @param v   The vector operand.
 * @param t   The scalar.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector3_sub_f32(const CML_Vector3 *v, f32 t, CML_Vector3 *out);


/**
 * @brief Multiplies a CML_Vector3 by a scalar, and writes the result to the out 
 *        CML_Vector3.
 *
 * @param v   The vector operand.
 * @param t   The scalar.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector3_scale(const CML_Vector3 *v, f32 t, CML_Vector3 *out);


/**
 * @brief Calculates the modulus of the input CML_Vector3.
 *
 * @param v The input vector.
 * 
 * @return The modulus of the input CML_Vector3.
 */
f32 cmlc_vector3_mod(const CML_Vector3 *v);


/**
 * @brief Calculates the squared modulus of the input CML_Vector3.
 *
 * @param v The input vector.
 * 
 * @return The squared modulus of the input CML_Vector3.
 */
f32 cmlc_vector3_mod2(const CML_Vector3 *v);


/**
 * @brief Normalizes the input CML_Vector3 and writes it to the out CML_Vector3.
 *
 * @param v   The input vector.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector3_norm(const CML_Vector3 *v, CML_Vector3 *out);


/**
 * @brief Calculates the dot product of the input CML_Vector3s.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The dot product of the input vectors.
 */
f32 cmlc_vector3_dot(const CML_Vector3 *v, const CML_Vector3 *w);


/**
 * @brief Calculates the cross product of the input CML_Vector3s and writes the
 *        result to the out CML_Vector3.
 *
 * @param v   The left vector operand.
 * @param w   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector3_cross(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out);


/**
 * @brief Calculates the distance between two CML_Vector3s.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The distance between the input vectors.
 */
f32 cmlc_vector3_distance(const CML_Vector3 *v, const CML_Vector3 *w);


/**
 * @brief Calculates the squared distance between two CML_Vector3s.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The squared distance between the input vectors.
 */
f32 cmlc_vector3_distance2(const CML_Vector3 *v, const CML_Vector3 *w);


/**
 * @brief Calculates the angle between two CML_Vector3s in radians.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The angle between the input vectors in radians.
 */
f32 cmlc_vector3_angle(const CML_Vector3 *v, const CML_Vector3 *w);


/**
 * @brief Projects the first CML_Vector3 onto the second CML_Vector3 and writes
 *        the result to the out CML_Vector3.
 *
 * @param v   The vector operand.
 * @param w   The vector to project onto.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector3_project(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out);


/**
 * @brief Reflects the first CML_Vector3 across the surface defined by the 
 *        normal CML_Vector3 and writes the result to the out CML_Vector3.
 *
 * @param v      The vector operand.
 * @param normal The normal of the surface to reflect across.
 * @param out    The output vector.
 * 
 * @return void.
 */
void cmlc_vector3_reflect(const CML_Vector3 *v, const CML_Vector3 *normal, CML_Vector3 *out);


/**
 * @brief Compares two CML_Vector3s for equality.
 * 
 * @param v The left input vector.
 * @param w The right input vector.
 * 
 * @return Boolean value indicating whether the vectors are equal.
 */
b8 cmlc_vector3_eq(const CML_Vector3 *v, const CML_Vector3 *w);


/**
 * @brief Returns a debug message comparing the input CML_Vector3s.
 *
 * @param expected Expected vector.
 * @param got      Result vector.
 * 
 * @return A string containing the debug message.
 */
char *cmlc_vector3_debug(const CML_Vector3 *expected, const CML_Vector3 *got);



/**
 * @brief Adds two CML_Vector4 and writes the result to the out CML_Vector4.
 *
 * @param v   The left vector operand.
 * @param w   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector4_add(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out);


/**
 * @brief Adds a scalar to all CML_Vector4 and writes the result to the out
 *        CML_Vector4.
 *
 * @param v   The vector operand.
 * @param t   The scalar.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector4_add_f32(const CML_Vector4 *v, f32 t, CML_Vector4 *out);


/**
 * @brief Subtracts two CML_Vector4 and writes the result to the out 
 *        CML_Vector4.
 *
 * @param v   The left vector operand.
 * @param w   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector4_sub(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out);


/**
 * @brief Subtracts a scalar to all CML_Vector4 and writes the result to the out
 *        CML_Vector4.
 *
 * @param v   The vector operand.
 * @param t   The scalar.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector4_sub_f32(const CML_Vector4 *v, f32 t, CML_Vector4 *out);


/**
 * @brief Multiplies a CML_Vector4 by a scalar, and writes the result to the out 
 *        CML_Vector4.
 *
 * @param v   The vector operand.
 * @param t   The scalar.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector4_scale(const CML_Vector4 *v, f32 t, CML_Vector4 *out);


/**
 * @brief Calculates the modulus of the input CML_Vector4.
 *
 * @param v The input vector.
 * 
 * @return The modulus of the input CML_Vector4.
 */
f32 cmlc_vector4_mod(const CML_Vector4 *v);


/**
 * @brief Calculates the squared modulus of the input CML_Vector4.
 *
 * @param v The input vector.
 * 
 * @return The squared modulus of the input CML_Vector4.
 */
f32 cmlc_vector4_mod2(const CML_Vector4 *v);


/**
 * @brief Normalizes the input CML_Vector4 and writes it to the out CML_Vector4.
 *
 * @param v   The input vector.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector4_norm(const CML_Vector4 *v, CML_Vector4 *out);


/**
 * @brief Calculates the dot product of the input CML_Vector4s.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The dot product of the input vectors.
 */
f32 cmlc_vector4_dot(const CML_Vector4 *v, const CML_Vector4 *w);


/**
 * @brief Calculates the distance between two CML_Vector4s.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The distance between the input vectors.
 */
f32 cmlc_vector4_distance(const CML_Vector4 *v, const CML_Vector4 *w);


/**
 * @brief Calculates the squared distance between two CML_Vector4s.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The squared distance between the input vectors.
 */
f32 cmlc_vector4_distance2(const CML_Vector4 *v, const CML_Vector4 *w);


/**
 * @brief Calculates the angle between two CML_Vector4s in radians.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The angle between the input vectors in radians.
 */
f32 cmlc_vector4_angle(const CML_Vector4 *v, const CML_Vector4 *w);


/**
 * @brief Projects the first CML_Vector4 onto the second CML_Vector4 and writes
 *        the result to the out CML_Vector4.
 *
 * @param v   The vector operand.
 * @param w   The vector to project onto.
 * @param out The output vector.
 * 
 * @return void.
 */
void cmlc_vector4_project(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out);


/**
 * @brief Reflects the first CML_Vector4 across the surface defined by the 
 *        normal CML_Vector4 and writes the result to the out CML_Vector4.
 *
 * @param v      The vector operand.
 * @param normal The normal of the surface to reflect across.
 * @param out    The output vector.
 * 
 * @return void.
 */
void cmlc_vector4_reflect(const CML_Vector4 *v, const CML_Vector4 *normal, CML_Vector4 *out);


/**
 * @brief Compares two CML_Vector4s for equality.
 * 
 * @param v The left input vector.
 * @param w The right input vector.
 * 
 * @return Boolean value indicating whether the vectors are equal.
 */
b8 cmlc_vector4_eq(const CML_Vector4 *v, const CML_Vector4 *w);


/**
 * @brief Returns a debug message comparing the input CML_Vector4s.
 *
 * @param expected Expected vector.
 * @param got      Result vector.
 * 
 * @return A string containing the debug message.
 */
char *cmlc_vector4_debug(const CML_Vector4 *expected, const CML_Vector4 *got);


#endif /* CAMEL_CFIXED_VECTOR */
