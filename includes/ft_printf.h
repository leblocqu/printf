/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 14:16:15 by behaudeg          #+#    #+#             */
/*   Updated: 2020/01/10 14:16:17 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/libft.h"

typedef struct	s_print
{
	char	**args;
}				t_print;

int		ft_printf(const char *format, ...);
int		count_args(const char *fomat);
int		init_args(const char *format, t_print *print);

#endif
