/**
 * @file mtest.c
 * 
 * @brief Main test file for the project. This file runs all tests for all modules
 *        in the project.
 *
 * @author Sergio Madrid
 * @date 12/12/2023
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include <sys/time.h>

#include "../include/camel.h"


void cml_register_algebra_tests(CML_Test *registry, u32 *count);
void cml_register_core_tests(CML_Test *registry, u32 *count);


void cml_register_all_tests(CML_Test *registry, u32 *count) {
    cml_register_algebra_tests(registry, count);

    cml_register_core_tests(registry, count);
}



int main() {
    b8 testing = false;
    if (testing) {
        u32 count = 0;
        u32 expectedCount = 400;
        CML_Test registry[expectedCount];

        // cml_test_init(&registry, &count, expectedCount);
        // Better create the registry on the stack, so we 
        // don't have to free it.

        cml_register_all_tests(registry, &count);

        cml_run_tests(registry, count);
    }

    b8 profiling = false;
    if (profiling && testing) {
        printf("\n\n");
    }
    if (profiling) {
        // Time profiling
        u32 iterations = 1000000;
        u32 outIterations = 1000;
        printf("Time profiling:\n");
        printf("Function being profiled: cml_vector4_add\n");
        printf("Total iterations: %d\n", iterations*outIterations);

        struct timeval start, end;
        CML_Vector4 v = CML_VECTOR4_ONE;
        CML_Vector4 w = CML_VECTOR4_ONE;
        double totalElapsed = 0.0;
        double elapsed = 0.0;
        for (u32 i = 0; i < outIterations; i++) {
            gettimeofday(&start, NULL);
            for (u32 j = 0; j < iterations; j++) {
                CML_Vector4 u;
                cml_vector4_add(&v, &w, &u);
            }
            gettimeofday(&end, NULL);
            elapsed = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec) / 1000000.0);
            totalElapsed += elapsed;
        }
        elapsed = totalElapsed / outIterations;
        printf("Elapsed time: %fs\n", totalElapsed);
        printf("Average elapsed time per %u iterations: %fs\n", iterations, elapsed);
        printf("Average elapsed time per iteration: %.12fs\n", elapsed / iterations);
        printf("Average iterations per second: %f\n", 1.0 / (elapsed / iterations));
    }

    b8 individualTesting = true;
    if (individualTesting) {
        CML_Allocator a = CML_ALLOCATOR_DEFAULT;

        /*CML_DArray darray;
        CML_String expression;
        cml_string_init(&a, "867x + y^(sin(z)) / (291(xlog(y + z)))", &expression);
        cml_expression_lex(&a, &expression, &darray);

        printf("Expression: %s\n", expression.data);
        for (u32 i = 0; i < darray.length; ++i) {
            CML_ExpressionToken *token = cml_darray_get(i, &darray);
            //CML_ExpressionToken token = ((CML_ExpressionToken*)darray.data)[i];
            printf("[CharType: %i, String: %s]\n", token->charType, token->characters.data);
            //printf("[CharType: %i, String: %s]\n", token.charType, token.characters.data);
        }

        cml_string_destroy(&expression);
        cml_darray_destroy(&darray); */

        f64 test[] = {1,2,-3,4,5,6,7,8,9,1,1,3,4,5,6,7};
        CML_Matrix A;
        cml_matrix_init(&a, 4, 4, true, CML_F64, &A);
        u32 i = 0;
        for (u32 r = 0; r < 4; r++) {
            for (u32 c = 0; c < 4; c++) {
                cml_matrix_set(&test[i], r, c, &A);
                i++;
            }
        }
        printf("A = \n");
        cml_matrix_print(&A);

        /* Permutation
        u32 parr[] = {0,0,1,2,3,3,3,3};
        CML_Matrix p;
        cml_matrix_init(&a, 8, 1, true, CML_U32, &p);
        for (u32 r = 0; r < 8; r++) {
            cml_matrix_set(&parr[r], r, 0, &p);
        }
        printf("\np = \n");
        cml_matrix_print(&p);
        u32 qarr[] = {1,2};
        CML_Matrix q;
        cml_matrix_init(&a, 2, 1, true, CML_U32, &q);
        for (u32 r = 0; r < 2; r++) {
            cml_matrix_set(&qarr[r], r, 0, &q);
        }
        printf("\nq = \n");
        cml_matrix_print(&q);

        CML_Matrix B;
        cml_matrix_select(NULL, &A, &p, &q, true, &B);
        printf("\nA(p, q) = B = \n");
        cml_matrix_print(&B); */

        CML_Matrix B;
        cml_matrix_init(&a, 4, 4, true, CML_F64, &B);
        f64 number = 1.65;
        for (u32 r = 0; r < 4; r++) {
            for (u32 c = 0; c < 4; c++) {
                cml_matrix_set(&number, r, c, &B);
                number *= 1.5;
                i++;
            }
        }
        printf("\nB = \n");
        cml_matrix_print(&B);

        CML_Matrix C;
        cml_matrix_add(NULL, &A, &B, true, &C);
        printf("\nC = A+B = \n");
        cml_matrix_print(&C);

        cml_matrix_destroy(&A);
        //cml_matrix_destroy(&p);
        //cml_matrix_destroy(&q);
        cml_matrix_destroy(&B);
        cml_matrix_destroy(&C);
    }

    return 0;
}
