/**
 * @file allocator.c
 * 
 * @brief Implementation for the allocator structure and management.
 *
 * @author Sergio Madrid
 * @date 1/2/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/core/memory/allocator.h"


void *cml_malloc(u64 size, void *context) {
    (void)context;
    return malloc(size);
}


void cml_free(void *ptr, void *context) {
    (void)context;
    free(ptr);
}


void *cml_realloc(void *ptr, u64 newSize, void *context) {
    (void)context;
    return realloc(ptr, newSize);
}


void *cml_calloc(u64 numElements, u64 size, void *context) {
    (void)context;
    return calloc(numElements, size);
}


void *cml_aligned_alloc(u64 alignment, u64 size, void *context) {
    (void)context;
    return aligned_alloc(alignment, size);
}

