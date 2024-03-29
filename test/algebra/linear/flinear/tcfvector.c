/**
 * @file tcfvector.c
 * 
 * @brief Test file for the compiled fixed vector module.
 *
 * @author Sergio Madrid
 * @date 25/12/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/camel.h"


CML_TestResult testc_vector2_add(void) {
    CML_Vector2 v = CML_VECTOR2(1.0f, 2.0f);
    CML_Vector2 w = {{3.0f, 4.0f}};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {{4.0f, 6.0f}};
    cmlc_vector2_add(&v, &w, &out);
    CML_TestResult result;
    result.passed = cmlc_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector2_add_f32(void) {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {{3.0f, 4.0f}};
    cmlc_vector2_add_f32(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cmlc_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector2_sub(void) {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 w = {{3.0f, 4.0f}};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {{-2.0f, -2.0f}};
    cmlc_vector2_sub(&v, &w, &out);
    CML_TestResult result;
    result.passed = cmlc_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector2_sub_f32(void) {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {{-1.0f, 0.0f}};
    cmlc_vector2_sub_f32(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cmlc_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector2_scale(void) {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {{2.0f, 4.0f}};
    cmlc_vector2_scale(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cmlc_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector2_mod(void) {
    CML_Vector2 v = {{3.0f, 4.0f}};
    f32 expected = 5.0f;
    f32 result = cmlc_vector2_mod(&v);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult testc_vector2_mod2(void) {
    CML_Vector2 v = {{3.0f, 4.0f}};
    f32 expected = 25.0f;
    f32 result = cmlc_vector2_mod2(&v);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult testc_vector2_norm(void) {
    CML_Vector2 v = {{3.0f, 4.0f}};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {{0.6f, 0.8f}};
    cmlc_vector2_norm(&v, &out);
    CML_TestResult result;
    result.passed = cmlc_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector2_dot(void) {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 w = {{3.0f, 4.0f}};
    f32 expected = 11.0f;
    f32 result = cmlc_vector2_dot(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult testc_vector2_distance(void) {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 w = {{3.0f, 4.0f}};
    f32 expected = 2.8284271247461903f;
    f32 result = cmlc_vector2_distance(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult testc_vector2_distance2(void) {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 w = {{3.0f, 4.0f}};
    f32 expected = 8.0f;
    f32 result = cmlc_vector2_distance2(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult testc_vector2_angle(void) {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 w = {{3.0f, 4.0f}};
    f32 expected = 0.17985349979247847f;
    f32 result = cmlc_vector2_angle(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult testc_vector2_project(void) {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 w = {{3.0f, 4.0f}};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {{1.32f, 1.76f}};
    cmlc_vector2_project(&v, &w, &out);
    CML_TestResult result;
    result.passed = cmlc_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector2_reflect(void) {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Vector2 w = {{3.0f, 4.0f}};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {{-1.64f, -1.52f}};
    cmlc_vector2_reflect(&v, &w, &out);
    CML_TestResult result;
    result.passed = cmlc_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector2_debug(&expected, &out);
    }
    return result;
}



CML_TestResult testc_vector3_add(void) {
    CML_Vector3 v = CML_VECTOR3(1.0f, 2.0f, 3.0f);
    CML_Vector3 w = {{4.0f, 5.0f, 6.0f}};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {{5.0f, 7.0f, 9.0f}};
    cmlc_vector3_add(&v, &w, &out);
    CML_TestResult result;
    result.passed = cmlc_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector3_add_f32(void) {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {{3.0f, 4.0f, 5.0f}};
    cmlc_vector3_add_f32(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cmlc_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector3_sub(void) {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 w = {{4.0f, 5.0f, 6.0f}};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {{-3.0f, -3.0f, -3.0f}};
    cmlc_vector3_sub(&v, &w, &out);
    CML_TestResult result;
    result.passed = cmlc_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector3_sub_f32(void) {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {{-1.0f, 0.0f, 1.0f}};
    cmlc_vector3_sub_f32(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cmlc_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector3_scale(void) {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {{2.0f, 4.0f, 6.0f}};
    cmlc_vector3_scale(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cmlc_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector3_mod(void) {
    CML_Vector3 v = {{3.0f, 4.0f, 5.0f}};
    f32 expected = 7.0710678118654755f;
    f32 result = cmlc_vector3_mod(&v);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult testc_vector3_mod2(void) {
    CML_Vector3 v = {{3.0f, 4.0f, 5.0f}};
    f32 expected = 50.0f;
    f32 result = cmlc_vector3_mod2(&v);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult testc_vector3_norm(void) {
    CML_Vector3 v = {{3.0f, 4.0f, 5.0f}};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {{0.4242640687119285f, 0.565685424949238f, 0.7071067811865475f}};
    cmlc_vector3_norm(&v, &out);
    CML_TestResult result;
    result.passed = cmlc_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector3_dot(void) {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 w = {{4.0f, 5.0f, 6.0f}};
    f32 expected = 32.0f;
    f32 result = cmlc_vector3_dot(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult testc_vector3_cross(void) {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 w = {{4.0f, 5.0f, 6.0f}};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {{-3.0f, 6.0f, -3.0f}};
    cmlc_vector3_cross(&v, &w, &out);
    CML_TestResult result;
    result.passed = cmlc_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector3_distance(void) {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 w = {{4.0f, 5.0f, 6.0f}};
    f32 expected = 5.196152422706632f;
    f32 result = cmlc_vector3_distance(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult testc_vector3_distance2(void) {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 w = {{4.0f, 5.0f, 6.0f}};
    f32 expected = 27.0f;
    f32 result = cmlc_vector3_distance2(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult testc_vector3_angle(void) {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 w = {{4.0f, 5.0f, 6.0f}};
    f32 expected = 0.2257261285527342f;
    f32 result = cmlc_vector3_angle(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(result, expected);
    }
    return test;
}


CML_TestResult testc_vector3_project(void) {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 w = {{4.0f, 5.0f, 6.0f}};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {{1.662337662337662f, 2.077922077922078f, 2.493506493506494f}};
    cmlc_vector3_project(&v, &w, &out);
    CML_TestResult result;
    result.passed = cmlc_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector3_reflect(void) {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Vector3 w = {{4.0f, 5.0f, 6.0f}};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {{-2.324675324675325f, -2.1558441558441563f, -1.987012987012987f}};
    cmlc_vector3_reflect(&v, &w, &out);
    CML_TestResult result;
    result.passed = cmlc_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector3_debug(&expected, &out);
    }
    return result;
}



CML_TestResult testc_vector4_add(void) {
    CML_Vector4 v = CML_VECTOR4(1.0f, 2.0f, 3.0f, 4.0f);
    CML_Vector4 w = {{5.0f, 6.0f, 7.0f, 8.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{6.0f, 8.0f, 10.0f, 12.0f}};
    cmlc_vector4_add(&v, &w, &out);
    CML_TestResult result;
    result.passed = cmlc_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector4_add_f32(void) {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{3.0f, 4.0f, 5.0f, 6.0f}};
    cmlc_vector4_add_f32(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cmlc_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector4_sub(void) {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 w = {{5.0f, 6.0f, 7.0f, 8.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{-4.0f, -4.0f, -4.0f, -4.0f}};
    cmlc_vector4_sub(&v, &w, &out);
    CML_TestResult result;
    result.passed = cmlc_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector4_sub_f32(void) {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{-1.0f, 0.0f, 1.0f, 2.0f}};
    cmlc_vector4_sub_f32(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cmlc_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector4_scale(void) {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{2.0f, 4.0f, 6.0f, 8.0f}};
    cmlc_vector4_scale(&v, 2.0f, &out);
    CML_TestResult result;
    result.passed = cmlc_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector4_mod(void) {
    CML_Vector4 v = {{3.0f, 4.0f, 5.0f, 6.0f}};
    f32 expected = 9.273618495495704f;
    f32 result = cmlc_vector4_mod(&v);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult testc_vector4_mod2(void) {
    CML_Vector4 v = {{3.0f, 4.0f, 5.0f, 6.0f}};
    f32 expected = 86.0f;
    f32 result = cmlc_vector4_mod2(&v);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult testc_vector4_norm(void) {
    CML_Vector4 v = {{3.0f, 4.0f, 5.0f, 6.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{0.32349831961063324f, 0.43133109281417765f, 0.5391638660177221f, 0.6469966392212665f}};
    cmlc_vector4_norm(&v, &out);
    CML_TestResult result;
    result.passed = cmlc_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector4_dot(void) {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 w = {{5.0f, 6.0f, 7.0f, 8.0f}};
    f32 expected = 70.0f;
    f32 result = cmlc_vector4_dot(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult testc_vector4_distance(void) {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 w = {{5.0f, 6.0f, 7.0f, 8.0f}};
    f32 expected = 8.0f;
    f32 result = cmlc_vector4_distance(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult testc_vector4_distance2(void) {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 w = {{5.0f, 6.0f, 7.0f, 8.0f}};
    f32 expected = 64.0f;
    f32 result = cmlc_vector4_distance2(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult testc_vector4_angle(void) {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 w = {{5.0f, 6.0f, 7.0f, 8.0f}};
    f32 expected = 0.250195920422511f;
    f32 result = cmlc_vector4_angle(&v, &w);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult testc_vector4_project(void) {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 w = {{5.0f, 6.0f, 7.0f, 8.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{2.011494252873563f, 2.413793103448276f, 2.816091954022989f, 3.218390804597701f}};
    cmlc_vector4_project(&v, &w, &out);
    CML_TestResult result;
    result.passed = cmlc_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult testc_vector4_reflect(void) {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Vector4 w = {{5.0f, 6.0f, 7.0f, 8.0f}};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {{-3.0229885057471266f, -2.8275862068965516f, -2.6321839080459775f, -2.4367816091954024f}};
    cmlc_vector4_reflect(&v, &w, &out);
    CML_TestResult result;
    result.passed = cmlc_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cmlc_vector4_debug(&expected, &out);
    }
    return result;
}



void cml_register_cfvector_tests(CML_Test *registry, u32 *count) {
    cml_test_register(registry, count, testc_vector2_add, "testc_vector2_add");
    cml_test_register(registry, count, testc_vector2_add_f32, "testc_vector2_add_f32");
    cml_test_register(registry, count, testc_vector2_sub, "testc_vector2_sub");
    cml_test_register(registry, count, testc_vector2_sub_f32, "testc_vector2_sub_f32");
    cml_test_register(registry, count, testc_vector2_scale, "testc_vector2_scale");
    cml_test_register(registry, count, testc_vector2_mod, "testc_vector2_mod");
    cml_test_register(registry, count, testc_vector2_mod2, "testc_vector2_mod2");
    cml_test_register(registry, count, testc_vector2_norm, "testc_vector2_norm");
    cml_test_register(registry, count, testc_vector2_dot, "testc_vector2_dot");
    cml_test_register(registry, count, testc_vector2_distance, "testc_vector2_distance");
    cml_test_register(registry, count, testc_vector2_distance2, "testc_vector2_distance2");
    cml_test_register(registry, count, testc_vector2_angle, "testc_vector2_angle");
    cml_test_register(registry, count, testc_vector2_project, "testc_vector2_project");
    cml_test_register(registry, count, testc_vector2_reflect, "testc_vector2_reflect");

    cml_test_register(registry, count, testc_vector3_add, "testc_vector3_add");
    cml_test_register(registry, count, testc_vector3_add_f32, "testc_vector3_add_f32");
    cml_test_register(registry, count, testc_vector3_sub, "testc_vector3_sub");
    cml_test_register(registry, count, testc_vector3_sub_f32, "testc_vector3_sub_f32");
    cml_test_register(registry, count, testc_vector3_scale, "testc_vector3_scale");
    cml_test_register(registry, count, testc_vector3_mod, "testc_vector3_mod");
    cml_test_register(registry, count, testc_vector3_mod2, "testc_vector3_mod2");
    cml_test_register(registry, count, testc_vector3_norm, "testc_vector3_norm");
    cml_test_register(registry, count, testc_vector3_dot, "testc_vector3_dot");
    cml_test_register(registry, count, testc_vector3_cross, "testc_vector3_cross");
    cml_test_register(registry, count, testc_vector3_distance, "testc_vector3_distance");
    cml_test_register(registry, count, testc_vector3_distance2, "testc_vector3_distance2");
    cml_test_register(registry, count, testc_vector3_angle, "testc_vector3_angle");
    cml_test_register(registry, count, testc_vector3_project, "testc_vector3_project");
    cml_test_register(registry, count, testc_vector3_reflect, "testc_vector3_reflect");

    cml_test_register(registry, count, testc_vector4_add, "testc_vector4_add");
    cml_test_register(registry, count, testc_vector4_add_f32, "testc_vector4_add_f32");
    cml_test_register(registry, count, testc_vector4_sub, "testc_vector4_sub");
    cml_test_register(registry, count, testc_vector4_sub_f32, "testc_vector4_sub_f32");
    cml_test_register(registry, count, testc_vector4_scale, "testc_vector4_scale");
    cml_test_register(registry, count, testc_vector4_mod, "testc_vector4_mod");
    cml_test_register(registry, count, testc_vector4_mod2, "testc_vector4_mod2");
    cml_test_register(registry, count, testc_vector4_norm, "testc_vector4_norm");
    cml_test_register(registry, count, testc_vector4_dot, "testc_vector4_dot");
    cml_test_register(registry, count, testc_vector4_distance, "testc_vector4_distance");
    cml_test_register(registry, count, testc_vector4_distance2, "testc_vector4_distance2");
    cml_test_register(registry, count, testc_vector4_angle, "testc_vector4_angle");
    cml_test_register(registry, count, testc_vector4_project, "testc_vector4_project");
    cml_test_register(registry, count, testc_vector4_reflect, "testc_vector4_reflect");
}
