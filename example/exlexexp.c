/**
 * @file exlexexp.c
 * 
 * @brief Example file for using the lexer, how to extract data from a
 *        CML_DArray, adn from that how to print the lexed expression.
 *
 * @author Sergio Madrid
 * @date 20/1/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../include/camel.h"


int main() {
    // Create the CML_DArray and CML_String
    CML_DArray darray;
    CML_String expression;
    // Initialize the CML_String to the expression to be lexed
    cml_string_init("867x + y^(sin(z)) / (291(xlog(y + z)))", &expression);
    // Use the lexer to extract the tokens from the expression. The CML_DArray
    // can be initialized or not, if it is not initialized, it will be
    // initialized within the lexer.
    cml_lex_expression(&expression, &darray);

    // To print the expression, there are two options, extract the data from the
    // CML_DArray using cml_darray_get, or directly accessing the data pointer
    // of the CML_DArray. This is option 1:
    printf("Expression: %s\n", expression.data);
    for (u32 i = 0; i < darray.length; ++i) {
        CML_ExpressionToken *token = cml_darray_get(i, &darray);
        printf("[CharType: %i, String: %s]\n", token->charType, token->characters.data);
        // Only free external token, not internal string
        free(token);
    }

    // This is option 2:
    printf("Expression: %s\n", expression.data);
    for (u32 i = 0; i < darray.length; ++i) {
        CML_ExpressionToken token = ((CML_ExpressionToken*)darray.data)[i];
        printf("[CharType: %i, String: %s]\n", token.charType, token.characters.data);
    }

    cml_string_free(&expression);
    cml_darray_free(&darray);
}