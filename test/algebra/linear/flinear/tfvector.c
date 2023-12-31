/******************************************************************************
 * Filename: tfvector.c
 * 
 * Description:
 *      Test file for the fixed vector module.
 *
 * Author: Sergio Madrid
 * Created on: 12/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include "../../../../include/camel.h"


CML_TestResult test_vector2_add() {
    CML_Vector2 v = CML_VECTOR2(1.0f, 2.0f);
    CML_Vector2 w = {{3.0f, 4.0f}};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {{4.0f, 6.0f}};
    cml_vector2_add(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector2_add_f32() {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {{3.0f, 4.0f}};
    cml_vector2_add_f32(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector2_sub() {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 w = {{3.0f, 4.0f}};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {{-2.0f, -2.0f}};
    cml_vector2_sub(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector2_sub_scalar() {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {{-1.0f, 0.0f}};
    cml_vector2_sub_scalar(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector2_scale() {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {{2.0f, 4.0f}};
    cml_vector2_scale(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector2_mod() {
    CML_Vector2 v = {{3.0f, 4.0f}};
    f32 expected = 5.0f;
    f32 result = cml_vector2_mod(&v);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector2_mod2() {
    CML_Vector2 v = {{3.0f, 4.0f}};
    f32 expected = 25.0f;
    f32 result = cml_vector2_mod2(&v);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector2_norm() {
    CML_Vector2 v = {{3.0f, 4.0f}};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {{0.6f, 0.8f}};
    cml_vector2_norm(&v, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector2_dot() {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 w = {{3.0f, 4.0f}};
    f32 expected = 11.0f;
    f32 result = cml_vector2_dot(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector2_distance() {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 w = {{3.0f, 4.0f}};
    f32 expected = 2.8284271247461903f;
    f32 result = cml_vector2_distance(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector2_distance2() {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 w = {{3.0f, 4.0f}};
    f32 expected = 8.0f;
    f32 result = cml_vector2_distance2(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector2_angle() {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 w = {{3.0f, 4.0f}};
    f32 expected = 0.17985349979247847f;
    f32 result = cml_vector2_angle(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector2_project() {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 w = {{3.0f, 4.0f}};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {{1.32f, 1.76f}};
    cml_vector2_project(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector2_reflect() {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 w = {{3.0f, 4.0f}};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {{-1.64f, -1.52f}};
    cml_vector2_reflect(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}



CML_TestResult test_vector3_add() {
    CML_Vector3 v = CML_VECTOR3(1.0f, 2.0f, 3.0f);
    CML_Vector3 w = {{4.0f, 5.0f, 6.0f}};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {{5.0f, 7.0f, 9.0f}};
    cml_vector3_add(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector3_add_f32() {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {{3.0f, 4.0f, 5.0f}};
    cml_vector3_add_f32(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector3_sub() {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 w = {{4.0f, 5.0f, 6.0f}};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {{-3.0f, -3.0f, -3.0f}};
    cml_vector3_sub(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector3_sub_scalar() {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {{-1.0f, 0.0f, 1.0f}};
    cml_vector3_sub_scalar(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector3_scale() {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {{2.0f, 4.0f, 6.0f}};
    cml_vector3_scale(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector3_mod() {
    CML_Vector3 v = {{3.0f, 4.0f, 5.0f}};
    f32 expected = 7.0710678118654755f;
    f32 result = cml_vector3_mod(&v);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector3_mod2() {
    CML_Vector3 v = {{3.0f, 4.0f, 5.0f}};
    f32 expected = 50.0f;
    f32 result = cml_vector3_mod2(&v);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector3_norm() {
    CML_Vector3 v = {{3.0f, 4.0f, 5.0f}};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {{0.4242640687119285f, 0.565685424949238f, 0.7071067811865475f}};
    cml_vector3_norm(&v, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector3_dot() {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 w = {{4.0f, 5.0f, 6.0f}};
    f32 expected = 32.0f;
    f32 result = cml_vector3_dot(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector3_cross() {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 w = {{4.0f, 5.0f, 6.0f}};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {{-3.0f, 6.0f, -3.0f}};
    cml_vector3_cross(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector3_distance() {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 w = {{4.0f, 5.0f, 6.0f}};
    f32 expected = 5.196152422706632f;
    f32 result = cml_vector3_distance(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector3_distance2() {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 w = {{4.0f, 5.0f, 6.0f}};
    f32 expected = 27.0f;
    f32 result = cml_vector3_distance2(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector3_angle() {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 w = {{4.0f, 5.0f, 6.0f}};
    f32 expected = 0.2257261285527342f;
    f32 result = cml_vector3_angle(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(result, expected);
    }
    return test;
}


CML_TestResult test_vector3_project() {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 w = {{4.0f, 5.0f, 6.0f}};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {{1.662337662337662f, 2.077922077922078f, 2.493506493506494f}};
    cml_vector3_project(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector3_reflect() {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 w = {{4.0f, 5.0f, 6.0f}};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {{-2.324675324675325f, -2.1558441558441563f, -1.987012987012987f}};
    cml_vector3_reflect(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}



CML_TestResult test_vector4_add() {
    CML_Vector4 v = CML_VECTOR4(1.0f, 2.0f, 3.0f, 4.0f);
    CML_Vector4 w = {{5.0f, 6.0f, 7.0f, 8.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{6.0f, 8.0f, 10.0f, 12.0f}};
    cml_vector4_add(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector4_add_f32() {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{3.0f, 4.0f, 5.0f, 6.0f}};
    cml_vector4_add_f32(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector4_sub() {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 w = {{5.0f, 6.0f, 7.0f, 8.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{-4.0f, -4.0f, -4.0f, -4.0f}};
    cml_vector4_sub(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector4_sub_scalar() {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{-1.0f, 0.0f, 1.0f, 2.0f}};
    cml_vector4_sub_scalar(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector4_scale() {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{2.0f, 4.0f, 6.0f, 8.0f}};
    cml_vector4_scale(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector4_mod() {
    CML_Vector4 v = {{3.0f, 4.0f, 5.0f, 6.0f}};
    f32 expected = 9.273618495495704f;
    f32 result = cml_vector4_mod(&v);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector4_mod2() {
    CML_Vector4 v = {{3.0f, 4.0f, 5.0f, 6.0f}};
    f32 expected = 86.0f;
    f32 result = cml_vector4_mod2(&v);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector4_norm() {
    CML_Vector4 v = {{3.0f, 4.0f, 5.0f, 6.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{0.32349831961063324f, 0.43133109281417765f, 0.5391638660177221f, 0.6469966392212665f}};
    cml_vector4_norm(&v, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector4_dot() {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 w = {{5.0f, 6.0f, 7.0f, 8.0f}};
    f32 expected = 70.0f;
    f32 result = cml_vector4_dot(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector4_distance() {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 w = {{5.0f, 6.0f, 7.0f, 8.0f}};
    f32 expected = 8.0f;
    f32 result = cml_vector4_distance(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector4_distance2() {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 w = {{5.0f, 6.0f, 7.0f, 8.0f}};
    f32 expected = 64.0f;
    f32 result = cml_vector4_distance2(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector4_angle() {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 w = {{5.0f, 6.0f, 7.0f, 8.0f}};
    f32 expected = 0.250195920422511f;
    f32 result = cml_vector4_angle(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector4_project() {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 w = {{5.0f, 6.0f, 7.0f, 8.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{2.011494252873563f, 2.413793103448276f, 2.816091954022989f, 3.218390804597701f}};
    cml_vector4_project(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector4_reflect() {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 w = {{5.0f, 6.0f, 7.0f, 8.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{-3.0229885057471266f, -2.8275862068965516f, -2.6321839080459775f, -2.4367816091954024f}};
    cml_vector4_reflect(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}



void cml_register_fvector_tests(CML_Test *registry, u32 *count) {
    cml_test_register(registry, count, test_vector2_add, "test_vector2_add");
    cml_test_register(registry, count, test_vector2_add_f32, "test_vector2_add_f32");
    cml_test_register(registry, count, test_vector2_sub, "test_vector2_sub");
    cml_test_register(registry, count, test_vector2_sub_scalar, "test_vector2_sub_scalar");
    cml_test_register(registry, count, test_vector2_scale, "test_vector2_scale");
    cml_test_register(registry, count, test_vector2_mod, "test_vector2_mod");
    cml_test_register(registry, count, test_vector2_mod2, "test_vector2_mod2");
    cml_test_register(registry, count, test_vector2_norm, "test_vector2_norm");
    cml_test_register(registry, count, test_vector2_dot, "test_vector2_dot");
    cml_test_register(registry, count, test_vector2_distance, "test_vector2_distance");
    cml_test_register(registry, count, test_vector2_distance2, "test_vector2_distance2");
    cml_test_register(registry, count, test_vector2_angle, "test_vector2_angle");
    cml_test_register(registry, count, test_vector2_project, "test_vector2_project");
    cml_test_register(registry, count, test_vector2_reflect, "test_vector2_reflect");

    cml_test_register(registry, count, test_vector3_add, "test_vector3_add");
    cml_test_register(registry, count, test_vector3_add_f32, "test_vector3_add_f32");
    cml_test_register(registry, count, test_vector3_sub, "test_vector3_sub");
    cml_test_register(registry, count, test_vector3_sub_scalar, "test_vector3_sub_scalar");
    cml_test_register(registry, count, test_vector3_scale, "test_vector3_scale");
    cml_test_register(registry, count, test_vector3_mod, "test_vector3_mod");
    cml_test_register(registry, count, test_vector3_mod2, "test_vector3_mod2");
    cml_test_register(registry, count, test_vector3_norm, "test_vector3_norm");
    cml_test_register(registry, count, test_vector3_dot, "test_vector3_dot");
    cml_test_register(registry, count, test_vector3_cross, "test_vector3_cross");
    cml_test_register(registry, count, test_vector3_distance, "test_vector3_distance");
    cml_test_register(registry, count, test_vector3_distance2, "test_vector3_distance2");
    cml_test_register(registry, count, test_vector3_angle, "test_vector3_angle");
    cml_test_register(registry, count, test_vector3_project, "test_vector3_project");
    cml_test_register(registry, count, test_vector3_reflect, "test_vector3_reflect");

    cml_test_register(registry, count, test_vector4_add, "test_vector4_add");
    cml_test_register(registry, count, test_vector4_add_f32, "test_vector4_add_f32");
    cml_test_register(registry, count, test_vector4_sub, "test_vector4_sub");
    cml_test_register(registry, count, test_vector4_sub_scalar, "test_vector4_sub_scalar");
    cml_test_register(registry, count, test_vector4_scale, "test_vector4_scale");
    cml_test_register(registry, count, test_vector4_mod, "test_vector4_mod");
    cml_test_register(registry, count, test_vector4_mod2, "test_vector4_mod2");
    cml_test_register(registry, count, test_vector4_norm, "test_vector4_norm");
    cml_test_register(registry, count, test_vector4_dot, "test_vector4_dot");
    cml_test_register(registry, count, test_vector4_distance, "test_vector4_distance");
    cml_test_register(registry, count, test_vector4_distance2, "test_vector4_distance2");
    cml_test_register(registry, count, test_vector4_angle, "test_vector4_angle");
    cml_test_register(registry, count, test_vector4_project, "test_vector4_project");
    cml_test_register(registry, count, test_vector4_reflect, "test_vector4_reflect");
}
