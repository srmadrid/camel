/**
 * @file stack.h
 * 
 * @brief Declaration for expression parsing and manupulation of CAMEL.
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


/** @brief Default capacity of a stack. */
#define CML_INITIAL_STACK_CAP  8


/**
 * @brief Represents a stack of void pointers.
 * 
 * @note NOT FINISHED.
 */
typedef struct {
    void **data;
    u32 size;
    u32 capacity;
} CML_Stack;


#endif /* CAMEL_STACK */
