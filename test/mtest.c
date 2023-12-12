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


#define CML_TEST_ENABLED
#include "../../../include/camel.h"


int main() {
    runTests();
    return 0;
}