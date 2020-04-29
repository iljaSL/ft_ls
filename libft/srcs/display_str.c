/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:44:59 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:11:38 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Checks for extra case on the left of the input.
*/

void	aligned_left(t_struct *f, char c, char *s, int i)
{
	if (f->minus == 0)
	{
		if (f->precision_dot && i > f->precision)
			i = f->precision;
		if (f->width > i)
		{
			while ((f->width - i) > 0)
			{
				f->len = f->len + write(1, &c, 1);
				f->n_print++;
				f->width--;
			}
		}
		f->len = f->len + write(1, s, i);
		f->n_print = f->n_print + i;
	}
}

/*
** Checks for extra case on the right of the input.
*/

void	aligned_right(t_struct *f, char c, char *s, int i)
{
	if (f->minus != 0)
	{
		c = ' ';
		if (f->precision_dot && i > f->precision)
			i = f->precision;
		f->len = f->len + write(1, s, i);
		f->n_print = f->n_print + i;
		while (f->width > i)
		{
			f->len = f->len + write(1, &c, 1);
			f->n_print++;
			f->width--;
		}
	}
}

/*
** Prints String if %s is found, from here we go to left or right aligned
** depending if the - or + switch is on or off.
*/

void	display_str(t_struct *f, va_list ap)
{
	int		i;
	char	*s;
	char	c;

	if (f->zero == 1)
		c = '0';
	else
		c = ' ';
	s = (char *)va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	i = ft_strlen(s);
	if (f->minus == 1)
		aligned_right(f, c, s, i);
	else if (f->minus == 0)
		aligned_left(f, c, s, i);
}
