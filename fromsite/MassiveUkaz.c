#include <stdio.h>
 
int main()
{
    char *chel[] = {"Sanya", "Vanya", "Vasya"};
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", chel[i]);
    }
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", *(chel + i));
    }
    return 0;
}

// Определите массив указателей
// который содержит три следующих элемента в виде имен. {"Name1", "Name2", "Name3"}
// Выведите все эти строки на консоль.
