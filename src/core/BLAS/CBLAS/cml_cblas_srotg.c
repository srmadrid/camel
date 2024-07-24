/**
 * @file cml_cblas_srotg.c
 * 
 * @brief SROTG subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/s_cblas.h"


extern void srotg_(f32 *a, f32 *b, f32 *c, f32 *s);

void cml_cblas_srotg(f32 *a, f32 *b, f32 *c, f32 *s) {
    srotg_(a, b, c, s);
}

