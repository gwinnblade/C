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
