#include <stdio.h>
#include <string.h>

int is_vowel(char ch){
	ch = tolower(ch);
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch =='u';
}

int main() {
	FILE* f = fopen("input.txt", "r");
	if (!f) {
		printf("Error of open file");
		return 1;
	}
	
	char ch;
	int count = 0;
	while((ch = fgetc(f)) != EOF){
		if (is_vowel(ch)){
			count++;
		}
	}
	fclose(f);
	printf("Vowel in file: %d", count);
	return 0;
}
