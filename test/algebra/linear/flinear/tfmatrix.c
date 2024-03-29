/**
 * @file tfmatrix.c
 * 
 * @brief Test file for the fixed matrix module.
 *
 * @author Sergio Madrid
 * @date 16/12/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../../include/camel.h"


CML_TestResult test_matrix2x2_add(void) {
    CML_Matrix2x2 A = CML_MATRIX2X2(
        1.0f, 2.0f, 
        3.0f, 4.0f
    );
    CML_Matrix2x2 B = CML_MATRIX2X2(
        5.0f, 6.0f,
        7.0f, 8.0f
    );
    CML_Matrix2x2 out;
    CML_Matrix2x2 expected = CML_MATRIX2X2(
        6.0f, 8.0f,
        10.0f, 12.0f
    );
    cml_matrix2x2_add(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x2_sub(void) {
    CML_Matrix2x2 A = CML_MATRIX2X2(
        1.0f, 2.0f,
        3.0f, 4.0f
    );
    CML_Matrix2x2 B = CML_MATRIX2X2(
        5.0f, 6.0f,
        7.0f, 8.0f
    );
    CML_Matrix2x2 out;
    CML_Matrix2x2 expected = CML_MATRIX2X2(
        -4.0f, -4.0f,
        -4.0f, -4.0f
    );
    cml_matrix2x2_sub(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x2_scale(void) {
    CML_Matrix2x2 A = CML_MATRIX2X2(
        1.0f, 2.0f,
        3.0f, 4.0f
    );
    CML_Matrix2x2 out;
    CML_Matrix2x2 expected = CML_MATRIX2X2(
        2.0f, 4.0f,
        6.0f, 8.0f
    );
    cml_matrix2x2_scale(&A, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x2_mult(void) {
    CML_Matrix2x2 A = CML_MATRIX2X2(
        1.0f, 2.0f,
        3.0f, 4.0f
    );
    CML_Matrix2x2 B = CML_MATRIX2X2(
        5.0f, 6.0f,
        7.0f, 8.0f
    );
    CML_Matrix2x2 out;
    CML_Matrix2x2 expected = CML_MATRIX2X2(
        19.0f, 22.0f,
        43.0f, 50.0f
    );
    cml_matrix2x2_mult(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x2_mult_matrix2x3(void) {
    CML_Matrix2x2 A = CML_MATRIX2X2(
        1.0f, 2.0f,
        3.0f, 4.0f
    );
    CML_Matrix2x3 B = CML_MATRIX2X3(
        5.0f, 6.0f, 7.0f,
        8.0f, 9.0f, 10.0f
    );
    CML_Matrix2x3 out;
    CML_Matrix2x3 expected = CML_MATRIX2X3(
        21.0f, 24.0f, 27.0f,
        47.0f, 54.0f, 61.0f
    );
    cml_matrix2x2_mult_matrix2x3(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x2_mult_matrix2x4(void) {
    CML_Matrix2x2 A = CML_MATRIX2X2(
        1.0f, 2.0f,
        3.0f, 4.0f
    );
    CML_Matrix2x4 B = CML_MATRIX2X4(
        5.0f, 6.0f, 7.0f, 8.0f,
        9.0f, 10.0f, 11.0f, 12.0f
    );
    CML_Matrix2x4 out;
    CML_Matrix2x4 expected = CML_MATRIX2X4(
        23.0f, 26.0f, 29.0f, 32.0f,
        51.0f, 58.0f, 65.0f, 72.0f
    );
    cml_matrix2x2_mult_matrix2x4(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x2_mult_vector2(void) {
    CML_Matrix2x2 A = CML_MATRIX2X2(
        1.0f, 2.0f,
        3.0f, 4.0f
    );
    CML_Vector2 v = {{5.0f, 6.0f}};
    CML_Vector2 out;
    CML_Vector2 expected = {{17.0f, 39.0f}};
    cml_matrix2x2_mult_vector2(&A, &v, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector2_mult_matrix2x2(void) {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Matrix2x2 A = CML_MATRIX2X2(
        3.0f, 4.0f,
        5.0f, 6.0f
    );
    CML_Vector2 out;
    CML_Vector2 expected = {{13.0f, 16.0f}};
    cml_vector2_mult_matrix2x2(&v, &A, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x2_det(void) {
    CML_Matrix2x2 A = CML_MATRIX2X2(
        1.0f, 2.0f,
        3.0f, 4.0f
    );
    f32 expected = -2.0f;
    f32 result = cml_matrix2x2_det(&A);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_matrix2x2_inv(void) {
    CML_Matrix2x2 A = CML_MATRIX2X2(
        1.0f, 2.0f,
        3.0f, 4.0f
    );
    CML_Matrix2x2 out = CML_MATRIX2X2_ONE;
    CML_Matrix2x2 expected = CML_MATRIX2X2(
        -2.0f, 1.0f,
        1.5f, -0.5f
    );
    cml_matrix2x2_inv(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x2_transpose(void) {
    CML_Matrix2x2 A = CML_MATRIX2X2(
        1.0f, 2.0f,
        3.0f, 4.0f
    );
    CML_Matrix2x2 out;
    CML_Matrix2x2 expected = CML_MATRIX2X2(
        1.0f, 3.0f,
        2.0f, 4.0f
    );
    cml_matrix2x2_transpose(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x2_trace(void) {
    CML_Matrix2x2 A = CML_MATRIX2X2(
        1.0f, 2.0f,
        3.0f, 4.0f
    );
    f32 expected = 5.0f;
    f32 result = cml_matrix2x2_trace(&A);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_matrix2x2_gen_scale(void) {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Matrix2x2 out;
    CML_Vector2 expected = {{2.0f, 6.0f}};
    cml_matrix2x2_gen_scale(2.0f, 3.0f, &out);
    cml_matrix2x2_mult_vector2(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix2x2_gen_invscale(void) {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Matrix2x2 out;
    CML_Vector2 expected = {{1.0f, 2.0f}};
    cml_matrix2x2_gen_scale(2.0f, 3.0f, &out);
    cml_matrix2x2_mult_vector2(&out, &v, &v);
    cml_matrix2x2_gen_invscale(&out, &out);
    cml_matrix2x2_mult_vector2(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix2x2_gen_shearx(void) {
    CML_Vector2 v = {{1.0f, 1.0f}};
    CML_Matrix2x2 out;
    CML_Vector2 expected = {{2.0f, 1.0f}};
    cml_matrix2x2_gen_shearx(1.0f, &out);
    cml_matrix2x2_mult_vector2(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix2x2_gen_sheary(void) {
    CML_Vector2 v = {{1.0f, 1.0f}};
    CML_Matrix2x2 out;
    CML_Vector2 expected = {{1.0f, 2.0f}};
    cml_matrix2x2_gen_sheary(1.0f, &out);
    cml_matrix2x2_mult_vector2(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix2x2_gen_invshear(void) {
    CML_Vector2 v = {{1.0f, 1.0f}};
    CML_Matrix2x2 out1;
    CML_Matrix2x2 out2;
    CML_Vector2 expected = {{1.0f, 1.0f}};
    cml_matrix2x2_gen_shearx(10.0f, &out1);
    cml_matrix2x2_mult_vector2(&out1, &v, &v);
    cml_matrix2x2_gen_sheary(1.0f, &out2);
    cml_matrix2x2_mult_vector2(&out2, &v, &v);
    cml_matrix2x2_gen_invshear(&out1, &out1);
    cml_matrix2x2_gen_invshear(&out2, &out2);
    cml_matrix2x2_mult_vector2(&out2, &v, &v);
    cml_matrix2x2_mult_vector2(&out1, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix2x2_genlh_rotation(void) {
    CML_Vector2 v = {{1.0f, 1.0f}};
    CML_Matrix2x2 out;
    CML_Vector2 expected = {{1.0f, -1.0f}};
    cml_matrix2x2_genlh_rotation(CML_PI/2.0f, &out);
    cml_matrix2x2_mult_vector2(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix2x2_genrh_rotation(void) {
    CML_Vector2 v = {{1.0f, 1.0f}};
    CML_Matrix2x2 out;
    CML_Vector2 expected = {{-1.0f, 1.0f}};
    cml_matrix2x2_genrh_rotation(CML_PI/2.0f, &out);
    cml_matrix2x2_mult_vector2(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix2x2_gen_invrotation(void) {
    CML_Vector2 v = {{1.0f, 1.0f}};
    CML_Matrix2x2 out1;
    CML_Matrix2x2 out2;
    CML_Vector2 expected = {{1.0f, 1.0f}};
    cml_matrix2x2_genlh_rotation(CML_PI/2.0f, &out1);
    cml_matrix2x2_mult_vector2(&out1, &v, &v);
    cml_matrix2x2_gen_invrotation(&out1, &out1);
    cml_matrix2x2_mult_vector2(&out1, &v, &v);
    cml_matrix2x2_genrh_rotation(CML_PI/2.0f, &out2);
    cml_matrix2x2_mult_vector2(&out2, &v, &v);
    cml_matrix2x2_gen_invrotation(&out2, &out2);
    cml_matrix2x2_mult_vector2(&out2, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &v);
    }
    return result;
}



CML_TestResult test_matrix3x3_add(void) {
    CML_Matrix3x3 A = CML_MATRIX3X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    );
    CML_Matrix3x3 B = CML_MATRIX3X3(
        10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f,
        16.0f, 17.0f, 18.0f
    );
    CML_Matrix3x3 out;
    CML_Matrix3x3 expected = CML_MATRIX3X3(
        11.0f, 13.0f, 15.0f,
        17.0f, 19.0f, 21.0f,
        23.0f, 25.0f, 27.0f
    );
    cml_matrix3x3_add(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x3_sub(void) {
    CML_Matrix3x3 A = CML_MATRIX3X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    );
    CML_Matrix3x3 B = CML_MATRIX3X3(
        10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f,
        16.0f, 17.0f, 18.0f
    );
    CML_Matrix3x3 out;
    CML_Matrix3x3 expected = CML_MATRIX3X3(
        -9.0f, -9.0f, -9.0f,
        -9.0f, -9.0f, -9.0f,
        -9.0f, -9.0f, -9.0f
    );
    cml_matrix3x3_sub(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x3_scale(void) {
    CML_Matrix3x3 A = CML_MATRIX3X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    );
    CML_Matrix3x3 out;
    CML_Matrix3x3 expected = CML_MATRIX3X3(
        2.0f, 4.0f, 6.0f,
        8.0f, 10.0f, 12.0f,
        14.0f, 16.0f, 18.0f
    );
    cml_matrix3x3_scale(&A, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x3_mult(void) {
    CML_Matrix3x3 A = CML_MATRIX3X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    );
    CML_Matrix3x3 B = CML_MATRIX3X3(
        10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f,
        16.0f, 17.0f, 18.0f
    );
    CML_Matrix3x3 out;
    CML_Matrix3x3 expected = CML_MATRIX3X3(
        84.0f, 90.0f, 96.0f,
        201.0f, 216.0f, 231.0f,
        318.0f, 342.0f, 366.0f
    );
    cml_matrix3x3_mult(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x3_mult_matrix3x2(void) {
    CML_Matrix3x3 A = CML_MATRIX3X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    );
    CML_Matrix3x2 B = CML_MATRIX3X2(
        10.0f, 11.0f,
        12.0f, 13.0f,
        14.0f, 15.0f
    );
    CML_Matrix3x2 out;
    CML_Matrix3x2 expected = CML_MATRIX3X2(
        76.0f, 82.0f,
        184.0f, 199.0f,
        292.0f, 316.0f
    );
    cml_matrix3x3_mult_matrix3x2(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x3_mult_matrix3x4(void) {
    CML_Matrix3x3 A = CML_MATRIX3X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    );
    CML_Matrix3x4 B = CML_MATRIX3X4(
        10.0f, 11.0f, 12.0f, 13.0f,
        14.0f, 15.0f, 16.0f, 17.0f,
        18.0f, 19.0f, 20.0f, 21.0f
    );
    CML_Matrix3x4 out;
    CML_Matrix3x4 expected = CML_MATRIX3X4(
        92.0f, 98.0f, 104.0f, 110.0f,
        218.0f, 233.0f, 248.0f, 263.0f,
        344.0f, 368.0f, 392.0f, 416.0f
    );
    cml_matrix3x3_mult_matrix3x4(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x3_mult_vector3(void) {
    CML_Matrix3x3 A = CML_MATRIX3X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    );
    CML_Vector3 v = {{10.0f, 11.0f, 12.0f}};
    CML_Vector3 out;
    CML_Vector3 expected = {{68.0f, 167.0f, 266.0f}};
    cml_matrix3x3_mult_vector3(&A, &v, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector3_mult_matrix3x3(void) {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Matrix3x3 A = CML_MATRIX3X3(
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f,
        10.0f, 11.0f, 12.0f
    );
    CML_Vector3 out;
    CML_Vector3 expected = {{48.0f, 54.0f, 60.0f}};
    cml_vector3_mult_matrix3x3(&v, &A, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x3_det(void) {
    CML_Matrix3x3 A = CML_MATRIX3X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    );
    f32 expected = 0.0f;
    f32 result = cml_matrix3x3_det(&A);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_matrix3x3_inv(void) {
    CML_Matrix3x3 A = CML_MATRIX3X3(
        1.0f, 2.0f, 3.0f,
        0.0f, 1.0f, 4.0f,
        5.0f, 6.0f, 0.0f
    );
    CML_Matrix3x3 out;
    CML_Matrix3x3 expected = CML_MATRIX3X3(
        -24.0f, 18.0f, 5.0f,
        20.0f, -15.0f, -4.0f,
        -5.0f, 4.0f, 1.0f
    );
    cml_matrix3x3_inv(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x3_transpose(void) {
    CML_Matrix3x3 A = CML_MATRIX3X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    );
    CML_Matrix3x3 out;
    CML_Matrix3x3 expected = CML_MATRIX3X3(
        1.0f, 4.0f, 7.0f,
        2.0f, 5.0f, 8.0f,
        3.0f, 6.0f, 9.0f
    );
    cml_matrix3x3_transpose(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x3_trace(void) {
    CML_Matrix3x3 A = CML_MATRIX3X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    );
    f32 expected = 15.0f;
    f32 result = cml_matrix3x3_trace(&A);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_matrix3x3_gen_scale(void) {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Matrix3x3 out;
    CML_Vector3 expected = {{2.0f, 6.0f, 12.0f}};
    cml_matrix3x3_gen_scale(2.0f, 3.0f, 4.0f, &out);
    cml_matrix3x3_mult_vector3(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix3x3_gen_invscale(void) {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Matrix3x3 out;
    CML_Vector3 expected = {{1.0f, 2.0f, 3.0f}};
    cml_matrix3x3_gen_scale(2.0f, 3.0f, 4.0f, &out);
    cml_matrix3x3_mult_vector3(&out, &v, &v);
    cml_matrix3x3_gen_invscale(&out, &out);
    cml_matrix3x3_mult_vector3(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix3x3_gen_shearx(void) {
    CML_Vector3 v = {{1.0f, 1.0f, 1.0f}};
    CML_Matrix3x3 out;
    CML_Vector3 expected = {{3.0f, 1.0f, 1.0f}};
    cml_matrix3x3_gen_shearx(1.0f, 1.0f, &out);
    cml_matrix3x3_mult_vector3(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix3x3_gen_sheary(void) {
    CML_Vector3 v = {{1.0f, 1.0f, 1.0f}};
    CML_Matrix3x3 out;
    CML_Vector3 expected = {{1.0f, 3.0f, 1.0f}};
    cml_matrix3x3_gen_sheary(1.0f, 1.0f, &out);
    cml_matrix3x3_mult_vector3(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix3x3_gen_shearz(void) {
    CML_Vector3 v = {{1.0f, 1.0f, 1.0f}};
    CML_Matrix3x3 out;
    CML_Vector3 expected = {{1.0f, 1.0f, 3.0f}};
    cml_matrix3x3_gen_shearz(1.0f, 1.0f, &out);
    cml_matrix3x3_mult_vector3(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix3x3_gen_invshear(void) {
    CML_Vector3 v = {{1.0f, 1.0f, 1.0f}};
    CML_Matrix3x3 out1;
    CML_Matrix3x3 out2;
    CML_Matrix3x3 out3;
    CML_Vector3 expected = {{1.0f, 1.0f, 1.0f}};
    cml_matrix3x3_gen_shearx(10.0f, 10.0f, &out1);
    cml_matrix3x3_mult_vector3(&out1, &v, &v);
    cml_matrix3x3_gen_sheary(10.0f, 10.0f, &out2);
    cml_matrix3x3_mult_vector3(&out2, &v, &v);
    cml_matrix3x3_gen_shearz(10.0f, 10.0f, &out3);
    cml_matrix3x3_mult_vector3(&out3, &v, &v);
    cml_matrix3x3_gen_invshear(&out1, &out1);
    cml_matrix3x3_gen_invshear(&out2, &out2);
    cml_matrix3x3_gen_invshear(&out3, &out3);
    cml_matrix3x3_mult_vector3(&out3, &v, &v);
    cml_matrix3x3_mult_vector3(&out2, &v, &v);
    cml_matrix3x3_mult_vector3(&out1, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix3x3_genlh_rotationx(void) {
    CML_Vector3 v = {{1.0f, 1.0f, 1.0f}};
    CML_Matrix3x3 out;
    CML_Vector3 expected = {{1.0f, 1.0f, -1.0f}};
    cml_matrix3x3_genlh_rotationx(CML_PI/2.0f, &out);
    cml_matrix3x3_mult_vector3(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix3x3_genlh_rotationy(void) {
    CML_Vector3 v = {{1.0f, 1.0f, 1.0f}};
    CML_Matrix3x3 out;
    CML_Vector3 expected = {{-1.0f, 1.0f, 1.0f}};
    cml_matrix3x3_genlh_rotationy(CML_PI/2.0f, &out);
    cml_matrix3x3_mult_vector3(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix3x3_genlh_rotationz(void) {
    CML_Vector3 v = {{1.0f, 1.0f, 1.0f}};
    CML_Matrix3x3 out;
    CML_Vector3 expected = {{1.0f, -1.0f, 1.0f}};
    cml_matrix3x3_genlh_rotationz(CML_PI/2.0f, &out);
    cml_matrix3x3_mult_vector3(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix3x3_genlh_rotation(void) {
    CML_Vector3 v = {{1.0f, 1.0f, 1.0f}};
    CML_Matrix3x3 out;
    CML_Vector3 axis = {{1.0f, 1.0f, 0.0f}};
    CML_Vector3 expected = {{1.0f, 1.0f, -1.0f}};
    cml_matrix3x3_genlh_rotation(CML_PI, &axis, &out);
    cml_matrix3x3_mult_vector3(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix3x3_genrh_rotationx(void) {
    CML_Vector3 v = {{1.0f, 1.0f, 1.0f}};
    CML_Matrix3x3 out;
    CML_Vector3 expected = {{1.0f, -1.0f, 1.0f}};
    cml_matrix3x3_genrh_rotationx(CML_PI/2.0f, &out);
    cml_matrix3x3_mult_vector3(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix3x3_genrh_rotationy(void) {
    CML_Vector3 v = {{1.0f, 1.0f, 1.0f}};
    CML_Matrix3x3 out;
    CML_Vector3 expected = {{1.0f, 1.0f, -1.0f}};
    cml_matrix3x3_genrh_rotationy(CML_PI/2.0f, &out);
    cml_matrix3x3_mult_vector3(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&v, &expected);
    if (!result.passed) { 
        result.debugMessage = cml_vector3_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix3x3_genrh_rotationz(void) {
    CML_Vector3 v = {{1.0f, 1.0f, 1.0f}}; 
    CML_Matrix3x3 out;
    CML_Vector3 expected = {{-1.0f, 1.0f, 1.0f}};
    cml_matrix3x3_genrh_rotationz(CML_PI/2.0f, &out);
    cml_matrix3x3_mult_vector3(&out, &v, &v); 
    CML_TestResult result;
    result.passed = cml_vector3_eq(&v, &expected);
    if (!result.passed) { 
        result.debugMessage = cml_vector3_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix3x3_genrh_rotation(void) {
    CML_Vector3 v = {{1.0f, 1.0f, 1.0f}}; 
    CML_Matrix3x3 out;
    CML_Vector3 axis = {{1.0f, 0.0f, 1.0f}};
    CML_Vector3 expected = {{1.0f, -1.0f, 1.0f}};
    cml_matrix3x3_genrh_rotation(CML_PI, &axis, &out);
    cml_matrix3x3_mult_vector3(&out, &v, &v); 
    CML_TestResult result;
    result.passed = cml_vector3_eq(&v, &expected);
    if (!result.passed) { 
        result.debugMessage = cml_vector3_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix3x3_gen_invrotation(void) {
    CML_Vector3 v = {{1.0f, 1.0f, 1.0f}}; 
    CML_Matrix3x3 out1;
    CML_Matrix3x3 out2;
    CML_Vector3 expected = {{1.0f, 1.0f, 1.0f}};
    cml_matrix3x3_genlh_rotationx(1.75f, &out1);
    cml_matrix3x3_mult_vector3(&out1, &v, &v); 
    cml_matrix3x3_genrh_rotationy(3.0f, &out2);
    cml_matrix3x3_mult_vector3(&out2, &v, &v); 
    cml_matrix3x3_gen_invrotation(&out1, &out1);
    cml_matrix3x3_gen_invrotation(&out2, &out2);
    cml_matrix3x3_mult_vector3(&out2, &v, &v); 
    cml_matrix3x3_mult_vector3(&out1, &v, &v); 
    CML_TestResult result;
    result.passed = cml_vector3_eq(&v, &expected);
    if (!result.passed) { 
        result.debugMessage = cml_vector3_debug(&expected, &v);
    }
    return result;
}



CML_TestResult test_matrix4x4_add(void) {
    CML_Matrix4x4 A = CML_MATRIX4X4(
        1.0f, 2.0f, 3.0f, 4.0f,
        5.0f, 6.0f, 7.0f, 8.0f,
        9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f
    );
    CML_Matrix4x4 B = CML_MATRIX4X4(
        17.0f, 18.0f, 19.0f, 20.0f,
        21.0f, 22.0f, 23.0f, 24.0f,
        25.0f, 26.0f, 27.0f, 28.0f,
        29.0f, 30.0f, 31.0f, 32.0f
    );
    CML_Matrix4x4 out;
    CML_Matrix4x4 expected = CML_MATRIX4X4(
        18.0f, 20.0f, 22.0f, 24.0f,
        26.0f, 28.0f, 30.0f, 32.0f,
        34.0f, 36.0f, 38.0f, 40.0f,
        42.0f, 44.0f, 46.0f, 48.0f
    );
    cml_matrix4x4_add(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x4_sub(void) {
    CML_Matrix4x4 A = CML_MATRIX4X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f, 
        9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f
    );
    CML_Matrix4x4 B = CML_MATRIX4X4(
        17.0f, 18.0f, 19.0f, 20.0f,
        21.0f, 22.0f, 23.0f, 24.0f,
        25.0f, 26.0f, 27.0f, 28.0f,
        29.0f, 30.0f, 31.0f, 32.0f
    );
    CML_Matrix4x4 out;
    CML_Matrix4x4 expected = CML_MATRIX4X4(
        -16.0f, -16.0f, -16.0f, -16.0f,
        -16.0f, -16.0f, -16.0f, -16.0f,
        -16.0f, -16.0f, -16.0f, -16.0f,
        -16.0f, -16.0f, -16.0f, -16.0f
    );
    cml_matrix4x4_sub(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x4_scale(void) {
    CML_Matrix4x4 A = CML_MATRIX4X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f, 
        9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f
    );
    CML_Matrix4x4 out;
    CML_Matrix4x4 expected = CML_MATRIX4X4(
        2.0f, 4.0f, 6.0f, 8.0f, 
        10.0f, 12.0f, 14.0f, 16.0f, 
        18.0f, 20.0f, 22.0f, 24.0f,
        26.0f, 28.0f, 30.0f, 32.0f
    );
    cml_matrix4x4_scale(&A, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x4_mult(void) {
    CML_Matrix4x4 A = CML_MATRIX4X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f, 
        9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f
    );
    CML_Matrix4x4 B = CML_MATRIX4X4(
        17.0f, 18.0f, 19.0f, 20.0f,
        21.0f, 22.0f, 23.0f, 24.0f,
        25.0f, 26.0f, 27.0f, 28.0f,
        29.0f, 30.0f, 31.0f, 32.0f
    );
    CML_Matrix4x4 out;
    CML_Matrix4x4 expected = CML_MATRIX4X4(
        250.0f, 260.0f, 270.0f, 280.0f,
        618.0f, 644.0f, 670.0f, 696.0f,
        986.0f, 1028.0f, 1070.0f, 1112.0f,
        1354.0f, 1412.0f, 1470.0f, 1528.0f
    );
    cml_matrix4x4_mult(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x4_mult_matrix4x2(void) {
    CML_Matrix4x4 A = CML_MATRIX4X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f, 
        9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f
    );
    CML_Matrix4x2 B = CML_MATRIX4X2(
        17.0f, 18.0f,
        19.0f, 20.0f,
        21.0f, 22.0f,
        23.0f, 24.0f
    );
    CML_Matrix4x2 out;
    CML_Matrix4x2 expected = CML_MATRIX4X2(
        210.0f, 220.0f,
        530.0f, 556.0f,
        850.0f, 892.0f,
        1170.0f, 1228.0f
    );
    cml_matrix4x4_mult_matrix4x2(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x4_mult_matrix4x3(void) {
    CML_Matrix4x4 A = CML_MATRIX4X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f, 
        9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f
    );
    CML_Matrix4x3 B = CML_MATRIX4X3(
        17.0f, 18.0f, 19.0f,
        20.0f, 21.0f, 22.0f,
        23.0f, 24.0f, 25.0f,
        26.0f, 27.0f, 28.0f
    );
    CML_Matrix4x3 out;
    CML_Matrix4x3 expected = CML_MATRIX4X3(
        230.0f, 240.0f, 250.0f,
        574.0f, 600.0f, 626.0f,
        918.0f, 960.0f, 1002.0f,
        1262.0f, 1320.0f, 1378.0f
    );
    cml_matrix4x4_mult_matrix4x3(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x4_mult_vector4(void) {
    CML_Matrix4x4 A = CML_MATRIX4X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f, 
        9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f
    );
    CML_Vector4 v = {{17.0f, 18.0f, 19.0f, 20.0f}};
    CML_Vector4 out;
    CML_Vector4 expected = {{190.0f, 486.0f, 782.0f, 1078.0f}};
    cml_matrix4x4_mult_vector4(&A, &v, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector4_mult_matrix4x4(void) {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Matrix4x4 A = CML_MATRIX4X4(
        5.0f, 6.0f, 7.0f, 8.0f, 
        9.0f, 10.0f, 11.0f, 12.0f, 
        13.0f, 14.0f, 15.0f, 16.0f,
        17.0f, 18.0f, 19.0f, 20.0f
    );
    CML_Vector4 out;
    CML_Vector4 expected = {{130.0f, 140.0f, 150.0f, 160.0f}};
    cml_vector4_mult_matrix4x4(&v, &A, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x4_det(void) {
    CML_Matrix4x4 A = CML_MATRIX4X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f, 
        9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f
    );
    f32 expected = 0.0f;
    f32 result = cml_matrix4x4_det(&A);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_matrix4x4_inv(void) {
    CML_Matrix4x4 A = CML_MATRIX4X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        0.0f, 1.0f, 5.0f, 6.0f, 
        7.0f, 8.0f, 0.0f, 9.0f,
        10.0f, 11.0f, 12.0f, 0.0f
    );
    CML_Matrix4x4 out;
    CML_Matrix4x4 expected = CML_MATRIX4X4(
        -2.8918918918918918922f, 1.3963963963963963967f, 0.35435435435435435445f, 0.1411411411411411411f,
        2.864864864864864865f, -1.4954954954954954955f, -0.27627627627627627631f, -0.09309309309309309308f,
        -0.21621621621621621625f, 0.20720720720720720723f, -0.04204204204204204203f, 0.051051051051051051048f,
        -0.29729729729729729729f, 0.24324324324324324324f, 0.081081081081081081081f, -0.027027027027027027027f
    );
    cml_matrix4x4_inv(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x4_transpose(void) {
    CML_Matrix4x4 A = CML_MATRIX4X4(
        1.0f, 2.0f, 3.0f, 4.0f,
        5.0f, 6.0f, 7.0f, 8.0f,
        9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f
    );
    CML_Matrix4x4 out;
    CML_Matrix4x4 expected = CML_MATRIX4X4(
        1.0f, 5.0f, 9.0f, 13.0f,
        2.0f, 6.0f, 10.0f, 14.0f,
        3.0f, 7.0f, 11.0f, 15.0f,
        4.0f, 8.0f, 12.0f, 16.0f
    );
    cml_matrix4x4_transpose(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x4_trace(void) {
    CML_Matrix4x4 A = CML_MATRIX4X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f, 
        9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f
    );
    f32 expected = 34.0f;
    f32 result = cml_matrix4x4_trace(&A);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? true : false;
    if (!test.passed) {
        test.debugMessage = cml_f32_debug(expected, result);
    }
    return test;
}


CML_TestResult test_matrix4x4_gen_scale(void) {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 1.0f}};
    CML_Matrix4x4 out;
    CML_Vector4 expected = {{2.0f, 6.0f, 12.0f, 1.0f}};
    cml_matrix4x4_gen_scale(2.0f, 3.0f, 4.0f, &out);
    cml_matrix4x4_mult_vector4(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix4x4_gen_invscale(void) {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 1.0f}};
    CML_Matrix4x4 out;
    CML_Vector4 expected = {{1.0f, 2.0f, 3.0f, 1.0f}};
    cml_matrix4x4_gen_scale(2.0f, 3.0f, 4.0f, &out);
    cml_matrix4x4_mult_vector4(&out, &v, &v);
    cml_matrix4x4_gen_invscale(&out, &out);
    cml_matrix4x4_mult_vector4(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix4x4_gen_shearx(void) {
    CML_Vector4 v = {{1.0f, 1.0f, 1.0f, 1.0f}};
    CML_Matrix4x4 out;
    CML_Vector4 expected = {{3.0f, 1.0f, 1.0f, 1.0f}};
    cml_matrix4x4_gen_shearx(1.0f, 1.0f, &out);
    cml_matrix4x4_mult_vector4(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix4x4_gen_sheary(void) {
    CML_Vector4 v = {{1.0f, 1.0f, 1.0f, 1.0f}};
    CML_Matrix4x4 out;
    CML_Vector4 expected = {{1.0f, 3.0f, 1.0f, 1.0f}};
    cml_matrix4x4_gen_sheary(1.0f, 1.0f, &out);
    cml_matrix4x4_mult_vector4(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix4x4_gen_shearz(void) {
    CML_Vector4 v = {{1.0f, 1.0f, 1.0f, 1.0f}};
    CML_Matrix4x4 out;
    CML_Vector4 expected = {{1.0f, 1.0f, 3.0f, 1.0f}};
    cml_matrix4x4_gen_shearz(1.0f, 1.0f, &out);
    cml_matrix4x4_mult_vector4(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix4x4_gen_invshear(void) {
    CML_Vector4 v = {{1.0f, 1.0f, 1.0f, 1.0f}};
    CML_Matrix4x4 out1;
    CML_Matrix4x4 out2;
    CML_Matrix4x4 out3;
    CML_Vector4 expected = {{1.0f, 1.0f, 1.0f, 1.0f}};
    cml_matrix4x4_gen_shearx(10.0f, 10.0f, &out1);
    cml_matrix4x4_mult_vector4(&out1, &v, &v);
    cml_matrix4x4_gen_sheary(10.0f, 10.0f, &out2);
    cml_matrix4x4_mult_vector4(&out2, &v, &v);
    cml_matrix4x4_gen_shearz(10.0f, 10.0f, &out3);
    cml_matrix4x4_mult_vector4(&out3, &v, &v);
    cml_matrix4x4_gen_invshear(&out1, &out1);
    cml_matrix4x4_gen_invshear(&out2, &out2);
    cml_matrix4x4_gen_invshear(&out3, &out3);
    cml_matrix4x4_mult_vector4(&out3, &v, &v);
    cml_matrix4x4_mult_vector4(&out2, &v, &v);
    cml_matrix4x4_mult_vector4(&out1, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix4x4_gen_translation(void) {
    CML_Vector4 v = {{1.0f, 1.0f, 1.0f, 1.0f}};
    CML_Matrix4x4 out;
    CML_Vector4 expected = {{2.0f, 3.0f, 4.0f, 1.0f}};
    cml_matrix4x4_gen_translation(1.0f, 2.0f, 3.0f, &out);
    cml_matrix4x4_mult_vector4(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix4x4_gen_invtranslation(void) {
    CML_Vector4 v = {{1.0f, 1.0f, 1.0f, 1.0f}};
    CML_Matrix4x4 out;
    CML_Vector4 expected = {{1.0f, 1.0f, 1.0f, 1.0f}};
    cml_matrix4x4_gen_translation(1.0f, 2.0f, 3.0f, &out);
    cml_matrix4x4_mult_vector4(&out, &v, &v);
    cml_matrix4x4_gen_invtranslation(&out, &out);
    cml_matrix4x4_mult_vector4(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix4x4_genlh_rotationx(void) {
    CML_Vector4 v = {{1.0f, 1.0f, 1.0f, 1.0f}}; 
    CML_Matrix4x4 out;
    CML_Vector4 expected = {{1.0f, 1.0f, -1.0f, 1.0f}};
    cml_matrix4x4_genlh_rotationx(CML_PI/2.0f, &out);
    cml_matrix4x4_mult_vector4(&out, &v, &v); 
    CML_TestResult result;
    result.passed = cml_vector4_eq(&v, &expected);
    if (!result.passed) { 
        result.debugMessage = cml_vector4_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix4x4_genlh_rotationy(void) {
    CML_Vector4 v = {{1.0f, 1.0f, 1.0f, 1.0f}};
    CML_Matrix4x4 out;
    CML_Vector4 expected = {{-1.0f, 1.0f, 1.0f, 1.0f}};
    cml_matrix4x4_genlh_rotationy(CML_PI_OVER_2, &out);
    cml_matrix4x4_mult_vector4(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&v, &expected);
    if (!result.passed) { 
        result.debugMessage = cml_vector4_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix4x4_genlh_rotationz(void) {
    CML_Vector4 v = {{1.0f, 1.0f, 1.0f, 1.0f}};
    CML_Matrix4x4 out;
    CML_Vector4 expected = {{1.0f, -1.0f, 1.0f, 1.0f}};
    cml_matrix4x4_genlh_rotationz(CML_PI_OVER_2, &out);
    cml_matrix4x4_mult_vector4(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&v, &expected);
    if (!result.passed) { 
        result.debugMessage = cml_vector4_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix4x4_genlh_rotation(void) {
    CML_Vector4 v = {{1.0f, 1.0f, 1.0f, 1.0f}};
    CML_Matrix4x4 out;
    CML_Vector3 axis = {{1.0f, 1.0f, 0.0f}};
    CML_Vector4 expected = {{1.0f, 1.0f, -1.0f, 1.0f}};
    cml_matrix4x4_genlh_rotation(CML_PI, &axis, &out);
    cml_matrix4x4_mult_vector4(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&v, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix4x4_genrh_rotationx(void) {
    CML_Vector4 v = {{1.0f, 1.0f, 1.0f, 1.0f}}; 
    CML_Matrix4x4 out;
    CML_Vector4 expected = {{1.0f, -1.0f, 1.0f, 1.0f}};
    cml_matrix4x4_genrh_rotationx(CML_PI/2.0f, &out);
    cml_matrix4x4_mult_vector4(&out, &v, &v); 
    CML_TestResult result;
    result.passed = cml_vector4_eq(&v, &expected);
    if (!result.passed) { 
        result.debugMessage = cml_vector4_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix4x4_genrh_rotationy(void) {
    CML_Vector4 v = {{1.0f, 1.0f, 1.0f, 1.0f}};
    CML_Matrix4x4 out;
    CML_Vector4 expected = {{1.0f, 1.0f, -1.0f, 1.0f}};
    cml_matrix4x4_genrh_rotationy(CML_PI_OVER_2, &out);
    cml_matrix4x4_mult_vector4(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&v, &expected);
    if (!result.passed) { 
        result.debugMessage = cml_vector4_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix4x4_genrh_rotationz(void) {
    CML_Vector4 v = {{1.0f, 1.0f, 1.0f, 1.0f}};
    CML_Matrix4x4 out;
    CML_Vector4 expected = {{-1.0f, 1.0f, 1.0f, 1.0f}};
    cml_matrix4x4_genrh_rotationz(CML_PI_OVER_2, &out);
    cml_matrix4x4_mult_vector4(&out, &v, &v);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&v, &expected);
    if (!result.passed) { 
        result.debugMessage = cml_vector4_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix4x4_genrh_rotation(void) {
    CML_Vector4 v = {{1.0f, 1.0f, 1.0f, 1.0f}}; 
    CML_Matrix4x4 out;
    CML_Vector3 axis = {{1.0f, 0.0f, 1.0f}};
    CML_Vector4 expected = {{1.0f, -1.0f, 1.0f, 1.0f}};
    cml_matrix4x4_genrh_rotation(CML_PI, &axis, &out);
    cml_matrix4x4_mult_vector4(&out, &v, &v); 
    CML_TestResult result;
    result.passed = cml_vector4_eq(&v, &expected);
    if (!result.passed) { 
        result.debugMessage = cml_vector4_debug(&expected, &v);
    }
    return result;
}


CML_TestResult test_matrix4x4_gen_invrotation(void) {
    CML_Vector4 v = {{1.0f, 1.0f, 1.0f, 1.0f}}; 
    CML_Matrix4x4 out1;
    CML_Matrix4x4 out2;
    CML_Vector4 expected = {{1.0f, 1.0f, 1.0f, 1.0f}};
    cml_matrix4x4_genlh_rotationx(1.75f, &out1);
    cml_matrix4x4_mult_vector4(&out1, &v, &v); 
    cml_matrix4x4_genrh_rotationy(3.0f, &out2);
    cml_matrix4x4_mult_vector4(&out2, &v, &v); 
    cml_matrix4x4_gen_invrotation(&out1, &out1);
    cml_matrix4x4_gen_invrotation(&out2, &out2);
    cml_matrix4x4_mult_vector4(&out2, &v, &v); 
    cml_matrix4x4_mult_vector4(&out1, &v, &v); 
    CML_TestResult result;
    result.passed = cml_vector4_eq(&v, &expected);
    if (!result.passed) { 
        result.debugMessage = cml_vector4_debug(&expected, &v);
    }
    return result;
}



CML_TestResult test_matrix2x3_add(void) {
    CML_Matrix2x3 A = CML_MATRIX2X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f
    );
    CML_Matrix2x3 B = CML_MATRIX2X3(
        7.0f, 8.0f, 9.0f,
        10.0f, 11.0f, 12.0f
    );
    CML_Matrix2x3 out;
    CML_Matrix2x3 expected = CML_MATRIX2X3(
        8.0f, 10.0f, 12.0f,
        14.0f, 16.0f, 18.0f
    );
    cml_matrix2x3_add(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x3_sub(void) {
    CML_Matrix2x3 A = CML_MATRIX2X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f
    );
    CML_Matrix2x3 B = CML_MATRIX2X3(
        7.0f, 8.0f, 9.0f,
        10.0f, 11.0f, 12.0f
    );
    CML_Matrix2x3 out;
    CML_Matrix2x3 expected = CML_MATRIX2X3(
        -6.0f, -6.0f, -6.0f,
        -6.0f, -6.0f, -6.0f
    );
    cml_matrix2x3_sub(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x3_scale(void) {
    CML_Matrix2x3 A = CML_MATRIX2X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f
    );
    CML_Matrix2x3 out;
    CML_Matrix2x3 expected = CML_MATRIX2X3(
        2.0f, 4.0f, 6.0f,
        8.0f, 10.0f, 12.0f
    );
    cml_matrix2x3_scale(&A, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x3_mult_matrix3x2(void) {
    CML_Matrix2x3 A = CML_MATRIX2X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f
    );
    CML_Matrix3x2 B = CML_MATRIX3X2(
        7.0f, 8.0f,
        9.0f, 10.0f,
        11.0f, 12.0f
    );
    CML_Matrix2x2 out;
    CML_Matrix2x2 expected = CML_MATRIX2X2(
        58.0f, 64.0f,
        139.0f, 154.0f
    );
    cml_matrix2x3_mult_matrix3x2(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x3_mult_matrix3x3(void) {
    CML_Matrix2x3 A = CML_MATRIX2X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f
    );
    CML_Matrix3x3 B = CML_MATRIX3X3(
        7.0f, 8.0f, 9.0f,
        10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f
    );
    CML_Matrix2x3 out;
    CML_Matrix2x3 expected = CML_MATRIX2X3(
        66.0f, 72.0f, 78.0f,
        156.0f, 171.0f, 186.0f
    );
    cml_matrix2x3_mult_matrix3x3(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x3_mult_matrix3x4(void) {
    CML_Matrix2x3 A = CML_MATRIX2X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f
    );
    CML_Matrix3x4 B = CML_MATRIX3X4(
        7.0f, 8.0f, 9.0f, 10.0f,
        11.0f, 12.0f, 13.0f, 14.0f,
        15.0f, 16.0f, 17.0f, 18.0f
    );
    CML_Matrix2x4 out;
    CML_Matrix2x4 expected = CML_MATRIX2X4(
        74.0f, 80.0f, 86.0f, 92.0f,
        173.0f, 188.0f, 203.0f, 218.0f
    );
    cml_matrix2x3_mult_matrix3x4(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x3_mult_vector3(void) {
    CML_Matrix2x3 A = CML_MATRIX2X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f
    );
    CML_Vector3 v = {{7.0f, 8.0f, 9.0f}};
    CML_Vector2 out;
    CML_Vector2 expected = {{50.0f, 122.0f}};
    cml_matrix2x3_mult_vector3(&A, &v, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector2_mult_matrix2x3(void) {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Matrix2x3 A = CML_MATRIX2X3(
        3.0f, 4.0f, 5.0f,
        6.0f, 7.0f, 8.0f
    );
    CML_Vector3 out;
    CML_Vector3 expected = {{15.0f, 18.0f, 21.0f}};
    cml_vector2_mult_matrix2x3(&v, &A, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x3_transpose(void) {
    CML_Matrix2x3 A = CML_MATRIX2X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f
    );
    CML_Matrix3x2 out;
    CML_Matrix3x2 expected = CML_MATRIX3X2(
        1.0f, 4.0f,
        2.0f, 5.0f,
        3.0f, 6.0f
    );
    cml_matrix2x3_transpose(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x2_debug(&expected, &out);
    }
    return result;
}



CML_TestResult test_matrix2x4_add(void) {
    CML_Matrix2x4 A = CML_MATRIX2X4(
        1.0f, 2.0f, 3.0f, 4.0f,
        5.0f, 6.0f, 7.0f, 8.0f
    );
    CML_Matrix2x4 B = CML_MATRIX2X4(
        9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f
    );
    CML_Matrix2x4 out;
    CML_Matrix2x4 expected = CML_MATRIX2X4(
        10.0f, 12.0f, 14.0f, 16.0f,
        18.0f, 20.0f, 22.0f, 24.0f
    );
    cml_matrix2x4_add(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x4_sub(void) {
    CML_Matrix2x4 A = CML_MATRIX2X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f
    );
    CML_Matrix2x4 B = CML_MATRIX2X4(
        9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f
    );
    CML_Matrix2x4 out;
    CML_Matrix2x4 expected = CML_MATRIX2X4(
        -8.0f, -8.0f, -8.0f, -8.0f,
        -8.0f, -8.0f, -8.0f, -8.0f
    );
    cml_matrix2x4_sub(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x4_scale(void) {
    CML_Matrix2x4 A = CML_MATRIX2X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f
    );
    CML_Matrix2x4 out;
    CML_Matrix2x4 expected = CML_MATRIX2X4(
        2.0f, 4.0f, 6.0f, 8.0f, 
        10.0f, 12.0f, 14.0f, 16.0f
    );
    cml_matrix2x4_scale(&A, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x4_mult_matrix4x2(void) {
    CML_Matrix2x4 A = CML_MATRIX2X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f
    );
    CML_Matrix4x2 B = CML_MATRIX4X2(
        9.0f, 10.0f,
        11.0f, 12.0f,
        13.0f, 14.0f,
        15.0f, 16.0f
    );
    CML_Matrix2x2 out;
    CML_Matrix2x2 expected = CML_MATRIX2X2(
        130.0f, 140.0f,
        322.0f, 348.0f
    );
    cml_matrix2x4_mult_matrix4x2(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x4_mult_matrix4x3(void) {
    CML_Matrix2x4 A = CML_MATRIX2X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f
    );
    CML_Matrix4x3 B = CML_MATRIX4X3(
        9.0f, 10.0f, 11.0f,
        12.0f, 13.0f, 14.0f,
        15.0f, 16.0f, 17.0f,
        18.0f, 19.0f, 20.0f
    );
    CML_Matrix2x3 out;
    CML_Matrix2x3 expected = CML_MATRIX2X3(
        150.0f, 160.0f, 170.0f,
        366.0f, 392.0f, 418.0f
    );
    cml_matrix2x4_mult_matrix4x3(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x4_mult_matrix4x4(void) {
    CML_Matrix2x4 A = CML_MATRIX2X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f
    );
    CML_Matrix4x4 B = CML_MATRIX4X4(
        9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f,
        17.0f, 18.0f, 19.0f, 20.0f,
        21.0f, 22.0f, 23.0f, 24.0f
    );
    CML_Matrix2x4 out;
    CML_Matrix2x4 expected = CML_MATRIX2X4(
        170.0f, 180.0f, 190.0f, 200.0f,
        410.0f, 436.0f, 462.0f, 488.0f
    );
    cml_matrix2x4_mult_matrix4x4(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x4_mult_vector4(void) {
    CML_Matrix2x4 A = CML_MATRIX2X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f
    );
    CML_Vector4 v = {{9.0f, 10.0f, 11.0f, 12.0f}};
    CML_Vector2 out;
    CML_Vector2 expected = {{110.0f, 278.0f}};
    cml_matrix2x4_mult_vector4(&A, &v, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector2_mult_matrix2x4(void) {
    CML_Vector2 v = {{1.0f, 2.0f}};
    CML_Matrix2x4 A = CML_MATRIX2X4(
        3.0f, 4.0f, 5.0f, 6.0f, 
        7.0f, 8.0f, 9.0f, 10.0f
    );
    CML_Vector4 out;
    CML_Vector4 expected = {{17.0f, 20.0f, 23.0f, 26.0f}};
    cml_vector2_mult_matrix2x4(&v, &A, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x4_transpose(void) {
    CML_Matrix2x4 A = CML_MATRIX2X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f
    );
    CML_Matrix4x2 out;
    CML_Matrix4x2 expected = CML_MATRIX4X2(
        1.0f, 5.0f,
        2.0f, 6.0f,
        3.0f, 7.0f,
        4.0f, 8.0f
    );
    cml_matrix2x4_transpose(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x2_debug(&expected, &out);
    }
    return result;
}



CML_TestResult test_matrix3x2_add(void) {
    CML_Matrix3x2 A = CML_MATRIX3X2(
        1.0f, 2.0f,
        3.0f, 4.0f,
        5.0f, 6.0f
    );
    CML_Matrix3x2 B = CML_MATRIX3X2(
        7.0f, 8.0f,
        9.0f, 10.0f,
        11.0f, 12.0f
    );
    CML_Matrix3x2 out;
    CML_Matrix3x2 expected = CML_MATRIX3X2(
        8.0f, 10.0f,
        12.0f, 14.0f,
        16.0f, 18.0f
    );
    cml_matrix3x2_add(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x2_sub(void) {
    CML_Matrix3x2 A = CML_MATRIX3X2(
        1.0f, 2.0f,
        3.0f, 4.0f,
        5.0f, 6.0f
    );
    CML_Matrix3x2 B = CML_MATRIX3X2(
        7.0f, 8.0f,
        9.0f, 10.0f,
        11.0f, 12.0f
    );
    CML_Matrix3x2 out;
    CML_Matrix3x2 expected = CML_MATRIX3X2(
        -6.0f, -6.0f,
        -6.0f, -6.0f,
        -6.0f, -6.0f
    );
    cml_matrix3x2_sub(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x2_scale(void) {
    CML_Matrix3x2 A = CML_MATRIX3X2(
        1.0f, 2.0f,
        3.0f, 4.0f,
        5.0f, 6.0f
    );
    CML_Matrix3x2 out;
    CML_Matrix3x2 expected = CML_MATRIX3X2(
        2.0f, 4.0f,
        6.0f, 8.0f,
        10.0f, 12.0f
    );
    cml_matrix3x2_scale(&A, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x2_mult_matrix2x2(void) {
    CML_Matrix3x2 A = CML_MATRIX3X2(
        1.0f, 2.0f,
        3.0f, 4.0f,
        5.0f, 6.0f
    );
    CML_Matrix2x2 B = CML_MATRIX2X2(
        7.0f, 8.0f,
        9.0f, 10.0f
    );
    CML_Matrix3x2 out;
    CML_Matrix3x2 expected = CML_MATRIX3X2(
        25.0f, 28.0f,
        57.0f, 64.0f,
        89.0f, 100.0f
    );
    cml_matrix3x2_mult_matrix2x2(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x2_mult_matrix2x3(void) {
    CML_Matrix3x2 A = CML_MATRIX3X2(
        1.0f, 2.0f,
        3.0f, 4.0f,
        5.0f, 6.0f
    );
    CML_Matrix2x3 B = CML_MATRIX2X3(
        7.0f, 8.0f, 9.0f,
        10.0f, 11.0f, 12.0f
    );
    CML_Matrix3x3 out;
    CML_Matrix3x3 expected = CML_MATRIX3X3(
        27.0f, 30.0f, 33.0f,
        61.0f, 68.0f, 75.0f,
        95.0f, 106.0f, 117.0f
    );
    cml_matrix3x2_mult_matrix2x3(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x2_mult_matrix2x4(void) {
    CML_Matrix3x2 A = CML_MATRIX3X2(
        1.0f, 2.0f,
        3.0f, 4.0f,
        5.0f, 6.0f
    );
    CML_Matrix2x4 B = CML_MATRIX2X4(
        7.0f, 8.0f, 9.0f, 10.0f,
        11.0f, 12.0f, 13.0f, 14.0f
    );
    CML_Matrix3x4 out;
    CML_Matrix3x4 expected = CML_MATRIX3X4(
        29.0f, 32.0f, 35.0f, 38.0f,
        65.0f, 72.0f, 79.0f, 86.0f,
        101.0f, 112.0f, 123.0f, 134.0f
    );
    cml_matrix3x2_mult_matrix2x4(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x2_mult_vector2(void) {
    CML_Matrix3x2 A = CML_MATRIX3X2(
        1.0f, 2.0f,
        3.0f, 4.0f,
        5.0f, 6.0f
    );
    CML_Vector2 v = {{7.0f, 8.0f}};
    CML_Vector3 out;
    CML_Vector3 expected = {{23.0f, 53.0f, 83.0f}};
    cml_matrix3x2_mult_vector2(&A, &v, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector3_mult_matrix3x2(void) {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Matrix3x2 A = CML_MATRIX3X2(
        4.0f, 5.0f,
        6.0f, 7.0f,
        8.0f, 9.0f
    );
    CML_Vector2 out;
    CML_Vector2 expected = {{40.0f, 46.0f}};
    cml_vector3_mult_matrix3x2(&v, &A, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x2_transpose(void) {
    CML_Matrix3x2 A = CML_MATRIX3X2(
        1.0f, 2.0f,
        3.0f, 4.0f,
        5.0f, 6.0f
    );
    CML_Matrix2x3 out;
    CML_Matrix2x3 expected = CML_MATRIX2X3(
        1.0f, 3.0f, 5.0f,
        2.0f, 4.0f, 6.0f
    );
    cml_matrix3x2_transpose(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x3_eq(&expected, &out);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x3_debug(&expected, &out);
    }
    return result;
}



CML_TestResult test_matrix3x4_add(void) {
    CML_Matrix3x4 A = CML_MATRIX3X4(
        1.0f, 2.0f, 3.0f, 4.0f,
        5.0f, 6.0f, 7.0f, 8.0f,
        9.0f, 10.0f, 11.0f, 12.0f
    );
    CML_Matrix3x4 B = CML_MATRIX3X4(
        13.0f, 14.0f, 15.0f, 16.0f, 
        17.0f, 18.0f, 19.0f, 20.0f, 
        21.0f, 22.0f, 23.0f, 24.0f
    );
    CML_Matrix3x4 out;
    CML_Matrix3x4 expected = CML_MATRIX3X4(
        14.0f, 16.0f, 18.0f, 20.0f, 
        22.0f, 24.0f, 26.0f, 28.0f, 
        30.0f, 32.0f, 34.0f, 36.0f
    );
    cml_matrix3x4_add(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x4_sub(void) {
    CML_Matrix3x4 A = CML_MATRIX3X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f, 
        9.0f, 10.0f, 11.0f, 12.0f
    );
    CML_Matrix3x4 B = CML_MATRIX3X4(
        13.0f, 14.0f, 15.0f, 16.0f, 
        17.0f, 18.0f, 19.0f, 20.0f, 
        21.0f, 22.0f, 23.0f, 24.0f
    );
    CML_Matrix3x4 out;
    CML_Matrix3x4 expected = CML_MATRIX3X4(
        -12.0f, -12.0f, -12.0f, -12.0f, 
        -12.0f, -12.0f, -12.0f, -12.0f, 
        -12.0f, -12.0f, -12.0f, -12.0f
    );
    cml_matrix3x4_sub(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x4_scale(void) {
    CML_Matrix3x4 A = CML_MATRIX3X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f, 
        9.0f, 10.0f, 11.0f, 12.0f
    );
    CML_Matrix3x4 out;
    CML_Matrix3x4 expected = CML_MATRIX3X4(
        2.0f, 4.0f, 6.0f, 8.0f, 
        10.0f, 12.0f, 14.0f, 16.0f, 
        18.0f, 20.0f, 22.0f, 24.0f
    );
    cml_matrix3x4_scale(&A, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x4_mult_matrix4x2(void) {
    CML_Matrix3x4 A = CML_MATRIX3X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f, 
        9.0f, 10.0f, 11.0f, 12.0f
    );
    CML_Matrix4x2 B = CML_MATRIX4X2(
        13.0f, 14.0f,
        15.0f, 16.0f,
        17.0f, 18.0f,
        19.0f, 20.0f
    );
    CML_Matrix3x2 out;
    CML_Matrix3x2 expected = CML_MATRIX3X2(
        170.0f, 180.0f,
        426.0f, 452.0f,
        682.0f, 724.0f
    );
    cml_matrix3x4_mult_matrix4x2(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x4_mult_matrix4x3(void) {
    CML_Matrix3x4 A = CML_MATRIX3X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f, 
        9.0f, 10.0f, 11.0f, 12.0f
    );
    CML_Matrix4x3 B = CML_MATRIX4X3(
        13.0f, 14.0f, 15.0f,
        16.0f, 17.0f, 18.0f,
        19.0f, 20.0f, 21.0f,
        22.0f, 23.0f, 24.0f
    );
    CML_Matrix3x3 out;
    CML_Matrix3x3 expected = CML_MATRIX3X3(
        190.0f, 200.0f, 210.0f,
        470.0f, 496.0f, 522.0f,
        750.0f, 792.0f, 834.0f
    );
    cml_matrix3x4_mult_matrix4x3(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x4_mult_matrix4x4(void) {
    CML_Matrix3x4 A = CML_MATRIX3X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f, 
        9.0f, 10.0f, 11.0f, 12.0f
    );
    CML_Matrix4x4 B = CML_MATRIX4X4(
        13.0f, 14.0f, 15.0f, 16.0f,
        17.0f, 18.0f, 19.0f, 20.0f,
        21.0f, 22.0f, 23.0f, 24.0f,
        25.0f, 26.0f, 27.0f, 28.0f
    );
    CML_Matrix3x4 out;
    CML_Matrix3x4 expected = CML_MATRIX3X4(
        210.0f, 220.0f, 230.0f, 240.0f,
        514.0f, 540.0f, 566.0f, 592.0f,
        818.0f, 860.0f, 902.0f, 944.0f
    );
    cml_matrix3x4_mult_matrix4x4(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x4_mult_vector4(void) {
    CML_Matrix3x4 A = CML_MATRIX3X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f, 
        9.0f, 10.0f, 11.0f, 12.0f
    );
    CML_Vector4 v = {{13.0f, 14.0f, 15.0f, 16.0f}};
    CML_Vector3 out;
    CML_Vector3 expected = {{150.0f, 382.0f, 614.0f}};
    cml_matrix3x4_mult_vector4(&A, &v, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector3_mult_matrix3x4(void) {
    CML_Vector3 v = {{1.0f, 2.0f, 3.0f}};
    CML_Matrix3x4 A = CML_MATRIX3X4(
        4.0f, 5.0f, 6.0f, 7.0f, 
        8.0f, 9.0f, 10.0f, 11.0f, 
        12.0f, 13.0f, 14.0f, 15.0f
    );
    CML_Vector4 out;
    CML_Vector4 expected = {{56.0f, 62.0f, 68.0f, 74.0f}};
    cml_vector3_mult_matrix3x4(&v, &A, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x4_transpose(void) {
    CML_Matrix3x4 A = CML_MATRIX3X4(
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.0f, 6.0f, 7.0f, 8.0f, 
        9.0f, 10.0f, 11.0f, 12.0f
    );
    CML_Matrix4x3 out;
    CML_Matrix4x3 expected = CML_MATRIX4X3(
        1.0f, 5.0f, 9.0f,
        2.0f, 6.0f, 10.0f,
        3.0f, 7.0f, 11.0f,
        4.0f, 8.0f, 12.0f
    );
    cml_matrix3x4_transpose(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x3_debug(&expected, &out);
    }
    return result;
}



CML_TestResult test_matrix4x2_add(void) {
    CML_Matrix4x2 A = CML_MATRIX4X2(
        1.0f, 2.0f,
        3.0f, 4.0f,
        5.0f, 6.0f,
        7.0f, 8.0f
    );
    CML_Matrix4x2 B = CML_MATRIX4X2(
        9.0f, 10.0f,
        11.0f, 12.0f,
        13.0f, 14.0f,
        15.0f, 16.0f
    );
    CML_Matrix4x2 out;
    CML_Matrix4x2 expected = CML_MATRIX4X2(
        10.0f, 12.0f,
        14.0f, 16.0f,
        18.0f, 20.0f,
        22.0f, 24.0f
    );
    cml_matrix4x2_add(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x2_sub(void) {
    CML_Matrix4x2 A = CML_MATRIX4X2(
        1.0f, 2.0f,
        3.0f, 4.0f,
        5.0f, 6.0f,
        7.0f, 8.0f
    );
    CML_Matrix4x2 B = CML_MATRIX4X2(
        9.0f, 10.0f,
        11.0f, 12.0f,
        13.0f, 14.0f,
        15.0f, 16.0f
    );
    CML_Matrix4x2 out;
    CML_Matrix4x2 expected = CML_MATRIX4X2(
        -8.0f, -8.0f,
        -8.0f, -8.0f,
        -8.0f, -8.0f,
        -8.0f, -8.0f
    );
    cml_matrix4x2_sub(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x2_scale(void) {
    CML_Matrix4x2 A = CML_MATRIX4X2(
        1.0f, 2.0f,
        3.0f, 4.0f,
        5.0f, 6.0f,
        7.0f, 8.0f
    );
    CML_Matrix4x2 out;
    CML_Matrix4x2 expected = CML_MATRIX4X2(
        2.0f, 4.0f,
        6.0f, 8.0f,
        10.0f, 12.0f,
        14.0f, 16.0f
    );
    cml_matrix4x2_scale(&A, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x2_mult_matrix2x2(void) {
    CML_Matrix4x2 A = CML_MATRIX4X2(
        1.0f, 2.0f,
        3.0f, 4.0f,
        5.0f, 6.0f,
        7.0f, 8.0f
    );
    CML_Matrix2x2 B = CML_MATRIX2X2(
        9.0f, 10.0f,
        11.0f, 12.0f
    );
    CML_Matrix4x2 out;
    CML_Matrix4x2 expected = CML_MATRIX4X2(
        31.0f, 34.0f,
        71.0f, 78.0f,
        111.0f, 122.0f,
        151.0f, 166.0f
    );
    cml_matrix4x2_mult_matrix2x2(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x2_mult_matrix2x3(void) {
    CML_Matrix4x2 A = CML_MATRIX4X2(
        1.0f, 2.0f, 
        3.0f, 4.0f, 
        5.0f, 6.0f,
        7.0f, 8.0f
    );
    CML_Matrix2x3 B = CML_MATRIX2X3(
        9.0f, 10.0f, 11.0f,
        12.0f, 13.0f, 14.0f
    );
    CML_Matrix4x3 out;
    CML_Matrix4x3 expected = CML_MATRIX4X3(
        33.0f, 36.0f, 39.0f,
        75.0f, 82.0f, 89.0f,
        117.0f, 128.0f, 139.0f,
        159.0f, 174.0f, 189.0f
    );
    cml_matrix4x2_mult_matrix2x3(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x2_mult_matrix2x4(void) {
    CML_Matrix4x2 A = CML_MATRIX4X2(
        1.0f, 2.0f, 
        3.0f, 4.0f, 
        5.0f, 6.0f,
        7.0f, 8.0f
    );
    CML_Matrix2x4 B = CML_MATRIX2X4(
        9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f
    );
    CML_Matrix4x4 out;
    CML_Matrix4x4 expected = CML_MATRIX4X4(
        35.0f, 38.0f, 41.0f, 44.0f,
        79.0f, 86.0f, 93.0f, 100.0f,
        123.0f, 134.0f, 145.0f, 156.0f,
        167.0f, 182.0f, 197.0f, 212.0f
    );
    cml_matrix4x2_mult_matrix2x4(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x2_mult_vector2(void) {
    CML_Matrix4x2 A = CML_MATRIX4X2(
        1.0f, 2.0f, 
        3.0f, 4.0f, 
        5.0f, 6.0f,
        7.0f, 8.0f
    );
    CML_Vector2 v = {{9.0f, 10.0f}};
    CML_Vector4 out;
    CML_Vector4 expected = {{29.0f, 67.0f, 105.0f, 143.0f}};
    cml_matrix4x2_mult_vector2(&A, &v, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector4_mult_matrix4x2(void) {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Matrix4x2 A = CML_MATRIX4X2(
        5.0f, 6.0f, 
        7.0f, 8.0f, 
        9.0f, 10.0f,
        11.0f, 12.0f
    );
    CML_Vector2 out;
    CML_Vector2 expected = {{90.0f, 100.0f}};
    cml_vector4_mult_matrix4x2(&v, &A, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x2_transpose(void) {
    CML_Matrix4x2 A = CML_MATRIX4X2(
        1.0f, 2.0f, 
        3.0f, 4.0f, 
        5.0f, 6.0f,
        7.0f, 8.0f
    );
    CML_Matrix2x4 out;
    CML_Matrix2x4 expected = CML_MATRIX2X4(
        1.0f, 3.0f, 5.0f, 7.0f,
        2.0f, 4.0f, 6.0f, 8.0f
    );
    cml_matrix4x2_transpose(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x4_debug(&expected, &out);
    }
    return result;
}



CML_TestResult test_matrix4x3_add(void) {
    CML_Matrix4x3 A = CML_MATRIX4X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f,
        10.0f, 11.0f, 12.0f
    );
    CML_Matrix4x3 B = CML_MATRIX4X3(
        13.0f, 14.0f, 15.0f,
        16.0f, 17.0f, 18.0f, 
        19.0f, 20.0f, 21.0f,
        22.0f, 23.0f, 24.0f
    );
    CML_Matrix4x3 out;
    CML_Matrix4x3 expected = CML_MATRIX4X3(
        14.0f, 16.0f, 18.0f,
        20.0f, 22.0f, 24.0f, 
        26.0f, 28.0f, 30.0f,
        32.0f, 34.0f, 36.0f
    );
    cml_matrix4x3_add(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x3_sub(void) {
    CML_Matrix4x3 A = CML_MATRIX4X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f, 
        7.0f, 8.0f, 9.0f,
        10.0f, 11.0f, 12.0f
    );
    CML_Matrix4x3 B = CML_MATRIX4X3(
        13.0f, 14.0f, 15.0f,
        16.0f, 17.0f, 18.0f, 
        19.0f, 20.0f, 21.0f,
        22.0f, 23.0f, 24.0f
    );
    CML_Matrix4x3 out;
    CML_Matrix4x3 expected = CML_MATRIX4X3(
        -12.0f, -12.0f, -12.0f,
        -12.0f, -12.0f, -12.0f, 
        -12.0f, -12.0f, -12.0f,
        -12.0f, -12.0f, -12.0f
    );
    cml_matrix4x3_sub(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x3_scale(void) {
    CML_Matrix4x3 A = CML_MATRIX4X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f, 
        7.0f, 8.0f, 9.0f,
        10.0f, 11.0f, 12.0f
    );
    CML_Matrix4x3 out;
    CML_Matrix4x3 expected = CML_MATRIX4X3(
        2.0f, 4.0f, 6.0f,
        8.0f, 10.0f, 12.0f, 
        14.0f, 16.0f, 18.0f,
        20.0f, 22.0f, 24.0f
    );
    cml_matrix4x3_scale(&A, 2.0f, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x3_mult_matrix3x2(void) {
    CML_Matrix4x3 A = CML_MATRIX4X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f, 
        7.0f, 8.0f, 9.0f,
        10.0f, 11.0f, 12.0f
    );
    CML_Matrix3x2 B = CML_MATRIX3X2(
        13.0f, 14.0f,
        15.0f, 16.0f,
        17.0f, 18.0f
    );
    CML_Matrix4x2 out;
    CML_Matrix4x2 expected = CML_MATRIX4X2(
        94.0f, 100.0f,
        229.0f, 244.0f,
        364.0f, 388.0f,
        499.0f, 532.0f
    );
    cml_matrix4x3_mult_matrix3x2(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x3_mult_matrix3x3(void) {
    CML_Matrix4x3 A = CML_MATRIX4X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f, 
        7.0f, 8.0f, 9.0f,
        10.0f, 11.0f, 12.0f
    );
    CML_Matrix3x3 B = CML_MATRIX3X3(
        13.0f, 14.0f, 15.0f,
        16.0f, 17.0f, 18.0f,
        19.0f, 20.0f, 21.0f
    );
    CML_Matrix4x3 out;
    CML_Matrix4x3 expected = CML_MATRIX4X3(
        102.0f, 108.0f, 114.0f,
        246.0f, 261.0f, 276.0f,
        390.0f, 414.0f, 438.0f,
        534.0f, 567.0f, 600.0f
    );
    cml_matrix4x3_mult_matrix3x3(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x3_mult_matrix3x4(void) {
    CML_Matrix4x3 A = CML_MATRIX4X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f, 
        7.0f, 8.0f, 9.0f,
        10.0f, 11.0f, 12.0f
    );
    CML_Matrix3x4 B = CML_MATRIX3X4(
        13.0f, 14.0f, 15.0f, 16.0f,
        17.0f, 18.0f, 19.0f, 20.0f,
        21.0f, 22.0f, 23.0f, 24.0f
    );
    CML_Matrix4x4 out;
    CML_Matrix4x4 expected = CML_MATRIX4X4(
        110.0f, 116.0f, 122.0f, 128.0f,
        263.0f, 278.0f, 293.0f, 308.0f,
        416.0f, 440.0f, 464.0f, 488.0f,
        569.0f, 602.0f, 635.0f, 668.0f
    );
    cml_matrix4x3_mult_matrix3x4(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x3_mult_vector3(void) {
    CML_Matrix4x3 A = CML_MATRIX4X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f, 
        7.0f, 8.0f, 9.0f,
        10.0f, 11.0f, 12.0f
    );
    CML_Vector3 v = {{13.0f, 14.0f, 15.0f}};
    CML_Vector4 out;
    CML_Vector4 expected = {{86.0f, 212.0f, 338.0f, 464.0f}};
    cml_matrix4x3_mult_vector3(&A, &v, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector4_mult_matrix4x3(void) {
    CML_Vector4 v = {{1.0f, 2.0f, 3.0f, 4.0f}};
    CML_Matrix4x3 A = CML_MATRIX4X3(
        5.0f, 6.0f, 7.0f,
        8.0f, 9.0f, 10.0f, 
        11.0f, 12.0f, 13.0f,
        14.0f, 15.0f, 16.0f
    );
    CML_Vector3 out;
    CML_Vector3 expected = {{110.0f, 120.0f, 130.0f}};
    cml_vector4_mult_matrix4x3(&v, &A, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x3_transpose(void) {
    CML_Matrix4x3 A = CML_MATRIX4X3(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f, 
        7.0f, 8.0f, 9.0f,
        10.0f, 11.0f, 12.0f
    );
    CML_Matrix3x4 out;
    CML_Matrix3x4 expected = CML_MATRIX3X4(
        1.0f, 4.0f, 7.0f, 10.0f,
        2.0f, 5.0f, 8.0f, 11.0f,
        3.0f, 6.0f, 9.0f, 12.0f
    );
    cml_matrix4x3_transpose(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x4_debug(&expected, &out);
    }
    return result;
}



void cml_register_fmatrix_tests(CML_Test *registry, u32 *count) {
    cml_test_register(registry, count, test_matrix2x2_add, "test_matrix2x2_add");
    cml_test_register(registry, count, test_matrix2x2_sub, "test_matrix2x2_sub");
    cml_test_register(registry, count, test_matrix2x2_scale, "test_matrix2x2_scale");
    cml_test_register(registry, count, test_matrix2x2_mult, "test_matrix2x2_mult");
    cml_test_register(registry, count, test_matrix2x2_mult_matrix2x3, "test_matrix2x2_mult_matrix2x3");
    cml_test_register(registry, count, test_matrix2x2_mult_matrix2x4, "test_matrix2x2_mult_matrix2x4");
    cml_test_register(registry, count, test_matrix2x2_mult_vector2, "test_matrix2x2_mult_vector2");
    cml_test_register(registry, count, test_vector2_mult_matrix2x2, "test_vector2_mult_matrix2x2");
    cml_test_register(registry, count, test_matrix2x2_det, "test_matrix2x2_det");
    cml_test_register(registry, count, test_matrix2x2_inv, "test_matrix2x2_inv");
    cml_test_register(registry, count, test_matrix2x2_transpose, "test_matrix2x2_transpose");
    cml_test_register(registry, count, test_matrix2x2_trace, "test_matrix2x2_trace");
    cml_test_register(registry, count, test_matrix2x2_gen_scale, "test_matrix2x2_gen_scale");
    cml_test_register(registry, count, test_matrix2x2_gen_invscale, "test_matrix2x2_gen_invscale");
    cml_test_register(registry, count, test_matrix2x2_gen_shearx, "test_matrix2x2_gen_shearx");
    cml_test_register(registry, count, test_matrix2x2_gen_sheary, "test_matrix2x2_gen_sheary");
    cml_test_register(registry, count, test_matrix2x2_gen_invshear, "test_matrix2x2_gen_invshear");
    cml_test_register(registry, count, test_matrix2x2_genlh_rotation, "test_matrix2x2_genlh_rotation");
    cml_test_register(registry, count, test_matrix2x2_genrh_rotation, "test_matrix2x2_genrh_rotation");
    cml_test_register(registry, count, test_matrix2x2_gen_invrotation, "test_matrix2x2_gen_invrotation");

    cml_test_register(registry, count, test_matrix3x3_add, "test_matrix3x3_add");
    cml_test_register(registry, count, test_matrix3x3_sub, "test_matrix3x3_sub");
    cml_test_register(registry, count, test_matrix3x3_scale, "test_matrix3x3_scale");
    cml_test_register(registry, count, test_matrix3x3_mult, "test_matrix3x3_mult");
    cml_test_register(registry, count, test_matrix3x3_mult_matrix3x2, "test_matrix3x3_mult_matrix3x2");
    cml_test_register(registry, count, test_matrix3x3_mult_matrix3x4, "test_matrix3x3_mult_matrix3x4");
    cml_test_register(registry, count, test_matrix3x3_mult_vector3, "test_matrix3x3_mult_vector3");
    cml_test_register(registry, count, test_vector3_mult_matrix3x3, "test_vector3_mult_matrix3x3");
    cml_test_register(registry, count, test_matrix3x3_det, "test_matrix3x3_det");
    cml_test_register(registry, count, test_matrix3x3_inv, "test_matrix3x3_inv");
    cml_test_register(registry, count, test_matrix3x3_transpose, "test_matrix3x3_transpose");
    cml_test_register(registry, count, test_matrix3x3_trace, "test_matrix3x3_trace");
    cml_test_register(registry, count, test_matrix3x3_gen_scale, "test_matrix3x3_gen_scale");
    cml_test_register(registry, count, test_matrix3x3_gen_invscale, "test_matrix3x3_gen_invscale");
    cml_test_register(registry, count, test_matrix3x3_gen_shearx, "test_matrix3x3_gen_shearx");
    cml_test_register(registry, count, test_matrix3x3_gen_sheary, "test_matrix3x3_gen_sheary");
    cml_test_register(registry, count, test_matrix3x3_gen_shearz, "test_matrix3x3_gen_shearz");
    cml_test_register(registry, count, test_matrix3x3_gen_invshear, "test_matrix3x3_gen_invshear");
    cml_test_register(registry, count, test_matrix3x3_genlh_rotationx, "test_matrix3x3_genlh_rotationx");
    cml_test_register(registry, count, test_matrix3x3_genlh_rotationy, "test_matrix3x3_genlh_rotationy");
    cml_test_register(registry, count, test_matrix3x3_genlh_rotationz, "test_matrix3x3_genlh_rotationz");
    cml_test_register(registry, count, test_matrix3x3_genlh_rotation, "test_matrix3x3_genlh_rotation");
    cml_test_register(registry, count, test_matrix3x3_genrh_rotationx, "test_matrix3x3_genrh_rotationx");
    cml_test_register(registry, count, test_matrix3x3_genrh_rotationy, "test_matrix3x3_genrh_rotationy");
    cml_test_register(registry, count, test_matrix3x3_genrh_rotationz, "test_matrix3x3_genrh_rotationz");
    cml_test_register(registry, count, test_matrix3x3_genrh_rotation, "test_matrix3x3_genrh_rotation");
    cml_test_register(registry, count, test_matrix3x3_gen_invrotation, "test_matrix3x3_gen_invrotation");

    cml_test_register(registry, count, test_matrix4x4_add, "test_matrix4x4_add");
    cml_test_register(registry, count, test_matrix4x4_sub, "test_matrix4x4_sub");
    cml_test_register(registry, count, test_matrix4x4_scale, "test_matrix4x4_scale");
    cml_test_register(registry, count, test_matrix4x4_mult, "test_matrix4x4_mult");
    cml_test_register(registry, count, test_matrix4x4_mult_matrix4x2, "test_matrix4x4_mult_matrix4x2");
    cml_test_register(registry, count, test_matrix4x4_mult_matrix4x3, "test_matrix4x4_mult_matrix4x3");
    cml_test_register(registry, count, test_matrix4x4_mult_vector4, "test_matrix4x4_mult_vector4");
    cml_test_register(registry, count, test_vector4_mult_matrix4x4, "test_vector4_mult_matrix4x4");
    cml_test_register(registry, count, test_matrix4x4_det, "test_matrix4x4_det");
    cml_test_register(registry, count, test_matrix4x4_inv, "test_matrix4x4_inv");
    cml_test_register(registry, count, test_matrix4x4_transpose, "test_matrix4x4_transpose");
    cml_test_register(registry, count, test_matrix4x4_trace, "test_matrix4x4_trace");
    cml_test_register(registry, count, test_matrix4x4_gen_scale, "test_matrix4x4_gen_scale");
    cml_test_register(registry, count, test_matrix4x4_gen_invscale, "test_matrix4x4_gen_invscale");
    cml_test_register(registry, count, test_matrix4x4_gen_shearx, "test_matrix4x4_gen_shearx");
    cml_test_register(registry, count, test_matrix4x4_gen_sheary, "test_matrix4x4_gen_sheary");
    cml_test_register(registry, count, test_matrix4x4_gen_shearz, "test_matrix4x4_gen_shearz");
    cml_test_register(registry, count, test_matrix4x4_gen_invshear, "test_matrix4x4_gen_invshear");
    cml_test_register(registry, count, test_matrix4x4_gen_translation, "test_matrix4x4_gen_translation");
    cml_test_register(registry, count, test_matrix4x4_gen_invtranslation, "test_matrix4x4_gen_invtranslation");
    cml_test_register(registry, count, test_matrix4x4_genlh_rotationx, "test_matrix4x4_genlh_rotationx");
    cml_test_register(registry, count, test_matrix4x4_genlh_rotationy, "test_matrix4x4_genlh_rotationy");
    cml_test_register(registry, count, test_matrix4x4_genlh_rotationz, "test_matrix4x4_genlh_rotationz");
    cml_test_register(registry, count, test_matrix4x4_genlh_rotation, "test_matrix4x4_genlh_rotation");
    cml_test_register(registry, count, test_matrix4x4_genrh_rotationx, "test_matrix4x4_genrh_rotationx");
    cml_test_register(registry, count, test_matrix4x4_genrh_rotationy, "test_matrix4x4_genrh_rotationy");
    cml_test_register(registry, count, test_matrix4x4_genrh_rotationz, "test_matrix4x4_genrh_rotationz");
    cml_test_register(registry, count, test_matrix4x4_genrh_rotation, "test_matrix4x4_genrh_rotation");
    cml_test_register(registry, count, test_matrix4x4_gen_invrotation, "test_matrix4x4_gen_invrotation");

    cml_test_register(registry, count, test_matrix2x3_add, "test_matrix2x3_add");
    cml_test_register(registry, count, test_matrix2x3_sub, "test_matrix2x3_sub");
    cml_test_register(registry, count, test_matrix2x3_scale, "test_matrix2x3_scale");
    cml_test_register(registry, count, test_matrix2x3_mult_matrix3x2, "test_matrix2x3_mult_matrix3x2");
    cml_test_register(registry, count, test_matrix2x3_mult_matrix3x3, "test_matrix2x3_mult_matrix3x3");
    cml_test_register(registry, count, test_matrix2x3_mult_matrix3x4, "test_matrix2x3_mult_matrix3x4");
    cml_test_register(registry, count, test_matrix2x3_mult_vector3, "test_matrix2x3_mult_vector3");
    cml_test_register(registry, count, test_vector2_mult_matrix2x3, "test_vector2_mult_matrix2x3");
    cml_test_register(registry, count, test_matrix2x3_transpose, "test_matrix2x3_transpose");

    cml_test_register(registry, count, test_matrix2x4_add, "test_matrix2x4_add");
    cml_test_register(registry, count, test_matrix2x4_sub, "test_matrix2x4_sub");
    cml_test_register(registry, count, test_matrix2x4_scale, "test_matrix2x4_scale");
    cml_test_register(registry, count, test_matrix2x4_mult_matrix4x2, "test_matrix2x4_mult_matrix4x2");
    cml_test_register(registry, count, test_matrix2x4_mult_matrix4x3, "test_matrix2x4_mult_matrix4x3");
    cml_test_register(registry, count, test_matrix2x4_mult_matrix4x4, "test_matrix2x4_mult_matrix4x4");
    cml_test_register(registry, count, test_matrix2x4_mult_vector4, "test_matrix2x4_mult_vector4");
    cml_test_register(registry, count, test_vector2_mult_matrix2x4, "test_vector2_mult_matrix2x4");
    cml_test_register(registry, count, test_matrix2x4_transpose, "test_matrix2x4_transpose");

    cml_test_register(registry, count, test_matrix3x2_add, "test_matrix3x2_add");
    cml_test_register(registry, count, test_matrix3x2_sub, "test_matrix3x2_sub");
    cml_test_register(registry, count, test_matrix3x2_scale, "test_matrix3x2_scale");
    cml_test_register(registry, count, test_matrix3x2_mult_matrix2x2, "test_matrix3x2_mult_matrix2x2");
    cml_test_register(registry, count, test_matrix3x2_mult_matrix2x3, "test_matrix3x2_mult_matrix2x3");
    cml_test_register(registry, count, test_matrix3x2_mult_matrix2x4, "test_matrix3x2_mult_matrix2x4");
    cml_test_register(registry, count, test_matrix3x2_mult_vector2, "test_matrix3x2_mult_vector2");
    cml_test_register(registry, count, test_vector3_mult_matrix3x2, "test_vector3_mult_matrix3x2");
    cml_test_register(registry, count, test_matrix3x2_transpose, "test_matrix3x2_transpose");

    cml_test_register(registry, count, test_matrix3x4_add, "test_matrix3x4_add");
    cml_test_register(registry, count, test_matrix3x4_sub, "test_matrix3x4_sub");
    cml_test_register(registry, count, test_matrix3x4_scale, "test_matrix3x4_scale");
    cml_test_register(registry, count, test_matrix3x4_mult_matrix4x2, "test_matrix3x4_mult_matrix4x2");
    cml_test_register(registry, count, test_matrix3x4_mult_matrix4x3, "test_matrix3x4_mult_matrix4x3");
    cml_test_register(registry, count, test_matrix3x4_mult_matrix4x4, "test_matrix3x4_mult_matrix4x4");
    cml_test_register(registry, count, test_matrix3x4_mult_vector4, "test_matrix3x4_mult_vector4");
    cml_test_register(registry, count, test_vector3_mult_matrix3x4, "test_vector3_mult_matrix3x4");
    cml_test_register(registry, count, test_matrix3x4_transpose, "test_matrix3x4_transpose");

    cml_test_register(registry, count, test_matrix4x2_add, "test_matrix4x2_add");
    cml_test_register(registry, count, test_matrix4x2_sub, "test_matrix4x2_sub");
    cml_test_register(registry, count, test_matrix4x2_scale, "test_matrix4x2_scale");
    cml_test_register(registry, count, test_matrix4x2_mult_matrix2x2, "test_matrix4x2_mult_matrix2x2");
    cml_test_register(registry, count, test_matrix4x2_mult_matrix2x3, "test_matrix4x2_mult_matrix2x3");
    cml_test_register(registry, count, test_matrix4x2_mult_matrix2x4, "test_matrix4x2_mult_matrix2x4");
    cml_test_register(registry, count, test_matrix4x2_mult_vector2, "test_matrix4x2_mult_vector2");
    cml_test_register(registry, count, test_vector4_mult_matrix4x2, "test_vector4_mult_matrix4x2");
    cml_test_register(registry, count, test_matrix4x2_transpose, "test_matrix4x2_transpose");

    cml_test_register(registry, count, test_matrix4x3_add, "test_matrix4x3_add");
    cml_test_register(registry, count, test_matrix4x3_sub, "test_matrix4x3_sub");
    cml_test_register(registry, count, test_matrix4x3_scale, "test_matrix4x3_scale");
    cml_test_register(registry, count, test_matrix4x3_mult_matrix3x2, "test_matrix4x3_mult_matrix3x2");
    cml_test_register(registry, count, test_matrix4x3_mult_matrix3x3, "test_matrix4x3_mult_matrix3x3");
    cml_test_register(registry, count, test_matrix4x3_mult_matrix3x4, "test_matrix4x3_mult_matrix3x4");
    cml_test_register(registry, count, test_matrix4x3_mult_vector3, "test_matrix4x3_mult_vector3");
    cml_test_register(registry, count, test_vector4_mult_matrix4x3, "test_vector4_mult_matrix4x3");
    cml_test_register(registry, count, test_matrix4x3_transpose, "test_matrix4x3_transpose");
}
