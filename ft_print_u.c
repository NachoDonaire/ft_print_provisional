#include "printf_lib.h"

int len(unsigned long int i)
{
  int y;

  y = 0;
  while (i > 0)
  {
    i = i / 10;
    y++;
  }
  return (y);
}

char    *aitoa(unsigned long int i)
{
  int w = len(i);
  char *sol;
  int rest = 0;
  sol = malloc((w + 1) * sizeof(char));
  //w = w - 1;
  sol[w] = '\0';
  w--;
  while (w  >= 0)
  {
    rest = i % 10;
    sol[w] = rest + 48;
    w--;
    i = i / 10;
  }
  return(sol);
}



