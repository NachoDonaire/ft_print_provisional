/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:22:05 by ndonaire          #+#    #+#             */
/*   Updated: 2022/04/01 09:48:57 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:22:03 by ndonaire          #+#    #+#             */
/*   Updated: 2022/04/01 09:22:03 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_hexa_p(unsigned int long i)
{
	if (i > 15)
	{
		ft_print_hexa_p(i / 16);
		ft_print_hexa_p(i % 16);
	}
	else if (i >= 0 && i <= 15)
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

void	ft_print_pointier(void *p)
{
	write(1, "0x", 2);
	if (p == 0)
		write(1, "0", 1);
	else
		ft_print_hexa_p((unsigned int long)p);
}

static int	len(unsigned long int i)
{
	int	y;

	y = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / 10;
		y++;
	}
	return (y);
}

char	*aitoa(unsigned long int i)
{
	int		w;
	char	*sol;
	int		rest;

	w = len(i);
	rest = 0;
	sol = malloc((w + 1) * sizeof(char));
	sol[w] = '\0';
	w--;
	while (w >= 0)
	{
		rest = i % 10;
		sol[w] = rest + 48;
		w--;
		i = i / 10;
	}
	return (sol);
}

void	ft_print_no_sign(unsigned int i)
{
	char	*s;
	int		y;

	y = 0;
	s = aitoa((unsigned long int)i);
	while (s[y])
	{
		write(1, &s[y], 1);
		y++;
	}
	free(s);
}
