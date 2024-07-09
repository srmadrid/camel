/**
 * @file cml_cblas_srot.c
 * 
 * @brief SROT subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/s_cblas.h"


extern void srot_(const i32 *n, f32 *x, const i32 *incx, f32 *y, const i32 *incy, const f32 *c, const f32 *s);

void cml_cblas_srot(const i32 n, f32 *x, const i32 incx, f32 *y, const i32 incy, const f32 c, const f32 s) {
    srot_(&n, x, &incx, y, &incy, &c, &s);
}

