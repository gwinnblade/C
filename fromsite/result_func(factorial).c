// Напишите функцию, которая вычисляет факториал числа. Факториал числа N вычисляется по формуле N! = 1 * 2 * 3 ...* N. 
// Например, факториал числа 5 равен 5! = 120 (то есть 1*2*3*4*5 =120)
// В функции main вызовите выше определенную функцию несколько раз, передавая ей разные аргументы.

#include <stdio.h>
 
unsigned long long  int factorial(unsigned n)
{
  unsigned long long result = 1;
  for(unsigned i=1; i<=n; i++)
  {
      result *= i;
  }
  return result;
}

int main(void)
{
    printf("factorial 4: %lld\n", factorial(4));
    printf("factorial 5: %lld\n", factorial(5));
    printf("factorial 6: %lld\n", factorial(6));
    return 0;
}
