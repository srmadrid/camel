/**
 * @file camel.h
 * 
 * @brief Common includes.
 *
 * @author Sergio Madrid
 * @date 22/2/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CML_COMMON
#define CML_COMMON


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


#ifdef __GNUC__ // GCC, Clang, ICC
    #define unreachable() (__builtin_unreachable())
#else
    #ifdef _MSC_VER // MSVC
        #define unreachable() (__assume(0))
    #else
        [[noreturn]] inline void unreachable_impl() {}
        #define unreachable() (unreachable_impl())
    #endif
#endif


#endif /* CML_COMMON */
