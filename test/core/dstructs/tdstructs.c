/**
 * @file tdstructs.c
 * 
 * @brief Test file for the data structures module.
 *
 * @author Sergio Madrid
 * @date 15/1/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/camel.h"


void cml_register_string_tests(CML_Test *registry, u32 *count);


void cml_register_dstructs_tests(CML_Test *registry, u32 *count) {
    cml_register_string_tests(registry, count);
}
