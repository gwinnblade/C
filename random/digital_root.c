// ЦИФРОВОЙ КОРЕНЬ -- 9875 = 9+8+7+5 = 29 -> 2 + 9 = 11 -> 1 + 1 = 2

#include <stdio.h>

int dig_root(int n){
	while (n >= 10){
		int sum = 0;
		while (n > 0){
			sum += n % 10;
			n /= 10;
		}
		n = sum;
	}
	return n;
}

int main(){
	int n;
	printf("Input num: ");
	scanf("%d", &n);
	printf("digital root %d", dig_root(n));
	return 0;
}
