/******************************************************************************
 * Filename: fvector.h
 * 
 * Description:
 *      Declarations and implementations for the fixed vector manipulation 
 *      functions of CAMEL.
 * 
 * Notes: 
 *      This module is header only.
 *
 * Author: Sergio Madrid
 * Created on: 7/11/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/

#ifndef CAMEL_FIXED_VECTOR
#define CAMEL_FIXED_VECTOR


#include <stdlib.h>
#include <math.h>

#ifdef CML_USE_SSE
    #include <xmmintrin.h>
    #include <smmintrin.h>
#endif
#ifdef CML_USE_NEON
    #include <arm_neon.h>
#endif

#include "../../../core/macros.h"
#include "../../../core/err.h"
#include "../../../core/constants.h"


/******************************************************************************
 * Type: CML_Vector2
 * 
 * Description:
 *      Represents a 2 dimensional vector.
 *
 * Fields:
 *      f32 x - The x component of the vector.
 *      f32 y - The y component of the vector.
 *****************************************************************************/
typedef union {
    struct {
        f32 x;
        f32 y;
    };
    f32 array[2];
} CML_Vector2;


/******************************************************************************
 * Macro: CML_VECTOR2_ZERO
 * 
 * Description:
 *      Initializes a CML_Vector2 to 0.
 *****************************************************************************/
#define CML_VECTOR2_ZERO {{0.0f, 0.0f}}


/******************************************************************************
 * Macro: CML_VECTOR2_I
 * 
 * Description:
 *      Initializes a CML_Vector2 to the unit vector in the i direction.
 *****************************************************************************/
#define CML_VECTOR2_I {{1.0f, 0.0f}}


/******************************************************************************
 * Macro: CML_VECTOR2_J
 * 
 * Description:
 *      Initializes a CML_Vector2 to the unit vector in the j direction.
 *****************************************************************************/
#define CML_VECTOR2_J {{0.0f, 1.0f}}


/******************************************************************************
 * Macro: CML_VECTOR2_ONE
 * 
 * Description:
 *      Initializes a CML_Vector2 to 1.
 *****************************************************************************/
#define CML_VECTOR2_ONE {{1.0f, 1.0f}}


/******************************************************************************
 * Macro: CML_VECTOR2
 * 
 * Description:
 *      Initializes a CML_Vector2 to the given values.
 *
 * Parameters:
 *      f32 x - The x component of the vector.
 *      f32 y - The y component of the vector.
 *****************************************************************************/
#define CML_VECTOR2(x, y) {{x, y}}



/******************************************************************************
 * Type: CML_Vector3
 * 
 * Description:
 *      Represents a 3 dimensional vector.
 *
 * Fields:
 *      f32 x - The x component of the vector.
 *      f32 y - The y component of the vector.
 *      f32 z - The z component of the vector.
 *****************************************************************************/
typedef union {
    struct {
        f32 x;
        f32 y;
        f32 z;
    };
    f32 array[3];
} CML_Vector3;


/******************************************************************************
 * Macro: CML_VECTOR3_ZERO
 * 
 * Description:
 *      Initializes a CML_Vector3 to 0.
 *****************************************************************************/
#define CML_VECTOR3_ZERO {{0.0f, 0.0f, 0.0f}}


/******************************************************************************
 * Macro: CML_VECTOR3_I
 * 
 * Description:
 *      Initializes a CML_Vector3 to the unit vector in the i direction.
 *****************************************************************************/
#define CML_VECTOR3_I {{1.0f, 0.0f, 0.0f}}


/******************************************************************************
 * Macro: CML_VECTOR3_J
 * 
 * Description:
 *      Initializes a CML_Vector3 to the unit vector in the j direction.
 *****************************************************************************/
#define CML_VECTOR3_J {{0.0f, 1.0f, 0.0f}}


/******************************************************************************
 * Macro: CML_VECTOR3_K
 * 
 * Description:
 *      Initializes a CML_Vector3 to the unit vector in the k direction.
 *****************************************************************************/
#define CML_VECTOR3_K {{0.0f, 0.0f, 1.0f}}


/******************************************************************************
 * Macro: CML_VECTOR3_ONE
 * 
 * Description:
 *      Initializes a CML_Vector3 to 1.
 *****************************************************************************/
#define CML_VECTOR3_ONE {{1.0f, 1.0f, 1.0f}}


/******************************************************************************
 * Macro: CML_VECTOR3
 * 
 * Description:
 *      Initializes a CML_Vector3 to the given values.
 *
 * Parameters:
 *      f32 x - The x component of the vector.
 *      f32 y - The y component of the vector.
 *      f32 z - The z component of the vector.
 *****************************************************************************/
#define CML_VECTOR3(x, y, z) {{x, y, z}}



/******************************************************************************
 * Type: CML_Vector4
 * 
 * Description:
 *      Represents a 4 dimensional vector.
 *
 * Fields:
 *      f32 x - The x component of the vector.
 *      f32 y - The y component of the vector.
 *      f32 z - The z component of the vector.
 *      f32 w - The w component of the vector.
 *****************************************************************************/
typedef union {
    struct {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };
    f32 array[4];

#ifdef CML_USE_SSE
    __m128 sse;
#endif
#ifdef CML_USE_NEON
    float32x4_t neon;
#endif
} CML_Vector4;


/******************************************************************************
 * Macro: CML_VECTOR4_ZERO
 * 
 * Description:
 *      Initializes a CML_Vector4 to 0.
 *****************************************************************************/
#define CML_VECTOR4_ZERO {{0.0f, 0.0f, 0.0f, 0.0f}}


/******************************************************************************
 * Macro: CML_VECTOR4_I
 * 
 * Description:
 *      Initializes a CML_Vector4 to the unit vector in the i direction.
 *****************************************************************************/
#define CML_VECTOR4_I {{1.0f, 0.0f, 0.0f, 0.0f}}


/******************************************************************************
 * Macro: CML_VECTOR4_J
 * 
 * Description:
 *      Initializes a CML_Vector4 to the unit vector in the j direction.
 *****************************************************************************/
#define CML_VECTOR4_J {{0.0f, 1.0f, 0.0f, 0.0f}}


/******************************************************************************
 * Macro: CML_VECTOR4_K
 * 
 * Description:
 *      Initializes a CML_Vector4 to the unit vector in the k direction.
 *****************************************************************************/
#define CML_VECTOR4_K {{0.0f, 0.0f, 1.0f, 0.0f}}


/******************************************************************************
 * Macro: CML_VECTOR4_L
 * 
 * Description:
 *      Initializes a CML_Vector4 to the unit vector in the l direction.
 *****************************************************************************/
#define CML_VECTOR4_L {{0.0f, 0.0f, 0.0f, 1.0f}}


/******************************************************************************
 * Macro: CML_VECTOR4_ONE
 * 
 * Description:
 *      Initializes a CML_Vector4 to 1.
 *****************************************************************************/
#define CML_VECTOR4_ONE {{1.0f, 1.0f, 1.0f, 1.0f}}


/******************************************************************************
 * Macro: CML_VECTOR4
 * 
 * Description:
 *      Initializes a CML_Vector4 to the given values.
 *
 * Parameters:
 *      f32 x - The x component of the vector.
 *      f32 y - The y component of the vector.
 *      f32 z - The z component of the vector.
 *      f32 w - The w component of the vector.
 *****************************************************************************/
#define CML_VECTOR4(x, y, z, w) {{x, y, z, w}}



/******************************************************************************
 * Function: cml_vector2_add
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
CAMEL_STATIC CAMEL_API void cml_vector2_add(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out) {
    out->x = v->x + w->x;
    out->y = v->y + w->y;
}


/******************************************************************************
 * Function: cml_vector2_add_f32
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
CAMEL_STATIC CAMEL_API void cml_vector2_add_f32(const CML_Vector2 *v, f32 t, CML_Vector2 *out) {
    out->x = v->x + t;
    out->y = v->y + t;
}


/******************************************************************************
 * Function: cml_vector2_sub
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
CAMEL_STATIC CAMEL_API void cml_vector2_sub(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out) {
    out->x = v->x - w->x;
    out->y = v->y - w->y;
}


/******************************************************************************
 * Function: cml_vector2_sub_f32
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
CAMEL_STATIC CAMEL_API void cml_vector2_sub_f32(const CML_Vector2 *v, f32 t, CML_Vector2 *out) {
    out->x = v->x - t;
    out->y = v->y - t;
}


/******************************************************************************
 * Function: cml_vector2_scale
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
CAMEL_STATIC CAMEL_API void cml_vector2_scale(const CML_Vector2 *v, f32 t, CML_Vector2 *out) {
    out->x = v->x * t;
    out->y = v->y * t;
}


/******************************************************************************
 * Function: cml_vector2_mod
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
CAMEL_STATIC CAMEL_API f32 cml_vector2_mod(const CML_Vector2 *v) {
    return sqrtf(v->x * v->x + v->y * v->y);
}


/******************************************************************************
 * Function: cml_vector2_mod2
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
CAMEL_STATIC CAMEL_API f32 cml_vector2_mod2(const CML_Vector2 *v) {
    return v->x * v->x + v->y * v->y;
}


/******************************************************************************
 * Function: cml_vector2_norm
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
CAMEL_STATIC CAMEL_API void cml_vector2_norm(const CML_Vector2 *v, CML_Vector2 *out) {
    f32 mod = 1/sqrtf(v->x * v->x + v->y * v->y);
    out->x = v->x * mod;
    out->y = v->y * mod;
}


/******************************************************************************
 * Function: cml_vector2_dot
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
CAMEL_STATIC CAMEL_API f32 cml_vector2_dot(const CML_Vector2 *v, const CML_Vector2 *w) {
    return v->x * w->x + v->y * w->y;
}


/******************************************************************************
 * Function: cml_vector2_distance
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
CAMEL_STATIC CAMEL_API f32 cml_vector2_distance(const CML_Vector2 *v, const CML_Vector2 *w) {
    return sqrtf((v->x - w->x) * (v->x - w->x) + (v->y - w->y) * (v->y - w->y));
}


/******************************************************************************
 * Function: cml_vector2_distance2
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
CAMEL_STATIC CAMEL_API f32 cml_vector2_distance2(const CML_Vector2 *v, const CML_Vector2 *w) {
    return (v->x - w->x) * (v->x - w->x) + (v->y - w->y) * (v->y - w->y);
}


/******************************************************************************
 * Function: cml_vector2_angle
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
CAMEL_STATIC CAMEL_API f32 cml_vector2_angle(const CML_Vector2 *v, const CML_Vector2 *w) {
    return acosf((v->x * w->x + v->y * w->y) / (sqrtf(v->x * v->x + v->y * v->y) * sqrtf(w->x * w->x + w->y * w->y)));
}


/******************************************************************************
 * Function: cml_vector2_project
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
CAMEL_STATIC CAMEL_API void cml_vector2_project(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out) {
    f32 mod = (v->x * w->x + v->y * w->y) / (w->x * w->x + w->y * w->y);
    out->x = mod * w->x;
    out->y = mod * w->y;
}


/******************************************************************************
 * Function: cml_vector2_reflect
 * 
 * Description:
 *      Reflects the first CML_Vector2 across the surface defined by the normal
 *      CML_Vector2 and writes the result to the out CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 *v   - The vector operand.
 *      CML_Vector2 *normal   - The normal of the surface to reflect across.
 *      CML_Vector2 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API void cml_vector2_reflect(const CML_Vector2 *v, const CML_Vector2 *normal, CML_Vector2 *out) {
    f32 mod = 2 * (v->x * normal->x + v->y * normal->y) / (normal->x * normal->x + normal->y * normal->y);
    out->x = v->x - mod * normal->x;
    out->y = v->y - mod * normal->y;
}


/******************************************************************************
 * Function: cml_vector2_eq
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
CAMEL_STATIC CAMEL_API b8 cml_vector2_eq(const CML_Vector2 *v, const CML_Vector2 *w) {
    if (!v || !w) {
        return false;
    }

    return (fabsf(v->x - w->x) <= CML_EPSILON && fabsf(v->y - w->y) <= CML_EPSILON)? true : false;
}


/******************************************************************************
 * Function: cml_vector2_debug
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
CAMEL_STATIC CAMEL_API char *cml_vector2_debug(const CML_Vector2 *expected, const CML_Vector2 *got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debug = (char *)malloc(sizeof(char) * 256);
    if (debug == NULL) {
        return NULL;
    }

    sprintf(debug, "\t\tExpected:\n\t\t\t[%lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf]\n", 
            expected->x, expected->y, got->x, got->y);
    return debug;
}



/******************************************************************************
 * Function: cml_vector3_add
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
CAMEL_STATIC CAMEL_API void cml_vector3_add(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out) {
    out->x = v->x + w->x;
    out->y = v->y + w->y;
    out->z = v->z + w->z;
}


/******************************************************************************
 * Function: cml_vector3_add_f32
 * 
 * Description:
 *      Adds a scalar to all CML_Vector3 and writes the result to the out.
 *
 * Parameters:
 *      CML_Vector3 *v   - The first vector operand.
 *      f32          t   - The scalar.
 *      CML_Vector3 *out - The output vector.
 * 
 * Returns:
 *      void.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API void cml_vector3_add_f32(const CML_Vector3 *v, f32 t, CML_Vector3 *out) {
    out->x = v->x + t;
    out->y = v->y + t;
    out->z = v->z + t;
}


/******************************************************************************
 * Function: cml_vector3_sub
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
CAMEL_STATIC CAMEL_API void cml_vector3_sub(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out) {
    out->x = v->x - w->x;
    out->y = v->y - w->y;
    out->z = v->z - w->z;
}


/******************************************************************************
 * Function: cml_vector3_sub_f32
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
CAMEL_STATIC CAMEL_API void cml_vector3_sub_f32(const CML_Vector3 *v, f32 t, CML_Vector3 *out) {
    out->x = v->x - t;
    out->y = v->y - t;
    out->z = v->z - t;
}


/******************************************************************************
 * Function: cml_vector3_scale
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
CAMEL_STATIC CAMEL_API void cml_vector3_scale(const CML_Vector3 *v, f32 t, CML_Vector3 *out) {
    out->x = v->x * t;
    out->y = v->y * t;
    out->z = v->z * t;
}


/******************************************************************************
 * Function: cml_vector3_mod
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
CAMEL_STATIC CAMEL_API f32 cml_vector3_mod(const CML_Vector3 *v) {
    return sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
}


/******************************************************************************
 * Function: cml_vector3_mod2
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
CAMEL_STATIC CAMEL_API f32 cml_vector3_mod2(const CML_Vector3 *v) {
    return v->x * v->x + v->y * v->y + v->z * v->z;
}


/******************************************************************************
 * Function: cml_vector3_norm
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
CAMEL_STATIC CAMEL_API void cml_vector3_norm(const CML_Vector3 *v, CML_Vector3 *out) {
    f32 mod = 1/sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
    out->x = v->x * mod;
    out->y = v->y * mod;
    out->z = v->z * mod;
}


/******************************************************************************
 * Function: cml_vector3_dot
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
CAMEL_STATIC CAMEL_API f32 cml_vector3_dot(const CML_Vector3 *v, const CML_Vector3 *w) {
    return v->x * w->x + v->y * w->y + v->z * w->z;
}


/******************************************************************************
 * Function: cml_vector3_cross
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
CAMEL_STATIC CAMEL_API void cml_vector3_cross(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out) {
    out->x = v->y * w->z - v->z * w->y;
    out->y = v->z * w->x - v->x * w->z;
    out->z = v->x * w->y - v->y * w->x;
}


/******************************************************************************
 * Function: cml_vector3_distance
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
CAMEL_STATIC CAMEL_API f32 cml_vector3_distance(const CML_Vector3 *v, const CML_Vector3 *w) {
    return sqrtf((v->x - w->x) * (v->x - w->x) + (v->y - w->y) * (v->y - w->y) + (v->z - w->z) * (v->z - w->z));
}


/******************************************************************************
 * Function: cml_vector3_distance2
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
CAMEL_STATIC CAMEL_API f32 cml_vector3_distance2(const CML_Vector3 *v, const CML_Vector3 *w) {
    return (v->x - w->x) * (v->x - w->x) + (v->y - w->y) * (v->y - w->y) + (v->z - w->z) * (v->z - w->z);
}


/******************************************************************************
 * Function: cml_vector3_angle
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
CAMEL_STATIC CAMEL_API f32 cml_vector3_angle(const CML_Vector3 *v, const CML_Vector3 *w) {
    return acosf((v->x * w->x + v->y * w->y + v->z * w->z) / 
                (sqrtf(v->x * v->x + v->y * v->y + v->z * v->z) * 
                 sqrtf(w->x * w->x + w->y * w->y + w->z * w->z)));
}


/******************************************************************************
 * Function: cml_vector3_project
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
CAMEL_STATIC CAMEL_API void cml_vector3_project(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out) {
    f32 mod = (v->x * w->x + v->y * w->y + v->z * w->z) / (w->x * w->x + w->y * w->y + w->z * w->z);
    out->x = mod * w->x;
    out->y = mod * w->y;
    out->z = mod * w->z;
}


/******************************************************************************
 * Function: cml_vector3_reflect
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
CAMEL_STATIC CAMEL_API void cml_vector3_reflect(const CML_Vector3 *v, const CML_Vector3 *normal, CML_Vector3 *out) {
    f32 mod = 2 * (v->x * normal->x + v->y * normal->y + v->z * normal->z) / 
                  (normal->x * normal->x + normal->y * normal->y + normal->z * normal->z);
    out->x = v->x - mod * normal->x;
    out->y = v->y - mod * normal->y;
    out->z = v->z - mod * normal->z;
}


/******************************************************************************
 * Function: cml_vector3_eq
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
CAMEL_STATIC CAMEL_API b8 cml_vector3_eq(const CML_Vector3 *v, const CML_Vector3 *w) {
    if (!v || !w) {
        return false;
    }

    return (fabsf(v->x - w->x) <= CML_EPSILON && fabsf(v->y - w->y) <= CML_EPSILON && fabsf(v->z - w->z) <= CML_EPSILON)? true : false;
}


/******************************************************************************
 * Function: cml_vector3_debug
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
CAMEL_STATIC CAMEL_API char *cml_vector3_debug(const CML_Vector3 *expected, const CML_Vector3 *got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debug = (char *)malloc(sizeof(char) * 256);
    if (debug == NULL) {
        return NULL;
    }

    sprintf(debug, "\t\tExpected:\n\t\t\t[%lf, %lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf, %lf]\n",
            expected->x, expected->y, expected->z, got->x, got->y, got->z);
    return debug;
}



/******************************************************************************
 * Function: cml_vector4_add
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
CAMEL_STATIC CAMEL_API void cml_vector4_add(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out) {
    out->x = v->x + w->x;
    out->y = v->y + w->y;
    out->z = v->z + w->z;
    out->w = v->w + w->w;
}


/******************************************************************************
 * Function: cml_vector4_add_f32
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
CAMEL_STATIC CAMEL_API void cml_vector4_add_f32(const CML_Vector4 *v, f32 t, CML_Vector4 *out) {
    out->x = v->x + t;
    out->y = v->y + t;
    out->z = v->z + t;
    out->w = v->w + t;
}


/******************************************************************************
 * Function: cml_vector4_sub
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
CAMEL_STATIC CAMEL_API void cml_vector4_sub(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out) {
    out->x = v->x - w->x;
    out->y = v->y - w->y;
    out->z = v->z - w->z;
    out->w = v->w - w->w;
}


/******************************************************************************
 * Function: cml_vector4_sub_f32
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
CAMEL_STATIC CAMEL_API void cml_vector4_sub_f32(const CML_Vector4 *v, f32 t, CML_Vector4 *out) {
    out->x = v->x - t;
    out->y = v->y - t;
    out->z = v->z - t;
    out->w = v->w - t;
}


/******************************************************************************
 * Function: cml_vector4_scale
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
CAMEL_STATIC CAMEL_API void cml_vector4_scale(const CML_Vector4 *v, f32 t, CML_Vector4 *out) {
    out->x = v->x * t;
    out->y = v->y * t;
    out->z = v->z * t;
    out->w = v->w * t;
}


/******************************************************************************
 * Function: cml_vector4_mod
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
CAMEL_STATIC CAMEL_API f32 cml_vector4_mod(const CML_Vector4 *v) {
    return sqrtf(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
}


/******************************************************************************
 * Function: cml_vector4_mod2
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
CAMEL_STATIC CAMEL_API f32 cml_vector4_mod2(const CML_Vector4 *v) {
    return v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w;
}


/******************************************************************************
 * Function: cml_vector4_norm
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
CAMEL_STATIC CAMEL_API void cml_vector4_norm(const CML_Vector4 *v, CML_Vector4 *out) {
    f32 mod = 1/sqrtf(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
    out->x = v->x * mod;
    out->y = v->y * mod;
    out->z = v->z * mod;
    out->w = v->w * mod;
}


/******************************************************************************
 * Function: cml_vector4_dot
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
CAMEL_STATIC CAMEL_API f32 cml_vector4_dot(const CML_Vector4 *v, const CML_Vector4 *w) {
    return v->x * w->x + v->y * w->y + v->z * w->z + v->w * w->w;
}


/******************************************************************************
 * Function: cml_vector4_distance
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
CAMEL_STATIC CAMEL_API f32 cml_vector4_distance(const CML_Vector4 *v, const CML_Vector4 *w) {
    return sqrtf((v->x - w->x) * (v->x - w->x) + (v->y - w->y) * (v->y - w->y) + 
                (v->z - w->z) * (v->z - w->z) + (v->w - w->w) * (v->w - w->w));
}


/******************************************************************************
 * Function: cml_vector4_distance2
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
CAMEL_STATIC CAMEL_API f32 cml_vector4_distance2(const CML_Vector4 *v, const CML_Vector4 *w) {
    return (v->x - w->x) * (v->x - w->x) + (v->y - w->y) * (v->y - w->y) + 
           (v->z - w->z) * (v->z - w->z) + (v->w - w->w) * (v->w - w->w);
}


/******************************************************************************
 * Function: cml_vector4_angle
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
CAMEL_STATIC CAMEL_API f32 cml_vector4_angle(const CML_Vector4 *v, const CML_Vector4 *w) {
    return acosf((v->x * w->x + v->y * w->y + v->z * w->z + v->w * w->w) / 
                (sqrtf(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w) * 
                 sqrtf(w->x * w->x + w->y * w->y + w->z * w->z + w->w * w->w)));
}


/******************************************************************************
 * Function: cml_vector4_project
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
CAMEL_STATIC CAMEL_API void cml_vector4_project(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out) {
    f32 mod = (v->x * w->x + v->y * w->y + v->z * w->z + v->w * w->w) / 
              (w->x * w->x + w->y * w->y + w->z * w->z + w->w * w->w);
    out->x = mod * w->x;
    out->y = mod * w->y;
    out->z = mod * w->z;
    out->w = mod * w->w;
}


/******************************************************************************
 * Function: cml_vector4_reflect
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
CAMEL_STATIC CAMEL_API void cml_vector4_reflect(const CML_Vector4 *v, const CML_Vector4 *normal, CML_Vector4 *out) {
    f32 mod = 2 * (v->x * normal->x + v->y * normal->y + v->z * normal->z + v->w * normal->w) / 
                  (normal->x * normal->x + normal->y * normal->y + normal->z * normal->z + normal->w * normal->w);
    out->x = v->x - mod * normal->x;
    out->y = v->y - mod * normal->y;
    out->z = v->z - mod * normal->z;
    out->w = v->w - mod * normal->w;
}


/******************************************************************************
 * Function: cml_vector4_eq
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
CAMEL_STATIC CAMEL_API b8 cml_vector4_eq(const CML_Vector4 *v, const CML_Vector4 *w) {
    if (!v || !w) {
        return false;
    }

    return (fabsf(v->x - w->x) <= CML_EPSILON && fabsf(v->y - w->y) <= CML_EPSILON && 
            fabsf(v->z - w->z) <= CML_EPSILON && fabsf(v->w - w->w) <= CML_EPSILON)? true : false;
}


/******************************************************************************
 * Function: cml_vector4_debug
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
CAMEL_STATIC CAMEL_API char *cml_vector4_debug(const CML_Vector4 *expected, const CML_Vector4 *got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debug = (char *)malloc(sizeof(char) * 256);
    if (debug == NULL) {
        return NULL;
    }

    sprintf(debug, "\t\tExpected:\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf, %lf, %lf]\n", 
            expected->x, expected->y, expected->z, expected->w, got->x, got->y, got->z, got->w);
    return debug;
}


#endif /* CAMEL_FIXED_VECTOR */
