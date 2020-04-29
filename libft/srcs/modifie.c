/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifie.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:22:20 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:34:36 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** We enter width if we encounter a number from 0-9 or the * sign.
*/

void	width(const char *format, t_struct *f, va_list ap)
{
	w_start(format, f, ap);
	if (format[f->i] >= '0' && format[f->i] <= '9')
	{
		f->width = ft_atoi(&format[f->i]);
		while (format[f->i] >= '0' && format[f->i] <= '9')
		{
			f->i++;
			if (format[f->i] == '*')
			{
				if (f->width < 0)
				{
					f->minus = 1;
					f->width = -(f->width);
				}
				while (format[f->i] == '*')
					f->i++;
			}
		}
	}
}

/*
** We enter flags if one of the mentioned flags is found.
*/

void	flags(const char *format, t_struct *f)
{
	while (ft_strchr("-+ #0", format[f->i]))
	{
		if (format[f->i] == '-')
			f->minus = 1;
		if (format[f->i] == '+')
			f->plus = 1;
		if (format[f->i] == ' ')
			f->space = 1;
		if (format[f->i] == '#')
			f->hash = 1;
		if (format[f->i] == '0')
			f->zero = 1;
		f->i++;
	}
	if (f->plus == 1)
		f->space = 0;
}

/*
** We enter precision if . or * is found.
*/

void	precision(const char *format, t_struct *f, va_list ap, int p)
{
	int	i;

	i = f->i;
	if (format[i] == '.')
	{
		i++;
		f->precision_dot = 1;
		if (format[i] >= '0' && format[i] <= '9')
		{
			f->precision = ft_atoi(&format[i]);
			while (format[i] >= '0' && format[i] <= '9')
				i++;
		}
		else if (format[f->i] == '*')
		{
			p = va_arg(ap, int);
			if (p >= 0)
				f->precision = p;
			else if (p < 0)
				f->precision_dot = 0;
			while (format[f->i] == '*')
				i++;
		}
	}
	f->i = i;
}

/*
** We enter length if the "hlLjz" sub-specifier is found and modifie it.
*/

void	length(const char *format, t_struct *f, int i)
{
	i = f->i;
	if (ft_strchr("hlLjz", format[i]))
	{
		if (format[i] == 'h')
		{
			if (format[i + 1] == 'h')
				f->length = HH;
			else if (format[i - 1] != 'h')
				f->length = H;
		}
		if (format[i] == 'l')
		{
			if (format[i + 1] == 'l')
				f->length = LL;
			else if (format[i - 1] != 'l')
				f->length = L;
		}
		if (format[i] == 'L')
			f->length = CAPL;
	}
	while (ft_strchr("hlLjz", format[i]))
		i++;
	f->i = i;
}

/*
** This a dispatcher to different funtions with different flags.
*/

void	modifie(const char *format, t_struct *f, va_list ap)
{
	flags(format, f);
	width(format, f, ap);
	precision(format, f, ap, 0);
	length(format, f, 0);
}
