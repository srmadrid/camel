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


/******************************************************************************
 * Function: cml_u8_debug
 * 
 * Description:
 *      Returns a debug message comparing the input u8s.
 *
 * Parameters:
 *      u8 expected - Expected uint.
 *      u8 got - Result uint.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_API char *cml_u8_debug(u8 expected, u8 got);


/******************************************************************************
 * Function: cml_u16_debug
 * 
 * Description:
 *      Returns a debug message comparing the input u16s.
 *
 * Parameters:
 *      u16 expected - Expected uint.
 *      u16 got - Result uint.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_API char *cml_u16_debug(u16 expected, u16 got);


/******************************************************************************
 * Function: cml_u32_debug
 * 
 * Description:
 *      Returns a debug message comparing the input u32s.
 *
 * Parameters:
 *      u32 expected - Expected uint.
 *      u32 got - Result uint.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_API char *cml_u32_debug(u32 expected, u32 got);


/******************************************************************************
 * Function: cml_u64_debug
 * 
 * Description:
 *      Returns a debug message comparing the input u64s.
 *
 * Parameters:
 *      u64 expected - Expected uint.
 *      u64 got - Result uint.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_API char *cml_u64_debug(u64 expected, u64 got);


/******************************************************************************
 * Function: cml_i8_debug
 * 
 * Description:
 *      Returns a debug message comparing the input i8s.
 *
 * Parameters:
 *      i8 expected - Expected int.
 *      i8 got - Result int.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_API char *cml_i8_debug(i8 expected, i8 got);


/******************************************************************************
 * Function: cml_i16_debug
 * 
 * Description:
 *      Returns a debug message comparing the input i16s.
 *
 * Parameters:
 *      i16 expected - Expected int.
 *      i16 got - Result int.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_API char *cml_i16_debug(i16 expected, i16 got);


/******************************************************************************
 * Function: cml_i32_debug
 * 
 * Description:
 *      Returns a debug message comparing the input i32s.
 *
 * Parameters:
 *      i32 expected - Expected int.
 *      i32 got - Result int.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_API char *cml_i32_debug(i32 expected, i32 got);


/******************************************************************************
 * Function: cml_i64_debug
 * 
 * Description:
 *      Returns a debug message comparing the input i64s.
 *
 * Parameters:
 *      i64 expected - Expected int.
 *      i64 got - Result int.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_API char *cml_i64_debug(i64 expected, i64 got);


/******************************************************************************
 * Function: cml_f32_debug
 * 
 * Description:
 *      Returns a debug message comparing the input f32s.
 *
 * Parameters:
 *      f32 expected - Expected float.
 *      f32 got - Result float.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_API char *cml_f32_debug(f32 expected, f32 got);


/******************************************************************************
 * Function: cml_f64_debug
 * 
 * Description:
 *      Returns a debug message comparing the input f64s.
 *
 * Parameters:
 *      f64 expected - Expected float.
 *      f64 got - Result float.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_API char *cml_f64_debug(f64 expected, f64 got);

// TODO: Add debug functions for CML_Bool and arrays of numbers.


#define CML_TERMINAL_RED    "\x1b[31m"
#define CML_TERMINAL_GREEN  "\x1b[32m"
#define CML_TERMINAL_YELLOW "\x1b[33m"
#define CML_TERMINAL_BLUE   "\x1b[34m"
#define CML_TERMINAL_MAGENTA "\x1b[35m"
#define CML_TERMINAL_CYAN   "\x1b[36m"
#define CML_TERMINAL_RESET  "\x1b[0m"


#endif /* CAMEL_MACROS */
