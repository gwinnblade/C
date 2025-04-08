#include <stdio.h>

int main() {
	int Matrix[2][2];
	int MatrixSQ[2][2] = {0};
	int i, j, k;

	printf("Input Elements (2x2): \n");
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			scanf("%d", &Matrix[i][j]);
		}
	}
	printf("Matrix: \n");
	for (i=0; i<2; i++){
		for (j=0; j<2; j++){
			printf("%d ", Matrix[i][j]);
		}
		printf("\n");
	}
	for (i=0; i<2; i++){
		for (j=0; j<2; j++){
			MatrixSQ[i][j] = 0;
			for (k=0; k<2; k++){
				MatrixSQ[i][j] += Matrix[i][k] * Matrix[k][j];
			}
		}
	}
	printf("Martix Square: \n");
	for (i=0; i<2; i++){
		for (j=0; j<2; j++){
			printf("%d ", MatrixSQ[i][j]);
		}
		printf("\n");
	}
	return 0;
}

