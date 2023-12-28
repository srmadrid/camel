/******************************************************************************
 * Filename: cfvector.h
 * 
 * Description:
 *      Implementations for the compilef version of the fixed vector manipulation 
 *      functions of CAMEL.
 * 
 * Author: Sergio Madrid
 * Created on: 25/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include <math.h>

#include "../../../../include/algebra/linear/flinear/cfvector.h"


void cmlc_vector2_add(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out) {
    out->x = v->x + w->x;
    out->y = v->y + w->y;
}


void cmlc_vector2_add_scalar(const CML_Vector2 *v, f64 t, CML_Vector2 *out) {
    out->x = v->x + t;
    out->y = v->y + t;
}


void cmlc_vector2_sub(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out) {
    out->x = v->x - w->x;
    out->y = v->y - w->y;
}


void cmlc_vector2_sub_scalar(const CML_Vector2 *v, f64 t, CML_Vector2 *out) {
    out->x = v->x - t;
    out->y = v->y - t;
}


void cmlc_vector2_scale(const CML_Vector2 *v, f64 t, CML_Vector2 *out) {
    out->x = v->x * t;
    out->y = v->y * t;
}


f64 cmlc_vector2_mod(const CML_Vector2 *v) {
    return sqrt(v->x * v->x + v->y * v->y);
}


f64 cmlc_vector2_mod2(const CML_Vector2 *v) {
    return v->x * v->x + v->y * v->y;
}


void cmlc_vector2_norm(const CML_Vector2 *v, CML_Vector2 *out) {
    f64 mod = 1/sqrt(v->x * v->x + v->y * v->y);
    out->x = v->x * mod;
    out->y = v->y * mod;
}


f64 cmlc_vector2_dot(const CML_Vector2 *v, const CML_Vector2 *w) {
    return v->x * w->x + v->y * w->y;
}


f64 cmlc_vector2_distance(const CML_Vector2 *v, const CML_Vector2 *w) {
    return sqrt((v->x - w->x) * (v->x - w->x) + (v->y - w->y) * (v->y - w->y));
}


f64 cmlc_vector2_distance2(const CML_Vector2 *v, const CML_Vector2 *w) {
    return (v->x - w->x) * (v->x - w->x) + (v->y - w->y) * (v->y - w->y);
}


f64 cmlc_vector2_angle(const CML_Vector2 *v, const CML_Vector2 *w) {
    return acos((v->x * w->x + v->y * w->y) / (sqrt(v->x * v->x + v->y * v->y) * sqrt(w->x * w->x + w->y * w->y)));
}


void cmlc_vector2_project(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out) {
    f64 mod = (v->x * w->x + v->y * w->y) / (w->x * w->x + w->y * w->y);
    out->x = mod * w->x;
    out->y = mod * w->y;
}


void cmlc_vector2_reflect(const CML_Vector2 *v, const CML_Vector2 *normal, CML_Vector2 *out) {
    f64 mod = 2 * (v->x * normal->x + v->y * normal->y) / (normal->x * normal->x + normal->y * normal->y);
    out->x = v->x - mod * normal->x;
    out->y = v->y - mod * normal->y;
}


CML_Bool cmlc_vector2_eq(const CML_Vector2 *v, const CML_Vector2 *w) {
    if (!v || !w) {
        return CML_FALSE;
    }

    return (fabs(v->x - w->x) <= CML_EPSILON && fabs(v->y - w->y) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cmlc_vector2_debug(const CML_Vector2 *expected, const CML_Vector2 *got) {
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



void cmlc_vector3_add(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out) {
    out->x = v->x + w->x;
    out->y = v->y + w->y;
    out->z = v->z + w->z;
}


void cmlc_vector3_add_scalar(const CML_Vector3 *v, f64 t, CML_Vector3 *out) {
    out->x = v->x + t;
    out->y = v->y + t;
    out->z = v->z + t;
}


void cmlc_vector3_sub(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out) {
    out->x = v->x - w->x;
    out->y = v->y - w->y;
    out->z = v->z - w->z;
}


void cmlc_vector3_sub_scalar(const CML_Vector3 *v, f64 t, CML_Vector3 *out) {
    out->x = v->x - t;
    out->y = v->y - t;
    out->z = v->z - t;
}


void cmlc_vector3_scale(const CML_Vector3 *v, f64 t, CML_Vector3 *out) {
    out->x = v->x * t;
    out->y = v->y * t;
    out->z = v->z * t;
}


f64 cmlc_vector3_mod(const CML_Vector3 *v) {
    return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}


f64 cmlc_vector3_mod2(const CML_Vector3 *v) {
    return v->x * v->x + v->y * v->y + v->z * v->z;
}


void cmlc_vector3_norm(const CML_Vector3 *v, CML_Vector3 *out) {
    f64 mod = 1/sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
    out->x = v->x * mod;
    out->y = v->y * mod;
    out->z = v->z * mod;
}


f64 cmlc_vector3_dot(const CML_Vector3 *v, const CML_Vector3 *w) {
    return v->x * w->x + v->y * w->y + v->z * w->z;
}


void cmlc_vector3_cross(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out) {
    out->x = v->y * w->z - v->z * w->y;
    out->y = v->z * w->x - v->x * w->z;
    out->z = v->x * w->y - v->y * w->x;
}


f64 cmlc_vector3_distance(const CML_Vector3 *v, const CML_Vector3 *w) {
    return sqrt((v->x - w->x) * (v->x - w->x) + (v->y - w->y) * (v->y - w->y) + (v->z - w->z) * (v->z - w->z));
}


f64 cmlc_vector3_distance2(const CML_Vector3 *v, const CML_Vector3 *w) {
    return (v->x - w->x) * (v->x - w->x) + (v->y - w->y) * (v->y - w->y) + (v->z - w->z) * (v->z - w->z);
}


f64 cmlc_vector3_angle(const CML_Vector3 *v, const CML_Vector3 *w) {
    return acos((v->x * w->x + v->y * w->y + v->z * w->z) / 
                (sqrt(v->x * v->x + v->y * v->y + v->z * v->z) * 
                 sqrt(w->x * w->x + w->y * w->y + w->z * w->z)));
}


void cmlc_vector3_project(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out) {
    f64 mod = (v->x * w->x + v->y * w->y + v->z * w->z) / (w->x * w->x + w->y * w->y + w->z * w->z);
    out->x = mod * w->x;
    out->y = mod * w->y;
    out->z = mod * w->z;
}


void cmlc_vector3_reflect(const CML_Vector3 *v, const CML_Vector3 *normal, CML_Vector3 *out) {
    f64 mod = 2 * (v->x * normal->x + v->y * normal->y + v->z * normal->z) / 
                  (normal->x * normal->x + normal->y * normal->y + normal->z * normal->z);
    out->x = v->x - mod * normal->x;
    out->y = v->y - mod * normal->y;
    out->z = v->z - mod * normal->z;
}


CML_Bool cmlc_vector3_eq(const CML_Vector3 *v, const CML_Vector3 *w) {
    if (!v || !w) {
        return CML_FALSE;
    }

    return (fabs(v->x - w->x) <= CML_EPSILON && fabs(v->y - w->y) <= CML_EPSILON && fabs(v->z - w->z) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cmlc_vector3_debug(const CML_Vector3 *expected, const CML_Vector3 *got) {
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



void cmlc_vector4_add(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out) {
    out->x = v->x + w->x;
    out->y = v->y + w->y;
    out->z = v->z + w->z;
    out->w = v->w + w->w;
}


void cmlc_vector4_add_scalar(const CML_Vector4 *v, f64 t, CML_Vector4 *out) {
    out->x = v->x + t;
    out->y = v->y + t;
    out->z = v->z + t;
    out->w = v->w + t;
}


void cmlc_vector4_sub(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out) {
    out->x = v->x - w->x;
    out->y = v->y - w->y;
    out->z = v->z - w->z;
    out->w = v->w - w->w;
}


void cmlc_vector4_sub_scalar(const CML_Vector4 *v, f64 t, CML_Vector4 *out) {
    out->x = v->x - t;
    out->y = v->y - t;
    out->z = v->z - t;
    out->w = v->w - t;
}


void cmlc_vector4_scale(const CML_Vector4 *v, f64 t, CML_Vector4 *out) {
    out->x = v->x * t;
    out->y = v->y * t;
    out->z = v->z * t;
    out->w = v->w * t;
}


f64 cmlc_vector4_mod(const CML_Vector4 *v) {
    return sqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
}


f64 cmlc_vector4_mod2(const CML_Vector4 *v) {
    return v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w;
}


void cmlc_vector4_norm(const CML_Vector4 *v, CML_Vector4 *out) {
    f64 mod = 1/sqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
    out->x = v->x * mod;
    out->y = v->y * mod;
    out->z = v->z * mod;
    out->w = v->w * mod;
}


f64 cmlc_vector4_dot(const CML_Vector4 *v, const CML_Vector4 *w) {
    return v->x * w->x + v->y * w->y + v->z * w->z + v->w * w->w;
}


f64 cmlc_vector4_distance(const CML_Vector4 *v, const CML_Vector4 *w) {
    return sqrt((v->x - w->x) * (v->x - w->x) + (v->y - w->y) * (v->y - w->y) + 
                (v->z - w->z) * (v->z - w->z) + (v->w - w->w) * (v->w - w->w));
}


f64 cmlc_vector4_distance2(const CML_Vector4 *v, const CML_Vector4 *w) {
    return (v->x - w->x) * (v->x - w->x) + (v->y - w->y) * (v->y - w->y) + 
           (v->z - w->z) * (v->z - w->z) + (v->w - w->w) * (v->w - w->w);
}


f64 cmlc_vector4_angle(const CML_Vector4 *v, const CML_Vector4 *w) {
    return acos((v->x * w->x + v->y * w->y + v->z * w->z + v->w * w->w) / 
                (sqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w) * 
                 sqrt(w->x * w->x + w->y * w->y + w->z * w->z + w->w * w->w)));
}


void cmlc_vector4_project(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out) {
    f64 mod = (v->x * w->x + v->y * w->y + v->z * w->z + v->w * w->w) / 
              (w->x * w->x + w->y * w->y + w->z * w->z + w->w * w->w);
    out->x = mod * w->x;
    out->y = mod * w->y;
    out->z = mod * w->z;
    out->w = mod * w->w;
}


void cmlc_vector4_reflect(const CML_Vector4 *v, const CML_Vector4 *normal, CML_Vector4 *out) {
    f64 mod = 2 * (v->x * normal->x + v->y * normal->y + v->z * normal->z + v->w * normal->w) / 
                  (normal->x * normal->x + normal->y * normal->y + normal->z * normal->z + normal->w * normal->w);
    out->x = v->x - mod * normal->x;
    out->y = v->y - mod * normal->y;
    out->z = v->z - mod * normal->z;
    out->w = v->w - mod * normal->w;
}


CML_Bool cmlc_vector4_eq(const CML_Vector4 *v, const CML_Vector4 *w) {
    if (!v || !w) {
        return CML_FALSE;
    }

    return (fabs(v->x - w->x) <= CML_EPSILON && fabs(v->y - w->y) <= CML_EPSILON && 
            fabs(v->z - w->z) <= CML_EPSILON && fabs(v->w - w->w) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
}


char *cmlc_vector4_debug(const CML_Vector4 *expected, const CML_Vector4 *got) {
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
