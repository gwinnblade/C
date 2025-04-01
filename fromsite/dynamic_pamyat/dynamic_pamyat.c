#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    double *p_double = malloc(sizeof(double));
    if (p_double)
    {
        *p_double = 3.1415;
        printf("*p_double = %f\n", *p_double);
    }
    free(p_double);
    long *p_long = malloc(sizeof *p_long);
    if (p_long)
    {
        *p_long = 32;
        printf("*p_long: %ld\n", *p_long);
    }
    free(p_long);
}


//Напишите программу, которая выделяет память для одного объекта double, 
// используя размер типа, и для одного объекта long, используя размер указателя.
// Поместите значения в выделенные участки памяти и выведите эти значения на консоль. После этого освободите выделенную память.
