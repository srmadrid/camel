/******************************************************************************
 * Filename: macros.h
 * 
 * Description:
 *      Declaration of most macros of CAMEL.
 *
 * Author: Sergio Madrid
 * Created on: 8/11/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/

#ifndef CAMEL_MACROS
#define CAMEL_MACROS


#include <stdint.h>


#define CAMEL_API inline
#define CAMEL_STATIC static


typedef enum {
    CML_TRUE = 1,
    CML_FALSE = 0,
} CML_Bool;


typedef enum {
    CML_LOWER = -1,
    CML_EQUAL = 0,
    CML_GREATER = 1,
} CML_Comparison;



// Unsigned int types.
typedef uint8_t  u8;   /** @brief Unsigned 8-bit integer */
typedef uint16_t u16;  /** @brief Unsigned 16-bit integer */
typedef uint32_t u32;  /** @brief Unsigned 32-bit integer */
typedef uint64_t u64;  /** @brief Unsigned 64-bit integer */

// Signed int types.
typedef int8_t  i8;   /** @brief Signed 8-bit integer */
typedef int16_t i16;  /** @brief Signed 16-bit integer */
typedef int32_t i32;  /** @brief Signed 32-bit integer */
typedef int64_t i64;  /** @brief Signed 64-bit integer */

// Floating point types.
typedef float  f32;   /** @brief 32-bit floating point number */
typedef double f64;   /** @brief 64-bit floating point number */



#define CML_TERMINAL_RED    "\x1b[31m"
#define CML_TERMINAL_GREEN  "\x1b[32m"
#define CML_TERMINAL_YELLOW "\x1b[33m"
#define CML_TERMINAL_BLUE   "\x1b[34m"
#define CML_TERMINAL_MAGENTA "\x1b[35m"
#define CML_TERMINAL_CYAN   "\x1b[36m"
#define CML_TERMINAL_RESET  "\x1b[0m"


#endif /* CAMEL_MACROS */
