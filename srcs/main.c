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

int		positif(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);	
}

int		main(void)
{
	// int *p;
	// int a = 42;

	// p = &a;
	// intptr_t addr = (intptr_t)&a;
	// ft_putnbr(addr);
	printf("vrai printf:%0.7d\n", 42);
	//ft_printf("faux printf:%-+2.2d\n", 42);
	return (0);
}
