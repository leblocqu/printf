#include "../includes/ft_printf.h"

char    *ft_show_s_prec(char *str, int len)
{
    char *ret;
    int i;

    i = 0;
    if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
        return (NULL);
    while (i < len)
    {
        ret[i] = str[i];
        i++;
    }
    ret[i] = '\0';
    return (ret);
}

char    *ft_show_s_width_flag(char *str, int len, int width)
{
    char *ret;
    int i;
    int j;

    i = 0;
    j = 0;
    if (width <= len)
        return (str);
    else
    {
        if (!(ret = (char *)malloc(sizeof(char) * width + 1)))
            return (NULL);
        ret[width] = '\0';
        while(i < width)
        {
            if (i < len)
            {
                ret[i] = str[j];
                j++;
            }
            else
                ret[i] = ' ';
            i++;
        }
    }
    return (ret);
}

char    *ft_show_s_width(char *str, int len, int width)
{
    char *ret;
    int i;
    int j;

    i = 0;
    j = 0;
    if (width <= len)
        return (str);
    else
    {
        if (!(ret = (char *)malloc(sizeof(char) * width + 1)))
            return (NULL);
        ret[width] = '\0';
        while(i < width)
        {
            if (i < width - len)
                ret[i] = ' ';
            else
            {
                ret[i] = str[j];
                j++;
            }
            i++;
        }
    }
    return (ret);
}

int     ft_s(t_print *print, t_flag *flag)
{
    char *str;
    int len;

    str = va_arg(print->args, char *);
    len = ft_strlen(str);
    if (flag[print->n].flags[6] == 1 
        && flag[print->n].flags[7] < len)
    {
        if (!(str = ft_show_s_prec(str, flag[print->n].flags[7])))
            return (-1);
        len = flag[print->n].flags[7];
    }
    if (flag[print->n].flags[5] > 0 && flag[print->n].flags[2] == 1)
    {
        if (!(str = ft_show_s_width_flag(str, len, flag[print->n].flags[5])))
            return (-1);
    }
    else if (flag[print->n].flags[5] > 0)
        if (!(str = ft_show_s_width(str, len, flag[print->n].flags[5])))
            return (-1);
    ft_putstr(str);
    return (1);
}