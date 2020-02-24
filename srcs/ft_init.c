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

int		check_val_type(char c)
{
	if (c != 'c' && c != 's' && c != 'p' && c != 'd' && c != 'i' && c != 'o' && c != 'u' && c != 'x' && c != 'X')
		return (1);
	else
		return (0);
}

int		check_args(t_print *print, char *arg)
{
	int i;

	i = 0;
	if (arg[i] == '\0')
	{
		ft_putstr("Erreur à écrire\n");
		return (-1);
	}
	while (check_val_type(arg[i]) == 1)
	{
		if (check_flag((char *)&arg[i], print) == -1)
			return (-1);
		if (check_width((char *)&arg[i], print) == -1)
			return (-1);
		if (check_precision((char *)&arg[i], print) == -1)
			return (-1);
		
	}
	return (1);
}

int		check_all_args(t_print *print)
{
	int i;

	i = 0;
	while (print->str[i] != '\0')
	{
		if (print->str[i] == '%' && print->str[i + 1] == '%')
			i++;
		else if (print->str[i] == '%' && print->str[i + 1] != '%')
		{
			if (check_args(print, (char *)&print->str[i + 1]) == -1)
				return (-1);
		}
		i++;
	}
	return (1);
}