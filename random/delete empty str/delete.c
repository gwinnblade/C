#include <stdio.h>
#include <string.h>

int main() {
    FILE* in = fopen("input.txt", "r");
    FILE* out = fopen("output.txt", "w");

    if (!in || !out) {
        printf("Error of open file.\n");
        return 1;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), in)) {
    	int empty = 1;
    	for (int i = 0; line[i]; i++) {
    		if (line[i] != ' ' && line[i] != '\n'){
    			empty = 0;
    			break;
			}
		}
		if (!empty) {
			fputs(line, out);
		}
	}
	fclose(in);
	fclose(out);
	printf("Empty str deleted");
	return 0;
}
