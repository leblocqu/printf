/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:12:23 by behaudeg          #+#    #+#             */
/*   Updated: 2020/01/08 15:37:33 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_print		*print;
	va_list		args;
	int			i;

	i = 0;
	print->str = format;
	if (!format || check_all_args(print) == -1)
		return (0);
	return (0);
}
