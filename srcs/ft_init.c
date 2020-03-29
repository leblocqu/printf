/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:06:15 by leblocqu          #+#    #+#             */
/*   Updated: 2020/02/27 20:06:17 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_val_type(char c)
{
	if (c != 'c' && c != 's' && c != 'p' && c != 'd' && c != 'i' && c != 'o' && c != 'u' && c != 'x' && c != 'X' && c != 'f')
		return (0);
	else
		return (1);
}

int		check_args(t_print *print, t_flag *flag)
{
	int i;

	i = 0;
	if (print->arg_i[i] == '\0')
	{
		ft_putstr("There is a '%' without params.\n");
		return (-1);
	}
	while (check_val_type(print->arg_i[i]) == 0)
	{
		if (init_flag(print, flag) == -1)
			return (-1);
	 	if (init_width(print, flag) == -1)
	 		return (-1);
	 	if (init_precision(print, flag) == -1)
			return (-1);
		if (init_size(print, flag) == -1)
			return (-1);
	}
	if (init_type(print, flag) == -1)
		return (-1);
	return (1);
}

int		check_init_args(t_print *print, t_flag *flag)
{
	int i;

	i = 0;
	while (print->str[i] != '\0')
	{
		if (print->str[i] == '%' && print->str[i + 1] == '%')
			i++;
		else if (print->str[i] == '%' && print->str[i + 1] != '%')
		{
			print->arg_i = (char *)&print->str[i + 1];
			if (check_args(print, flag) == -1)
				return (-1);
			print->n++;
		}
		i++;
	}
	print->n = 0;
	return (1);
}

void	set_tab(t_print *print, t_flag *flag)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < print->nb_args)
	{
		while(j < 13)
		{	
			flag[i].flags[j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
}

void	aff_tab(t_print *print, t_flag *flag)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < print->nb_args)
	{
		while(j < 13)
		{	
			printf("%d", flag[i].flags[j]);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
}

int		init_all(t_print *print, t_flag *flag)
{
	print->n = 0;
	set_tab(print, flag);
	if (check_init_args(print, flag) == -1)
		return (-1);
	return (show_all(print, flag));
	return (1);
}
