#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM(arr, len, result)	\
	result = arr[0];				\
	for(int i = 1; i < len; i++) {	\
		if (arr[i] > result)		\
			result =arr[i];			\
	}

int main() {
	char input[100];
	int nums[20];
	int c = 0;
	
	printf("Input numbers: ");
	fgets(input, 100, stdin);
	
	char* token = strtok(input, " ");
	while (token != NULL && c < 20) {
		nums[c] = atoi(token); // преобразует строку в целое число 
		c++;
		token = strtok(NULL, " "); // разбивает строку на части (токены) по указанным разделителям (например, пробелы, запятые и т. д.).
	}
	
	int max;
	MAX_NUM(nums, c, max);
	printf("Max Num: %d\n", max);
}
