/**
 * @file cml_cblas_daxpy.c
 * 
 * @brief DAXPY subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/d_cblas.h"


extern void daxpy_(const i32 *n, const f64 *a, const f64 *x, const i32 *incx, f64 *y, const i32 *incy);

void cml_cblas_daxpy(const i32 n, const f64 a, const f64 *x, const i32 incx, f64 *y, const i32 incy) {
    daxpy_(&n, &a, x, &incx, y, &incy);
}

