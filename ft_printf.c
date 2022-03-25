#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "printf_lib.h"

t_sc    *ft_initialise_tab(t_sc *tab)
{
  tab -> len = 0;
  tab -> width = 0;
  return (tab);
}

int ft_eval_format(const char *s, int i, va_list arg, t_sc *tab)
{
  if (s[i] == 'c')
    ft_print_char(arg, tab);
  else if (s[i] == 'd')
  {
    ft_print_nb(va_arg(arg, int));
  }
  i++;
  return (i);
}

void    ft_flags(t_sc *tab, va_list dest, va_list arg)
{
  if (tab -> width == 1)
    ft_aply_width(dest, arg);
}

int ft_eval_next(const char *s, int i, t_sc *tab)
{
  while (s[i] != 'c' && s[i] != 'd')
  {
    if (s[i] == '*')
      tab -> width = 1;
    i++;
  }
  return (i);
}


int ft_printf(const char *s, ...)
{
  t_sc *tab;
  va_list arg;
  va_list dest;
  va_start(arg, s);
  va_copy(dest, arg);
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
      ft_flags(tab, dest, arg);
      i = ft_eval_format(s, i, arg, tab);
    }
    tab = ft_initialise_tab(tab);
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
 int x = 23;
 ft_printf("nb: %*d\nchr: %c\notro_nb: %*d\n",5,d, a,5, x);
 printf("nb: %*d\nchr: %c\notro_nb: %*d\n",5,d, a,5, x);


  return (0);
}
