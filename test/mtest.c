/******************************************************************************
 * Filename: mtest.c
 * 
 * Description:
 *      Main test file for the project. This file runs all tests for all modules
 *      in the project.
 *
 * Author: Sergio Madrid
 * Created on: 12/12/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/


#include <sys/time.h>

#include "../include/camel.h"


void cml_register_algebra_tests(CML_Test *registry, u32 *count);
void cml_register_core_tests(CML_Test *registry, u32 *count);


void cml_register_all_tests(CML_Test *registry, u32 *count) {
    cml_register_algebra_tests(registry, count);

    //cml_register_core_tests(registry, count);
}



int main() {
    u32 count = 0;
    u32 expectedCount = 300;
    CML_Test registry[expectedCount];

    // cml_test_init(&registry, &count, expectedCount);
    // Better create the registry on the stack, so we 
    // don't have to free it.

    cml_register_all_tests(registry, &count);

    cml_run_tests(registry, count);


    int profiling = 1;
    if (profiling) {
        // Time profiling
        u32 iterations = 1000000;
        u32 outIterations = 1000;
        printf("\n\nTime profiling:\n");
        printf("Function being profiled: cml_matrix4x4_mult\n");
        printf("Total iterations: %d\n", iterations*outIterations);

        struct timeval start, end;
        CML_Matrix4x4 A = {
            1.0, 2.0, 3.0, 4.0,
            5.0, 6.0, 7.0, 8.0,
            9.0, 10.0, 11.0, 12.0,
            13.0, 14.0, 15.0, 16.0
        };
        CML_Matrix4x4 B = {
            1.0, 2.0, 3.0, 4.0,
            5.0, 6.0, 7.0, 8.0,
            9.0, 10.0, 11.0, 12.0,
            13.0, 14.0, 15.0, 16.0
        };
        CML_Matrix4x4 C = {0};
        double totalElapsed = 0.0;
        double elapsed = 0.0;
        for (u32 i = 0; i < outIterations; i++) {
            gettimeofday(&start, NULL);
            for (u32 i = 0; i < iterations; i++) {
                cml_matrix4x4_mult(&A, &B, &C);
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

    return 0;
}