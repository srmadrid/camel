/**
 * @file cml_cblas_drot.c
 * 
 * @brief DROT subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/d_cblas.h"


extern void drot_(const i32 *n, f64 *x, const i32 *incx, f64 *y, const i32 *incy, const f64 *c, const f64 *s);

void cml_cblas_drot(const i32 n, f64 *x, const i32 incx, f64 *y, const i32 incy, const f64 c, const f64 s) {
    drot_(&n, x, &incx, y, &incy, &c, &s);
}

