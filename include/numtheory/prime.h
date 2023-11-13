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


#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "../core/core.h"


/******************************************************************************
 * Function: cml_is_prime
 * 
 * Description:
 *      Checks if the input number is prime.
 *
 * Parameters:
 *      uint64_t n - Input number.
 * 
 * Returns:
 *      CAMEL_TRUE or CAMEL_FALSE.
 *****************************************************************************/
CAMEL_API int cml_is_prime(uint64_t n) {
    if (n == 2 || n == 3)
        return CAMEL_TRUE;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return CAMEL_FALSE;

    for (uint32_t i = 5; i*i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return CAMEL_FALSE;
    }

    return CAMEL_TRUE;
}


/******************************************************************************
 * Function: cml_generate_primes
 * 
 * Description:
 *      Uses Eratostenes' sieve to generate prime numbers up to the limit.
 *
 * Parameters:
 *      uint64_t limit - Limit.
 *      size_t   *size - Pointer to an unsigned int that will hold the size of the output array.
 * 
 * Returns:
 *      A dynamically allocated array with all primes up to limit.
 *
 * Notes:
 *      The user is responsible for freeing the returned array.
 *****************************************************************************/
CAMEL_API uint64_t *cml_generate_primes(uint64_t limit, size_t *size) {
    *size = 0;
    
    if (limit < 2)
        return NULL;

    int arrSize = (limit + 1)/2;
    uint8_t *isPrime = (uint8_t*)malloc(arrSize);

    if (isPrime == NULL)
        return NULL;

    memset(isPrime, 1, arrSize);

    *size = 1;
    for (uint64_t i = 3; i <= limit; i += 2) {
        if (isPrime[i / 2]) {
            (*size)++;
            if ((uint64_t) i * i <= limit) {
                for (uint64_t j = i * i; j <= limit; j += 2 * i) {
                    isPrime[j / 2] = 0;
                }
            }
        }
    }

    uint64_t *primes = (uint64_t*)malloc(*size * sizeof(uint64_t));
    if (primes == NULL) {
        *size = 0;
        free(isPrime);
        return NULL;
    }

    uint64_t index = 0;
    primes[index++] = 2;
    for (uint64_t i = 3; i <= limit; i += 2) {
        if (isPrime[i / 2]) {
            primes[index++] = i;
        }
    }

    free(isPrime);
    return primes;
}


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
CAMEL_API uint64_t *cml_prime_factors(uint64_t n, size_t *size) {
    *size = 0;
    uint64_t* factors = NULL;

    size_t capacity = 10; // Initial capacity
    factors = (uint64_t*)malloc(capacity * sizeof(uint64_t));
    if (!factors) {
        return NULL;
    }

    // Factor out 2s
    while (n % 2 == 0) {
        if (*size >= capacity) {
            // Resize array
            capacity *= 2;
            uint64_t *temp = (uint64_t*)realloc(factors, capacity * sizeof(uint64_t));
            if (!temp) {
                *size = 0;
                free(factors);
                return NULL;
            }
            factors = temp;
        }
        factors[(*size)++] = 2;
        n /= 2;
    }

    // Factor out odd primes
    for (uint64_t i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            if (*size >= capacity) {
                // Resize array
                capacity *= 2;
                uint64_t *temp = (uint64_t*)realloc(factors, capacity * sizeof(uint64_t));
                if (!temp) {
                    *size = 0;
                    free(factors);
                    return NULL;
                }
                factors = temp;
            }
            factors[(*size)++] = i;
            n /= i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2) {
        if (*size >= capacity) {
            // Resize array
            capacity += 1; // Only need space for one more element
            uint64_t *temp = (uint64_t*)realloc(factors, capacity * sizeof(uint64_t));
            if (!temp) {
                *size = 0;
                free(factors);
                return NULL;
            }
            factors = temp;
        }
        factors[(*size)++] = n;
    }

    return factors;
}


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
CAMEL_API uint64_t cml_gcd(uint64_t a, uint64_t b) {
    if (a == 0) return b;
    if (b == 0) return a;

    // Find common factors of 2
    int shift;
    for (shift = 0; ((a | b) & 1) == 0; ++shift) {
        a >>= 1;
        b >>= 1;
    }

    // Divide a by 2 until it becomes odd
    while ((a & 1) == 0) {
        a >>= 1;
    }

    do {
        // If b is even, remove all factor of 2 in b
        while ((b & 1) == 0) {
            b >>= 1;
        }

        // Now a and b are both odd, subtract smaller from larger
        if (a > b) {
            uint64_t temp = a;
            a = b;
            b = temp;
        }
        b = b - a;

    } while (b != 0);

    // restore common factors of 2
    return a << shift;
}


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
CAMEL_API uint64_t cml_lcm(uint64_t a, uint64_t b) {
    if (a == 0 || b == 0) return 0;
    return (a / cml_gcd(a, b)) * b;
}


#endif /* CAMEL_PRIME */
