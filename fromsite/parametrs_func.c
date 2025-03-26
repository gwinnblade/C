#include <stdio.h>
void print_number(int n)
{
    n = n + 5;
    printf("%d\n", n);
}
int main(void)
{
    print_number(10);
    print_number(14);
    return 0;
}

// Определите функцию, которая принимает один параметр типа int, увеличивает его значение на 5 и выводит его на консоль.
