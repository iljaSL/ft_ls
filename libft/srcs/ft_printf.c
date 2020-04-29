/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:44:43 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:44:38 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** From here on we determine the type of the conversion and move to the
** modifie function if we have flags or starith to convert if we don't.
*/

int		par2(t_struct *f, int position, const char *format, va_list ap)
{
	f->i = position;
	if (!ft_strchr("cspdiouxXf%", format[position]))
		modifie(format, f, ap);
	else if (ft_strchr(("cspdiouxXf%"), format[position]))
	{
		convert(format[position], ap, f);
		re_initialize(f);
	}
	return (f->i - 1);
}

/*
** The pre parser, here we diffeerentiate between the input that we want
** to print out and the conversions start with '%'. If the percent sign
** is found we enter the parse function.
*/

int		par1(const char *format, t_struct *list, va_list ap, int pos)
{
	while (format[pos] != '\0')
	{
		if (format[pos] != '%' && format[pos])
			list->n_print += write(1, &format[pos], 1);
		else if (format[pos] == '%')
		{
			if (!ft_strchr(ASYMBOLS, format[pos + 1]))
				break ;
			while (ft_strchr(ASYMBOLS, format[pos + 1]))
			{
				pos = pos + 1;
				if (ft_strchr("cspdiouxXf%", format[pos]))
				{
					pos = par2(list, pos, format, ap) + 2;
					break ;
				}
				else
					pos = par2(list, pos, format, ap);
			}
			continue;
		}
		pos++;
	}
	return (list->n_print);
}

void	re_initialize(t_struct *list)
{
	list->len = 0;
	list->minus = 0;
	list->plus = 0;
	list->space = 0;
	list->zero = 0;
	list->hash = 0;
	list->width = 0;
	list->precision = 0;
	list->precision_dot = 0;
	list->length = 0;
}

void	initialize(t_struct *list)
{
	list->i = 0;
	list->len = 0;
	list->minus = 0;
	list->plus = 0;
	list->space = 0;
	list->zero = 0;
	list->hash = 0;
	list->width = 0;
	list->precision = 0;
	list->length = 0;
	list->n_print = 0;
	list->precision_dot = 0;
}

/*
** The Beginnin. With the help of va_arg we pull all arguments one
** by one in the order they are listed in printf.
*/

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_struct	*s;
	int			res;
	int			format_len;

	format_len = ft_strlen(format);
	if (!(s = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	initialize(s);
	s->format = (char *)format;
	va_start(ap, format);
	if (!format[0])
	{
		error();
		return (0);
	}
	if (format_len == 1 && format[0] == '%')
		return (0);
	else
		res = par1(format, s, ap, 0);
	va_end(ap);
	free(s);
	return (res);
}
