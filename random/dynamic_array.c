#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, sum = 0;
    int *arr;
    
    printf("Input array: ");
    scanf("%d", &n);
    
    
    
    arr = (int*)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Error: memory\n");
        return 1;
    }
    
    printf("Input %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    printf("Sum of elements: %d\n", sum);
    
    free(arr);
    
    return 0;
}
