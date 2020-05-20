#include "../includes/ft_printf.h"

void    ft_f_moins(t_print *print, t_flag *flag, int len)
{
	if (flag[print->n].f_d < 0)
		ft_putchar('-');
	if (flag[print->n].f_d >= 0 && flag[print->n].flags[1] == 1)
	{
		ft_putchar('+');
		len++;
	}
	if (flag[print->n].flags[4] == 1 && flag[print->n].f_d >= 0)
	{
		ft_putchar(' ');
		len++;
	}
	ft_putdouble(positif_double(flag[print->n].f_d), flag[print->n].flags[7]);
	if (flag[print->n].flags[3] == 1 && flag[print->n].flags[7] == 0)
		ft_putchar('.');
	while (len < flag[print->n].flags[5])
	{
		ft_putchar(' ');
		len++;
	}
}

void	ft_f_wmoins(t_print *print, t_flag *flag, int len)
{
	if (flag[print->n].f_d >= 0)
	{
		if (flag[print->n].flags[1] == 1 && flag[print->n].flags[5] >= len)
			len++;
		if (flag[print->n].flags[4] == 1)
			len++;
	}
	if (flag[print->n].flags[3] == 1 && flag[print->n].flags[7] == 0)
		len++;
	while (flag[print->n].flags[5] > len)
	{
		ft_putchar(' ');
		len++;
	}
	if (flag[print->n].f_d >= 0)
	{
		if (flag[print->n].flags[1] == 1)
			ft_putchar('+');
		if (flag[print->n].flags[4] == 1)
			ft_putchar(' ');
	}
	if (flag[print->n].f_d < 0)
		ft_putchar('-');
	ft_putdouble(positif_double(flag[print->n].f_d), flag[print->n].flags[7]);
	if (flag[print->n].flags[3] == 1 && flag[print->n].flags[7] == 0)
		ft_putchar('.');
}

void	ft_f_wmoins_zero(t_print *print, t_flag *flag, int len)
{
	if (flag[print->n].f_d < 0)
		ft_putchar('-');
	if (flag[print->n].flags[3] == 1 && flag[print->n].flags[7] == 0)
		len++;
	if (flag[print->n].f_d >= 0)
	{
		if (flag[print->n].flags[1] == 1)
		{
			len++;
			ft_putchar('+');
		}
		if (flag[print->n].flags[4] == 1)
		{
			len++;
			ft_putchar(' ');
		}
	}
	while (flag[print->n].flags[5] > len)
	{
		ft_putchar('0');
		len++;
	}
	ft_putdouble(positif_double(flag[print->n].f_d), flag[print->n].flags[7]);
	if (flag[print->n].flags[3] == 1 && flag[print->n].flags[7] == 0)
		ft_putchar('.');
}

int     ft_f(t_print *print, t_flag *flag)
{
	int len;

	len = 0;
	if (flag[print->n].flags[12] == 1)
		flag[print->n].f_d = va_arg(print->args, long double);
	else
		flag[print->n].f_d = va_arg(print->args, double);
	if (flag[print->n].flags[6] == 0)
		flag[print->n].flags[7] = 6;
	len = ft_doublelen(flag[print->n].f_d, flag[print->n].flags[7], len);
	if (flag[print->n].flags[2] == 1)
		ft_f_moins(print, flag, len);
	else if (flag[print->n].flags[0] == 1)
		ft_f_wmoins_zero(print, flag, len);
	else
		ft_f_wmoins(print, flag, len);
	return (1);
}