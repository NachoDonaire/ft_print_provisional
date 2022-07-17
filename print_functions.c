/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:30:09 by ndonaire          #+#    #+#             */
/*   Updated: 2022/04/01 09:48:33 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:30:06 by ndonaire          #+#    #+#             */
/*   Updated: 2022/04/01 09:30:06 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_char(va_list arg)
{
	char	a;

	a = va_arg(arg, int);
	write(1, &a, 1);
}

void	ft_print_nb(int i)
{
	int	y;

	y = i;
	if (y == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (y < 0)
	{
		y = y * (-1);
		write(1, "-", 1);
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

void	ft_print_hexa(unsigned int i)
{
	if (i > 15)
	{
		ft_print_hexa(i / 16);
		ft_print_hexa(i % 16);
	}
	else if (i <= 15)
	{
		if (i >= 10 && i <= 15)
		{
			i = i + 55;
			write(1, &i, 1);
			i = i - 55;
		}
		else
		{
			i = i + 48;
			write(1, &i, 1);
			i = i - 48;
		}
	}
}

void	ft_print_hexa_x(unsigned int i)
{
	if (i > 15)
	{
		ft_print_hexa_x(i / 16);
		ft_print_hexa_x(i % 16);
	}
	else if (i <= 15)
	{
		if (i >= 10 && i <= 15)
		{
			i = i + 87;
			write(1, &i, 1);
			i = i - 87;
		}
		else
		{
			i = i + 48;
			write(1, &i, 1);
			i = i - 48;
		}
	}
}

void	ft_print_string(char *a)
{
	int	y;

	y = 0;
	if (a == 0)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (a[y])
	{
		write(1, &a[y], 1);
		y++;
	}
}
