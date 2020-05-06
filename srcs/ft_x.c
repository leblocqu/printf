#include "../includes/ft_printf.h"

void    ft_x_zero(t_print *print, t_flag *flag, int len, int indice)
{
    if (flag[print->n].flags[3] == 1 && flag[print->n].u_int != 0)
    {
        ft_putchar('0');
        if (flag[print->n].letter_flag == 'X')
            ft_putchar('X');
        if (flag[print->n].letter_flag == 'x')
            ft_putchar('x');
        len += 2;
    }
    while (len < flag[print->n].flags[5])
    {
        ft_putchar('0');
        len++;
    }
    ft_putstr(ft_conv_hexa(flag[print->n].u_int, indice));
}

void    ft_x_wmoins(t_print *print, t_flag *flag, int len, int indice)
{
    if (len < flag[print->n].flags[7])
        len = flag[print->n].flags[7];
    if (flag[print->n].flags[3] == 1 && flag[print->n].u_int != 0)
        len += 2;
    while (len < flag[print->n].flags[5])
    {
        ft_putchar(' ');
        flag[print->n].flags[5]--;
    }
    if (flag[print->n].flags[3] && flag[print->n].u_int != 0)
    {
        ft_putchar('0');
        if (flag[print->n].letter_flag == 'X')
            ft_putchar('X');
        if (flag[print->n].letter_flag == 'x')
            ft_putchar('x');
        len -= 2;
    }
    while (len > len_hexa(flag[print->n].u_int))
    {
        ft_putchar('0');
        len--;
    }
    ft_putstr(ft_conv_hexa(flag[print->n].u_int, indice));
}

void    ft_x_moins(t_print *print, t_flag *flag, int len, int indice)
{
    if (flag[print->n].flags[3] == 1 && flag[print->n].u_int != 0)
    {
        ft_putchar('0');
        if (flag[print->n].letter_flag == 'x')
            ft_putchar('x');
        if (flag[print->n].letter_flag == 'X')
            ft_putchar('X');
    }
    while (flag[print->n].flags[7] > len)
    {
        ft_putchar('0');
        len++;
    }
    if (flag[print->n].flags[3] == 1 && flag[print->n].u_int != 0)
        len += 2;
    ft_putstr(ft_conv_hexa(flag[print->n].u_int, indice));
    while (flag[print->n].flags[5] > len)
    {
        ft_putchar(' ');
        len++;
    }
}

int     ft_x(t_print *print, t_flag *flag)
{
    int len;
    int indice;

    if (flag[print->n].letter_flag == 'x')
        indice = 1;
    if (flag[print->n].letter_flag == 'X')
        indice = 2;
    flag[print->n].u_int = va_arg(print->args, unsigned int);
    if (flag[print->n].u_int == 0)
        len = 1;
    else
        len = len_hexa(flag[print->n].u_int);
    if (flag[print->n].flags[0] == 1)
        ft_x_zero(print, flag, len, indice);
    else if (flag[print->n].flags[2] == 1)
        ft_x_moins(print, flag, len, indice);
    else
        ft_x_wmoins(print, flag, len, indice);
    return (1);
}