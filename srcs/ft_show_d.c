#include "../includes/ft_printf.h"

void    ft_show_d_moins(t_print *print, t_flag *flag, int nb)
{
    int i;
    int len;
    int test;

    i = -1;
    len = ft_numlen(nb);
    test = 0;
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
        len--;
        test++;
    }
    else
    {
        if (flag[print->n].flags[1] == 1)
        {
            test++;
            ft_putchar('+');
        }
        if (flag[print->n].flags[4] == 1)    
        {
            test++;
            ft_putchar(' ');
        }
    }
    if (flag[print->n].flags[6] == 1)
        if (flag[print->n].flags[7] > len)
            while (++i < flag[print->n].flags[7] - len)
            {
                test++;
                ft_putchar('0');
            }
    ft_putnbr(nb);
    i = -1;
    test = test + ft_numlen(nb);
    if (flag[print->n].flags[5] > 0)
        if (flag[print->n].flags[5] > test)
             while (++i < flag[print->n].flags[5] - test)
                ft_putchar(' ');
}

void    ft_show_d_wmoins(t_print *print, t_flag *flag, int nb)
{
    int i;
    int len;
    int test;

    i = -1;
    len = ft_numlen(nb);
    test = 0;
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
        len--;
        test++;
    }
    else
    {
        if (flag[print->n].flags[1] == 1)
        {
            test++;
            ft_putchar('+');
        }
        if (flag[print->n].flags[4] == 1)    
        {
            test++;
            ft_putchar(' ');
        }
    }
    if (flag[print->n].flags[6] == 1)
        if (flag[print->n].flags[7] > len)
            while (++i < flag[print->n].flags[7] - len)
            {
                test++;
                ft_putchar('0');
            }
    ft_putnbr(nb);
    i = -1;
    test = test + ft_numlen(nb);
    if (flag[print->n].flags[5] > 0)
        if (flag[print->n].flags[5] > test)
             while (++i < flag[print->n].flags[5] - test)
                ft_putchar(' ');
}

int     ft_show_d(t_print *print, t_flag *flag)
{
    int nb;

    nb = va_arg(print->args, int);
    if (flag[print->n].flags[2] == 1)
        ft_show_d_moins(print, flag, nb);
    else
        ft_show_d_wmoins(print, flag, nb):
    return (1);
}

// width : augmente la taille
// precision : ajoute des 0 devants
// 0 ajoute des 0 devant
// - aligne agauche
// espace si nb >= 0 alors tu met un espace
// + met un plus si nb >= 0