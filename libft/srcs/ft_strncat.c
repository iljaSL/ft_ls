/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:39:18 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:32:16 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Appends the string pointed to by src to the end of the string pointed to by
** dest up to n characters long.
*/

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	l;

	if (*src)
	{
		i = 0;
		l = 0;
		while (dest[l])
		{
			l++;
		}
		while (src[i] && i < n)
		{
			dest[l + i] = src[i];
			i++;
		}
		dest[l + i] = '\0';
	}
	return (dest);
}
