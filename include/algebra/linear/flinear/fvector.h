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

#include "../../../core/core.h"


/******************************************************************************
 * Type: CML_Vector2
 * 
 * Description:
 *      Represents a 2 dimensional vector.
 *
 * Fields:
 *      f64 x - The x component of the vector.
 *      f64 y - The y component of the vector.
 *****************************************************************************/
typedef union {
    struct {
        f64 x;
        f64 y;
    };
    f64 array[2];
} CML_Vector2;


/******************************************************************************
 * Macro: CML_VECTOR2_ZERO
 * 
 * Description:
 *      Initializes a CML_Vector2 to 0.
 *****************************************************************************/
#define CML_VECTOR2_ZERO {0.0, 0.0}


/******************************************************************************
 * Macro: CML_VECTOR2_I
 * 
 * Description:
 *      Initializes a CML_Vector2 to the unit vector in the i direction.
 *****************************************************************************/
#define CML_VECTOR2_I {1.0, 0.0}


/******************************************************************************
 * Macro: CML_VECTOR2_J
 * 
 * Description:
 *      Initializes a CML_Vector2 to the unit vector in the j direction.
 *****************************************************************************/
#define CML_VECTOR2_J {0.0, 1.0}


/******************************************************************************
 * Macro: CML_VECTOR2_ONE
 * 
 * Description:
 *      Initializes a CML_Vector2 to 1.
 *****************************************************************************/
#define CML_VECTOR2_ONE {1.0, 1.0}



/******************************************************************************
 * Type: CML_Vector3
 * 
 * Description:
 *      Represents a 3 dimensional vector.
 *
 * Fields:
 *      f64 x - The x component of the vector.
 *      f64 y - The y component of the vector.
 *      f64 z - The z component of the vector.
 *****************************************************************************/
typedef union {
    struct {
        f64 x;
        f64 y;
        f64 z;
    };
    f64 array[3];
} CML_Vector3;


/******************************************************************************
 * Macro: CML_VECTOR3_ZERO
 * 
 * Description:
 *      Initializes a CML_Vector3 to 0.
 *****************************************************************************/
#define CML_VECTOR3_ZERO {0.0, 0.0, 0.0}


/******************************************************************************
 * Macro: CML_VECTOR3_I
 * 
 * Description:
 *      Initializes a CML_Vector3 to the unit vector in the i direction.
 *****************************************************************************/
#define CML_VECTOR3_I {1.0, 0.0, 0.0}


/******************************************************************************
 * Macro: CML_VECTOR3_J
 * 
 * Description:
 *      Initializes a CML_Vector3 to the unit vector in the j direction.
 *****************************************************************************/
#define CML_VECTOR3_J {0.0, 1.0, 0.0}


/******************************************************************************
 * Macro: CML_VECTOR3_K
 * 
 * Description:
 *      Initializes a CML_Vector3 to the unit vector in the k direction.
 *****************************************************************************/
#define CML_VECTOR3_K {0.0, 0.0, 1.0}


/******************************************************************************
 * Macro: CML_VECTOR3_ONE
 * 
 * Description:
 *      Initializes a CML_Vector3 to 1.
 *****************************************************************************/
#define CML_VECTOR3_ONE {1.0, 1.0, 1.0}



/******************************************************************************
 * Type: CML_Vector4
 * 
 * Description:
 *      Represents a 4 dimensional vector.
 *
 * Fields:
 *      f64 x - The x component of the vector.
 *      f64 y - The y component of the vector.
 *      f64 z - The z component of the vector.
 *      f64 w - The w component of the vector.
 *****************************************************************************/
typedef union {
    struct {
        f64 x;
        f64 y;
        f64 z;
        f64 w;
    };
    f64 array[4];
} CML_Vector4;


/******************************************************************************
 * Macro: CML_VECTOR4_ZERO
 * 
 * Description:
 *      Initializes a CML_Vector4 to 0.
 *****************************************************************************/
#define CML_VECTOR4_ZERO {0.0, 0.0, 0.0, 0.0}


/******************************************************************************
 * Macro: CML_VECTOR4_I
 * 
 * Description:
 *      Initializes a CML_Vector4 to the unit vector in the i direction.
 *****************************************************************************/
#define CML_VECTOR4_I {1.0, 0.0, 0.0, 0.0}


/******************************************************************************
 * Macro: CML_VECTOR4_J
 * 
 * Description:
 *      Initializes a CML_Vector4 to the unit vector in the j direction.
 *****************************************************************************/
#define CML_VECTOR4_J {0.0, 1.0, 0.0, 0.0}


/******************************************************************************
 * Macro: CML_VECTOR4_K
 * 
 * Description:
 *      Initializes a CML_Vector4 to the unit vector in the k direction.
 *****************************************************************************/
#define CML_VECTOR4_K {0.0, 0.0, 1.0, 0.0}


/******************************************************************************
 * Macro: CML_VECTOR4_L
 * 
 * Description:
 *      Initializes a CML_Vector4 to the unit vector in the l direction.
 *****************************************************************************/
#define CML_VECTOR4_L {0.0, 0.0, 0.0, 1.0}


/******************************************************************************
 * Macro: CML_VECTOR4_ONE
 * 
 * Description:
 *      Initializes a CML_Vector4 to 1.
 *****************************************************************************/
#define CML_VECTOR4_ONE {1.0, 1.0, 1.0, 1.0}



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
CAMEL_STATIC CAMEL_API void cml_vector2_scale(const CML_Vector2 *v, f64 t, CML_Vector2 *out) {
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
CAMEL_STATIC CAMEL_API f64 cml_vector2_mod(const CML_Vector2 *v) {
    return sqrt(v->x * v->x + v->y * v->y);
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
CAMEL_STATIC CAMEL_API f64 cml_vector2_mod2(const CML_Vector2 *v) {
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
    f64 mod = 1/sqrt(v->x * v->x + v->y * v->y);
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
CAMEL_STATIC CAMEL_API f64 cml_vector2_dot(const CML_Vector2 *v, const CML_Vector2 *w) {
    return v->x * w->x + v->y * w->y;
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
CAMEL_STATIC CAMEL_API CML_Bool cml_vector2_eq(const CML_Vector2 *v, const CML_Vector2 *w) {
    if (!v || !w) {
        return CML_FALSE;
    }

    return (fabs(v->x - w->x) <= CML_EPSILON && fabs(v->y - w->y) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
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
CAMEL_STATIC CAMEL_API void cml_vector3_scale(const CML_Vector3 *v, f64 t, CML_Vector3 *out) {
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
CAMEL_STATIC CAMEL_API f64 cml_vector3_mod(const CML_Vector3 *v) {
    return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
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
CAMEL_STATIC CAMEL_API f64 cml_vector3_mod2(const CML_Vector3 *v) {
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
    f64 mod = 1/sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
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
CAMEL_STATIC CAMEL_API f64 cml_vector3_dot(const CML_Vector3 *v, const CML_Vector3 *w) {
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
CAMEL_STATIC CAMEL_API CML_Bool cml_vector3_eq(const CML_Vector3 *v, const CML_Vector3 *w) {
    if (!v || !w) {
        return CML_FALSE;
    }

    return (fabs(v->x - w->x) <= CML_EPSILON && fabs(v->y - w->y) <= CML_EPSILON && fabs(v->z - w->z) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
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
CAMEL_STATIC CAMEL_API void cml_vector4_scale(const CML_Vector4 *v, f64 t, CML_Vector4 *out) {
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
CAMEL_STATIC CAMEL_API f64 cml_vector4_mod(const CML_Vector4 *v) {
    return sqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
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
CAMEL_STATIC CAMEL_API f64 cml_vector4_mod2(const CML_Vector4 *v) {
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
    f64 mod = 1/sqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
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
CAMEL_STATIC CAMEL_API f64 cml_vector4_dot(const CML_Vector4 *v, const CML_Vector4 *w) {
    return v->x * w->x + v->y * w->y + v->z * w->z + v->w * w->w;
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
CAMEL_STATIC CAMEL_API CML_Bool cml_vector4_eq(const CML_Vector4 *v, const CML_Vector4 *w) {
    if (!v || !w) {
        return CML_FALSE;
    }

    return (fabs(v->x - w->x) <= CML_EPSILON && fabs(v->y - w->y) <= CML_EPSILON && 
            fabs(v->z - w->z) <= CML_EPSILON && fabs(v->w - w->w) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
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
