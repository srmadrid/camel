/**
 * @file cml_cblas_isamax.c
 * 
 * @brief ISAMAX subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 11/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/s_cblas.h"


extern i32 isamax_(const i32 *n, const f32 *x, const i32 *incx);

i32 cml_cblas_isamax(const i32 n, const f32 *x, const i32 incx) {
    return isamax_(&n, x, &incx);
}

