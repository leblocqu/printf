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
# include <time.h>
# include <limits.h>

typedef struct s_flag
{
	char			letter_flag;
	int				flags[13];
	int				nb_int;
	unsigned int	u_int;
	unsigned long long l_l;
	double			f_d;
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
int     check_precision(t_print *print, t_flag *flag);
int     init_type(t_print *print, t_flag *flag);
int     show_all(t_print *print, t_flag *flag);
int     show_args(t_print *print, t_flag *flag);
int     ft_s(t_print *print, t_flag *flag);
int     ft_d(t_print *print, t_flag *flag);
int		ft_numlen(int n);
int		positif(int nb);
int		ft_c(t_print *print, t_flag *flag);
void    ft_d_0(t_print *print, t_flag *flag);
int		ft_x(t_print *print, t_flag *flag);
char	*ft_conv_hexa(unsigned long long val, int indice);
int		len_hexa(unsigned long long val);
int     ft_u(t_print *print, t_flag *flag);
void    ft_x_zero(t_print *print, t_flag *flag, int len, int indice);
void    ft_x_wmoins(t_print *print, t_flag *flag, int len, int indice);
void    ft_x_moins(t_print *print, t_flag *flag, int len, int indice);
void    ft_u_moins(t_print *print, t_flag *flag, int len);
int		ft_ui_numlen(unsigned int n);
int     ft_o(t_print *print, t_flag *flag);
char	*ft_conv_octal(unsigned int val);
int		len_octal(unsigned int val);
int     ft_f(t_print *print, t_flag *flag);
void	ft_putdouble(double d, int precision);
int		ft_doublelen(double n, int precision, int len);
int		ft_longlen( int len, long int n);
int     ft_p(t_print *print, t_flag *flag);

#endif