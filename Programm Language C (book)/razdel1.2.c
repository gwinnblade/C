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
		
			/* �� C ���� ���� �������� �� ������� �����, 
		�� ������� ����� ��������� ��������� � ����� �������*/
		
		
		printf("%3d %4d \n", fahr, cels);
		/*printf("%d\t%d\n", fahr, cels); */
		/*printf("%3d %6d \n", fahr, cels); */
		
		/* %d - ��������� ������������� �������� ����� ������� �� ������� 
					\t - ��������� ��������� (4 �������) */
		
		fahr = fahr + step;
	}
}
