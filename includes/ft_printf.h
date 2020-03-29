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
	int			flags[13];
}				t_flag;

typedef struct	s_print
{
	char		*arg_i;
	int			n;
	const char	*str;
	int			nb_args;
	int			ret;
	va_list		args;
}				t_print;

int		ft_printf(const char *format, ...);
int		check_val_type(char c);
int     init_flag(t_print *print, t_flag *flag);
int		init_all(t_print *print, t_flag *flag);
int		check_init_args(t_print *print, t_flag *flag);
int		check_args(t_print *print, t_flag *flag);
int		count_args(const char *str);
int		init_args(const char *format, t_print *print);
int     check_flags(t_print *print, t_flag *flag);
int		init_width(t_print *print, t_flag *flag);
int     init_size(t_print *print, t_flag *flag);
int     check_size(t_print *print, t_flag *flag);
int     init_precision(t_print *print, t_flag *flag);
int     init_type(t_print *print, t_flag *flag);
int     show_all(t_print *print, t_flag *flag);
int     show_args(t_print *print, t_flag *flag);
int     ft_show_s(t_print *print, t_flag *flag);

#endif