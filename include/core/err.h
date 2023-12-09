/******************************************************************************
 * Filename: err.h
 * 
 * Description:
 *      Error handling code for CAMEL.
 *
 * Author: Sergio Madrid
 * Created on: 8/11/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/

#ifndef CAMEL_ERROR
#define CAMEL_ERROR

typedef enum {
    CML_SUCCESS = 0,
    CML_ERR_INVALID_SIZE = -1,
    CML_ERR_NULL_PTR = -2,
} CML_Status;

#endif /* CAMEL_ERROR */
