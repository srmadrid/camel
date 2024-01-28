/**
 * @file string.h
 * 
 * @brief Declaration for the string data structure. This is offered as a
 *        safe replacement for the C string.
 *
 * @author Sergio Madrid
 * @date 15/1/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_STRING
#define CAMEL_STRING

#include <stdlib.h>

#include "../macros.h"
#include "../err.h"


/** @brief Default resize factor of the string. */
#define CML_STRING_RESIZE_FACTOR 2


/**
 * @brief Represents a string.
 * 
 * @note refCount is used to keep track of how many functions can still use the
 *       string. If refCount is 1, the next function to use the string will
 *       free it after use.
 */
typedef struct CML_String {
    /** @brief Pointer to the data of the string. */
    char *data;
    /** @brief Length of the string. */
    u32 length;
    /** @brief Capacity of the string. */
    u32 capacity;
    /** @brief Remaining allowed references to the string. */
    i32 refCount;
} CML_String;



/**
 * @brief Creates a new CML_String on the heap.
 * 
 * @return Pointer to the new CML_String.
 */
CML_String *cml_string_new();


/**
 * @brief Initializes a CML_String with the input string.
 * 
 * @note The input string is expected to be null-terminated, and ideally is a
 *       string literal.
 *
 * @param input  Pointer to the input string.
 * @param string Pointer to the CML_String to be initialized.
 * 
 * @return Status code.
 */
CML_Status cml_string_init(const char *input, CML_String *string);


/**
 * @brief Initializes a CML_String without any input.
 * 
 * @note The string will be initialized with a capacity of 0 and a length of 0,
 *       and data will be NULL. This is useful for functions like copy, concat, 
 *       etc. that will initialize the string themselves if it is not
 *       initialized.
 * 
 * @param string Pointer to the CML_String to be initialized.
 * 
 * @return Status code.
 */
CML_Status cml_string_alloc(CML_String *string);


/**
 * @brief Frees the internal memory of a CML_String.
 * 
 * @note The function frees internal data only, the pointer to the string
 *       itself is not freed and must be freed by the user.
 *
 * @param string The CML_String to be freed.
 * 
 * @return void.
 */
void cml_string_destroy(void *string);


/**
 * @brief Frees the pointer to the CML_String.
 * 
 * @note Use only on CML_Strings on the heap and after destroying them.
 *
 * @param node Pointer to the CML_String to be freed.
 * 
 * @return void.
 */
void cml_string_free(CML_String *string);


/**
 * @brief Creates a temporary CML_String from the input string. It will have a
 *        refCount of 1.
 * 
 * @note The input string is expected to be null-terminated, and ideally is a
 *       string literal.
 * 
 * @note This function is expected to be used directly as an argument to a
 *       function, and not to be stored in a variable.
 * 
 * @param input Pointer to the input string.
 * 
 * @return The temporary CML_String.
 */
CML_String *cml_string_temp(const char *input);


/**
 * @brief Check the input string for left reference count. If it is 1, the
 *        string is freed and the pointer is set to NULL. This function should 
 *        be called at the end of any function that uses a CML_String.
 * 
 * @param string The string to be checked.
 * 
 * @return void.
 */
void cml_string_checkref(CML_String **string);


/**
 * @brief Copies the input string into the output string.
 * 
 * @note The output string is not expected to be initialized, but can be. If it
 *       is not initialized, data is expected to be NULL (use cml_string_alloc).
 * 
 * @param input Input string.
 * @param out   Output string.
 * 
 * @return Status code.
 */
CML_Status cml_string_copy(CML_String *input, CML_String *out);


/**
 * @brief Copies n characters from the input string into the output string.
 * 
 * @note The output string is not expected to be initialized, but can be. If it
 *       is not initialized, data is expected to be NULL (use cml_string_alloc).
 * 
 * @param input Input string.
 * @param n     Number of characters to copy.
 * @param out   Output string.
 * 
 * @return Status code.
 */
CML_Status cml_string_ncopy(CML_String *input, u32 n, CML_String *out);


/**
 * @brief Copies the input string into the output string.
 * 
 * @note The output string is not expected to be initialized, but can be. If it
 *       is not initialized, data is expected to be NULL (use cml_string_alloc).
 * 
 * @param input Input string.
 * @param out   Output string.
 * 
 * @return Status code.
 */
CML_Status cml_string_copy_char(const char *input, CML_String *out);


/**
 * @brief Copies n characters from the input string into the output string.
 * 
 * @note The output string is not expected to be initialized, but can be. If it
 *       is not initialized, data is expected to be NULL (use cml_string_alloc).
 * 
 * @param input Input string.
 * @param n     Number of characters to copy.
 * @param out   Output string.
 * 
 * @return Status code.
 */
CML_Status cml_string_ncopy_char(const char *input, u32 n, CML_String *out);


/**
 * @brief Concatenates the input string into the output string.
 *
 * @note The output string is expected to be initialized with length > 0. In 
 *       this function out is on the left side of the concatenation operator,
 *       for more intuitive use.
 * 
 * @param input Output string.
 * @param out   Input string.
 * 
 * @return Status code.
 */
CML_Status cml_string_cat(CML_String *input, CML_String *out);


/**
 * @brief Concatenates n characters from the input string into the output
 *        string.
 * 
 * @note The output string is expected to be initialized with length > 0. In
 *       this function out is on the left side of the concatenation operator,
 *       for more intuitive use.
 * 
 * @param input Input string.
 * @param n     Number of characters to concatenate.
 * @param out   Output string.
 * 
 * @return Status code.
 */
CML_Status cml_string_ncat(CML_String *input, u32 n, CML_String *out);


/**
 * @brief Concatenates the input string into the output string.
 *
 * @note The output string is expected to be initialized with length > 0. In
 *       this function out is on the left side of the concatenation operator,
 *       for more intuitive use.
 * 
 * @param input Input string.
 * @param out   Output string.
 * 
 * @return Status code.
 */
CML_Status cml_string_cat_char(const char *input, CML_String *out);


/**
 * @brief Concatenates n characters from the input string into the output
 *        string.
 * 
 * @note The output string is expected to be initialized with length > 0. In
 *       this function out is on the left side of the concatenation operator,
 *       for more intuitive use.
 * 
 * @param input Input string.
 * @param n     Number of characters to concatenate.
 * @param out   Output string.
 * 
 * @return Status code.
 */
CML_Status cml_string_ncat_char(const char *input, u32 n, CML_String *out);


/**
 * @brief Compares the input strings for equality.
 * 
 * @param s1 First string.
 * @param s2 Second string.
 * 
 * @return Boolean value indicating whether the strings are equal or not.
 */
b8 cml_string_eq(CML_String *s1, CML_String *s2);


/**
 * @brief Compares the input strings for equality.
 * 
 * @param s1 First string.
 * @param s2 Second string.
 * 
 * @return Boolean value indicating whether the strings are equal or not.
 */
b8 cml_string_eq_char(CML_String *s1, const char *s2);


/**
 * @brief Returns a debug message comparing the input strings.
 *
 * @param expected The expected string.
 * @param got      The result string.
 * @param bervose  Whether to print all the string data or not.
 * 
 * @return A string containing the debug message.
 */
char *cml_string_debug(CML_String *expected, CML_String *got, b8 verbose);


#endif /* CAMEL_STRING */
