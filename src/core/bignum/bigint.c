/**
 * @file bigint.c
 * 
 * @brief Implementations for arbitrary precision integers of CAMEL.
 *
 * @author Sergio Madrid
 * @date 9/12/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/core/bignum/bigint.h"


CML_Status cml_bigint_init(CML_Allocator *allocator, u32 capacity, CML_BigInt *bigint) {
    if (capacity < CML_INITIAL_BIGINT_CAP) {
        capacity = CML_INITIAL_BIGINT_CAP;
    }

    if (allocator == NULL || bigint == NULL) {
        return CML_ERR_NULL_PTR;
    }

    bigint->data = (u32*)allocator->malloc(capacity * sizeof(u32), allocator->context);
    if (bigint->data == NULL) {
        bigint->capacity = 0;
        bigint->size = 0;
        bigint->allocator = NULL;
        return CML_ERR_MALLOC;
    }
    for (u32 i = 0; i < capacity; ++i) {
        bigint->data[i] = 0;
    }
    bigint->size = 0;
    bigint->capacity = capacity;
    bigint->allocator = allocator;

    return CML_SUCCESS;
}


void cml_bigint_destroy(void *bigint) {
    CML_BigInt *bi = (CML_BigInt*)bigint;
    if (bi != NULL) {
        if (bi->data != NULL) {
            free(bi->data);
        }
        bi->data = NULL;
        bi->size = 0;
        bi->capacity = 0;
    }
}


CML_Status cml_bigint_set_int(u64 input, i32 sign, CML_BigInt *out) {
    if (out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if ((input >> 32) & 0xFFFFFFFF) {
        out->size = 2;
    } else {
        out->size = 1;
    }

    out->data[0] = input & 0xFFFFFFFF;
    out->data[1] = input >> 32;

    out->sign = sign > 0 ? 1 : -1;

    return CML_SUCCESS;
}


CML_Status cml_bigint_set_str(char *input, CML_BigInt *out) {
    if (out == NULL || input == NULL) {
        return CML_ERR_NULL_PTR;
    }
    return CML_SUCCESS;
    // To be implemented
}


CML_Status cml_bigint_set(CML_BigInt *input, CML_BigInt *out) {
    if (out == NULL || input == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (out->capacity < input->capacity) {
        out->data = (u32*)realloc(out->data, input->capacity * sizeof(u32));
        if (out->data == NULL) {
            out->capacity = 0;
            out->size = 0;
            return CML_ERR_NULL_PTR;
        }
        out->capacity = input->capacity;
    }

    out->size = input->size;
    out->sign = input->sign;

    for (u32 i = 0; i < input->size; ++i) {
        out->data[i] = input->data[i];
    }

    return CML_SUCCESS;
}


char *cml_bigint_to_str(CML_BigInt *bigint) {
    if (bigint == NULL) {
        return NULL;
    }
    // To be implemented
    return NULL;
}


char *cml_bigint_to_bin_str(CML_BigInt *bigint) {
    if (bigint == NULL) {
        return NULL;
    }

    char *str = (char*)malloc(bigint->size * 32 + 1);
    if (str == NULL) {
        return NULL;
    }

    for (u32 i = 0; i < bigint->size * 32; ++i) {
        str[i] = (bigint->data[i / 32] & (1 << (i % 32))) ? '1' : '0';
    }
    str[bigint->size * 32] = '\0';

    u32 start = 0, end = strlen(str) - 1;
    while (start < end && str[end] == '0') {
        end--;
    }
    str[end + 1] = '\0';
    while (start < end) {
        char temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }

    return str;
}


b8 cml_bigint_eq(CML_BigInt *bigint1, CML_BigInt *bigint2) {
    if (bigint1 == NULL || bigint2 == NULL) {
        return false;
    }

    if (bigint1->size != bigint2->size) {
        return false;
    }

    for (u32 i = 0; i < bigint1->size; ++i) {
        if (bigint1->data[i] != bigint2->data[i]) {
            return false;
        }
    }

    return true;
}


CML_Comparison cml_bigint_compare(CML_BigInt *bigint1, CML_BigInt *bigint2) {
    if (bigint1 == NULL || bigint2 == NULL) {
        return CML_EQUAL;
    }

    if (bigint1->sign > bigint2->sign) {
        return CML_GREATER;
    } else if (bigint1->sign < bigint2->sign) {
        return CML_LOWER;
    }

    if (bigint1->size > bigint2->size) {
        return CML_GREATER;
    } else if (bigint1->size < bigint2->size) {
        return CML_LOWER;
    }

    for (u32 i = bigint1->size; i > 0; --i) {
        if (bigint1->data[i - 1] > bigint2->data[i - 1]) {
            return CML_GREATER;
        } else if (bigint1->data[i - 1] < bigint2->data[i - 1]) {
            return CML_LOWER;
        }
    }

    return CML_EQUAL;
}


b8 cml_bigint_eq_int(CML_BigInt *bigint, u64 input, i32 sign) {
    if (bigint == NULL) {
        return false;
    }

    if ((input >> 32) & 0xFFFFFFFF) {
        if (bigint->size != 2) {
            return false;
        }
    } else {
        if (bigint->size != 1) {
            return false;
        }
    }

    if (bigint->data[0] != (input & 0xFFFFFFFF)) {
        return false;
    }

    if (bigint->size == 2 && bigint->data[1] != (input >> 32)) {
        return false;
    }

    if (bigint->sign != sign) {
        return false;
    }

    return true;
}


CML_Comparison cml_bigint_compare_int(CML_BigInt *bigint, u64 input, i32 sign) {
    if (bigint == NULL) {
        return CML_EQUAL;
    }
    if (input + sign) {
        return CML_EQUAL;
    }
    // To be implemented
    return CML_EQUAL;
}


b8 cml_bigint_eq_str(CML_BigInt *bigint, char *str) {
    if (bigint == NULL || str == NULL) {
        return false;
    }
    // To be implemented
    return false;
}


CML_Comparison cml_bigint_compare_str(CML_BigInt *bigint, char *str) {
    if (bigint == NULL || str == NULL) {
        return CML_EQUAL;
    }

    CML_BigInt bigint2;
    cml_bigint_init(bigint->allocator, 0, &bigint2);
    cml_bigint_set_str(str, &bigint2);

    CML_Comparison result = cml_bigint_compare(bigint, &bigint2);

    cml_bigint_destroy(&bigint2);

    return result;
}


char *cml_bigint_debug(char *expected_str, CML_BigInt *got) {
    char *got_str = cml_bigint_to_str(got);

    char *debug = (char*)malloc(strlen(expected_str) + strlen(got_str) + 100);
    sprintf(debug, "\t\tExpected:\n\t\t\t%s\n\t\tGot:\n\t\t\t%s\n", 
        expected_str, got_str);

    free(got_str);

    return debug;
}
