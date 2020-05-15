#include "../includes/ft_printf.h"

void    ft_o_zero(t_print *print, t_flag *flag, int len)
{
    if (flag[print->n].flags[3] == 1 && flag[print->n].u_int != 0)
    {
        ft_putchar('0');
        len ++;
    }
    while (len < flag[print->n].flags[5])
    {
        ft_putchar('0');
        len++;
    }
    ft_putstr(ft_conv_octal(flag[print->n].u_int));
}

void    ft_o_wmoins(t_print *print, t_flag *flag, int len)
{
    if (len < flag[print->n].flags[7])
        len = flag[print->n].flags[7];
    if (flag[print->n].flags[3] == 1 && flag[print->n].u_int != 0)
        len ++;
    while (len < flag[print->n].flags[5])
    {
        ft_putchar(' ');
        flag[print->n].flags[5]--;
    }
    if (flag[print->n].flags[3] && flag[print->n].u_int != 0)
    {
        ft_putchar('0');
        len --;
    }
    while (len > len_octal(flag[print->n].u_int))
    {
        ft_putchar('0');
        len--;
    }
    ft_putstr(ft_conv_octal(flag[print->n].u_int));
}

void    ft_o_moins(t_print *print, t_flag *flag, int len)
{
    if (flag[print->n].flags[3] == 1 && flag[print->n].u_int != 0)
        ft_putchar('0');
    while (flag[print->n].flags[7] > len)
    {
        ft_putchar('0');
        len++;
    }
    if (flag[print->n].flags[3] == 1 && flag[print->n].u_int != 0)
        len ++;
    ft_putstr(ft_conv_octal(flag[print->n].u_int));
    while (flag[print->n].flags[5] > len)
    {
        ft_putchar(' ');
        len++;
    }
}

int     ft_o(t_print *print, t_flag *flag)
{
    int len;

    flag[print->n].u_int = va_arg(print->args, unsigned int);
    if (flag[print->n].u_int == 0)
        len = 1;
    else
        len = len_octal(flag[print->n].u_int);
    if (flag[print->n].flags[0] == 1)
        ft_o_zero(print, flag, len);
    else if (flag[print->n].flags[2] == 1)
        ft_o_moins(print, flag, len);
    else
        ft_o_wmoins(print, flag, len);
    return (1);
}