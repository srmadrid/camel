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



int main(void) {
    b8 testing = false;
    if (testing) {
        u32 count = 0;
        u32 expectedCount = 400;
        CML_Test *registry = malloc(sizeof(CML_Test)*expectedCount);

        // cml_test_init(&registry, &count, expectedCount);
        // Better create the registry on the stack, so we 
        // don't have to free it.

        cml_register_all_tests(registry, &count);

        cml_run_tests(registry, count);

        free(registry);
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
        struct timeval start, end;

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
        /*
        f64 test[] = {1,2,-3,4,5,6,7,8,9,1,1,3,4,5,6,7};
        CML_Matrix A;
        cml_matrix_init(&a, 4, 4, CML_F64, &A);
        u32 i = 0;
        for (u32 r = 0; r < 4; r++) {
            for (u32 c = 0; c < 4; c++) {
                cml_matrix_set(&test[i], r, c, &A);
                i++;
            }
        }
        printf("A = \n");
        cml_matrix_print(NULL, &A);
        // Permutation
        u32 parr[] = {0,0,1,2,3,3,3,3};
        CML_Matrix p;
        cml_matrix_init(&a, 8, 1, CML_U32, &p);
        for (u32 r = 0; r < 8; r++) {
            cml_matrix_set(&parr[r], r, 0, &p);
        }
        printf("\np = \n");
        cml_matrix_print(NULL, &p);
        u32 qarr[] = {1,2};
        CML_Matrix q;
        cml_matrix_init(&a, 2, 1, CML_U32, &q);
        for (u32 r = 0; r < 2; r++) {
            cml_matrix_set(&qarr[r], r, 0, &q);
        }
        printf("\nq = \n");
        cml_matrix_print(NULL, &q);

        CML_Matrix B;
        cml_matrix_select(&a, &A, &p, &q, &B);
        printf("\nA(p, q) = B = \n");
        cml_matrix_print(NULL, &B);
        cml_matrix_destroy(&B);

        cml_matrix_init(&a, 4, 4, CML_F64, &B);
        f64 number = 1.0;
        for (u32 r = 0; r < 4; r++) {
            for (u32 c = 0; c < 4; c++) {
                cml_matrix_set(&number, r, c, &B);
                number += 1.0;
                i++;
            }
        }
        printf("\nB = \n");
        cml_matrix_print(NULL, &B);

        CML_Matrix C;
        gettimeofday(&start, NULL);
        cml_matrix_mult(&a, &A, &B, &C);
        gettimeofday(&end, NULL);
        printf("\nC = A*B = \n");
        cml_matrix_print(NULL, &C);
        printf("Mult time: %fs\n", end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec)/1000000.0);
        cml_matrix_destroy(&C);
        gettimeofday(&start, NULL);
        cml_matrix_mult(&a, &A, &B, &C);
        gettimeofday(&end, NULL);
        printf("Mult time redone: %fs\n", end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec)/1000000.0);

        CML_Matrix scalar;
        cml_matrix_init(&a, 1, 1, CML_F64, &scalar);
        f64 snumber = 10;
        cml_matrix_set(&snumber, 0, 0, &scalar);
        printf("\nscalar = \n");
        cml_matrix_print(NULL, &scalar);
        CML_Matrix D;
        cml_matrix_divew(&a, &A, &scalar, &D);
        printf("\nD = A/scalar: \n");
        cml_matrix_print(NULL, &D);

        cml_matrix_destroy(&p);
        cml_matrix_init(&a, 9, 1, CML_F64, &p);
        for (u32 r = 0; r < 9; r++) {
            f64 number = r + 1;
            cml_matrix_set(&number, r, 0, &p);
        }
        printf("\np = \n");
        cml_matrix_print(NULL, &p);
        f64 qarr2[] = {1.0, 2.0, 3.0, 3.0, 3.0};
        cml_matrix_destroy(&q);
        cml_matrix_init(&a, 1, 5, CML_F64, &q);
        for (u32 r = 0; r < 5; r++) {
            cml_matrix_set(&qarr2[r], 0, r, &q);
        }
        printf("\nq = \n");
        cml_matrix_print(NULL, &q);
        CML_Matrix P;
        gettimeofday(&start, NULL);
        cml_matrix_mult(&a, &p, &q, &P);
        gettimeofday(&end, NULL);
        printf("\nP = pq\n");
        cml_matrix_print(NULL, &P);
        printf("Mult time: %fs\n", end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec)/1000000.0);

        CML_Matrix p2;
        cml_matrix_init(&a, 1, 9, CML_F64, &p2);
        for (u32 r = 0; r < 9; r++) {
            f64 number = r + 1;
            cml_matrix_set(&number, 0, r, &p2);
        }
        printf("\np2 = \n");
        cml_matrix_print(NULL, &p2);
        CML_Matrix dot;
        gettimeofday(&start, NULL);
        cml_matrix_mult(&a, &p2, &p, &dot);
        gettimeofday(&end, NULL);
        printf("\ndot = p2*p\n");
        cml_matrix_print(NULL, &dot);
        printf("Mult time: %fs\n", end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec)/1000000.0);

        CML_Matrix p3;
        cml_matrix_transpose(&a, &p2, &p3);
        printf("\np3 = p2^T = \n");
        cml_matrix_print(NULL, &p3);


        CML_Matrix big1, big2;
        cml_matrix_init(&a, 500, 1000, CML_F64, &big1);
        cml_matrix_init(&a, 1000, 500, CML_F64, &big2);
        printf("\nDim(big1) = %dx%d\n", big1.rows, big1.columns);
        printf("\nDim(big2) = %dx%d\n", big2.rows, big2.columns);
        CML_Matrix big3;
        gettimeofday(&start, NULL);
        cml_matrix_mult(&a, &big1, &big2, &big3);
        gettimeofday(&end, NULL);
        printf("\nbig3 = big1*big2 \n");
        printf("\nDim(big3) = %dx%d\n", big3.rows, big3.columns);
        printf("Mult time: %fs\n", end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec)/1000000.0);
        cml_matrix_destroy(&big3);
        gettimeofday(&start, NULL);
        cml_matrix_mult(&a, &big2, &big1, &big3);
        gettimeofday(&end, NULL);
        printf("\nbig3 = big2*big1 \n");
        printf("\nDim(big3) = %dx%d\n", big3.rows, big3.columns);
        printf("Mult time: %fs\n", end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec)/1000000.0);
        cml_matrix_destroy(&big3);
        cml_matrix_destroy(&big2);
        cml_matrix_destroy(&big1);

        CML_Matrix big8, big9, big10;
        cml_matrix_init(&a, 1000, 1000, CML_F64, &big8);
        cml_matrix_init(&a, 1000, 1000, CML_F64, &big9);
        printf("\nDim(big8) = %dx%d\n", big8.rows, big8.columns);
        printf("\nDim(big9) = %dx%d\n", big9.rows, big9.columns);
        gettimeofday(&start, NULL);
        cml_matrix_mult(&a, &big8, &big9, &big10);
        gettimeofday(&end, NULL);
        printf("\nbig10 = big8*big9 \n");
        printf("\nDim(big10) = %dx%d\n", big10.rows, big10.columns);
        printf("Mult time: %fs\n", end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec)/1000000.0);
        cml_matrix_destroy(&big8);
        cml_matrix_destroy(&big9);
        cml_matrix_destroy(&big10);
        */

        CML_Matrix big5, big6, big7;
        cml_matrix_init(&a, 50000, 5000, CML_F64, &big5);
        cml_matrix_init(&a, 50000, 5000, CML_F64, &big6);
        cml_matrix_init(&a, 50000, 5000, CML_F64, &big7);
        printf("\nbig7 = big5 + big6 (50000x5000)\n");
        gettimeofday(&start, NULL);
        cml_matrix_add(NULL, &big5, &big6, &big7);
        gettimeofday(&end, NULL);
        printf("Add time: %fs\n", end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec)/1000000.0);
        cml_matrix_destroy(&big5);
        cml_matrix_destroy(&big6);
        cml_matrix_destroy(&big7);

        /*
        printf("\nA = \n");
        cml_matrix_print(NULL, &A);
        printf("\nB = \n");
        cml_matrix_print(NULL, &B);
        cml_matrix_add(NULL, &A, &B, &C);
        printf("\nC = A+B = \n");
        cml_matrix_print(&a, &C);


        cml_matrix_destroy(&A);
        cml_matrix_destroy(&p);
        cml_matrix_destroy(&p2);
        cml_matrix_destroy(&p3);
        cml_matrix_destroy(&q);
        cml_matrix_destroy(&B);
        cml_matrix_destroy(&C);
        cml_matrix_destroy(&D);
        cml_matrix_destroy(&P);
        cml_matrix_destroy(&scalar);
        cml_matrix_destroy(&dot);
        */

        /*
        FILE *f;
        f = fopen("perf/core/matrix/cml_matrix_mult(oneScalar)(f64).csv", "w+");
        fprintf(f,"i,j,parallel,nonparallel,opcount,sum\n");

        u32 dims = 300;
        u32 averaging = 100;
        f64 fveraging = averaging;
        u32 iters = dims*dims;
        u32 iter = 1;
        for (u32 i = 1; i <= dims; i++) {
            for (u32 j = 1; j <= dims; j++) {
                printf("\rProgress: %f%%", (f64)iter/iters * 100);
                fflush(stdout);
                f64 parallel = 0;
                f64 nonparallel = 0;
                for (u32 l = 0; l < averaging; l++) {
                    CML_Matrix A, B, C;
                    cml_matrix_init(&a, 1, 1, CML_F64, &A);
                    cml_matrix_init(&a, i, j, CML_F64, &B);
                    gettimeofday(&start, NULL);
                    cml_matrix_mult(true, NULL, &A, &B, &C);
                    gettimeofday(&end, NULL);
                    parallel += end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec)/1000000.0;
                    cml_matrix_destroy(&A);
                    cml_matrix_destroy(&B);
                    cml_matrix_destroy(&C);

                    cml_matrix_init(&a, 1, 1, CML_F64, &A);
                    cml_matrix_init(&a, i, j, CML_F64, &B);
                    gettimeofday(&start, NULL);
                    cml_matrix_mult(false, NULL, &A, &B, &C);
                    gettimeofday(&end, NULL);
                    nonparallel += end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec)/1000000.0;
                    cml_matrix_destroy(&A);
                    cml_matrix_destroy(&B);
                    cml_matrix_destroy(&C);
                }
                parallel /= fveraging;
                nonparallel /= fveraging;
                fprintf(f,"%d,%d,%f,%f,%d,%d\n", i, j, parallel, nonparallel, i*j, i+j);
                iter++;
            }
        }
        printf("\n");
        fclose(f);
        */
        /*
        CML_Matrix A, B, C;
        cml_matrix_init(&a, 1, 1, CML_F64, &A);
        cml_matrix_init(&a, 5000, 5000, CML_F64, &B);
        gettimeofday(&start, NULL);
        cml_matrix_mult(true, NULL, &A, &B, &C);
        gettimeofday(&end, NULL);
        printf("Mult time: %fs\n", end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec)/1000000.0);
        cml_matrix_destroy(&C);
        gettimeofday(&start, NULL);
        cml_matrix_mult(false, NULL, &A, &B, &C);
        gettimeofday(&end, NULL);
        printf("Mult time: %fs\n", end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec)/1000000.0);

        cml_matrix_destroy(&A);
        cml_matrix_destroy(&B);
        cml_matrix_destroy(&C);
        */
    }

    return 0;
}
