/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:42:56 by ndonaire          #+#    #+#             */
/*   Updated: 2022/04/01 09:49:58 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF
# define LIBFTPRINTF
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdarg.h>

int		ft_eval_format(const char *s, int i, va_list arg);
int		ft_eval_format_count(const char *s, int i, va_list dest, int count);
int		ft_print(const char *s, ...);
void	ft_print_char(va_list arg);
void	ft_print_nb(int i);
void	ft_aply_width(va_list dest, va_list arg);
void	ft_print_hexa(unsigned int i);
void	ft_print_hexa_x(unsigned int i);
void	ft_print_string(char *a);
void	ft_print_hexa(unsigned int i);
void	ft_print_hexa_p(unsigned int long i);
void	ft_print_pointier(void *p);
void	ft_print_no_sign(unsigned  int i);
char	*ft_itoa(long int n);
char	*aitoa(unsigned long int i);
int		ft_print_hexa_c(unsigned int i, int count);
int		ft_print_hexa_x_c(unsigned int i, int count);
int		ft_print_string_c(char *a, int count);
int		ft_print_pointier_c(void  *p, int count);
int		ft_print_hexa_p_c(va_list dest, int  count);
int		ft_print_no_sign_c(int i, int count);
int		ft_print_char_c(va_list arg, int count);
int		ft_print_nb_c(int y, int count);
void	ft_print_unsigned(int i);
int		pot(int base, int exp);
int		aitoa_c(unsigned long int i, int count);


#endif
