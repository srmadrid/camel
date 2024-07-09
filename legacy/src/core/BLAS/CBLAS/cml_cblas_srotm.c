/**
 * @file cml_cblas_srotm.c
 * 
 * @brief SROTM subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/s_cblas.h"


extern void srotm_(const i32 *n, f32 *x, const i32 *incx, f32 *y, const i32 *incy, const f32 *param);

void cml_cblas_srotm(const i32 n, f32 *x, const i32 incx, f32 *y, const i32 incy, const f32 *param) {
    srotm_(&n, x, &incx, y, &incy, param);
}

