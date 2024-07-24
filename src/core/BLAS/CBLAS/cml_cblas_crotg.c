/**
 * @file cml_cblas_crotg.c
 * 
 * @brief CROTG subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/c_cblas.h"


extern void crotg_(void *a, void *b, f32 *c, void *s);

void cml_cblas_crotg(void *a, void *b, f32 *c, void *s) {
    crotg_(a, b, c, s);
}

