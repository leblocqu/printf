/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:57:11 by leblocqu          #+#    #+#             */
/*   Updated: 2020/02/27 19:57:13 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		count_args(const char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '%')
			i += 2;
		else if (str[i] == '%' && str[i + 1] != '%')
		{	
			res++;
			i++;
		}
		else
			i++;
	}
	return (res);
}

int		ft_printf(const char *format, ...)
{
	t_print		*print;
	va_list		args;
	int			i;

	i = 0;
	print->str = format;
	print->nb_args = count_args(print->str);
	printf("nb args = %d\n", print->nb_args);
	if (!format || check_all_args(print) == -1)
		return (0);
	return (0);
}