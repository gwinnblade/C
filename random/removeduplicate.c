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
    int arr[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int newSize = removeDuplicates(arr, 8);
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
