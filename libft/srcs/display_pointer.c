/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:46:06 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:11:34 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** A counter function with a base of 16.
*/

int		hex_count(unsigned long long nbr)
{
	int	i;

	i = 0;
	while (nbr / 16)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

/*
** Checks for extra case on the left of the input and prints it out.
*/

int		aligned_right_p(int width_p, int precision_p, int hex_len, char *s)
{
	int	i;

	i = 0;
	while (width_p > 0)
	{
		i += write(1, " ", 1);
		width_p--;
	}
	i += write(1, "0x", 2);
	while (precision_p > 0)
	{
		i += write(1, "0", 1);
		precision_p--;
	}
	i += write(1, s, hex_len);
	return (i);
}

/*
** Checks for extra case on the left of the input and
** print the address out.
*/

int		aligned_left_p(int width_p, int precision_p, int hex_len, char *s)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	while (precision_p > 0)
	{
		i += write(1, "0", 1);
		precision_p--;
	}
	i += write(1, s, hex_len);
	while (width_p > 0)
	{
		i += write(1, " ", 1);
		width_p--;
	}
	return (i);
}

/*
** Displays the Pointer address if %p is found, ft_itoa_base is
** needed for transforming the int to an str.
*/

void	display_pointer(t_struct *f, va_list ap, int hexp_header)
{
	int					hex_len;
	char				*s;
	int					precision_p;
	int					width_p;
	unsigned long long	pointer;

	pointer = (unsigned long long)va_arg(ap, void *);
	hex_len = hex_count(pointer) + 1;
	s = ft_itoa_base(pointer, 16);
	precision_p = f->precision - hex_len;
	width_p = f->width - hex_len - hexp_header;
	if (f->precision_dot && f->precision == 0)
		hex_len = 0;
	if (f->minus)
		f->n_print += aligned_left_p(width_p, precision_p, hex_len, s);
	else
		f->n_print += aligned_right_p(width_p, precision_p, hex_len, s);
	free(s);
}
