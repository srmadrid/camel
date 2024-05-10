/**
 * @file cml_cblas_sswap.c
 * 
 * @brief SSWAP subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/s_cblas.h"


extern void sswap_(const i32 *n, f32 *x, const i32 *incx, f32 *y, const i32 *incy);

void cml_cblas_sswap(const i32 n, f32 *x, const i32 incx, f32 *y, const i32 incy) {
    sswap_(&n, x, &incx, y, &incy);
}

