/**
 * @file talgebra.c
 * 
 * @brief Test file for the algebra module.
 *
 * @author Sergio Madrid
 * @date 14/12/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../include/camel.h"


void cml_register_linear_tests(CML_Test *registry, u32 *count);


void cml_register_algebra_tests(CML_Test *registry, u32 *count) {
    cml_register_linear_tests(registry, count);
}
