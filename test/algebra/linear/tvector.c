/******************************************************************************
 * Filename: tvector.c
 * 
 * Description:
 *      Test file for the vector module.
 *
 * Author: Sergio Madrid
 * Created on: 12/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#define CML_TEST_ENABLED
#include "../../../include/camel.h"


CML_TEST(test_vector2_add) {
    CML_Vector2 v = {1.0, 2.0};
    CML_Vector2 w = {3.0, 4.0};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {4.0, 6.0};
    cml_vector2_add(&v, &w, &out);
    CML_ASSERT(cml_vector2_compare(&out, &expected));
}


CML_TEST(test_vector2_sub) {
    CML_Vector2 v = {1.0, 2.0};
    CML_Vector2 w = {3.0, 4.0};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {-2.0, -2.0};
    cml_vector2_sub(&v, &w, &out);
    CML_ASSERT(cml_vector2_compare(&out, &expected));
}


CML_TEST(test_vector2_scale) {
    CML_Vector2 v = {1.0, 2.0};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {2.0, 4.0};
    cml_vector2_scale(&v, 2.0, &out);
    CML_ASSERT(cml_vector2_compare(&out, &expected));
}


CML_TEST(test_vector2_mod) {
    CML_Vector2 v = {3.0, 4.0};
    f64 expected = 5.0;
    f64 result = cml_vector2_mod(&v);
    CML_ASSERT(((result - expected) < 0.0001)? CAMEL_TRUE : CAMEL_FALSE);
}


CML_TEST(test_vector2_dot) {
    CML_Vector2 v = {1.0, 2.0};
    CML_Vector2 w = {3.0, 4.0};
    f64 out = 0.0;
    f64 expected = 11.0;
    cml_vector2_dot(&v, &w, &out);
    CML_ASSERT(cml_f64_compare(out, expected));
}
