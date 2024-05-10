/**
 * @file cml_cblas_sasum.c
 * 
 * @brief SASUM subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 10/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/s_cblas.h"


f32 sasum_(const i32 *n, const f32 *x, const i32 *incx);

f32 cml_cblas_sasum(const i32 n, const f32 *x, const i32 incx) {
    return sasum_(&n, x, &incx);
}

