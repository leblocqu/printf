#include "../includes/ft_printf.h"

void	ft_u_wmoins(t_print *print, t_flag *flag, int len)
{
	if (len < flag[print->n].flags[7])
		len = flag[print->n].flags[7];
	while (len < flag[print->n].flags[5])
	{
		ft_putchar(' ');
		flag[print->n].flags[5]--;
	}
	while (len > ft_ui_numlen(flag[print->n].u_int))
	{
		ft_putchar('0');
		len--;
	}
	ft_ui_putnbr(flag[print->n].u_int);
}

void	ft_u_moins(t_print *print, t_flag *flag, int len)
{
	while (len < flag[print->n].flags[7])
	{
		ft_putchar('0');
		len++;
	}
	ft_ui_putnbr(flag[print->n].u_int);
	while (len < flag[print->n].flags[5])
	{
		ft_putchar(' ');
		len++;
	}
}

int		ft_u(t_print *print, t_flag *flag)
{
	int len;

	flag[print->n].u_int = va_arg(print->args, unsigned int);
	if (flag[print->n].u_int == 0)
		len = 1;
	else
		len = ft_ui_numlen(flag[print->n].u_int);
	if (flag[print->n].flags[2] == 1)
		ft_u_moins(print, flag, len);
	else
		ft_u_wmoins(print, flag, len);
	return (1);
}