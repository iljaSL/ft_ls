/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:12:33 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:11:43 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Extar function for the case of width and zero specifiers
*/

int		width_and_zero(t_struct *f, char c, int sign, char usign)
{
	if (f->width > 0 && c == '0')
	{
		if (f->space)
		{
			f->n_print += write(1, " ", 1);
			f->space = 0;
		}
		if (sign != '\0')
			f->n_print += write(1, &usign, 1);
		sign -= sign;
	}
	return (sign);
}

/*
** Checks for extra case on the left of the input and prints it out.
*/

void	aligned_left_uint(t_struct *f, int len, char *s, int sign)
{
	sign = 0;
	if (f->space)
		f->n_print += write(1, " ", 1);
	if (sign == POSITIVE)
		f->n_print += write(1, "+", 1);
	else if (sign == NEGATIVE)
		f->n_print += write(1, "-", 1);
	while (f->precision > 0)
	{
		f->n_print += write(1, "0", 1);
		f->precision--;
	}
	f->n_print += write(1, s, len);
	while (f->width > 0)
	{
		f->n_print += write(1, " ", 1);
		f->width--;
	}
}

/*
** Checks for extra case on the right of the input and prints it out.
*/

void	aligned_right_uint(t_struct *f, int len, char *s, int sign)
{
	char	usign;
	char	c;

	c = find_char(f);
	sign = 0;
	usign = '\0';
	if (f->width > 0 && c == '0')
		sign = width_and_zero(f, c, sign, usign);
	else if (f->width <= 0 && usign != '\0')
	{
		f->n_print += write(1, &usign, 1);
		sign -= sign;
	}
	while (f->width-- > 0)
		f->n_print += write(1, &c, 1);
	if (f->space != 0)
		f->n_print += write(1, " ", 1);
	if (sign != 0 && usign != '\0')
		f->n_print += write(1, &sign, 1);
	while (f->precision-- > 0)
		f->n_print += write(1, "0", 1);
	f->n_print += write(1, s, len);
}

/*
** Format function for different specifiers.
*/

void	format_uint(uintmax_t n, t_struct *f, int sign)
{
	char	*s;
	int		len;

	if (f->space && sign != 0)
		f->space = 0;
	s = ft_itoa_base(n, 10);
	len = unbr_len(n, 10);
	if (n == 0)
		len = 1;
	if (f->precision_dot && f->precision == 0)
		len = 0;
	if (f->precision_dot && f->precision > len)
		f->precision = f->precision - len;
	else
		f->precision = 0;
	if (sign != 0)
		f->width = f->width - (f->precision + len + 1 + f->space);
	else
		f->width = f->width - (f->precision + len + f->space);
	if (f->minus == 0)
		aligned_right_uint(f, len, s, sign);
	if (f->minus == 1)
		aligned_left_uint(f, len, s, sign);
	free(s);
}

/*
** Dispatcher functions for diifferent flags.
*/

void	display_uint(t_struct *f, va_list ap)
{
	uintmax_t	n;
	int			sign;

	sign = 0;
	n = 0;
	if (f->space)
		f->space = 0;
	if (f->length == 0)
		n = (unsigned int)va_arg(ap, unsigned int);
	else if (f->length == H)
		n = (unsigned short int)va_arg(ap, int);
	else if (f->length == HH)
		n = (unsigned char)va_arg(ap, int);
	else if (f->length == L)
		n = (unsigned long int)va_arg(ap, long int);
	else if (f->length == LL)
		n = (unsigned long long int)va_arg(ap, long long int);
	if (f->plus)
		sign = POSITIVE;
	format_uint(n, f, sign);
}
