/**
 * @file err.c
 * 
 * @brief Implementations for the functions for errors of CAMEL.
 *
 * @author Sergio Madrid
 * @date 17/12/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../include/core/err.h"


char *cml_status_to_str(CML_Status status) {
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


char *cml_u8_debug(u8 expected, u8 got) {
    char *debug = malloc(256 * sizeof(char));
    sprintf(debug, "\t\tExpected: %u\n\t\tGot: %u", expected, got);
    return debug;
}


char *cml_u16_debug(u16 expected, u16 got) {
    char *debug = malloc(256 * sizeof(char));
    sprintf(debug, "\t\tExpected: %u\n\t\tGot: %u", expected, got);
    return debug;
}


char *cml_u32_debug(u32 expected, u32 got) {
    char *debug = malloc(256 * sizeof(char));
    sprintf(debug, "\t\tExpected: %u\n\t\tGot: %u", expected, got);
    return debug;
}


char *cml_u64_debug(u64 expected, u64 got) {
    char *debug = malloc(256 * sizeof(char));
    sprintf(debug, "\t\tExpected: %lu\n\t\tGot: %lu", expected, got);
    return debug;
}


char *cml_i8_debug(i8 expected, i8 got) {
    char *debug = malloc(256 * sizeof(char));
    sprintf(debug, "\t\tExpected: %i\n\t\tGot: %i", expected, got);
    return debug;
}


char *cml_i16_debug(i16 expected, i16 got) {
    char *debug = malloc(256 * sizeof(char));
    sprintf(debug, "\t\tExpected: %i\n\t\tGot: %i", expected, got);
    return debug;
}


char *cml_i32_debug(i32 expected, i32 got) {
    char *debug = malloc(256 * sizeof(char));
    sprintf(debug, "\t\tExpected: %i\n\t\tGot: %i", expected, got);
    return debug;
}


char *cml_i64_debug(i64 expected, i64 got) {
    char *debug = malloc(256 * sizeof(char));
    sprintf(debug, "\t\tExpected: %li\n\t\tGot: %li", expected, got);
    return debug;
}


char *cml_f32_debug(f32 expected, f32 got) {
    char *debug = malloc(256 * sizeof(char));
    sprintf(debug, "\t\tExpected: %f\n\t\tGot: %f", expected, got);
    return debug;
}


char *cml_f64_debug(f64 expected, f64 got) {
    char *debug = malloc(256 * sizeof(char));
    sprintf(debug, "\t\tExpected: %lf\n\t\tGot: %lf", expected, got);
    return debug;
}
