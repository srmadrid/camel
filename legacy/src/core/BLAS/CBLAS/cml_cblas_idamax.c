/**
 * @file cml_cblas_idamax.c
 * 
 * @brief IDAMAX subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 11/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/d_cblas.h"


extern i32 idamax_(const i32 *n, const f64 *x, const i32 *incx);

i32 cml_cblas_idamax(const i32 n, const f64 *x, const i32 incx) {
    return idamax_(&n, x, &incx);
}

