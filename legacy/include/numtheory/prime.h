/**
 * @file prime.h
 * 
 * @brief Declaration of all functions related to prime numbers in CAMEL.
 *
 * @author Sergio Madrid
 * @date 13/11/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_PRIME
#define CAMEL_PRIME


#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "../core/macros.h"
#include "../core/err.h"


/**
 * @brief Checks if the input number is prime.
 *
 * @param n Input number.
 * 
 * @return Boolean value indicating whether the input number is prime.
 */
b8 cml_is_prime(u64 n);


/**
 * @brief Uses Eratostenes' sieve to generate prime numbers up to the limit.
 *
 * @param limit Limit.
 * @param size  Pointer to an unsigned int that will hold the size of the output
 *              array.
 * 
 * @return A dynamically allocated array with all primes up to limit.
 *
 * @note The user is responsible for freeing the returned array.
 */
u64 *cml_generate_primes(u64 limit, size_t *size);


/**
 * @brief Calculates prime factors of the input number.
 *
 * @param n    Input number.
 * @param size Size of the output array.
 * 
 * @return An array with all the prime factors (repetition is allowed).
 */
u64 *cml_prime_factors(u64 n, size_t *size);


/**
 * @brief Calculates the greatest common divisor of the input numbers.
 *
 * @param a First input number.
 * @param b Second input number.
 * 
 * @return The result of the gcd.
 */
u64 cml_gcd(u64 a, u64 b);


/**
 * @brief Calculates the least common multiple of the input numbers.
 *
 * @param a First input number.
 * @param b Second input number.
 * 
 * @return The result of the lcm.
 */
u64 cml_lcm(u64 a, u64 b);


#endif /* CAMEL_PRIME */
