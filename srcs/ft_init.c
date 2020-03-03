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
	if (c != 'c' && c != 's' && c != 'p' && c != 'd' && c != 'i' && c != 'o' && c != 'u' && c != 'x' && c != 'X')
		return (0);
	else
		return (1);
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
	while (check_val_type(arg[i]) == 0)
	{
		if (init_flag(print, (char *)&arg[i]) == -1)
			return (-1);
	// 	if (check_width((char *)&arg[i], print) == -1)
	// 		return (-1);
	// 	if (check_precision((char *)&arg[i], print) == -1)
	// 		return (-1);
	//	if (check_size((char *)&arg[i], print) == -1)
	//		return (-1);
	}
	return (1);
}

int		check_init_args(t_print *print)
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
			print->n++;
		}
		i++;
	}
	return (1);
}

void	set_tab(t_print *print)
{
	int i;
	int j;

	i = print->nb_args;
	i--;
	j = 0;
	while (i >= 0)
	{
		while(print->all_flags[i].flag[j])
		{	
			print->all_flags[i].flag[j] = 0;
			j++;
		}
		i--;
	}
}

void	aff_tab(t_print *print)
{
	int i;
	int j;

	i = print->nb_args;
	i--;
	j = 0;
	while (i >= 0)
	{
		while(print->all_flags[i].flag[j])
		{	
			printf("test1\n");
			printf("%d", print->all_flags[i].flag[j]);
			j++;
		}
		printf("\n");
		i--;
	}
}

int		init_all(t_print *print)
{
	print->n = 0;
	print->nb_args = count_args(print->str);
	if (!(print->all_flags = malloc(sizeof(t_flag) * print->nb_args)))
	{
		ft_putstr("Error Malloc\n");
		return (-1);
	}
	set_tab(print);
	aff_tab(print);
	if (check_init_args(print) == -1)
		return (-1);
	return (1);
}
