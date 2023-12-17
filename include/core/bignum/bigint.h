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
 *      i8       sign     - Sign of the number (-1: Negative; 1: Positive).
 *****************************************************************************/
typedef struct {
    u32 *data;
    size_t size;
    size_t capacity;
    i8 sign;
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
CAMEL_API CML_Status cml_bigint_set_str(CML_BigInt *bigint, char *input);


/******************************************************************************
 * Function: cml_bigint_set
 * 
 * Description:
 *      Sets the input CML_BigInt to the input CML_BigInt.
 *
 * Parameters:
 *      CML_BigInt *bigint - Big int to set.
 *      CML_BigInt *input  - Number to be set into the big int.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_bigint_set(CML_BigInt *bigint, CML_BigInt *input);


/******************************************************************************
 * Function: cml_bigint_to_str
 * 
 * Description:
 *      Converts the input CML_BigInt to a string.
 *
 * Parameters:
 *      CML_BigInt *bigint - Big int to convert.
 * 
 * Returns:
 *      String representation of the big int.
 *****************************************************************************/
CAMEL_API char *cml_bigint_to_str(CML_BigInt *bigint);


/******************************************************************************
 * Function: cml_bigint_to_bin_str
 * 
 * Description:
 *      Converts the input CML_BigInt to a binary string.
 *
 * Parameters:
 *      CML_BigInt *bigint - Big int to convert.
 * 
 * Returns:
 *      Binary string representation of the big int.
 *****************************************************************************/
CAMEL_API char *cml_bigint_to_bin_str(CML_BigInt *bigint);

// Implement addition, subtraction, multiplication, division, exponentiation, etc.


/******************************************************************************
 * Function: cml_bigint_eq
 * 
 * Description:
 *      Compares two CML_BigInts for equality.
 * 
 * Parameters:
 *      CML_BigInt *bigint1 - First big int to compare.
 *      CML_BigInt *bigint2 - Second big int to compare.
 * 
 * Returns:
 *      CML_TRUE if bigint1 == bigint2, CML_FALSE otherwise.
 *****************************************************************************/
CAMEL_API CML_Bool cml_bigint_eq(CML_BigInt *bigint1, CML_BigInt *bigint2);


/******************************************************************************
 * Function: cml_bigint_compare
 * 
 * Description:
 *      Compares two CML_BigInts.
 *
 * Parameters:
 *      CML_BigInt *bigint1 - First big int to compare.
 *      CML_BigInt *bigint2 - Second big int to compare.
 * 
 * Returns:
 *      CML_LOWER if bigint1 < bigint2, CML_EQUAL if bigint1 == bigint2,
 *      CML_GREATER if bigint1 > bigint2.
 *****************************************************************************/
CAMEL_API CML_Comparison cml_bigint_compare(CML_BigInt *bigint1, CML_BigInt *bigint2);


/******************************************************************************
 * Function: cml_bigint_eq_int
 * 
 * Description:
 *      Compares a CML_BigInt to an int for equality.
 * 
 * Parameters:
 *      CML_BigInt *bigint - Big int to compare.
 *      u64   input   - Number to be compared to the big int.
 *      i8    sign    - Sign of the input number. Done separately to be
 *                      able to input a higher range of numbers.
 * 
 * Returns:
 *      CML_TRUE if bigint == input, CML_FALSE otherwise.
 *****************************************************************************/
CAMEL_API CML_Bool cml_bigint_eq_int(CML_BigInt *bigint, u64 input, i8 sign);


/******************************************************************************
 * Function: cml_bigint_compare_int
 * 
 * Description:
 *      Compares a CML_BigInt to an int.
 * 
 * Parameters:
 *      CML_BigInt *bigint - Big int to compare.
 *      u64   input   - Number to be compared to the big int.
 *      i8    sign    - Sign of the input number. Done separately to be
 *                      able to input a higher range of numbers.
 * 
 * Returns:
 *      CML_LOWER if bigint < input, CML_EQUAL if bigint == input,
 *      CML_GREATER if bigint > input.
 *****************************************************************************/
CAMEL_API CML_Comparison cml_bigint_compare_int(CML_BigInt *bigint, u64 input, i8 sign);


/******************************************************************************
 * Function: cml_bigint_eq_str
 * 
 * Description:
 *      Compares a CML_BigInt to a string for equality.
 *
 * Parameters:
 *      CML_BigInt *bigint - Big int to compare.
 *      char       *str    - String to compare.
 * 
 * Returns:
 *      CML_TRUE if bigint == str, CML_FALSE otherwise.
 *****************************************************************************/
CAMEL_API CML_Bool cml_bigint_eq_str(CML_BigInt *bigint, char *str);


/******************************************************************************
 * Function: cml_bigint_compare_str
 * 
 * Description:
 *      Compares a CML_BigInt to a string.
 *
 * Parameters:
 *      CML_BigInt *bigint - Big int to compare.
 *      char       *str    - String to compare.
 * 
 * Returns:
 *      CML_LOWER if bigint < str, CML_EQUAL if bigint == str,
 *      CML_GREATER if bigint > str.
 *****************************************************************************/
CAMEL_API CML_Comparison cml_bigint_compare_str(CML_BigInt *bigint, char *str);


/******************************************************************************
 * Function: cml_bigint_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_BigInts.
 *
 * Parameters:
 *      char *expected - Expected big int.
 *      CML_BigInt *got      - Result big int.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_API char *cml_bigint_debug(char *expected_str, CML_BigInt *got);


#endif /* CAMEL_BIGINT */
