#include <stdio.h>
main (){
	float fahr, cels;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	cels = lower;
	printf("Cels \tFahr \n");
	while (cels <= upper) {
		fahr = (9.0/5.0)*cels + 32; 

		printf("%3.0f %8.1f \n", cels, fahr);
		cels = cels + step;
	}
}
