/**
 * @file darray.h
 * 
 * @brief Declaration for the dynamic array data structure.
 *
 * @author Sergio Madrid
 * @date 15/1/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_DARRAY
#define CAMEL_DARRAY

#include <stdlib.h>

#include "../macros.h"
#include "../err.h"


/** @brief Default size of the dynamic array. */
#define CML_INITIAL_DARRAY_CAPACITY 1


/** @brief Default resize factor of the dynamic array. */
#define CML_DARRAY_RESIZE_FACTOR 2


/**
 * @brief Represents a dynamic array.
 */
typedef struct CML_DArray {
    /** @brief Pointer to the data of the array. */
    void *data;
    /** @brief Length of the array. */
    u32 length;
    /** @brief Capacity of the array. */
    u32 capacity;
    /** @brief Size of each element in the array in bytes. */
    u32 stride;
    /** @brief Freeing function for the elements of the array. */
    void (*freeFn)(void *element);
} CML_DArray;



/**
 * @brief Creates a new CML_DArray on the heap.
 * 
 * @return Pointer to the new CML_DArray.
 */
CML_DArray *cml_darray_new();


/**
 * @brief Initializes a CML_DArray with the input size and stride.
 * 
 * @param capacity Capacity of the array.
 * @param stride   Size of each element in the array in bytes.
 * @param freeFn   Freeing function for the elements of the array.
 * @param darray   Pointer to the CML_DArray to be initialized.
 * 
 * @return Status code.
 */
CML_Status _cml_darray_init(u32 capacity, u32 stride, void (*freeFn)(void *element), CML_DArray *darray);


/**
 * @brief Initializes a CML_DArray with the input type and size.
 * 
 * @param capacity Size of the array.
 * @param type     Type of the array.
 * @param freeFn   Freeing function for the elements of the array.
 * @param darray   Pointer to the CML_DArray to be initialized.
 * 
 * @return Status code.
 */
#define cml_darray_init(capacity, type, freeFn, darray) _cml_darray_init(capacity, sizeof(type), freeFn, darray)


/**
 * @brief Initializes a CML_DArray with the input type and default capacity.
 * 
 * @param type   Type of the array.
 * @param freeFn Freeing function for the elements of the array.
 * @param darray Pointer to the CML_DArray to be initialized.
 * 
 * @return Status code.
 */
#define cml_darray_init_default(type, freeFn, darray) _cml_darray_init(CML_INITIAL_DARRAY_CAPACITY, sizeof(type), freeFn, darray)


/**
 * @brief Frees the internal memory of a CML_DArray and its elements using the 
 *        freeing function stored in the CML_DArray.
 * 
 * @param darray The CML_DArray to be freed.
 * 
 * @return void.
 */
void cml_darray_destroy(CML_DArray *darray);


/**
 * @brief Frees the pointer to the CML_DArray.
 * 
 * @note Use only on CML_DArrays on the heap and after destroying them.
 *
 * @param node Pointer to the CML_DArray to be freed.
 * 
 * @return void.
 */
void cml_darray_free(CML_DArray *darray);


/**
 * @brief Resizes a CML_DArray to the input size.
 * 
 * @param capacity The new capacity of the array.
 * @param out      The CML_DArray to be resized.
 * 
 * @return Status code.
 */
CML_Status cml_darray_resize(u32 capacity, CML_DArray *out);


/**
 * @brief Pushes a copy of an element to the end of a CML_DArray.
 * 
 * @param element Pointer to the element to be pushed.
 * @param out     The CML_DArray to be pushed to.
 * 
 * @return Status code.
 */
CML_Status cml_darray_push(void *element, CML_DArray *out);


/**
 * @brief Inserts a copy of an element at the input index of a CML_DArray.
 * 
 * @param element Pointer to the element to be inserted.
 * @param index   Index at which the element will be inserted.
 * @param out     The CML_DArray to be inserted to.
 * 
 * @return Status code.
 */
CML_Status cml_darray_insert(void *element, u32 index, CML_DArray *out);


/**
 * @brief Pops an element from the end of a CML_DArray.
 * 
 * @param out The CML_DArray to be popped from.
 * 
 * @return The popped element.
 */
void *cml_darray_pop(CML_DArray *out);


/**
 * @brief Pops an element at the input index of a CML_DArray.
 * 
 * @param index Index at which the element will be removed.
 * @param out   The CML_DArray to be removed from.
 * 
 * @return The removed element.
 */
void *cml_darray_remove(u32 index, CML_DArray *out);


/**
 * @brief Gets the element at the input index of a CML_DArray.
 * 
 * @note If the elements are structs holding pointers, the pointers will be
 *       copied, not the data they point to. The user is responsible for freeing
 *       the memory of the copied structure, but not the data pointed to by the
 *       pointers, that is freed by the freeing function of the CML_DArray.
 * 
 * @param index Index of the element to be retrieved.
 * @param out   The CML_DArray to be retrieved from.
 * 
 * @return A pointer to the element at the input index.
 */
void *cml_darray_get(u32 index, CML_DArray *out);


/**
 * @brief Sets the element at the input index of a CML_DArray.
 * 
 * @param element Pointer to the element to be set.
 * @param index   Index of the element to be set.
 * @param out     The CML_DArray to be set.
 * 
 * @return Status code.
 */
CML_Status cml_darray_set(void *element, u32 index, CML_DArray *out);


/**
 * @brief Compares two CML_DArray for equality.
 * 
 * @param darray1 The first CML_DArray to be compared.
 * @param darray2 The second CML_DArray to be compared.
 * 
 * @return Boolean value indicating whether the two CML_DArray are equal.
 */
b8 cml_darray_eq(CML_DArray *darray1, CML_DArray *darray2);


/**
 * @brief Returns a debug message comparing the input darrays.
 *
 * @param expected The expected darray.
 * @param got      The result darray.
 * @param bervose  Whether to print all the darray data or not.
 * 
 * @return A string containing the debug message.
 */
char *cml_darray_debug(CML_DArray *expected, CML_DArray *got, b8 verbose);


#endif /* CAMEL_DARRAY */
