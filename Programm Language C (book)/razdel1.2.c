#include <stdio.h>
main (){
	int fahr, cels;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	fahr = lower;
	while (fahr <= upper) {
		cels = 5 * (fahr-32) / 9; 
		
			/* На C если надо умножить на дробное число, 
		то сначала нужно выполнить умножение а после деление*/
		
		
		printf("%3d %4d \n", fahr, cels);
		/*printf("%d\t%d\n", fahr, cels); */
		/*printf("%3d %6d \n", fahr, cels); */
		
		/* %d - вставляет целочисленные значения после запятой по порядку 
					\t - вставляет табуляцию (4 пробела) */
		
		fahr = fahr + step;
	}
}
