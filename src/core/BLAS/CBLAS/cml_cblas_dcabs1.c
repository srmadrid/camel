/**
 * @file cml_cblas_dcabs1.c
 * 
 * @brief DCABS1 subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 11/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/z_cblas.h"


extern f64 dcabs1_(const void *z);

f64 cml_cblas_dcabs1(const void *z) {
    return dcabs1_(z);
}

