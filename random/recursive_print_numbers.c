#include <stdio.h>

void printNumbers(int n) {
    if (n == 0) {
        return;
    }
    printNumbers(n - 1);
    printf("%d ", n);
}

int main() {
    int n;
    printf("Input N: ");
    scanf("%d", &n);

    printf("Numbers from 1 to %d: ", n);
    printNumbers(n);

    return 0;
}
