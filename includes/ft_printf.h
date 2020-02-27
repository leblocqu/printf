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

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_print
{
	const char	*str;
	int			nb_args;
}				t_print;

typedef struct s_flag
{
	char		letter_flag;
	int			flag[12];
}				t_flag;

int		ft_printf(const char *format, ...);
int		check_all_args(t_print *print);
int		check_args(t_print *print, char *arg);
int		count_args(const char *str);
int		init_args(const char *format, t_print *print);

#endif