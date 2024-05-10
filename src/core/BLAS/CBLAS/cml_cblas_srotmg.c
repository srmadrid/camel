/**
 * @file cml_cblas_srotmg.c
 * 
 * @brief SROTMG subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/s_cblas.h"


extern void srotmg_(f32 *d1, f32 *d2, f32 *x1, const f32 *y1, f32 *param);

void cml_cblas_srotmg(f32 *d1, f32 *d2, f32 *x1, const f32 y1, f32 *param) {
    srotmg_(d1, d2, x1, &y1, param);
}

