/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:06:54 by leblocqu          #+#    #+#             */
/*   Updated: 2020/02/27 20:06:55 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_numlen(int n)
{
	if (n == -2147483648)
		return (11);
	if (n < 0)
		return (ft_numlen(n * -1) + 1);
	if (n >= 10)
		return (ft_numlen(n / 10) + 1);
	return (1);
}

int		ft_ui_numlen(unsigned int n)
{
	if (n >= 10)
		return (ft_numlen(n / 10) + 1);
	return (1);
}

int		positif(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);	
}

int		len_hexa(unsigned long long val)
{
	int res;

	res = 0;
	if (val == 0)
		return (1);
	while (val != 0)
	{
		res++;
		val = val / 16;
	}
	return (res);
}

char	*ft_conv_hexa(unsigned long long val, int indice)
{
	char			*conv_min;
	char			*conv_maj;
	char			*res;
	int				len;

	conv_min = "0123456789abcdef";
	conv_maj = "0123456789ABCDEF";
	len = len_hexa(val);
	if (val == 0)
		return ("0");
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	res[len] = '\0';
	len--;
	while(val != 0)
	{
		if (indice == 1)
			res[len] = conv_min[val % 16];
		if (indice == 2)
			res[len] = conv_maj[val % 16];
		val = val / 16;
		len--;
	}
	return (res);
}

char	*ft_conv_octal(unsigned int val)
{
	char			*res;
	int				len;

	len = len_octal(val);
	if (val == 0)
		return ("0");
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	res[len] = '\0';
	len--;
	while(val != 0)
	{
		res[len] = (val % 8) + '0';
		val = val / 8;
		len--;
	}
	return (res);
}

int		len_octal(unsigned int val)
{
	int res;

	res = 0;
	if (val == 0)
		return (1);
	while (val != 0)
	{
		res++;
		val = val / 8;
	}
	return (res);
}
long		calcul_retenue(double nb)
{
	if (nb >= 0)
		return ((long)((nb)+0.4));
	else
		return ((long)((nb)-0.4));
}

void	ft_putdouble(double n, int precision)
{
	int		i;
	int		firstp;
	double	secondp;
	double	precision_adder;

	firstp = (int)n;
	secondp = (double)(n - firstp) * (n < 0 ? -1 : 1);
	if (precision == 0)
	{
		ft_putnbr(calcul_retenue(-n));
		return ;
	}
	ft_putnbr(firstp);
	if (precision > 0)
	{
		ft_putchar('.');
		precision_adder = 0.1;
		i = 0;
		while (i++ < precision)
			precision_adder /= 10;
		secondp += precision_adder;
		while (--i)
		{
			ft_putnbr((int)(secondp *= 10));
			firstp = (int)secondp;
			secondp -= (double)firstp;
		}
	}
}

int		ft_doublelen(double n, int precision, int len)
{
	int		i;
	int		firstp;
	double	secondp;
	double	precision_adder;

	firstp = (int)n;
	secondp = (double)(n - firstp) * (n < 0 ? -1 : 1);
	if (precision == 0)
	{
		len += ft_numlen(calcul_retenue(-n));
		return (len);
	}
	len += ft_numlen(firstp);
	if (precision > 0)
	{
		len++;
		precision_adder = 0.1;
		i = 0;
		while (i++ < precision)
			precision_adder /= 10;
		secondp += precision_adder;
		while (--i)
		{
			len++;
			firstp = (int)secondp;
			secondp -= (double)firstp;
		}
	}
	return (len);
}


// int		main(void)
// {
// 	double f = 42.34;
// 	printf("vrai printf:%0 15f\n", f);
// 	ft_printf("faux printf:%0 15f\n", f);
// 	return (0);
// }

int main(void)
{
	int t;
	char c;

	c = 'a';
	t = 50;
	// printf("p0 % .3s\n", "cccc");
	// printf("pp %.50d\n", 10000);
	// printf("p1 %.4s\n", "cccc");
	// printf("p2 %.10s\n", "cccc");
	// printf("p3 %.4s\n", NULL);
	// printf("p4 %.5s\n", "aaaaa");
	// printf("p5 %.3d\n", 100);
	// printf("p6 %.0d\n", 100);
	// printf("p7 %.4d\n", 100);
	// printf("p8 %.10d\n", 100);
	// printf("p9 %.50d\n", 100);
	// printf("p10 %.1d\n", 100);
	// printf("p11 %.3d\n", 100);
	// printf("p12 %.0d\n", 0);
	// printf("p13 %.3i\n", 100);
	// printf("p14 %.0i\n", 100);
	// printf("p15 %.4i\n", 100);
	// printf("p16 %.10i\n", 100);
	// printf("p17 %.50i\n", 100);
	// printf("p18 %.1i\n", 100);
	// printf("p19 %.3x\n", 100);
	// printf("p20 %.0x\n", 0);
	// printf("p21 %.3x\n", 100);
	// printf("p22 %.0x\n", 100);
	// printf("p23 %.4x\n", 100);
	// printf("p24 %.10x\n", 100);
	// printf("p25 %.50x\n", 100);
	// printf("p26 %.1x\n", 100);
	// printf("p27 %.3x\n", 100);
	// printf("p28 %.0x\n", 0);
	// printf("p29 %.3u\n", 100);
	// printf("p30 %.0u\n", 100);
	// printf("p31 %.4u\n", 100);
	// printf("p32 %.10u\n", 100);
	// printf("p33 %.50u\n", 100);
	// printf("p34 %.1u\n", 100);
	// printf("p35 %.3u\n", 100);
	// printf("p36 %.0u\n", 0);
	// printf("%%\n");
	// printf("Hello 42 school! %s", NULL);
	// printf("%010%");
	// printf("%u", 4294967295);
	// printf("%d\n", 2147483647);
	// printf("%d\n", -2147483648);
	// printf("%x\n", 2147483647);
	// printf("%x\n", -2147483648);
	// printf("%X\n", 2147483647);
	// printf("%X\n", -2147483648);
	// printf("%x\n", 0);
	// printf("%010x\n", 0);
	// printf("%010x\n", 20);
	// printf("%010x\n", -20);
	// printf("%10x\n", 20);
	// printf("%10.2x\n", -20);
	// printf("%-10x\n", 50);
	// printf("%-15x\n", 0);
	// printf("%.1x\n", 500);
	// printf("%*.*x\n", 50, 10, 2);
	// printf("%x\n", -1);
	// printf("%");
	// printf("%40.50d\n", 50);
    // printf("%d\n", -589);
    // printf("%-4d\n", -2464);
    // printf("%.5d\n", -2372);
	// printf("%p\n", NULL);
	// printf("%015p\n", NULL);
	// printf("%15p\n", NULL);
	// printf("%-15p\n", NULL);
    // printf("ret = %d\n", printf("%%p::[%010d]\n", -8473));
    // printf("ret = %d\n", printf("%%p::[%10d]\n", -8473));
    // printf("ret = %d\n", printf("%%p::[%.5d]\n", -8473));
    // printf("ret = %d\n", printf("%%p::[%01.1d]\n", -8473));
    // printf("ret = %d\n", printf("%%p::[%010.1d]\n", -8473));
    // printf("ret = %d\n", printf("%%p::[%01.50d]\n", -8473));
    // printf("ret = %d\n", printf("%%p::[%1.50d]\n", -8473));
    // printf("ret = %d\n", printf("%%p::[%0100.50d]\n", -8473));
    // printf("ret = %d\n", printf("%%p::[%010d]\n", 8473));
    // printf("ret = %d\n", printf("%%p::[%10d]\n", 8473));
    // printf("ret = %d\n", printf("%%p::[%.5d]\n", 8473));
    // printf("ret = %d\n", printf("%%p::[%01.1d]\n", 8473));
    // printf("ret = %d\n", printf("%%p::[%010.1d]\n", 8473));
    // printf("ret = %d\n", printf("%%p::[%01.50d]\n", 8473));
    // printf("ret = %d\n", printf("%%p::[%1.50d]\n", 8473));
    // printf("ret = %d\n", printf("%%p::[%0100.50d]\n", 8473));
	// printf("%c", 'a');
	// printf("%10c", 't');
	// printf("%1c", 'y');
	// printf("%010c", 't');
	// printf("%50.2s", "Coucou");
	// printf("%50.2s", NULL);
	// printf("%5.0s", "Hello");
	// printf("%.1s", "Test");
	// printf("%10s", NULL);
	// printf("%10s", "Ok");
	// printf("%d\n", printf("Les bornes :  %d, %d\n", -2147483648, 2147483647));
    // printf("%d\n", printf("Les bornes :  %u, %u\n", 0, 4294967295));
	// printf("%d\n", printf("Les bornes :  %x, %x\n", 0, 4294967295));
	// printf("%d\n", printf("1chiffre 1 %d chiffre 2 %d\n", 42, -42));
	// printf("%d\n", printf("2chiffre 1 %   d chiffre 2 % d\n", 42, -42));
	// printf("%d\n\n", printf("4chiffre 1 %-12d chiffre 2 %-12d\n\n", 42, -42));
	// printf("%    i\n", -60);
    // printf("%   i\n", -60);
    // printf("%1p\n", &t);
    // printf("%1p\n", &t);
	// printf("t1 %050d\n", 10);
	// printf("t2 %-50d\n", 10);
	// printf("t3 %50.0d\n", 10);
	// printf("t4 %50.50d\n", 10);
	// printf("t5 %50.10d\n", 10);
	// printf("t6 %*.*d\n", 50,  5, 10);
	// printf("t7 %1.50d\n", -10);
	// printf("t8 %1.50d\n", 10);
	// printf("t9 %2.2d\n", 10);
	// printf("t10 %2.2d\n", -10);
	// printf("t12 %.0d\n", 0);
	// printf("t13 %01d\n", -20);
	// printf("t14 %10d\n", 1000);
	// printf("%d\n\n", printf("5chiffre 1 %0d chiffre 2 %0d\n\n", 42, -42));
	// printf("%d\n\n", printf("6chiffre 1 %012d chiffre 2 %012d\n\n", 42, -42));
	// printf("%d\n\n", printf("8chiffre 1 %*d chiffre 2 %*d\n\n", 42, 6, 6, 6));
	// printf("%d\n\n", printf("15chiffre 1 %.d chiffre 2 %.d\n\n", 42, -42));
	// printf("%d\n\n", printf("4caractere 1 %12c caractere 2 %12c\n\n", 'a', 'c'));
	// printf("1caractere 1 %c caractere 2 %c\n\n", 'a', 'c');
	// printf("3caractere 1 %   c caractere 2 % c\n\n", 'a', 'c');
	// printf("%d\n\n", printf("1hexa-maj 1 %X hexa-maj 2 %X\n\n", 42, -42));
	// printf("%d\n\n", printf("3hexa-maj 1 %   X hexa-maj 2 % X\n\n", 42, -42));
	// printf("%d\n\n", printf("4hexa-maj 1 %12X hexa-maj 2 %int12X\n\n", 42, -42));
	// printf("%d\n\n", printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n\n", 42, -42));
	// printf("%d\n\n", printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n\n", 42, -42));
	// printf("%d\n\n", printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n\n", 42, -42));
	// printf("%d\n\n", printf("8hexa-maj 1 %*X hexa-maj 2 %*X\n\n", 42, 6, 6, 6));
	// printf("%d\n\n", printf("1pointeur 1 %p pointeur 2 %p\n\n", &c, &c));
	// printf("%d\n\n", printf("3pointeur 1 %   p pointeur 2 % p\n\n", &c, &c));
	// printf("%d\n\n", printf("4pointeur 1 %12p pointeur 2 %12p\n\n", &c, &c));
	// printf("%d\n\n", printf("4pointeur 1 %-12p pointeur 2 %-12p\n\n", &c, &c));
	// printf("%d\n\n", printf("5pointeur 1 %0p pointeur 2 %0p\n\n", &c, &c));
	// printf("%d\n\n", printf("6pointeur 1 %012p pointeur 2 %012p\n\n", &c, &c));
	// printf("%d\n\n", printf("1unsigned 1 %u unsigned 2 %u\n\n", 42, -42));
	// printf("%d\n\n", printf("3unsigned 1 %   u unsigned 2 % u\n\n", 42, -42));
	// printf("%d\n\n", printf("4unsigned 1 %12u unsigned 2 %12u\n\n", 42, -42));
	// printf("%d\n\n", printf("4unsigned 1 %-12u unsigned 2 %-12u\n\n", 42, -42));
	// printf("%d\n\n", printf("5unsigned 1 %0u unsigned 2 %0u\n\n", 42, -42));
	// printf("%d\n\n", printf("6unsigned 1 %012u unsigned 2 %012u\n\n", 42, -42));
	// printf("%d\n\n", printf("8unsigned 1 %*u unsigned 2 %*u\n\n", 42, 6, 6, 6));
	// printf("%d\n\n", printf("15unsigned 1 %.u unsigned 2 %.u\n\n", 42, -42));
	// printf("%d\n\n", printf("%s", 0));
	// printf("%d\n\n", printf("%%\n")); 
	// printf("%d\n\n", printf("%-.12u\n", -20000000));
	// printf("%d\n\n", printf("%-.12i\n", -20000000));
	// printf("%d\n", printf("truc"));
	// printf("%d\n", printf("bonjour !\n", 42, -42));
	// printf("04 Test de chiffre sans h : %d, et %d\n", 432767, -432767);
	// printf("%d\n", printf("03 This is a float : %f\n\n", 45.236));
	// printf("%d\n", printf("02 This is a float : %.3f\n\n", 45.236));
	// printf("%d\n",   printf("01 This is a float : %3f\n\n", 45.236));
	// printf("%d\n", printf("000 This is a float : %f\n\n", -45.236));
	// printf("%d\n", printf("0 This is a float : %.3f\n\n", -45.236));
	// printf("%d\n", printf("00 This is a float : %3f\n\n", -45.236));
	// printf("1 This is a float : %.0f\n\n", 42.99);
	// ft_printf("1 This is a float : %.0f\n\n", 42.99);
	// printf("vrai:8 This is a float : %3f\n\n", 1.0 / 0.0);
	// ft_printf("faux:8 This is a float : %3f\n\n", 1.0 / 0.0);
	// printf("9 This is a float : %3f\n\n", -1.0 / 0.0);
	// ft_printf("9 This is a float : %3f\n\n", -1.0 / 0.0);
	// printf("10 This is a float : %3f\n\n", 0.0 / 0.0);
	// ft_printf("10 This is a float : %3f\n\n", 0.0 / 0.0);
	// printf("11 This is a float : %3f\n\n", -0.0 / 0.0);
	// ft_printf("11 This is a float : %3f\n\n", -0.0 / 0.0);
	// printf("vrai:12 This is a float : %.0f\n", 2.5);
	// ft_printf("faux:12 This is a float : %.0f\n", 2.5);
	// printf("13 This is a float : %.0f\n\n", 3.5);
	printf("15 This is a float : %.0f\n\n", -3.5);
	ft_printf("15 This is a float : %.0f\n\n", -3.5);
	// printf("16 This is a float : %.0f\n\n", 2.51);
	// printf("17 This is a float : %.0f\n\n", 3.51);
	// printf("18 This is a float : %10.0f\n\n", -2.51);
	// printf("19 This is a float : %10.0f\n\n", -3.51);
	// printf("20 This is a float : %10.5f\n\n", -2.51);
	// printf("21 This is a float : %10.5f\n\n", -3.51);
	// printf("22 This is a float : %10.5f\n\n", 2.51);
	// printf("23 This is a float : %10.5f\n\n", 3.51);
	// printf("24 This is a float : %10.0f\n\n", 2.51);
	// printf("25 This is a float : %10.0f\n\n", 3.51);
	// printf("26 This is a float : %010f\n\n", 2.51);
	// printf("27 This is a float : %-10f\n\n", 3.51);
	// printf("28 This is a float : %015f\n\n", 2.51);
	// printf("29 This is a float : %15f\n\n", 3.51);
	// printf("30 This is a float : %.0f\n\n", 0.0);
	// printf("31 This is an int : %.0d\n\n", 0);
	// printf("32 This is an int : %0d\n\n", 0);
	// ft_printf("1 This is a float : %f\n\n", 0.00025);
	// ft_printf("2 This is a float : %.3f\n\n", 0.00025);
	// ft_printf("3 This is a float : %3f\n\n", 0.00025);
	// ft_printf("4 This is a float : %f\n\n", -0.00025);
	// ft_printf("5 This is a float : %f\n\n", -0.00025);
	// ft_printf("6 This is a float : %.3f\n\n", -0.00025);
	// ft_printf("7 This is a float : %3f\n\n", -0.00025);
	// ft_printf("8 This is a float : %3f\n\n", 1.0 / 0.0);
	// ft_printf("9 This is a float : %3f\n\n", -1.0 / 0.0);
	// ft_printf("10 This is a float : %3f\n\n", 0.0 / 0.0);
	// ft_printf("11 This is a float : %3f\n\n", -0.0 / 0.0);
	// ft_printf("12 This is a float : %.0f\n\n", 2.5);
	// ft_printf("13 This is a float : %.0f\n\n", 3.5);
	// ft_printf("14 This is a float : %.0f\n\n", -2.5);
	// ft_printf("15 This is a float : %.0f\n\n", -3.5);
	// ft_printf("16 This is a float : %.0f\n\n", 2.51);
	// ft_printf("17 This is a float : %.0f\n\n", 3.51);
	// ft_printf("18 This is a float : %10.0f\n\n", -2.51);
	// ft_printf("19 This is a float : %10.0f\n\n", -3.51);
	// ft_printf("20 This is a float : %10.5f\n\n", -2.51);
	// ft_printf("21 This is a float : %10.5f\n\n", -3.51);
	// ft_printf("22 This is a float : %10.5f\n\n", 2.51);
	// ft_printf("23 This is a float : %10.5f\n\n", 3.51);
	// ft_printf("24 This is a float : %10.0f\n\n", 2.51);
	// ft_printf("25 This is a float : %10.0f\n\n", 3.51);
	// ft_printf("26 This is a float : %010f\n\n", 2.51);
	// ft_printf("27 This is a float : %-10f\n\n", 3.51);
	// ft_printf("28 This is a float : %015f\n\n", 2.51);
	// ft_printf("29 This is a float : %15f\n\n", 3.51);
	// ft_printf("30 This is a float : %.0f\n\n", 0.0);
	// ft_printf("31 This is an int : %.0d\n\n", 0);
	// ft_printf("32 This is an int : %0d\n\n", 0);
	// printf("percent 1 %012%");
	// printf("percent 2 %12%");
	// printf("percent 3 %-12%");
	// printf("percent 4 %0%");
	// printf("percent 5 % %");
	// printf("percent 6 % 15%");
	// printf("percent 7 % 12%");
	// printf("percent 8 %  *%", 13);
	// printf("%n", &t);
	// printf("%d\n", t);
	// printf("%n", NULL);
	// printf("%d\n", t);
	// printf("test %n", &t);
	// printf("%d\n", t);
	// printf("%s %n", "hello world", &t);
	// printf("%d\n", t);
	// printf("% .1s %n", "hey", &t);
	// printf("%d\n", t);
	// printf("%40s %n", "co", &t);
	// printf("%d\n", t);
	// printf("%050 d%n", 500, &t);
	// printf("%d\n", t);
	// printf("%050 u%n", 500, &t);
	// printf("%d\n", t);
	// printf("%d\n\n", printf("1string 1 %s string 2 %s\n\n", "toto", "bonjour"));
	// printf("%d\n\n", printf("3string 1 %   s string 2 % s\n\n", "toto", "bonjour"));
	// printf("%d\n\n", printf("4string 1 %12s string 2 %12s\n\n", "toto", "bonjour"));
	// printf("%d\n\n", printf("4string 1 %-12s string 2 %-12s\n\n", "toto", "bonjour"));
	// printf("%d\n\n", printf("5string 1 %0s string 2 %0s\n\n", "toto", "bonjour"));
	// printf("%d\n\n", printf("6string 1 %012s string 2 %012s\n\n", "toto", "bonjour"));
	// printf("%d\n\n", printf("7string 1 %-012s string 2 %012s\n\n", "toto", "bonjour"));
	// printf("st1 %*.*d\n", 10, 10, 50);
	// printf("st2 %*.*d\n", 1, 50, 50);
	// printf("st3 %*.*d\n", 0, 0, 50);
	// printf("st4 %*.*d\n", 0, 50, 50);
	// printf("st5 %*.*d\n", 10, 0, 50);
	// printf("st6 %*.*d\n", 10, 10, 50);
	// printf("st12 %*d\n", 10, 50);
	// printf("st13 %*d\n", 0, 0);
	// printf("st14 %.*d\n", 0, 0);
	// printf("st15 %*d\n", 50, 5);
	// printf("st16 %0.*d\n", 50, 5);
	// printf("st17 %0.*d\n", 0, 0);
	// printf("st7 %*.*s\n", 1, 50, "hey");
	// printf("st8 %*.*s\n", 0, 0, "coucou");
	// printf("st9 %*.*s\n", 0, 50, "hey");
	// printf("st10 %*.*s\n", 10, 0, "dsa");
	// printf("st11 %*.*s\n", 10, 10, "hello");
	// printf("st7 %0.*s\n", 50, "hey");
	// printf("st8 %.*s\n", 0, "coucou");
	// printf("st9 %*s\n", 0, "hey");
	// printf("st10 %*s\n", 10, "dsa");
	// printf("st118 %*s\n", 100, "hello");
	// printf("st119 %*s\n", 1000, "hello");
	// printf("st120 %*s\n", 10000, "hello");
	// printf("st121 %*s\n", 100000, "hello");
	// printf("st118 %*d\n", 100, 0);
	// printf("st119 %*d\n", 1000, 10);
	// printf("st120 %*d\n", 10000, 467);
	// printf("st121 %*d\n", 100000, -589);
	// printf("ultimate1 %*d        %*i\n", 500, 0, 10, 10);
	// printf("ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 10000, -55, 1, -60);
	// printf("ultimate3 %*.*d %*.*s\n", 1, 50, 5000, 1, 0, "hey");
	// printf("ultimate4 %*.*x %*.*X\n", 1, 50, 5000, 1, 0, 10);
	// printf("ultimate5 %*.*u\n", 1, 50, 5000);
	// printf("neg1 %*s\n", -9, "coucou");
	// printf("neg2 %*.*s\n", -9, 4, "coucou");
	// printf("neg3 %*s\n", -9, NULL);
	// printf("neg4 %*.*s\n", 0, 0, "coucou");
	// printf("neg5 %*s\n", -100, "coucou");
	// printf("neg6 %*s\n", -156, "coucou");
	// printf("neg7 %*.*s\n", -1586, 15, "coucou");
	// printf("neg8 %*.*s\n", -1586, 15, "coucou");
	// printf("neg9 %*.*s\n", 15856, 155, "coucou");
	// printf("neg10 %*.*s\n", -15586, 15, "coucou");
	// printf("neg11 %*.*s\n", -15586, 15, "coucou");
	// printf("neg1 %*d\n", -9, 150);
	// printf("neg2 %*.*d\n", -9, 4, 1555);
	// printf("neg3 %*d\n", -9, -255);
	// printf("neg4 %*.*d\n", 0, 0, -30);
	// printf("neg5 %*d\n", -100, -589);
	// printf("neg6 %*d\n", -156, 15555);
	// printf("neg7 %*.*d\n", -1586, 15, 0);
	// printf("neg8 %*.*d\n", -1586, 15, 300);
	// printf("neg9 %*.*d\n", 15856, 155, -3000);
	// printf("neg10 %*.*d\n", -15586, 15, 150);
	// printf("neg11 %*.*d\n", -15586, 15, 0);
	// printf("***************%*s%*d**************%*u*************", 10, "coucou", 10, 10, -50, 20);
	// printf("taaa %100s\n", "hello");
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       