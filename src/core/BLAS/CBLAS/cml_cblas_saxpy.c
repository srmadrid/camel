/**
 * @file cml_cblas_saxpy.c
 * 
 * @brief SAXPY subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/s_cblas.h"


extern void saxpy_(const i32 *n, const f32 *a, const f32 *x, const i32 *incx, f32 *y, const i32 *incy);

void cml_cblas_saxpy(const i32 n, const f32 a, const f32 *x, const i32 incx, f32 *y, const i32 incy) {
    saxpy_(&n, &a, x, &incx, y, &incy);
}

