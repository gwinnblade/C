#include <stdio.h>
#define LOWER 0 /* нижний предел */
#define UPPER 300 /*верхний  */
#define STEP 20 /* шаг */
main (){
	int fahr;
	/* 				ПО	ВОЗРАСТАНИЮ					  */
	/* for (fahr = 0; fahr <= 300; fahr = fahr + 20) */
	for (fahr = UPPER; fahr > LOWER; fahr = fahr - STEP)
		printf("%3d %6.1f \n", fahr, (5.0/9.0) * (fahr-32));
}
