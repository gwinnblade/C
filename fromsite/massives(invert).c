#include <stdio.h>
 
int main()
{
    int numbers[] = {1, 2, 3, 4, 5, 6};

    int n = sizeof(numbers) / sizeof(numbers[0]);
    int m = n / 2;
    for(int i = 0; i < m; i++)
    {
        int temp = numbers[i];
        numbers[i] = numbers[n-i-1];
        numbers[n-i-1] = temp;
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d", numbers[i]);
    }
    return 0;
}

// Напишите программу, в которой определите следующий массив из пяти чисел - {1, 2, 3, 4, 5}. 
// Инвертируйте массив (чтобы в массиве элементы расположились в обраном порядке - {5, 4, 3, 2, 1}).
