/******************************************************************************
 * Filename: tcore.c
 * 
 * Description:
 *      Test file for the core module.
 *
 * Author: Sergio Madrid
 * Created on: 17/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include "../../include/camel.h"


void cml_register_bignum_tests(CML_Test *registry, u32 *count);


void cml_register_core_tests(CML_Test *registry, u32 *count) {
    cml_register_bignum_tests(registry, count);
}