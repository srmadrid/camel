/**
 * @file fvector.h
 * 
 * @brief Declarations and implementations for the fixed vector manipulation 
 *        functions of CAMEL.
 * 
 * @note This module is header only. Vectors are column major.
 *
 * @author Sergio Madrid
 * @date 7/11/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

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


/**
 * @brief Represents a 2 dimensional vector.
 * 
 * @note The vector is stored in column major order.
 */
typedef union CML_Vector2 {
    struct {
        /** @brief The x component of the vector. */
        f32 x;
        /** @brief The y component of the vector. */
        f32 y;
    };
    /** @brief The vector as an array of 2 elements. */
    f32 array[2];
} CML_Vector2;


/**
 * @brief Initializes a CML_Vector2 to the zero vector.
 */
#define CML_VECTOR2_ZERO {{0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Vector2 to the unit vector in the i direction.
 */
#define CML_VECTOR2_I {{1.0f, 0.0f}}


/**
 * @brief Initializes a CML_Vector2 to the unit vector in the j direction.
 */
#define CML_VECTOR2_J {{0.0f, 1.0f}}


/**
 * @brief Initializes a CML_Vector2 to the one vector.
 */
#define CML_VECTOR2_ONE {{1.0f, 1.0f}}


/**
 * @brief Initializes a CML_Vector2 to the given values.
 * 
 * @param x The x component of the vector.
 * @param y The y component of the vector.
 */
#define CML_VECTOR2(x, y) {{x, y}}



/**
 * @brief Represents a 3 dimensional vector.
 * 
 * @note The vector is stored in column major order.
 */
typedef union CML_Vector3 {
    struct {
        /** @brief The x component of the vector. */
        f32 x;
        /** @brief The y component of the vector. */
        f32 y;
        /** @brief The z component of the vector. */
        f32 z;
    };
    /** @brief The vector as an array of 3 elements. */
    f32 array[3];
} CML_Vector3;


/**
 * @brief Initializes a CML_Vector3 to the zero vector.
 */
#define CML_VECTOR3_ZERO {{0.0f, 0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Vector3 to the unit vector in the i direction.
 */
#define CML_VECTOR3_I {{1.0f, 0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Vector3 to the unit vector in the j direction.
 */
#define CML_VECTOR3_J {{0.0f, 1.0f, 0.0f}}


/**
 * @brief Initializes a CML_Vector3 to the unit vector in the k direction.
 */
#define CML_VECTOR3_K {{0.0f, 0.0f, 1.0f}}


/**
 * @brief Initializes a CML_Vector3 to the one vector.
 */
#define CML_VECTOR3_ONE {{1.0f, 1.0f, 1.0f}}


/**
 * @brief Initializes a CML_Vector3 to the given values.
 * 
 * @param x The x component of the vector.
 * @param y The y component of the vector.
 * @param z The z component of the vector.
 */
#define CML_VECTOR3(x, y, z) {{x, y, z}}



/**
 * @brief Represents a 4 dimensional vector.
 * 
 * @note The vector is stored in column major order.
 */
typedef union CML_Vector4 {
    struct {
        /** @brief The x component of the vector. */
        f32 x;
        /** @brief The y component of the vector. */
        f32 y;
        /** @brief The z component of the vector. */
        f32 z;
        /** @brief The w component of the vector. */
        f32 w;
    };
    /** @brief The vector as an array of 4 elements. */
    f32 array[4];

#ifdef CML_USE_SSE
    __m128 sse;
#endif
#ifdef CML_USE_NEON
    float32x4_t neon;
#endif
} CML_Vector4;


/**
 * @brief Initializes a CML_Vector4 to the zero vector.
 */
#define CML_VECTOR4_ZERO {{0.0f, 0.0f, 0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Vector4 to the unit vector in the i direction.
 */
#define CML_VECTOR4_I {{1.0f, 0.0f, 0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Vector4 to the unit vector in the j direction.
 */
#define CML_VECTOR4_J {{0.0f, 1.0f, 0.0f, 0.0f}}


/**
 * @brief Initializes a CML_Vector4 to the unit vector in the k direction.
 */
#define CML_VECTOR4_K {{0.0f, 0.0f, 1.0f, 0.0f}}


/**
 * @brief Initializes a CML_Vector4 to the unit vector in the l direction.
 */
#define CML_VECTOR4_L {{0.0f, 0.0f, 0.0f, 1.0f}}


/**
 * @brief Initializes a CML_Vector4 to the one vector.
 */
#define CML_VECTOR4_ONE {{1.0f, 1.0f, 1.0f, 1.0f}}


/**
 * @brief Initializes a CML_Vector4 to the given values.
 * 
 * @param x The x component of the vector.
 * @param y The y component of the vector.
 * @param z The z component of the vector.
 * @param w The w component of the vector.
 */
#define CML_VECTOR4(x, y, z, w) {{x, y, z, w}}



/**
 * @brief Adds two CML_Vector2 and writes the result to the out CML_Vector2.
 *
 * @param v   The left vector operand.
 * @param w   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_vector2_add(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out) {
    out->x = v->x + w->x;
    out->y = v->y + w->y;
}


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
CAMEL_STATIC CAMEL_API void cml_vector2_add_f32(const CML_Vector2 *v, f32 t, CML_Vector2 *out) {
    out->x = v->x + t;
    out->y = v->y + t;
}


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
CAMEL_STATIC CAMEL_API void cml_vector2_sub(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out) {
    out->x = v->x - w->x;
    out->y = v->y - w->y;
}


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
CAMEL_STATIC CAMEL_API void cml_vector2_sub_f32(const CML_Vector2 *v, f32 t, CML_Vector2 *out) {
    out->x = v->x - t;
    out->y = v->y - t;
}


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
CAMEL_STATIC CAMEL_API void cml_vector2_scale(const CML_Vector2 *v, f32 t, CML_Vector2 *out) {
    out->x = v->x * t;
    out->y = v->y * t;
}


/**
 * @brief Calculates the modulus of the input CML_Vector2.
 *
 * @param v The input vector.
 * 
 * @return The modulus of the input CML_Vector2.
 */
CAMEL_STATIC CAMEL_API f32 cml_vector2_mod(const CML_Vector2 *v) {
    return sqrtf(v->x * v->x + v->y * v->y);
}


/**
 * @brief Calculates the squared modulus of the input CML_Vector2.
 *
 * @param v The input vector.
 * 
 * @return The squared modulus of the input CML_Vector2.
 */
CAMEL_STATIC CAMEL_API f32 cml_vector2_mod2(const CML_Vector2 *v) {
    return v->x * v->x + v->y * v->y;
}


/**
 * @brief Normalizes the input CML_Vector2 and writes it to the out CML_Vector2.
 *
 * @param v   The input vector.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_vector2_norm(const CML_Vector2 *v, CML_Vector2 *out) {
    f32 mod = 1/sqrtf(v->x * v->x + v->y * v->y);
    out->x = v->x * mod;
    out->y = v->y * mod;
}


/**
 * @brief Calculates the dot product of the input CML_Vector2s.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The dot product of the input vectors.
 */
CAMEL_STATIC CAMEL_API f32 cml_vector2_dot(const CML_Vector2 *v, const CML_Vector2 *w) {
    return v->x * w->x + v->y * w->y;
}


/**
 * @brief Calculates the distance between two CML_Vector2s.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The distance between the input vectors.
 */
CAMEL_STATIC CAMEL_API f32 cml_vector2_distance(const CML_Vector2 *v, const CML_Vector2 *w) {
    return sqrtf((v->x - w->x) * (v->x - w->x) + (v->y - w->y) * (v->y - w->y));
}


/**
 * @brief Calculates the squared distance between two CML_Vector2s.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The squared distance between the input vectors.
 */
CAMEL_STATIC CAMEL_API f32 cml_vector2_distance2(const CML_Vector2 *v, const CML_Vector2 *w) {
    return (v->x - w->x) * (v->x - w->x) + (v->y - w->y) * (v->y - w->y);
}


/**
 * @brief Calculates the angle between two CML_Vector2s in radians.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The angle between the input vectors in radians.
 */
CAMEL_STATIC CAMEL_API f32 cml_vector2_angle(const CML_Vector2 *v, const CML_Vector2 *w) {
    return acosf((v->x * w->x + v->y * w->y) / (sqrtf(v->x * v->x + v->y * v->y) * sqrtf(w->x * w->x + w->y * w->y)));
}


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
CAMEL_STATIC CAMEL_API void cml_vector2_project(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out) {
    f32 mod = (v->x * w->x + v->y * w->y) / (w->x * w->x + w->y * w->y);
    out->x = mod * w->x;
    out->y = mod * w->y;
}


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
CAMEL_STATIC CAMEL_API void cml_vector2_reflect(const CML_Vector2 *v, const CML_Vector2 *normal, CML_Vector2 *out) {
    f32 mod = 2 * (v->x * normal->x + v->y * normal->y) / (normal->x * normal->x + normal->y * normal->y);
    out->x = v->x - mod * normal->x;
    out->y = v->y - mod * normal->y;
}


/**
 * @brief Compares two CML_Vector2s for equality.
 * 
 * @param v The left input vector.
 * @param w The right input vector.
 * 
 * @return Boolean value indicating whether the vectors are equal.
 */
CAMEL_STATIC CAMEL_API b8 cml_vector2_eq(const CML_Vector2 *v, const CML_Vector2 *w) {
    if (!v || !w) {
        return false;
    }

    return (fabsf(v->x - w->x) <= CML_EPSILON && fabsf(v->y - w->y) <= CML_EPSILON)? true : false;
}


/**
 * @brief Returns a debug message comparing the input CML_Vector2s.
 *
 * @param expected Expected vector.
 * @param got      Result vector.
 * 
 * @return A string containing the debug message.
 */
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



/**
 * @brief Adds two CML_Vector3 and writes the result to the out CML_Vector3.
 *
 * @param v   The left vector operand.
 * @param w   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_vector3_add(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out) {
    out->x = v->x + w->x;
    out->y = v->y + w->y;
    out->z = v->z + w->z;
}


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
CAMEL_STATIC CAMEL_API void cml_vector3_add_f32(const CML_Vector3 *v, f32 t, CML_Vector3 *out) {
    out->x = v->x + t;
    out->y = v->y + t;
    out->z = v->z + t;
}


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
CAMEL_STATIC CAMEL_API void cml_vector3_sub(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out) {
    out->x = v->x - w->x;
    out->y = v->y - w->y;
    out->z = v->z - w->z;
}


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
CAMEL_STATIC CAMEL_API void cml_vector3_sub_f32(const CML_Vector3 *v, f32 t, CML_Vector3 *out) {
    out->x = v->x - t;
    out->y = v->y - t;
    out->z = v->z - t;
}


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
CAMEL_STATIC CAMEL_API void cml_vector3_scale(const CML_Vector3 *v, f32 t, CML_Vector3 *out) {
    out->x = v->x * t;
    out->y = v->y * t;
    out->z = v->z * t;
}


/**
 * @brief Calculates the modulus of the input CML_Vector3.
 *
 * @param v The input vector.
 * 
 * @return The modulus of the input CML_Vector3.
 */
CAMEL_STATIC CAMEL_API f32 cml_vector3_mod(const CML_Vector3 *v) {
    return sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
}


/**
 * @brief Calculates the squared modulus of the input CML_Vector3.
 *
 * @param v The input vector.
 * 
 * @return The squared modulus of the input CML_Vector3.
 */
CAMEL_STATIC CAMEL_API f32 cml_vector3_mod2(const CML_Vector3 *v) {
    return v->x * v->x + v->y * v->y + v->z * v->z;
}


/**
 * @brief Normalizes the input CML_Vector3 and writes it to the out CML_Vector3.
 *
 * @param v   The input vector.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_vector3_norm(const CML_Vector3 *v, CML_Vector3 *out) {
    f32 mod = 1/sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
    out->x = v->x * mod;
    out->y = v->y * mod;
    out->z = v->z * mod;
}


/**
 * @brief Calculates the dot product of the input CML_Vector3s.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The dot product of the input vectors.
 */
CAMEL_STATIC CAMEL_API f32 cml_vector3_dot(const CML_Vector3 *v, const CML_Vector3 *w) {
    return v->x * w->x + v->y * w->y + v->z * w->z;
}


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
CAMEL_STATIC CAMEL_API void cml_vector3_cross(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out) {
    out->x = v->y * w->z - v->z * w->y;
    out->y = v->z * w->x - v->x * w->z;
    out->z = v->x * w->y - v->y * w->x;
}


/**
 * @brief Calculates the distance between two CML_Vector3s.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The distance between the input vectors.
 */
CAMEL_STATIC CAMEL_API f32 cml_vector3_distance(const CML_Vector3 *v, const CML_Vector3 *w) {
    return sqrtf((v->x - w->x) * (v->x - w->x) + (v->y - w->y) * (v->y - w->y) + (v->z - w->z) * (v->z - w->z));
}


/**
 * @brief Calculates the squared distance between two CML_Vector3s.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The squared distance between the input vectors.
 */
CAMEL_STATIC CAMEL_API f32 cml_vector3_distance2(const CML_Vector3 *v, const CML_Vector3 *w) {
    return (v->x - w->x) * (v->x - w->x) + (v->y - w->y) * (v->y - w->y) + (v->z - w->z) * (v->z - w->z);
}


/**
 * @brief Calculates the angle between two CML_Vector3s in radians.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The angle between the input vectors in radians.
 */
CAMEL_STATIC CAMEL_API f32 cml_vector3_angle(const CML_Vector3 *v, const CML_Vector3 *w) {
    return acosf((v->x * w->x + v->y * w->y + v->z * w->z) / 
                (sqrtf(v->x * v->x + v->y * v->y + v->z * v->z) * 
                 sqrtf(w->x * w->x + w->y * w->y + w->z * w->z)));
}


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
CAMEL_STATIC CAMEL_API void cml_vector3_project(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out) {
    f32 mod = (v->x * w->x + v->y * w->y + v->z * w->z) / (w->x * w->x + w->y * w->y + w->z * w->z);
    out->x = mod * w->x;
    out->y = mod * w->y;
    out->z = mod * w->z;
}


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
CAMEL_STATIC CAMEL_API void cml_vector3_reflect(const CML_Vector3 *v, const CML_Vector3 *normal, CML_Vector3 *out) {
    f32 mod = 2 * (v->x * normal->x + v->y * normal->y + v->z * normal->z) / 
                  (normal->x * normal->x + normal->y * normal->y + normal->z * normal->z);
    out->x = v->x - mod * normal->x;
    out->y = v->y - mod * normal->y;
    out->z = v->z - mod * normal->z;
}


/**
 * @brief Compares two CML_Vector3s for equality.
 * 
 * @param v The left input vector.
 * @param w The right input vector.
 * 
 * @return Boolean value indicating whether the vectors are equal.
 */
CAMEL_STATIC CAMEL_API b8 cml_vector3_eq(const CML_Vector3 *v, const CML_Vector3 *w) {
    if (!v || !w) {
        return false;
    }

    return (fabsf(v->x - w->x) <= CML_EPSILON && fabsf(v->y - w->y) <= CML_EPSILON && fabsf(v->z - w->z) <= CML_EPSILON)? true : false;
}


/**
 * @brief Returns a debug message comparing the input CML_Vector3s.
 *
 * @param expected Expected vector.
 * @param got      Result vector.
 * 
 * @return A string containing the debug message.
 */
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



/**
 * @brief Adds two CML_Vector4 and writes the result to the out CML_Vector4.
 *
 * @param v   The left vector operand.
 * @param w   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_vector4_add(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out) {
    out->x = v->x + w->x;
    out->y = v->y + w->y;
    out->z = v->z + w->z;
    out->w = v->w + w->w;
}


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
CAMEL_STATIC CAMEL_API void cml_vector4_add_f32(const CML_Vector4 *v, f32 t, CML_Vector4 *out) {
    out->x = v->x + t;
    out->y = v->y + t;
    out->z = v->z + t;
    out->w = v->w + t;
}


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
CAMEL_STATIC CAMEL_API void cml_vector4_sub(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out) {
    out->x = v->x - w->x;
    out->y = v->y - w->y;
    out->z = v->z - w->z;
    out->w = v->w - w->w;
}


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
CAMEL_STATIC CAMEL_API void cml_vector4_sub_f32(const CML_Vector4 *v, f32 t, CML_Vector4 *out) {
    out->x = v->x - t;
    out->y = v->y - t;
    out->z = v->z - t;
    out->w = v->w - t;
}


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
CAMEL_STATIC CAMEL_API void cml_vector4_scale(const CML_Vector4 *v, f32 t, CML_Vector4 *out) {
    out->x = v->x * t;
    out->y = v->y * t;
    out->z = v->z * t;
    out->w = v->w * t;
}


/**
 * @brief Calculates the modulus of the input CML_Vector4.
 *
 * @param v The input vector.
 * 
 * @return The modulus of the input CML_Vector4.
 */
CAMEL_STATIC CAMEL_API f32 cml_vector4_mod(const CML_Vector4 *v) {
    return sqrtf(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
}


/**
 * @brief Calculates the squared modulus of the input CML_Vector4.
 *
 * @param v The input vector.
 * 
 * @return The squared modulus of the input CML_Vector4.
 */
CAMEL_STATIC CAMEL_API f32 cml_vector4_mod2(const CML_Vector4 *v) {
    return v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w;
}


/**
 * @brief Normalizes the input CML_Vector4 and writes it to the out CML_Vector4.
 *
 * @param v   The input vector.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_vector4_norm(const CML_Vector4 *v, CML_Vector4 *out) {
    f32 mod = 1/sqrtf(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
    out->x = v->x * mod;
    out->y = v->y * mod;
    out->z = v->z * mod;
    out->w = v->w * mod;
}


/**
 * @brief Calculates the dot product of the input CML_Vector4s.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The dot product of the input vectors.
 */
CAMEL_STATIC CAMEL_API f32 cml_vector4_dot(const CML_Vector4 *v, const CML_Vector4 *w) {
    return v->x * w->x + v->y * w->y + v->z * w->z + v->w * w->w;
}


/**
 * @brief Calculates the distance between two CML_Vector4s.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The distance between the input vectors.
 */
CAMEL_STATIC CAMEL_API f32 cml_vector4_distance(const CML_Vector4 *v, const CML_Vector4 *w) {
    return sqrtf((v->x - w->x) * (v->x - w->x) + (v->y - w->y) * (v->y - w->y) + 
                (v->z - w->z) * (v->z - w->z) + (v->w - w->w) * (v->w - w->w));
}


/**
 * @brief Calculates the squared distance between two CML_Vector4s.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The squared distance between the input vectors.
 */
CAMEL_STATIC CAMEL_API f32 cml_vector4_distance2(const CML_Vector4 *v, const CML_Vector4 *w) {
    return (v->x - w->x) * (v->x - w->x) + (v->y - w->y) * (v->y - w->y) + 
           (v->z - w->z) * (v->z - w->z) + (v->w - w->w) * (v->w - w->w);
}


/**
 * @brief Calculates the angle between two CML_Vector4s in radians.
 *
 * @param v The left vector operand.
 * @param w The right vector operand.
 * 
 * @return The angle between the input vectors in radians.
 */
CAMEL_STATIC CAMEL_API f32 cml_vector4_angle(const CML_Vector4 *v, const CML_Vector4 *w) {
    return acosf((v->x * w->x + v->y * w->y + v->z * w->z + v->w * w->w) / 
                (sqrtf(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w) * 
                 sqrtf(w->x * w->x + w->y * w->y + w->z * w->z + w->w * w->w)));
}


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
CAMEL_STATIC CAMEL_API void cml_vector4_project(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out) {
    f32 mod = (v->x * w->x + v->y * w->y + v->z * w->z + v->w * w->w) / 
              (w->x * w->x + w->y * w->y + w->z * w->z + w->w * w->w);
    out->x = mod * w->x;
    out->y = mod * w->y;
    out->z = mod * w->z;
    out->w = mod * w->w;
}


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
CAMEL_STATIC CAMEL_API void cml_vector4_reflect(const CML_Vector4 *v, const CML_Vector4 *normal, CML_Vector4 *out) {
    f32 mod = 2 * (v->x * normal->x + v->y * normal->y + v->z * normal->z + v->w * normal->w) / 
                  (normal->x * normal->x + normal->y * normal->y + normal->z * normal->z + normal->w * normal->w);
    out->x = v->x - mod * normal->x;
    out->y = v->y - mod * normal->y;
    out->z = v->z - mod * normal->z;
    out->w = v->w - mod * normal->w;
}


/**
 * @brief Compares two CML_Vector4s for equality.
 * 
 * @param v The left input vector.
 * @param w The right input vector.
 * 
 * @return Boolean value indicating whether the vectors are equal.
 */
CAMEL_STATIC CAMEL_API b8 cml_vector4_eq(const CML_Vector4 *v, const CML_Vector4 *w) {
    if (!v || !w) {
        return false;
    }

    return (fabsf(v->x - w->x) <= CML_EPSILON && fabsf(v->y - w->y) <= CML_EPSILON && 
            fabsf(v->z - w->z) <= CML_EPSILON && fabsf(v->w - w->w) <= CML_EPSILON)? true : false;
}


/**
 * @brief Returns a debug message comparing the input CML_Vector4s.
 *
 * @param expected Expected vector.
 * @param got      Result vector.
 * 
 * @return A string containing the debug message.
 */
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
