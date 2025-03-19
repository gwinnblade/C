#include <stdio.h>
  
int main(void)
{
    for(int i=0; i < 5; i++)
    {
        printf("for - Hello\n");
    }
 
    int c = 0;
    while(c < 5)
    {
        printf("while - Hello\n");
        c++;
    }
    return 0;
}
// Напишите программу, которая c помощью циклов for и while выводит на консоль пять раз строки
