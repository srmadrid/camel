/******************************************************************************
 * Filename: err.h
 * 
 * Description:
 *      Error handling code for CAMEL.
 *
 * Author: Sergio Madrid
 * Created on: 8/11/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/

#ifndef CAMEL_ERROR
#define CAMEL_ERROR


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "macros.h"


typedef enum {
    CML_SUCCESS = 1,
    CML_ERR_INVALID_SIZE = -1,
    CML_ERR_NULL_PTR = -2,
    CML_ERR_SINGULAR_MATRIX = -3,
} CML_Status;


/******************************************************************************
 * Function: cml_status_to_str
 * 
 * Description:
 *      Returns a string representation of the input CML_Status.
 *
 * Parameters:
 *      CML_Status status - Status to convert to string.
 * 
 * Returns:
 *      String representation of the status.
 *****************************************************************************/
char* cml_status_to_str(CML_Status status);


/******************************************************************************
 * Function: cml_status_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Statuses.
 *
 * Parameters:
 *      CML_Status expected - Expected status.
 *      CML_Status got      - Result status.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
char *cml_status_debug(CML_Status expected, CML_Status got);


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
char *cml_u8_debug(u8 expected, u8 got);


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
char *cml_u16_debug(u16 expected, u16 got);


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
char *cml_u32_debug(u32 expected, u32 got);


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
char *cml_u64_debug(u64 expected, u64 got);


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
char *cml_i8_debug(i8 expected, i8 got);


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
char *cml_i16_debug(i16 expected, i16 got);


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
char *cml_i32_debug(i32 expected, i32 got);


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
char *cml_i64_debug(i64 expected, i64 got);


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
char *cml_f32_debug(f32 expected, f32 got);


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
char *cml_f64_debug(f64 expected, f64 got);

// TODO: Add debug functions for CML_Bool and arrays of numbers.


#endif /* CAMEL_ERROR */
