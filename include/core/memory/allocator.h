/**
 * @file allocator.h
 * 
 * @brief Declaration for the allocator structure and management.
 *
 * @author Sergio Madrid
 * @date 29/1/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_ALLOCATOR
#define CAMEL_ALLOCATOR

#include <stdlib.h>

#include "../macros.h"
#include "../err.h"


/**
 * @brief Represents a custom allocator.
 *
 * @note No initializer is provided, the user should create their allocator 
 *       using standard C struct creation. Any unused fields should be set to
 *       NULL.
 * @note Some fields are mandatory to have.
 * @note It is recommended to create one allocator for all structures, since
 *       they all store a pointer to one. This allocator should not be destroyed
 *       before all data structures using it.
 */
typedef struct CML_Allocator {
    /** @brief Allocates memory of the specified size. MANDATORY. */
    void *(*malloc)(u64 size, void *context);
    /** @brief Frees memory allocated with alloc. MANDATORY. */
    void (*free)(void *ptr, void *context);
    /** @brief Changes the size of an allocated memory block. MANDATORY. */
    void *(*realloc)(void *ptr, u64 newSize, void *context);
    /** @brief Allocates numElements of size bytes each. */ 
    void *(*calloc)(u64 numElements, u64 size, void *context);
    /** @brief Allocates the specified number of bytes at the specified 
     *         alignment. */
    void *(*aligned_alloc)(u64 alignment, u64 size, void *context);
    /** @brief Aligned version of freel. If needed. */
    void (*aligned_free)(void *ptr, void *context);
    /** @brief Returns memory stats of the allocator. */
    void *(*get_stats)(void *context, void *outStats);
    /** @brief Context needed by the allocator. */
    void *context;
} CML_Allocator;




/**
 * @brief Default C malloc accustomed for CML_Allocator.
 *
 * @param size    Size of the memory to be allocated.
 * @param context Dummy.
 *
 * @return The allocated memory.
 */
void *cml_malloc(u64 size, void *context);


/**
 * @brief Default C free accustomed for CML_Allocator.
 *
 * @param ptr     Ponter to the memory to be freed.
 * @param context Dummy.
 *
 * @return void.
 */
void cml_free(void *ptr, void *context);


/**
 * @brief Default C realloc accustomed for CML_Allocator.
 *
 * @param ptr     Ponter to the memory to be reallocated.
 * @param newSize New size.
 * @param context Dummy.
 *
 * @return The allocated memory.
 */
void *cml_realloc(void *ptr, u64 newSize, void *context);


/**
 * @brief Default C calloc accustomed for CML_Allocator.
 *
 * @param numElements Number of elements of size size.
 * @param size        Size of the elements.
 * @param context     Dummy.
 *
 * @return The allocated memory.
 */
void *cml_calloc(u64 numElements, u64 size, void *context);


/**
 * @brief Default C aligned_alloc accustomed for CML_Allocator.
 *
 * @param alignment   Alignment of the memory.
 * @param size        Size of the memory to be allocated.
 * @param context     Dummy.
 *
 * @return The allocated memory.
 */
void *cml_aligned_alloc(u64 alignment, u64 size, void *context);


/**
 * @brief Default allocator using standard C memory management functions.
 */
#define CML_ALLOCATOR_DEFAULT (CML_Allocator){                                    \
                                              .malloc        = cml_malloc,        \
                                              .free          = cml_free,          \
                                              .realloc       = cml_realloc,       \
                                              .calloc        = cml_calloc,        \
                                              .aligned_alloc = cml_aligned_alloc, \
                                              .aligned_free  = NULL,              \
                                              .context       = NULL,              \
                                             }


#endif /* CAMEL_ALLOCATOR */
