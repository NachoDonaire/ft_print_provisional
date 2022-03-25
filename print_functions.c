#include "printf_lib.h"

void    ft_print_char(va_list arg, t_sc *tab)
{
  char a;
  int y;
  char z;

  z = '0';
  if (tab -> width == 1)
  {
    y = va_arg(arg, int);
    while (y > 0)
    {
      write(1, &z, 1);
      y--;
    }
  }
  a = va_arg(arg, int);
  write(1, &a, 1);
}

void    ft_print_nb(int i)
{
  int y;

  y = i;
  if (y < 0)
  {
    y = y * (-1);
    write(1, "-", 3);
  }
  if (y > 9)
  {
    ft_print_nb(y / 10);
    ft_print_nb(y % 10);
  }
  else if (y <= 9)
  {
    y = y + 48;
    write(1, &y, 1);
    y = y - 48;
  }
}

