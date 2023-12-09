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


#define CAMEL_API static inline

typedef enum {
    CAMEL_TRUE = 1,
    CAMEL_FALSE = 0,
} CML_Bool;


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

#endif /* CAMEL_MACROS */
