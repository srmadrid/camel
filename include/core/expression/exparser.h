/******************************************************************************
 * Filename: exparser.h
 * 
 * Description:
 *      Declaration for expression parsing and manupulation of CAMEL.
 *
 * Author: Sergio Madrid
 * Created on: 16/11/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/

#ifndef CAMEL_EXPARSER
#define CAMEL_EXPARSER

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../macros.h"


/******************************************************************************
 * Struct: CML_ExpressionToken
 * 
 * Description:
 *      Token that stores information of each toke of a tokenized expression.
 *
 * Fields:
 *      int charType     - The type stored (refer to Notes).
 *      char *characters - String of the token stored.
 *      u32 len     - Length of the string stored in characters.
 *
 * Notes:
 *      Character types:
 *          1:  Number
 *          2:  Low precedence operator (+, -)
 *          3:  Medium precedence operator (*, /)
 *          4:  High precedence operator (^)
 *          5:  Letter (auxiliary for identifying function operators, variables
 *                and constants)
 *          6:  Function operator (log, sin, cos, etc.)
 *          7:  Variable (any letter not interpreted as a constant)
 *          8:  Constant (pi, e, i, etc.)
 *          9:  Opening parenthesis
 *          10: Closing parenthesis
 *          11: Space
 *          -1: Undefined
 *****************************************************************************/
typedef struct {
    int charType;
    char *characters;
    u32 len;
} CML_ExpressionToken;


/******************************************************************************
 * Function: cml_exptkn_init
 * 
 * Description:
 *      Initializes a CML_ExpressionToken with the input string.
 *
 * Parameters:
 *      char **input - Pointer to the input string.
 *      int  size    - Size of the input string.
 * 
 * Returns:
 *      A pointer to the initialized CML_ExpressionToken.
 *
 * Notes:
 *      The input string is a double pointer, since after embedding it into 
 *      the CML_ExpressionToken the reference will be edited to point to NULL,
 *      so the original memory can only be accessed through the token.
 *      Therefore this should be called like:
 *          cml_exptkn_init(&string, charType, size);.
 *****************************************************************************/
// Yet to change to return CML_Status and initialize input CML_ExpressionToken *
CAMEL_API CML_ExpressionToken *cml_exptkn_init(char **input, int charType, u32 size);


/******************************************************************************
 * Function: cml_exptkn_free
 * 
 * Description:
 *      Frees the input CML_ExpressionToken.
 *
 * Parameters:
 *      CML_ExpressionToken *token - Input token.
 * 
 * Returns:
 *      Void.
 *****************************************************************************/
CAMEL_API void cml_exptkn_free(CML_ExpressionToken *token);


/******************************************************************************
 * Function: cml_read_char
 * 
 * Description:
 *      Reads the type of a char (key in Notes in CML_ExpressionToken).
 *
 * Parameters:
 *      char input - Input character.
 * 
 * Returns:
 *      The type of the character input.
 *****************************************************************************/
CAMEL_API int cml_read_char(char input);


/******************************************************************************
 * Function: cml_lex_expression
 * 
 * Description:
 *      Tokenizes the input expression (string) into an array of 
 *      CML_ExpressionToken and writes it to the out array.
 *
 * Parameters:
 *      char                *expression - Input expression.
 *      uint32_t            size        - Size of the output expression array.
 * 
 * Returns:
 *      The tokenized expression (**: pointer to pointer array).
 *****************************************************************************/
#define INITIAL_EXP_SIZE 10
#define INITIAL_NUM_SIZE 20
CAMEL_API CML_ExpressionToken **cml_lex_expression(const char *expression, size_t *size);


/******************************************************************************
 * Function: cml_infix_postfix
 * 
 * Description:
 *      Converts to infix the input postfix expression. 
 *
 * Parameters: // To be decided
 *      char                *expression - Input expression.
 *      uint32_t            size        - Size of the output expression array.
 * 
 * Returns:
 *      The tokenized expression (**: pointer to pointer array).
 *****************************************************************************/
// To be implemented


#endif /* CAMEL_EXPARSER */
