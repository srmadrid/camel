/**
 * @file cml_cblas_dzasum.c
 * 
 * @brief DZASUM subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 10/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/z_cblas.h"


f64 dzasum_(const i32 *n, const void *x, const i32 *incx);

f64 cml_cblas_dzasum(const i32 n, const void *x, const i32 incx) {
    return dzasum_(&n, x, &incx);
}

