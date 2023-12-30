/******************************************************************************
 * Filename: prime.h
 * 
 * Description:
 *      Declaration of all functions related to prime numbers in CAMEL.
 *
 * Author: Sergio Madrid
 * Created on: 13/11/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/

#ifndef CAMEL_PRIME
#define CAMEL_PRIME


#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "../core/macros.h"
#include "../core/err.h"


/******************************************************************************
 * Function: cml_is_prime
 * 
 * Description:
 *      Checks if the input number is prime.
 *
 * Parameters:
 *      u64 n - Input number.
 * 
 * Returns:
 *      CAMEL_TRUE or CAMEL_FALSE.
 *****************************************************************************/
CML_Bool cml_is_prime(u64 n);


/******************************************************************************
 * Function: cml_generate_primes
 * 
 * Description:
 *      Uses Eratostenes' sieve to generate prime numbers up to the limit.
 *
 * Parameters:
 *      u64 limit - Limit.
 *      size_t   *size - Pointer to an unsigned int that will hold the size of the output array.
 * 
 * Returns:
 *      A dynamically allocated array with all primes up to limit.
 *
 * Notes:
 *      The user is responsible for freeing the returned array.
 *****************************************************************************/
u64 *cml_generate_primes(u64 limit, size_t *size);


/******************************************************************************
 * Function: cml_prime_factors
 * 
 * Description:
 *      Calculates prime factors of the input number.
 *
 * Parameters:
 *      uint64_t  n    - Input number.
 *      size_t   *size - Size of the output array.
 * 
 * Returns:
 *      An array with all the prime factors (repetition is allowed).
 *****************************************************************************/
u64 *cml_prime_factors(u64 n, size_t *size);


/******************************************************************************
 * Function: cml_gcd
 * 
 * Description:
 *      Calculates the greatest common divisor of the input numbers.
 *
 * Parameters:
 *      uint64_t a - First input number.
 *      uint64_t b - Second input number.
 * 
 * Returns:
 *      The result of the gcd.
 *****************************************************************************/
u64 cml_gcd(u64 a, u64 b);


/******************************************************************************
 * Function: cml_lcm
 * 
 * Description:
 *      Calculates the least common multiple of the input numbers.
 *
 * Parameters:
 *      uint64_t a - First input number.
 *      uint64_t b - Second input number.
 * 
 * Returns:
 *      The result of the lcm.
 *****************************************************************************/
u64 cml_lcm(u64 a, u64 b);


#endif /* CAMEL_PRIME */
