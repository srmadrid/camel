/**
 * @file cml_cblas_dsdot.c
 * 
 * @brief DSDOT subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 10/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/d_cblas.h"


extern f64 dsdot_(const i32 *n, const f32 *sx, const i32 *incx, const f32 *sy, const i32 *incy);

f64 cml_cblas_dsdot(const i32 n, const f32 *sx, const i32 incx, const f32 *sy, const i32 incy) {
    return dsdot_(&n, sx, &incx, sy, &incy);
}

