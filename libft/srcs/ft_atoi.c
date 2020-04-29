/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:41:50 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:26:45 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Converts the str argument to an int. Returns an int value or 0 if it fails.
** Calculation in the while loop works with ascii decimal table.
** First Char '2' is 50 in ascii, 0 * 10 + (50 - 48) = 2, 2 is stored in res.
*/

int	ft_atoi(const char *str)
{
	int		sign;
	int		ans;
	int		len;

	ans = 0;
	sign = 1;
	len = 0;
	while (*str && (*str == '\t' || *str == '\f' || *str == '\r'
				|| *str == '\n' || *str == '\v' || *str == ' '))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? str++ : str;
	while (ft_isdigit(str[len]))
		len++;
	if (len > 19)
		return ((sign > 0) ? -1 : 0);
	while (*str && *str >= 48 && *str <= 57)
		ans = ans * 10 + (*str++ - '0');
	return (sign * ans);
}
