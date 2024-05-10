/**
 * @file cml_cblas_zdotc_sub.c
 * 
 * @brief ZDOTC subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 10/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/z_cblas.h"


extern void zdotc_(const i32 *n, const void *x, const i32 *incx, const void *y, const i32 *incy, void *dotc);

void cml_cblas_zdotc_sub(const i32 n, const void *x, const i32 incx, const void *y, const i32 incy, void *dotc) {
    zdotc_(&n, x, &incx, y, &incy, dotc);
}

