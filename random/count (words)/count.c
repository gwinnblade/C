#include <stdio.h>
#include <ctype.h>

int main () {
	FILE* f = fopen("input.txt", "r");
	if (!f) {
		printf("Error input.txt");
		return 1;
	}
	
	int in_word = 0, words = 0;
	char ch;
	while ((ch = fgetc(f)) != EOF){
		if (isspace(ch)){
			in_word = 0;
		} else if (!in_word) {
			in_word = 1;
			words++;
		}
	}
	
	fclose(f);
	printf("count of word: %d\n", words);
	return 0;
}
