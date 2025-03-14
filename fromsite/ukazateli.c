#include <stdio.h>
 
int main()
{
    int n = 10;
    int *an = &n;
    printf("Address: %p \n", (void *)an);
    printf("Value: %d \n", *an);
    return 0;
}
