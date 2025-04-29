#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float average_grade;
};

int main() {
    struct Student s;
    
    printf("Input name: ");
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = '\0';
    
    printf("Input age: ");
    scanf("%d", &s.age);
    
    printf("Input average grade: ");
    scanf("%f", &s.average_grade);
    
    printf("\nStudent:\n");
    printf("name: %s\n", s.name);
    printf("age: %d\n", s.age);
    printf("average_grade: %.2f\n", s.average_grade);
    
    return 0;
}
