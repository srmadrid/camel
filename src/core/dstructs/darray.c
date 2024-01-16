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


CML_Status _cml_darray_init(u32 capacity, u32 stride, CML_DArray *darray) {
    if (darray == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (capacity == 0) {
        return CML_ERR_INVALID_SIZE;
    }

    darray->data = malloc(capacity*stride);
    if (darray->data == NULL) {
        return CML_ERR_NULL_PTR;
    }

    darray->length = 0;
    darray->capacity = capacity;
    darray->stride = stride;

    return CML_SUCCESS;
}


void cml_darray_free(CML_DArray *darray, void (*freeFn)(void *element)) {
    if (darray != NULL) {
        if (freeFn != NULL) {
            for (u32 i = 0; i < darray->length; ++i) {
                freeFn((u8*)darray->data + i*darray->stride);
            }
        }
        free(darray->data);
        darray->data = NULL;
        darray->length = 0;
        darray->capacity = 0;
        darray->stride = 0;
    }
}


CML_Status cml_darray_resize(u32 capacity, CML_DArray *darray) {
    if (darray == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (capacity == 0) {
        return CML_ERR_INVALID_SIZE;
    }

    darray->data = realloc(darray->data, capacity*darray->stride);
    if (darray->data == NULL) {
        return CML_ERR_NULL_PTR;
    }

    darray->capacity = capacity;

    return CML_SUCCESS;
}


CML_Status cml_darray_push(void *element, CML_DArray *darray) {
    if (darray == NULL || element == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (darray->length == darray->capacity) {
        darray->data = realloc(darray->data, darray->capacity*CML_DARRAY_RESIZE_FACTOR*darray->stride);
        if (darray->data == NULL) {
            return CML_ERR_NULL_PTR;
        }
        darray->capacity *= CML_DARRAY_RESIZE_FACTOR;
    }

    memcpy((u8*)darray->data + darray->length*darray->stride, element, darray->stride);
    darray->length++;

    return CML_SUCCESS;
}


CML_Status cml_darray_insert(void *element, u32 index, CML_DArray *darray) {
    if (darray == NULL || element == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (index > darray->length) {
        return CML_ERR_INVALID_INDEX;
    }

    if (darray->length == darray->capacity) {
        darray->data = realloc(darray->data, darray->capacity*CML_DARRAY_RESIZE_FACTOR*darray->stride);
        if (darray->data == NULL) {
            return CML_ERR_NULL_PTR;
        }
        darray->capacity *= CML_DARRAY_RESIZE_FACTOR;
    }

    memmove((u8*)darray->data + (index + 1)*darray->stride, (u8*)darray->data + index*darray->stride, (darray->length - index)*darray->stride);
    memcpy((u8*)darray->data + index*darray->stride, element, darray->stride);
    darray->length++;

    return CML_SUCCESS;
}


void *cml_darray_pop(CML_DArray *darray) {
    if (darray == NULL) {
        return NULL;
    }

    if (darray->length == 0) {
        return NULL;
    }

    void *element = malloc(darray->stride);
    if (element == NULL) {
        return NULL;
    }

    memcpy(element, (u8*)darray->data + (darray->length - 1)*darray->stride, darray->stride);
    darray->length--;

    if (darray->length < darray->capacity/(CML_DARRAY_RESIZE_FACTOR*CML_DARRAY_RESIZE_FACTOR)) {
        darray->data = realloc(darray->data, darray->capacity/CML_DARRAY_RESIZE_FACTOR*darray->stride);
        if (darray->data == NULL) {
            return NULL;
        }
        darray->capacity /= CML_DARRAY_RESIZE_FACTOR;
    }

    return element;
}


void *cml_darray_remove(u32 index, CML_DArray *darray) {
    if (darray == NULL) {
        return NULL;
    }

    if (index >= darray->length) {
        return NULL;
    }

    void *element = malloc(darray->stride);
    if (element == NULL) {
        return NULL;
    }

    memcpy(element, (u8*)darray->data + index*darray->stride, darray->stride);
    memmove((u8*)darray->data + index*darray->stride, (u8*)darray->data + (index + 1)*darray->stride, (darray->length - index - 1)*darray->stride);
    darray->length--;

    if (darray->length < darray->capacity/(CML_DARRAY_RESIZE_FACTOR*CML_DARRAY_RESIZE_FACTOR)) {
        darray->data = realloc(darray->data, darray->capacity/CML_DARRAY_RESIZE_FACTOR*darray->stride);
        if (darray->data == NULL) {
            return NULL;
        }
        darray->capacity /= CML_DARRAY_RESIZE_FACTOR;
    }

    return element;
}


void *cml_darray_get(u32 index, CML_DArray *darray) {
    if (darray == NULL) {
        return NULL;
    }

    if (index >= darray->length) {
        return NULL;
    }

    void *element = malloc(darray->stride);
    if (element == NULL) {
        return NULL;
    }

    memcpy(element, (u8*)darray->data + index*darray->stride, darray->stride);

    return element;
}


CML_Status cml_darray_set(void *element, u32 index, CML_DArray *darray) {
    if (darray == NULL || element == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (index >= darray->length) {
        return CML_ERR_INVALID_INDEX;
    }

    memcpy((u8*)darray->data + index*darray->stride, element, darray->stride);

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
