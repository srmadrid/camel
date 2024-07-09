/**
 * @file cml_cblas_zrotg.c
 * 
 * @brief ZROTG subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/z_cblas.h"


extern void zrotg_(void *a, void *b, f64 *c, void *s);

void cml_cblas_zrotg(void *a, void *b, f64 *c, void *s) {
    zrotg_(a, b, c, s);
}

