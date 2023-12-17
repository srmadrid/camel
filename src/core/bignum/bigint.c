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
        return CML_ERR_INVALID_SIZE;
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


CML_Status cml_bigint_set_str(CML_BigInt *bigint, char *input) {
    if (bigint == NULL) {
        return CML_ERR_NULL_PTR;
    }

    size_t input_len = strlen(input);
    size_t size = (input_len * 4 + 31) / 32;
    size_t capacity = size * 2;

    if (bigint->capacity < capacity) {
        bigint->data = (u32*)realloc(bigint->data, capacity * sizeof(u32));
        if (bigint->data == NULL) {
            bigint->capacity = 0;
            bigint->size = 0;
            return CML_ERR_NULL_PTR;
        }
        bigint->capacity = capacity;
    }

    bigint->size = capacity;

    for (int i = 0; i < capacity; ++i) {
        bigint->data[i] = 0;
    }

    for (int i = 0; i < input_len; ++i) {
        int digit = input[input_len - i - 1] - '0';
        for (int j = 0; j < 4; ++j) {
            if (digit & (1 << j)) {
                bigint->data[(i * 4 + j) / 32] |= 1 << ((i * 4 + j) % 32);
            }
        }
    }

    while (bigint->size > 0 && bigint->data[bigint->size - 1] == 0) {
        --bigint->size;
    }

    return CML_SUCCESS;
}


CML_Status cml_bigint_set(CML_BigInt *bigint, CML_BigInt *input) {
    if (bigint == NULL || input == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (bigint->capacity < input->capacity) {
        bigint->data = (u32*)realloc(bigint->data, input->capacity * sizeof(u32));
        if (bigint->data == NULL) {
            bigint->capacity = 0;
            bigint->size = 0;
            return CML_ERR_NULL_PTR;
        }
        bigint->capacity = input->capacity;
    }

    bigint->size = input->size;
    bigint->sign = input->sign;

    for (int i = 0; i < input->size; ++i) {
        bigint->data[i] = input->data[i];
    }

    return CML_SUCCESS;
}


// not working
char *cml_bigint_to_str(CML_BigInt *bigint) {
    if (bigint == NULL) {
        return NULL;
    }

    char *str = (char*)malloc(bigint->size * 4 + 1);
    if (str == NULL) {
        return NULL;
    }

    for (int i = 0; i < bigint->size * 4; ++i) {
        str[i] = (bigint->data[i / 4] & (1 << (i % 4))) ? '1' : '0';
    }
    str[bigint->size * 4] = '\0';

    return str;
}


char *cml_bigint_to_bin_str(CML_BigInt *bigint) {
    if (bigint == NULL) {
        return NULL;
    }

    char *str = (char*)malloc(bigint->size * 32 + 1);
    if (str == NULL) {
        return NULL;
    }

    for (int i = 0; i < bigint->size * 32; ++i) {
        str[i] = (bigint->data[i / 32] & (1 << (i % 32))) ? '1' : '0';
    }
    str[bigint->size * 32] = '\0';

    return str;
}


CML_Bool cml_bigint_eq(CML_BigInt *bigint1, CML_BigInt *bigint2) {
    if (bigint1 == NULL || bigint2 == NULL) {
        return CML_FALSE;
    }

    if (bigint1->size != bigint2->size) {
        return CML_FALSE;
    }

    for (int i = 0; i < bigint1->size; ++i) {
        if (bigint1->data[i] != bigint2->data[i]) {
            return CML_FALSE;
        }
    }

    return CML_TRUE;
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

    for (int i = bigint1->size - 1; i >= 0; --i) {
        if (bigint1->data[i] > bigint2->data[i]) {
            return CML_GREATER;
        } else if (bigint1->data[i] < bigint2->data[i]) {
            return CML_LOWER;
        }
    }

    return CML_EQUAL;
}


CML_Bool cml_bigint_eq_int(CML_BigInt *bigint, u64 input, i8 sign) {
    if (bigint == NULL) {
        return CML_FALSE;
    }

    if ((input >> 32) & 0xFFFFFFFF) {
        if (bigint->size != 2) {
            return CML_FALSE;
        }
    } else {
        if (bigint->size != 1) {
            return CML_FALSE;
        }
    }

    if (bigint->data[0] != (input & 0xFFFFFFFF)) {
        return CML_FALSE;
    }

    if (bigint->size == 2 && bigint->data[1] != (input >> 32)) {
        return CML_FALSE;
    }

    if (bigint->sign != sign) {
        return CML_FALSE;
    }

    return CML_TRUE;
}


CML_Comparison cml_bigint_compare_int(CML_BigInt *bigint, u64 input, i8 sign) {
    if (bigint == NULL) {
        return CML_EQUAL;
    }

    if ((input >> 32) & 0xFFFFFFFF) {
        if (bigint->size != 2) {
            return CML_EQUAL;
        }
    } else {
        if (bigint->size != 1) {
            return CML_EQUAL;
        }
    }

    if (bigint->data[0] > (input & 0xFFFFFFFF)) {
        return CML_GREATER;
    } else if (bigint->data[0] < (input & 0xFFFFFFFF)) {
        return CML_LOWER;
    }

    if (bigint->size == 2 && bigint->data[1] > (input >> 32)) {
        return CML_GREATER;
    } else if (bigint->size == 2 && bigint->data[1] < (input >> 32)) {
        return CML_LOWER;
    }

    if (bigint->sign > sign) {
        return CML_GREATER;
    } else if (bigint->sign < sign) {
        return CML_LOWER;
    }

    return CML_EQUAL;
}


CML_Bool cml_bigint_eq_str(CML_BigInt *bigint, char *str) {
    if (bigint == NULL || str == NULL) {
        return CML_FALSE;
    }

    size_t input_len = strlen(str);
    size_t size = (input_len * 4 + 31) / 32;
    size_t capacity = size * 2;

    if (bigint->size != capacity) {
        return CML_FALSE;
    }

    for (int i = 0; i < input_len; ++i) {
        int digit = str[input_len - i - 1] - '0';
        for (int j = 0; j < 4; ++j) {
            if ((bigint->data[(i * 4 + j) / 32] & (1 << ((i * 4 + j) % 32))) != (digit & (1 << j))) {
                return CML_FALSE;
            }
        }
    }

    return CML_TRUE;
}


CML_Comparison cml_bigint_compare_str(CML_BigInt *bigint, char *str) {
    if (bigint == NULL || str == NULL) {
        return CML_EQUAL;
    }

    CML_BigInt bigint2;
    cml_bigint_init(&bigint2, 0);
    cml_bigint_set_str(&bigint2, str);

    CML_Comparison result = cml_bigint_compare(bigint, &bigint2);

    cml_bigint_free(&bigint2);

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
