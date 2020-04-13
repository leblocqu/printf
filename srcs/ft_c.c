#include "../includes/ft_printf.h"

int     ft_c(t_print *print, t_flag *flag)
{
    char c;
    int i;

    i = 0;
    c = va_arg(print->args, int);
    if (flag[print->n].flags[5] > 0)
    {
        if (flag[print->n].flags[2] == 1)
        {
            ft_putchar(c);
            while(flag[print->n].flags[5] > ++i)
                ft_putchar(' ');
        }
        else
        {   
            while(flag[print->n].flags[5] > ++i)
                ft_putchar(' ');
            ft_putchar(c);
        }
    }
    else
        ft_putchar(c);
    return (1);
}