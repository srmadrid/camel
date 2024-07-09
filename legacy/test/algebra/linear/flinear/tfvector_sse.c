/**
 * @file tfvector_sse.c
 * 
 * @brief Test file for the fixed vector module of CAMEL, with SSE support.
 *
 * @author Sergio Madrid
 * @date 2/1/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/camel.h"

/*
CML_TestResult test_sse_vector4_add() {
    CML_Vector4 v = CML_VECTOR4(1.0f, 2.0f, 3.0f, 4.0f);
    CML_Vector4 w = {{5.0f, 6.0f, 7.0f, 8.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{6.0f, 8.0f, 10.0f, 12.0f}};
    cml_sse_vector4_add(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_sse_vector4_add_f32() {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{3.0f, 4.0f, 5.0f, 6.0f}};
    cml_sse_vector4_add_f32(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_sse_vector4_sub() {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 w = {{5.0f, 6.0f, 7.0f, 8.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{-4.0f, -4.0f, -4.0f, -4.0f}};
    cml_sse_vector4_sub(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_sse_vector4_sub_f32() {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{-1.0f, 0.0f, 1.0f, 2.0f}};
    cml_sse_vector4_sub_f32(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_sse_vector4_scale() {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{2.0f, 4.0f, 6.0f, 8.0f}};
    cml_sse_vector4_scale(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_sse_vector4_mod() {
    CML_Vector4 v = {{3.0f, 4.0f, 5.0f, 6.0f}};
    f32 expected = 9.273618495495704f;
    f32 result = cml_sse_vector4_mod(&v);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_sse_vector4_mod2() {
    CML_Vector4 v = {{3.0f, 4.0f, 5.0f, 6.0f}};
    f32 expected = 86.0f;
    f32 result = cml_sse_vector4_mod2(&v);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_sse_vector4_norm() {
    CML_Vector4 v = {{3.0f, 4.0f, 5.0f, 6.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{0.32349831961063324f, 0.43133109281417765f, 0.5391638660177221f, 0.6469966392212665f}};
    cml_sse_vector4_norm(&v, &out);
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



void cml_register_sse_fvector_tests(CML_Test *registry, u32 *count) {
    cml_test_register(registry, count, test_sse_vector4_add, "test_sse_vector4_add");
    cml_test_register(registry, count, test_sse_vector4_add_f32, "test_sse_vector4_add_f32");
    cml_test_register(registry, count, test_sse_vector4_sub, "test_sse_vector4_sub");
    cml_test_register(registry, count, test_sse_vector4_sub_f32, "test_sse_vector4_sub_f32");
    cml_test_register(registry, count, test_sse_vector4_scale, "test_sse_vector4_scale");
    cml_test_register(registry, count, test_sse_vector4_mod, "test_sse_vector4_mod");
    cml_test_register(registry, count, test_sse_vector4_mod2, "test_sse_vector4_mod2");
    cml_test_register(registry, count, test_sse_vector4_norm, "test_sse_vector4_norm");
}*/
i32 dummy = 0;
