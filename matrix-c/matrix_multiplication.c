#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void multiply_matrices(int *a, int *b, int *result, int size) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i * size + j] = 0;
            for (int k = 0; k < size; k++) {
                result[i * size + j] += a[i * size + k] * b[k * size + j];
            }
        }
    }
}

void fill_matrix(int *matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i * size + j] = 1;
        }
    }
}

double get_time_in_seconds() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <matrix size>\n", argv[0]);
        return 1;
    }

    int size = atoi(argv[1]);
    if (size <= 0) {
        printf("Matrix size must be a positive integer.\n");
        return 1;
    }

    int *a = (int *)malloc(size * size * sizeof(int));
    int *b = (int *)malloc(size * size * sizeof(int));
    int *result = (int *)malloc(size * size * sizeof(int));

    if (a == NULL || b == NULL || result == NULL) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    fill_matrix(a, size);
    fill_matrix(b, size);

    double start_time = get_time_in_seconds();
    multiply_matrices(a, b, result, size);
    double end_time = get_time_in_seconds();

    double elapsed_time = end_time - start_time;
    printf("Matrix multiplication took: %f seconds.\n", elapsed_time);

    free(a);
    free(b);
    free(result);

    return 0;
}
