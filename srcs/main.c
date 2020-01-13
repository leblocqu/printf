/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 14:56:14 by behaudeg          #+#    #+#             */
/*   Updated: 2020/01/10 14:56:16 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

/*void	aff_tab(t_print print)
{

}*/

int		main(int argc, char **argv)
{
	(void)argc;
	const char *str;

	str = (const char *)argv[1];
	ft_printf(str);
	return (0);
}
