/**
 * @file cml_cblas_drotm.c
 * 
 * @brief DROTM subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/d_cblas.h"


extern void drotm_(const i32 *n, f64 *x, const i32 *incx, f64 *y, const i32 *incy, const f64 *param);

void cml_cblas_drotm(const i32 n, f64 *x, const i32 incx, f64 *y, const i32 incy, const f64 *param) {
    drotm_(&n, x, &incx, y, &incy, param);
}

