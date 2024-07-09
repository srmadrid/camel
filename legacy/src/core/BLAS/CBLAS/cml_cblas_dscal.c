/**
 * @file cml_cblas_dscal.c
 * 
 * @brief DSCAL subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/d_cblas.h"


extern void dscal_(const i32 *n, const f64 *a, f64 *x, const i32 *incx);

void cml_cblas_dscal(const i32 n, const f64 a, f64 *x, const i32 incx) {
    dscal_(&n, &a, x, &incx);
}

