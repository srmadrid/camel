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
#include "../../../include/core/dstructs/btree.h"


/** @brief Default size of the expression token array. */
#define CML_INITIAL_EXP_SIZE 10


/** @brief Default size of the number array. */
#define CML_INITIAL_NUM_SIZE 5


/** @brief Character types. */
typedef enum CML_CharType {
    /** @brief Number. */
    CML_CHAR_NUMBER = 1,
    /** @brief Low precedence operator (+, -). */
    CML_CHAR_LOW_PRECEDENCE_OP = 2,
    /** @brief Medium precedence operator (*, /). */
    CML_CHAR_MEDIUM_PRECEDENCE_OP = 3,
    /** @brief High precedence operator (^). */
    CML_CHAR_HIGH_PRECEDENCE_OP = 4,
    /** @brief Letter (auxiliary for identifying function operators, variables
     *         and constants). */
    CML_CHAR_LETTER = 5,
    /** @brief Function operator (log, sin, cos, etc.). */
    CML_CHAR_FUNCTION_OP = 6,
    /** @brief Variable (any letter not interpreted as a constant). */
    CML_CHAR_VARIABLE = 7,
    /** @brief Constant (pi, e, i, etc.). */
    CML_CHAR_CONSTANT = 8,
    /** @brief Opening parenthesis. */
    CML_CHAR_OPENING_PARENTHESIS = 9,
    /** @brief Closing parenthesis. */
    CML_CHAR_CLOSING_PARENTHESIS = 10,
    /** @brief Space. */
    CML_CHAR_SPACE = 11,
    /** @brief Undefined. */
    CML_CHAR_UNDEFINED = -1
} CML_CharType;


/**
 * @brief Token that stores information of each toke of a tokenized expression.
 */
typedef struct CML_ExpressionToken{
    /** @brief Type of the character. */
    CML_CharType charType;
    /** @brief String that holds the characters of the token. */
    CML_String characters;
} CML_ExpressionToken;


/**
 * @brief Struture that holds an expression.
 * 
 * @note Not implemented yet.
 */
typedef struct CML_Expression {
    /** @brief Binary tree that holds the expression in tokens. */
    CML_BTree data;
    /** @brief Dynamic array that holds the expression in tokens. */
    CML_DArray tokens;
    /** @brief String that holds the original expression in characters. */
    CML_String expression;
} CML_Expression;



/**
 * @brief Initializes a CML_ExpressionToken with a copy of the input string.
 *
 * @param input    Pointer to the input string.
 * @param charType Type of the character.
 * @param expToken Pointer to the CML_ExpressionToken to be initialized.
 * 
 * @return Status code.
 */
CML_Status cml_exptkn_init(CML_String *characters, CML_CharType charType, CML_ExpressionToken *expToken);


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
CML_CharType cml_read_char(char input);


/**
 * @brief Tokenizes the input expression (string) into an array of 
 *        CML_ExpressionToken and writes it to the out array.
 * 
 * @note The function initializes the out array.
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
