#include <stdio.h>

int main() {
	double Matrix[3][3];
	double SumMainDiagonal = 0;
	double SumPobochDiagonal = 0;
	int i, j;

// ����������� ���� 3�3 �������
	printf("Input elements (3x3): \n"); 
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			(scanf("%lf", &Matrix[i][j]) != 1);
		}
	}
// ������� �������
	printf("\n");
	printf("Matrix: \n");
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			printf("%.2f ", Matrix[i][j]);
		}
		printf("\n");
	}
// ������� ������� ���������
	for (i = 0; i < 3; i++) {
		SumMainDiagonal += Matrix[i][i];
	}
// ������� �������������� ���������
	for (i = 0; i < 3; i++) {
		SumPobochDiagonal += Matrix[i][2-i];
	}
	printf("Sum Main Diagonal: %.2f\n", SumMainDiagonal);
	printf("Sum Poboch Diagonal: %.2f\n", SumPobochDiagonal);
}
