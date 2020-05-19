#include "../includes/ft_printf.h"

void    ft_f_moins(t_print *print, t_flag *flag, int len)
{
	if (flag[print->n].f_d >= 0 && flag[print->n].flags[1] == 1)
	{
		ft_putchar('+');
		len++;
	}
	if (flag[print->n].flags[4] == 1)
	{
		ft_putchar(' ');
		len++;
	}
	ft_putdouble(flag[print->n].f_d, flag[print->n].flags[7]);
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
	ft_putdouble(flag[print->n].f_d, flag[print->n].flags[7]);
}

void	ft_f_wmoins_zero(t_print *print, t_flag *flag, int len)
{
	if (flag[print->n].f_d >= 0)
	{
		if (flag[print->n].flags[1] == 1 && flag[print->n].flags[5] >= len)
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
	ft_putdouble(flag[print->n].f_d, flag[print->n].flags[7]);
}

int     ft_f(t_print *print, t_flag *flag)
{
	int len;

	len = 0;
	flag[print->n].f_d = va_arg(print->args, double);
	if (flag[print->n].flags[6] == 0)
		flag[print->n].flags[7] = 6;
	len = ft_doublelen(flag[print->n].f_d, flag[print->n].flags[7], len);
	//printf("len = %d\n", len);
	if (flag[print->n].f_d < 0)
	{
		len++;
		ft_putchar('-');
	}
	if (flag[print->n].flags[2] == 1)
		ft_f_moins(print, flag, len);
	else if (flag[print->n].flags[0] == 1)
		ft_f_wmoins_zero(print, flag, len);
	else
		ft_f_wmoins(print, flag, len);
	return (1);
}