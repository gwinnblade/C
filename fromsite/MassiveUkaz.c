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
