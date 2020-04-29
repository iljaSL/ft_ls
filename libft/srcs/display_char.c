/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 09:20:25 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:11:04 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** A function for the case of a %% input.
*/

void	percent_case(t_struct *f)
{
	int	nbr;

	if (f->width != 0 && f->minus == 0)
	{
		nbr = f->width - 1;
		if (f->zero != 0)
			write_zeros(nbr);
		else
			write_blank(nbr);
		write(1, "%", 1);
		f->n_print = f->n_print + nbr + 1;
	}
	else if (f->width && f->minus == 1)
	{
		nbr = f->width - 1;
		write(1, "%", 1);
		write_blank(nbr);
		f->n_print = f->n_print + nbr + 1;
	}
	else
	{
		write(1, "%", 1);
		f->n_print++;
	}
}

/*
** Print Character if %c is found with special case for 0 or whitespace.
*/

void	display_char(t_struct *f, va_list ap)
{
	int				nbr;
	unsigned char	c;

	nbr = 0;
	c = (unsigned char)va_arg(ap, int);
	if (f->width && f->minus == 0)
	{
		nbr = f->width - 1;
		if (f->zero != 0)
			write_zeros(nbr);
		else if (f->zero == 0)
			write_blank(nbr);
		write(1, &c, 1);
		f->n_print = f->n_print + nbr;
	}
	else if (f->width && f->minus == 1)
	{
		nbr = f->width - 1;
		write(1, &c, 1);
		write_blank(nbr);
		f->n_print = f->n_print + nbr;
	}
	else
		write(1, &c, 1);
	f->n_print++;
}
