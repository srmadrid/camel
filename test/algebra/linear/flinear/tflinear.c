/******************************************************************************
 * Filename: tflinear.c
 * 
 * Description:
 *      Test file for the fixed linear algebra module.
 *
 * Author: Sergio Madrid
 * Created on: 25/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include "../../../../include/camel.h"


void cml_register_fvector_tests(CML_Test *registry, u32 *count);
void cml_register_cfvector_tests(CML_Test *registry, u32 *count);
void cml_register_fmatrix_tests(CML_Test *registry, u32 *count);
void cml_register_cfmatrix_tests(CML_Test *registry, u32 *count);
void cml_register_sse_fvector_tests(CML_Test *registry, u32 *count);


void cml_register_flinear_tests(CML_Test *registry, u32 *count) {
    cml_register_fvector_tests(registry, count);
    cml_register_cfvector_tests(registry, count);
    cml_register_fmatrix_tests(registry, count);
    cml_register_cfmatrix_tests(registry, count);
#ifdef CML_USE_SSE
    //cml_register_sse_fvector_tests(registry, count);
#endif
}
