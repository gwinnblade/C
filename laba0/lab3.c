#include <stdio.h>

int main(int argc, char** argv) {
	char str[80];
	scanf("%s", &str);
	for (int a=0; a<80; a++){
		if (str[a]=='a'){
			str[a]='A';
		}
		if (str[a] == 'b') {
			str[a] = 'B';
		}
		
	}
	printf("%s", str);
	
}
