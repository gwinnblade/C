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
