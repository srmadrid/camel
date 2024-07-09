/**
 * @file complex.h
 * 
 * @brief Declaration for arbitrary precision complex numbers of CAMEL.
 *
 * @author Sergio Madrid
 * @date 23/11/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_COMPLEX
#define CAMEL_COMPLEX

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "fraction.h"
#include "../macros.h"
#include "../err.h"
#include "../memory/memory.h"


/**
 * @brief Represents an arbitrary precision fraction.
 */
typedef struct CML_Complex {
    /** @brief Real part. */
    CML_Fraction real;
    /** @brief Imaginary part. */
    CML_Fraction imag;
    /** @brief Allocator used for dynamic memory management within the 
     *         structure. */
    CML_Allocator *allocator;
} CML_Complex;


#endif /* CAMEL_COMPLEX */
