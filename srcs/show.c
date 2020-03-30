#include "../includes/ft_printf.h"

int     show_args(t_print *print, t_flag *flag)
{
	if (flag[print->n].letter_flag == 's')
		return (ft_show_s(print, flag));
	if (flag[print->n].letter_flag == 'd'
		||flag[print->n].letter_flag == 'i')
		return (ft_show_d(print, flag));
	return (1);
}

int     show_all(t_print *print, t_flag *flag)
{
    int i;

	i = 0;
	while (print->str[i] != '\0')
	{
		if (print->str[i] != '%')
			ft_putchar(print->str[i]);
        else if (print->str[i] == '%' && print->str[i + 1] != '%')
		{
			if (show_args(print, flag) == -1)
				return (-1);
            while (check_val_type(print->str[i]) != 1)
                i++;
			print->n++;
		}
		else if (print->str[i] == '%' && print->str[i + 1] == '%')
        {
            ft_putstr("%%");
			i++;
        }
		i++;
	}
	return (1);
}