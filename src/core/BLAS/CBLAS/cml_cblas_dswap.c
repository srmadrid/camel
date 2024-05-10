/**
 * @file cml_cblas_dswap.c
 * 
 * @brief DSWAP subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/d_cblas.h"


extern void dswap_(const i32 *n, f64 *x, const i32 *incx, f64 *y, const i32 *incy);

void cml_cblas_dswap(const i32 n, f64 *x, const i32 incx, f64 *y, const i32 incy) {
    dswap_(&n, x, &incx, y, &incy);
}

