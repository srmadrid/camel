/******************************************************************************
 * Filename: macros.c
 * 
 * Description:
 *      Implementations for the functions for macros of CAMEL.
 *
 * Author: Sergio Madrid
 * Created on: 14/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include "../../include/core/macros.h"


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