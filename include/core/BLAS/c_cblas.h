/**
 * @file c_cblas.h
 * 
 * @brief Declaration of Camel's BLAS single precision complex C wrapper.
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
void cml_cblas_crotg(void *a, void *b, f32 *c, void *s);


/**
 * @brief Performs rotation of points in the plane.
 *
 * @param n [in] Specifies the number of elements in vectors x and y. 
 * @param x [in] Array, size at least (1 + (n-1)*abs(incx)).
 * @param incx [in] Specifies the increment for the elements of x.
 * @param y [in] Array, size at least (1 + (n -1)*abs(incy)).
 * @param incy [in] Specifies the increment for the elements of y.
 * @param c [in] A scalar.
 * @param s [in] A scalar.
 *
 * @param x [out] Each element is replaced by c*x + s*y.
 * @param y [out] Each element is replaced by c*y - s*x, or by c*y-conj(s)*x if 
 *                s is a complex type.
 *
 * @return Void.
 */
void cml_cblas_csrot(const i32 n, void *x, const i32 incx, void *y, const i32 incy, const f32 c, const f32 s);


/**
 * @brief Swaps a vector with another vector.
 *
 * @param n [in] Specifies the number of elements in vectors x and y.
 * @param x [in] Array, size at least (1 + (n-1)*abs(incx)).
 * @param incx [in] Specifies the increment for the elements of x.
 * @param y [in] Array, size at least (1 + (n-1)*abs(incy)). 
 * @param incy [in] Specifies the increment for the elements of y.
 *
 * @param x [out] Contains the resultant vector x, that is, the input vector y.
 * @param y [out] Contains the resultant vector y, that is, the input vector x.
 *
 * @return Void.
 */
void cml_cblas_cswap(const i32 n, void *x, const i32 incx, void *y, const i32 incy);


/**
 * @brief Computes the product of a vector by a scalar.
 *
 * @param n [in] Specifies the number of elements in vector x.
 * @param a [in] Specifies the scalar a.
 * @param x [in] Array, size at least (1 + (n -1)*abs(incx)).
 * @param incx [in] Specifies the increment for the elements of x.
 *
 * @param x [out] Updated vector x.
 *
 * @return Void.
 */
void cml_cblas_cscal(const i32 n, const void *a, void *x, const i32 incx);


/**
 * @brief Computes the product of a vector by a scalar.
 *
 * @param n [in] Specifies the number of elements in vector x.
 * @param a [in] Specifies the scalar a.
 * @param x [in] Array, size at least (1 + (n -1)*abs(incx)).
 * @param incx [in] Specifies the increment for the elements of x.
 *
 * @param x [out] Updated vector x.
 *
 * @return Void.
 */
void cml_cblas_csscal(const i32 n, const f32 a, void *x, const i32 incx);


/**
 * @brief Copies a vector to another vector.
 *
 * @param n [in] Specifies the number of elements in vectors x and y.
 * @param x [in] Array, size at least (1 + (n-1)*abs(incx)).
 * @param incx [in] Specifies the increment for the elements of x.
 * @param y [in] Array, size at least (1 + (n-1)*abs(incy)).
 * @param incy [in] Specifies the increment for the elements of y.
 *
 * @param y [out] Contains a copy of the vector x if n is positive. Otherwise, 
 *                parameters are unaltered.
 *
 * @return Void.
 */
void cml_cblas_ccopy(const i32 n, const void *x, const i32 incx, void *y, const i32 incy);


/**
 * @brief Computes a vector-scalar product and adds the result to a vector.
 *
 * @param n [in] Specifies the number of elements in vectors x and y.
 * @param a [in] Specifies the scalar a.
 * @param x [in] Array, size at least (1 + (n-1)*abs(incx)).
 * @param incx [in] Specifies the increment for the elements of x.
 * @param y [in] Array, size at least (1 + (n-1)*abs(incy)).
 * @param incy [in] Specifies the increment for the elements of y.
 *
 * @param y [out] Contains the updated vector y.
 *
 * @return Void.
 */
void cml_cblas_caxpy(const i32 n, const void *a, const void *x, const i32 incx, void *y, const i32 incy);


/**
 * @brief Computes a complex vector-vector dot product.
 *
 * @param n [in] Specifies the number of elements in vectors x and y.
 * @param x [in] Array, size at least (1 + (n -1)*abs(incx)).
 * @param incx [in] Specifies the increment for the elements of x.
 * @param y [in] Array, size at least (1 + (n -1)*abs(incy)).
 * @param incy [in] Specifies the increment for the elements of y.
 *
 * @param dotu [out] Contains the result of the dot product of x and y, if n is 
 *                   positive. Otherwise, it contains 0.
 *
 * @return Void.
 */
void cml_cblas_cdotu_sub(const i32 n, const void *x, const i32 incx, const void *y, const i32 incy, void *dotu);


/**
 * @brief Computes a dot product of a conjugated vector with another vector.
 *
 * @param n [in] Specifies the number of elements in vectors x and y.
 * @param x [in] Array, size at least (1 + (n -1)*abs(incx)).
 * @param incx [in] Specifies the increment for the elements of x.
 * @param y [in] Array, size at least (1 + (n -1)*abs(incy)).
 * @param incy [in] Specifies the increment for the elements of y.
 *
 * @param dotu [out] Contains the result of the dot product of the conjugated x 
 *                   and unconjugated y, if n is positive. Otherwise, it 
 *                   contains 0.
 *
 * @return Void.
 */
void cml_cblas_cdotc_sub(const i32 n, const void *x, const i32 incx, const void *y, const i32 incy, void *dotc);


/**
 * @brief Computes the Euclidean norm of a vector.
 *
 * @param n [in] Specifies the number of elements in vector x. 
 * @param x [in] Array, size at least (1 + (n -1)*abs (incx)).
 * @param incx [in] Specifies the increment for the elements of x.
 *
 * @return Void.
 */
f32 cml_cblas_scnrm2(const i32 n, const void *x, const i32 incx);


/**
 * @brief Computes the sum of magnitudes of the vector elements.
 *
 * @param n [in] Specifies the number of elements in vector x. 
 * @param x [in] Array, size at least (1 + (n -1)*abs (incx)).
 * @param incx [in] Specifies the increment for the elements of x.
 *
 * @return Void.
 */
f32 cml_cblas_scasum(const i32 n, const void *x, const i32 incx);


#endif /* CAMEL_C_CBLAS */
