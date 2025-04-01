#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n = 5;
    long *p_long = malloc(5 * sizeof(long));
    if (p_long)
    {
        for(int i = 0; i < n; i++)
        {
            p_long[i] = i + 1;
            printf("p_long[%d]: %ld\n",i, p_long[i]);
        }
    }
    free(p_long);
}
//Напишите программу, которая динамически выделяет память для массива из пяти чисел типа long. 
//Используя цикл for, присвойте значения элементами массива и выведите их на консоль. После этого освободите память.
