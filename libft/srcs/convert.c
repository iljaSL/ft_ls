/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:39:03 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:09:36 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** In convert we dispatch to different function depending on the specifier
** found in the ft_printf funtion.
*/

void	convert(char c, va_list ap, t_struct *f)
{
	if (c == 'c')
		display_char(f, ap);
	else if (c == 's')
		display_str(f, ap);
	else if (c == 'u')
		display_uint(f, ap);
	else if (c == 'p')
		display_pointer(f, ap, 2);
	else if (c == '%')
		percent_case(f);
	else if (c == 'x' || c == 'X')
		display_hex(f, ap, c);
	else if (c == 'o')
		display_octal(f, ap);
	else if (c == 'd' || c == 'i')
		display_int(f, ap, 0, 0);
	else if (c == 'f')
		display_float(f, ap);
}
