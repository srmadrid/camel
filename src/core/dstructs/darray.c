/**
 * @file darray.c
 * 
 * @brief Implementation for the dynamic array data structure.
 *
 * @author Sergio Madrid
 * @date 16/1/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/core/dstructs/darray.h"


CML_Status _cml_darray_init(CML_Allocator *allocator, u32 capacity, u32 stride, void (*destroyFn)(void *element), CML_DArray *darray) {
    if (darray == NULL || allocator == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (capacity == 0) {
        return CML_ERR_INVALID_CAPACITY;
    }

    darray->data = allocator->malloc(capacity*stride, allocator->context);
    if (darray->data == NULL) {
        return CML_ERR_MALLOC;
    }

    darray->destroyFn = destroyFn;
    darray->length = 0;
    darray->allocator = allocator;
    darray->capacity = capacity;
    darray->stride = stride;

    return CML_SUCCESS;
}


void cml_darray_destroy(CML_DArray *darray) {
    if (darray != NULL) {
        if (darray->destroyFn != NULL) {
            for (u32 i = 0; i < darray->length; ++i) {
                darray->destroyFn((u8*)darray->data + i*darray->stride);
            }
        }
        darray->allocator->free(darray->data, darray->allocator->context);
        darray->data = NULL;
        darray->length = 0;
        darray->allocator = NULL;
        darray->capacity = 0;
        darray->stride = 0;
    }
}


CML_Status cml_darray_resize(u32 capacity, CML_DArray *out) {
    if (out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (capacity == 0) {
        return CML_ERR_INVALID_CAPACITY;
    }

    void *tmp = out->allocator->realloc(out->data, capacity*out->stride, out->allocator->context);
    if (tmp== NULL) {
        return CML_ERR_REALLOC;
    }
    out->data = tmp;

    out->capacity = capacity;

    return CML_SUCCESS;
}


CML_Status cml_darray_push(void *element, CML_DArray *out) {
    if (out == NULL || element == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (out->length == out->capacity) {
        void *tmp = out->allocator->realloc(out->data, out->capacity*CML_DARRAY_RESIZE_FACTOR*out->stride, out->allocator->context);
        if (tmp == NULL) {
            return CML_ERR_REALLOC;
        }
        out->data = tmp;
        out->capacity *= CML_DARRAY_RESIZE_FACTOR;
    }

    memcpy((u8*)out->data + out->length*out->stride, element, out->stride);
    out->length++;

    return CML_SUCCESS;
}


CML_Status cml_darray_insert(void *element, u32 index, CML_DArray *out) {
    if (out == NULL || element == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (index > out->length) {
        return CML_ERR_INVALID_INDEX;
    }

    if (out->length == out->capacity) {
        void *tmp = out->allocator->realloc(out->data, out->capacity*CML_DARRAY_RESIZE_FACTOR*out->stride, out->allocator->context);
        if (tmp == NULL) {
            return CML_ERR_REALLOC;
        }
        out->data = tmp;
        out->capacity *= CML_DARRAY_RESIZE_FACTOR;
    }

    memmove((u8*)out->data + (index + 1)*out->stride, (u8*)out->data + index*out->stride, (out->length - index)*out->stride);
    memcpy((u8*)out->data + index*out->stride, element, out->stride);
    out->length++;

    return CML_SUCCESS;
}


void *cml_darray_pop(CML_DArray *out) {
    if (out == NULL) {
        return NULL;
    }

    if (out->length == 0) {
        return NULL;
    }

    void *element = out->allocator->malloc(out->stride, out->allocator->context);
    if (element == NULL) {
        return NULL;
    }

    memcpy(element, (u8*)out->data + (out->length - 1)*out->stride, out->stride);
    out->length--;

    if (out->length < out->capacity/(CML_DARRAY_RESIZE_FACTOR*CML_DARRAY_RESIZE_FACTOR)) {
        void *tmp = out->allocator->realloc(out->data, out->capacity/(CML_DARRAY_RESIZE_FACTOR*out->stride), out->allocator->context);
        if (tmp == NULL) {
            out->allocator->free(element, out->allocator->context);
            return NULL;
        }
        out->data = tmp;
        out->capacity /= CML_DARRAY_RESIZE_FACTOR;
    }

    return element;
}


void *cml_darray_remove(u32 index, CML_DArray *out) {
    if (out == NULL) {
        return NULL;
    }

    if (index >= out->length) {
        return NULL;
    }

    void *element = out->allocator->malloc(out->stride, out->allocator->context);
    if (element == NULL) {
        return NULL;
    }

    memcpy(element, (u8*)out->data + index*out->stride, out->stride);
    memmove((u8*)out->data + index*out->stride, (u8*)out->data + (index + 1)*out->stride, (out->length - index - 1)*out->stride);
    out->length--;

    if (out->length < out->capacity/(CML_DARRAY_RESIZE_FACTOR*CML_DARRAY_RESIZE_FACTOR)) {
        void *tmp = out->allocator->realloc(out->data, out->capacity/(CML_DARRAY_RESIZE_FACTOR*out->stride), out->allocator->context);
        if (tmp == NULL) {
            out->allocator->free(element, out->allocator->context);
            return NULL;
        }
        out->data = tmp;
        out->capacity /= CML_DARRAY_RESIZE_FACTOR;
    }

    return element;
}


void *cml_darray_get(u32 index, CML_DArray *out) {
    if (out == NULL) {
        return NULL;
    }

    if (index >= out->length) {
        return NULL;
    }

    void *element = (u8*)out->data + index*out->stride;

    return element;
}


CML_Status cml_darray_set(void *element, u32 index, CML_DArray *out) {
    if (out == NULL || element == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (index >= out->length) {
        return CML_ERR_INVALID_INDEX;
    }

    if (out->destroyFn) {
        out->destroyFn((u8*)out->data + index*out->stride);
    }

    memcpy((u8*)out->data + index*out->stride, element, out->stride);

    return CML_SUCCESS;
}


b8 cml_darray_eq(CML_DArray *darray1, CML_DArray *darray2) {
    if (darray1 == NULL || darray2 == NULL) {
        return false;
    }

    if (darray1->length != darray2->length) {
        return false;
    }

    if (darray1->stride != darray2->stride) {
        return false;
    }

    for (u32 i = 0; i < darray1->length; ++i) {
        if (memcmp((u8*)darray1->data + i*darray1->stride, (u8*)darray2->data + i*darray2->stride, darray1->stride) != 0) {
            return false;
        }
    }

    return true;
}


char *cml_darray_debug(CML_DArray *expected, CML_DArray *got, b8 verbose) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    if (verbose) {
        sprintf(debugMessage, "\t\tExpected:\n\t\t\tData: %p\n\t\t\tLength: %i\n\t\t\tCapacity: %i\n\t\tGot:\n\t\t\tData: %p\n\t\t\tLength: %i\n\t\t\tCapacity: %i\n", 
            expected->data, expected->length, expected->capacity, 
            got->data, got->length, got->capacity);
    } else {
        sprintf(debugMessage, "\t\tExpected:\n\t\t\t%p\n\t\tGot:\n\t\t\t%p\n", 
                expected->data, got->data);
    }

    return debugMessage;
}
