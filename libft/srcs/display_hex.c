/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:15:14 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:11:20 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** The first two chars of an hex start with 0x or 0X for %X,
** depends also on the input integer.
*/

void	hash_and_zero(t_struct *f, int hex_len_p, char *s, char x)
{
	char	c;

	c = find_char(f);
	if (c == '0' && f->hash == 2)
	{
		if (f->hash == 2 && x == 'x')
			f->n_print += write(1, "0x", 2);
		else if (f->hash == 2 && x == 'X')
			f->n_print += write(1, "0X", 2);
		while (f->width-- > 0)
			f->n_print += write(1, &c, 1);
		while (f->precision-- > 0)
			f->n_print += write(1, "0", 1);
		f->n_print += write(1, s, hex_len_p);
		return ;
	}
}

/*
** Checks for extra case on the left of the input and prints it out.
*/

void	aligned_left_hex(t_struct *f, int hex_len_p, char *s, char x)
{
	if (f->hash == 2 && x == 'x')
		f->n_print += write(1, "0x", 2);
	else if (f->hash == 2 && x == 'X')
		f->n_print += write(1, "0X", 2);
	while (f->precision > 0)
	{
		f->n_print += write(1, "0", 1);
		f->precision--;
	}
	f->n_print += write(1, s, hex_len_p);
	while (f->width > 0)
	{
		f->n_print += write(1, " ", 1);
		f->width--;
	}
	free(s);
}

/*
** Checks for extra case on the right of the input and prints it out.
*/

void	aligned_right_hex(t_struct *f, int hex_len_p, char *s, char x)
{
	char	c;

	c = find_char(f);
	if (c == '0' && f->hash == 2)
	{
		hash_and_zero(f, hex_len_p, s, x);
		return ;
	}
	while (f->width > 0)
	{
		f->n_print += write(1, &c, 1);
		f->width--;
	}
	if (f->hash == 2 && x == 'x')
		f->n_print += write(1, "0x", 2);
	else if (f->hash == 2 && x == 'X')
		f->n_print += write(1, "0X", 2);
	while (f->precision > 0)
	{
		f->n_print += write(1, "0", 1);
		f->precision--;
	}
	f->n_print += write(1, s, hex_len_p);
	free(s);
}

/*
** Format function for different specifiers. Ft_itoa_base_upper
** is needed for the case of %X, prints out the hex in upper case.
*/

void	format_hex(uintmax_t n, t_struct *f, char x, int hex_len_p)
{
	char	*s;

	if (x == 'x')
		s = ft_itoa_base(n, 16);
	else if (x == 'X')
		s = ft_itoa_base_upper(n, 16);
	if (f->hash)
		f->hash = 2;
	if (n == 0)
	{
		hex_len_p = 1;
		if (f->hash == 2)
			f->hash = 0;
		if (f->precision_dot && f->precision == 0)
			hex_len_p = 0;
	}
	if (f->precision_dot && f->precision > hex_len_p)
		f->precision = f->precision - hex_len_p;
	else
		f->precision = 0;
	f->width = f->width - (f->precision + hex_len_p) - f->hash;
	if (f->minus == 0)
		aligned_right_hex(f, hex_len_p, s, x);
	else if (f->minus == 1)
		aligned_left_hex(f, hex_len_p, s, x);
}

/*
** Dispatcher for different flag cases.
*/

void	display_hex(t_struct *f, va_list ap, char x)
{
	uintmax_t	n;
	int			hex_len_p;

	n = 0;
	if (f->length == 0)
		n = (unsigned int)va_arg(ap, unsigned int);
	else if (f->length == H)
		n = (unsigned short)va_arg(ap, int);
	else if (f->length == HH)
		n = (unsigned char)va_arg(ap, int);
	else if (f->length == L)
		n = (unsigned long int)va_arg(ap, uintmax_t);
	else if (f->length == LL)
		n = (unsigned long long int)va_arg(ap, uintmax_t);
	hex_len_p = unbr_len(n, 16);
	format_hex(n, f, x, hex_len_p);
}
