/**
 * @file cml_cblas_zswap.c
 * 
 * @brief ZSWAP subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/z_cblas.h"


extern void zswap_(const i32 *n, void *x, const i32 *incx, void *y, const i32 *incy);

void cml_cblas_zswap(const i32 n, void *x, const i32 incx, void *y, const i32 incy) {
    zswap_(&n, x, &incx, y, &incy);
}

