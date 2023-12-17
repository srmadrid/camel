/******************************************************************************
 * Filename: tvector.c
 * 
 * Description:
 *      Test file for the vector module.
 *
 * Author: Sergio Madrid
 * Created on: 16/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include "../../../include/camel.h"


CML_TestResult test_matrix2x2_add() {
    CML_Matrix2x2 A = {
        1.0, 2.0,
        3.0, 4.0
    };
    CML_Matrix2x2 B = {
        5.0, 6.0,
        7.0, 8.0
    };
    CML_Matrix2x2 out = CML_MATRIX2X2_ZERO;
    CML_Matrix2x2 expected = {
        6.0, 8.0,
        10.0, 12.0
    };
    cml_matrix2x2_add(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x2_sub() {
    CML_Matrix2x2 A = {
        1.0, 2.0,
        3.0, 4.0
    };
    CML_Matrix2x2 B = {
        5.0, 6.0,
        7.0, 8.0
    };
    CML_Matrix2x2 out = CML_MATRIX2X2_ZERO;
    CML_Matrix2x2 expected = {
        -4.0, -4.0,
        -4.0, -4.0
    };
    cml_matrix2x2_sub(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x2_scale() {
    CML_Matrix2x2 A = {
        1.0, 2.0,
        3.0, 4.0
    };
    CML_Matrix2x2 out = CML_MATRIX2X2_ZERO;
    CML_Matrix2x2 expected = {
        2.0, 4.0,
        6.0, 8.0
    };
    cml_matrix2x2_scale(&A, 2.0, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x2_mult() {
    CML_Matrix2x2 A = {
        1.0, 2.0,
        3.0, 4.0
    };
    CML_Matrix2x2 B = {
        5.0, 6.0,
        7.0, 8.0
    };
    CML_Matrix2x2 out = CML_MATRIX2X2_ZERO;
    CML_Matrix2x2 expected = {
        19.0, 22.0,
        43.0, 50.0
    };
    cml_matrix2x2_mult(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x2_mult_vector2() {
    CML_Matrix2x2 A = {
        1.0, 2.0,
        3.0, 4.0
    };
    CML_Vector2 v = {5.0, 6.0};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {17.0, 39.0};
    cml_matrix2x2_mult_vector2(&A, &v, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector2_mult_matrix2x2() {
    CML_Vector2 v = {1.0, 2.0};
    CML_Matrix2x2 A = {
        3.0, 4.0,
        5.0, 6.0
    };
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {13.0, 16.0};
    cml_vector2_mult_matrix2x2(&v, &A, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x2_det() {
    CML_Matrix2x2 A = {
        1.0, 2.0,
        3.0, 4.0
    };
    f64 expected = -2.0;
    f64 result = cml_matrix2x2_det(&A);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f64_debug(expected, result);
    }
    return test;
}


CML_TestResult test_matrix2x2_inv() {
    CML_Matrix2x2 A = {
        1.0, 2.0,
        3.0, 4.0
    };
    CML_Matrix2x2 out = CML_MATRIX2X2_ZERO;
    CML_Matrix2x2 expected = {
        -2.0, 1.0,
        1.5, -0.5
    };
    cml_matrix2x2_inv(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x2_transpose() {
    CML_Matrix2x2 A = {
        1.0, 2.0,
        3.0, 4.0
    };
    CML_Matrix2x2 out = CML_MATRIX2X2_ZERO;
    CML_Matrix2x2 expected = {
        1.0, 3.0,
        2.0, 4.0
    };
    cml_matrix2x2_transpose(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x2_trace() {
    CML_Matrix2x2 A = {
        1.0, 2.0,
        3.0, 4.0
    };
    f64 expected = 5.0;
    f64 result = cml_matrix2x2_trace(&A);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f64_debug(expected, result);
    }
    return test;
}



CML_TestResult test_matrix3x3_add() {
    CML_Matrix3x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0,
        7.0, 8.0, 9.0
    };
    CML_Matrix3x3 B = {
        10.0, 11.0, 12.0,
        13.0, 14.0, 15.0,
        16.0, 17.0, 18.0
    };
    CML_Matrix3x3 out = CML_MATRIX3X3_ZERO;
    CML_Matrix3x3 expected = {
        11.0, 13.0, 15.0,
        17.0, 19.0, 21.0,
        23.0, 25.0, 27.0
    };
    cml_matrix3x3_add(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x3_sub() {
    CML_Matrix3x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0,
        7.0, 8.0, 9.0
    };
    CML_Matrix3x3 B = {
        10.0, 11.0, 12.0,
        13.0, 14.0, 15.0,
        16.0, 17.0, 18.0
    };
    CML_Matrix3x3 out = CML_MATRIX3X3_ZERO;
    CML_Matrix3x3 expected = {
        -9.0, -9.0, -9.0,
        -9.0, -9.0, -9.0,
        -9.0, -9.0, -9.0
    };
    cml_matrix3x3_sub(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x3_scale() {
    CML_Matrix3x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0,
        7.0, 8.0, 9.0
    };
    CML_Matrix3x3 out = CML_MATRIX3X3_ZERO;
    CML_Matrix3x3 expected = {
        2.0, 4.0, 6.0,
        8.0, 10.0, 12.0,
        14.0, 16.0, 18.0
    };
    cml_matrix3x3_scale(&A, 2.0, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x3_mult() {
    CML_Matrix3x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0,
        7.0, 8.0, 9.0
    };
    CML_Matrix3x3 B = {
        10.0, 11.0, 12.0,
        13.0, 14.0, 15.0,
        16.0, 17.0, 18.0
    };
    CML_Matrix3x3 out = CML_MATRIX3X3_ZERO;
    CML_Matrix3x3 expected = {
        84.0, 90.0, 96.0,
        201.0, 216.0, 231.0,
        318.0, 342.0, 366.0
    };
    cml_matrix3x3_mult(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x3_mult_vector3() {
    CML_Matrix3x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0,
        7.0, 8.0, 9.0
    };
    CML_Vector3 v = {10.0, 11.0, 12.0};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {68.0, 167.0, 266.0};
    cml_matrix3x3_mult_vector3(&A, &v, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector3_mult_matrix3x3() {
    CML_Vector3 v = {1.0, 2.0, 3.0};
    CML_Matrix3x3 A = {
        4.0, 5.0, 6.0,
        7.0, 8.0, 9.0,
        10.0, 11.0, 12.0
    };
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {48.0, 54.0, 60.0};
    cml_vector3_mult_matrix3x3(&v, &A, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x3_det() {
    CML_Matrix3x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0,
        7.0, 8.0, 9.0
    };
    f64 expected = 0.0;
    f64 result = cml_matrix3x3_det(&A);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f64_debug(expected, result);
    }
    return test;
}


CML_TestResult test_matrix3x3_inv() {
    CML_Matrix3x3 A = {
        1.0, 2.0, 3.0,
        0.0, 1.0, 4.0,
        5.0, 6.0, 0.0
    };
    CML_Matrix3x3 out = CML_MATRIX3X3_ZERO;
    CML_Matrix3x3 expected = {
        -24.0, 18.0, 5.0,
        20.0, -15.0, -4.0,
        -5.0, 4.0, 1.0
    };
    cml_matrix3x3_inv(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x3_transpose() {
    CML_Matrix3x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0,
        7.0, 8.0, 9.0
    };
    CML_Matrix3x3 out = CML_MATRIX3X3_ZERO;
    CML_Matrix3x3 expected = {
        1.0, 4.0, 7.0,
        2.0, 5.0, 8.0,
        3.0, 6.0, 9.0
    };
    cml_matrix3x3_transpose(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x3_trace() {
    CML_Matrix3x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0,
        7.0, 8.0, 9.0
    };
    f64 expected = 15.0;
    f64 result = cml_matrix3x3_trace(&A);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f64_debug(expected, result);
    }
    return test;
}



CML_TestResult test_matrix4x4_add() {
   CML_Matrix4x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0, 
        9.0, 10.0, 11.0, 12.0,
        13.0, 14.0, 15.0, 16.0
    };
    CML_Matrix4x4 B = {
        17.0, 18.0, 19.0, 20.0,
        21.0, 22.0, 23.0, 24.0,
        25.0, 26.0, 27.0, 28.0,
        29.0, 30.0, 31.0, 32.0
    };
    CML_Matrix4x4 out = CML_MATRIX3X3_ZERO;
    CML_Matrix4x4 expected = {
        18.0, 20.0, 22.0, 24.0,
        26.0, 28.0, 30.0, 32.0,
        34.0, 36.0, 38.0, 40.0,
        42.0, 44.0, 46.0, 48.0
    };
    cml_matrix4x4_add(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x4_sub() {
    CML_Matrix4x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0, 
        9.0, 10.0, 11.0, 12.0,
        13.0, 14.0, 15.0, 16.0
    };
    CML_Matrix4x4 B = {
        17.0, 18.0, 19.0, 20.0,
        21.0, 22.0, 23.0, 24.0,
        25.0, 26.0, 27.0, 28.0,
        29.0, 30.0, 31.0, 32.0
    };
    CML_Matrix4x4 out = CML_MATRIX3X3_ZERO;
    CML_Matrix4x4 expected = {
        -16.0, -16.0, -16.0, -16.0,
        -16.0, -16.0, -16.0, -16.0,
        -16.0, -16.0, -16.0, -16.0,
        -16.0, -16.0, -16.0, -16.0
    };
    cml_matrix4x4_sub(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x4_scale() {
    CML_Matrix4x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0, 
        9.0, 10.0, 11.0, 12.0,
        13.0, 14.0, 15.0, 16.0
    };
    CML_Matrix4x4 out = CML_MATRIX4X4_ZERO;
    CML_Matrix4x4 expected = {
        2.0, 4.0, 6.0, 8.0, 
        10.0, 12.0, 14.0, 16.0, 
        18.0, 20.0, 22.0, 24.0,
        26.0, 28.0, 30.0, 32.0
    };
    cml_matrix4x4_scale(&A, 2.0, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x4_mult() {
    CML_Matrix4x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0, 
        9.0, 10.0, 11.0, 12.0,
        13.0, 14.0, 15.0, 16.0
    };
    CML_Matrix4x4 B = {
        17.0, 18.0, 19.0, 20.0,
        21.0, 22.0, 23.0, 24.0,
        25.0, 26.0, 27.0, 28.0,
        29.0, 30.0, 31.0, 32.0
    };
    CML_Matrix4x4 out = CML_MATRIX4X4_ZERO;
    CML_Matrix4x4 expected = {
        250.0, 260.0, 270.0, 280.0,
        618.0, 644.0, 670.0, 696.0,
        986.0, 1028.0, 1070.0, 1112.0,
        1354.0, 1412.0, 1470.0, 1528.0
    };
    cml_matrix4x4_mult(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x4_mult_vector4() {
    CML_Matrix4x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0, 
        9.0, 10.0, 11.0, 12.0,
        13.0, 14.0, 15.0, 16.0
    };
    CML_Vector4 v = {17.0, 18.0, 19.0, 20.0};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {190.0, 486.0, 782.0, 1078.0};
    cml_matrix4x4_mult_vector4(&A, &v, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector4_mult_matrix4x4() {
    CML_Vector4 v = {1.0, 2.0, 3.0, 4.0};
    CML_Matrix4x4 A = {
        5.0, 6.0, 7.0, 8.0, 
        9.0, 10.0, 11.0, 12.0, 
        13.0, 14.0, 15.0, 16.0,
        17.0, 18.0, 19.0, 20.0
    };
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {130.0, 140.0, 150.0, 160.0};
    cml_vector4_mult_matrix4x4(&v, &A, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x4_det() {
    CML_Matrix4x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0, 
        9.0, 10.0, 11.0, 12.0,
        13.0, 14.0, 15.0, 16.0
    };
    f64 expected = 0.0;
    f64 result = cml_matrix4x4_det(&A);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f64_debug(expected, result);
    }
    return test;
}


CML_TestResult test_matrix4x4_inv() {
    CML_Matrix4x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        0.0, 1.0, 5.0, 6.0, 
        7.0, 8.0, 0.0, 9.0,
        10.0, 11.0, 12.0, 0.0
    };
    CML_Matrix4x4 out = CML_MATRIX4X4_ZERO;
    CML_Matrix4x4 expected = {
        -2.8918918918918918922, 1.3963963963963963967, 0.35435435435435435445, 0.1411411411411411411,
        2.864864864864864865, -1.4954954954954954955, -0.27627627627627627631, -0.09309309309309309308,
        -0.21621621621621621625, 0.20720720720720720723, -0.04204204204204204203, 0.051051051051051051048,
        -0.29729729729729729729, 0.24324324324324324324, 0.081081081081081081081, -0.027027027027027027027
    };
    cml_matrix4x4_inv(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x4_transpose() {
    CML_Matrix4x4 A = {
        1.0, 2.0, 3.0, 4.0,
        5.0, 6.0, 7.0, 8.0,
        9.0, 10.0, 11.0, 12.0,
        13.0, 14.0, 15.0, 16.0
    };
    CML_Matrix4x4 out = CML_MATRIX3X3_ZERO;
    CML_Matrix4x4 expected = {
        1.0, 5.0, 9.0, 13.0,
        2.0, 6.0, 10.0, 14.0,
        3.0, 7.0, 11.0, 15.0,
        4.0, 8.0, 12.0, 16.0
    };
    cml_matrix4x4_transpose(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x4_trace() {
    CML_Matrix4x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0, 
        9.0, 10.0, 11.0, 12.0,
        13.0, 14.0, 15.0, 16.0
    };
    f64 expected = 34.0;
    f64 result = cml_matrix4x4_trace(&A);
    CML_TestResult test;
    test.passed = ((result - expected) <= CML_EPSILON)? CML_TRUE : CML_FALSE;
    if (!test.passed) {
        test.debugMessage = cml_f64_debug(expected, result);
    }
    return test;
}



CML_TestResult test_matrix2x3_add() {
    CML_Matrix2x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0
    };
    CML_Matrix2x3 B = {
        7.0, 8.0, 9.0,
        10.0, 11.0, 12.0
    };
    CML_Matrix2x3 out = CML_MATRIX2X3_ZERO;
    CML_Matrix2x3 expected = {
        8.0, 10.0, 12.0,
        14.0, 16.0, 18.0
    };
    cml_matrix2x3_add(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x3_sub() {
    CML_Matrix2x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0
    };
    CML_Matrix2x3 B = {
        7.0, 8.0, 9.0,
        10.0, 11.0, 12.0
    };
    CML_Matrix2x3 out = CML_MATRIX2X3_ZERO;
    CML_Matrix2x3 expected = {
        -6.0, -6.0, -6.0,
        -6.0, -6.0, -6.0
    };
    cml_matrix2x3_sub(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x3_scale() {
    CML_Matrix2x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0
    };
    CML_Matrix2x3 out = CML_MATRIX2X3_ZERO;
    CML_Matrix2x3 expected = {
        2.0, 4.0, 6.0,
        8.0, 10.0, 12.0
    };
    cml_matrix2x3_scale(&A, 2.0, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x3_mult_matrix3x2() {
    CML_Matrix2x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0
    };
    CML_Matrix3x2 B = {
        7.0, 8.0,
        9.0, 10.0,
        11.0, 12.0
    };
    CML_Matrix2x2 out = CML_MATRIX2X2_ZERO;
    CML_Matrix2x2 expected = {
        58.0, 64.0,
        139.0, 154.0
    };
    cml_matrix2x3_mult_matrix3x2(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x3_mult_matrix3x3() {
    CML_Matrix2x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0
    };
    CML_Matrix3x3 B = {
        7.0, 8.0, 9.0,
        10.0, 11.0, 12.0,
        13.0, 14.0, 15.0
    };
    CML_Matrix2x3 out = CML_MATRIX2X3_ZERO;
    CML_Matrix2x3 expected = {
        66.0, 72.0, 78.0,
        156.0, 171.0, 186.0
    };
    cml_matrix2x3_mult_matrix3x3(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x3_mult_matrix3x4() {
    CML_Matrix2x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0
    };
    CML_Matrix3x4 B = {
        7.0, 8.0, 9.0, 10.0,
        11.0, 12.0, 13.0, 14.0,
        15.0, 16.0, 17.0, 18.0
    };
    CML_Matrix2x4 out = CML_MATRIX2X4_ZERO;
    CML_Matrix2x4 expected = {
        74.0, 80.0, 86.0, 92.0,
        173.0, 188.0, 203.0, 218.0
    };
    cml_matrix2x3_mult_matrix3x4(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x3_mult_vector3() {
    CML_Matrix2x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0
    };
    CML_Vector3 v = {7.0, 8.0, 9.0};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {50.0, 122.0};
    cml_matrix2x3_mult_vector3(&A, &v, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector2_mult_matrix2x3() {
    CML_Vector2 v = {1.0, 2.0};
    CML_Matrix2x3 A = {
        3.0, 4.0, 5.0,
        6.0, 7.0, 8.0
    };
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {15.0, 18.0, 21.0};
    cml_vector2_mult_matrix2x3(&v, &A, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x3_transpose() {
    CML_Matrix2x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0
    };
    CML_Matrix3x2 out = CML_MATRIX3X2_ZERO;
    CML_Matrix3x2 expected = {
        1.0, 4.0,
        2.0, 5.0,
        3.0, 6.0
    };
    cml_matrix2x3_transpose(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x2_debug(&expected, &out);
    }
    return result;
}



CML_TestResult test_matrix2x4_add() {
    CML_Matrix2x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0
    };
    CML_Matrix2x4 B = {
        9.0, 10.0, 11.0, 12.0,
        13.0, 14.0, 15.0, 16.0
    };
    CML_Matrix2x4 out = CML_MATRIX2X4_ZERO;
    CML_Matrix2x4 expected = {
        10.0, 12.0, 14.0, 16.0,
        18.0, 20.0, 22.0, 24.0
    };
    cml_matrix2x4_add(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x4_sub() {
    CML_Matrix2x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0
    };
    CML_Matrix2x4 B = {
        9.0, 10.0, 11.0, 12.0,
        13.0, 14.0, 15.0, 16.0
    };
    CML_Matrix2x4 out = CML_MATRIX2X4_ZERO;
    CML_Matrix2x4 expected = {
        -8.0, -8.0, -8.0, -8.0,
        -8.0, -8.0, -8.0, -8.0
    };
    cml_matrix2x4_sub(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x4_scale() {
    CML_Matrix2x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0
    };
    CML_Matrix2x4 out = CML_MATRIX2X4_ZERO;
    CML_Matrix2x4 expected = {
        2.0, 4.0, 6.0, 8.0, 
        10.0, 12.0, 14.0, 16.0
    };
    cml_matrix2x4_scale(&A, 2.0, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x4_mult_matrix4x2() {
    CML_Matrix2x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0
    };
    CML_Matrix4x2 B = {
        9.0, 10.0,
        11.0, 12.0,
        13.0, 14.0,
        15.0, 16.0
    };
    CML_Matrix2x2 out = CML_MATRIX2X2_ZERO;
    CML_Matrix2x2 expected = {
        130.0, 140.0,
        322.0, 348.0
    };
    cml_matrix2x4_mult_matrix4x2(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x4_mult_matrix4x3() {
    CML_Matrix2x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0
    };
    CML_Matrix4x3 B = {
        9.0, 10.0, 11.0,
        12.0, 13.0, 14.0,
        15.0, 16.0, 17.0,
        18.0, 19.0, 20.0
    };
    CML_Matrix2x3 out = CML_MATRIX2X3_ZERO;
    CML_Matrix2x3 expected = {
        150.0, 160.0, 170.0,
        366.0, 392.0, 418.0
    };
    cml_matrix2x4_mult_matrix4x3(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x4_mult_matrix4x4() {
    CML_Matrix2x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0
    };
    CML_Matrix4x4 B = {
        9.0, 10.0, 11.0, 12.0,
        13.0, 14.0, 15.0, 16.0,
        17.0, 18.0, 19.0, 20.0,
        21.0, 22.0, 23.0, 24.0
    };
    CML_Matrix2x4 out = CML_MATRIX2X4_ZERO;
    CML_Matrix2x4 expected = {
        170.0, 180.0, 190.0, 200.0,
        410.0, 436.0, 462.0, 488.0
    };
    cml_matrix2x4_mult_matrix4x4(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x4_mult_vector4() {
    CML_Matrix2x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0
    };
    CML_Vector4 v = {9.0, 10.0, 11.0, 12.0};
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {110.0, 278.0};
    cml_matrix2x4_mult_vector4(&A, &v, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector2_mult_matrix2x4() {
    CML_Vector2 v = {1.0, 2.0};
    CML_Matrix2x4 A = {
        3.0, 4.0, 5.0, 6.0, 
        7.0, 8.0, 9.0, 10.0
    };
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {17.0, 20.0, 23.0, 26.0};
    cml_vector2_mult_matrix2x4(&v, &A, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix2x4_transpose() {
    CML_Matrix2x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0
    };
    CML_Matrix4x2 out = CML_MATRIX4X2_ZERO;
    CML_Matrix4x2 expected = {
        1.0, 5.0,
        2.0, 6.0,
        3.0, 7.0,
        4.0, 8.0
    };
    cml_matrix2x4_transpose(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x2_debug(&expected, &out);
    }
    return result;
}



CML_TestResult test_matrix3x2_add() {
    CML_Matrix3x2 A = {
        1.0, 2.0,
        3.0, 4.0,
        5.0, 6.0
    };
    CML_Matrix3x2 B = {
        7.0, 8.0,
        9.0, 10.0,
        11.0, 12.0
    };
    CML_Matrix3x2 out = CML_MATRIX3X2_ZERO;
    CML_Matrix3x2 expected = {
        8.0, 10.0,
        12.0, 14.0,
        16.0, 18.0
    };
    cml_matrix3x2_add(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x2_sub() {
    CML_Matrix3x2 A = {
        1.0, 2.0,
        3.0, 4.0,
        5.0, 6.0
    };
    CML_Matrix3x2 B = {
        7.0, 8.0,
        9.0, 10.0,
        11.0, 12.0
    };
    CML_Matrix3x2 out = CML_MATRIX3X2_ZERO;
    CML_Matrix3x2 expected = {
        -6.0, -6.0,
        -6.0, -6.0,
        -6.0, -6.0
    };
    cml_matrix3x2_sub(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x2_scale() {
    CML_Matrix3x2 A = {
        1.0, 2.0,
        3.0, 4.0,
        5.0, 6.0
    };
    CML_Matrix3x2 out = CML_MATRIX3X2_ZERO;
    CML_Matrix3x2 expected = {
        2.0, 4.0,
        6.0, 8.0,
        10.0, 12.0
    };
    cml_matrix3x2_scale(&A, 2.0, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x2_mult_matrix2x2() {
    CML_Matrix3x2 A = {
        1.0, 2.0,
        3.0, 4.0,
        5.0, 6.0
    };
    CML_Matrix2x2 B = {
        7.0, 8.0,
        9.0, 10.0
    };
    CML_Matrix3x2 out = CML_MATRIX3X2_ZERO;
    CML_Matrix3x2 expected = {
        25.0, 28.0,
        57.0, 64.0,
        89.0, 100.0
    };
    cml_matrix3x2_mult_matrix2x2(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x2_mult_matrix2x3() {
    CML_Matrix3x2 A = {
        1.0, 2.0,
        3.0, 4.0,
        5.0, 6.0
    };
    CML_Matrix2x3 B = {
        7.0, 8.0, 9.0,
        10.0, 11.0, 12.0
    };
    CML_Matrix3x3 out = CML_MATRIX3X3_ZERO;
    CML_Matrix3x3 expected = {
        27.0, 30.0, 33.0,
        61.0, 68.0, 75.0,
        95.0, 106.0, 117.0
    };
    cml_matrix3x2_mult_matrix2x3(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x2_mult_matrix2x4() {
    CML_Matrix3x2 A = {
        1.0, 2.0,
        3.0, 4.0,
        5.0, 6.0
    };
    CML_Matrix2x4 B = {
        7.0, 8.0, 9.0, 10.0,
        11.0, 12.0, 13.0, 14.0
    };
    CML_Matrix3x4 out = CML_MATRIX3X4_ZERO;
    CML_Matrix3x4 expected = {
        29.0, 32.0, 35.0, 38.0,
        65.0, 72.0, 79.0, 86.0,
        101.0, 112.0, 123.0, 134.0
    };
    cml_matrix3x2_mult_matrix2x4(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x2_mult_vector2() {
    CML_Matrix3x2 A = {
        1.0, 2.0,
        3.0, 4.0,
        5.0, 6.0
    };
    CML_Vector2 v = {7.0, 8.0};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {23.0, 53.0, 83.0};
    cml_matrix3x2_mult_vector2(&A, &v, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector3_mult_matrix3x2() {
    CML_Vector3 v = {1.0, 2.0, 3.0};
    CML_Matrix3x2 A = {
        4.0, 5.0,
        6.0, 7.0,
        8.0, 9.0
    };
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {40.0, 46.0};
    cml_vector3_mult_matrix3x2(&v, &A, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x2_transpose() {
    CML_Matrix3x2 A = {
        1.0, 2.0,
        3.0, 4.0,
        5.0, 6.0
    };
    CML_Matrix2x3 out = CML_MATRIX2X3_ZERO;
    CML_Matrix3x2 expected = {
        1.0, 3.0, 5.0,
        2.0, 4.0, 6.0
    };
    cml_matrix3x2_transpose(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x3_eq(&expected, &out);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x3_debug(&expected, &out);
    }
    return result;
}



CML_TestResult test_matrix3x4_add() {
    CML_Matrix3x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0, 
        9.0, 10.0, 11.0, 12.0
    };
    CML_Matrix3x4 B = {
        13.0, 14.0, 15.0, 16.0, 
        17.0, 18.0, 19.0, 20.0, 
        21.0, 22.0, 23.0, 24.0
    };
    CML_Matrix3x4 out = CML_MATRIX3X4_ZERO;
    CML_Matrix3x4 expected = {
        14.0, 16.0, 18.0, 20.0, 
        22.0, 24.0, 26.0, 28.0, 
        30.0, 32.0, 34.0, 36.0
    };
    cml_matrix3x4_add(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x4_sub() {
    CML_Matrix3x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0, 
        9.0, 10.0, 11.0, 12.0
    };
    CML_Matrix3x4 B = {
        13.0, 14.0, 15.0, 16.0, 
        17.0, 18.0, 19.0, 20.0, 
        21.0, 22.0, 23.0, 24.0
    };
    CML_Matrix3x4 out = CML_MATRIX3X4_ZERO;
    CML_Matrix3x4 expected = {
        -12.0, -12.0, -12.0, -12.0, 
        -12.0, -12.0, -12.0, -12.0, 
        -12.0, -12.0, -12.0, -12.0
    };
    cml_matrix3x4_sub(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x4_scale() {
    CML_Matrix3x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0, 
        9.0, 10.0, 11.0, 12.0
    };
    CML_Matrix3x4 out = CML_MATRIX3X4_ZERO;
    CML_Matrix3x4 expected = {
        2.0, 4.0, 6.0, 8.0, 
        10.0, 12.0, 14.0, 16.0, 
        18.0, 20.0, 22.0, 24.0
    };
    cml_matrix3x4_scale(&A, 2.0, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x4_mult_matrix4x2() {
    CML_Matrix3x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0, 
        9.0, 10.0, 11.0, 12.0
    };
    CML_Matrix4x2 B = {
        13.0, 14.0,
        15.0, 16.0,
        17.0, 18.0,
        19.0, 20.0
    };
    CML_Matrix3x2 out = CML_MATRIX3X2_ZERO;
    CML_Matrix3x2 expected = {
        170.0, 180.0,
        426.0, 452.0,
        682.0, 724.0
    };
    cml_matrix3x4_mult_matrix4x2(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x4_mult_matrix4x3() {
    CML_Matrix3x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0, 
        9.0, 10.0, 11.0, 12.0
    };
    CML_Matrix4x3 B = {
        13.0, 14.0, 15.0,
        16.0, 17.0, 18.0,
        19.0, 20.0, 21.0,
        22.0, 23.0, 24.0
    };
    CML_Matrix3x3 out = CML_MATRIX3X3_ZERO;
    CML_Matrix3x3 expected = {
        190.0, 200.0, 210.0,
        470.0, 496.0, 522.0,
        750.0, 792.0, 834.0
    };
    cml_matrix3x4_mult_matrix4x3(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x4_mult_matrix4x4() {
    CML_Matrix3x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0, 
        9.0, 10.0, 11.0, 12.0
    };
    CML_Matrix4x4 B = {
        13.0, 14.0, 15.0, 16.0,
        17.0, 18.0, 19.0, 20.0,
        21.0, 22.0, 23.0, 24.0,
        25.0, 26.0, 27.0, 28.0
    };
    CML_Matrix3x4 out = CML_MATRIX3X4_ZERO;
    CML_Matrix3x4 expected = {
        210.0, 220.0, 230.0, 240.0,
        514.0, 540.0, 566.0, 592.0,
        818.0, 860.0, 902.0, 944.0
    };
    cml_matrix3x4_mult_matrix4x4(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x4_mult_vector4() {
    CML_Matrix3x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0, 
        9.0, 10.0, 11.0, 12.0
    };
    CML_Vector4 v = {13.0, 14.0, 15.0, 16.0};
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {150.0, 382.0, 614.0};
    cml_matrix3x4_mult_vector4(&A, &v, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector3_mult_matrix3x4() {
    CML_Vector3 v = {1.0, 2.0, 3.0};
    CML_Matrix3x4 A = {
        4.0, 5.0, 6.0, 7.0, 
        8.0, 9.0, 10.0, 11.0, 
        12.0, 13.0, 14.0, 15.0
    };
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {56.0, 62.0, 68.0, 74.0};
    cml_vector3_mult_matrix3x4(&v, &A, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix3x4_transpose() {
    CML_Matrix3x4 A = {
        1.0, 2.0, 3.0, 4.0, 
        5.0, 6.0, 7.0, 8.0, 
        9.0, 10.0, 11.0, 12.0
    };
    CML_Matrix4x3 out = CML_MATRIX4X3_ZERO;
    CML_Matrix3x4 expected = {
        1.0, 5.0, 9.0,
        2.0, 6.0, 10.0,
        3.0, 7.0, 11.0,
        4.0, 8.0, 12.0
    };
    cml_matrix3x4_transpose(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x3_debug(&expected, &out);
    }
    return result;
}



CML_TestResult test_matrix4x2_add() {
    CML_Matrix4x2 A = {
        1.0, 2.0,
        3.0, 4.0,
        5.0, 6.0,
        7.0, 8.0
    };
    CML_Matrix4x2 B = {
        9.0, 10.0,
        11.0, 12.0,
        13.0, 14.0,
        15.0, 16.0
    };
    CML_Matrix4x2 out = CML_MATRIX4X2_ZERO;
    CML_Matrix4x2 expected = {
        10.0, 12.0,
        14.0, 16.0,
        18.0, 20.0,
        22.0, 24.0
    };
    cml_matrix4x2_add(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x2_sub() {
    CML_Matrix4x2 A = {
        1.0, 2.0,
        3.0, 4.0,
        5.0, 6.0,
        7.0, 8.0
    };
    CML_Matrix4x2 B = {
        9.0, 10.0,
        11.0, 12.0,
        13.0, 14.0,
        15.0, 16.0
    };
    CML_Matrix4x2 out = CML_MATRIX4X2_ZERO;
    CML_Matrix4x2 expected = {
        -8.0, -8.0,
        -8.0, -8.0,
        -8.0, -8.0,
        -8.0, -8.0
    };
    cml_matrix4x2_sub(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x2_scale() {
    CML_Matrix4x2 A = {
        1.0, 2.0,
        3.0, 4.0,
        5.0, 6.0,
        7.0, 8.0
    };
    CML_Matrix4x2 out = CML_MATRIX4X2_ZERO;
    CML_Matrix4x2 expected = {
        2.0, 4.0,
        6.0, 8.0,
        10.0, 12.0,
        14.0, 16.0
    };
    cml_matrix4x2_scale(&A, 2.0, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x2_mult_matrix2x2() {
    CML_Matrix4x2 A = {
        1.0, 2.0,
        3.0, 4.0,
        5.0, 6.0,
        7.0, 8.0
    };
    CML_Matrix2x2 B = {
        9.0, 10.0,
        11.0, 12.0
    };
    CML_Matrix4x2 out = CML_MATRIX4X2_ZERO;
    CML_Matrix4x2 expected = {
        31.0, 34.0,
        71.0, 78.0,
        111.0, 122.0,
        151.0, 166.0
    };
    cml_matrix4x2_mult_matrix2x2(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x2_mult_matrix2x3() {
    CML_Matrix4x2 A = {
        1.0, 2.0, 
        3.0, 4.0, 
        5.0, 6.0,
        7.0, 8.0
    };
    CML_Matrix2x3 B = {
        9.0, 10.0, 11.0,
        12.0, 13.0, 14.0
    };
    CML_Matrix4x3 out = CML_MATRIX4X3_ZERO;
    CML_Matrix4x3 expected = {
        33.0, 36.0, 39.0,
        75.0, 82.0, 89.0,
        117.0, 128.0, 139.0,
        159.0, 174.0, 189.0
    };
    cml_matrix4x2_mult_matrix2x3(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x2_mult_matrix2x4() {
    CML_Matrix4x2 A = {
        1.0, 2.0, 
        3.0, 4.0, 
        5.0, 6.0,
        7.0, 8.0
    };
    CML_Matrix2x4 B = {
        9.0, 10.0, 11.0, 12.0,
        13.0, 14.0, 15.0, 16.0
    };
    CML_Matrix4x4 out = CML_MATRIX4X4_ZERO;
    CML_Matrix4x4 expected = {
        35.0, 38.0, 41.0, 44.0,
        79.0, 86.0, 93.0, 100.0,
        123.0, 134.0, 145.0, 156.0,
        167.0, 182.0, 197.0, 212.0
    };
    cml_matrix4x2_mult_matrix2x4(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x2_mult_vector2() {
    CML_Matrix4x2 A = {
        1.0, 2.0, 
        3.0, 4.0, 
        5.0, 6.0,
        7.0, 8.0
    };
    CML_Vector2 v = {9.0, 10.0};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {29.0, 67.0, 105.0, 143.0};
    cml_matrix4x2_mult_vector2(&A, &v, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector4_mult_matrix4x2() {
    CML_Vector4 v = {1.0, 2.0, 3.0, 4.0};
    CML_Matrix4x2 A = {
        5.0, 6.0, 
        7.0, 8.0, 
        9.0, 10.0,
        11.0, 12.0
    };
    CML_Vector2 out = CML_VECTOR2_ZERO;
    CML_Vector2 expected = {90.0, 100.0};
    cml_vector4_mult_matrix4x2(&v, &A, &out);
    CML_TestResult result;
    result.passed = cml_vector2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x2_transpose() {
    CML_Matrix4x2 A = {
        1.0, 2.0, 
        3.0, 4.0, 
        5.0, 6.0,
        7.0, 8.0
    };
    CML_Matrix2x4 out = CML_MATRIX2X4_ZERO;
    CML_Matrix4x2 expected = {
        1.0, 3.0, 5.0, 7.0,
        2.0, 4.0, 6.0, 8.0
    };
    cml_matrix4x2_transpose(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix2x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix2x4_debug(&expected, &out);
    }
    return result;
}



CML_TestResult test_matrix4x3_add() {
    CML_Matrix4x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0, 
        7.0, 8.0, 9.0,
        10.0, 11.0, 12.0
    };
    CML_Matrix4x3 B = {
        13.0, 14.0, 15.0,
        16.0, 17.0, 18.0, 
        19.0, 20.0, 21.0,
        22.0, 23.0, 24.0
    };
    CML_Matrix4x3 out = CML_MATRIX4X3_ZERO;
    CML_Matrix4x3 expected = {
        14.0, 16.0, 18.0,
        20.0, 22.0, 24.0, 
        26.0, 28.0, 30.0,
        32.0, 34.0, 36.0
    };
    cml_matrix4x3_add(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x3_sub() {
    CML_Matrix4x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0, 
        7.0, 8.0, 9.0,
        10.0, 11.0, 12.0
    };
    CML_Matrix4x3 B = {
        13.0, 14.0, 15.0,
        16.0, 17.0, 18.0, 
        19.0, 20.0, 21.0,
        22.0, 23.0, 24.0
    };
    CML_Matrix4x3 out = CML_MATRIX4X3_ZERO;
    CML_Matrix4x3 expected = {
        -12.0, -12.0, -12.0,
        -12.0, -12.0, -12.0, 
        -12.0, -12.0, -12.0,
        -12.0, -12.0, -12.0
    };
    cml_matrix4x3_sub(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x3_scale() {
    CML_Matrix4x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0, 
        7.0, 8.0, 9.0,
        10.0, 11.0, 12.0
    };
    CML_Matrix4x3 out = CML_MATRIX4X3_ZERO;
    CML_Matrix4x3 expected = {
        2.0, 4.0, 6.0,
        8.0, 10.0, 12.0, 
        14.0, 16.0, 18.0,
        20.0, 22.0, 24.0
    };
    cml_matrix4x3_scale(&A, 2.0, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x3_mult_matrix3x2() {
    CML_Matrix4x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0, 
        7.0, 8.0, 9.0,
        10.0, 11.0, 12.0
    };
    CML_Matrix3x2 B = {
        13.0, 14.0,
        15.0, 16.0,
        17.0, 18.0
    };
    CML_Matrix4x2 out = CML_MATRIX4X2_ZERO;
    CML_Matrix4x2 expected = {
        94.0, 100.0,
        229.0, 244.0,
        364.0, 388.0,
        499.0, 532.0
    };
    cml_matrix4x3_mult_matrix3x2(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x2_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x2_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x3_mult_matrix3x3() {
    CML_Matrix4x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0, 
        7.0, 8.0, 9.0,
        10.0, 11.0, 12.0
    };
    CML_Matrix3x3 B = {
        13.0, 14.0, 15.0,
        16.0, 17.0, 18.0,
        19.0, 20.0, 21.0
    };
    CML_Matrix4x3 out = CML_MATRIX4X3_ZERO;
    CML_Matrix4x3 expected = {
        102.0, 108.0, 114.0,
        246.0, 261.0, 276.0,
        390.0, 414.0, 438.0,
        534.0, 567.0, 600.0
    };
    cml_matrix4x3_mult_matrix3x3(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x3_mult_matrix3x4() {
    CML_Matrix4x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0, 
        7.0, 8.0, 9.0,
        10.0, 11.0, 12.0
    };
    CML_Matrix3x4 B = {
        13.0, 14.0, 15.0, 16.0,
        17.0, 18.0, 19.0, 20.0,
        21.0, 22.0, 23.0, 24.0
    };
    CML_Matrix4x4 out = CML_MATRIX4X4_ZERO;
    CML_Matrix4x4 expected = {
        110.0, 116.0, 122.0, 128.0,
        263.0, 278.0, 293.0, 308.0,
        416.0, 440.0, 464.0, 488.0,
        569.0, 602.0, 635.0, 668.0
    };
    cml_matrix4x3_mult_matrix3x4(&A, &B, &out);
    CML_TestResult result;
    result.passed = cml_matrix4x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix4x4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x3_mult_vector3() {
    CML_Matrix4x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0, 
        7.0, 8.0, 9.0,
        10.0, 11.0, 12.0
    };
    CML_Vector3 v = {13.0, 14.0, 15.0};
    CML_Vector4 out = CML_VECTOR4_ZERO;
    CML_Vector4 expected = {86.0, 212.0, 338.0, 464.0};
    cml_matrix4x3_mult_vector3(&A, &v, &out);
    CML_TestResult result;
    result.passed = cml_vector4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector4_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_vector4_mult_matrix4x3() {
    CML_Vector4 v = {1.0, 2.0, 3.0, 4.0};
    CML_Matrix4x3 A = {
        5.0, 6.0, 7.0,
        8.0, 9.0, 10.0, 
        11.0, 12.0, 13.0,
        14.0, 15.0, 16.0
    };
    CML_Vector3 out = CML_VECTOR3_ZERO;
    CML_Vector3 expected = {110.0, 120.0, 130.0};
    cml_vector4_mult_matrix4x3(&v, &A, &out);
    CML_TestResult result;
    result.passed = cml_vector3_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_vector3_debug(&expected, &out);
    }
    return result;
}


CML_TestResult test_matrix4x3_transpose() {
    CML_Matrix4x3 A = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0, 
        7.0, 8.0, 9.0,
        10.0, 11.0, 12.0
    };
    CML_Matrix3x4 out = CML_MATRIX3X4_ZERO;
    CML_Matrix3x4 expected = {
        1.0, 4.0, 7.0, 10.0,
        2.0, 5.0, 8.0, 11.0,
        3.0, 6.0, 9.0, 12.0
    };
    cml_matrix4x3_transpose(&A, &out);
    CML_TestResult result;
    result.passed = cml_matrix3x4_eq(&out, &expected);
    if (!result.passed) {
        result.debugMessage = cml_matrix3x4_debug(&expected, &out);
    }
    return result;
}



void cml_register_matrix_tests(CML_Test *registry, u32 *count) {
    cml_test_register(registry, count, test_matrix2x2_add, "test_matrix2x2_add");
    cml_test_register(registry, count, test_matrix2x2_sub, "test_matrix2x2_sub");
    cml_test_register(registry, count, test_matrix2x2_scale, "test_matrix2x2_scale");
    cml_test_register(registry, count, test_matrix2x2_mult, "test_matrix2x2_mult");
    cml_test_register(registry, count, test_matrix2x2_mult_vector2, "test_matrix2x2_mult_vector2");
    cml_test_register(registry, count, test_vector2_mult_matrix2x2, "test_vector2_mult_matrix2x2");
    cml_test_register(registry, count, test_matrix2x2_det, "test_matrix2x2_det");
    cml_test_register(registry, count, test_matrix2x2_inv, "test_matrix2x2_inv");
    cml_test_register(registry, count, test_matrix2x2_transpose, "test_matrix2x2_transpose");
    cml_test_register(registry, count, test_matrix2x2_trace, "test_matrix2x2_trace");

    cml_test_register(registry, count, test_matrix3x3_add, "test_matrix3x3_add");
    cml_test_register(registry, count, test_matrix3x3_sub, "test_matrix3x3_sub");
    cml_test_register(registry, count, test_matrix3x3_scale, "test_matrix3x3_scale");
    cml_test_register(registry, count, test_matrix3x3_mult, "test_matrix3x3_mult");
    cml_test_register(registry, count, test_matrix3x3_mult_vector3, "test_matrix3x3_mult_vector3");
    cml_test_register(registry, count, test_vector3_mult_matrix3x3, "test_vector3_mult_matrix3x3");
    cml_test_register(registry, count, test_matrix3x3_det, "test_matrix3x3_det");
    cml_test_register(registry, count, test_matrix3x3_inv, "test_matrix3x3_inv");
    cml_test_register(registry, count, test_matrix3x3_transpose, "test_matrix3x3_transpose");
    cml_test_register(registry, count, test_matrix3x3_trace, "test_matrix3x3_trace");

    cml_test_register(registry, count, test_matrix4x4_add, "test_matrix4x4_add");
    cml_test_register(registry, count, test_matrix4x4_sub, "test_matrix4x4_sub");
    cml_test_register(registry, count, test_matrix4x4_scale, "test_matrix4x4_scale");
    cml_test_register(registry, count, test_matrix4x4_mult, "test_matrix4x4_mult");
    cml_test_register(registry, count, test_matrix4x4_mult_vector4, "test_matrix4x4_mult_vector4");
    cml_test_register(registry, count, test_vector4_mult_matrix4x4, "test_vector4_mult_matrix4x4");
    cml_test_register(registry, count, test_matrix4x4_det, "test_matrix4x4_det");
    cml_test_register(registry, count, test_matrix4x4_inv, "test_matrix4x4_inv");
    cml_test_register(registry, count, test_matrix4x4_transpose, "test_matrix4x4_transpose");
    cml_test_register(registry, count, test_matrix4x4_trace, "test_matrix4x4_trace");

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
