/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:38:08 by ndonaire          #+#    #+#             */
/*   Updated: 2022/04/01 09:49:30 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_no_sign_c(int i, int count)
{
	if (i == -2147483648)
	{
		count = count + 10;
		return (count);
	}
	if (i < 0)
		i = i * (-1);
	count = ft_print_nb_c(i, count);
	return (count);
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

int	aitoa_c(unsigned long int i, int count)
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
		count++;
	}
	free(sol);
	return (count);
}
