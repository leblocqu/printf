#include "../includes/ft_printf.h"

void    ft_p_moins(t_print *print, t_flag *flag, int len)
{
    ft_putstr("0x");
    ft_putstr(ft_conv_hexa(flag[print->n].l_l, 1));
    while (flag[print->n].flags[5] > len)
    {
        ft_putchar(' ');
        len++;
    }
}

void    ft_p_wmoins(t_print *print, t_flag *flag, int len)
{
    while (flag[print->n].flags[5] > len)
    {
        ft_putchar(' ');
        len++;
    }
    ft_putstr("0x");
    ft_putstr(ft_conv_hexa(flag[print->n].l_l, 1));
}

int     ft_p(t_print *print, t_flag *flag)
{
    int len;

    flag[print->n].l_l = va_arg(print->args, unsigned long long);
    len = len_hexa(flag[print->n].l_l) + 2;
    if (flag[print->n].flags[2] == 1)
        ft_p_moins(print, flag, len);
    else
        ft_p_wmoins(print, flag, len);
    return (1);
}