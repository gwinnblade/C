#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	char name[50];
	char second_name[50];
	char gender;
	int year;
	float height
} Person;

void print_people(Person people[], int c){
	printf("Name \t Second name \t Year \t Gender \t Height \n");
	for(int i=0; i<c; i++) {
		printf("%s \t %s \t\t %d \t %c \t\t %.2f\n",
               people[i].name, people[i].second_name, 
               people[i].year, people[i].gender, people[i].height);
	}
}

int compare_people(const void *a, const void *b, int *fields, int field_count) {
	const Person *pa = (const Person *)a;
	const Person *pb = (const Person *)b;
	
	for (int i = 0; i<field_count; i++) {
		int field = fields[i];
		int cmp = 0;
		
		switch(field) {
			case 1:
				cmp = pa->year - pb->year;
				break;
			case 2:
				cmp = strcmp(pa->name, pb->name);
				break;
			case 3:
				cmp = strcmp(pa->second_name, pb->second_name);
				break;
			case 4:
				cmp = pa->gender - pb->gender;
				break;
			case 5:
				cmp = (pa->height > pb->height) ? 1 : (pa->height < pb->height) ? -1 : 0;
				break;
		}
		if(cmp != 0) return cmp;
	}
	return 0;
}

int main(){
	FILE *lab8 = fopen("lab8.txt", "w");
	if (!lab8) {
		perror("Error: Create file");
		return 1;
	}
	fprintf(lab8, "\nJohn Doe 1988 M 1.73\n");
	fprintf(lab8, "Dane Joe 1983 F 1.73\n");
	fprintf(lab8, "Alice Kole 1995 F 1.73\n");
	fprintf(lab8, "Chris Brown 1994 M 1.73\n");
	fprintf(lab8, "Kate Cale 1990 F 1.73\n");
	fprintf(lab8, "Mike Aqua 1997 M 1.73\n");
	fprintf(lab8, "Nicole Pek 1986 M 1.73\n");
	fclose(lab8);
	
	lab8 = fopen("lab8.txt", "r");
	if(!lab8){
		perror("Error: Read file");
		return 1;
	}
	Person people[50];
	int c = 0;
	
	while (fscanf(lab8, "%s %s %d %c %f", people[c].name, people[c].second_name, &people[c].year, &people[c].gender, &people[c].height) == 5){
		c++;
		if (c >= 50) break;
	}
	fclose(lab8);
	
	printf("Original data:\n");
	print_people(people, c);
	
	
    printf("\nSorting:\n");
    printf("1 - Year\n");
    printf("2 - Name\n");
    printf("3 - Second Name\n");
    printf("4 - Gender\n");
    printf("5 - Height\n");
    printf("Enter numbers: ");
    
    char input[50];
    fgets(input, sizeof(input), stdin);
    while (getchar() != '\n');
    
    int fields[5];
    int field_count = 0;
    char *token = strtok(input, " ");
    
    while (token != NULL && field_count < 5) {
    	int field = atoi(token);
    	if (field >= 1 && field <= 5){
    		fields[field_count++] = field;
		}
		token = strtok(NULL, " ");
	}
    
    if(field_count == 0) {
    	printf("Sorting by year");
    	fields[0] = 1;
    	field_count = 1;
	}
	for (int i = 0; i < c - 1; i++){
		for (int j = 0; j < c - i - 1; j++){
			if(compare_people(&people[j], &people[j+1], fields, field_count) > 0){
				Person temp = people[j];
				people[j] = people[j+1];
				people[j+1] = temp;
			}
		}
	}
	printf("\nSorted:\n");
	print_people(people, c);
} 
