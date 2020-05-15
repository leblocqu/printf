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
	ft_putdouble(flag, print, flag[print->n].f_d);
	while (len < flag[print->n].flags[5])
	{
		ft_putchar(' ');
		len++;
	}
}

void	ft_f_wmoins_zero(t_print *print, t_flag *flag, int len)
{
	printf("test\n");
	if (flag[print->n].f_d >= 0)
	{
		if (flag[print->n].flags[1] == 1 && flag[print->n].flags[5] >= len)
		{
			len++;
			flag[print->n].flags[1] == 0;
		}
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
	ft_putdouble(flag, print, flag[print->n].f_d);
}

int     ft_f(t_print *print, t_flag *flag)
{
	int len;

	flag[print->n].f_d = va_arg(print->args, double);
	if (flag[print->n].flags[6] == 0)
		flag[print->n].flags[7] = 6;
	len = ft_doublelen(flag, print, flag[print->n].f_d, flag[print->n].flags[7]);
	printf("len = %d\n", len);
	if (flag[print->n].flags[2] == 1)
		ft_f_moins(print, flag, len);
	else
		ft_f_wmoins_zero(print, flag, len);
	/*else
		ft_o_wmoins(print, flag, len);*/
	return (1);
}