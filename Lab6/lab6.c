#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    FILE *input_file = fopen("input.txt", "w");
    if (input_file == NULL) {
        perror("Error: Input.txt");
        return 1;
    }
    for (int i = 0; i < 100; i++) {
        char surname[15], name[15], otchestvo[15];
        int year = 1900 + rand() % 101;
        sprintf(surname, "surname%d", rand() % 100);
        sprintf(name, "Name%d", rand() % 100);
        sprintf(otchestvo, "otchestvo%d", rand() % 100);
        fprintf(input_file, "%s %s %s %d\n", surname, name, otchestvo, year);
    }
    fclose(input_file);
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        perror("Error: Input.txt");
        return 1;
    }
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        perror("Error: Output.txt");
        fclose(input_file);
        return 1;
    }
    char surname[15], name[15], otchestvo[15];
    int year;
    while (fscanf(input_file, "%s %s %s %d", surname, name, otchestvo, &year) != EOF) {
        if (year > 1980) {
            fprintf(output_file, "%s %s %s %d\n", surname, name, otchestvo, year);
        }
    }
    fclose(input_file);
    fclose(output_file);
    printf("Complete\n");
    return 0;
}
