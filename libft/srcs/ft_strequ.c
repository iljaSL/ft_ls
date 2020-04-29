/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:12:51 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:31:35 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Alphabetical order comparison between s1 and s2, If the 2 string are
** identical the function returns 1, or 0 otherwise.
*/

int	ft_strequ(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
	{
		return (0);
	}
	while (s1[i] || s2[i])
	{
		if ((s1[i] - s2[i]) != 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
