#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


double parse_number(char* token) {
	return atof(token);
}

int main() {
	char input[256];
	printf("Input expression: \n");
	fgets(input, sizeof(input), stdin);
	
	input[strcspn(input, "\n")] = '\0'; 
	
	char modified[512] = "";
	int i = 0;
	if (input[0] == '-') {
		strcat(modified, "0 ");
	}
	while (input[i]) {
		if (input[i] == '-' && (i == 0 || input[i - 1] == ' ')) {
			strcat(modified, "-");
		} else if (input[i] == '+' && (i == 0 || input[i - 1] == ' ')) {
			strcat(modified, "+");
		} else {
			strncat(modified, &input[i], 1);
		}
		i++;
	}
	
	char* token = strtok(modified, " ");
	double result = 0.0;
	char current_op = '+';
	
	while (token != NULL) {
		if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0){
			current_op = token[0];
		} else {
			double number = parse_number(token);
			if (current_op == '+'){
				result += number;
			} else if (current_op == '-') {
				result -= number;
			}
		}
		token = strtok (NULL, " ");
	}
	printf("Result: %.2f\n", result);
	return 0;
}
