/**
 * @file cml_cblas_icamax.c
 * 
 * @brief ICAMAX subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 11/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/c_cblas.h"


extern i32 icamax_(const i32 *n, const void *x, const i32 *incx);

i32 cml_cblas_icamax(const i32 n, const void *x, const i32 incx) {
    return icamax_(&n, x, &incx);
}

