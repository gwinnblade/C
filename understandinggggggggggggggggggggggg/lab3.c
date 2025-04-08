#include <stdio.h>
int main() {
	char str[80];
	printf("Input str: \n");
	scanf("%s ", &str);
	for (int i=0; i<80; i++){
		if (str[i] == 'a'){
			str[i] = 'A';
		}
		if (str[i] == 'b'){
			str[i] = 'B';
		}
	}
	printf("%s", str);
}
