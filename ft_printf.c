#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "printf_lib.h"
/*
t_sc    *ft_initialise_tab(t_sc *tab)
{
  tab -> len = 0;
  tab -> width = 0;
  return (tab);
}*/

int ft_eval_format(const char *s, int i, va_list arg, int count)
{
  if (s[i] == 'c')
	  count = ft_print_char(arg, count);
  else if (s[i] == 'i' || s[i] == 'd')
	  count =ft_print_nb(va_arg(arg, int), count);
  else if(s[i] == 'x')
	  count =ft_print_hexa_x(va_arg(arg, int), count);
  else if(s[i] == 'X')
	  count = ft_print_hexa(va_arg(arg, int), count);
  else if (s[i] == 's')
	  count = ft_print_string(arg, count);
  else if (s[i] == 'p')
	  count = ft_print_pointier(va_arg(arg, uintptr_t), count);
  else if (s[i] == '%')
  {
	  count ++;
	  write(1, "%", 1);
  }
  else if (s[i] == 'u')
	  count = ft_print_no_sign(va_arg(arg, int), count);
  i++;
  return (i);
}
/*
int ft_eval_format_count(const char *s, int i, va_list arg, int count)
{
  if (s[i] == 'c')
	  count = ft_print_char(arg, count);
  else if (s[i] == 'i' || s[i] == 'd')
	  count =ft_print_nb(va_arg(arg, int), count);
  else if(s[i] == 'x')
	  count =ft_print_hexa_x(va_arg(arg, int), count);
  else if(s[i] == 'X')
	  count = ft_print_hexa(va_arg(arg, int), count);
  else if (s[i] == 's')
	  count = ft_print_string(arg, count);
  else if (s[i] == 'p')
	  count = ft_print_pointier(va_arg(arg, uintptr_t), count);
  else if (s[i] == '%')
  {
	  count ++;
	  write(1, "%", 1);
  }
  else if (s[i] == 'u')
	  count = ft_print_no_sign(va_arg(arg, int), count);
  i++;
  return (count);
}

void    ft_flags(t_sc *tab, va_list dest, va_list arg)
{
  if (tab -> width == 1)
    ft_aply_width(dest, arg);
}

int ft_eval_next(const char *s, int i, t_sc *tab)

else if(s[i] == 'x')
ft_print_hexa(va_arg(arg, int));{
  while (s[i] != 'c' && s[i] != 'd')
  {
    if (s[i] == '*')
      tab -> width = 1;
    i++;
  }
  return (i);
}
*/

int ft_printf(const char *s, ...)
{
  //t_sc *tab;
  va_list arg;
  //va_list dest;
  va_start(arg, s);
  //va_copy(dest, arg);
  int i;
  int count;

  i = 0;
  count = 0;
 /* tab = (t_sc *)malloc(sizeof(t_sc));
  if (!tab)
    return (-1);
  tab = ft_initialise_tab(tab);*/
  while (s[i])
  {
    if (s[i] == '%')
    {
      //i = ft_eval_next(s, i + 1, tab);
     // ft_flags(tab, dest, arg);
	 //count = ft_eval_format_count(s, i + 1, arg, count);
      i = ft_eval_format(s, i + 1, arg, count);
    }
    //tab = ft_initialise_tab(tab);
    if (s[i])
    {
      write(1, &s[i], 1);
      i++;
	  count++;
    }
  }
  return (count);
}


int main()
{
  //char a = 'x';
int d = 2;
 //int x = -23;
 //int hex = 234;
 //char s[67] = "prueba";
 //int *p;
 //p = &x;
 int ft = ft_printf("nb:%d \n", d);
 int tf = printf("nb:%d \n", d);
printf("ft: %d, tf: %d", ft, tf);
  return (0);
}
