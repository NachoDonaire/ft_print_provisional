/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:13:52 by ndonaire          #+#    #+#             */
/*   Updated: 2022/04/01 09:48:13 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"

int	ft_eval_format(const char *s, int i, va_list arg)
{
	if (s[i] == 'c')
		ft_print_char(arg);
	else if (s[i] == 'i' || s[i] == 'd')
		ft_print_nb(va_arg(arg, int));
	else if (s[i] == 'x')
		ft_print_hexa_x(va_arg(arg, int));
	else if (s[i] == 'X')
		ft_print_hexa(va_arg(arg, unsigned int));
	else if (s[i] == 's')
		ft_print_string(va_arg(arg, char *));
	else if (s[i] == 'p')
		ft_print_pointier(va_arg(arg, void *));
	else if (s[i] == '%')
		write(1, "%", 1);
	else if (s[i] == 'u')
		ft_print_no_sign(va_arg(arg, unsigned int));
	i++;
	return (i);
}

int	ft_eval_format_count(const char *s, int i, va_list dest, int count)
{
	if (s[i] == 'c')
		count = ft_print_char_c(dest, count);
	else if (s[i] == 'i' || s[i] == 'd')
		count = ft_print_nb_c(va_arg(dest, int), count);
	else if (s[i] == 'x')
		count = ft_print_hexa_c(va_arg(dest, unsigned int), count);
	else if (s[i] == 'X')
		count = ft_print_hexa_c(va_arg(dest, int), count);
	else if (s[i] == 's')
		count = ft_print_string_c(va_arg(dest, char *), count);
	else if (s[i] == 'p')
		count = ft_print_hexa_p_c(dest, count);
	else if (s[i] == '%')
	{
		count++;
	}
	else if (s[i] == 'u')
		count = aitoa_c(va_arg(dest, unsigned long int), count);
	i++;
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	va_list	dest;
	int		i;
	int		count;

	va_start(arg, s);
	va_copy(dest, arg);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			count = ft_eval_format_count(s, i + 1, dest, count);
			i = ft_eval_format(s, i + 1, arg);
		}
		if (s[i] && s[i] != '%')
		{
			write(1, &s[i], 1);
			i++;
			count++;
		}
	}
	return (count);
}

/*
int main()
{
	//printf("%d\n", ft_printf("- %p  - %x %X %%",(void *)-1, 200000000, 20));
	//printf("%d", printf("- %p  - %x %X %%", (void *)-1, 200000000, 20));
	//ft_printf("%c*\n", '1');
	//char *empty_string = 0;
	//printf("*%s*", empty_string);
	//ft_printf("*holaaa:%s*holaa", empty_string);
	printf("%u\n", (unsigned int)3147983649);
	ft_printf("%u",(unsigned int)3147983649);
	//char *s;
	//s = aitoa((unsigned long int)3147983649);
//	printf("%s", s);
	//printf("%s", ft_itoa((long int)3147983649));
	return (0);
}*/
/*
int main()
{
  //char a = 'x';
//int d = -2345;
 int x = -23;
 //int hex = 234;
 //char s[67] = "prueba";
 int *p;
 p = &x;
 int ft = ft_printf("hola %p ee\n", p);
 int tf = printf("hola %p ee\n", p);
printf("ft: %d, tf: %d", ft, tf);
  return (0);
}*/
