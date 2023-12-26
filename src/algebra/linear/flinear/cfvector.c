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


CML_Status cmlc_vector2_add(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    out->x = v->x + w->x;
    out->y = v->y + w->y;

    return CML_SUCCESS;
}


CML_Status cmlc_vector2_sub(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    out->x = v->x - w->x;
    out->y = v->y - w->y;

    return CML_SUCCESS;
}


CML_Status cmlc_vector2_scale(const CML_Vector2 *v, f64 t, CML_Vector2 *out) {
    if (!v || !out) {
        return CML_ERR_NULL_PTR;
    }

    out->x = v->x * t;
    out->y = v->y * t;

    return CML_SUCCESS;
}


f64 cmlc_vector2_mod(const CML_Vector2 *v) {
    if (!v) {
        return 0;
    }

    return sqrt(v->x * v->x + v->y * v->y);
}


CML_Status cmlc_vector2_norm(const CML_Vector2 *v, CML_Vector2 *out) {
    if (!v || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 mod = 1/sqrt(v->x * v->x + v->y * v->y);
    out->x = v->x * mod;
    out->y = v->y * mod;

    return CML_SUCCESS;
}


f64 cmlc_vector2_dot(const CML_Vector2 *v, const CML_Vector2 *w) {
    if (!v || !w) {
        return 0;
    }

    return v->x * w->x + v->y * w->y;
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



CML_Status cmlc_vector3_add(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    out->x = v->x + w->x;
    out->y = v->y + w->y;
    out->z = v->z + w->z;

    return CML_SUCCESS;
}


CML_Status cmlc_vector3_sub(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    out->x = v->x - w->x;
    out->y = v->y - w->y;
    out->z = v->z - w->z;

    return CML_SUCCESS;
}


CML_Status cmlc_vector3_scale(const CML_Vector3 *v, f64 t, CML_Vector3 *out) {
    if (!v || !out) {
        return CML_ERR_NULL_PTR;
    }

    out->x = v->x * t;
    out->y = v->y * t;
    out->z = v->z * t;

    return CML_SUCCESS;
}


f64 cmlc_vector3_mod(const CML_Vector3 *v) {
    if (!v) {
        return 0;
    }

    return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}


CML_Status cmlc_vector3_norm(const CML_Vector3 *v, CML_Vector3 *out) {
    if (!v || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 mod = 1/sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
    out->x = v->x * mod;
    out->y = v->y * mod;
    out->z = v->z * mod;

    return CML_SUCCESS;
}


f64 cmlc_vector3_dot(const CML_Vector3 *v, const CML_Vector3 *w) {
    if (!v || !w) {
        return 0;
    }

    return v->x * w->x + v->y * w->y + v->z * w->z;
}


CML_Status cmlc_vector3_cross(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    out->x = v->y * w->z - v->z * w->y;
    out->y = v->z * w->x - v->x * w->z;
    out->z = v->x * w->y - v->y * w->x;

    return CML_SUCCESS;
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



CML_Status cmlc_vector4_add(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    out->x = v->x + w->x;
    out->y = v->y + w->y;
    out->z = v->z + w->z;
    out->w = v->w + w->w;

    return CML_SUCCESS;
}


CML_Status cmlc_vector4_sub(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out) {
    if (!v || !w || !out) {
        return CML_ERR_NULL_PTR;
    }

    out->x = v->x - w->x;
    out->y = v->y - w->y;
    out->z = v->z - w->z;
    out->w = v->w - w->w;

    return CML_SUCCESS;
}


CML_Status cmlc_vector4_scale(const CML_Vector4 *v, f64 t, CML_Vector4 *out) {
    if (!v || !out) {
        return CML_ERR_NULL_PTR;
    }

    out->x = v->x * t;
    out->y = v->y * t;
    out->z = v->z * t;
    out->w = v->w * t;

    return CML_SUCCESS;
}


f64 cmlc_vector4_mod(const CML_Vector4 *v) {
    if (!v) {
        return 0;
    }

    return sqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
}


CML_Status cmlc_vector4_norm(const CML_Vector4 *v, CML_Vector4 *out) {
    if (!v || !out) {
        return CML_ERR_NULL_PTR;
    }

    f64 mod = 1/sqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
    out->x = v->x * mod;
    out->y = v->y * mod;
    out->z = v->z * mod;
    out->w = v->w * mod;

    return CML_SUCCESS;
}


f64 cmlc_vector4_dot(const CML_Vector4 *v, const CML_Vector4 *w) {
    if (!v || !w) {
        return 0;
    }

    return v->x * w->x + v->y * w->y + v->z * w->z + v->w * w->w;
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
