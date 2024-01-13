/**
 * @file flinear.h
 * 
 * @brief Main entry point for the fixed size linear algebra module of CAMEL.
 * 
 * @note This module is offered as header-only or compiled versions.
 *
 * @author Sergio Madrid
 * @date 25/12/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_FIXED_LINEAR_ALGEBRA
#define CAMEL_FIXED_LINEAR_ALGEBRA


#if defined(__AVX__) && defined(__SSE__)
    #define CML_USE_AVX
    #define CML_USE_SSE
#elif defined(__AVX__)
    #define CML_USE_AVX
#elif defined(__SSE__)
    #define CML_USE_SSE
#elif defined(__ARM_NEON) || defined(__ARM_NEON__)
    #define CML_USE_NEON
#endif


#include "fvector.h"
#include "cfvector.h"
#include "fmatrix.h"
#include "cfmatrix.h"
/*
#ifdef CML_USE_AVX
    #include "fvector_avx.h"
    #include "cfvector_avx.h"
    #include "fmatrix_avx.h"
    #include "cfmatrix_avx.h"
#endif
#ifdef CML_USE_SSE
    #include "fvector_sse.h"
    #include "cfvector_sse.h"
    #include "fmatrix_sse.h"
    #include "cfmatrix_sse.h"
#endif
#ifdef CML_USE_NEON
    #include "fvector_neon.h"
    #include "cfvector_neon.h"
    #include "fmatrix_neon.h"
    #include "cfmatrix_neon.h"
#endif */

#endif /* CAMEL_FIXED_LINEAR_ALGEBRA */