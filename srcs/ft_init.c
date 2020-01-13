/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 14:29:51 by behaudeg          #+#    #+#             */
/*   Updated: 2020/01/13 09:45:24 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_is_space(const char *format, int i)
{
	if (format[i] == '\f' || format[i] == '\t' || format[i] == '\n'
		|| format[i] == '\r' || format[i] == '\v' || format[i] == '\0')
		return (1);
	return (0);
}

int		init_tab_args(const char *format, t_print *print, int nb)
{
	int i;
	int j;
	int k;
	int	len;
	int	tmp;

	i = 0;
	j = 0;
	k = 0;
	len = 0;
	tmp = 0;
	char **res;
	res = (char**)malloc(sizeof(char *) * nb + 1);
	print->args = res;
	printf("segfot\n");
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			while(format[i] == '%')
				i++;
		}
		if (format[i] == '%' && format[i + 1] != '%')
		{
			tmp = i + 1;
			while (ft_is_space(format, i) != 1)
			{	
				len++;
				i++;
			}
			if(!(print->args[j] = (char *)malloc(sizeof(char) * len + 1)))
				return (0);
			print->args[j][len] = '\0';
			while (print->args[j][k])
			{
				print->args[j][k] = tmp;
				tmp++;
				k++;
			}
			nb++;
			len = 0;
			k = 0;
		}
		j++;
		i++;
	}
	return (1);
}

int			count_args(const char *format)
{
	int i;
	int	nb;

	i = 0;
	nb = 0;
	while(format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			while(format[i] == '%')
				i++;
		}
		if (format[i] == '%' && format[i + 1] != '%')
			nb++;
		i++;
	}
	return (nb);
}

int			init_args(const char *format, t_print *print)
{
	init_tab_args(format, print, count_args(format));
	return (1);
}