/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 10:16:54 by ismelich          #+#    #+#             */
/*   Updated: 2020/06/02 14:44:48 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_nbrlen(int_fast64_t value, int base)
{
	uint_fast64_t	u_value;
	int				i;

	i = 0;
	u_value = (uint_fast64_t)value;
	if (value == 0)
		return (0);
	if (value < 0 && base == 10)
		i++;
	while (base == 10 && value)
	{
		value = value / base;
		i++;
	}
	while (base != 10 && u_value)
	{
		u_value = u_value / base;
		i++;
	}
	return (i);
}
