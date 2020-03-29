#include "../includes/ft_printf.h"

int     ft_show_s(t_print *print, t_flag *flag)
{
    char *str;
    int len;

    str = va_arg(print->args, char *);
    len = ft_strlen(str);
    if (flag[print->n].flags[2] == 0 
        && flag[print->n].flags[5] == 0
            && flag[print->n].flags[6] == 0)
        ft_putstr(str);
    
    return (1);
}