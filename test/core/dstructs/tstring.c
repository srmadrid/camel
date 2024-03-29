/**
 * @file tstring.c
 * 
 * @brief Test file for the string module.
 *
 * @author Sergio Madrid
 * @date 15/1/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/camel.h"


CML_TestResult test_string_temp(void) {
    CML_Allocator _a = CML_ALLOCATOR_DEFAULT;
    CML_String *string = cml_string_temp(&_a, "Hello, world!");
    cml_string_checkref(&string);
    CML_TestResult result;
    result.passed = string == NULL;
    if (!result.passed) {
        result.debugMessage = "Temp string was not freed.\n";
    }
    cml_string_destroy(string);
    return result;
}


CML_TestResult test_string_checkref(void) {
    CML_Allocator _a = CML_ALLOCATOR_DEFAULT;
    CML_String string1;
    cml_string_init(&_a, "Hello, world!", &string1);
    string1.refCount = 5;
    CML_String *string1ptr = &string1;
    cml_string_checkref(&string1ptr);
    CML_String string2;
    cml_string_init(&_a, "Hello, world!", &string2);
    CML_String *string2ptr = &string2;
    cml_string_checkref(&string2ptr);
    CML_TestResult result;
    result.passed = string1.refCount == 4 && string2.refCount == -1;
    if (!result.passed) {
        result.debugMessage = "String refcount was not decremented correctly.\n";
    }
    cml_string_destroy(&string1);
    cml_string_destroy(&string2);
    return result;
}


CML_TestResult test_string_copy(void) {
    CML_Allocator _a = CML_ALLOCATOR_DEFAULT;
    CML_String string;
    cml_string_init0(&_a, &string);
    cml_string_copy(cml_string_temp(&_a, "Hello, world!"), &string);
    CML_TestResult result;
    result.passed = cml_string_eq(cml_string_temp(&_a, "Hello, world!"), &string);
    if (!result.passed) {
        result.debugMessage = cml_string_debug(cml_string_temp(&_a, "Hello, world!"), &string, true);
    }
    cml_string_destroy(&string);
    return result;
}


CML_TestResult test_string_ncopy(void) {
    CML_Allocator _a = CML_ALLOCATOR_DEFAULT;
    CML_String string;
    cml_string_init0(&_a, &string);
    cml_string_ncopy(cml_string_temp(&_a, "Hello, world!"), 6, &string);
    CML_TestResult result;
    result.passed = cml_string_eq(cml_string_temp(&_a, "Hello,"), &string);
    if (!result.passed) {
        result.debugMessage = cml_string_debug(cml_string_temp(&_a, "Hello,"), &string, true);
    }
    cml_string_destroy(&string);
    return result;
}


CML_TestResult test_string_copy_char(void) {
    CML_Allocator _a = CML_ALLOCATOR_DEFAULT;
    CML_String string;
    cml_string_init0(&_a, &string);
    cml_string_copy_char("Hello, world!", &string);
    CML_TestResult result;
    result.passed = cml_string_eq(cml_string_temp(&_a, "Hello, world!"), &string);
    if (!result.passed) {
        result.debugMessage = cml_string_debug(cml_string_temp(&_a, "Hello, world!"), &string, true);
    }
    cml_string_destroy(&string);
    return result;
}


CML_TestResult test_string_ncopy_char(void) {
    CML_Allocator _a = CML_ALLOCATOR_DEFAULT;
    CML_String string;
    cml_string_init0(&_a, &string);
    cml_string_ncopy_char("Hello, world!", 6, &string);
    CML_TestResult result;
    result.passed = cml_string_eq(cml_string_temp(&_a, "Hello,"), &string);
    if (!result.passed) {
        result.debugMessage = cml_string_debug(cml_string_temp(&_a, "Hello,"), &string, true);
    }
    cml_string_destroy(&string);
    return result;
}


CML_TestResult test_string_cat(void) {
    CML_Allocator _a = CML_ALLOCATOR_DEFAULT;
    CML_String string;
    cml_string_init(&_a, "Hello", &string);
    cml_string_cat(cml_string_temp(&_a, ", world!"), &string);
    CML_TestResult result;
    result.passed = cml_string_eq(cml_string_temp(&_a, "Hello, world!"), &string);
    if (!result.passed) {
        result.debugMessage = cml_string_debug(cml_string_temp(&_a, "Hello, world!"), &string, true);
    }
    cml_string_destroy(&string);
    return result;
}


CML_TestResult test_string_ncat(void) {
    CML_Allocator _a = CML_ALLOCATOR_DEFAULT;
    CML_String string;
    cml_string_init(&_a, "Hello", &string);
    cml_string_ncat(cml_string_temp(&_a, ", world!"), 3, &string);
    CML_TestResult result;
    result.passed = cml_string_eq(cml_string_temp(&_a, "Hello, w"), &string);
    if (!result.passed) {
        result.debugMessage = cml_string_debug(cml_string_temp(&_a, "Hello, w"), &string, true);
    }
    cml_string_destroy(&string);
    return result;
}


CML_TestResult test_string_cat_char(void) {
    CML_Allocator _a = CML_ALLOCATOR_DEFAULT;
    CML_String string;
    cml_string_init(&_a, "Hello", &string);
    cml_string_cat_char(", world!", &string);
    CML_TestResult result;
    result.passed = cml_string_eq_char(&string, "Hello, world!");
    if (!result.passed) {
        result.debugMessage = cml_string_debug(cml_string_temp(&_a, "Hello, world!"), &string, true);
    }
    cml_string_destroy(&string);
    return result;
}


CML_TestResult test_string_ncat_char(void) {
    CML_Allocator _a = CML_ALLOCATOR_DEFAULT;
    CML_String string;
    cml_string_init(&_a, "Hello", &string);
    cml_string_ncat_char(", world!", 3, &string);
    CML_TestResult result;
    result.passed = cml_string_eq_char(&string, "Hello, w");
    if (!result.passed) {
        result.debugMessage = cml_string_debug(cml_string_temp(&_a, "Hello, w"), &string, true);
    }
    cml_string_destroy(&string);
    return result;
}



void cml_register_string_tests(CML_Test *registry, u32 *count) {
    cml_test_register(registry, count, test_string_temp, "test_string_temp");
    cml_test_register(registry, count, test_string_checkref, "test_string_checkref");
    cml_test_register(registry, count, test_string_copy, "test_string_copy");
    cml_test_register(registry, count, test_string_ncopy, "test_string_ncopy");
    cml_test_register(registry, count, test_string_copy_char, "test_string_copy_char");
    cml_test_register(registry, count, test_string_ncopy_char, "test_string_ncopy_char");
    cml_test_register(registry, count, test_string_cat, "test_string_cat");
    cml_test_register(registry, count, test_string_ncat, "test_string_ncat");
    cml_test_register(registry, count, test_string_cat_char, "test_string_cat_char");
    cml_test_register(registry, count, test_string_ncat_char, "test_string_ncat_char");
}
