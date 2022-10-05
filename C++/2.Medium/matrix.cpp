// g++ skeleton.cpp && ./a.out
#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// UNCOMMENT LINE BELOW TO DEBUG WITH SMALLER SAMPLE
#define DEBUG

#ifdef DEBUG
#define N 8
#else
#define N 2048
#endif

float A[N * N];
float B[N * N];
float C[N * N];
float keyvals[N * N];

uint64_t nanos() {
    struct timespec start;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    return (uint64_t)start.tv_sec * 1000000000 + (uint64_t)start.tv_nsec;
}

void matrix_multiplication() {

    // A[r][c];
    // A[r * ROW_WIDTH + c];


}

int main() {
#ifdef DEBUG
    for (int i = 0; i < N * N; i++) A[i] = i;
    for (int i = 0; i < N * N; i++) B[i] = i;
#else
    FILE *f = fopen("newdata.txt", "rb");
    if (f == NULL) {
        printf("Error: Download newdata.txt file!\n");
        return -1;
    }
    fread(A, 1, sizeof(float) * N * N, f);
    fread(B, 1, sizeof(float) * N * N, f);
    fread(keyvals, 1, sizeof(float) * N * N, f);
    fclose(f);
#endif

    // Make sure C matrix is cleared
    memset(C, 0, N * N * sizeof(float));

    // Run it
    uint64_t start = nanos();
    matrix_multiplication();
    uint64_t end = nanos();

// Verify results
#ifdef DEBUG
    for (int i = 0; i < N * N; i++) {
        if (i % N == 0 && i != 0) printf("\n");
        printf("%f ", C[i]);
    }
    printf("\n");
#else
    for (int k = 0; k < N * N; k++) {
        if (fabsf(C[k] - keyvals[k]) > 1e-3) {
            printf("MISMATCH AT %d, %f != %f\n", k, C[k], keyvals[k]);
            return -1;
        }
    }
    printf("SUCCESS: Results verified\n");
#endif

    // How fast is your code?
    double gflop = (2.0 * N * N * N) * 1e-9;
    double s = (end - start) * 1e-9;
    printf("%f GFLOP/S -- %.2f ms\n", gflop / s, s * 1e3);
    return 0;
}