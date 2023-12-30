/******************************************************************************
 * Filename: vvector.c
 * 
 * Description:
 *      Implementations for the variable vector manipulation functions of CAMEL.
 * 
 * Author: Sergio Madrid
 * Created on: 25/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include "../../../../include/algebra/linear/vlinear/vvector.h"


CML_Status clm_vector_init(CML_Vector *v, u32 n) {
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


void cml_vector_free(CML_Vector *v) {
    if (v != NULL) {
        if (v->data != NULL) {
            free(v->data);
        }
        v->n = 0;
    }
}


CML_Status cml_vector_add(const CML_Vector *v, const CML_Vector *w, CML_Vector *out) {
    if (!v || !w || !out || !v->n || !v->data || !w->n || !w->data || !out->n || !out->data) {
        return CML_ERR_NULL_PTR;
    }

    if (v->n != w->n || v->n != out->n) {
        return CML_ERR_INVALID_SIZE;
    }

    for (u32 i = 0; i < v->n; i++) {
        out->data[i] = v->data[i] + w->data[i];
    }

    return CML_SUCCESS;
}


CML_Status cml_vector_sub(const CML_Vector *v, const CML_Vector *w, CML_Vector *out) {
    if (!v || !w || !out || !v->n || !v->data || !w->n || !w->data || !out->n || !out->data) {
        return CML_ERR_NULL_PTR;
    }

    if (v->n != w->n || v->n != out->n) {
        return CML_ERR_INVALID_SIZE;
    }

    for (u32 i = 0; i < v->n; i++) {
        out->data[i] = v->data[i] - w->data[i];
    }

    return CML_SUCCESS;
}


CML_Status cml_vector_scale(const CML_Vector *v, f64 t, CML_Vector *out) {
    if (!v || !out || !v->n || !v->data || !out->n || !out->data) {
        return CML_ERR_NULL_PTR;
    }

    if (v->n != out->n) {
        return CML_ERR_INVALID_SIZE;
    }

    for (u32 i = 0; i < v->n; i++) {
        out->data[i] = v->data[i] * t;
    }

    return CML_SUCCESS;
}


f64 cml_vector_mod(const CML_Vector *v) {
    if (!v || !v->n || !v->data) {
        return 0;
    }

    f64 mod = 0;
    for (u32 i = 0; i < v->n; i++) {
        mod += v->data[i] * v->data[i];
    }
    return sqrt(mod);
}


CML_Status cml_vector_norm(const CML_Vector *v, CML_Vector *out) {
    if (!v || !out || !v->n || !v->data || !out->n || !out->data) {
        return CML_ERR_NULL_PTR;
    }

    if (v->n != out->n) {
        return CML_ERR_INVALID_SIZE;
    }

    f64 mod = 0;
    for (u32 i = 0; i < v->n; i++) {
        mod += v->data[i] * v->data[i];
    }
    mod = 1/sqrt(mod);

    for (u32 i = 0; i < v->n; i++) {
        out->data[i] = v->data[i] * mod;
    }

    return CML_SUCCESS;
}


f64 cml_vector_dot(const CML_Vector *v, const CML_Vector *w) {
    if (!v || !w || !v->n || !v->data || !w->n || !w->data) {
        return 0;
    }

    if (v->n != w->n) {
        return 0;
    }

    f64 dot = 0;
    for (u32 i = 0; i < v->n; i++) {
        dot += v->data[i] * w->data[i];
    }

    return dot;
}
