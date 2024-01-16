/**
 * @file string.h
 * 
 * @brief Implementation for the string data structure. This is offered as a
 *        safe replacement for the C string.
 *
 * @author Sergio Madrid
 * @date 15/1/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/core/dstructs/string.h"


CML_Status cml_string_init(const char *input, CML_String *string) {
    if (input == NULL || string == NULL) {
        return CML_ERR_NULL_PTR;
    }

    u32 length = 0;
    while (input[length]) {
        length++;
    }

    string->length = length;
    string->data = (char*)malloc(sizeof(char)*(length+1));
    if (string->data == NULL) {
        return CML_ERR_NULL_PTR;
    }

    for (u32 i = 0; i < length; i++) {
        string->data[i] = input[i];
    }
    string->data[length] = '\0';
    string->capacity = length+1;

    // Infinite references
    string->refCount = -1;

    return CML_SUCCESS;
}


CML_Status cml_string_alloc(CML_String *string) {
    if (string == NULL) {
        return CML_ERR_NULL_PTR;
    }

    string->data = NULL;
    string->length = 0;
    string->capacity = 0;
    string->refCount = -1;

    return CML_SUCCESS;
}


void cml_string_free(void *string) {
    CML_String *str = (CML_String*)string;
    if (str != NULL) {
        if (str->data != NULL) {
            free(str->data);
        }
        str->data = NULL;
        str->length = 0;
        str->capacity = 0;
        str->refCount = 0;
    }
}


CML_String *cml_string_temp(const char *input) {
    CML_String *string = (CML_String*)malloc(sizeof(CML_String));
    if (string == NULL) {
        return NULL;
    }

    cml_string_init(input, string);
    string->refCount = 1;

    return string;
}


void cml_string_checkref(CML_String **string) {
    if (string == NULL || *string == NULL) {
        return;
    }

    if ((*string)->refCount == 1) {
        cml_string_free(*string);
        free(*string);
        *string = NULL;
    } else if ((*string)->refCount > 1) {
        (*string)->refCount--;
    }
}


CML_Status cml_string_copy(CML_String *input, CML_String *out) {
    if (input == NULL || out == NULL || input->data == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (out->data == NULL) {
        out->data = (char*)malloc(sizeof(char)*(input->capacity));
        if (out->data == NULL) {
            out->capacity = 0;
            out->length = 0;
            return CML_ERR_NULL_PTR;
        }
        out->capacity = input->capacity;
        out->length = input->length;
    }

    if (input->capacity != out->capacity) {
        out->data = (char*)realloc(out->data, sizeof(char)*input->capacity);
        if (out->data == NULL) {
            out->capacity = 0;
            out->length = 0;
            return CML_ERR_NULL_PTR;
        }
        out->capacity = input->capacity;
        out->length = input->length;
    }

    for (u32 i = 0; i < input->length; i++) {
        out->data[i] = input->data[i];
    }
    out->data[input->length] = '\0';
    out->refCount = -1;

    // Check if the input string is temporary
    cml_string_checkref(&input);

    return CML_SUCCESS;
}


CML_Status cml_string_ncopy(CML_String *input, u32 n, CML_String *out) {
    if (input == NULL || out == NULL || input->data == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (n > input->length) {
        n = input->length;
    }

    if (out->data == NULL) {
        out->data = (char*)malloc(sizeof(char)*(n+1));
        if (out->data == NULL) {
            out->capacity = 0;
            out->length = 0;
            return CML_ERR_NULL_PTR;
        }
        out->capacity = n + 1;
    }

    if (out->capacity < n + 1) {
        out->data = (char*)realloc(out->data, sizeof(char)*(n + 1));
        if (out->data == NULL) {
            out->capacity = 0;
            out->length = 0;
            return CML_ERR_NULL_PTR;
        }
        out->capacity = n + 1;
    }

    for (u32 i = 0; i < n; i++) {
        out->data[i] = input->data[i];
    }
    out->data[n] = '\0';
    out->length = n;
    out->refCount = -1;

    // Check if the input string is temporary
    cml_string_checkref(&input);

    return CML_SUCCESS;
}


CML_Status cml_string_copy_char(const char *input, CML_String *out) {
    if (input == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    u32 length = 0;
    while (input[length]) {
        length++;
    }

    if (out->data == NULL) {
        out->data = (char*)malloc(sizeof(char)*(length+1));
        if (out->data == NULL) {
            out->capacity = 0;
            out->length = 0;
            return CML_ERR_NULL_PTR;
        }
        out->capacity = length + 1;
    }

    if (out->capacity < length + 1) {
        out->data = (char*)realloc(out->data, sizeof(char)*(length + 1));
        if (out->data == NULL) {
            out->capacity = 0;
            out->length = 0;
            return CML_ERR_NULL_PTR;
        }
        out->capacity = length + 1;
    }

    for (u32 i = 0; i < length; i++) {
        out->data[i] = input[i];
    }
    out->data[length] = '\0';
    out->length = length;
    out->refCount = -1;

    return CML_SUCCESS;
}


CML_Status cml_string_ncopy_char(const char *input, u32 n, CML_String *out) {
    if (input == NULL || out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    u32 length = 0;
    while (input[length]) {
        length++;
    }

    if (n > length) {
        n = length;
    }

    if (out->data == NULL) {
        out->data = (char*)malloc(sizeof(char)*(n+1));
        if (out->data == NULL) {
            out->capacity = 0;
            out->length = 0;
            return CML_ERR_NULL_PTR;
        }
        out->capacity = n + 1;
    }

    if (out->capacity < n + 1) {
        out->data = (char*)realloc(out->data, sizeof(char)*(n + 1));
        if (out->data == NULL) {
            out->capacity = 0;
            out->length = 0;
            return CML_ERR_NULL_PTR;
        }
        out->capacity = n + 1;
    }

    for (u32 i = 0; i < n; i++) {
        out->data[i] = input[i];
    }
    out->data[n] = '\0';
    out->length = n;
    out->refCount = -1;

    return CML_SUCCESS;
}


CML_Status cml_string_cat(CML_String *input, CML_String *out) {
    if (input == NULL || out == NULL || input->data == NULL || out->data == NULL) {
        return CML_ERR_NULL_PTR;
    }

    u32 length = input->length + out->length;

    if (out->capacity < length + 1) {
        out->data = (char*)realloc(out->data, sizeof(char)*(length + 1));
        if (out->data == NULL) {
            out->capacity = 0;
            out->length = 0;
            return CML_ERR_NULL_PTR;
        }
        out->capacity = length + 1;
    }

    for (u32 i = 0; i < input->length; i++) {
        out->data[out->length + i] = input->data[i];
    }
    out->data[length] = '\0';
    out->length = length;
    out->refCount = -1;

    // Check if the input string is temporary
    cml_string_checkref(&input);

    return CML_SUCCESS;
}


CML_Status cml_string_ncat(CML_String *input, u32 n, CML_String *out) {
    if (input == NULL || out == NULL || input->data == NULL || out->data == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (n > input->length) {
        n = input->length;
    }

    u32 length = n + out->length;

    if (out->capacity < length + 1) {
        out->data = (char*)realloc(out->data, sizeof(char)*(length + 1));
        if (out->data == NULL) {
            out->capacity = 0;
            out->length = 0;
            return CML_ERR_NULL_PTR;
        }
        out->capacity = length + 1;
    }

    for (u32 i = 0; i < n; i++) {
        out->data[out->length + i] = input->data[i];
    }
    out->data[length] = '\0';
    out->length = length;
    out->refCount = -1;

    // Check if the input string is temporary
    cml_string_checkref(&input);

    return CML_SUCCESS;
}


CML_Status cml_string_cat_char(const char *input, CML_String *out) {
    if (input == NULL || out == NULL || out->data == NULL) {
        return CML_ERR_NULL_PTR;
    }

    u32 length = 0;
    while (input[length]) {
        length++;
    }

    length += out->length;

    if (out->capacity < length + 1) {
        out->data = (char*)realloc(out->data, sizeof(char)*(length + 1));
        if (out->data == NULL) {
            out->capacity = 0;
            out->length = 0;
            return CML_ERR_NULL_PTR;
        }
        out->capacity = length + 1;
    }

    for (u32 i = 0; i < length; i++) {
        out->data[out->length + i] = input[i];
    }
    out->data[length] = '\0';
    out->length = length;
    out->refCount = -1;

    return CML_SUCCESS;
}


CML_Status cml_string_ncat_char(const char *input, u32 n, CML_String *out) {
    if (input == NULL || out == NULL || out->data == NULL) {
        return CML_ERR_NULL_PTR;
    }

    u32 length = 0;
    while (input[length]) {
        length++;
    }

    if (n > length) {
        n = length;
    }

    length = n + out->length;

    if (out->capacity < length + 1) {
        out->data = (char*)realloc(out->data, sizeof(char)*(length + 1));
        if (out->data == NULL) {
            out->capacity = 0;
            out->length = 0;
            return CML_ERR_NULL_PTR;
        }
        out->capacity = length + 1;
    }

    for (u32 i = 0; i < n; i++) {
        out->data[out->length + i] = input[i];
    }
    out->data[length] = '\0';
    out->length = length;
    out->refCount = -1;

    return CML_SUCCESS;
}


b8 cml_string_eq(CML_String *s1, CML_String *s2) {
    if (s1 == NULL) {
        // Check if s2 is temporary
        cml_string_checkref(&s2);
        return false;
    }

    if (s2 == NULL) {
        // Check if s1 is temporary
        cml_string_checkref(&s1);
        return false;
    }

    if (s1->length != s2->length) {
        // Check if s1 or s2 are temporary
        cml_string_checkref(&s1);
        cml_string_checkref(&s2);
        return false;
    }

    for (u32 i = 0; i < s1->length; i++) {
        if (s1->data[i] != s2->data[i]) {
            // Check if s1 or s2 are temporary
            cml_string_checkref(&s1);
            cml_string_checkref(&s2);
            return false;
        }
    }

    // Check if s1 or s2 are temporary
    cml_string_checkref(&s1);
    cml_string_checkref(&s2);
    
    return true;
}


b8 cml_string_eq_char(CML_String *s1, const char *s2) {
    if (s1 == NULL) {
        return false;
    }

    if (s2 == NULL) {
        // Check if s1 is temporary
        cml_string_checkref(&s1);
        return false;
    }

    u32 length = 0;
    while (s2[length]) {
        length++;
    }

    if (s1->length != length) {
        // Check if s1 is temporary
        cml_string_checkref(&s1);
        return false;
    }

    for (u32 i = 0; i < s1->length; i++) {
        if (s1->data[i] != s2[i]) {
            // Check if s1 is temporary
            cml_string_checkref(&s1);
            return false;
        }
    }

    // Check if s1 is temporary
    cml_string_checkref(&s1);

    return true;
}


char *cml_string_debug(CML_String *expected, CML_String *got, b8 verbose) {
    if (!expected || !got) {
        return NULL;
    }

    char *debugMessage = (char *)malloc(1024 * sizeof(char));
    if (debugMessage == NULL) {
        return NULL;
    }

    if (verbose) {
        sprintf(debugMessage, "\t\tExpected:\n\t\t\tData: %s\n\t\t\tLength: %i\n\t\t\tCapacity: %i\n\t\t\tRefCount: %i\n\t\tGot:\n\t\t\tData: %s\n\t\t\tLength: %i\n\t\t\tCapacity: %i\n\t\t\tRefCount: %i\n", 
            expected->data, expected->length, expected->capacity, expected->refCount, 
            got->data, got->length, got->capacity, got->refCount);
    } else {
        sprintf(debugMessage, "\t\tExpected:\n\t\t\t%s\n\t\tGot:\n\t\t\t%s\n", 
                expected->data, got->data);
    }

    // Check if the expected string is temporary
    cml_string_checkref(&expected);
    // Check if the got string is temporary
    cml_string_checkref(&got);

    return debugMessage;
}
