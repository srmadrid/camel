/******************************************************************************
 * Filename: tlinear.c
 * 
 * Description:
 *      Test file for the linear algebra module.
 *
 * Author: Sergio Madrid
 * Created on: 14/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include "../../../include/camel.h"


void cml_register_vector_tests(CML_Test *registry, u32 *count);
void cml_register_matrix_tests(CML_Test *registry, u32 *count);


void cml_register_linear_tests(CML_Test *registry, u32 *count) {
    cml_register_vector_tests(registry, count);
    cml_register_matrix_tests(registry, count);
}
