#ifndef PRINTF_LIB
#define PRINTF_LIB
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_sc
{
  int   len;
  int   width;
}t_sc;
void    ft_print_char(va_list arg, t_sc *tab);
void    ft_print_nb(int i);
void    ft_aply_width(va_list dest, va_list arg);


#endif
