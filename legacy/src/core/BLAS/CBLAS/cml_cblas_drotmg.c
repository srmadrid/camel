/**
 * @file cml_cblas_drotmg.c
 * 
 * @brief DROTMG subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/d_cblas.h"


extern void drotmg_(f64 *d1, f64 *d2, f64 *x1, const f64 *y1, f64 *param);

void cml_cblas_drotmg(f64 *d1, f64 *d2, f64 *x1, const f64 y1, f64 *param) {
    drotmg_(d1, d2, x1, &y1, param);
}

