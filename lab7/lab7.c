#include <stdio.h>
#include <string.h>

typedef struct {
	char name[50];
	char second_name[50];
	int year;
} humen;

void swap(humen *a, humen *b) {
	humen temp = *a;
	*a = *b;
	*b = temp;
}

void sortByYear(humen arr[], int n) {
	for (int i = 0; i < n-1; i++){
		for (int j=0; j<n-i-1; j++){
			if(arr[j].year > arr[j+1].year){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

int main() {
	humen array1[4];
	humen array2[4];
	printf("Input data for 4 people\n");
	for (int i = 0; i < 4; i++){
		printf("Human N%d:\n", i+1);
		printf("Name: ");
		scanf("%s", array1[i].name);
		printf("Second Name: ");
		scanf("%s", array1[i].second_name);
		printf("Year: ");
		scanf("%d", &array1[i].year);
	}
	
	for (int i = 0; i < 4; i++) {
		strcpy(array2[i].name, array1[i].name);
		strcpy(array2[i].second_name, array1[i].second_name);
		array2[i].year = array1[i].year;
	}
	sortByYear(array2, 4);
	
	printf("\nSorted Data by Year\n");
	for (int i = 0; i < 4; i++) {
		printf("%s %s, %d\n", array2[i].name, array2[i].second_name, array2[i].year);
	}
	
	return 0;
}
