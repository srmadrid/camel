/**
 * @file cml_cblas_sdsdot.c
 * 
 * @brief SDSDOT subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 10/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/s_cblas.h"


extern f32 sdsdot_(const i32 *n, const f32 *sb, const f32 *sx, const i32 *incx, const f32 *sy, const i32 *incy);

f32 cml_cblas_sdsdot(const i32 n, const f32 sb, const f32 *sx, const i32 incx, const f32 *sy, const i32 incy) {
    return sdsdot_(&n, &sb, sx, &incx, sy, &incy);
}

