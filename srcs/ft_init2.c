#include "../includes/ft_printf.h"

int     init_flag(t_print *print,t_flag *flag)
{
    while (print->arg_i[0] == '0' || print->arg_i[0] == '+' || print->arg_i[0] == '-' || print->arg_i[0] == '#'
        || print->arg_i[0] == ' ')
    {
        if (print->arg_i[0] == '0')
            flag[print->n].flags[0] = 1;
        if (print->arg_i[0] == '+')
            flag[print->n].flags[1] = 1;
        if (print->arg_i[0] == '-')
            flag[print->n].flags[2] = 1;
        if (print->arg_i[0] == '#')
            flag[print->n].flags[3] = 1;
        if (print->arg_i[0] == ' ')
            flag[print->n].flags[4] = 1;
        print->arg_i++;
    }
    return (check_flags(print, flag));
}

int     check_flags(t_print *print, t_flag *flag)
{
    if (flag[print->n].flags[0] == 1 && flag[print->n].flags[2] == 1)
    {
        ft_putstr("Flag '0' can't be use with flag '-'.\n");
        return (-1);
    }
    if (flag[print->n].flags[4] == 1 && flag[print->n].flags[1] == 1)
    {
        ft_putstr("Flag ' ' can't be use with flag '+'.\n");
        return (-1);
    }
    return (1);
}

int     check_width(t_print *print, t_flag *flag)
{
    if (flag[print->n].flags[0] == 1 && flag[print->n].flags[6] == 1)
    {
        ft_putstr("Flag '0' can't be use with precision.\n");
        return (-1);
    }
    return (1);
}

int		init_width(t_print *print, t_flag *flag)
{
    if (ft_isdigit(print->arg_i[0]) == 1)
    {
        flag[print->n].flags[5] = ft_atoi(print->arg_i);
    }
    while (ft_isdigit(print->arg_i[0]) == 1)
    {
        print->arg_i++;
    }
    return (check_width(print, flag));
}

int     init_precision(t_print *print, t_flag *flag)
{
    if (print->arg_i[0] == '.')
    {
        print->arg_i++;
        flag[print->n].flags[6] = 1;
        if (ft_isdigit(print->arg_i[0]) == 1)
        {
            flag[print->n].flags[7] = ft_atoi(print->arg_i);
            while (ft_isdigit(print->arg_i[0]) == 1)
                print->arg_i++;
        }
    }
    return (1);
}