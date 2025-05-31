#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void generate_numbers(int count) {
    FILE *fp = fopen("input.txt", "w");
    if (!fp) {
        printf("Не удалось открыть input.txt для записи.\n");
        return;
    }
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d\n", rand() % 100);
    }

    fclose(fp);
}

void process_numbers() {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        printf("Не удалось открыть input.txt для чтения.\n");
        return;
    }

    int arr[1000];
    int n = 0;

    while (fscanf(fp, "%d", &arr[n]) == 1) {
        n++;
    }
    fclose(fp);

    fp = fopen("output.txt", "w");
    if (!fp) {
        printf("Не удалось открыть output.txt для записи.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        int num = arr[i];
        if (num % 5 == 0 || num % 7 == 0) {
            if (num % 5 == 0) fprintf(fp, "FIVE");
            if (num % 7 == 0) fprintf(fp, "SEVEN");
            fprintf(fp, "\n");
        } else {
            fprintf(fp, "%d\n", num);
        }
    }

    fclose(fp);
}

void analyze_matrix() {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        printf("Не удалось открыть input.txt для чтения.\n");
        return;
    }

    int numbers[100];
    int n = 0;

    while (fscanf(fp, "%d", &numbers[n]) == 1) {
        n++;
    }
    fclose(fp);

    int N = (int)sqrt(n);
    if (N * N != n) {
        printf("Количество чисел не является полным квадратом.\n");
        return;
    }

    int matrix[N][N];
    int idx = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            matrix[i][j] = numbers[idx++];

    // Вывод матрицы
    printf("Матрица %dx%d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Суммы строк и столбцов
    printf("\nСуммы строк и столбцов:\n");
    for (int i = 0; i < N; i++) {
        int row_sum = 0, col_sum = 0;
        for (int j = 0; j < N; j++) {
            row_sum += matrix[i][j];
            col_sum += matrix[j][i];
        }
        printf("Строка %d: %d\tСтолбец %d: %d\n", i, row_sum, i, col_sum);
    }
}

int main() {
    int count;
    printf("Введите количество чисел (должно быть квадратом целого числа): ");
    scanf("%d", &count);

    clock_t start = clock();

    generate_numbers(count);
    process_numbers();
    analyze_matrix();

    clock_t end = clock();
    printf("\nВремя выполнения: %.3f секунд\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
