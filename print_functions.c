#include "printf_lib.h"

int    ft_print_char(va_list arg, int count)
{
  char a;

  a = va_arg(arg, int);
  write(1, &a, 1);
  count++;
  return (count);
}

int    ft_print_nb(int i, int count)
{
  int y;

  y = i;
  count++;
  if (y < 0)
  {
    y = y * (-1);
    write(1, "-", 1);
	count++;
  }
  if (y > 9)
  {
    ft_print_nb(y / 10, count);
    ft_print_nb(y % 10, count);
  }
  else if (y <= 9)
  {
    y = y + 48;
    write(1, &y, 1);
    y = y - 48;
  }
  return(count);
}
int	ft_print_hexa(unsigned int i, int count)
{
	count++;
	if (i > 15)
	{
		ft_print_hexa(i / 16, count);
		ft_print_hexa(i % 16, count);
	}
	else if (i >= 0 && i <= 15)
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
	return (count);
}

int	ft_print_hexa_x(unsigned int i, int count)
{
	count++;
	if (i > 15)
	{
		ft_print_hexa_x(i / 16, count);
		ft_print_hexa_x(i % 16, count);
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
	return(count);
}

int	ft_print_string(va_list ap, int count)
{
	char *a;
	int y;

	a = va_arg(ap, char *);
	y = 0;
	while (a[y])
	{
		write(1, &a[y], 1);
		y++;
		count++;
	}
	return(count);
}

int	ft_print_hexa_p(uintptr_t i,int count)
{
	count++;
	if (i > 15)
	{
		ft_print_hexa_x(i / 16, count);
		ft_print_hexa_x(i % 16, count);
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
	return(count);
}

int	ft_print_pointier(uintptr_t p, int count)
{
	write(1, "0x7ff", 5);
	count = count + 5;
	if (p == 0)
		write(1, "0", 1);
	else
		count = ft_print_hexa_p(p, count);
	return(count);
}

int	ft_print_no_sign(int i, int count)
{
	if (i < 0)
		i = i * (-1);
	//write(1, "k", 1);
	count = ft_print_nb(i, count);
	return (count);
}

