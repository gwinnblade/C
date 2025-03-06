#include <stdio.h>

int main()
{
	int a = 10, b = 12, c = 15;
	int max = c;
	
	if(a>b && a>c)
		max=a;
	else if(b>a && b>c)
		max=b;
	
	printf("Max: %d", max);
	return 0;
}
