#include <stdio.h>

int main() {
    FILE* f = fopen("input.txt", "r");
    if (!f) {
        printf("File not found.\n");
        return 1;
    }
    
    int count = 0, num;
    while (fscanf(f, "%d", &num) == 1) {
    	count++;
	}
	
	fclose(f);
	printf("Count num in file: %d\n", count);
	return 0;
}
