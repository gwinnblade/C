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



//Дана следующая программа:

/*

#include <stdio.h>
  
int main(void)
{
    int age;
    char name[20];
    // вводим возраст
    printf("Your age: ");
    scanf("%d", &age);
    // вводим имя
    printf("Your name: ");
    scanf("%20s", name);
     
    printf("Name: %s \t Age = %d",name,  age);
    return 0;
}

*/

/* Эта программа имеет проблему - при вводе имени в переменную name помещается только первая часть имени, которая идет до пробела:
Your age: 34
Your name: Tom Smith
Name: Tom        Age = 34
Исправьте программу таким образом, чтобы она могла принимать в качестве имени строки, разделенные пробелом, например, "Tom Smith". */
