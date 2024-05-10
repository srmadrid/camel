/**
 * @file cml_cblas_cscal.c
 * 
 * @brief CSCAL subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/c_cblas.h"


extern void cscal_(const i32 *n, const void *a, void *x, const i32 *incx);

void cml_cblas_cscal(const i32 n, const void *a, void *x, const i32 incx) {
    cscal_(&n, a, x, &incx);
}

