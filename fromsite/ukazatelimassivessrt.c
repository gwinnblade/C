#include <stdio.h>
 
int main()
{
    int array[] = {3, 4, 5, 6, 7};
    int *p = array;
    p = p + 2;
    printf("array[2] = %d\n", *p);
    p = p + 1;
    printf("array[3] = %d\n", *p);
    return 0;
}
