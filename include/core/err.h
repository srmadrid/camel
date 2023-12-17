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

#include "macros.h"

typedef enum {
    CML_SUCCESS = 1,
    CML_ERR_INVALID_SIZE = -1,
    CML_ERR_NULL_PTR = -2,
} CML_Status;


//cml_status_to_str
/******************************************************************************
 * Function: cml_status_to_str
 * 
 * Description:
 *      Returns a string representation of the input CML_Status.
 *
 * Parameters:
 *      CML_Status status - Status to convert to string.
 * 
 * Returns:
 *      String representation of the status.
 *****************************************************************************/
CAMEL_API char* cml_status_to_str(CML_Status status);


//cml_status_debug
/******************************************************************************
 * Function: cml_status_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Statuses.
 *
 * Parameters:
 *      CML_Status expected - Expected status.
 *      CML_Status got      - Result status.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_API char *cml_status_debug(CML_Status expected, CML_Status got);


#endif /* CAMEL_ERROR */
