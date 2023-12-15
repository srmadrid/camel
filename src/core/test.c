/******************************************************************************
 * Filename: test.c
 * 
 * Description:
 *      Implementations for the testing suite of CAMEL.
 *
 * Author: Sergio Madrid
 * Created on: 14/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include "../../include/core/test.h"


CML_Status cml_test_init(CML_Test *registry, u32 *count, u32 expectedCount) {
    registry = (CML_Test *)malloc(sizeof(CML_Test) * expectedCount);
    if (registry == NULL || count == NULL)
        return CML_ERR_NULL_PTR;
    *count = 0;
}


void cml_test_register(CML_Test *testRegistry, u32 *testCount, CML_TestFunction func, const char *name) {
    testRegistry[*testCount].func = func;
    testRegistry[*testCount].name = name;
    (*testCount)++;
}


void cml_run_tests(CML_Test *testRegistry, u32 testCount) {
    u32 passedCount = 0;
    u32 failedCount = 0;
    u32 *failed = (u32 *)malloc(sizeof(u32) * testCount);
    if (failed == NULL) {
        printf("Failed to allocate memory for failed tests.\n");
        return;
    }
    for (int i = 0; i < testCount; i++) {
        printf("[%i/%i] Running test: %s\n", i + 1, testCount, testRegistry[i].name);
        CML_TestResult result = testRegistry[i].func();
        if (result.passed == CAMEL_TRUE) {
            printf("\t%sPASSED%s\n\n", CML_TERMINAL_GREEN, CML_TERMINAL_RESET);
            passedCount++;
        } else {
            printf("\t%sFAILED%s\n", CML_TERMINAL_RED, CML_TERMINAL_RESET);
            printf("%s\n", result.debugMessage);
            failed[failedCount++] = i;
        }
    }
    printf("Passed [%i/%i] tests.\n", passedCount, testCount);

    if (passedCount != testCount){
        printf("Failed tests:\n");
        for (int i = 0; i < failedCount; i++) {
            printf("\t[%i]: %s\n",failed[i] + 1, testRegistry[failed[i]].name);
        }
    }
}
