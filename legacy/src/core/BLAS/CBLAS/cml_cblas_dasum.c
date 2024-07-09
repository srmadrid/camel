/**
 * @file cml_cblas_dasum.c
 * 
 * @brief DASUM subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 10/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/d_cblas.h"


f64 dasum_(const i32 *n, const f64 *x, const i32 *incx);

f64 cml_cblas_dasum(const i32 n, const f64 *x, const i32 incx) {
    return dasum_(&n, x, &incx);
}

