#include <stdio.h>
#include <stdlib.h>

double* matrix_operation(double* matrix1, double* matrix2, int n, char operation);

int main() {
    int n;
    char operation;

    printf("Input size of matrix N: ");
    scanf("%d", &n);

    double* matrix1 = (double*)malloc(n * n * sizeof(double));
    double* matrix2 = (double*)malloc(n * n * sizeof(double));

    printf("Input elements 1st matrix:\n");
    for (int i = 0; i < n * n; i++) {
        scanf("%lf", &matrix1[i]);
    }

    printf("Input elements 2nd matrix:\n");
    for (int i = 0; i < n * n; i++) {
        scanf("%lf", &matrix2[i]);
    }

    printf("Operation: (+, -, *): ");
    scanf(" %c", &operation);

    double* result = matrix_operation(matrix1, matrix2, n, operation);

    printf("Result:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", result[i * n + j]);
        }
        printf("\n");
    }
    return 0;
}
