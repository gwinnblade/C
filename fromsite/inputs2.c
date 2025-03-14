#include <stdio.h>

int main(void)
{
    int age;
    char name[20];
    printf("Your age: ");
    scanf("%d", &age);
    printf("Your name: ");
    scanf(" %20[^\n]", name);
    printf("Name: %s \t Age = %d\n", name, age);
    return 0;
}
