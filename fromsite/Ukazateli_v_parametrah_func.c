// Напишите функцию, которая в качестве параметра принимает строку и выводит ее на консоль. 
// В функции main вызовите выше определенную функцию несколько раз, передавая ей разные строки.

#include <stdio.h>
 
void print(char text[])
{
    printf(text);
}

int main(void)
{
    print("die \n");
    print("in \n");
    print("agxny \n");
    return 0;
}
