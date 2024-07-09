/**
 * @file stack.h
 * 
 * @brief Declaration for expression parsing and manupulation of CAMEL.
 *
 * @author Sergio Madrid
 * @date 9/12/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/core/dstructs/stack.h"


CML_Status _cml_stack_init(CML_Allocator *allocator, u32 capacity, u32 stride, void (*destroyFn)(void *element), CML_Stack *stack) {
    if (stack == NULL || allocator == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (capacity == 0) {
        return CML_ERR_INVALID_CAPACITY;
    }

    stack->data = allocator->malloc(capacity*stride, allocator->context);
    if (stack->data == NULL) {
        return CML_ERR_MALLOC;
    }

    stack->destroyFn = destroyFn;
    stack->length = 0;
    stack->allocator = allocator;
    stack->capacity = capacity;
    stack->stride = stride;

    return CML_SUCCESS;
}


void cml_stack_destroy(void *stack) {
    CML_Stack *stk = (CML_Stack*)stack;
    if (stk != NULL) {
        if (stk->destroyFn != NULL) {
            for (u32 i = 0; i < stk->length; ++i) {
                stk->destroyFn((u8*)stk->data + i*stk->stride);
            }
        }
        stk->allocator->free(stk->data, stk->allocator->context);
        stk->data = NULL;
        stk->length = 0;
        stk->allocator = NULL;
        stk->capacity = 0;
        stk->stride = 0;
    }
}


CML_Status cml_stack_resize(u32 capacity, CML_Stack *out) {
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


CML_Status cml_stack_push(void *element, CML_Stack *out) {
    if (out == NULL || element == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (out->length == out->capacity) {
        void *tmp = out->allocator->realloc(out->data, out->capacity*CML_STACK_RESIZE_FACTOR*out->stride, out->allocator->context);
        if (tmp == NULL) {
            return CML_ERR_REALLOC;
        }
        out->data = tmp;
        out->capacity *= CML_STACK_RESIZE_FACTOR;
    }

    memcpy((u8*)out->data + out->length*out->stride, element, out->stride);
    out->length++;

    return CML_SUCCESS;
}


CML_Status cml_stack_pop(CML_Stack *stack, void *out) {
    if (stack == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (stack->length == 0) {
        return CML_ERR_EMPTY_STRUCTURE;
    }

    memcpy(out, (u8*)stack->data + (stack->length - 1)*stack->stride, stack->stride);
    stack->length--;

    if (stack->length < stack->capacity/(CML_STACK_RESIZE_FACTOR*CML_STACK_RESIZE_FACTOR)) {
        void *tmp = stack->allocator->realloc(stack->data, stack->capacity/(CML_STACK_RESIZE_FACTOR*stack->stride), stack->allocator->context);
        if (tmp == NULL) {
            return CML_ERR_REALLOC;
        }
        stack->data = tmp;
        stack->capacity /= CML_STACK_RESIZE_FACTOR;
    }

    return CML_SUCCESS;
}


void *cml_stack_peek(CML_Stack *out) {
    if (out == NULL) {
        return NULL;
    }

    void *element = (u8*)out->data + out->length*out->stride;

    return element;
}


b8 cml_stack_eq(CML_Stack *stack1, CML_Stack *stack2) {
    if (stack1 == NULL || stack2 == NULL) {
        return false;
    }

    if (stack1->length != stack2->length) {
        return false;
    }

    if (stack1->stride != stack2->stride) {
        return false;
    }

    for (u32 i = 0; i < stack1->length; ++i) {
        if (memcmp((u8*)stack1->data + i*stack1->stride, (u8*)stack2->data + i*stack2->stride, stack1->stride) != 0) {
            return false;
        }
    }

    return true;
}


char *cml_stack_debug(CML_Stack *expected, CML_Stack *got, b8 verbose) {
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

