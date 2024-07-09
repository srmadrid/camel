/**
 * @file cml_cblas_zdrot.c
 * 
 * @brief ZDROT subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/z_cblas.h"


extern void zdrot_(const i32 *n, void *x, const i32 *incx, void *y, const i32 *incy, const f64 *c, const f64 *s);

void cml_cblas_zdrot(const i32 n, void *x, const i32 incx, void *y, const i32 incy, const f64 c, const f64 s) {
    zdrot_(&n, x, &incx, y, &incy, &c, &s);
}

