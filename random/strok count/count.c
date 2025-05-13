#include <stdio.h>

int main() {
	FILE* f = fopen("input.txt", "r");
	if (!f) {
		printf("file not found");
		return 1;
	}
	
	int count = 0;
	char nul;
	while((nul = fgetc(f)) != EOF){
		if (nul == '\n')
			count++;
	}
	
	fclose(f);
	
	printf("Count of strok: %d\n", count + 1);
	return 0;
}
