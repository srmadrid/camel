/******************************************************************************
 * Filename: vector.c
 * 
 * Description:
 *      Implementations for the vector manipulation functions of CAMEL.
 *
 * Author: Sergio Madrid
 * Created on: 9/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include "../../../include/algebra/linear/vector.h"


CML_Status clm_vector_init(CML_Vector *v, size_t n) {
    if (n <= 0) {
        return CML_ERR_INVALID_SIZE;
    }

    if (v == NULL) {
        return CML_ERR_NULL_PTR;
    }

    v->data = (f64*)calloc(n, sizeof(double));
    if (v->data == NULL) {
        v->n = 0;
        return CML_ERR_NULL_PTR;
    }

    v->n = n;

    return CML_SUCCESS;
}


void sm_vector_free(CML_Vector *v) {
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

    for (int i = 0; i < v->n; i++) {
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

    for (int i = 0; i < v->n; i++) {
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

    for (int i = 0; i < v->n; i++) {
        out->data[i] = v->data[i] * t;
    }

    return CML_SUCCESS;
}


f64 cml_vector_mod(const CML_Vector *v) {
    if (!v || !v->n || !v->data) {
        return 0;
    }

    f64 mod = 0;
    for (int i = 0; i < v->n; i++) {
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
    for (int i = 0; i < v->n; i++) {
        mod += v->data[i] * v->data[i];
    }
    mod = 1/sqrt(mod);

    for (int i = 0; i < v->n; i++) {
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
    for (int i = 0; i < v->n; i++) {
        dot += v->data[i] * w->data[i];
    }

    return dot;
}



CML_Status cml_vector2_add(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    (*out)[0] = (*v)[0] + (*w)[0];
    (*out)[1] = (*v)[1] + (*w)[1];

    return CML_SUCCESS;
}


CML_Status cml_vector2_sub(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    (*out)[0] = (*v)[0] - (*w)[0];
    (*out)[1] = (*v)[1] - (*w)[1];

    return CML_SUCCESS;
}


CML_Status cml_vector2_scale(const CML_Vector2 *v, f64 t, CML_Vector2 *out) {
    if (!v || !out) {
        return CML_ERR_NULL_PTR;
    }

    (*out)[0] = (*v)[0] * t;
    (*out)[1] = (*v)[1] * t;

    return CML_SUCCESS;
}


f64 cml_vector2_mod(const CML_Vector2 *v) {
    if (!v) {
        return 0;
    }

    return sqrt((*v)[0] * (*v)[0] + (*v)[1] * (*v)[1]);
}


CML_Status cml_vector2_norm(const CML_Vector2 *v, CML_Vector2 *out) {
    if (!v || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 mod = 1/sqrt((*v)[0] * (*v)[0] + (*v)[1] * (*v)[1]);
    (*out)[0] = (*v)[0] * mod;
    (*out)[1] = (*v)[1] * mod;

    return CML_SUCCESS;
}


f64 cml_vector2_dot(const CML_Vector2 *v, const CML_Vector2 *w) {
    if (!v || !w) {
        return 0;
    }

    return (*v)[0] * (*w)[0] + (*v)[1] * (*w)[1];
}


CML_Bool cml_vector2_compare(const CML_Vector2 *v, const CML_Vector2 *w) {
    if (!v || !w) {
        return CAMEL_FALSE;
    }

    return (fabs((*v)[0] - (*w)[0]) <= CML_EPSILON && fabs((*v)[1] - (*w)[1]) <= CML_EPSILON)? CAMEL_TRUE : CAMEL_FALSE;
}


char *cml_vector2_debug(const CML_Vector2 *expected, const CML_Vector2 *got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debug = (char *)malloc(sizeof(char) * 256);
    if (debug == NULL) {
        return NULL;
    }

    sprintf(debug, "\t\tExpected:\n\t\t\t[%lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf]\n", 
            (*expected)[0], (*expected)[1], (*got)[0], (*got)[1]);
    return debug;
}



CML_Status cml_vector3_add(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    (*out)[0] = (*v)[0] + (*w)[0];
    (*out)[1] = (*v)[1] + (*w)[1];
    (*out)[2] = (*v)[2] + (*w)[2];

    return CML_SUCCESS;
}


CML_Status cml_vector3_sub(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    (*out)[0] = (*v)[0] - (*w)[0];
    (*out)[1] = (*v)[1] - (*w)[1];
    (*out)[2] = (*v)[2] - (*w)[2];

    return CML_SUCCESS;
}


CML_Status cml_vector3_scale(const CML_Vector3 *v, f64 t, CML_Vector3 *out) {
    if (!v || !out) {
        return CML_ERR_NULL_PTR;
    }

    (*out)[0] = (*v)[0] * t;
    (*out)[1] = (*v)[1] * t;
    (*out)[2] = (*v)[2] * t;

    return CML_SUCCESS;
}


f64 cml_vector3_mod(const CML_Vector3 *v) {
    if (!v) {
        return 0;
    }

    return sqrt((*v)[0] * (*v)[0] + (*v)[1] * (*v)[1] + (*v)[2] * (*v)[2]);
}


CML_Status cml_vector3_norm(const CML_Vector3 *v, CML_Vector3 *out) {
    if (!v || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 mod = 1/sqrt((*v)[0] * (*v)[0] + (*v)[1] * (*v)[1] + (*v)[2] * (*v)[2]);
    (*out)[0] = (*v)[0] * mod;
    (*out)[1] = (*v)[1] * mod;
    (*out)[2] = (*v)[2] * mod;

    return CML_SUCCESS;
}


f64 cml_vector3_dot(const CML_Vector3 *v, const CML_Vector3 *w) {
    if (!v || !w) {
        return 0;
    }

    return (*v)[0] * (*w)[0] + (*v)[1] * (*w)[1] + (*v)[2] * (*w)[2];
}


CML_Status cml_vector3_cross(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    (*out)[0] = (*v)[1] * (*w)[2] - (*v)[2] * (*w)[1];
    (*out)[1] = (*v)[2] * (*w)[0] - (*v)[0] * (*w)[2];
    (*out)[2] = (*v)[0] * (*w)[1] - (*v)[1] * (*w)[0];

    return CML_SUCCESS;
}


CML_Bool cml_vector3_compare(const CML_Vector3 *v, const CML_Vector3 *w) {
    if (!v || !w) {
        return CAMEL_FALSE;
    }

    return (fabs((*v)[0] - (*w)[0]) <= CML_EPSILON && fabs((*v)[1] - (*w)[1]) <= CML_EPSILON && fabs((*v)[2] - (*w)[2]) <= CML_EPSILON)? CAMEL_TRUE : CAMEL_FALSE;
}


char *cml_vector3_debug(const CML_Vector3 *expected, const CML_Vector3 *got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debug = (char *)malloc(sizeof(char) * 256);
    if (debug == NULL) {
        return NULL;
    }

    sprintf(debug, "\t\tExpected:\n\t\t\t[%lf, %lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf, %lf]\n",
            (*expected)[0], (*expected)[1], (*expected)[2], (*got)[0], (*got)[1], (*got)[2]);
    return debug;
}



CML_Status cml_vector4_add(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    (*out)[0] = (*v)[0] + (*w)[0];
    (*out)[1] = (*v)[1] + (*w)[1];
    (*out)[2] = (*v)[2] + (*w)[2];
    (*out)[3] = (*v)[3] + (*w)[3];

    return CML_SUCCESS;
}


CML_Status cml_vector4_sub(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    (*out)[0] = (*v)[0] - (*w)[0];
    (*out)[1] = (*v)[1] - (*w)[1];
    (*out)[2] = (*v)[2] - (*w)[2];
    (*out)[3] = (*v)[3] - (*w)[3];

    return CML_SUCCESS;
}


CML_Status cml_vector4_scale(const CML_Vector4 *v, double t, CML_Vector4 *out) {
    if (!v || !out) {
        return CML_ERR_NULL_PTR;
    }

    (*out)[0] = (*v)[0] * t;
    (*out)[1] = (*v)[1] * t;
    (*out)[2] = (*v)[2] * t;
    (*out)[3] = (*v)[3] * t;

    return CML_SUCCESS;
}


f64 cml_vector4_mod(const CML_Vector4 *v) {
    if (!v) {
        return 0;
    }

    return sqrt((*v)[0] * (*v)[0] + (*v)[1] * (*v)[1] + (*v)[2] * (*v)[2] + (*v)[3] * (*v)[3]);
}


CML_Status cml_vector4_norm(const CML_Vector4 *v, CML_Vector4 *out) {
    if (!v || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 mod = 1/sqrt((*v)[0] * (*v)[0] + (*v)[1] * (*v)[1] + (*v)[2] * (*v)[2] + (*v)[3] * (*v)[3]);
    (*out)[0] = (*v)[0] * mod;
    (*out)[1] = (*v)[1] * mod;
    (*out)[2] = (*v)[2] * mod;
    (*out)[3] = (*v)[3] * mod;

    return CML_SUCCESS;
}


f64 cml_vector4_dot(const CML_Vector4 *v, const CML_Vector4 *w) {
    if (!v || !w) {
        return 0;
    }

    return (*v)[0] * (*w)[0] + (*v)[1] * (*w)[1] + (*v)[2] * (*w)[2] + (*v)[3] * (*w)[3];
}


CML_Bool cml_vector4_compare(const CML_Vector4 *v, const CML_Vector4 *w) {
    if (!v || !w) {
        return CAMEL_FALSE;
    }

    return (fabs((*v)[0] - (*w)[0]) <= CML_EPSILON && fabs((*v)[1] - (*w)[1]) <= CML_EPSILON && 
            fabs((*v)[2] - (*w)[2]) <= CML_EPSILON && fabs((*v)[3] - (*w)[3]) <= CML_EPSILON)? CAMEL_TRUE : CAMEL_FALSE;
}


char *cml_vector4_debug(const CML_Vector4 *expected, const CML_Vector4 *got) {
    if (!expected || !got) {
        return NULL;
    }

    char *debug = (char *)malloc(sizeof(char) * 256);
    if (debug == NULL) {
        return NULL;
    }

    sprintf(debug, "\t\tExpected:\n\t\t\t[%lf, %lf, %lf, %lf]\n\t\tGot:\n\t\t\t[%lf, %lf, %lf, %lf]\n", 
            (*expected)[0], (*expected)[1], (*expected)[2], (*expected)[3], (*got)[0], (*got)[1], (*got)[2], (*got)[3]);
    return debug;
}
