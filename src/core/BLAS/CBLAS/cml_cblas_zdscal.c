/**
 * @file cml_cblas_zdscal.c
 * 
 * @brief ZDSCAL subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/z_cblas.h"


extern void zdscal_(const i32 *n, const f64 *a, void *x, const i32 *incx);

void cml_cblas_zdscal(const i32 n, const f64 a, void *x, const i32 incx) {
    zdscal_(&n, &a, x, &incx);
}

