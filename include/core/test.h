/******************************************************************************
 * Filename: test.h
 * 
 * Description:
 *      Testing suite for the Camel library.
 *
 * Author: Sergio Madrid
 * Created on: 12/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/

#ifdef CAMEL_TEST_ENABLED
#ifndef CAMEL_TEST
#define CAMEL_TEST


#include <stdio.h>

#include "core.h"


/******************************************************************************
 * Type: CML_TestFunction
 * 
 * Description:
 *      Represents a function pointer for a test function.
 *****************************************************************************/
typedef void (*CML_TestFunction)();


/******************************************************************************
 * Type: CML_Test
 * 
 * Description:
 *      Represents a test case, including the test function and its name.
 *****************************************************************************/
typedef struct {
    CML_TestFunction func;
    const char *name;
} CML_Test;

CML_Test testRegistry[100];
u32 testCount = 0;


/******************************************************************************
 * Function: cml_register_test
 * 
 * Description:
 *      Registers a test function and its name to the test registry.
 * 
 * Parameters:
 *      TestFunc func - The test function to register.
 *      const char *name - The name of the test function.
 *****************************************************************************/
void cml_register_test(CML_TestFunction func, const char *name) {
    testRegistry[testCount].func = func;
    testRegistry[testCount].name = name;
    testCount++;
}


/******************************************************************************
 * Function: cml_run_tests
 * 
 * Description:
 *      Runs all registered test functions.
 *****************************************************************************/
void cml_run_tests() {
    for (int i = 0; i < testCount; i++) {
        printf("Running test: %s\n", testRegistry[i].name);
        testRegistry[i].func();
    }
}


/******************************************************************************
 * Macro: CML_TEST
 * 
 * Description:
 *      Declares, registers, and defines a test function.
 *****************************************************************************/
#define CML_TEST(name) void name(); cml_register_test(name, #name); void name()


/******************************************************************************
 * Macro: CML_ASSERT
 * 
 * Description:
 *      Checks a condition and if it's not met, prints an error message and 
 *      returns from the function.
 *****************************************************************************/
#define CML_ASSERT(cond) if (cond != CAMEL_TRUE) { printf("Assertion failed: %s\n", #cond); return; }


#endif /* CAMEL_TEST */
#endif /* CAMEL_TEST_ENABLED */
