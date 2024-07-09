/**
 * @file types.c
 * 
 * @brief Implementation of most type helper functionalities of CAMEL.
 *
 * @author Sergio Madrid
 * @date 3/3/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../include/core/types.h"


const u32 cml_numerictype_size_lookup2[] = {
    [CML_U8] = sizeof(u8),
    [CML_U16] = sizeof(u16),
    [CML_U32] = sizeof(u32),
    [CML_U64] = sizeof(u64),
    [CML_I8] = sizeof(i8),
    [CML_I16] = sizeof(i16),
    [CML_I32] = sizeof(i32),
    [CML_I64] = sizeof(i64),
    [CML_F32] = sizeof(f32),
    [CML_F64] = sizeof(f64),
    [CML_CF32] = sizeof(cf32),
    [CML_CF64] = sizeof(cf64),
    [CML_BIGINT] = sizeof(CML_BigInt),
    [CML_FRACTION] = 0, // a/b, both CML_Bigint
    [CML_COMPLEX] = 0, // a + bi, both CML_Fraction
};

