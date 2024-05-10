/**
 * @file cml_cblas_ddot.c
 * 
 * @brief DDOT subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 10/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/d_cblas.h"


extern f64 ddot_(const i32 *n, const f64 *x, const i32 *incx, const f64 *y, const i32 *incy);

f64 cml_cblas_ddot(const i32 n, const f64 *x, const i32 incx, const f64 *y, const i32 incy) {
    return ddot_(&n, x, &incx, y, &incy);
}

