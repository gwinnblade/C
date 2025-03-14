#include <stdio.h>
  
int main(void)
{
    int first;
    double second;
    printf("Input first (int):");
    scanf("%d", &first);
     
    printf("Input second (double):");
    scanf("%lf", &second);
     
    printf("Double: %.2lf \t int: %d \n", second, first);
    return 0;
}
