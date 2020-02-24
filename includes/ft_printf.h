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

# include "../libft/test/libft.h"
# include <stdarg.h>

typedef struct	s_print
{
	const char	*str;
	int			flag[12];
}				t_print;

int		ft_printf(const char *format, ...);
int		check_all_args(t_print *print);
int		check_args(t_print *print, char *arg);
int		count_args(const char *fomat);
int		init_args(const char *format, t_print *print);

#endif
