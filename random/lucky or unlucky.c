#include <stdio.h>

int main()
{
	int n;
	printf("input 6-digit num: ");
	scanf("%d", &n);
	
	if (n < 100000 || n > 999999){
		printf("Your num less or higher than 6 digit");
		return 1;
	}
	
	int s1 = 0, s2 = 0;
	for (int i = 0; i < 3; i++){
		s1 += n % 10;
		n /= 10;
	}
	
	for (int i = 0; i < 3; i++){
		s2 += n % 10;
		n /= 10;
	}
    if (s1 == s2)
        printf("Lucky num\n");
    else
        printf("Unlucky num\n");

    return 0;
}
