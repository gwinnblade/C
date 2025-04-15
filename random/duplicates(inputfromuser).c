#include <stdio.h>

int has_duplicates(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    int size;
    printf("Input size of array: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Array must be > 0\n");
        return 1;
    }
    int arr[size];
    printf("Input %d elements of array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    if (has_duplicates(arr, size)) {
        printf("Yes duplicates.\n");
    } else {
        printf("No duplicates.\n");
    }
    return 0;
}
