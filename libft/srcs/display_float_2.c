/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_float_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 10:56:50 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:10:03 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	aligned_left_flt_2(t_struct *f, t_fstruct g)
{
	while (*g.s2 && g.precision != 0)
	{
		f->n_print += write(1, g.s2, 1);
		g.s2++;
		g.precision--;
	}
	if (f->space && g.sign == '-' && g.precision > 0)
	{
		f->n_print += write(1, " ", 1);
		g.padding--;
		f->space = 0;
	}
	while (g.precisionadd-- > 0)
		f->n_print += write(1, "0", 1);
	while (g.padding-- > 0)
		f->n_print += write(1, &g.c, 1);
}

void	aligned_left_flt(t_struct *f, t_fstruct g)
{
	if (f->space && g.sign != '-')
	{
		f->n_print += write(1, " ", 1);
		g.padding--;
		f->space = 0;
	}
	if (g.sign_int == 1 && g.sign)
		f->n_print += write(1, &g.sign, 1);
	while (*g.s1)
	{
		f->n_print += write(1, g.s1, 1);
		g.s1++;
	}
	if (g.dot == 1 || f->hash)
		f->n_print += write(1, ".", 1);
	while (g.zeros-- > 0 && g.precision-- != 0)
		f->n_print += write(1, "0", 1);
	aligned_left_flt_2(f, g);
}

void	aligned_right_flt_3(t_struct *f, t_fstruct g)
{
	if (g.dot == 1 || f->hash)
		f->n_print += write(1, ".", 1);
	while (g.zeros > 0 && g.precision != 0)
	{
		f->n_print += write(1, "0", 1);
		g.zeros--;
		g.precision--;
	}
	while (*g.s2 && g.precision != 0)
	{
		f->n_print += write(1, g.s2, 1);
		g.s2++;
		g.precision--;
	}
	while (g.precisionadd-- > 0)
		f->n_print += write(1, "0", 1);
}

void	aligned_right_flt_2(t_struct *f, t_fstruct g, char space)
{
	if (f->precision == 0 && f->precision_dot == 1)
		space = ' ';
	if (f->precision == 0 && f->zero == 0 && f->width != 0)
		space = ' ';
	if (f->space == 1)
	{
		f->n_print += write(1, &space, 1);
		g.padding--;
	}
	while (g.padding-- > 0)
		f->n_print += write(1, &g.c, 1);
	if (g.sign != 'a' && g.sign_int)
	{
		if (g.sign_int == 1 && g.sign)
			f->n_print += write(1, &g.sign, 1);
	}
	while (*g.s1)
	{
		f->n_print += write(1, g.s1, 1);
		g.s1++;
	}
}

void	aligned_right_flt(t_struct *f, t_fstruct g)
{
	char	space;

	space = '0';
	if (g.padding > 0 && g.c == '\0')
	{
		if (g.sign_int == 1 && g.sign)
		{
			f->n_print += write(1, &g.sign, 1);
			g.sign = 'a';
			f->space = 0;
		}
	}
	if (f->space == 1 && (f->zero == 0 || f->precision))
		space = ' ';
	if (g.sign == '-' || f->precision == 0)
	{
		if (f->precision == 0 && f->space)
			f->space = 1;
		else
			f->space = 0;
	}
	aligned_right_flt_2(f, g, space);
	aligned_right_flt_3(f, g);
}
