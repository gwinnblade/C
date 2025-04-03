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

/* Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n
с эле-ментами типа double (значения n и элементы массивов ввести с консоли).
А также вве-сти с консоли знак операции: '+', '-' или '*'.
Написать функцию, вычисляющую сумму, разность или произведение данных матриц (их передать по указателю)
и возвращаю-щую указатель на массив-результат. Разместить эту функцию в отдельном модуле (от-личном от того,
где располагается функция main()).
Выдать на консоль значения полу-ченного вектора. */
