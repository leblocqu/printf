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
	t_print print;
	t_flag *flag;

	ft_bzero(&print, sizeof(t_print));
	va_start(print.args, format);
	print.str = format;
	print.nb_args = count_args(print.str);
	flag = ft_memalloc(sizeof(t_flag) * (print.nb_args));
	if (!format || init_all(&print, flag) == -1)
		return (0); //Pas oublier de free la.
	va_end(print.args);
	return (0); // Et la aussi.
}