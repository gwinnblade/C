#include <stdio.h>

int removeDuplicates(int arr[], int size) {
    if (size == 0) return 0;

    int uniqueIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[uniqueIndex]) {
            arr[++uniqueIndex] = arr[i];
        }
    }
    return uniqueIndex + 1;
}
int main() {
    int size;

    printf("Input array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Error \n");
        return 1;
    }

    int arr[size];

    printf("Input sorted elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            printf("Error input has been sorted\n");
            return 1;
        }
    }

    int newSize = removeDuplicates(arr, size);

    printf("Massives without duplicates:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
