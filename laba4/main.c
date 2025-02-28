#include <stdio.h>

double calculate_perimeter(double a, double b, double c);
double calculate_area(double a, double b, double c);

int is_valid_triangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int main() {
    double a, b, c;

    printf("Input side:\n");
    printf("Input a: ");
    scanf("%lf", &a);
    printf("Input b: ");
    scanf("%lf", &b);
    printf("Input c: ");
    scanf("%lf", &c);

    if (is_valid_triangle(a, b, c)) {
        double perimeter = calculate_perimeter(a, b, c);
        double area = calculate_area(a, b, c);

        printf("perimeter: %.2f\n", perimeter);
        printf("area: %.2f\n", area);
    } else {
        printf("Error.\n");
    }

    return 0;
}
