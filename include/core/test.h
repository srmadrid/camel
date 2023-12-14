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

#ifndef CAMEL_TEST
#define CAMEL_TEST


#include <stdio.h>
#include <stdlib.h>

#include "core.h"


/******************************************************************************
 * Type: CML_TestResult
 * 
 * Description:
 *      Represents the result of a test.
 *****************************************************************************/
typedef struct {
    CML_Bool passed;
    char *debugMessage;
} CML_TestResult;


/******************************************************************************
 * Type: CML_TestFunction
 * 
 * Description:
 *      Represents a function pointer for a test function.
 *****************************************************************************/
typedef CML_TestResult (*CML_TestFunction)();


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


/******************************************************************************
 * Function: cml_test_init
 * 
 * Description:
 *      Initializes the test registry.
 *****************************************************************************/
CAMEL_API CML_Status cml_test_init(CML_Test *registry, u32 *count, u32 expectedCount);


/******************************************************************************
 * Function: cml_test_register
 * 
 * Description:
 *      Registers a test function and its name to the test registry.
 *
 * Parameters:
 *      TestFunc func - The test function to register.
 *      const char *name - The name of the test function.
 *****************************************************************************/
CAMEL_API void cml_test_register(CML_Test *testRegistry, u32 *testCount, CML_TestFunction func, const char *name);


/******************************************************************************
 * Function: cml_run_tests
 * 
 * Description:
 *      Runs all registered test functions.
 *****************************************************************************/
CAMEL_API void cml_run_tests(CML_Test *testRegistry, u32 testCount);


#endif /* CAMEL_TEST */
