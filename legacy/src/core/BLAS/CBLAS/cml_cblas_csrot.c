/**
 * @file cml_cblas_csrot.c
 * 
 * @brief CSROT subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/c_cblas.h"


extern void csrot_(const i32 *n, void *x, const i32 *incx, void *y, const i32 *incy, const f32 *c, const f32 *s);

void cml_cblas_csrot(const i32 n, void *x, const i32 incx, void *y, const i32 incy, const f32 c, const f32 s) {
    csrot_(&n, x, &incx, y, &incy, &c, &s);
}

