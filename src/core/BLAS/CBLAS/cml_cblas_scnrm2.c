/**
 * @file cml_cblas_scnrm2.c
 * 
 * @brief SCNRM2 subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 10/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/c_cblas.h"


f32 scnrm2_(const i32 *n, const void *x, const i32 *incx);

f32 cml_cblas_scnrm2(const i32 n, const void *x, const i32 incx) {
    return scnrm2_(&n, x, &incx);
}

