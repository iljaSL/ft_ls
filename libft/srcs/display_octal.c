/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:23:23 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:11:29 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Checks for extra case on the left of the input and prints it out.
*/

void	aligned_left_octal(t_struct *f, int width_p, int octal_len, char *s)
{
	while (f->precision > 0)
	{
		f->n_print += write(1, "0", 1);
		f->precision--;
	}
	if (f->hash == 1)
		f->n_print += write(1, "0", 1);
	f->n_print += write(1, s, octal_len);
	while (width_p > 0)
	{
		f->n_print += write(1, " ", 1);
		width_p--;
	}
	return ;
}

/*
** Checks for extra case on the right of the input and prints it out.
*/

void	aligned_right_octal(t_struct *f, int width_p, int octal_len, char *s)
{
	char	c;

	if (f->zero && !f->precision_dot)
		c = '0';
	else
		c = ' ';
	while (width_p > 0)
	{
		f->n_print += write(1, &c, 1);
		width_p--;
	}
	while (f->precision > 0)
	{
		f->n_print += write(1, "0", 1);
		f->precision--;
	}
	if (f->hash == 1)
		f->n_print += write(1, "0", 1);
	f->n_print += write(1, s, octal_len);
}

/*
** Format function for different specifiers.
*/

void	format_octal(uintmax_t n, t_struct *f)
{
	int		octal_len;
	int		width_p;
	char	*s;

	s = ft_itoa_base(n, 8);
	octal_len = unbr_len(n, 8);
	if (n == 0)
	{
		octal_len = 1;
		if (f->hash == 1)
			octal_len = 0;
		if (f->precision_dot && f->precision == 0)
			octal_len = 0;
	}
	if (f->precision_dot && f->precision > octal_len)
		f->precision = f->precision - octal_len - f->hash;
	else
		f->precision = 0;
	width_p = f->width - (f->precision + octal_len) - f->hash;
	if (f->minus == 0)
		aligned_right_octal(f, width_p, octal_len, s);
	else if (f->minus == 1)
		aligned_left_octal(f, width_p, octal_len, s);
	free(s);
}

/*
** Dispatcher for different flag cases.
*/

void	display_octal(t_struct *f, va_list ap)
{
	unsigned long	n;

	n = 0;
	if (f->length == 0)
		n = va_arg(ap, unsigned int);
	else if (f->length == H)
		n = (unsigned int)va_arg(ap, unsigned int);
	else if (f->length == HH)
		n = (unsigned char)va_arg(ap, unsigned int);
	else if (f->length == L)
		n = (unsigned long)va_arg(ap, unsigned long);
	else if (f->length == LL)
		n = (unsigned long long)va_arg(ap, unsigned long long);
	format_octal(n, f);
}
