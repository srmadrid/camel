/******************************************************************************
 * Filename: bigint.h
 * 
 * Description:
 *      Declaration for arbitrary precision integers of CAMEL.
 *
 * Author: Sergio Madrid
 * Created on: 23/11/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/

#ifndef CAMEL_BIGINT
#define CAMEL_BIGINT

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../macros.h"
#include "../err.h"

#define CML_INITIAL_BIGINT_CAP  2

/******************************************************************************
 * Struct: CML_BigInt
 * 
 * Description:
 *      Arbitrary precision integer.
 *
 * Fields:
 *      u32 *data    - Array holding the number data.
 *      size_t   size     - Number of elements with data (>0x00000001).
 *      size_t   capacity - Current size of the array, maximum amount of elements
 *                          that can fit until a resize is needed.
 *      int      sign     - Sign of the number (-1: Negative; 1: Positive).
 *****************************************************************************/
typedef struct {
    u32 *data;
    size_t size;
    size_t capacity;
    int sign;
} CML_BigInt;


/******************************************************************************
 * Function: cml_bigint_init
 * 
 * Description:
 *      Initializes the input CML_BigInt with the input capacity, and sets its 
 *      value to 0. If a size under 2 is passed, the default initial size of 
 *      2 will be used.
 *
 * Parameters:
 *      CML_BigInt *bigint - Big int to be initialized.
 *      size_t capacity    - Initial capacity of the bigint.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_bigint_init(CML_BigInt *bigint, size_t capacity);


/******************************************************************************
 * Function: cml_bigint_free
 * 
 * Description:
 *      Frees the input CML_BigInt.
 *
 * Parameters:
 *      CML_BigInt *bigint - Input big int.
 * 
 * Returns:
 *      Void.
 *****************************************************************************/
CAMEL_API void cml_bigint_free(CML_BigInt *bigint);


/******************************************************************************
 * Function: cml_bigint_set_int
 * 
 * Description:
 *      Sets the input CML_BigInt to the input uint64_t.
 *
 * Parameters:
 *      CML_BigInt *bigint - Big int to set.
 *      u64   input   - Number to be set into the big int.
 *      int        sign    - Sign of the input number. Done separately to be
 *                           able to input a higher range of numbers.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_bigint_set_int(CML_BigInt *bigint, u64 input, int sign);


/******************************************************************************
 * Function: cml_bigint_set_str
 * 
 * Description:
 *      Sets the input CML_BigInt to the input char array (string).
 *
 * Parameters:
 *      CML_BigInt *bigint - Big int to set.
 *      char       *input  - Number to be set into the big int.
 * 
 * Returns:
 *      Success or error code.
 *
 * Notes:
 *      While with an int the sign is entered separately to allow for a bigger
 *      range of numbers, here the sign must be included in the number. If no
 *      sign is there, positive will be assumed, otherwise a - must be at the 
 *      beginning, like "-20".
 *****************************************************************************/


/******************************************************************************
 * Function: cml_bigint_set_str
 * 
 * Description:
 *      Sets the input CML_BigInt to the input char array (string).
 *
 * Parameters:
 *      CML_BigInt *bigint - Big int to set.
 *      char       *input  - Number to be set into the big int.
 * 
 * Returns:
 *      Success or error code.
 *
 * Notes:
 *      While with an int the sign is entered separately to allow for a bigger
 *      range of numbers, here the sign must be included in the number. If no
 *      sign is there, positive will be assumed, otherwise a - must be at the 
 *      beginning, like "-20".
 *****************************************************************************/

// Implement addition, subtraction, multiplication, division, exponentiation, etc.
#endif /* CAMEL_BIGINT */
