/******************************************************************************
 * Filename: vector.h
 * 
 * Description:
 *      Declarations for the vector manipulation functions of CAMEL.
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


#include <stdint.h>
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
 *      double* data - A pointer to the dynamically allocated array of components.
 *
 * Notes:
 *      The 'data' pointer should be managed using cml_vector_init and
 *      cml_vector_free functions to ensure proper memory management. The 'n'
 *      should always reflect the number of allocated elements in 'data'.
 *****************************************************************************/
typedef struct {
    size_t n;
    double *data;
} CML_Vector;


/******************************************************************************
 * Function: cml_vector_init
 * 
 * Description:
 *      Initializes a vector of size 'n' to 0.
 *
 * Parameters:
 *      size_t n - Size of the vector.
 * 
 * Returns:
 *      A pointer to the allocated CML_Vector.
 *****************************************************************************/
CAMEL_API CML_Vector *clm_vector_init(size_t n) {
    if (n <= 0) {
        return NULL;
    }

    CML_Vector *out = (CML_Vector*)malloc(sizeof(CML_Vector));
    if (out == NULL) {
        return NULL;
    }

    out->data = (double*)malloc(n * sizeof(double));
    if (out->data == NULL) {
        free(out);
        return NULL;
    }

    out->n = n;

    for (int i = 0; i < n; i++) {
        out->data[i] = 0.0;
    }

    return out;
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
CAMEL_API void sm_vector_free(CML_Vector *v) {
    if (v != NULL) {
        if (v->data != NULL) {
            free(v->data);
        }
        free(v);
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
CAMEL_API int cml_vector_add(const CML_Vector *v, const CML_Vector *w, CML_Vector *out) {
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
CAMEL_API int cml_vector_sub(const CML_Vector *v, const CML_Vector *w, CML_Vector *out) {
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
 * Function: cml_vector_mult
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
CAMEL_API int cml_vector_mult(const CML_Vector *v, double t, CML_Vector *out) {
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
CAMEL_API double cml_vector_mod(const CML_Vector *v) {
    if (!v || !v->n || !v->data) {
        return CML_ERR_NULL_PTR;
    }

    double mod = 0;
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
CAMEL_API int cml_vector_norm(const CML_Vector *v, CML_Vector *out) {
    if (!v || !out || !v->n || !v->data || !out->n || !out->data) {
        return CML_ERR_NULL_PTR;
    }

    if (v->n != out->n) {
        return CML_ERR_INVALID_SIZE;
    }

    double mod = 0;
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
 *      CML_Vector *v   - The input vector.
 *      CML_Vector *out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API double cml_vector_dot(const CML_Vector *v, const CML_Vector *w) {
    if (!v || !w || !v->n || !v->data || !w->n || !w->data) {
        return CML_ERR_NULL_PTR;
    }

    if (v->n != w->n) {
        return CML_ERR_INVALID_SIZE;
    }

    double dot = 0;
    for (int i = 0; i < v->n; i++) {
        dot += v->data[i] * w->data[i];
    }

    return dot;
}


#endif /* CAMEL_VECTOR */
