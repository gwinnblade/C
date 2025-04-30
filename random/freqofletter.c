#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char str[200];
	int freq[26] = {0};
	
	printf("Input string: ");
	fgets(str, sizeof(str), stdin);
	
	for(int i = 0; str[i] != '\0'; i++) {
		if (isalpha(str[i])){
			char lower = tolower(str[i]);
			freq[lower - 'a']++;
		}
	}

	printf("Frequency of letter: \n");
	for(int i = 0; i < 26; i++){
		if (freq[i] > 0)
			printf("%c: %d\n", i + 'a', freq[i]);
	}

	return 0;
}
