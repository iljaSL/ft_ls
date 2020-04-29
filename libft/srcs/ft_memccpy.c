/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:19:42 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:29:05 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Copy bytes from memory area str2 into str1, stopping after the first
** occurrence of byte c.
*/

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	unsigned char	*tmpstr1;
	unsigned char	*tmpstr2;
	unsigned char	tmpc;
	size_t			i;

	i = 0;
	tmpstr1 = (unsigned char*)str1;
	tmpstr2 = (unsigned char*)str2;
	tmpc = (unsigned char)c;
	while (n > 0)
	{
		tmpstr1[i] = tmpstr2[i];
		if (tmpstr2[i] == tmpc)
		{
			i++;
			return ((void*)&tmpstr1[i]);
		}
		i++;
		n--;
	}
	return (NULL);
}
