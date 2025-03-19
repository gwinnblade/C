#include <stdio.h>
 
int main(void)
{
    const long n = 123;
    const long *pn = &n;
    char *const hello = "Hello";

    printf("Constant: %ld\n", *pn);
    printf("Const ukazatel: %s\n", hello);
    return 0;
}

// Напишите программу, в которой определите константу типа long и определите указатель на эту константу. 
// Также определите константный указатель на строку "Hello".
// Выведите на консоль значения, на которые указывают указатели.
