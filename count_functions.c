/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:41:33 by ndonaire          #+#    #+#             */
/*   Updated: 2022/04/01 09:49:16 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_char_c(va_list arg, int count)
{
	char	a;

	a = va_arg(arg, int);
	count++;
	if (!a)
		return (count);
	return (count);
}

int	ft_print_nb_c(int y, int count)
{
	if (y == -2147483648)
	{
		count = count + 11;
		return (count);
	}	
	if (y < 0)
	{
		y = y * (-1);
		count++;
	}
	else if (y == 0)
		count++;
	while (y > 0)
	{
		y = y / 10;
		count++;
	}
	return (count);
}

int	ft_print_hexa_c(unsigned int i, int count)
{
	if (i == 0)
		count++;
	while (i > 0)
	{
		i = i / 16;
		count++;
	}
	return (count);
}

int	ft_print_string_c(char *a, int count)
{
	int	y;

	y = 0;
	if (a == NULL)
	{
		count = count + 6;
		return (count);
	}
	while (a[y])
	{
		y++;
		count++;
	}
	return (count);
}

int	ft_print_hexa_p_c(va_list dest, int count)
{
	unsigned int long	y;

	y = (unsigned int long)va_arg(dest, void *);
	while (y > 15)
	{
		y = y / 16;
		count++;
	}
	count = count + 3;
	return (count);
}
