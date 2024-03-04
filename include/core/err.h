/**
 * @file err.h
 * 
 * @brief Error handling code for CAMEL.
 *
 * @author Sergio Madrid
 * @date 8/11/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_ERROR
#define CAMEL_ERROR


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "macros.h"


/**
 * @brief Status codes for CAMEL.
 */
typedef enum CML_Status {
    /** @brief Operation was successful. */
    CML_SUCCESS = 1,
    /** @brief Null pointer passed as input. */
    CML_ERR_NULL_PTR = -1,
    /** @brief Malloc failed. */
    CML_ERR_MALLOC = -2,
    /** @brief Realloc failed. */
    CML_ERR_REALLOC = -3,
    /** @brief Calloc failed. */
    CML_ERR_CALLOC,
    /** @brief Invalid capacity. */
    CML_ERR_INVALID_CAPACITY = -4,
    /** @brief Invalid size for the input. */
    CML_ERR_INVALID_SIZE = -5,
    /** @brief Matrix is singular. */
    CML_ERR_SINGULAR_MATRIX = -6,
    /** @brief Invalid character. */
    CML_ERR_INVALID_CHAR = -7,
    /** @brief Invalid index. */
    CML_ERR_INVALID_INDEX = -8,
    /** @brief Empty structure. */
    CML_ERR_EMPTY_STRUCTURE = -9,
    /** @brief Expected vector. */
    CML_ERR_EXPECTED_VECTOR,
    /** @brief Invalid permuatation. */
    CML_ERR_INVALID_PERMUTATION,
} CML_Status;


/**
 * @brief Returns a string representation of the input CML_Status.
 *
 * @param status Status to convert to string.
 * 
 * @return String representation of the status.
 */
char* cml_status_to_str(CML_Status status);


/**
 * @brief Returns a debug message comparing the input CML_Status.
 *
 * @param expected The expected CML_Status.
 * @param got      The result CML_Status.
 * 
 * @return A string containing the debug message.
 */
char *cml_status_debug(CML_Status expected, CML_Status got);


/**
 * @brief Returns a debug message comparing the input u8.
 * 
 * @param expected Expected uint.
 * @param got      Result uint.
 * 
 * @return A string containing the debug message.
 */
char *cml_u8_debug(u8 expected, u8 got);


/**
 * @brief Returns a debug message comparing the input u16.
 * 
 * @param expected Expected uint.
 * @param got      Result uint.
 * 
 * @return A string containing the debug message.
 */
char *cml_u16_debug(u16 expected, u16 got);


/**
 * @brief Returns a debug message comparing the input u32.
 * 
 * @param expected Expected uint.
 * @param got      Result uint.
 * 
 * @return A string containing the debug message.
 */
char *cml_u32_debug(u32 expected, u32 got);


/**
 * @brief Returns a debug message comparing the input u64.
 * 
 * @param expected Expected uint.
 * @param got      Result uint.
 * 
 * @return A string containing the debug message.
 */
char *cml_u64_debug(u64 expected, u64 got);


/**
 * @brief Returns a debug message comparing the input i8.
 * 
 * @param expected Expected int.
 * @param got      Result int.
 * 
 * @return A string containing the debug message.
 */
char *cml_i8_debug(i8 expected, i8 got);


/**
 * @brief Returns a debug message comparing the input i16.
 * 
 * @param expected Expected int.
 * @param got      Result int.
 * 
 * @return A string containing the debug message.
 */
char *cml_i16_debug(i16 expected, i16 got);


/**
 * @brief Returns a debug message comparing the input i32.
 * 
 * @param expected Expected int.
 * @param got      Result int.
 * 
 * @return A string containing the debug message.
 */
char *cml_i32_debug(i32 expected, i32 got);


/**
 * @brief Returns a debug message comparing the input i64.
 * 
 * @param expected Expected int.
 * @param got      Result int.
 * 
 * @return A string containing the debug message.
 */
char *cml_i64_debug(i64 expected, i64 got);


/**
 * @brief Returns a debug message comparing the input f32s.
 * 
 * @param expected Expected float.
 * @param got      Result float.
 * 
 * @return A string containing the debug message.
 */
char *cml_f32_debug(f32 expected, f32 got);


/**
 * @brief Returns a debug message comparing the input f64s.
 * 
 * @param expected Expected float.
 * @param got      Result float.
 * 
 * @return A string containing the debug message.
 */
char *cml_f64_debug(f64 expected, f64 got);

// TODO: Add debug functions for CML_Bool and arrays of numbers.


#endif /* CAMEL_ERROR */
