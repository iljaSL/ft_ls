/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_float_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 09:40:18 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:11:12 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Multiplying the float into a whole number.
*/

long double	power(intmax_t n, int i)
{
	long		nbr;
	long double	res;

	res = n;
	nbr = 0;
	if (i == 0)
		return (1);
	while (nbr < i - 1)
	{
		res = res * n;
		nbr++;
	}
	return (res);
}

t_fstruct	format_float_3(t_fstruct g, t_struct *f)
{
	if (g.flt == 0)
		g.zeros--;
	g.hash = 0;
	if (f->hash)
		g.hash = 1;
	if (f->hash && ft_strlen(g.s2) > 0)
		g.hash = 0;
	g.dot = 0;
	if ((ft_strlen(g.s2) > 0 && g.precision != 0) || f->hash)
		g.dot = 1;
	if (g.precision != 0)
		g.padding = f->width - f->precision - g.before_dec_nbr
			- g.hash - g.sign_int - g.dot;
	else
		g.padding = f->width - f->precision - g.before_dec_nbr
			- g.hash - g.sign_int - g.dot - 1;
	g.zeros = g.zeros - g.precisionadd;
	if (f->minus == 0)
		aligned_right_flt(f, g);
	else if (f->minus == 1)
		aligned_left_flt(f, g);
	return (g);
}

/*
** Second formating function.
*/

t_fstruct	format_float_2(t_fstruct g, t_struct *f, long double n)
{
	if (f->precision_dot == 1 && f->precision >= 0)
		g.precision = f->precision;
	g.i = (long long)n;
	g.s1 = ft_itoa_base(g.i, 10);
	n = n - (long double)g.i;
	g.precisionadd = 0;
	if (n == 0)
		g.precisionadd = g.precision - 1;
	n = (n * power(10, g.precision));
	g.flt = (n >= 0) ? (long)(n + 0.5) : (long)(n - 0.5);
	if (g.flt == power(10, g.precision) && g.flt != 0)
	{
		g.s1 = ft_itoa_base(g.i + 1, 10);
		g.flt = 0;
		if (g.flt == 0)
			g.precisionadd = g.precision - 1;
	}
	g.s2 = ft_itoa_base(g.flt, 10);
	if (g.precision != 0)
		g.zeros = g.precision - snbr_len(g.flt, 10);
	else
		g.zeros = 0;
	g.before_dec_nbr = snbr_len(n, 10);
	return (g);
}

/*
** First formating function.
*/

void		format_float(long double n, t_struct *f)
{
	t_fstruct	g;

	g.sign_int = 0;
	if (f->plus)
		g.sign_int = 1;
	g.sign = ' ';
	if (n < 0)
	{
		g.sign = '-';
		n = -n;
		g.sign_int = 1;
	}
	else if (n > 0 && f->plus)
		g.sign = '+';
	g.precision = 6;
	if (f->zero == 1)
		g.c = '0';
	else
		g.c = ' ';
	if (f->minus)
		g.c = ' ';
	g = format_float_2(g, f, n);
	g = format_float_3(g, f);
	free(g.s1);
	free(g.s2);
}

/*
** Dispatch funtion for the flags l and L.
*/

void		display_float(t_struct *f, va_list ap)
{
	long double	n;

	n = 0;
	if (f->length == CAPL)
		n = va_arg(ap, long double);
	else
		n = va_arg(ap, double);
	format_float(n, f);
}
