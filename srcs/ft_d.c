#include "../includes/ft_printf.h"

void    ft_show_moins(t_print *print, t_flag *flag, int len, int size)
{
    int i;

    i = -1;
    if (flag[print->n].nb_int < 0)
        ft_putchar('-');
    else
    {
        if (flag[print->n].flags[1] == 1)
            ft_putchar('+');
        if (flag[print->n].flags[4] == 1)
            ft_putchar(' ');
    }
    if (flag[print->n].flags[6] == 1)
        if (flag[print->n].flags[7] > len)
            while (++i < flag[print->n].flags[7] - len)
                ft_putchar('0');
    if (flag[print->n].flags[7] != 0 || positif(flag[print->n].nb_int) != 0)
        ft_putnbr(positif(flag[print->n].nb_int));
    i = -1;
    size = size + ft_numlen(positif(flag[print->n].nb_int));
    if (flag[print->n].flags[5] > 0)
        if (flag[print->n].flags[5] > size)
             while (++i < flag[print->n].flags[5] - size)
                ft_putchar(' ');
}

void    ft_d_moins(t_print *print, t_flag *flag, int len)
{
    int i;
    int size;

    i = -1;
    size = 0;
    if (flag[print->n].nb_int < 0)
        size++;
    else
    {
        if (flag[print->n].flags[1] == 1)
            size++;
        if (flag[print->n].flags[4] == 1)    
            size++;
    }
    if (flag[print->n].flags[6] == 1)
        if (flag[print->n].flags[7] > len)
            while (++i < flag[print->n].flags[7] - len)
                size++;
    ft_show_moins(print, flag, len, size);
}

void    ft_show_wmoins(t_print *print, t_flag *flag, int len, int size)
{
    len = size;
    size--;
    while (flag[print->n].flags[5] > ++size)
        ft_putchar(' ');
    if (flag[print->n].nb_int < 0)
        ft_putchar('-');
    else
    {
        if (flag[print->n].flags[1] == 1)
        {
            ft_putchar('+');
            len--;
        }
        if (flag[print->n].flags[4] == 1)    
        {    
            ft_putchar(' ');
            len--;
        }
    }
    while (ft_numlen(flag[print->n].nb_int) < len)
    {
        ft_putchar('0');
        len--;
    }
}

void    ft_d_wmoins(t_print *print, t_flag *flag, int len)
{
    int size;

    size = len;
    if (flag[print->n].flags[6] == 1)
        while(flag[print->n].flags[7] > size)
            size++;
    if (flag[print->n].nb_int < 0)
        size++;
    else
        if(flag[print->n].flags[1] == 1 || flag[print->n].flags[4] == 1)
            size++;
    if (flag[print->n].flags[5] > 0 && flag[print->n].flags[5] > size)
        if (flag[print->n].flags[0] == 1)
            size = flag[print->n].flags[5];
    ft_show_wmoins(print, flag, len, size);
}

int     ft_d(t_print *print, t_flag *flag)
{
    int len;

    flag[print->n].nb_int = va_arg(print->args, int);
    if (flag[print->n].nb_int == 0)
        len = 0;
    else
    {
        if (flag[print->n].nb_int == -2147483648)
            len = 10;
        else
            len = ft_numlen(positif(flag[print->n].nb_int));
    }
    if (flag[print->n].flags[2] == 1)
        ft_d_moins(print, flag, len);
    else
    {
        ft_d_wmoins(print, flag, len);
        if (flag[print->n].flags[7] != 0 
            || positif(flag[print->n].nb_int) != 0)
            ft_putnbr(positif(flag[print->n].nb_int));
    }
    return (1);
}