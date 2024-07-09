/**
 * @file cml_cblas_drotg.c
 * 
 * @brief DROTG subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/d_cblas.h"


extern void drotg_(f64 *a, f64 *b, f64 *c, f64 *s);

void cml_cblas_drotg(f64 *a, f64 *b, f64 *c, f64 *s) {
    drotg_(a, b, c, s);
}

