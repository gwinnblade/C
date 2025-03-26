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

