/**
 * @file cml_cblas_cdotu_sub.c
 * 
 * @brief CDOTU subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 10/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/c_cblas.h"


extern void cdotu_(const i32 *n, const void *x, const i32 *incx, const void *y, const i32 *incy, void *dotu);

void cml_cblas_cdotu_sub(const i32 n, const void *x, const i32 incx, const void *y, const i32 incy, void *dotu) {
    cdotu_(&n, x, &incx, y, &incy, dotu);
}

