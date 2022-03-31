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
int    ft_print_char(va_list arg, int count);
int    ft_print_nb(int i, int count);
void    ft_aply_width(va_list dest, va_list arg);
int		ft_print_hexa(unsigned int i, int count);
int		ft_print_hexa_x(unsigned int i, int count);
int		ft_print_string(va_list ap, int count);
int		ft_print_hexa(unsigned int i, int count);
int		ft_print_pointier(uintptr_t p, int count);
int		ft_print_hexa_p(uintptr_t i, int  count);
int		ft_print_no_sign(int i, int count);

#endif
