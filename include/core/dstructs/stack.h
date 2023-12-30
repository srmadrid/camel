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
 *      u32 size     - Number of elements held, postion of top element + 1.
 *      u32 capacity - Current size of the array, maximum amount of elements
 *                        that can fit until a resize is needed.
 *
 * Notes:
 *      All char arrays inside of the data must end in NULL since it doesn't
 *      keep track of each of its sizes.
 *****************************************************************************/
typedef struct {
    char **data;
    u32 size;
    u32 capacity;
} CML_CharStack;


/******************************************************************************
 * Function: cml_charstack_init
 * 
 * Description:
 *      Initializes the input CML_CharStack with the input capacity. If a size 
 *      smaller than 1 is selected, the default initial size of 8 will be used.
 *
 * Parameters:
 *      CML_CharStack *stack   - Stack to be initiallized.
 *      u32        capacity - Initial capacity of the stack.
 * 
 * Returns:
 *      A pointer to the initialized CML_CharStack.
 *****************************************************************************/
CML_Status cml_charstack_init(CML_CharStack *stack, u32 capacity);


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
void cml_charstack_free(CML_CharStack *stack);


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
int cml_charstack_isempty(CML_CharStack *stack);


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
CML_Status cml_charstack_push(CML_CharStack *stack, char **input);


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
char *cml_charstack_pop(CML_CharStack *stack);


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
char *cml_charstack_peek(CML_CharStack *stack);



/******************************************************************************
 * Struct: CML_IntStack
 * 
 * Description:
 *      Stack data structure holding ints.
 *
 * Fields:
 *      i64    *data    - Array of ints, data of the stack.
 *      u32 size     - Number of elements held, postion of top element + 1.
 *      u32 capacity - Current size of the array, maximum amount of elements
 *                        that can fit until a resize is needed.
 *****************************************************************************/
typedef struct {
    i64 *data;
    u32 size;
    u32 capacity;
} CML_IntStack;


/******************************************************************************
 * Function: cml_intstack_init
 * 
 * Description:
 *      Initializes the input CML_IntStack with the input capacity. If a size 
 *      smaller than 1 is selected, the default initial size of 8 will be used.
 *
 * Parameters:
 *      CML_IntStack *stack   - Stack to be initialized.
 *      u32       capacity - Initial capacity of the stack.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CML_Status cml_intstack_init(CML_IntStack *stack, u32 capacity);


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
void cml_intstack_free(CML_IntStack *stack);


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
int cml_intstack_isempty(CML_CharStack *stack);


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
CML_Status cml_intstack_push(CML_IntStack *stack, i64 input);


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
i64 cml_intstack_pop(CML_IntStack *stack); 


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
i64 cml_intstack_peek(CML_IntStack *stack);



/******************************************************************************
 * Struct: CML_DoubleStack
 * 
 * Description:
 *      Stack data structure holding doubles.
 *
 * Fields:
 *      f64 *data    - Array of doubles, data of the stack.
 *      u32 size     - Number of elements held, postion of top element + 1.
 *      u32 capacity - Current size of the array, maximum amount of elements
 *                        that can fit until a resize is needed.
 *****************************************************************************/
typedef struct {
    f64 *data;
    u32 size;
    u32 capacity;
} CML_DoubleStack;


/******************************************************************************
 * Function: cml_doublestack_init
 * 
 * Description:
 *      Initializes the input CML_DoubleStack with the input capacity. If a 
 *      size smaller than 1 is selected, the default initial size of 8 will be 
 *      used.
 *
 * Parameters:
 *      CML_DoubleStack *stack   - The stack to be initialized.
 *      u32          capacity - Initial capacity of the stack.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CML_Status cml_doublestack_init(CML_DoubleStack *stack, u32 capacity);


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
void cml_doublestack_free(CML_DoubleStack *stack);


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
int cml_doublestack_isempty(CML_DoubleStack *stack);


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
CML_Status cml_doublestack_push(CML_DoubleStack *stack, f64 input);


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
f64 cml_doublestack_pop(CML_DoubleStack *stack);


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
f64 cml_doublestack_peek(CML_DoubleStack *stack);
// Make stack for CML_ExpressionToken and other types that may arise

#endif /* CAMEL_STACK */
