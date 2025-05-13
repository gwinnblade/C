#include <stdio.h>
#include <limits.h>

int main() {
	FILE* f = fopen("input.txt", "r");
	if (!f) {
		printf("Error input.txt");
		return 1;
	}
	
	int max = INT_MIN, num;
	while (fscanf(f, "%d", &num) == 1) {
		if (num > max)
			max = num;
	}
	fclose(f);
	printf("Max num: %d\n", max);
	return 0;
}
