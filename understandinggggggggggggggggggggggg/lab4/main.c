#include <stdio.h>

// ������ ������� ������� ������� � formuls.c
double calc_perimeter(double a, double b, double c);
double calc_area(double a, double b, double c);

// �������� �� �������������
int valid_triangle(double a, double b, double c) {
	return (a+b > c) && (a+c > b) && (b+c > a); 
// ���� ��� �������� �������� ������ ����������� ����������. && - "�" 
}

int main() {
	double a, b, c;
	printf("Input side: \n");
	printf("Input A: \n");
	scanf("%lf", &a); //lf -��������� � ��������� ������ 
	printf("Input B: \n");
	scanf("%lf", &b);
	printf("Input C: \n");
	scanf("%lf", &c);
	
	if (valid_triangle(a,b,c)) {
		double perimeter = calc_perimeter(a,b,c);
		double area = calc_area(a,b,c);
		printf("Perimeter: %.2f \n", perimeter);
		printf("Area: %.2f \n", area);
	}
	else {
		printf("No Triangle: \n");
	}
}
