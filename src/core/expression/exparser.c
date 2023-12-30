/******************************************************************************
 * Filename: exparser.h
 * 
 * Description:
 *      Declaration for expression parsing and manupulation of CAMEL.
 *
 * Author: Sergio Madrid
 * Created on: 9/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include "../../../include/core/expression/exparser.h"


// Yet to change to return CML_Status and initialize input CML_ExpressionToken *
CML_ExpressionToken *cml_exptkn_init(char **input, int charType, u32 size) {
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


void cml_exptkn_free(CML_ExpressionToken *token) {
    if (token != NULL) {
        if (token->characters != NULL) {
            free(token->characters);
        }
        free(token);
    }
}


int cml_read_char(char input) {
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


CML_ExpressionToken **cml_lex_expression(const char *expression, u32 *size) {
    size_t capacity = INITIAL_EXP_SIZE; // Initial size
    CML_ExpressionToken **result = (CML_ExpressionToken**)malloc(capacity * sizeof(CML_ExpressionToken*));
    if (result == NULL) {
        return NULL;
    }

    u32 expressionLength = strlen(expression);
    *size = 0;
    u32 length = 0;
    char *aux;
    
    int letterAuxLen = 0; // For charType == 5, to be removed when a map is implemented

    // Iterate through the expression
    for (u32 i = 0; i < expressionLength;) { // remove ++i from loop
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
    for (u32 j = 0; j < *size; j++) {
        cml_exptkn_free(result[j]);
    }
    *size = 0;
    free(result);
    return NULL;
}
