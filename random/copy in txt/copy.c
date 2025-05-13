#include <stdio.h>

int main() {
	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");
	
	if (!in || !out) {
		printf("error of open file");
		return 1;
	}
	
	char ch;
	while((ch = fgetc(in)) != EOF){
		fputc(ch, out);
	}
	
	fclose(in);
	fclose(out);
	
	printf("Copy complete");
	return 0;
}
