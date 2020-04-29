/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:52:09 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:34:19 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		snbr_len(intmax_t n, int base)
{
	int	n_len;

	n_len = 0;
	if (n < 0)
	{
		n = -n;
		n_len++;
	}
	while (n)
	{
		n = n / base;
		n_len++;
	}
	return (n_len);
}

void	error(void)
{
	write(1, "", 0);
}
