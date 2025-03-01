#include <stdio.h>
#include <stdlib.h>

double* matrix_operation(double* matrix1, double* matrix2, int n, char operation) {
    double* result = (double*)malloc(n * n * sizeof(double));

    if (operation == '+') {
        for (int i = 0; i < n * n; i++) {
            result[i] = matrix1[i] + matrix2[i];
        }
    } else if (operation == '-') {
        for (int i = 0; i < n * n; i++) {
            result[i] = matrix1[i] - matrix2[i];
        }
    } else if (operation == '*') {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i * n + j] = 0;
                for (int k = 0; k < n; k++) {
                    result[i * n + j] += matrix1[i * n + k] * matrix2[k * n + j];
                }
            }
        }
    } else {
        return NULL;
    }

    return result;
}
