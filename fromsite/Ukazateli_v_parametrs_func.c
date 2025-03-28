// Напишите функцию, которая в качестве параметра принимает два числа и меняет их значения.
#include <stdio.h>
 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b=temp;
}
int main(void)
{
    int x = 444;
    int y = 666;
    swap(&x, &y);
    printf("x=%d \t y=%d \n", x, y);
    return 0;
}
