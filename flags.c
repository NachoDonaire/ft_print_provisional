#include "printf_lib.h"

void    ft_aply_width(va_list dest, va_list arg)
{
  int y;
  int x;
  int digits;
  int count;

  y = va_arg(arg, int);
  va_arg(dest, int);
  x = va_arg(dest, int);
  digits = 0;
  while (x > 0)
  {
    x = x / 10;
    digits++;
  }
  count = y - digits;
  while (count > 0)
  {
    write(1, " ", 1);
    count--;
  }
}






