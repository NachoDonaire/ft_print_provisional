#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct s_sc
{
  int   len;
  int   width;
}t_sc;

t_sc    *ft_initialise_tab(t_sc *tab)
{
  tab -> len = 0;
  tab -> width = 0;
  return (tab);
}

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

 
int ft_eval_format(const char *s, int i, va_list arg, t_sc *tab)
{
  if (s[i] == 'c')
    ft_print_char(arg, tab);
  else if (s[i] == 'd')
    ft_print_nb(va_arg(arg, int));
  i++;
  return (i);
}

int ft_eval_next(const char *s, int i, t_sc *tab)
{
  int y;
  y = i;
  while (s[i] != 'c' && s[i] != 'd')
  {
    if (s[i] == '*')
      tab -> width = 1;
    i++;
  }
  if (y == i)
    return (i);
  return (i);
}


int ft_printf(const char *s, ...)
{
  t_sc *tab;
  va_list arg;
  va_start(arg, s);
  int i;

  i = 0;
  tab = (t_sc *)malloc(sizeof(t_sc));
  if (!tab)
    return (-1);
  tab = ft_initialise_tab(tab);
  while (s[i])
  {
    if (s[i] == '%')
    {
      i = ft_eval_next(s, i + 1, tab);
      i = ft_eval_format(s, i, arg, tab);
    }
    if (s[i])
    {
      write(1, &s[i], 1);
      i++;
    }
  }
  return (i);
}


int main()
{
  char a = 'x';
 int d = 242;
 ft_printf("hola: %d\n chr: %c",d, a);
  return (0);
}
