#include <stdio.h>



void    ft_swap(int *a, int *b)
{
  int swap;

  swap = *a;
  *a = *b;
  *b = swap;
}

int main()
{
  
  int voda = 8;
  int coffe = 10;
  int temp;
    
  int *iptr = &voda;
  int *jptr = &coffe;

  ft_swap(iptr, jptr);

  printf("%d\n", i);
  printf("%d\n", j);
  
  return (0);
}
