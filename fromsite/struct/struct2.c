#include <stdio.h>

typedef struct
{
	char *name;
	int age;
	double salary;
} employee;

int main(void)
{
	employee sanya = {"Sanya", 22, 5252};
	employee vanya = {"Vanya", 23, 2525};
	printf("Name %s \t Age %d \t Salary %.2f\n", sanya.name, sanya.age, sanya.salary);
	printf("Name %s \t Age %d \t Salary %.2f\n", vanya.name, vanya.age, vanya.salary);
	return 0;
}

//Возьмите программу из предыдущего упражнения и определите с помощью оператора typedef для структуры псевдоним "employee". 
//Используйте этот псевдоним для определения переменных этой структуры.
