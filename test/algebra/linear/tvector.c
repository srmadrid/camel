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



void cml_register_vector2_tests(CML_Test *registry, u32 *count) {
    cml_test_register(registry, count, test_vector2_add, "test_vector2_add");
    cml_test_register(registry, count, test_vector2_sub, "test_vector2_sub");
    cml_test_register(registry, count, test_vector2_scale, "test_vector2_scale");
    cml_test_register(registry, count, test_vector2_mod, "test_vector2_mod");
    cml_test_register(registry, count, test_vector2_dot, "test_vector2_dot");
}
