/**
 * @file s_cblas.h
 * 
 * @brief Declaration of Camel's BLAS single precision C wrapper.
 *
 * @author Sergio Madrid
 * @date 9/5/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_S_CBLAS
#define CAMEL_S_CBLAS


#include "../macros.h"


/**
 * @brief Computes the parameters for a Givens rotation.
 *
 * @param a [in] Provides the x-coordinate of the point p.
 * @param b [in] Provides the y-coordinate of the point p.
 *
 * @param a [out] Contains the parameter r associated with the Givens rotation.
 * @param b [out] Contains the parameter z associated with the Givens rotation.
 * @param c [out] Contains the parameter c associated with the Givens rotation.
 * @param s [out] Contains the parameter s associated with the Givens rotation.
 *
 * @return Void.
 */
void cml_cblas_srotg(f32 *a, f32 *b, f32 *c, f32 *s);


#endif /* CAMEL_S_CBLAS */
