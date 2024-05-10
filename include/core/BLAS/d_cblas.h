/**
 * @file d_cblas.h
 * 
 * @brief Declaration of Camel's BLAS double precision C wrapper.
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
void cml_cblas_drotg(f64 *a, f64 *b, f64 *c, f64 *s);


/**
 * @brief Computes the parameters for a modified Givens rotation.
 *
 * @param d1 [in] Provides the scaling factor for the x-coordinate of the input 
 *                vector.
 * @param d2 [in] Provides the scaling factor for the y-coordinate of the input 
 *                vector.
 * @param x1 [in] Provides the x-coordinate of the input vector.
 * @param y1 [in] Provides the y-coordinate of the input vector.
 *
 * @param d1 [out] Provides the first diagonal element of the updated matrix.
 * @param d2 [out] Provides the second diagonal element of the updated matrix.
 * @param x1 [out] Provides the x-coordinate of the rotated vector before 
 *                 scaling.
 * @param param [out] Array, size 5.
 *
 * @return Void.
 */
void cml_cblas_drotmg(f64 *d1, f64 *d2, f64 *x1, const f64 y1, f64 *param);


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
void cml_cblas_drot(const i32 n, f64 *x, const i32 incx, f64 *y, const i32 incy, const f64 c, const f64 s);


/**
 * @brief Performs modified Givens rotation of points in the plane.
 *
 * @param n [in] Specifies the number of elements in vectors x and y.
 * @param x [in] Array, size at least (1 + (n -1)*abs(incx)). 
 * @param incx [in] Specifies the increment for the elements of x.
 * @param y [in] Array, size at least (1 + (n -1)*abs(incy)).
 * @param incy [in] Specifies the increment for the elements of y.
 * @param param [in] Array, size 5.
 *
 * @param x [out] Each element x[i] is replaced by h11*x[i] + h12*y[i].
 * @param y [out] Each element y[i] is replaced by h21*x[i] + h22*y[i].
 *
 * @return Void.
 */
void cml_cblas_drotm(const i32 n, f64 *x, const i32 incx, f64 *y, const i32 incy, const f64 *param);


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
void cml_cblas_dswap(const i32 n, f64 *x, const i32 incx, f64 *y, const i32 incy);


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
void cml_cblas_dscal(const i32 n, const f64 a, f64 *x, const i32 incx);


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
void cml_cblas_dcopy(const i32 n, const f64 *x, const i32 incx, f64 *y, const i32 incy);


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
void cml_cblas_daxpy(const i32 n, const f64 a, const f64 *x, const i32 incx, f64 *y, const i32 incy);


/**
 * @brief Computes a vector-vector dot product.
 *
 * @param n [in] Specifies the number of elements in vectors x and y.
 * @param x [in] Array, size at least (1+(n-1)*abs(incx)).
 * @param incx [in] Specifies the increment for the elements of x.
 * @param y [in] Array, size at least (1+(n-1)*abs(incy)).
 * @param incy [in] Specifies the increment for the elements of y.
 *
 * @return Void.
 */
f64 cml_cblas_ddot(const i32 n, const f64 *x, const i32 incx, const f64 *y, const i32 incy);


/**
 * @brief Computes a vector-vector dot product with double precision.
 *
 * @param n [in] Specifies the number of elements in the input vectors sx and 
 *               sy. 
 * @param sx, sy [in] Arrays, size at least (1+(n -1)*abs(incx)) and 
 *                    (1+(n-1)*abs(incy)), respectively. Contain the input 
 *                    single precision vectors.
 * @param incx [in] Specifies the increment for the elements of sx.
 * @param incy [in] Specifies the increment for the elements of sy.
 *
 * @return Void.
 */
f64 cml_cblas_dsdot(const i32 n, const f32 *sx, const i32 incx, const f32 *sy, const i32 incy);


/**
 * @brief Computes the Euclidean norm of a vector.
 *
 * @param n [in] Specifies the number of elements in vector x. 
 * @param x [in] Array, size at least (1 + (n -1)*abs (incx)).
 * @param incx [in] Specifies the increment for the elements of x.
 *
 * @return Void.
 */
f64 cml_cblas_dnrm2(const i32 n, const f64 *x, const i32 incx);


/**
 * @brief Computes the sum of magnitudes of the vector elements.
 *
 * @param n [in] Specifies the number of elements in vector x. 
 * @param x [in] Array, size at least (1 + (n -1)*abs (incx)).
 * @param incx [in] Specifies the increment for the elements of x.
 *
 * @return Void.
 */
f64 cml_cblas_dasum(const i32 n, const f64 *x, const i32 incx);


#endif /* CAMEL_D_CBLAS */
