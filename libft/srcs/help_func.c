/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:26:22 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:34:26 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		unbr_len(uintmax_t n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char	find_char(t_struct *f)
{
	char	c;

	if (f->zero && !f->precision_dot)
		c = '0';
	else
		c = ' ';
	return (c);
}

void	w_start(const char *format, t_struct *f, va_list ap)
{
	if (format[f->i] == '*')
	{
		f->width = va_arg(ap, int);
		if (f->width < 0)
		{
			f->minus = 1;
			f->width = -(f->width);
		}
		while (format[f->i] == '*')
			f->i++;
	}
}

void	write_blank(int n)
{
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
	}
}

void	write_zeros(int n)
{
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
	}
}
