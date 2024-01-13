/**
 * @file test.h
 * 
 * @brief Testing suite for the Camel library.
 *
 * @author Sergio Madrid
 * @date 12/12/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_TEST
#define CAMEL_TEST


#include <stdio.h>
#include <stdlib.h>

#include "macros.h"
#include "err.h"


/**
 * @brief Represents the result of a test.
 */
typedef struct CML_TestResult {
    b8 passed;
    char *debugMessage;
} CML_TestResult;


/**
 * @brief Represents a function pointer for a test function.
 */
typedef CML_TestResult (*CML_TestFunction)();


/**
 * @brief Represents a test case, including the test function and its name.
 */
typedef struct CML_Test {
    CML_TestFunction func;
    const char *name;
} CML_Test;


/**
 * @brief Initializes the test registry.
 * 
 * @param registry      The test registry to initialize.
 * @param count         The number of tests.
 * @param expectedCount The number of tests to expect.
 * 
 * @return Status code.
 */
CML_Status cml_test_init(CML_Test *registry, u32 *count, u32 expectedCount);


/**
 * @brief Registers a test function.
 * 
 * @param testRegistry  The test registry to register the test function to.
 * @param testCount     The number of tests.
 * @param func          The test function to register.
 * @param name          The name of the test function.
 * 
 * @return void.
 */
void cml_test_register(CML_Test *testRegistry, u32 *testCount, CML_TestFunction func, const char *name);


/**
 * @brief Runs all tests in the test registry.
 * 
 * @param testRegistry  The test registry to run.
 * @param testCount     The number of tests.
 * 
 * @return void.
 */
void cml_run_tests(CML_Test *testRegistry, u32 testCount);


#endif /* CAMEL_TEST */
