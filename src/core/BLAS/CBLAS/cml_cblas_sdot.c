/**
 * @file cml_cblas_sdot.c
 * 
 * @brief SDOT subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 10/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/s_cblas.h"


extern f32 sdot_(const i32 *n, const f32 *x, const i32 *incx, const f32 *y, const i32 *incy);

f32 cml_cblas_sdot(const i32 n, const f32 *x, const i32 incx, const f32 *y, const i32 incy) {
    return sdot_(&n, x, &incx, y, &incy);
}

