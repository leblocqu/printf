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
	if (n < 0)
		return (ft_numlen(n * -1) + 1);
	if (n >= 10)
		return (ft_numlen(n / 10) + 1);
	return (1);
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

int		len_hexa(unsigned int val)
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

char	*ft_conv_hexa(unsigned int val, int indice)
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
		return ((int)((nb)+0.5));
	else
		return ((int)((nb)-0.5));
}

void	ft_putlong(long int n)
{
	int i;
	int arr[22];

	i = 0;
	if (n == 0)
		ft_putchar('0');
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -9223372036854775807)
		{
			ft_putchar('9');
			n = -223372036854775807;
		}
		n *= -1;
	}
	while (n)
	{
		arr[i] = n % 10;
		n /= 10;
		i++;
	}
	i--;
	while (i >= 0)
		ft_putchar(arr[i--] + '0');
}


void	ft_putdouble(t_flag *flag, t_print *print, long double d)
{
	if (flag[print->n].flags[7] == 0)
	{
		ft_putlong((long)calcul_retenue(d));
		if (flag[print->n].flags[3] == 1)
			ft_putchar('.');
		return ;
	}
	ft_putlong((long)d);
	d -= (long)d;
	if (d < 0)
		d *= -1;
	ft_putchar('.');
	while (flag[print->n].flags[7]-- >= 0)
	{
		d *= 10;
		if (flag[print->n].flags[7] == -1)
			if (((long)d % 10) > 4)
				d += 10;
	}
	d /= 10;
	ft_putlong((long)d);
}

int		ft_longlen(t_print *print, t_flag *flag, int len, long int n)
{
	int i;

	i = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		len++;
		if (n == -9223372036854775807)
		{
			len += 19;
			n = -223372036854775807;
		}
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		len++;
		i--;
	}
	return (len);
}


int		ft_doublelen(t_flag *flag, t_print *print, long double d, int precision)
{
	int len;

	len = 0;
	if (precision == 0)
	{
		len = ft_longlen(print, flag, len, (long)calcul_retenue(d));
		if (flag[print->n].flags[3] == 1)
			len++;
		return (len);
	}
	len = ft_longlen(print, flag, len, (long)d);
	d -= (long)d;
	if (d < 0)
		d *= -1;
	len++;
	while (precision-- >= 0)
	{
		d *= 10;
		if (precision == -1)
			if (((long)d % 10) > 4)
				d += 10;
	}
	d /= 10;
	len = ft_longlen(print, flag, len, (long)d);
	return (len);
}

int		main(void)
{
	double test;

	test = -22.5687;
	// printf("str = %s\n", ft_ldtoa(test, 6));
	printf("vrai printf:%+4.3f\n", test);
	// printf("vrai printf:% d\n", 42);
	ft_printf("faux printf:%+4.3f\n", test);
	//ft_printf("faux printf:%.5f\n", 42.5);
	return (0);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  