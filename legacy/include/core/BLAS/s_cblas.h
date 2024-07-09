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
void cml_cblas_srotmg(f32 *d1, f32 *d2, f32 *x1, const f32 y1, f32 *param);


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
void cml_cblas_srot(const i32 n, f32 *x, const i32 incx, f32 *y, const i32 incy, const f32 c, const f32 s);


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
void cml_cblas_srotm(const i32 n, f32 *x, const i32 incx, f32 *y, const i32 incy, const f32 *param);


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
void cml_cblas_sswap(const i32 n, f32 *x, const i32 incx, f32 *y, const i32 incy);


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
void cml_cblas_sscal(const i32 n, const f32 a, f32 *x, const i32 incx);


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
void cml_cblas_scopy(const i32 n, const f32 *x, const i32 incx, f32 *y, const i32 incy);


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
void cml_cblas_saxpy(const i32 n, const f32 a, const f32 *x, const i32 incx, f32 *y, const i32 incy);


/**
 * @brief Computes a vector-vector dot product.
 *
 * @param n [in] Specifies the number of elements in vectors x and y.
 * @param x [in] Array, size at least (1+(n-1)*abs(incx)).
 * @param incx [in] Specifies the increment for the elements of x.
 * @param y [in] Array, size at least (1+(n-1)*abs(incy)).
 * @param incy [in] Specifies the increment for the elements of y.
 *
 * @return The result of the dot product of x and y, if n is positive. 
 *         Otherwise, returns 0.
 */
f32 cml_cblas_sdot(const i32 n, const f32 *x, const i32 incx, const f32 *y, const i32 incy);


/**
 * @brief Computes a vector-vector dot product with double precision.
 *
 * @param n [in] Specifies the number of elements in the input vectors sx and 
 *               sy. 
 * @param sb [in] Single precision scalar to be added to inner product (for the 
 *                function sdsdot only).
 * @param sx, sy [in] Arrays, size at least (1+(n -1)*abs(incx)) and 
 *                    (1+(n-1)*abs(incy)), respectively. Contain the input 
 *                    single precision vectors.
 * @param incx [in] Specifies the increment for the elements of sx.
 * @param incy [in] Specifies the increment for the elements of sy.
 *
 * @return The result of the dot product of sx and sy with sb added, if n is 
 *         positive. Otherwise, returns.
 */
f32 cml_cblas_sdsdot(const i32 n, const f32 sb, const f32 *sx, const i32 incx, const f32 *sy, const i32 incy);


/**
 * @brief Computes the Euclidean norm of a vector.
 *
 * @param n [in] Specifies the number of elements in vector x. 
 * @param x [in] Array, size at least (1 + (n -1)*abs (incx)).
 * @param incx [in] Specifies the increment for the elements of x.
 *
 * @return The Euclidean norm of the vector x.
 */
f32 cml_cblas_snrm2(const i32 n, const f32 *x, const i32 incx);


/**
 * @brief Computes the sum of magnitudes of the vector elements.
 *
 * @param n [in] Specifies the number of elements in vector x. 
 * @param x [in] Array, size at least (1 + (n -1)*abs (incx)).
 * @param incx [in] Specifies the increment for the elements of x.
 *
 * @return The sum of magnitudes of real and imaginary parts of all elements of 
 *         the vector.
 */
f32 cml_cblas_sasum(const i32 n, const f32 *x, const i32 incx);


/**
 * @brief Finds the index of the element with maximum absolute value.
 *
 * @param n [in] Specifies the number of elements in vector x. 
 * @param x [in] Array, size at least (1 + (n -1)*abs (incx)).
 * @param incx [in] Specifies the increment for the elements of x.
 *
 * @return The position of vector element that has the largest absolute value 
 *         such that x[index-1] has the largest absolute value. The index 
 *         returned is zero-based.
 */
i32 cml_cblas_isamax(const i32 n, const f32 *x, const i32 incx);


#endif /* CAMEL_S_CBLAS */
