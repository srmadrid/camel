/**
 * @file m.h
 * 
 * @brief Declaration of CAMEL's basic type, the matrix.
 *
 * @author Sergio Madrid
 * @date 2/3/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_M
#define CAMEL_M


#include <stdio.h>
#include <math.h>
#include <omp.h>

#include "../err.h"
#include "../macros.h"
#include "../types.h"
#include "../memory/memory.h"
#include "../bignum/bignum.h"


/**
 * @brief Basic CAMEL type. Scalars are 1x1 matrices, vectors are 1xn or nx1
 *        matrices that may have to be transposed.
 */
typedef struct CML_Matrix {
    /** @brief Pointer to the data in the matrix. */
    union {
        u8  *u8d;
        u16 *u16d;
        u32 *u32d;
        u64 *u64d;

        i8  *i8d;
        i16 *i16d;
        i32 *i32d;
        i64 *i64d;

        f32 *f32d;
        f64 *f64d;

        cf32 *cf32d;
        cf64 *cf64d;

        CML_BigInt        *bigintd;
        CML_Fraction      *fracd;
        CML_Complex       *complexd;
        CML_Expression    *expd;
        struct CML_Matrix *matd;
    };
    /** @brief Type stored in the matrix. */
    CML_NumericType type;
    /** @brief Number of rows. */
    u32 rows;
    /** @brief Number of columns. */
    u32 columns;
    /** @brief Allocator used for dynamic memory management within the 
     *         structure. */
    CML_Allocator *allocator;
} CML_Matrix;



/**
 * @brief Initializes a CML_Matrix and zeroes its data (all standard types are
 *        set to zero, but library defined types are not initiallized).
 * 
 * @param allocator Allocator for the matrix.
 * @param rows      Number of rows.
 * @param columns   Number of columns.
 * @param type      Numeric type stored in the matrix.
 * @param matrix    Pointer to the matrix to be initialized.
 * 
 * @return Status code.
 */
CML_Status cml_matrix_init(CML_Allocator *allocator, u32 rows, u32 columns, CML_NumericType type, CML_Matrix *matrix);


/**
 * @brief Initializes a CML_Matrix and sets all values to 0. Incontrast to 
 *        the standard initializer, if the type is an arbitrary precision type 
 *        (CML_BigInt, CML_Fraction or CML_Complex), all elements will be 
 *        initialized with the allocator of the matrix to 0.
 * 
 * @param allocator Allocator for the matrix.
 * @param rows      Number of rows.
 * @param columns   Number of columns.
 * @param type      Numeric type stored in the matrix.
 * @param matrix    Pointer to the matrix to be initialized.
 * 
 * @return Status code.
 */
CML_Status cml_matrix_init0(CML_Allocator *allocator, u32 rows, u32 columns, CML_NumericType type, CML_Matrix *matrix);


/**
 * @brief Frees the internal memory of a CML_Matrix and its elements.
 * 
 * @param matrix The CML_Matrix to be freed.
 * 
 * @return void.
 */
void cml_matrix_destroy(void *matrix);


/**
 * @brief Sets the element at the specified location to the input value. If the
 *        type of the matrix is an arbitrary precision type, the matrix takes
 *        ownership of the object, and the user should not free its contents.
 *
 * @param element Value to insert in the matrix.
 * @param row     Row of the element.
 * @param column  Column of the element.
 * @param out     The matrix.
 *
 * @return Status code.
 */
CML_Status cml_matrix_set(void *element, u32 row, u32 column, CML_Matrix *out);


/**
 * @brief Gets the element at the input location of a CML_Matrix.
 * 
 * @param row   Row of the element to be retrieved.
 * @param column Column of the element to be retrieved.
 * @param matrix The CML_Matrix to be retrieved from.
 * @param out Optional error checking parameter.
 * 
 * @return A pointer to the location of the element.
 */
void *cml_matrix_get(u32 row, u32 column, const CML_Matrix *matrix, CML_Status *out);


/**
 * @brief Returns the index for an element in a specific row and column for use
 *        in the 1d array of the matrix.
 *
 * @note No NULL checking is done on the matrix. If the dimensions are larger 
 *       than the matrix's, they are wrapped around to avoid accessing unowned
 *       memory.
 *
 * @param row Row of the element.
 * @param column Column of the element.
 * @param matrix The matrix.
 *
 * @return The 1d index.
 */
static inline u32 cml_idx(u32 row, u32 column, CML_Matrix *matrix) {
    row = row < matrix->rows ? row : matrix->rows - 1;
    column = column < matrix->columns ? column : matrix->columns - 1;

    return row*matrix->columns + column;
}


/**
 * @brief Creates a new matrix out of the rows and columns specified by p and
 *        q (permutation vectors).
 *
 * @param allocator Allocator for the new matrix.
 * @param A         Input matrix.
 * @param p         Row permutation vector.
 * @param q         Column permutation vector.
 * @param out       Output matrix.
 *
 * @return Status code.
 */
CML_Status cml_matrix_select(CML_Allocator *allocator, const CML_Matrix *A, CML_Matrix *p, CML_Matrix *q, CML_Matrix *out);


/**
 * @brief Adds two matrices and stores the result in the out matrix.
 *
 * @param allocator Allocator for the new matrix.
 * @param left      The matrix on the left.
 * @param right     The matrix on the right.
 * @param out       Output matrix.
 *
 * @return Status code.
 */
CML_Status cml_matrix_add(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, CML_Matrix *out);


/**
 * @brief Adds two matrices in place (out += right) and stores the result in 
 *        the out matrix.
 *
 * @param right     The matrix on the right.
 * @param out       The matrix on the left.
 *
 * @return Status code.
 */
CML_Status cml_matrix_add_inplace(const CML_Matrix *right, CML_Matrix *out);


/**
 * @brief Subtracts two matrices and stores the result in the out matrix.
 *
 * @param allocator Allocator for the new matrix.
 * @param left      The matrix on the left.
 * @param right     The matrix on the right.
 * @param out       Output matrix.
 *
 * @return Status code.
 */
CML_Status cml_matrix_sub(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, CML_Matrix *out);


/**
 * @brief Subtracts two matrices in place (out -= right) and stores the result in 
 *        the out matrix.
 *
 * @param right     The matrix on the right.
 * @param out       The matrix on the left.
 *
 * @return Status code.
 */
CML_Status cml_matrix_sub_inplace(const CML_Matrix *right, CML_Matrix *out);


/**
 * @brief Multiplies two matrices and stores the result in the out matrix.
 *
 * @param allocator Allocator for the new matrix.
 * @param left      The matrix on the left.
 * @param right     The matrix on the right.
 * @param out       Output matrix.
 *
 * @return Status code.
 */
CML_Status cml_matrix_mult(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, CML_Matrix *out);


/**
 * @brief Multiplies two matrices element by element, and stores the result in
 *        out.
 *
 * @param allocator Allocator for the new matrix.
 * @param left      The matrix on the left.
 * @param right     The matrix on the right.
 * @param out       Output matrix.
 *
 * @return Status code.
 */
CML_Status cml_matrix_multew(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, CML_Matrix *out);


/**
 * @brief Multiplies two matrices element by element, and stores the result in
 *        the out matrix out .*= right.
 *
 * @param right     The matrix on the right.
 * @param out       The matrix on the left.
 *
 * @return Status code.
 */
CML_Status cml_matrix_multew_inplace(const CML_Matrix *right, CML_Matrix *out);


/**
 * @brief Divides two matrices element by element, and stores the result in
 *        out.
 *
 * @param allocator Allocator for the new matrix.
 * @param left      The matrix on the left.
 * @param right     The matrix on the right.
 * @param out       Output matrix.
 *
 * @return Status code.
 */
CML_Status cml_matrix_divew(CML_Allocator *allocator, const CML_Matrix *left, const CML_Matrix *right, CML_Matrix *out);


/**
 * @brief Divides two matrices element by element, and stores the result in
 *        the out matrix out ./= right.
 *
 * @param right     The matrix on the right.
 * @param out       The matrix on the left.
 *
 * @return Status code.
 */
CML_Status cml_matrix_divew_inplace(const CML_Matrix *right, CML_Matrix *out);


/**
 * @brief Transposes a matrix and stores the result in the out matrix.
 *
 * @param allocator Allocator for the new matrix.
 * @param A         Matrix to be transposed.
 * @param out       Output matrix.
 *
 * @return Status code.
 */
CML_Status cml_matrix_transpose(CML_Allocator *allocator, const CML_Matrix *A, CML_Matrix *out);


/**
 * @brief Prints the input matrix.
 *
 * @param allocator Allocator for the temporary array.
 * @param matrix The matrix to be printed.
 *
 * @return Status code. */
CML_Status cml_matrix_print(CML_Allocator *allocator, const CML_Matrix *matrix);


#endif /* CAMEL_M */
