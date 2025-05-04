#include <stdio.h>

int main()
{
	int n, is_palindrome = 1;
	printf("Input size of array ");
	scanf("%d", &n);
	
	int a[n];
	printf("Input elements of array\n");
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < n / 2; i++){
		if(a[i] != a[n-i-1]) {
			is_palindrome = 0;
			break;
		}
	}
	
	if(is_palindrome)
		printf("Massive is palindr");
	else
		printf("Massive is`nt palindr");

	return 0;
}
