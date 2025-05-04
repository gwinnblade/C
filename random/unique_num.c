// УНИКАЛЬНОЕ ЧИСЛО БЕЗ ПОВТОРЕНИЙ ЦИФР

#include <stdio.h>

int main()
{
	int num;
	int digits[10] = {0};
	
	printf("Input number ");
	scanf("%d", &num);
	
	while (num > 0) {
		int d = num % 10;
		if (digits[d] == 1) {
			printf("Repeat digit: %d\n", d);
			return 0;
		}
		digits[d] = 1;
		num /= 10;
	}
	printf("All digit uniqie\n");
	return 0;
}
