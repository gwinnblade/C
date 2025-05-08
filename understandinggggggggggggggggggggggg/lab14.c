#include <stdio.h>
#include <setjmp.h>

jmp_buf env;
int sum = 0;

int fib(int n) {
	if (n == 1 || n == 2)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

void sum_fib(int n, int current){
	if (current > n) {
		longjmp(env, 1);
	}
	sum += fib(current);
	sum_fib(n, current + 1);
}

int main(){
	int n;
	
	printf("Input quanity of nums for sum(fibbonachi) \n");
	scanf("%d", &n);
	
	if (setjmp(env) == 0){
		sum_fib(n, 1);
	} else {
		printf("Sum first %d nums fibbonachi %d\n", n, sum);
	}
	return 0;
}
