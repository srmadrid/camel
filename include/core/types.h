/**
 * @file types.h
 * 
 * @brief Declaration of most type helper functionalities of CAMEL.
 *
 * @author Sergio Madrid
 * @date 2/3/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_TYPES
#define CAMEL_TYPES


#include <stdint.h>
#include <stdbool.h>
#include <complex.h>

#include "macros.h"
#include "bignum/bignum.h"
#include "expression/expression.h"


typedef enum CML_NumericType {
    CML_U8,
    CML_U16,
    CML_U32,
    CML_U64,
    CML_I8,
    CML_I16,
    CML_I32,
    CML_I64,
    CML_F32,
    CML_F64,
    CML_COMPLEXF32,
    CML_COMPLEXF64,
    CML_BIGINT,
    CML_FRACTION, // a/b, both CML_Bigint
    CML_COMPLEX, // a + bi, both CML_Fraction
    CML_EXPRESSION,
    CML_MATRIX,
} CML_NumericType;


static inline u32 cml_numerictype_size(CML_NumericType t) {
    switch (t) {
        case CML_U8:
            return sizeof(u8);
        
        case CML_U16:
            return sizeof(u16);

        case CML_U32:
            return sizeof(u32);

        case CML_U64:
            return sizeof(u64);

        case CML_I8:
            return sizeof(u8);
        
        case CML_I16:
            return sizeof(u16);

        case CML_I32:
            return sizeof(u32);

        case CML_I64:
            return sizeof(u64);

        case CML_F32:
            return sizeof(u32);

        case CML_F64:
            return sizeof(u64);

        case CML_COMPLEXF32:
            return sizeof(u32);

        case CML_COMPLEXF64:
            return sizeof(u64);

        case CML_BIGINT:
            return sizeof(CML_BigInt);

        case CML_FRACTION:
            return 0;

        case CML_COMPLEX:
            return 0;

        case CML_EXPRESSION:
            return sizeof(CML_Expression);

        case CML_MATRIX:
            return sizeof(void*) + sizeof(CML_NumericType) + 2*sizeof(u32) + sizeof(b8) + sizeof(CML_Allocator*);
    }

    return 0;
}


#endif /* CAMEL_TYPES */
