/**
 * @file fvector_sse.h
 * 
 * @brief Declarations and implementations for the fixed vector manipulation 
 *        functions of CAMEL, with SSE support.
 * 
 * @author Sergio Madrid
 * @date 2/1/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_FIXED_VECTOR_SSE
#define CAMEL_FIXED_VECTOR_SSE


#include "fvector.h"


/**
 * @brief Adds two CML_Vector4 and writes the result to the out CML_Vector4.
 *
 * @param v   The left vector operand.
 * @param w   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_sse_vector4_add(CML_Vector4 *v, CML_Vector4 *w, CML_Vector4 *out) {
    out->sse = _mm_add_ps(v->sse, w->sse);
}


/**
 * @brief Adds a scalar to all CML_Vector4 and writes the result to the out
 *        CML_Vector4.
 *
 * @param v   The vector operand.
 * @param t   The scalar.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_sse_vector4_add_f32(CML_Vector4 *v, f32 t, CML_Vector4 *out) {
    __m128 tSSE = _mm_set1_ps(t);
    out->sse = _mm_add_ps(v->sse, tSSE);
}


/**
 * @brief Subtracts two CML_Vector4 and writes the result to the out 
 *        CML_Vector4.
 *
 * @param v   The left vector operand.
 * @param w   The right vector operand.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_sse_vector4_sub(CML_Vector4 *v, CML_Vector4 *w, CML_Vector4 *out) {
    out->sse = _mm_sub_ps(v->sse, w->sse);
}


/**
 * @brief Subtracts a scalar to all CML_Vector4 and writes the result to the out
 *        CML_Vector4.
 *
 * @param v   The vector operand.
 * @param t   The scalar.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_sse_vector4_sub_f32(CML_Vector4 *v, f32 t, CML_Vector4 *out) {
    __m128 tSSE = _mm_set1_ps(t);
    out->sse = _mm_sub_ps(v->sse, tSSE);
}


/**
 * @brief Multiplies a CML_Vector4 by a scalar, and writes the result to the out 
 *        CML_Vector4.
 *
 * @param v   The vector operand.
 * @param t   The scalar.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_sse_vector4_scale(CML_Vector4 *v, f32 t, CML_Vector4 *out) {
    __m128 tSSE = _mm_set1_ps(t);
    out->sse = _mm_mul_ps(v->sse, tSSE);
}


/**
 * @brief Calculates the modulus of the input CML_Vector4.
 *
 * @param v The input vector.
 * 
 * @return The modulus of the input CML_Vector4.
 */
CAMEL_STATIC CAMEL_API f32 cml_sse_vector4_mod(CML_Vector4 *v) {
    __m128 v2 = _mm_mul_ps(v->sse, v->sse);
    __m128 sum = _mm_hadd_ps(v2, v2);
    sum = _mm_hadd_ps(sum, sum);
    __m128 sumsqrt = _mm_sqrt_ss(sum);
    return _mm_cvtss_f32(sumsqrt);
}


/**
 * @brief Calculates the squared modulus of the input CML_Vector4.
 *
 * @param v The input vector.
 * 
 * @return The squared modulus of the input CML_Vector4.
 */
CAMEL_STATIC CAMEL_API f32 cml_sse_vector4_mod2(CML_Vector4 *v) {
    __m128 v2 = _mm_mul_ps(v->sse, v->sse);
    __m128 sum = _mm_hadd_ps(v2, v2);
    sum = _mm_hadd_ps(sum, sum);
    return _mm_cvtss_f32(sum);
}


/**
 * @brief Normalizes the input CML_Vector4 and writes it to the out CML_Vector4.
 *
 * @param v   The input vector.
 * @param out The output vector.
 * 
 * @return void.
 */
CAMEL_STATIC CAMEL_API void cml_sse_vector4_norm(CML_Vector4 *v, CML_Vector4 *out) {
    __m128 v2 = _mm_mul_ps(v->sse, v->sse);
    __m128 sum = _mm_hadd_ps(v2, v2);
    sum = _mm_hadd_ps(sum, sum);
    __m128 sumsqrt = _mm_sqrt_ss(sum);
    __m128 sumsqrt2 = _mm_shuffle_ps(sumsqrt, sumsqrt, _MM_SHUFFLE(0, 0, 0, 0));
    out->sse = _mm_div_ps(v->sse, sumsqrt2);
}


#endif /* CAMEL_FIXED_VECTOR_SSE */
