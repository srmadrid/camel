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
#include "../memory/allocator.h"


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
    /** @brief Allocator used for dynamic memory management within the 
     *         structure. */
    CML_Allocator *allocator;
    /** @brief Freeing function for the elements of the array. */
    void (*destroyFn)(void *element);
} CML_DArray;



/**
 * @brief Initializes a CML_DArray with the input capacity and stride.
 * 
 * @param allocator Allocator for the array.
 * @param capacity Initial capacity of the array.
 * @param stride   Size of each element in the array in bytes.
 * @param destroyFn   Freeing function for the elements of the array.
 * @param darray   Pointer to the CML_DArray to be initialized.
 * 
 * @return Status code.
 */
CML_Status _cml_darray_init(CML_Allocator *allocator, u32 capacity, u32 stride, void (*destroyFn)(void *element), CML_DArray *darray);


/**
 * @brief Initializes a CML_DArray with the input type and size.
 * 
 * @param allocator Allocator for the array.
 * @param capacity Size of the array.
 * @param type     Type of the array.
 * @param destroyFn   Freeing function for the elements of the array.
 * @param darray   Pointer to the CML_DArray to be initialized.
 * 
 * @return Status code.
 */
#define cml_darray_init(allocator, capacity, type, destroyFn, darray) _cml_darray_init(allocator, capacity, sizeof(type), destroyFn, darray)


/**
 * @brief Initializes a CML_DArray with the input type and default capacity.
 * 
 * @param allocator Allocator for the tree.
 * @param type   Type of the array.
 * @param destroyFn Freeing function for the elements of the array.
 * @param darray Pointer to the CML_DArray to be initialized.
 * 
 * @return Status code.
 */
#define cml_darray_init_default(allocator, type, destroyFn, darray) _cml_darray_init(allocator, CML_INITIAL_DARRAY_CAPACITY, sizeof(type), destroyFn, darray)


/**
 * @brief Frees the internal memory of a CML_DArray and its elements using the 
 *        freeing function stored in the CML_DArray.
 * 
 * @param darray The CML_DArray to be freed.
 * 
 * @return void.
 */
void cml_darray_destroy(void *darray);


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
 * @brief Pushes an element to the end of a CML_DArray.
 * 
 * @param element Pointer to the element to be pushed.
 * @param out     The CML_DArray to be pushed to.
 * 
 * @return Status code.
 */
CML_Status cml_darray_push(void *element, CML_DArray *out);


/**
 * @brief Inserts an of an element at the input index of a CML_DArray.
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
 * @param darray The CML_DArray to be popped from.
 * @param out    Pointer to the location to move the popped element.
 * 
 * @return Status code.
 */
CML_Status cml_darray_pop(CML_DArray *darray, void *out);


/**
 * @brief Pops an element at the input index of a CML_DArray.
 * 
 * @param index  Index at which the element will be removed.
 * @param darray The CML_DArray to be removed from.
 * @param out    Pointer to the location to move the popped element.
 * 
 * @return Status code.
 */
CML_Status cml_darray_remove(u32 index, CML_DArray *darray, void *out);


/**
 * @brief Gets the element at the input index of a CML_DArray.
 * 
 * @param index Index of the element to be retrieved.
 * @param out   The CML_DArray to be retrieved from.
 * 
 * @return A pointer to the element at the input index.
 */
void *cml_darray_get(u32 index, CML_DArray *out);


/**
 * @brief Sets the element at the input index of a CML_DArray and frees the 
 *        previous element.
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
