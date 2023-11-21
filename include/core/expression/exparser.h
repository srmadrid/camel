/******************************************************************************
 * Filename: expression.h
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

#include <stdint.h>
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
 *      uint32_t len     - Length of the string stored in characters.
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
    uint32_t len;
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
CAMEL_API CML_ExpressionToken *cml_exptkn_init(char **input, int charType, int size) {
    if (charType < -1 || charType > 11 || size < 1) {
        return NULL;
    }

    CML_ExpressionToken *out = (CML_ExpressionToken*)malloc(sizeof(CML_ExpressionToken));
    if (out == NULL) {
        return NULL;
    }

    out->charType = charType;
    out->characters = *input;
    out->len = size;

    // Render input pointer useless
    *input = NULL;

    return out;
}


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
CAMEL_API void cml_exptkn_free(CML_ExpressionToken *token) {
    if (token != NULL) {
        if (token->characters != NULL) {
            free(token->characters);
        }
        free(token);
    }
}


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
CAMEL_API int cml_read_char(char input) {
    switch (input) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return 1;

        case '+':
        case '-':
            return 2;

        case '*':
        case '/':
            return 3;

        case '^':
            return 4;

        // Add uppercase letters later to maybe implement functions with matrices
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
            return 5;

        case '(':
        case '[':
        case '{':
            return 9;

        case ')':
        case ']':
        case '}':
            return 10;

        case ' ':
            return 10;

        default:
            return -1;
    }
}


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
CAMEL_API CML_ExpressionToken **cml_lex_expression(const char *expression, size_t *size) {
    size_t capacity = INITIAL_EXP_SIZE; // Initial size
    CML_ExpressionToken **result = (CML_ExpressionToken**)malloc(capacity * sizeof(CML_ExpressionToken*));
    if (result == NULL) {
        return NULL;
    }

    int expressionLength = strlen(expression);
    *size = 0;
    size_t length = 0;
    char *aux;
    int nextCharType = 0;
    
    int letterAuxLen = 0; // For charType == 5, to be removed when a map is implemented

    // Iterate through the expression
    for (int i = 0; i < expressionLength;) { // remove ++i from loop
        if (*size >= capacity) {
            // Resize array
            capacity *= 2;
            CML_ExpressionToken **temp = (CML_ExpressionToken**)realloc(result, capacity * sizeof(CML_ExpressionToken*));
            if (!temp) {
                goto error;
            }
            result = temp;
        }
        int charType = cml_read_char(expression[i]);
        if (charType != -1 && charType != 11) {
            if (charType == 1) {
                aux = (char*)malloc(INITIAL_NUM_SIZE * sizeof(char));
                if (aux == NULL) {
                    goto error;
                }
                aux[length] = expression[i];
                ++length;
                while (i + length < expressionLength && cml_read_char(expression[i + length]) == 1) {
                    aux[length] = expression[i + length];
                    ++length;
                }
                char *temp = (char*)realloc(aux, length * sizeof(char));
                if (!temp) {
                    goto error;
                }
                aux = temp;
                result[*size] = cml_exptkn_init(&aux, charType, length);
                i += length; // Move i the length of the digit chain
                length = 0;
                (*size)++;
            } else if (charType == 2 || charType == 3 || charType == 4 || charType == 9 || charType == 10) {
                aux = (char*)malloc(sizeof(char));
                if (aux == NULL) {
                    goto error;
                }
                aux[0] = expression[i];
                result[*size] = cml_exptkn_init(&aux, charType, 1);
                ++i; // increment here since we've processed the character
                (*size)++;
            } else if (charType == 5) {
                // Standard if else chain. Future plans may include using a map 
                // or other more efficient data structure to more effitiently
                // and more maintainably check for constants and function operators
                // Constants
                if (expression[i] == 'e') {
                    letterAuxLen = 1;
                    charType = 8;
                } else if (expression[i] == 'i') {
                    letterAuxLen = 1;
                    charType = 8;
                } else if (expression[i] == 'p' && expression[i + 1] == 'i') {
                    letterAuxLen = 2;
                    charType = 8;
                } else if (expression[i] == 'p' && expression[i + 1] == 'h' &&
                           expression[i + 2] == 'i') {
                    letterAuxLen = 3;
                    charType = 8;
                } else if (expression[i] == 'l' && expression[i + 1] == 'n') { // Function operators
                    letterAuxLen = 2;
                    charType = 6;
                } else if (expression[i] == 'l' && expression[i + 1] == 'o' &&
                           expression[i + 2] == 'g') {
                    letterAuxLen = 3;
                    charType = 6;
                } else if (expression[i] == 's' && expression[i + 1] == 'i' &&
                           expression[i + 2] == 'n') {
                    letterAuxLen = 3;
                    charType = 6;
                } else if (expression[i] == 'c' && expression[i + 1] == 'o' &&
                           expression[i + 2] == 's') {
                    letterAuxLen = 3;
                    charType = 6;
                } else {
                    letterAuxLen = 1;
                    charType = 7;
                }
                // To be implemented (log, ln, sin, cos, etc. (6) and variables (7) and constants (8))
                // Right now placeholder code
                aux = (char*)malloc(letterAuxLen * sizeof(char));
                if (aux == NULL) {
                    goto error;
                }
                for (int k = 0; k < letterAuxLen; k++) {
                    aux[k] = expression[i + k];
                }
                result[*size] = cml_exptkn_init(&aux, charType, letterAuxLen);
                i += letterAuxLen; // increment here since we've processed the character
                (*size)++;
                // Maybe add a way to more quickly identify variables and constants 
                // once in the token to optimize evaluations
            } 
        } else {
            ++i; // If the charType is -1 or 10, just move to the next character
        }
    }
    // Resize final array to correct size
    CML_ExpressionToken **temp = (CML_ExpressionToken**)realloc(result, (*size) * sizeof(CML_ExpressionToken*));
    if (!temp) {
        goto error;
    }
    result = temp;
    return result;

error:
    if (aux) {
        free(aux);
    }
    for (int j = 0; j < *size; j++) {
        cml_exptkn_free(result[j]);
    }
    *size = 0;
    free(result);
    return NULL;
}


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
