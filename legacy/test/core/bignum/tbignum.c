/**
 * @file tbignum.c
 * 
 * @brief Test file for the bignum module.
 *
 * @author Sergio Madrid
 * @date 17/12/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/camel.h"


void cml_register_bigint_tests(CML_Test *registry, u32 *count);


void cml_register_bignum_tests(CML_Test *registry, u32 *count) {
    cml_register_bigint_tests(registry, count);
}
