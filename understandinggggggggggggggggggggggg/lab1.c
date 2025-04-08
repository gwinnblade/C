#include <stdio.h>
#include <math.h>

int main(){
// Обозначаем переменные
	double a, b, c; 
	double x1, x2, d;
	char choice;

// Зациклить через do - while
	do{
		printf("Input A: \n");
		scanf("%lf", &a);
		printf("Input B: \n");
		scanf("%lf", &b);
		printf("Input C: \n");
		scanf("%lf", &c);
		
		d = pow(b,2) - 4*a*c; //pow - первый элемент - переменная, второй элемент - возвести в степень
		printf("d = %lf \n", d);
		
		if (d > 0) {
			x1 = -b + sqrt(d) / (2*a); //sqrt - квадратный корень
			x2 = -b - sqrt(d) / (2*a);
			printf("x1 = %lf \n", x1);
			printf("x2 = %lf \n", x2);
		} else if (d == 0){
			x1 = -b + sqrt(b) / (2*a);
			printf("x = %lf \n", x1);
		} else {
			printf("Null");
		}
		printf("Continue? (Y/N): "); //Зациклить программу если Y || y
		scanf(" %c", &choice);
		
	} while (choice == 'Y' || choice == 'y'); // || - или
	return 0;
}
