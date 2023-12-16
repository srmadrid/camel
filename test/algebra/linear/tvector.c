/******************************************************************************
 * Filename: tvector.c
 * 
 * Description:
 *      Test file for the vector module.
 *
 * Author: Sergio Madrid
 * Created on: 12/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include "../../../include/camel.h"


CML_TestResult test_vector2_add() {
    CML_Vector2 v = {1.0, 2.0};
    CML_Vector2 w = {3.0, 4.0};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {4.0, 6.0};
    cml_vector2_add(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector2_compare(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector2_sub() {
    CML_Vector2 v = {1.0, 2.0};
    CML_Vector2 w = {3.0, 4.0};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {-2.0, -2.0};
    cml_vector2_sub(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector2_compare(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector2_scale() {
    CML_Vector2 v = {1.0, 2.0};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {2.0, 4.0};
    cml_vector2_scale(&v, 2.0, &out);
    CML_TestResult result;
    result.passed = cml_vector2_compare(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector2_mod() {
    CML_Vector2 v = {3.0, 4.0};
    f64 expected = 5.0;
    f64 result = cml_vector2_mod(&v);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CAMEL_TRUE : CAMEL_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f64_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector2_norm() {
    CML_Vector2 v = {3.0, 4.0};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {0.6, 0.8};
    cml_vector2_norm(&v, &out);
    CML_TestResult result;
    result.passed = cml_vector2_compare(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector2_dot() {
    CML_Vector2 v = {1.0, 2.0};
    CML_Vector2 w = {3.0, 4.0};
    f64 expected = 11.0;
    f64 result = cml_vector2_dot(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CAMEL_TRUE : CAMEL_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f64_debug(expected, result);
    }
    return test;
}



CML_TestResult test_vector3_add() {
    CML_Vector3 v = {1.0, 2.0, 3.0};
    CML_Vector3 w = {4.0, 5.0, 6.0};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {5.0, 7.0, 9.0};
    cml_vector3_add(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector3_compare(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector3_sub() {
    CML_Vector3 v = {1.0, 2.0, 3.0};
    CML_Vector3 w = {4.0, 5.0, 6.0};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {-3.0, -3.0, -3.0};
    cml_vector3_sub(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector3_compare(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector3_scale() {
    CML_Vector3 v = {1.0, 2.0, 3.0};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {2.0, 4.0, 6.0};
    cml_vector3_scale(&v, 2.0, &out);
    CML_TestResult result;
    result.passed = cml_vector3_compare(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector3_mod() {
    CML_Vector3 v = {3.0, 4.0, 5.0};
    f64 expected = 7.0710678118654755;
    f64 result = cml_vector3_mod(&v);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CAMEL_TRUE : CAMEL_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f64_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector3_norm() {
    CML_Vector3 v = {3.0, 4.0, 5.0};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {0.4242640687119285, 0.565685424949238, 0.7071067811865475};
    cml_vector3_norm(&v, &out);
    CML_TestResult result;
    result.passed = cml_vector3_compare(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector3_dot() {
    CML_Vector3 v = {1.0, 2.0, 3.0};
    CML_Vector3 w = {4.0, 5.0, 6.0};
    f64 expected = 32.0;
    f64 result = cml_vector3_dot(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CAMEL_TRUE : CAMEL_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f64_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector3_cross() {
    CML_Vector3 v = {1.0, 2.0, 3.0};
    CML_Vector3 w = {4.0, 5.0, 6.0};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {-3.0, 6.0, -3.0};
    cml_vector3_cross(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector3_compare(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}



CML_TestResult test_vector4_add() {
    CML_Vector4 v = {1.0, 2.0, 3.0, 4.0};
    CML_Vector4 w = {5.0, 6.0, 7.0, 8.0};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {6.0, 8.0, 10.0, 12.0};
    cml_vector4_add(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector4_compare(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector4_sub() {
    CML_Vector4 v = {1.0, 2.0, 3.0, 4.0};
    CML_Vector4 w = {5.0, 6.0, 7.0, 8.0};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {-4.0, -4.0, -4.0, -4.0};
    cml_vector4_sub(&v, &w, &out);
    CML_TestResult result;
    result.passed = cml_vector4_compare(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector4_scale() {
    CML_Vector4 v = {1.0, 2.0, 3.0, 4.0};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {2.0, 4.0, 6.0, 8.0};
    cml_vector4_scale(&v, 2.0, &out);
    CML_TestResult result;
    result.passed = cml_vector4_compare(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector4_mod() {
    CML_Vector4 v = {3.0, 4.0, 5.0, 6.0};
    f64 expected = 9.273618495495704;
    f64 result = cml_vector4_mod(&v);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CAMEL_TRUE : CAMEL_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f64_debug(expected, result);
    }
    return test;
}


CML_TestResult test_vector4_norm() {
    CML_Vector4 v = {3.0, 4.0, 5.0, 6.0};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {0.32349831961063324, 0.43133109281417765, 0.5391638660177221, 0.6469966392212665};
    cml_vector4_norm(&v, &out);
    CML_TestResult result;
    result.passed = cml_vector4_compare(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector4_dot() {
    CML_Vector4 v = {1.0, 2.0, 3.0, 4.0};
    CML_Vector4 w = {5.0, 6.0, 7.0, 8.0};
    f64 expected = 70.0;
    f64 result = cml_vector4_dot(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CAMEL_TRUE : CAMEL_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f64_debug(expected, result);
    }
    return test;
}



void cml_register_vector_tests(CML_Test *registry, u32 *count) {
    cml_test_register(registry, count, test_vector2_add, "test_vector2_add");
    cml_test_register(registry, count, test_vector2_sub, "test_vector2_sub");
    cml_test_register(registry, count, test_vector2_scale, "test_vector2_scale");
    cml_test_register(registry, count, test_vector2_mod, "test_vector2_mod");
    cml_test_register(registry, count, test_vector2_norm, "test_vector2_norm");
    cml_test_register(registry, count, test_vector2_dot, "test_vector2_dot");

    cml_test_register(registry, count, test_vector3_add, "test_vector3_add");
    cml_test_register(registry, count, test_vector3_sub, "test_vector3_sub");
    cml_test_register(registry, count, test_vector3_scale, "test_vector3_scale");
    cml_test_register(registry, count, test_vector3_mod, "test_vector3_mod");
    cml_test_register(registry, count, test_vector3_norm, "test_vector3_norm");
    cml_test_register(registry, count, test_vector3_dot, "test_vector3_dot");
    cml_test_register(registry, count, test_vector3_cross, "test_vector3_cross");

    cml_test_register(registry, count, test_vector4_add, "test_vector4_add");
    cml_test_register(registry, count, test_vector4_sub, "test_vector4_sub");
    cml_test_register(registry, count, test_vector4_scale, "test_vector4_scale");
    cml_test_register(registry, count, test_vector4_mod, "test_vector4_mod");
    cml_test_register(registry, count, test_vector4_norm, "test_vector4_norm");
    cml_test_register(registry, count, test_vector4_dot, "test_vector4_dot");
}
