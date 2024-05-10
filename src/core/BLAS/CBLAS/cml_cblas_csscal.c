/**
 * @file cml_cblas_csscal.c
 * 
 * @brief CSSCAL subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/c_cblas.h"


extern void csscal_(const i32 *n, const f32 *a, void *x, const i32 *incx);

void cml_cblas_csscal(const i32 n, const f32 a, void *x, const i32 incx) {
    csscal_(&n, &a, x, &incx);
}

