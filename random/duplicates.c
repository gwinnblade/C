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
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 2, 5};
    printf("%d\n", has_duplicates(arr1, 5));
    printf("%d\n", has_duplicates(arr2, 5));
    return 0;
}
