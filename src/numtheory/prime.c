/******************************************************************************
 * Filename: prime.h
 * 
 * Description:
 *      Declaration of all functions related to prime numbers in CAMEL.
 *
 * Author: Sergio Madrid
 * Created on: 9/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include "../../include/numtheory/prime.h"


CML_Bool cml_is_prime(u64 n) {
    if (n == 2 || n == 3)
        return CAMEL_TRUE;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return CAMEL_FALSE;

    for (u32 i = 5; i*i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return CAMEL_FALSE;
    }

    return CAMEL_TRUE;
}


u64 *cml_generate_primes(u64 limit, size_t *size) {
    *size = 0;
    
    if (limit < 2)
        return NULL;

    int arrSize = (limit + 1)/2;
    u8 *isPrime = (u8*)malloc(arrSize);

    if (isPrime == NULL)
        return NULL;

    memset(isPrime, 1, arrSize);

    *size = 1;
    for (u64 i = 3; i <= limit; i += 2) {
        if (isPrime[i / 2]) {
            (*size)++;
            if ((u64) i * i <= limit) {
                for (u64 j = i * i; j <= limit; j += 2 * i) {
                    isPrime[j / 2] = 0;
                }
            }
        }
    }

    u64 *primes = (u64*)malloc(*size * sizeof(u64));
    if (primes == NULL) {
        *size = 0;
        free(isPrime);
        return NULL;
    }

    u64 index = 0;
    primes[index++] = 2;
    for (u64 i = 3; i <= limit; i += 2) {
        if (isPrime[i / 2]) {
            primes[index++] = i;
        }
    }

    free(isPrime);
    return primes;
}


u64 *cml_prime_factors(u64 n, size_t *size) {
    *size = 0;
    u64* factors = NULL;

    size_t capacity = 10; // Initial capacity
    factors = (u64*)malloc(capacity * sizeof(u64));
    if (!factors) {
        return NULL;
    }

    // Factor out 2s
    while (n % 2 == 0) {
        if (*size >= capacity) {
            // Resize array
            capacity *= 2;
            u64 *temp = (u64*)realloc(factors, capacity * sizeof(u64));
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
    for (u64 i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            if (*size >= capacity) {
                // Resize array
                capacity *= 2;
                u64 *temp = (u64*)realloc(factors, capacity * sizeof(u64));
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
            u64 *temp = (u64*)realloc(factors, capacity * sizeof(u64));
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


u64 cml_gcd(u64 a, u64 b) {
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
            u64 temp = a;
            a = b;
            b = temp;
        }
        b = b - a;

    } while (b != 0);

    // restore common factors of 2
    return a << shift;
}


u64 cml_lcm(u64 a, u64 b) {
    if (a == 0 || b == 0) return 0;
    return (a / cml_gcd(a, b)) * b;
}
