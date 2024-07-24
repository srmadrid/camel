/**
 * @file cml_cblas_scabs1.c
 * 
 * @brief SCABS1 subroutine C wrapper.
 *
 * @author Sergio Madrid
 * @date 11/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/core/BLAS/c_cblas.h"


extern f32 scabs1_(const void *z);

f32 cml_cblas_scabs1(const void *z) {
    return scabs1_(z);
}

