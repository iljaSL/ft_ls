/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:37:14 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:11:25 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Extar function for the zero and width specifiers.
*/

int		zero_and_width(t_struct *f, char c, char char_sign, int sign)
{
	if (f->width > 0 && c == '0')
	{
		if (f->space)
		{
			f->n_print += write(1, " ", 1);
			f->space = 0;
		}
		if (char_sign != '\0')
			f->n_print += write(1, &char_sign, 1);
		sign -= sign;
	}
	return (sign);
}

/*
** Checks for extra case on the left of the input and prints it out.
*/

void	aligned_left_int(t_struct *f, int hex_len, char *s, int sign)
{
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
	f->n_print += write(1, s, hex_len);
	while (f->width > 0)
	{
		f->n_print += write(1, " ", 1);
		f->width--;
	}
}

/*
** Checks for extra case on the right of the input and prints it out.
*/

void	aligned_right_int(t_struct *f, int int_len, char *s, int sign)
{
	char	char_sign;
	char	c;

	if (f->zero && !f->precision_dot)
		c = '0';
	else
		c = ' ';
	char_sign = '\0';
	if (sign == NEGATIVE)
		char_sign = '-';
	else if (sign == POSITIVE)
		char_sign = '+';
	sign = zero_and_width(f, c, char_sign, sign);
	while (f->width-- > 0)
		f->n_print += write(1, &c, 1);
	if (f->space != 0)
		f->n_print += write(1, " ", 1);
	if (sign != 0 && char_sign != '\0')
		f->n_print += write(1, &char_sign, 1);
	while (f->precision-- > 0)
		f->n_print += write(1, "0", 1);
	f->n_print += write(1, s, int_len);
}

/*
** Format function for different specifiers.
*/

void	format_int(intmax_t n, t_struct *f, int sign)
{
	int		int_len;
	char	*s;

	if (f->space && sign != 0)
		f->space = 0;
	s = ft_itoa_base_upper(n, 10);
	int_len = snbr_len(n, 10);
	if (n == 0)
		int_len = 1;
	if (f->precision_dot == 1 && f->precision == 0 && n == 0)
		int_len = 0;
	if (f->precision_dot && f->precision > int_len)
		f->precision = f->precision - int_len;
	else
		f->precision = 0;
	if (sign != 0)
		f->width = f->width - (f->precision + int_len + 1 + f->space);
	else
		f->width = f->width - (f->precision + int_len + f->space);
	if (f->minus == 0)
		aligned_right_int(f, int_len, s, sign);
	if (f->minus == 1)
		aligned_left_int(f, int_len, s, sign);
	free(s);
}

/*
** Dispatcher function for different flags.
*/

void	display_int(t_struct *f, va_list ap, int sign, intmax_t n)
{
	if (f->length == 0)
		n = (int)va_arg(ap, int);
	else if (f->length == H)
		n = (short int)va_arg(ap, int);
	else if (f->length == HH)
		n = (signed char)va_arg(ap, int);
	else if (f->length == L)
		n = (long int)va_arg(ap, long int);
	else if (f->length == LL)
		n = (long long int)va_arg(ap, long long int);
	if (f->plus && n >= 0)
		sign = POSITIVE;
	else if (n < 0)
	{
		sign = NEGATIVE;
		n = n * -1;
	}
	if (n == LLONG_MIN)
	{
		f->n_print += write(1, "-9223372036854775808", 20);
		return ;
	}
	format_int(n, f, sign);
}
