#include <stdio.h>

int main(void)
{
	float width, height, area;
	printf("Enter width: ");
	scanf("%f", &width);
	printf("Enter height: ");
	scanf("%f",&height);
	area=width*height;
	printf("Area %f\n", area);
	return 0;
}

// Напишите программу, в которой с консоли вводятся высота и ширина прямоугольника, а выводится его площадь.
