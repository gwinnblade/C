#include <stdio.h>
#include <string.h>

void reverse(char *start, char *end) {
	while (start < end) {
		char temp = *start;
		*start++ = *end;
		*end-- = temp;
	}
}

void reverse_words(char *str){
	char *word_start = str;
	char *temp = str;


	while(*temp) {
		if (*temp == ' ') {
			reverse(word_start, temp-1);
			word_start = temp+1;
		}
	temp++;
	}
	reverse(word_start, temp-1);
	reverse(str, temp-1);
}

int main() {
	char str[] = "agxny agXny AGXNY";
	reverse_words(str);
	printf("%s\n", str);
	return 0;
}//
