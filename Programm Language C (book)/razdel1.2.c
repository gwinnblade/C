#include <stdio.h>
main (){
	float fahr, cels;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	fahr = lower;
	while (fahr <= upper) {
		cels = (5.0/9.0) * (fahr-32.0); 
		
			/* На C если надо умножить на дробное число, 
		то сначала нужно выполнить умножение а после деление
					(В ЦЕЛОЧИСЛЕННЫХ ДЕЛЕНИЯХ НА 0)
					cels = 5 * (fahr-32.0) / 9 */
					
		printf("%3.0f %6.1f \n", fahr, cels);
		/*printf("%d\t%d\n", fahr, cels); */
		/*printf("%3d %6d \n", fahr, cels); */
		
		/* %d - вставляет целочисленные значения после запятой по порядку 
		   %f - вставляет числа с плавающей точкой
		   \t - вставляет табуляцию (4 пробела)      */

		fahr = fahr + step;
	}
}
