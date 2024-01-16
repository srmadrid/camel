/**
 * @file exparser.h
 * 
 * @brief Declaration for expression parsing and manupulation of CAMEL.
 *
 * @author Sergio Madrid
 * @date 16/11/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_EXPARSER
#define CAMEL_EXPARSER

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../macros.h"
#include "../../../include/core/dstructs/string.h"
#include "../../../include/core/dstructs/darray.h"


/** @brief Default size of the expression token array. */
#define CML_INITIAL_EXP_SIZE 10


/** @brief Default size of the number array. */
#define CML_INITIAL_NUM_SIZE 5


/**
 * @brief Token that stores information of each toke of a tokenized expression.
 *
 * @details
 * Character types:
 *     1:  Number
 *     2:  Low precedence operator (+, -)
 *     3:  Medium precedence operator (*, /)
 *     4:  High precedence operator (^)
 *     5:  Letter (auxiliary for identifying function operators, variables
 *         and constants)
 *     6:  Function operator (log, sin, cos, etc.)
 *     7:  Variable (any letter not interpreted as a constant)
 *     8:  Constant (pi, e, i, etc.)
 *     9:  Opening parenthesis
 *     10: Closing parenthesis
 *     11: Space
 *     -1: Undefined
 */
typedef struct CML_ExpressionToken{
    int charType;
    CML_String characters;
} CML_ExpressionToken;


/**
 * @brief Initializes a CML_ExpressionToken with the input string.
 *
 * @param input    Pointer to the input string.
 * @param charType Type of the character.
 * @param expToken Pointer to the CML_ExpressionToken to be initialized.
 * 
 * @return Status code.
 */
CML_Status cml_exptkn_init(CML_String *characters, int charType, CML_ExpressionToken *expToken);


/**
 * @brief Frees the memory of a CML_ExpressionToken.
 *
 * @param token The CML_ExpressionToken to be freed.
 * 
 * @return void.
 */
void cml_exptkn_free(void *token);


/**
 * @brief Reads the type of a char (key in Notes in CML_ExpressionToken).
 *
 * @param input Input character.
 * 
 * @return The type of the character input.
 */
i32 cml_read_char(char input);


/**
 * @brief Tokenizes the input expression (string) into an array of 
 *        CML_ExpressionToken and writes it to the out array.
 *
 * @param expression Input expression.
 * @param out        Output CML_ExpressionToken dynamic array.
 * 
 * @return Status code.
 */
CML_Status cml_lex_expression(CML_String *expression, CML_DArray *out);


/**
 * @brief Converts to infix the input postfix expression. 
 *
 * @param expression Input expression.
 * @param size       Size of the output expression array.
 * 
 * @return The tokenized expression (**: pointer to pointer array).
 */
// To be implemented


#endif /* CAMEL_EXPARSER */
