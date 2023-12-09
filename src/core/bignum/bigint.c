/******************************************************************************
 * Filename: bigint.h
 * 
 * Description:
 *      Implementations for arbitrary precision integers of CAMEL.
 *
 * Author: Sergio Madrid
 * Created on: 9/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include "../../../include/core/bignum/bigint.h"


CML_Status cml_bigint_init(CML_BigInt *bigint, size_t capacity) {
    if (capacity < CML_INITIAL_BIGINT_CAP) {
        capacity = CML_INITIAL_BIGINT_CAP;
    }

    if (bigint == NULL) {
        return CML_ERR_NULL_PTR;
    }

    bigint->data = (u32*)malloc(capacity * sizeof(u32));
    if (bigint->data == NULL) {
        bigint->capacity = 0;
        bigint->size = 0;
        return CML_ERR_NULL_PTR;
    }
    for (int i = 0; i < capacity; ++i) {
        bigint->data[i] = 0;
    }
    bigint->size = 0;
    bigint->capacity = capacity;

    return CML_SUCCESS;
}


void cml_bigint_free(CML_BigInt *bigint) {
    if (bigint != NULL) {
        if (bigint->data != NULL) {
            free(bigint->data);
        }
        bigint->data = NULL;
        bigint->size = 0;
        bigint->capacity = 0;
    }
}


CML_Status cml_bigint_set_int(CML_BigInt *bigint, u64 input, int sign) {
    if (bigint == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if ((input >> 32) & 0xFFFFFFFF) {
        bigint->size = 2;
    } else {
        bigint->size = 1;
    }

    bigint->data[0] = input & 0xFFFFFFFF;
    bigint->data[1] = input >> 32;

    bigint->sign = sign;

    return CML_SUCCESS;
}
