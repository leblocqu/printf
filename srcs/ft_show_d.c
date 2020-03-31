#include "../includes/ft_printf.h"

void    ft_show_putchar_d(t_print *print, t_flag *flag, int len, int size)
{
    int i;

    i = -1;
    if (flag[print->n].nb_int > 0)
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
    ft_putnbr(flag[print->n].nb_int);
    i = -1;
    size = size + ft_numlen(flag[print->n].nb_int);
    if (flag[print->n].flags[5] > 0)
        if (flag[print->n].flags[5] > size)
             while (++i < flag[print->n].flags[5] - size)
                ft_putchar(' ');
}

void    ft_show_d_moins(t_print *print, t_flag *flag, int len)
{
    int i;
    int size;

    i = -1;
    size = 0;
    if (flag[print->n].nb_int < 0)
    {
        flag[print->n].nb_int = -(flag[print->n].nb_int);
        len--;
        size++;
    }
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
    ft_show_putchar_d(print, flag, len, size);
}

void    ft_show_d_wmoins(t_print *print, t_flag *flag, int nb)
{
    int i;
    int len;
    int size;

    i = -1;
    len = ft_numlen(nb);
    size = 0;
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
        len--;
        size++;
    }
    else
    {
        if (flag[print->n].flags[1] == 1)
        {
            size++;
            ft_putchar('+');
        }
        if (flag[print->n].flags[4] == 1)    
        {
            size++;
            ft_putchar(' ');
        }
    }
    if (flag[print->n].flags[6] == 1)
        if (flag[print->n].flags[7] > len)
            while (++i < flag[print->n].flags[7] - len)
            {
                size++;
                ft_putchar('0');
            }
    ft_putnbr(nb);
    i = -1;
    size = size + ft_numlen(nb);
    if (flag[print->n].flags[5] > 0)
        if (flag[print->n].flags[5] > size)
             while (++i < flag[print->n].flags[5] - size)
                ft_putchar(' ');
}

int     ft_show_d(t_print *print, t_flag *flag)
{
    int len;

    flag[print->n].nb_int = va_arg(print->args, int);
    len = ft_numlen(flag[print->n].nb_int);
    if (flag[print->n].flags[2] == 1)
        ft_show_d_moins(print, flag, len);
    // else
    //     ft_show_d_wmoins(print, flag);
    return (1);
}

// width : augmente la taille
// precision : ajoute des 0 devants
// 0 ajoute des 0 devant
// - aligne agauche
// espace si nb >= 0 alors tu met un espace
// + met un plus si nb >= 0