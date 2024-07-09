/**
 * @file fraction.h
 * 
 * @brief Declaration for arbitrary precision fractions of CAMEL.
 *
 * @author Sergio Madrid
 * @date 23/11/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_FRACTION
#define CAMEL_FRACTION

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "bigint.h"
#include "../macros.h"
#include "../err.h"
#include "../memory/memory.h"


/**
 * @brief Represents an arbitrary precision fraction.
 */
typedef struct CML_Fraction {
    /** @brief Numerator. */
    CML_BigInt numerator;
    /** @brief Denominator. */
    CML_BigInt denominator;
    /** @brief Irrational constants multiplying? */
    /** @brief Allocator used for dynamic memory management within the 
     *         structure. */
    CML_Allocator *allocator;
} CML_Fraction;


#endif /* CAMEL_FRACTION */
