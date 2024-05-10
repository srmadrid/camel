/**
 * @file cml_cblas_sscal.c
 * 
 * @brief SSCAL subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/s_cblas.h"


extern void sscal_(const i32 *n, const f32 *a, f32 *x, const i32 *incx);

void cml_cblas_sscal(const i32 n, const f32 a, f32 *x, const i32 incx) {
    sscal_(&n, &a, x, &incx);
}

