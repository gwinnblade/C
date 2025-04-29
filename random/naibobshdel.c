// наибольший общий делитель


#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int num1, num2;
    printf("Input 2 numbers: ");
    scanf("%d %d", &num1, &num2);

    int result = gcd(num1, num2);
    printf("Naibolsh Obsh Del %d and %d: %d\n", num1, num2, result);

    return 0;
}
