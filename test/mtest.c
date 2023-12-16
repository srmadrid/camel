/******************************************************************************
 * Filename: mtest.c
 * 
 * Description:
 *      Main test file for the project. This file runs all tests for all modules
 *      in the project.
 *
 * Author: Sergio Madrid
 * Created on: 12/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include "../include/camel.h"


void cml_register_algebra_tests(CML_Test *registry, u32 *count);


void cml_register_all_tests(CML_Test *registry, u32 *count) {
    cml_register_algebra_tests(registry, count);
}


int main() {
    u32 count = 0;
    u32 expectedCount = 200;
    CML_Test registry[expectedCount];

    // cml_test_init(&registry, &count, expectedCount);
    // Better create the registry on the stack, so we 
    // don't have to free it.

    cml_register_all_tests(&registry, &count);

    cml_run_tests(&registry, count);
    
    return 0;
}