/**
 * @file tdarray.c
 * 
 * @brief Test file for the darray module.
 *
 * @author Sergio Madrid
 * @date 16/1/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/camel.h"


CML_TestResult test_darray_resize() {
    CML_Allocator a = CML_ALLOCATOR_DEFAULT;
    CML_DArray darray;
    cml_darray_init(&a, 2, i32, NULL, &darray);
    cml_darray_resize(10, &darray);
    CML_DArray expected;
    cml_darray_init(&a, 4, i32, NULL, &expected);
    for (u32 i = 0; i < 4; ++i) {
        cml_darray_push(&i, &darray);
        cml_darray_push(&i, &expected);
    }
    CML_TestResult result;
    result.passed = cml_darray_eq(&expected, &darray) && darray.capacity == 10;
    if (!result.passed) {
        result.debugMessage = cml_darray_debug(&expected, &darray, true);
    }
    cml_darray_destroy(&darray);
    cml_darray_destroy(&expected);
    return result;
}


CML_TestResult test_darray_push() {
    CML_Allocator _a = CML_ALLOCATOR_DEFAULT;
    CML_DArray darray;
    cml_darray_init(&_a, 5, i32, NULL, &darray);
    CML_DArray expected;
    cml_darray_init(&_a, 5, i32, NULL, &expected);
    for (u32 i = 0; i < 4; ++i) {
        cml_darray_push(&i, &darray);
    }
    i32 a = 0, b = 1, c = 2, d = 3;
    i32 data[] = {a, b, c, d};
    memcpy(expected.data, data, 4*sizeof(i32));
    expected.length = 4;
    CML_TestResult result;
    result.passed = cml_darray_eq(&expected, &darray);
    if (!result.passed) {
        result.debugMessage = cml_darray_debug(&expected, &darray, true);
    }
    cml_darray_destroy(&darray);
    cml_darray_destroy(&expected);
    return result;
}


CML_TestResult test_darray_insert() {
    CML_Allocator _a = CML_ALLOCATOR_DEFAULT;
    CML_DArray darray;
    cml_darray_init(&_a, 5, i32, NULL, &darray);
    CML_DArray expected;
    cml_darray_init(&_a, 5, i32, NULL, &expected);
    for (u32 i = 0; i < 4; ++i) {
        cml_darray_insert(&i, 0, &darray);
    }
    i32 a = 0, b = 1, c = 2, d = 3;
    i32 data[] = {d, c, b, a};
    memcpy(expected.data, data, 4*sizeof(i32));
    expected.length = 4;
    CML_TestResult result;
    result.passed = cml_darray_eq(&expected, &darray);
    if (!result.passed) {
        result.debugMessage = cml_darray_debug(&expected, &darray, true);
    }
    cml_darray_destroy(&darray);
    cml_darray_destroy(&expected);
    return result;
}


CML_TestResult test_darray_pop() {
    CML_Allocator _a = CML_ALLOCATOR_DEFAULT;
    CML_DArray darray;
    cml_darray_init(&_a, 5, i32, NULL, &darray);
    CML_DArray expected;
    cml_darray_init(&_a, 5, i32, NULL, &expected);
    for (u32 i = 0; i < 4; ++i) {
        cml_darray_insert(&i, 0, &darray);
    }
    i32 b = 1, c = 2, d = 3;
    i32 data[] = {d, c, b};
    memcpy(expected.data, data, 3*sizeof(i32));
    expected.length = 3;
    i32 *element = (i32*)cml_darray_pop(&darray);
    CML_TestResult result;
    result.passed = cml_darray_eq(&expected, &darray) && *element == 0;
    if (!result.passed) {
        result.debugMessage = cml_darray_debug(&expected, &darray, true);
    }
    _a.free(element, _a.context);
    cml_darray_destroy(&darray);
    cml_darray_destroy(&expected);
    return result;
}


CML_TestResult test_darray_remove() {
    CML_Allocator _a = CML_ALLOCATOR_DEFAULT;
    CML_DArray darray;
    cml_darray_init(&_a, 5, i32, NULL, &darray);
    CML_DArray expected;
    cml_darray_init(&_a, 5, i32, NULL, &expected);
    for (u32 i = 0; i < 4; ++i) {
        cml_darray_push(&i, &darray);
    }
    i32 b = 1, c = 2, d = 3;
    i32 data[] = {b, c, d};
    memcpy(expected.data, data, 3*sizeof(i32));
    expected.length = 3;
    i32 *element = (i32*)cml_darray_remove(0, &darray);
    CML_TestResult result;
    result.passed = cml_darray_eq(&expected, &darray) && *element == 0;
    if (!result.passed) {
        result.debugMessage = cml_darray_debug(&expected, &darray, true);
    }
    _a.free(element, _a.context);
    cml_darray_destroy(&darray);
    cml_darray_destroy(&expected);
    return result;
}


CML_TestResult test_darray_get() {
    CML_Allocator _a = CML_ALLOCATOR_DEFAULT;
    CML_DArray darray;
    cml_darray_init(&_a, 5, i32, NULL, &darray);
    CML_DArray expected;
    cml_darray_init(&_a, 5, i32, NULL, &expected);
    for (u32 i = 0; i < 4; ++i) {
        cml_darray_push(&i, &darray);
    }
    i32 a = 0, b = 1, c = 2, d = 3;
    i32 data[] = {a, b, c, d};
    memcpy(expected.data, data, 4*sizeof(i32));
    expected.length = 4;
    i32 element = *(i32*)cml_darray_get(0, &darray);
    CML_TestResult result;
    result.passed = cml_darray_eq(&expected, &darray) && element == 0;
    if (!result.passed) {
        result.debugMessage = cml_darray_debug(&expected, &darray, true);
    }
    cml_darray_destroy(&darray);
    cml_darray_destroy(&expected);
    return result;
}


CML_TestResult test_darray_set() {
    CML_Allocator _a = CML_ALLOCATOR_DEFAULT;
    CML_DArray darray;
    cml_darray_init(&_a, 5, i32, NULL, &darray);
    CML_DArray expected;
    cml_darray_init(&_a, 5, i32, NULL, &expected);
    for (u32 i = 0; i < 4; ++i) {
        cml_darray_push(&i, &darray);
    }
    i32 a = 0, b = 1, d = 3;
    i32 data[] = {a, b, a, d};
    memcpy(expected.data, data, 4*sizeof(i32));
    expected.length = 4;
    i32 element = 0;
    cml_darray_set(&element, 2, &darray);
    CML_TestResult result;
    result.passed = cml_darray_eq(&expected, &darray);
    if (!result.passed) {
        result.debugMessage = cml_darray_debug(&expected, &darray, true);
    }
    cml_darray_destroy(&darray);
    cml_darray_destroy(&expected);
    return result;
}



void cml_register_darray_tests(CML_Test *registry, u32 *count) {
    cml_test_register(registry, count, test_darray_resize, "test_darray_resize");
    cml_test_register(registry, count, test_darray_push, "test_darray_push");
    cml_test_register(registry, count, test_darray_insert, "test_darray_insert");
    cml_test_register(registry, count, test_darray_pop, "test_darray_pop");
    cml_test_register(registry, count, test_darray_remove, "test_darray_remove");
    cml_test_register(registry, count, test_darray_get, "test_darray_get");
    cml_test_register(registry, count, test_darray_set, "test_darray_set");
}
