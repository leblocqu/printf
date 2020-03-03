#include "../includes/ft_printf.h"

int     init_flag(t_print *print, char *arg)
{
    int i;

    i = 0;
    while (arg[i] == '0' || arg[i] == '+' || arg[i] == '-' || arg[i] == '#'
        || arg[i] == ' ')
    {
        printf("arg[%d] = %c\n", i, arg[i]);
        if (arg[i] == '0')
        {
            printf("test\n");
            printf("n = %d\n", print->n);
            print->all_flags[print->n].flag[0] == 1;
            printf("truc = %d\n", print->all_flags[print->n].flag[0]);
        }
        if (arg[i] == '+')
            print->all_flags[print->n].flag[1] == 1;
        if (arg[i] == '-')
            print->all_flags[print->n].flag[2] == 1;
        if (arg[i] == '#')
            print->all_flags[print->n].flag[3] == 1;
        if (arg[i] == ' ')
            print->all_flags[print->n].flag[4] == 1;
        i++;
    }
    printf("truc 2 = %d\n", print->all_flags[print->n].flag[2]);
    if (check_flags(print) == -1)
        return (-1);
    return (1);
}

int     check_flags(t_print *print)
{
    if (print->all_flags[print->n].flag[0] == 1 && print->all_flags[print->n].flag[2] == 1)
    {
        ft_putstr("Flag '0' can't be use with flag '-'\n");
        return (-1);
    }
    if (print->all_flags[print->n].flag[4] == 1 && print->all_flags[print->n].flag[1] == 1)
    {
        ft_putstr("Flag ' ' can't be use with flag '+'\n");
        return (-1);
    }
    return (-1);
}