/**
 * @file bigint.h
 * 
 * @brief Declaration for arbitrary precision integers of CAMEL.
 *
 * @author Sergio Madrid
 * @date 23/11/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_BIGINT
#define CAMEL_BIGINT

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../macros.h"
#include "../err.h"


/** @brief Default capacity of a bigint. */
#define CML_INITIAL_BIGINT_CAP  2


/**
 * @brief Represents an arbitrary precision integer.
 * 
 * @note The integer is represented as an array of u32s, with the least
 *       significant digit at index 0.
 */
typedef struct CML_BigInt {
    /** @brief Array of u32s representing the integer. */
    u32 *data;
    /** @brief Number of used indices in the array. */
    u32 size;
    /** @brief Number of allocated indices in the array. */
    u32 capacity;
    /** @brief Sign of the integer. */
    i32 sign;
} CML_BigInt;


/**
 * @brief Initializes the input CML_BigInt with the input capacity, and sets its 
 *        value to 0. If a size under 2 is passed, the default initial size of 
 *        2 will be used.
 *
 * @param capacity Initial capacity of the bigint.
 * @param bigint   Big int to initialize.
 * 
 * @return Success or error code.
 */
CML_Status cml_bigint_init(u32 capacity, CML_BigInt *bigint);


/**
 * @brief Frees the memory allocated for the input CML_BigInt.
 *
 * @param bigint Big int to free.
 * 
 * @return void.
 */
void cml_bigint_free(CML_BigInt *bigint);


/**
 * @brief Sets the input CML_BigInt to the input int.
 *
 * @param input Number to be set into the big int.
 * @param sign  Sign of the input number. Done separately to be able to input a
 *              higher range of numbers.
 * @param out   Big int to set.
 * 
 * @return Success or error code.
 *

 */
CML_Status cml_bigint_set_int(u64 input, i32 sign, CML_BigInt *out);


/**
 * @brief Sets the input CML_BigInt to the input string.
 * 
 * @note While with an int the sign is entered separately to allow for a bigger
 *       range of numbers, here the sign must be included in the number. If no
 *       sign is there, positive will be assumed, otherwise a - must be at the 
 *       beginning, like "-20".
 *
 * @param input Number to be set into the big int.
 * @param out   Big int to set.
 * 
 * @return Success or error code.
 */
CML_Status cml_bigint_set_str(char *input, CML_BigInt *out);


/**
 * @brief Sets the input CML_BigInt to the input CML_BigInt.
 *
 * @param input Big int to be set into the big int.
 * @param out   Big int to set.
 * 
 * @return Success or error code.
 */
CML_Status cml_bigint_set(CML_BigInt *input, CML_BigInt *out);


/**
 * @brief Converts the input CML_BigInt to a string.
 *
 * @param bigint Big int to convert.
 * 
 * @return The string representation of the big int.
 */
char *cml_bigint_to_str(CML_BigInt *bigint);


/**
 * @brief Converts the input CML_BigInt to a binary string.
 *
 * @param bigint Big int to convert.
 * 
 * @return The binary string representation of the big int.
 */
char *cml_bigint_to_bin_str(CML_BigInt *bigint);

// Implement addition, subtraction, multiplication, division, exponentiation, etc.


/**
 * @brief Compares two CML_BigInts for equality.
 * 
 * @param bigint1 First big int to compare.
 * @param bigint2 Second big int to compare.
 * 
 * @return Boolean value indicating whether the two big ints are equal.
 */
b8 cml_bigint_eq(CML_BigInt *bigint1, CML_BigInt *bigint2);


/**
 * @brief Compares two CML_BigInts.
 * 
 * @param bigint1 First big int to compare.
 * @param bigint2 Second big int to compare.
 * 
 * @return CML_LOWER if bigint1 < bigint2, CML_EQUAL if bigint1 == bigint2,
 *         CML_GREATER if bigint1 > bigint2.
 */
CML_Comparison cml_bigint_compare(CML_BigInt *bigint1, CML_BigInt *bigint2);


/**
 * @brief Compares a CML_BigInt to an int for equality.
 * 
 * @param bigint Big int to compare.
 * @param input  Number to be compared to the big int.
 * @param sign   Sign of the input number. Done separately to be able to input a
 *               higher range of numbers.
 * 
 * @return CML_TRUE if bigint == input, CML_FALSE otherwise.
 */
b8 cml_bigint_eq_int(CML_BigInt *bigint, u64 input, i32 sign);


/**
 * @brief Compares a CML_BigInt to an int.
 * 
 * @param bigint Big int to compare.
 * @param input  Number to be compared to the big int.
 * @param sign   Sign of the input number. Done separately to be able to input a
 *               higher range of numbers.
 * 
 * @return CML_LOWER if bigint < input, CML_EQUAL if bigint == input,
 *         CML_GREATER if bigint > input.
 */
CML_Comparison cml_bigint_compare_int(CML_BigInt *bigint, u64 input, i32 sign);


/**
 * @brief Compares a CML_BigInt to a string for equality.
 * 
 * @param bigint Big int to compare.
 * @param str    String to be compared to the big int.
 * 
 * @return Boolean value indicating whether the big int is equal to the string.
 */
b8 cml_bigint_eq_str(CML_BigInt *bigint, char *str);


/**
 * @brief Compares a CML_BigInt to a string.
 * 
 * @param bigint Big int to compare.
 * @param str    String to be compared to the big int.
 * 
 * @return CML_LOWER if bigint < str, CML_EQUAL if bigint == str,
 *         CML_GREATER if bigint > str.
 */
CML_Comparison cml_bigint_compare_str(CML_BigInt *bigint, char *str);


/**
 * @brief Returns a debug message comparing the input CML_BigInts.
 *
 * @param expected Expected big int.
 * @param got      Result big int.
 * 
 * @return A string containing the debug message.
 */
char *cml_bigint_debug(char *expected_str, CML_BigInt *got);


#endif /* CAMEL_BIGINT */
