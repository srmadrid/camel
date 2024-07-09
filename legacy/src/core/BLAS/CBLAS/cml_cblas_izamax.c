/**
 * @file cml_cblas_izamax.c
 * 
 * @brief IZAMAX subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 11/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/z_cblas.h"


extern i32 izamax_(const i32 *n, const void *x, const i32 *incx);

i32 cml_cblas_izamax(const i32 n, const void *x, const i32 incx) {
    return izamax_(&n, x, &incx);
}

