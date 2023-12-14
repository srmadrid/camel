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
    CML_Test registry;
    u32 count;
    u32 expectedCount = 100;

    cml_test_init(&registry, &count, expectedCount);

    cml_register_all_tests(&registry, &count);

    cml_run_tests(&registry, count);
    
    return 0;
}