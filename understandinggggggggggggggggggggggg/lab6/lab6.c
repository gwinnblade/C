#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	FILE *input_file = fopen("input.txt", "w");
	for (int i = 0; i < 100; i++) {
		char surname[20], name[20], otchestvo[20];
		int year = 1900 + rand() % 100;
		sprintf(surname, "surname%d", rand()%100);
		sprintf(name, "name%d", rand()%100);
		sprintf(otchestvo, "otchestvo%d", rand()%100);
		fprintf(input_file, "%s %s %s %d\n", surname, name, otchestvo, year);
	}
	fclose(input_file);
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        return 1;
    }
	FILE *output_file = fopen("output.txt", "w");
	char surname[20], name[20], otchestvo[20];
	int year;
	while(fscanf(input_file, "%s %s %s %d", surname, name, otchestvo, &year) != EOF) {
		if (surname[7] == '1' && name[4] == '1') {
			fprintf(output_file, "%s %s %s %d\n", surname, name, otchestvo, year);
		}
	}
	fclose(input_file);
	fclose(output_file);
	printf("Complete\n");
	return 0;
}
