# Data Structures

This module offers the most common data structures used in computer science, as well as some more exotic ones. The data structures are implemented so that they can be used with any type, and are not limited to a specific type. This is achieved by using a void pointer to store the data. All functions in this module, except for very limited exceptions, check for errors.

**Module Location**: ```include/core/dstructs/dstructs.h```

**Usage Options:** Compiled.

## Table of Contents

- [Design Choices](#design-choices)
- [String](#string)
- [Stack](#stack)

## Design Choices

When adding an element, or creating any data structure that holds another data structure, the data structure creates a shallow copy of the element top be added, i.e., the structure takes ownership of the element and is now responsible of freeing its internal data; if it was allocated on the heap, you will still need to free the pointer, but if it was allocated on the stack, after inserting the element you should do nothing.

## String

Strings are used to store text, and as a safe replacement for character arrays.

### String File Locations

- Compiled: ```include/core/dstructs/string.h``` and ```src/core/dstructs/string.c```.

### String Definition

```CML_String``` is a struct that contains a pointer to the string data, the length of the string, the capacity of the string and the number of references left to the string, meaning how many functions can use the string. If the reference count reaches zero, the string is freed inside the function that decremented the reference count. This is to make possible the existence of temporary strings, that are only used inside a function where they are passed as a parameter, and are freed when the function returns. By default, the reference count is set to -1, meaning infinite references.

### String Initialization

- ```cml_string_init(char*, CML_String*)```: Initializes a string with a C string, which must be null terminated. The string is allocated with a capacity of ```length(char*) + 1```, and the length is set to ```length(char*)```. The reference count is set to -1, meaning infinite references.
- ```CML_String *cml_string_temp(char*)```: Initializes a temporary string with a C string, which must be null terminated. The string is allocated with a capacity of ```length(char*) + 1```, and the length is set to ```length(char*)```. The reference count is set to 1, meaning that the string will be freed when the reference count reaches zero. This function is used to create temporary strings, and returns a pointer to the string so it can be used as a parameter in a function call.

### String Functions

| Function | Description |
| --- | --- |
| ```cml_string_init(char *input, CML_String *string)``` | Initializes a string with a C string, which must be null terminated. The string is allocated with a capacity of ```length(char*) + 1```, and the length is set to ```length(char*)```. The reference count is set to -1, meaning infinite references. |
| ```CML_String *cml_string_temp(char *input)``` | Initializes a temporary string with a C string, which must be null terminated. The string is allocated with a capacity of ```length(char*) + 1```, and the length is set to ```length(char*)```. The reference count is set to 1, meaning that the string will be freed when the reference count reaches zero. This function is used to create temporary strings, and returns a pointer to the string so it can be used as a parameter in a function call. |
| ```cml_string_alloc(CML_String *string)``` | Initializes the data to NULL, the length to 0, the capacity to 0, and the reference count to -1. |
| ```cml_string_free(CML_String *string)``` | Frees the string data, and sets the data pointer to NULL, the length to 0, the capacity to 0, and the reference count to 0. The string must be freed by the user |
| ```cml_string_copy(CML_String *input, CML_String *out)``` | Copies the string ```input``` to ```out```. If the data in ```out``` is NULL, it is allocated with a capacity of ```input->length + 1```. If the data in ```out``` is not NULL, but the capacity is less than ```src->length + 1```, ```out``` is reallocated with a capacity of ```src->length + 1```. The length of ```out``` is set to ```input->length```, and the reference count is set to -1. |
| ```cml_string_ncopy(CML_String *input, u32 n, CML_String *out)``` | Copies the first ```n``` characters of the string ```input``` to ```out```. If the data in ```out``` is NULL, it is allocated with a capacity of ```n + 1```. If the data in ```out``` is not NULL, but the capacity is less than ```n + 1```, ```out``` is reallocated with a capacity of ```n + 1```. The length of ```out``` is set to ```n```, and the reference count is set to -1. |
| ```cml_string_copy_char(char *input, CML_String *out)``` | Copies the C string ```input``` to ```out```. ```input``` must be null terminated. If the data in ```out``` is NULL, it is allocated with a capacity of ```length(input) + 1```. If the data in ```out``` is not NULL, but the capacity is less than ```length(input) + 1```, ```out``` is reallocated with a capacity of ```length(input) + 1```. The length of ```out``` is set to ```length(input)```, and the reference count is set to -1. |
| ```cml_string_ncopy_char(char *input, u32 n, CML_String *out)``` | Copies the first ```n``` characters of the C string ```input``` to ```out```. ```input``` must be null terminated. If the data in ```out``` is NULL, it is allocated with a capacity of ```n + 1```. If the data in ```out``` is not NULL, but the capacity is less than ```n + 1```, ```out``` is reallocated with a capacity of ```n + 1```. The length of ```out``` is set to ```n```, and the reference count is set to -1. |
| ```cml_string_cat(CML_String *input, CML_String *out)``` | Concatenates the string ```input``` to ```out```. ```out``` must hold data. If the capacity of ```out``` is less than ```out->length + input->length + 1```, ```out``` is reallocated with a capacity of ```out->length + input->length + 1```. The length of ```out``` is set to ```out->length + input->length```, and the reference count is set to -1. |
| ```cml_string_ncat(CML_String *input, u32 n, CML_String *out)``` | Concatenates the first ```n``` characters of the string ```input``` to ```out```. ```out``` must hold data. If the capacity of ```out``` is less than ```out->length + n + 1```, ```out``` is reallocated with a capacity of ```out->length + n + 1```. The length of ```out``` is set to ```out->length + n```, and the reference count is set to -1. |
| ```cml_string_cat_char(char *input, CML_String *out)``` | Concatenates the C string ```input``` to ```out```. ```input``` must be null terminated. ```out``` must hold data. If the capacity of ```out``` is less than ```out->length + length(input) + 1```, ```out``` is reallocated with a capacity of ```out->length + length(input) + 1```. The length of ```out``` is set to ```out->length + length(input)```, and the reference count is set to -1. |
| ```cml_string_ncat_char(char *input, u32 n, CML_String *out)``` | Concatenates the first ```n``` characters of the C string ```input``` to ```out```. ```input``` must be null terminated. ```out``` must hold data. If the capacity of ```out``` is less than ```out->length + n + 1```, ```out``` is reallocated with a capacity of ```out->length + n + 1```. The length of ```out``` is set to ```out->length + n```, and the reference count is set to -1. |
| ```cml_string_eq(CML_String *s1, CML_String *s1)``` | Returns `true` if ```s1``` and ```s2``` are equal, `false` otherwise. |
| ```cml_string_eq_char(CML_String *s1, char *s2)``` | Returns `true` if ```s1``` and ```s2``` are equal, `false` otherwise. |

## Stack

[↑ Back to Top](#data-structures)\
[← Back to Main Documentation Index](../../README.md)\
[← Back to Core  Overview](core.md)
