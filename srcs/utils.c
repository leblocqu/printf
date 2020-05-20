/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:06:54 by leblocqu          #+#    #+#             */
/*   Updated: 2020/02/27 20:06:55 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_numlen(int n)
{
	if (n == -2147483648)
		return (11);
	if (n < 0)
		return (ft_numlen(n * -1) + 1);
	if (n >= 10)
		return (ft_numlen(n / 10) + 1);
	return (1);
}

long long int		ft_pow(int nb, int power)
{
	int					cpt;
	long long int		value;

	cpt = 1;
	value = nb;
	if (power > 0)
		while (cpt++ < power)
			value = value * nb;
	else
	{
		if (power == 0)
			value = 1;
		else
			value = 0;
	}
	return (value);
}

int		ft_ui_numlen(unsigned int n)
{
	if (n >= 10)
		return (ft_numlen(n / 10) + 1);
	return (1);
}

int		positif(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);	
}

double	positif_double(double nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);	
}

int		len_hexa(unsigned long long val)
{
	int res;

	res = 0;
	if (val == 0)
		return (1);
	while (val != 0)
	{
		res++;
		val = val / 16;
	}
	return (res);
}

char	*ft_conv_hexa(unsigned long long val, int indice)
{
	char			*conv_min;
	char			*conv_maj;
	char			*res;
	int				len;

	conv_min = "0123456789abcdef";
	conv_maj = "0123456789ABCDEF";
	len = len_hexa(val);
	if (val == 0)
		return ("0");
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	res[len] = '\0';
	len--;
	while(val != 0)
	{
		if (indice == 1)
			res[len] = conv_min[val % 16];
		if (indice == 2)
			res[len] = conv_maj[val % 16];
		val = val / 16;
		len--;
	}
	return (res);
}

char	*ft_conv_octal(unsigned int val)
{
	char			*res;
	int				len;

	len = len_octal(val);
	if (val == 0)
		return ("0");
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	res[len] = '\0';
	len--;
	while(val != 0)
	{
		res[len] = (val % 8) + '0';
		val = val / 8;
		len--;
	}
	return (res);
}

int		len_octal(unsigned int val)
{
	int res;

	res = 0;
	if (val == 0)
		return (1);
	while (val != 0)
	{
		res++;
		val = val / 8;
	}
	return (res);
}

long		calcul_retenue(double nb)
{
	if (nb >= 0)
		return ((int)((nb)+0.4));
	else
		return ((int)((nb)-0.4));
}


void	ft_putdouble(double n, int precision)
{
	int		i;
	int		firstp;
	double	secondp;
	double	precision_adder;

	firstp = (int)n;
	secondp = (double)(n - firstp) * (n < 0 ? -1 : 1);
	if (precision == 0)
	{
		ft_putnbr(calcul_retenue(n));
		return ;
	}
	ft_putnbr(firstp);
	if (precision > 0)
	{
		ft_putchar('.');
		precision_adder = 0.1;
		i = 0;
		while (i++ < precision)
			precision_adder /= 10;
		secondp += precision_adder * 5;
		while (--i)
		{
			ft_putnbr((int)(secondp *= 10));
			firstp = (int)secondp;
			secondp -= (double)firstp;
		}
	}
}

int		ft_doublelen(double n, int precision, int len)
{
	int		i;
	int		firstp;
	double	secondp;
	double	precision_adder;

	firstp = (int)n;
	secondp = (double)(n - firstp) * (n < 0 ? -1 : 1);
	if (precision == 0)
	{
		len += ft_numlen(calcul_retenue(n));
		return (len);
	}
	len += ft_numlen(firstp);
	if (precision > 0)
	{
		len++;
		precision_adder = 0.1;
		i = 0;
		while (i++ < precision)
			precision_adder /= 10;
		secondp += precision_adder * 5;
		while (--i)
		{
			len++;
			firstp = (int)secondp;
			secondp -= (double)firstp;
		}
	}
	return (len);
}

// int		main(void)
// {
// 	int f = 0;
// 	printf("vrai printf:%-+.0d\t\n", f);
// 	ft_printf("faux printf:%-+.0d\t\n", f);
// 	return (0);
// }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      