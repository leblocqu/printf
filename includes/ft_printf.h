/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:01:53 by leblocqu          #+#    #+#             */
/*   Updated: 2020/02/27 20:01:54 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flag
{
	char		letter_flag;
	int			flag[12];
}				t_flag;

typedef struct	s_print
{
	int			n;
	const char	*str;
	int			nb_args;
	va_list		args;
	t_flag		*all_flags;
}				t_print;

int		ft_printf(const char *format, ...);
int     init_flag(t_print *print, char *arg);
int		init_all(t_print *print);
int		check_init_args(t_print *print);
int		check_args(t_print *print, char *arg);
int		count_args(const char *str);
int		init_args(const char *format, t_print *print);
int     check_flags(t_print *print);

#endif