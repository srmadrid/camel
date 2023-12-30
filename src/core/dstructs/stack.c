/******************************************************************************
 * Filename: stack.h
 * 
 * Description:
 *      Declaration for expression parsing and manupulation of CAMEL.
 *
 * Author: Sergio Madrid
 * Created on: 9/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include "../../../include/core/dstructs/stack.h"


CML_Status cml_charstack_init(CML_CharStack *stack, u32 capacity) {
    if (capacity < 1) {
        capacity = CML_INITIAL_STACK_CAP;
    }

    if (stack == NULL) {
        return CML_ERR_NULL_PTR;
    }

    stack->data = (char**)malloc(capacity * sizeof(char*));
    if (stack->data == NULL) {
        stack->size = 0;
        stack->capacity = 0;
        return CML_ERR_NULL_PTR;
    }
    stack->size = 0;
    stack->capacity = capacity;

    return CML_SUCCESS;
}


void cml_charstack_free(CML_CharStack *stack) {
    if (stack != NULL) {
        if (stack->data != NULL) {
            for (u32 i = 0; i < stack->size; ++i) {
                free(stack->data[i]);
            }
            free(stack->data);
        }
        stack->size = 0;
        stack->capacity = 0;
    }
}


int cml_charstack_isempty(CML_CharStack *stack) {
    return stack->size == 0;
}


CML_Status cml_charstack_push(CML_CharStack *stack, char **input) {
    if (stack == NULL || input == NULL || *input == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (stack->size == stack->capacity) {
        stack->capacity *= 2;
        char **temp = (char**)realloc(stack->data, stack->capacity * sizeof(char*));
        if (!temp) {
            return CML_ERR_NULL_PTR;
        }
        stack->data = temp;
    }

    stack->data[stack->size] = *input; 
    *input = NULL;
    ++stack->size;

    return CML_SUCCESS;
}


char *cml_charstack_pop(CML_CharStack *stack) {
    if (stack == NULL || stack->size == 0) {
        return NULL;
    }

    char *out = stack->data[stack->size - 1];
    stack->data[stack->size - 1] = NULL;
    --stack->size;

    return out;
}


char *cml_charstack_peek(CML_CharStack *stack) {
    if (stack == NULL || stack->size == 0) {
        return NULL;
    }

    return stack->data[stack->size - 1];
}



CML_Status cml_intstack_init(CML_IntStack *stack, u32 capacity) {
    if (capacity < 1) {
        capacity = CML_INITIAL_STACK_CAP;
    }

    if (stack == NULL) {
        return CML_ERR_NULL_PTR;
    }

    stack->data = (i64*)malloc(capacity * sizeof(i64));
    if (stack->data == NULL) {
        stack->size = 0;
        stack->capacity = 0;
        return CML_ERR_NULL_PTR;
    }
    stack->size = 0;
    stack->capacity = capacity;

    return CML_SUCCESS;
}


void cml_intstack_free(CML_IntStack *stack) {
    if (stack != NULL) {
        if (stack->data != NULL) {
            free(stack->data);
        }
        stack->size = 0;
        stack->capacity = 0;
    }
}


int cml_intstack_isempty(CML_CharStack *stack) {
    return stack->size == 0;
}


CML_Status cml_intstack_push(CML_IntStack *stack, i64 input) {
    if (stack == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (stack->size == stack->capacity) {
        stack->capacity *= 2;
        i64 *temp = (i64*)realloc(stack->data, stack->capacity * sizeof(i64));
        if (!temp) {
            return CML_ERR_NULL_PTR;
        }
        stack->data = temp;
    }

    stack->data[stack->size] = input; 
    ++stack->size;

    return CML_SUCCESS;
}


i64 cml_intstack_pop(CML_IntStack *stack) {
    if (stack == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (stack->size == 0) {
        return CML_ERR_INVALID_SIZE;
    }

    int out = stack->data[stack->size - 1];
    --stack->size;

    return out;
}


i64 cml_intstack_peek(CML_IntStack *stack) {
    if (stack == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (stack->size == 0) {
        return CML_ERR_INVALID_SIZE;
    }

    return stack->data[stack->size - 1];
}



CML_Status cml_doublestack_init(CML_DoubleStack *stack, u32 capacity) {
    if (capacity < 1) {
        capacity = CML_INITIAL_STACK_CAP;
    }

    if (stack == NULL) {
        return CML_ERR_NULL_PTR;
    }

    stack->data = (f64*)malloc(capacity * sizeof(f64));
    if (stack->data == NULL) {
        stack->size = 0;
        stack->capacity = 0;
        return CML_ERR_NULL_PTR;
    }
    stack->size = 0;
    stack->capacity = capacity;

    return CML_SUCCESS;
}


void cml_doublestack_free(CML_DoubleStack *stack) {
    if (stack != NULL) {
        if (stack->data != NULL) {
            free(stack->data);
        }
        stack->size = 0;
        stack->capacity = 0;
    }
}


int cml_doublestack_isempty(CML_DoubleStack *stack) {
    return stack->size == 0;
}


CML_Status cml_doublestack_push(CML_DoubleStack *stack, f64 input) {
    if (stack == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (stack->size == stack->capacity) {
        stack->capacity *= 2;
        double *temp = (f64*)realloc(stack->data, stack->capacity * sizeof(f64));
        if (!temp) {
            return CML_ERR_NULL_PTR;
        }
        stack->data = temp;
    }

    stack->data[stack->size] = input; 
    ++stack->size;

    return CML_SUCCESS;
}


f64 cml_doublestack_pop(CML_DoubleStack *stack) {
    if (stack == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (stack->size == 0) {
        return CML_ERR_INVALID_SIZE;
    }

    double out = stack->data[stack->size - 1];
    --stack->size;

    return out;
}


f64 cml_doublestack_peek(CML_DoubleStack *stack) {
    if (stack == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (stack->size == 0) {
        return CML_ERR_INVALID_SIZE;
    }

    return stack->data[stack->size - 1];
}
