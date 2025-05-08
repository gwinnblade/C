#include <stdio.h>

void printDigitsForward(int n){
	if (n == 0)
		return 0;
	printDigitsForward(n / 10);
	printf("%d ", n % 10);
}

void printDigitsReverse(int n) {
	if (n == 0)
		return 0;
	printf("%d ", n % 10);
	printDigitsReverse(n / 10);
}

int main(){
	int N;
	printf("Input num: ");
	scanf("%d", &N);
	
	if (N == 0) {
		printf("0\n0\n");
		return 0;
	}
	
	printDigitsForward(N);
	printf("\n");
	
	printDigitsReverse(N);
	printf("\n");
	
	return 0;
}

/*

printDigitsForward(179)
|
--> printDigitsForward(17)
    |
    --> printDigitsForward(1)
        |
       	|
        |
        --> print: 1
    |
    --> print: 7
|
--> print: 9

*/

/*
printDigitsReverse(179)
|
+--> print: 9
+--> printDigitsReverse(17)
     |
     +--> print: 7
     +--> printDigitsReverse(1)
          |
          +--> print: 1
          +--> printDigitsReverse(0)

*/
