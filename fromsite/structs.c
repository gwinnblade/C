#include <stdio.h>
 
struct employee
{
    char *name;
    int age;
    double salary;
};
int main(void)
{
    struct employee oleg = {"Oleg", 22, 525252};
    printf("Name: %s\n", oleg.name);
    printf("Age: %d\n", oleg.age);
    printf("Salary: %.2f\n", oleg.salary);
    return 0;
}

// Определите структуру, которую назовите "employee". В структуре определите следующие элементы:

// name, который имеет тип char *
// age, который имеет тип int
// salary, который имеет тип double

// В функции main определите переменную данной структуры, присвойте ее элементам значения и выведите их на экран таким образом, чтобы консольный вывод программы был следующим:
