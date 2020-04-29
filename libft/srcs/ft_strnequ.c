/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:34:00 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:32:40 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Alphabetical oder comparison between s1 and s2 up to n character or until
** a '\0' is reached. If the 2 strings are identical, the function returns
** 1 or 0 otherwise.
*/

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
	{
		return (0);
	}
	while ((s1[i] || s2[i]) && n > 0)
	{
		if (s1[i] - s2[i] != 0)
		{
			return (0);
		}
		i++;
		n--;
	}
	return (1);
}
