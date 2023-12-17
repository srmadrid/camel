/******************************************************************************
 * Filename: err.c
 * 
 * Description:
 *      Implementations for the functions for errors of CAMEL.
 *
 * Author: Sergio Madrid
 * Created on: 17/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include "../../include/core/err.h"


char *cml_status_to_str(CML_Status status) {
    char *str = (char*)malloc(50);
    switch (status) {
        case CML_SUCCESS:
            return "CML_SUCCESS";
        case CML_ERR_NULL_PTR:
            return "CML_ERR_NULL_PTR";
        case CML_ERR_INVALID_SIZE:
            return "CML_ERR_INVALID_SIZE";
            /*
        case CML_ERR_INVALID_CAPACITY:
            return "CML_ERR_INVALID_CAPACITY";
        case CML_ERR_INVALID_INDEX:
            return "CML_ERR_INVALID_INDEX";
        case CML_ERR_INVALID_SIGN:
            return "CML_ERR_INVALID_SIGN";
        case CML_ERR_INVALID_BASE:
            return "CML_ERR_INVALID_BASE";
        case CML_ERR_INVALID_INPUT:
            return "CML_ERR_INVALID_INPUT";
        case CML_ERR_INVALID_OUTPUT:
            return "CML_ERR_INVALID_OUTPUT";
        case CML_ERR_INVALID_OPERATION:
            return "CML_ERR_INVALID_OPERATION";
        case CML_ERR_INVALID_ARGUMENT:
            return "CML_ERR_INVALID_ARGUMENT";
        case CML_ERR_INVALID_FORMAT:
            return "CML_ERR_INVALID_FORMAT";
        case CML_ERR_INVALID_FILE:
            return "CML_ERR_INVALID_FILE";
        case CML_ERR_INVALID_STATE:
            return "CML_ERR_INVALID_STATE";
        case CML_ERR_INVALID_MEMORY:
            return "CML_ERR_INVALID_MEMORY";
        case CML_ERR_INVALID_DATA:
            return "CML_ERR_INVALID_DATA";
        case CML_ERR_INVALID_KEY:
            return "CML_ERR_INVALID_KEY";
        case CML_ERR_INVALID_IV:
            return "CML_ERR_INVALID_IV";
        case CML_ERR_INVALID_CIPHER:
            return "CML_ERR_INVALID_CIPHER";
        case CML_ERR_INVALID_PADDING:
            return "CML_ERR_INVALID_PADDING";
        case CML_ERR_INVALID_MAC:
            return "CML_ERR_INVALID_MAC";
        case CML_ERR_INVALID_SIGNATURE:
            return "CML_ERR_INVALID_SIGNATURE";
        case CML_ERR_INVALID_HASH:
            return "CML_ERR_INVALID_HASH";
        case CML_ERR_INVALID_DIGEST:
            return "CML_ERR_INVALID_DIGEST";
        case CML_ERR_INVALID_ENCODING:
            return "CML_ERR_INVALID_ENCODING";
        case CML_ERR_INVALID_FORMAT_VERSION:
            return "CML_ERR_INVALID_FORMAT_VERSION";
        case CML_ERR_INVALID_FORMAT_TYPE:
            return "CML_ERR_INVALID_FORMAT_TYPE";
        case CML_ERR_INVALID_FORMAT_SIZE:
            return "CML_ERR_INVALID_FORMAT_SIZE"; */
        default:
            return "CML_ERR_UNKNOWN";
    }
}


char *cml_status_debug(CML_Status expected, CML_Status got) {
    char *expected_str = cml_status_to_str(expected);
    char *got_str = cml_status_to_str(got);

    char *debug_msg = (char*)malloc(
        strlen(expected_str) + strlen(got_str) + 50
    );
    sprintf(debug_msg, "\t\tExpected:\n\t\t\t%s\n\t\tGot:\n\t\t\t%s", expected_str, got_str);

    return debug_msg;
}