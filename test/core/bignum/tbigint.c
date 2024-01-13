/**
 * @file tbigint.c
 * 
 * @brief Test file for the bigint module.
 *
 * @author Sergio Madrid
 * @date 17/12/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/camel.h"


CML_TestResult test_bigint_set_int() {
    CML_BigInt bigint;
    cml_bigint_init(0, &bigint);
    char *expected = "200345";
    cml_bigint_set_int(200345, 1, &bigint);
    CML_TestResult result;
    result.passed = cml_bigint_eq_int(&bigint, 200345, 1);
    if (!result.passed) {
        result.debugMessage = cml_bigint_debug(expected, &bigint);
    }
    cml_bigint_free(&bigint);
    return result;
}



void cml_register_bigint_tests(CML_Test *registry, u32 *count) {
    cml_test_register(registry, count, test_bigint_set_int, "test_bigint_set_int");
}
