/******************************************************************************
 * Filename: stack.h
 * 
 * Description:
 *      Declaration for expression parsing and manupulation of CAMEL.
 *
 * Author: Sergio Madrid
 * Created on: 20/11/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/

#ifndef CAMEL_STACK
#define CAMEL_STACK

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../macros.h"
#include "../err.h"

#define CML_INITIAL_STACK_CAP  8

/******************************************************************************
 * Struct: CML_CharStack
 * 
 * Description:
 *      Stack data structure holding char arrays.
 *
 * Fields:
 *      char   **data   - Array of arrays of chars, data of the stack.
 *      size_t size     - Number of elements held, postion of top element + 1.
 *      size_t capacity - Current size of the array, maximum amount of elements
 *                        that can fit until a resize is needed.
 *
 * Notes:
 *      All char arrays inside of the data must end in NULL since it doesn't
 *      keep track of each of its sizes.
 *****************************************************************************/
typedef struct {
    char **data;
    size_t size;
    size_t capacity;
} CML_CharStack;


/******************************************************************************
 * Function: cml_charstack_init
 * 
 * Description:
 *      Initializes a CML_CharStack with the input capacity. If a size smaller
 *      than 1 is selected, the default initial size of 8 will be used.
 *
 * Parameters:
 *      size_t capacity - Initial capacity of the stack.
 * 
 * Returns:
 *      A pointer to the initialized CML_CharStack.
 *****************************************************************************/
CAMEL_API CML_CharStack *cml_charstack_init(size_t capacity) {
    if (capacity < 1) {
        capacity = CML_INITIAL_STACK_CAP;
    }

    CML_CharStack *out = (CML_CharStack*)malloc(sizeof(CML_CharStack));
    if (out == NULL) {
        return NULL;
    }

    out->data = (char**)malloc(capacity * sizeof(char*));
    if (out->data == NULL) {
        return NULL;
    }
    out->size = 0;
    out->capacity = capacity;

    return out;
}


/******************************************************************************
 * Function: cml_charstack_free
 * 
 * Description:
 *      Frees the input CML_CharStack.
 *
 * Parameters:
 *      CML_CharStack *stack - Input stack.
 * 
 * Returns:
 *      Void.
 *****************************************************************************/
CAMEL_API void cml_charstack_free(CML_CharStack *stack) {
    if (stack != NULL) {
        if (stack->data != NULL) {
            for (int i = 0; i < stack->size; ++i) {
                free(stack->data[i]);
            }
            free(stack->data);
        }
        free(stack);
    }
}


/******************************************************************************
 * Function: cml_charstack_isempty
 * 
 * Description:
 *      Checks if the stack is empty.
 *
 * Parameters:
 *      CML_CharStack *stack  - Stack to execute the function on.
 * 
 * Returns:
 *      True or false.
 *****************************************************************************/
CAMEL_API int cml_charstack_isempty(CML_CharStack *stack) {
    return stack->size == 0;
}


/******************************************************************************
 * Function: cml_charstack_push
 * 
 * Description:
 *      Pushes the input string into the stack.
 *
 * Parameters:
 *      CML_CharStack *stack  - Stack to execute the function on.
 *      char          **input - Pointer to the input string.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API int cml_charstack_push(CML_CharStack *stack, char **input) {
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


/******************************************************************************
 * Function: cml_charstack_pop
 * 
 * Description:
 *      Pops the top element of the stack.
 *
 * Parameters:
 *      CML_CharStack *stack  - Stack to execute the function on.
 * 
 * Returns:
 *      The top element of the stack.
 *****************************************************************************/
CAMEL_API char *cml_charstack_pop(CML_CharStack *stack) {
    if (stack == NULL || stack->size == 0) {
        return NULL;
    }

    char *out = stack->data[stack->size - 1];
    stack->data[stack->size - 1] = NULL;
    --stack->size;

    return out;
}


/******************************************************************************
 * Function: cml_charstack_peek
 * 
 * Description:
 *      Returns the top element of the stack to be peeked at.
 *
 * Parameters:
 *      CML_CharStack *stack  - Stack to execute the function on.
 * 
 * Returns:
 *      The top element of the stack.
 *
 * Notes:
 *      The function returns the active pointer to the top element of the stack.
 *      It is the users responsibility to not edit it in any way, and to delete
 *      the outside pointer (set it to NULL) once it is no longer needed.
 *****************************************************************************/
CAMEL_API const char *cml_charstack_peek(CML_CharStack *stack) {
    if (stack == NULL || stack->size == 0) {
        return NULL;
    }

    return stack->data[stack->size - 1];
}



/******************************************************************************
 * Struct: CML_IntStack
 * 
 * Description:
 *      Stack data structure holding ints.
 *
 * Fields:
 *      int    *data    - Array of ints, data of the stack.
 *      size_t size     - Number of elements held, postion of top element + 1.
 *      size_t capacity - Current size of the array, maximum amount of elements
 *                        that can fit until a resize is needed.
 *****************************************************************************/
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} CML_IntStack;


/******************************************************************************
 * Function: cml_intstack_init
 * 
 * Description:
 *      Initializes a CML_IntStack with the input capacity. If a size smaller
 *      than 1 is selected, the default initial size of 8 will be used.
 *
 * Parameters:
 *      size_t capacity - Initial capacity of the stack.
 * 
 * Returns:
 *      A pointer to the initialized CML_IntStack.
 *****************************************************************************/
CAMEL_API CML_IntStack *cml_intstack_init(size_t capacity) {
    if (capacity < 1) {
        capacity = CML_INITIAL_STACK_CAP;
    }

    CML_IntStack *out = (CML_IntStack*)malloc(sizeof(CML_IntStack));
    if (out == NULL) {
        return NULL;
    }

    out->data = (int*)malloc(capacity * sizeof(int));
    if (out->data == NULL) {
        return NULL;
    }
    out->size = 0;
    out->capacity = capacity;

    return out;
}


/******************************************************************************
 * Function: cml_intstack_free
 * 
 * Description:
 *      Frees the input CML_IntStack.
 *
 * Parameters:
 *      CML_IntStack *stack - Input stack.
 * 
 * Returns:
 *      Void.
 *****************************************************************************/
CAMEL_API void cml_intstack_free(CML_IntStack *stack) {
    if (stack != NULL) {
        if (stack->data != NULL) {
            free(stack->data);
        }
        free(stack);
    }
}


/******************************************************************************
 * Function: cml_intstack_isempty
 * 
 * Description:
 *      Checks if the stack is empty.
 *
 * Parameters:
 *      CML_IntStack *stack - Stack to execute the function on.
 * 
 * Returns:
 *      True or false.
 *****************************************************************************/
CAMEL_API int cml_intstack_isempty(CML_CharStack *stack) {
    return stack->size == 0;
}


/******************************************************************************
 * Function: cml_intstack_push
 * 
 * Description:
 *      Pushes the input int into the stack.
 *
 * Parameters:
 *      CML_IntStack *stack  - Stack to execute the function on.
 *      int          input   - Input int.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API int cml_intstack_push(CML_IntStack *stack, int input) {
    if (stack == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (stack->size == stack->capacity) {
        stack->capacity *= 2;
        int *temp = (int*)realloc(stack->data, stack->capacity * sizeof(int));
        if (!temp) {
            return CML_ERR_NULL_PTR;
        }
        stack->data = temp;
    }

    stack->data[stack->size] = input; 
    ++stack->size;

    return CML_SUCCESS;
}


/******************************************************************************
 * Function: cml_intstack_pop
 * 
 * Description:
 *      Pops the top element of the stack.
 *
 * Parameters:
 *      CML_IntStack *stack - Stack to execute the function on.
 * 
 * Returns:
 *      The top element of the stack.
 *****************************************************************************/
CAMEL_API int cml_intstack_pop(CML_IntStack *stack) {
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


/******************************************************************************
 * Function: cml_intstack_peek
 * 
 * Description:
 *      Returns the top element of the stack to be peeked at.
 *
 * Parameters:
 *      CML_IntStack *stack - Stack to execute the function on.
 * 
 * Returns:
 *      The top element of the stack.
 *****************************************************************************/
CAMEL_API const int cml_intstack_peek(CML_IntStack *stack) {
    if (stack == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (stack->size == 0) {
        return CML_ERR_INVALID_SIZE;
    }

    return stack->data[stack->size - 1];
}



/******************************************************************************
 * Struct: CML_DoubleStack
 * 
 * Description:
 *      Stack data structure holding doubles.
 *
 * Fields:
 *      double *data    - Array of doubles, data of the stack.
 *      size_t size     - Number of elements held, postion of top element + 1.
 *      size_t capacity - Current size of the array, maximum amount of elements
 *                        that can fit until a resize is needed.
 *****************************************************************************/
typedef struct {
    double *data;
    size_t size;
    size_t capacity;
} CML_DoubleStack;


/******************************************************************************
 * Function: cml_doublestack_init
 * 
 * Description:
 *      Initializes a CML_DoubleStack with the input capacity. If a size smaller
 *      than 1 is selected, the default initial size of 8 will be used.
 *
 * Parameters:
 *      size_t capacity - Initial capacity of the stack.
 * 
 * Returns:
 *      A pointer to the initialized CML_DoubleStack.
 *****************************************************************************/
CAMEL_API CML_DoubleStack *cml_doublestack_init(size_t capacity) {
    if (capacity < 1) {
        capacity = CML_INITIAL_STACK_CAP;
    }

    CML_DoubleStack *out = (CML_DoubleStack*)malloc(sizeof(CML_DoubleStack));
    if (out == NULL) {
        return NULL;
    }

    out->data = (double*)malloc(capacity * sizeof(double));
    if (out->data == NULL) {
        return NULL;
    }
    out->size = 0;
    out->capacity = capacity;

    return out;
}


/******************************************************************************
 * Function: cml_doublestack_free
 * 
 * Description:
 *      Frees the input CML_DoubleStack.
 *
 * Parameters:
 *      CML_DoubleStack *stack - Input stack.
 * 
 * Returns:
 *      Void.
 *****************************************************************************/
CAMEL_API void cml_doublestack_free(CML_DoubleStack *stack) {
    if (stack != NULL) {
        if (stack->data != NULL) {
            free(stack->data);
        }
        free(stack);
    }
}


/******************************************************************************
 * Function: cml_doublestack_isempty
 * 
 * Description:
 *      Checks if the stack is empty.
 *
 * Parameters:
 *      CML_DoubleStack *stack - Stack to execute the function on.
 * 
 * Returns:
 *      True or false.
 *****************************************************************************/
CAMEL_API int cml_doublestack_isempty(CML_DoubleStack *stack) {
    return stack->size == 0;
}


/******************************************************************************
 * Function: cml_doublestack_push
 * 
 * Description:
 *      Pushes the input double into the stack.
 *
 * Parameters:
 *      CML_DoubleStack *stack  - Stack to execute the function on.
 *      double          input   - Input double.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API int cml_doublestack_push(CML_DoubleStack *stack, double input) {
    if (stack == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (stack->size == stack->capacity) {
        stack->capacity *= 2;
        double *temp = (double*)realloc(stack->data, stack->capacity * sizeof(double));
        if (!temp) {
            return CML_ERR_NULL_PTR;
        }
        stack->data = temp;
    }

    stack->data[stack->size] = input; 
    ++stack->size;

    return CML_SUCCESS;
}


/******************************************************************************
 * Function: cml_doublestack_pop
 * 
 * Description:
 *      Pops the top element of the stack.
 *
 * Parameters:
 *      CML_DoubleStack *stack - Stack to execute the function on.
 * 
 * Returns:
 *      The top element of the stack.
 *****************************************************************************/
CAMEL_API double cml_doublestack_pop(CML_DoubleStack *stack) {
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


/******************************************************************************
 * Function: cml_doublestack_peek
 * 
 * Description:
 *      Returns the top element of the stack to be peeked at.
 *
 * Parameters:
 *      CML_DoubleStack *stack - Stack to execute the function on.
 * 
 * Returns:
 *      The top element of the stack.
 *****************************************************************************/
CAMEL_API const double cml_doublestack_peek(CML_DoubleStack *stack) {
    if (stack == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (stack->size == 0) {
        return CML_ERR_INVALID_SIZE;
    }

    return stack->data[stack->size - 1];
}
// Make stack for CML_ExpressionToken and other types that may arise

#endif /* CAMEL_STACK */
