/**
 * @file exparser.h
 * 
 * @brief Declaration for expression parsing and manupulation of CAMEL.
 *
 * @author Sergio Madrid
 * @date 9/12/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/core/expression/exparser.h"


CML_Status cml_exptkn_init(CML_String *characters, CML_CharType charType, CML_ExpressionToken *expToken) {
    if (charType <= -1 || charType > 11) {
        return CML_ERR_INVALID_CHAR;
    }

    if (expToken == NULL) {
        return CML_ERR_NULL_PTR;
    }

    expToken->charType = charType;
    memcpy(&expToken->characters, characters, sizeof(CML_String));
    expToken->characters.refCount = -1;

    // No need to call checkref: the token takes ownership of the string, so
    // it does not matter if it is temporary, no internal memory should be 
    // freed. But the pointer of the temporary string must.
    // cml_string_checkref(&characters);
    if (characters->refCount == 1) {
        characters->allocator->free(characters, characters->allocator->context);
        characters = NULL;
    }

    return CML_SUCCESS;
}


void cml_exptkn_destroy(void *token) {
    CML_ExpressionToken *tkn = (CML_ExpressionToken*)token;
    if (tkn != NULL) {
        cml_string_destroy(&tkn->characters);
        tkn->charType = -1;
    }
}


CML_Status cml_exptkn_copy(CML_Allocator *allocator, CML_ExpressionToken *token, CML_ExpressionToken *out) {
    if (allocator == NULL || token == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    CML_String aux;
    CML_Status result = cml_string_init(allocator, token->characters.data, &aux);
    if (result != CML_SUCCESS) {
        return result;
    }
    
    return cml_exptkn_init(&aux, token->charType, out);
}


CML_CharType cml_read_char(char input) {
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
            return CML_CHAR_NUMBER;

        case '+':
        case '-':
            return CML_CHAR_LOW_PRECEDENCE_OP;

        case '*':
        case '/':
            return CML_CHAR_MEDIUM_PRECEDENCE_OP;

        case '^':
            return CML_CHAR_HIGH_PRECEDENCE_OP;

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
            return CML_CHAR_LETTER;

        case '(':
        case '[':
        case '{':
            return CML_CHAR_OPENING_PARENTHESIS;

        case ')':
        case ']':
        case '}':
            return CML_CHAR_CLOSING_PARENTHESIS;

        case ' ':
            return CML_CHAR_SPACE;

        default:
            return CML_CHAR_UNDEFINED;
    }
}


CML_Status cml_expression_lex(CML_Allocator *allocator, CML_String *expression, CML_DArray *out) {
    if (allocator == NULL || expression == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    cml_darray_init_default(allocator, CML_ExpressionToken, cml_exptkn_destroy, out);
    u32 letterAuxLen = 0; // For charType == 5, to be removed when a something better is implemented
    CML_CharType charType = CML_CHAR_UNDEFINED;
    CML_CharType prevCharType = CML_CHAR_UNDEFINED;

    // Iterate through the expression
    for (u32 i = 0; i < expression->length;) {
        if (charType != CML_CHAR_UNDEFINED && charType != CML_CHAR_SPACE) {
            prevCharType = charType;
        }
        charType = cml_read_char(expression->data[i]);

        if (charType != CML_CHAR_UNDEFINED && charType != CML_CHAR_SPACE) {

            // Check if the previous character was not an operator and if the
            // current character is also not an operator, then add a multiplication
            // operator, unless both characters are the same parenthesis type
            // (opening or closing).
            if ((prevCharType != CML_CHAR_LOW_PRECEDENCE_OP    && 
                 prevCharType != CML_CHAR_MEDIUM_PRECEDENCE_OP && 
                 prevCharType != CML_CHAR_HIGH_PRECEDENCE_OP)   &&
                (charType != CML_CHAR_LOW_PRECEDENCE_OP        && 
                 charType != CML_CHAR_MEDIUM_PRECEDENCE_OP     && 
                 charType != CML_CHAR_HIGH_PRECEDENCE_OP)       &&
                 prevCharType != CML_CHAR_OPENING_PARENTHESIS   && 
                 charType != CML_CHAR_CLOSING_PARENTHESIS       &&
                 prevCharType != CML_CHAR_FUNCTION_OP           &&
                 prevCharType != CML_CHAR_UNDEFINED) {
                CML_String aux;
                cml_string_init(allocator, "*", &aux);
                CML_ExpressionToken token;
                cml_exptkn_init(&aux, CML_CHAR_MEDIUM_PRECEDENCE_OP, &token);
                cml_darray_push(&token, out);
            }

            if (charType == CML_CHAR_NUMBER) {
                letterAuxLen = 1;
                CML_String aux;
                cml_string_init0(allocator, &aux);
                while (i + letterAuxLen < expression->length && cml_read_char(expression->data[i + letterAuxLen]) == 1) {
                    letterAuxLen++;
                }
                cml_string_ncopy_char(&expression->data[i], letterAuxLen, &aux);
                CML_ExpressionToken token;
                cml_exptkn_init(&aux, charType, &token);
                cml_darray_push(&token, out);
                i += letterAuxLen; // Move i the length of the digit chain
            } else if (charType == CML_CHAR_LOW_PRECEDENCE_OP    || 
                       charType == CML_CHAR_MEDIUM_PRECEDENCE_OP || 
                       charType == CML_CHAR_HIGH_PRECEDENCE_OP   || 
                       charType == CML_CHAR_OPENING_PARENTHESIS  || 
                       charType == CML_CHAR_CLOSING_PARENTHESIS) {
                CML_String aux;
                cml_string_init0(allocator, &aux);
                cml_string_ncopy_char(&expression->data[i], 1, &aux);
                CML_ExpressionToken token;
                cml_exptkn_init(&aux, charType, &token);
                cml_darray_push(&token, out);
                ++i; // increment here since we've processed the character
            } else if (charType == 5) {
                // Standard if else chain. Future plans may include using a map 
                // or other more efficient data structure to more effitiently
                // and more maintainably check for constants and function operators
                // Constants
                if (expression->data[i] == 'e') {
                    letterAuxLen = 1;
                    charType = 8;
                } else if (expression->data[i] == 'i') {
                    letterAuxLen = 1;
                    charType = 8;
                } else if (expression->data[i] == 'p' && expression->data[i + 1] == 'i') {
                    letterAuxLen = 2;
                    charType = 8;
                } else if (expression->data[i] == 'p' && expression->data[i + 1] == 'h' &&
                           expression->data[i + 2] == 'i') {
                    letterAuxLen = 3;
                    charType = 8;
                } else if (expression->data[i] == 'l' && expression->data[i + 1] == 'n') { // Function operators
                    letterAuxLen = 2;
                    charType = 6;
                } else if (expression->data[i] == 'l' && expression->data[i + 1] == 'o' &&
                           expression->data[i + 2] == 'g') {
                    letterAuxLen = 3;
                    charType = 6;
                } else if (expression->data[i] == 's' && expression->data[i + 1] == 'i' &&
                           expression->data[i + 2] == 'n') {
                    letterAuxLen = 3;
                    charType = 6;
                } else if (expression->data[i] == 'c' && expression->data[i + 1] == 'o' &&
                           expression->data[i + 2] == 's') {
                    letterAuxLen = 3;
                    charType = 6;
                } else {
                    letterAuxLen = 1;
                    charType = 7;
                }
                // To be implemented (log, ln, sin, cos, etc. (6) and variables (7) and constants (8))
                // Right now placeholder code
                CML_String aux;
                cml_string_init0(allocator, &aux);
                cml_string_ncopy_char(&expression->data[i], letterAuxLen, &aux);
                CML_ExpressionToken token;
                cml_exptkn_init(&aux, charType, &token);
                cml_darray_push(&token, out);
                i += letterAuxLen; // increment here since we've processed the character
                // Maybe add a way to more quickly identify variables and constants 
                // once in the token to optimize evaluations
            } 
        } else {
            ++i; // If the charType is -1 or 10, just move to the next character
        }
    }

    // Check if expression is a temporary string
    cml_string_checkref(&expression);

    return CML_SUCCESS;
}


CML_Status cml_expression_parse(CML_Allocator *allocator, CML_DArray *expression, CML_BTree *out) {
    if (allocator == NULL || expression == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    CML_Stack operatorStack;
    cml_stack_init_default(allocator, CML_ExpressionToken, cml_exptkn_destroy, &operatorStack);
    cml_btree_init(allocator, NULL, CML_ExpressionToken, cml_exptkn_destroy, out);

    for (u32 i = 0; i < expression->length; i++) {
        CML_ExpressionToken token;
        cml_exptkn_copy(allocator, cml_darray_get(i, expression), &token);

        if (token.charType == CML_CHAR_NUMBER || token.charType == CML_CHAR_VARIABLE || token.charType == CML_CHAR_CONSTANT) {

        }
    }

    return CML_SUCCESS;
}

