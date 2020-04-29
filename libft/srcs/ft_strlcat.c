/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:10:37 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:31:58 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Appends the Nul-terminated string src to the end of dest. It will append
** at most -  size strlen - 1 bytes, NUL-terminating the result.
** Returns the total length of the string it tried to create.
** The src and dest string should not overlap, as the behavior is undefined.
*/

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;
	size_t	dest_l;
	size_t	src_l;

	dest_l = ft_strlen(dest);
	src_l = ft_strlen(src);
	if (destsize == 0 || destsize < dest_l)
	{
		return (destsize + src_l);
	}
	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	while (i < destsize - 1 && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_l + src_l);
}
