#include "../includes/ft_printf.h"

int     check_size(t_print *print, t_flag *flag)
{
    if (flag[print->n].flags[8] == 1 || flag[print->n].flags[9] == 1 || flag[print->n].flags[10] == 1
        || flag[print->n].flags[11] == 1 || flag[print->n].flags[12] == 1)
    {
        print->arg_i++;
        if (check_val_type(print->arg_i[0]) == 0)
        {
            ft_putstr("Error Syntax with size conversion.\n");
            return (-1);
        }
    }
    return (1);
}

int     init_size(t_print *print, t_flag *flag)
{
    if (print->arg_i[0] == 'h' || print->arg_i[0] == 'l')
    {
        if (print->arg_i[1] == 'h')
        {
            flag[print->n].flags[8] = 1;
            print->arg_i++;
        }
        else if (print->arg_i[1] == 'l')
        {
            flag[print->n].flags[10] = 1;
            print->arg_i++;
        }
        else if (check_val_type(print->arg_i[1]) == 1 && print->arg_i[0] == 'h')
            flag[print->n].flags[9] = 1;
        else if (check_val_type(print->arg_i[1]) == 1 && print->arg_i[0] == 'l')
            flag[print->n].flags[11] = 1;
    }
    else if (print->arg_i[0] == 'L')
        flag[print->n].flags[12] = 1;
    return (check_size(print, flag));
}

int     check_type_2(t_print *print, t_flag *flag)
{
    if (flag[print->n].flags[3] == 1 
        && ft_strchr("scpdiu", flag[print->n].letter_flag) != NULL)
    {
        ft_putstr("Type '");
        ft_putchar(flag[print->n].letter_flag);
        ft_putstr("' can't be use with flag '#'.\n");
        return (-1);
    }
    if (flag[print->n].flags[4] == 1 
        && ft_strchr("scpouxX", flag[print->n].letter_flag) != NULL)
    {
        ft_putstr("Type '");
        ft_putchar(flag[print->n].letter_flag);
        ft_putstr("' can't be use with flag '#'.\n");
        return (-1);
    }
    if (flag[print->n].flags[6] == 1 && flag[print->n].letter_flag == 'c')
    {
        ft_putstr("Type 'c' can't be use with precision.\n");
        return (-1);
    }
    return (1);
}

int     check_type(t_print *print, t_flag *flag)
{
    if (flag[print->n].flags[0] == 1 
        && ft_strchr("scpu", flag[print->n].letter_flag) != NULL)
    {
        ft_putstr("Type '");
        ft_putchar(flag[print->n].letter_flag);
        ft_putstr("' can't be use with flag '0'.\n");
        return (-1);
    }
    if (flag[print->n].flags[1] == 1 
        && ft_strchr("scpoxXu", flag[print->n].letter_flag) != NULL)
    {
        ft_putstr("Type '");
        ft_putchar(flag[print->n].letter_flag);
        ft_putstr("' can't be use with flag '+'.\n");
        return (-1);
    }
    if (flag[print->n].flags[6] == 1 && flag[print->n].letter_flag == 'p')
    {
        ft_putstr("Type 'p' can't be use with precision.\n");
        return (-1);
    }
    return (check_type_2(print, flag));
}

int     init_type(t_print *print, t_flag *flag)
{
    if (check_val_type(print->arg_i[0]) == 0)
    {
        ft_putstr("There is a '%' without type.\n");
        return (-1);
    }
    else
        flag[print->n].letter_flag = print->arg_i[0];
    return (check_type(print, flag));
}