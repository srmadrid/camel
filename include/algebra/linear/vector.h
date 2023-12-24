/******************************************************************************
 * Filename: vector.h
 * 
 * Description:
 *      Declarations and implementations for the vector manipulation functions 
 *      of CAMEL.
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

#ifndef CAMEL_VECTOR
#define CAMEL_VECTOR


#include <stdlib.h>
#include <math.h>

#include "../../core/core.h"


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
CAMEL_STATIC CAMEL_API CML_Status clm_vector_init(CML_Vector *v, size_t n) {
    if (n <= 0) {
        return CML_ERR_INVALID_SIZE;
    }

    if (v == NULL) {
        return CML_ERR_NULL_PTR;
    }

    v->data = (f64*)calloc(n, sizeof(f64));
    if (v->data == NULL) {
        v->n = 0;
        return CML_ERR_NULL_PTR;
    }

    v->n = n;

    return CML_SUCCESS;
}


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
CAMEL_STATIC CAMEL_API void sm_vector_free(CML_Vector *v) {
    if (v != NULL) {
        if (v->data != NULL) {
            free(v->data);
        }
        v->n = 0;
    }
}


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
CAMEL_STATIC CAMEL_API CML_Status cml_vector_add(const CML_Vector *v, const CML_Vector *w, CML_Vector *out) {
    if (!v || !w || !out || !v->n || !v->data || !w->n || !w->data || !out->n || !out->data) {
        return CML_ERR_NULL_PTR;
    }

    if (v->n != w->n || v->n != out->n) {
        return CML_ERR_INVALID_SIZE;
    }

    for (int i = 0; i < v->n; i++) {
        out->data[i] = v->data[i] + w->data[i];
    }

    return CML_SUCCESS;
}


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
CAMEL_STATIC CAMEL_API CML_Status cml_vector_sub(const CML_Vector *v, const CML_Vector *w, CML_Vector *out) {
    if (!v || !w || !out || !v->n || !v->data || !w->n || !w->data || !out->n || !out->data) {
        return CML_ERR_NULL_PTR;
    }

    if (v->n != w->n || v->n != out->n) {
        return CML_ERR_INVALID_SIZE;
    }

    for (int i = 0; i < v->n; i++) {
        out->data[i] = v->data[i] - w->data[i];
    }

    return CML_SUCCESS;
}


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
CAMEL_STATIC CAMEL_API CML_Status cml_vector_scale(const CML_Vector *v, f64 t, CML_Vector *out) {
    if (!v || !out || !v->n || !v->data || !out->n || !out->data) {
        return CML_ERR_NULL_PTR;
    }

    if (v->n != out->n) {
        return CML_ERR_INVALID_SIZE;
    }

    for (int i = 0; i < v->n; i++) {
        out->data[i] = v->data[i] * t;
    }

    return CML_SUCCESS;
}


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
CAMEL_STATIC CAMEL_API f64 cml_vector_mod(const CML_Vector *v) {
    if (!v || !v->n || !v->data) {
        return 0;
    }

    f64 mod = 0;
    for (int i = 0; i < v->n; i++) {
        mod += v->data[i] * v->data[i];
    }
    return sqrt(mod);
}


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
CAMEL_STATIC CAMEL_API CML_Status cml_vector_norm(const CML_Vector *v, CML_Vector *out) {
    if (!v || !out || !v->n || !v->data || !out->n || !out->data) {
        return CML_ERR_NULL_PTR;
    }

    if (v->n != out->n) {
        return CML_ERR_INVALID_SIZE;
    }

    f64 mod = 0;
    for (int i = 0; i < v->n; i++) {
        mod += v->data[i] * v->data[i];
    }
    mod = 1/sqrt(mod);

    for (int i = 0; i < v->n; i++) {
        out->data[i] = v->data[i] * mod;
    }

    return CML_SUCCESS;
}


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
CAMEL_STATIC CAMEL_API f64 cml_vector_dot(const CML_Vector *v, const CML_Vector *w) {
    if (!v || !w || !v->n || !v->data || !w->n || !w->data) {
        return 0;
    }

    if (v->n != w->n) {
        return 0;
    }

    f64 dot = 0;
    for (int i = 0; i < v->n; i++) {
        dot += v->data[i] * w->data[i];
    }

    return dot;
}



/******************************************************************************
 * Type: CML_Vector2
 * 
 * Description:
 *      Represents a 2 dimensional vector.
 *
 * Notes:
 *      The object is directly a 2 dimensional array of f64.
 *****************************************************************************/
typedef f64 CML_Vector2[2];


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
 * Notes:
 *      The object is directly a 3 dimensional array of f64.
 *****************************************************************************/
typedef f64 CML_Vector3[3];


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
 * Notes:
 *      The object is directly a 4 dimensional array of f64.
 *****************************************************************************/
typedef f64 CML_Vector4[4];


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
 *      CML_Vector2 v   - The first vector operand.
 *      CML_Vector2 w   - The second vector operand.
 *      CML_Vector2 out - The output vector.
 * 
 * Returns:
 *      Success (0) or error (<0) code.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API CML_Status cml_vector2_add(const CML_Vector2 v, const CML_Vector2 w, CML_Vector2 out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0] = v[0] + w[0];
    out[1] = v[1] + w[1];

    return CML_SUCCESS;
}


/******************************************************************************
 * Function: cml_vector2_sub
 * 
 * Description:
 *      Subtracts two CML_Vector2 and writes the result to the out CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 v   - The first vector operand.
 *      CML_Vector2 w   - The second vector operand.
 *      CML_Vector2 out - The output vector.
 * 
 * Returns:
 *      Success (0) or error (<0) code.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API CML_Status cml_vector2_sub(const CML_Vector2 v, const CML_Vector2 w, CML_Vector2 out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0] = v[0] - w[0];
    out[1] = v[1] - w[1];

    return CML_SUCCESS;
}


/******************************************************************************
 * Function: cml_vector2_scale
 * 
 * Description:
 *      Multiplies a CML_Vector2 by a scalar, and writes the result to the out 
 *      CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 v   - The vector operand.
 *      double       t   - The scalar.
 *      CML_Vector2 out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API CML_Status cml_vector2_scale(const CML_Vector2 v, f64 t, CML_Vector2 out) {
    if (!v || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0] = v[0] * t;
    out[1] = v[1] * t;

    return CML_SUCCESS;
}


/******************************************************************************
 * Function: cml_vector2_mod
 * 
 * Description:
 *      Calculates the modulus of the input CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 v - The input vector.
 * 
 * Returns:
 *      The modulus of the input CML_Vector2.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API f64 cml_vector2_mod(const CML_Vector2 v) {
    if (!v) {
        return 0;
    }

    return sqrt(v[0] * v[0] + v[1] * v[1]);
}


/******************************************************************************
 * Function: cml_vector2_norm
 * 
 * Description:
 *      Normalizes the input CML_Vector2 and writes it to the out CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 v   - The input vector.
 *      CML_Vector2 out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API CML_Status cml_vector2_norm(const CML_Vector2 v, CML_Vector2 out) {
    if (!v || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 mod = 1/sqrt(v[0] * v[0] + v[1] * v[1]);
    out[0] = v[0] * mod;
    out[1] = v[1] * mod;

    return CML_SUCCESS;
}


/******************************************************************************
 * Function: cml_vector2_dot
 * 
 * Description:
 *      Calculates the dot product of the input CML_Vector2s.
 *
 * Parameters:
 *      CML_Vector2 v   - The first input vector.
 *      CML_Vector2 w   - The second input vector.
 * 
 * Returns:
 *      The dot product of the input vectors.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API f64 cml_vector2_dot(const CML_Vector2 v, const CML_Vector2 w) {
    if (!v || !w) {
        return 0;
    }

    return v[0] * w[0] + v[1] * w[1];
}


/******************************************************************************
 * Function: cml_vector2_eq
 * 
 * Description:
 *      Compares two CML_Vector4s for equality.
 * 
 * Parameters:
 *      CML_Vector2 v - The first input vector.
 *      CML_Vector2 w - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API CML_Bool cml_vector2_eq(const CML_Vector2 v, const CML_Vector2 w) {
    if (!v || !w) {
        return CML_FALSE;
    }

    return (fabs(v[0] - w[0]) <= CML_EPSILON && fabs(v[1] - w[1]) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


/******************************************************************************
 * Function: cml_vector2_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Vector2s.
 *
 * Parameters:
 *      CML_Vector2 expected - Expected vector.
 *      CML_Vector2 got - Result vector.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API char *cml_vector2_debug(const CML_Vector2 expected, const CML_Vector2 got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debug = (char *)malloc(sizeof(char) * 256);
    if (debug == NULL) {
        return NULL;
    }

    sprintf(debug, "\t\tExpected:\n\t\t\t[%lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf]\n", 
            expected[0], expected[1], got[0], got[1]);
    return debug;
}



/******************************************************************************
 * Function: cml_vector3_add
 * 
 * Description:
 *      Adds two CML_Vector3 and writes the result to the out CML_Vector3.
 *
 * Parameters:
 *      CML_Vector3 v   - The first vector operand.
 *      CML_Vector3 w   - The second vector operand.
 *      CML_Vector3 out - The output vector.
 * 
 * Returns:
 *      Success (0) or error (<0) code.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API CML_Status cml_vector3_add(const CML_Vector3 v, const CML_Vector3 w, CML_Vector3 out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0] = v[0] + w[0];
    out[1] = v[1] + w[1];
    out[2] = v[2] + w[2];

    return CML_SUCCESS;
}


/******************************************************************************
 * Function: cml_vector3_sub
 * 
 * Description:
 *      Subtracts two CML_Vector3 and writes the result to the out CML_Vector3.
 *
 * Parameters:
 *      CML_Vector3 v   - The first vector operand.
 *      CML_Vector3 w   - The second vector operand.
 *      CML_Vector3 out - The output vector.
 * 
 * Returns:
 *      Success (0) or error (<0) code.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API CML_Status cml_vector3_sub(const CML_Vector3 v, const CML_Vector3 w, CML_Vector3 out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0] = v[0] - w[0];
    out[1] = v[1] - w[1];
    out[2] = v[2] - w[2];

    return CML_SUCCESS;
}


/******************************************************************************
 * Function: cml_vector3_scale
 * 
 * Description:
 *      Multiplies a CML_Vector3 by a scalar, and writes the result to the out 
 *      CML_Vector3.
 *
 * Parameters:
 *      CML_Vector3 v   - The vector operand.
 *      double       t   - The scalar.
 *      CML_Vector3 out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API CML_Status cml_vector3_scale(const CML_Vector3 v, f64 t, CML_Vector3 out) {
    if (!v || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0] = v[0] * t;
    out[1] = v[1] * t;
    out[2] = v[2] * t;

    return CML_SUCCESS;
}


/******************************************************************************
 * Function: cml_vector3_mod
 * 
 * Description:
 *      Calculates the modulus of the input CML_Vector3.
 *
 * Parameters:
 *      CML_Vector3 v - The input vector.
 * 
 * Returns:
 *      The modulus of the input CML_Vector3.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API f64 cml_vector3_mod(const CML_Vector3 v) {
    if (!v) {
        return 0;
    }

    return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}


/******************************************************************************
 * Function: cml_vector3_norm
 * 
 * Description:
 *      Normalizes the input CML_Vector3 and writes it to the out CML_Vector3.
 *
 * Parameters:
 *      CML_Vector3 v   - The input vector.
 *      CML_Vector3 out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API CML_Status cml_vector3_norm(const CML_Vector3 v, CML_Vector3 out) {
    if (!v || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 mod = 1/sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    out[0] = v[0] * mod;
    out[1] = v[1] * mod;
    out[2] = v[2] * mod;

    return CML_SUCCESS;
}


/******************************************************************************
 * Function: cml_vector3_dot
 * 
 * Description:
 *      Calculates the dot product of the input CML_Vector3s.
 *
 * Parameters:
 *      CML_Vector3 v   - The first input vector.
 *      CML_Vector3 w   - The second input vector.
 * 
 * Returns:
 *      The dot product of the input vectors.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API f64 cml_vector3_dot(const CML_Vector3 v, const CML_Vector3 w) {
    if (!v || !w) {
        return 0;
    }

    return v[0] * w[0] + v[1] * w[1] + v[2] * w[2];
}


/******************************************************************************
 * Function: cml_vector3_cross
 * 
 * Description:
 *      Calculates the cross product of the input CML_Vector3s.
 *
 * Parameters:
 *      CML_Vector3 v   - The first input vector.
 *      CML_Vector3 w   - The second input vector.
 *      CML_Vector3 out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API CML_Status cml_vector3_cross(const CML_Vector3 v, const CML_Vector3 w, CML_Vector3 out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0] = v[1] * w[2] - v[2] * w[1];
    out[1] = v[2] * w[0] - v[0] * w[2];
    out[2] = v[0] * w[1] - v[1] * w[0];

    return CML_SUCCESS;
}


/******************************************************************************
 * Function: cml_vector3_eq
 * 
 * Description:
 *      Compares two CML_Vector4s for equality.
 * 
 * Parameters:
 *      CML_Vector3 v - The first input vector.
 *      CML_Vector3 w - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API CML_Bool cml_vector3_eq(const CML_Vector3 v, const CML_Vector3 w) {
    if (!v || !w) {
        return CML_FALSE;
    }

    return (fabs(v[0] - w[0]) <= CML_EPSILON && fabs(v[1] - w[1]) <= CML_EPSILON && fabs(v[2] - w[2]) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


/******************************************************************************
 * Function: cml_vector3_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Vector3s.
 *
 * Parameters:
 *      CML_Vector3 expected - Expected vector.
 *      CML_Vector3 got - Result vector.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API char *cml_vector3_debug(const CML_Vector3 expected, const CML_Vector3 got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debug = (char *)malloc(sizeof(char) * 256);
    if (debug == NULL) {
        return NULL;
    }

    sprintf(debug, "\t\tExpected:\n\t\t\t[%lf, %lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf, %lf]\n",
            expected[0], expected[1], expected[2], got[0], got[1], got[2]);
    return debug;
}



/******************************************************************************
 * Function: cml_vector4_add
 * 
 * Description:
 *      Adds two CML_Vector4 and writes the result to the out CML_Vector4.
 *
 * Parameters:
 *      CML_Vector4 v   - The first vector operand.
 *      CML_Vector4 w   - The second vector operand.
 *      CML_Vector4 out - The output vector.
 * 
 * Returns:
 *      Success (0) or error (<0) code.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API CML_Status cml_vector4_add(const CML_Vector4 v, const CML_Vector4 w, CML_Vector4 out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0] = v[0] + w[0];
    out[1] = v[1] + w[1];
    out[2] = v[2] + w[2];
    out[3] = v[3] + w[3];

    return CML_SUCCESS;
}


/******************************************************************************
 * Function: cml_vector4_sub
 * 
 * Description:
 *      Subtracts two CML_Vector4 and writes the result to the out CML_Vector4.
 *
 * Parameters:
 *      CML_Vector4 v   - The first vector operand.
 *      CML_Vector4 w   - The second vector operand.
 *      CML_Vector4 out - The output vector.
 * 
 * Returns:
 *      Success (0) or error (<0) code.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API CML_Status cml_vector4_sub(const CML_Vector4 v, const CML_Vector4 w, CML_Vector4 out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0] = v[0] - w[0];
    out[1] = v[1] - w[1];
    out[2] = v[2] - w[2];
    out[3] = v[3] - w[3];

    return CML_SUCCESS;
}


/******************************************************************************
 * Function: cml_vector4_scale
 * 
 * Description:
 *      Multiplies a CML_Vector4 by a scalar, and writes the result to the out 
 *      CML_Vector4.
 *
 * Parameters:
 *      CML_Vector4 v   - The vector operand.
 *      double       t   - The scalar.
 *      CML_Vector4 out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API CML_Status cml_vector4_scale(const CML_Vector4 v, f64 t, CML_Vector4 out) {
    if (!v || !out) {
        return CML_ERR_NULL_PTR;
    }

    out[0] = v[0] * t;
    out[1] = v[1] * t;
    out[2] = v[2] * t;
    out[3] = v[3] * t;

    return CML_SUCCESS;
}


/******************************************************************************
 * Function: cml_vector4_mod
 * 
 * Description:
 *      Calculates the modulus of the input CML_Vector4.
 *
 * Parameters:
 *      CML_Vector4 v - The input vector.
 * 
 * Returns:
 *      The modulus of the input CML_Vector4.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API f64 cml_vector4_mod(const CML_Vector4 v) {
    if (!v) {
        return 0;
    }

    return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2] + v[3] * v[3]);
}


/******************************************************************************
 * Function: cml_vector4_norm
 * 
 * Description:
 *      Normalizes the input CML_Vector4 and writes it to the out CML_Vector4.
 *
 * Parameters:
 *      CML_Vector4 v   - The input vector.
 *      CML_Vector4 out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API CML_Status cml_vector4_norm(const CML_Vector4 v, CML_Vector4 out) {
    if (!v || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 mod = 1/sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2] + v[3] * v[3]);
    out[0] = v[0] * mod;
    out[1] = v[1] * mod;
    out[2] = v[2] * mod;
    out[3] = v[3] * mod;

    return CML_SUCCESS;
}


/******************************************************************************
 * Function: cml_vector4_dot
 * 
 * Description:
 *      Calculates the dot product of the input CML_Vector4s.
 *
 * Parameters:
 *      CML_Vector4 v   - The first input vector.
 *      CML_Vector4 w   - The second input vector.
 * 
 * Returns:
 *      The dot product of the input vectors.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API f64 cml_vector4_dot(const CML_Vector4 v, const CML_Vector4 w) {
    if (!v || !w) {
        return 0;
    }

    return v[0] * w[0] + v[1] * w[1] + v[2] * w[2] + v[3] * w[3];
}


/******************************************************************************
 * Function: cml_vector4_eq
 * 
 * Description:
 *      Compares two CML_Vector4s for equality.
 * 
 * Parameters:
 *      CML_Vector4 v - The first input vector.
 *      CML_Vector4 w - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API CML_Bool cml_vector4_eq(const CML_Vector4 v, const CML_Vector4 w) {
    if (!v || !w) {
        return CML_FALSE;
    }

    return (fabs(v[0] - w[0]) <= CML_EPSILON && fabs(v[1] - w[1]) <= CML_EPSILON && 
            fabs(v[2] - w[2]) <= CML_EPSILON && fabs(v[3] - w[3]) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


/******************************************************************************
 * Function: cml_vector4_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Vector4s.
 *
 * Parameters:
 *      CML_Vector4 expected - Expected vector.
 *      CML_Vector4 got - Result vector.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_STATIC CAMEL_API char *cml_vector4_debug(const CML_Vector4 expected, const CML_Vector4 got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debug = (char *)malloc(sizeof(char) * 256);
    if (debug == NULL) {
        return NULL;
    }

    sprintf(debug, "\t\tExpected:\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf, %lf, %lf]\n", 
            expected[0], expected[1], expected[2], expected[3], got[0], got[1], got[2], got[3]);
    return debug;
}


#endif /* CAMEL_VECTOR */
