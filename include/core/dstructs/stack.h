/**
 * @file stack.h
 * 
 * @brief Declaration for the stack data structure.
 *
 * @author Sergio Madrid
 * @date 20/11/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_STACK
#define CAMEL_STACK

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../macros.h"
#include "../err.h"
#include "../memory/allocator.h"


/** @brief Default capacity of a stack. */
#define CML_INITIAL_STACK_CAPACITY  1


/** @brief Default resize factor of the stack. */
#define CML_STACK_RESIZE_FACTOR 2


/**
 * @brief Represents a stack.
 */
typedef struct CML_Stack {
    /** @brief Pointer to the data of the stack. */
    void *data;
    /** @brief Length of the stack. */
    u32 length;
    /** @brief Capacity of the stack. */
    u32 capacity;
    /** @brief Size of each element in the stack in bytes. */
    u32 stride;
    /** @brief Allocator used for dynamic memory management within the 
     *         structure. */
    CML_Allocator *allocator;
    /** @brief Freeing function for the elements of the stack. */
    void (*destroyFn)(void *element);
} CML_Stack;



/**
 * @brief Initializes a CML_Stack with the input capacity and stride.
 * 
 * @param allocator Allocator for the stack.
 * @param capacity Initial capacity of the stack.
 * @param stride   Size of each element in the stack in bytes.
 * @param destroyFn   Freeing function for the elements of the stack.
 * @param darray   Pointer to the CML_Stack to be initialized.
 * 
 * @return Status code.
 */
CML_Status _cml_stack_init(CML_Allocator *allocator, u32 capacity, u32 stride, void (*destroyFn)(void *element), CML_Stack *stack);


/**
 * @brief Initializes a CML_Stack with the input type and size.
 * 
 * @param allocator Allocator for the stack.
 * @param capacity Initial capacity of the stack.
 * @param type     Type of the stack.
 * @param destroyFn   Freeing function for the elements of the stack.
 * @param stack    Pointer to the CML_Stack to be initialized.
 * 
 * @return Status code.
 */
#define cml_stack_init(allocator, capacity, type, destroyFn, stack) _cml_stack_init(allocator, capacity, sizeof(type), destroyFn, stack)


/**
 * @brief Initializes a CML_Stack with the input type and default capacity.
 * 
 * @param allocator Allocator for the stack.
 * @param type   Type of the array.
 * @param destroyFn Freeing function for the elements of the array.
 * @param stack  Pointer to the CML_Stack to be initialized.
 * 
 * @return Status code.
 */
#define cml_stack_init_default(allocator, type, destroyFn, stack) _cml_stack_init(allocator, CML_INITIAL_STACK_CAPACITY, sizeof(type), destroyFn, stack)


/**
 * @brief Frees the internal memory of a CML_Stack and its elements using the 
 *        freeing function stored in the CML_Stack.
 * 
 * @param stack The CML_Stack to be freed.
 * 
 * @return void.
 */
void cml_stack_destroy(CML_Stack *stack);


/**
 * @brief Resizes a CML_Stack to the input size.
 * 
 * @param capacity The new capacity of the array.
 * @param out      The CML_Stack to be resized.
 * 
 * @return Status code.
 */
CML_Status cml_stack_resize(u32 capacity, CML_Stack *out);


/**
 * @brief Pushes a copy of an element to the end of a CML_Stack.
 * 
 * @param element Pointer to the element to be pushed.
 * @param out     The CML_Stack to be pushed to.
 * 
 * @return Status code.
 */
CML_Status cml_stack_push(void *element, CML_Stack *out);


/**
 * @brief Pops an element from the top of a CML_Stack.
 * 
 * @param out The CML_Stack to be popped from.
 * 
 * @return The popped element.
 */
void *cml_stack_pop(CML_Stack *out);


/**
 * @brief Gets the element at the top of a CML_Stack.
 * 
 * @param out   The CML_Stack to be retrieved from.
 * 
 * @return A pointer to the element at the top.
 */
void *cml_stack_get(u32 index, CML_Stack *out);


/**
 * @brief Compares two CML_Stack for equality.
 * 
 * @param stack1 The first CML_Stack to be compared.
 * @param stack2 The second CML_Stack to be compared.
 * 
 * @return Boolean value indicating whether the two CML_Stack are equal.
 */
b8 cml_stack_eq(CML_Stack *stack1, CML_Stack *stack2);


/**
 * @brief Returns a debug message comparing the input stacks.
 *
 * @param expected The expected stack.
 * @param got      The result stack.
 * @param bervose  Whether to print all the stack data or not.
 * 
 * @return A string containing the debug message.
 */
char *cml_stack_debug(CML_Stack *expected, CML_Stack *got, b8 verbose);


#endif /* CAMEL_STACK */
