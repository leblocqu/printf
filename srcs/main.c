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

	len = len_hexa(val);
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

int		main(void)
{
	printf("vrai printf:%o\n", -1);
	ft_printf("faux printf:%o\n", -1);
	return (0);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  