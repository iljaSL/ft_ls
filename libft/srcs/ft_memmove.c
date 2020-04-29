/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:35:12 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:29:45 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Copies n characters from str2 to str1, but for overlapping memory blocks,
** memmove is a safer approach than memcpy.
** If str2 is lesser than str1 it will just copy whats inside str2 with
** n--, so we starting from the end of the array, ignoring the empty space
** in str1, so we are able to move the chars into str1.
*/

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	*tmpstr1;
	char	*tmpstr2;
	size_t	i;

	if (!str1 && !str2)
		return (NULL);
	tmpstr1 = (char*)str1;
	tmpstr2 = (char*)str2;
	i = 0;
	if (tmpstr2 < tmpstr1)
		while (n > 0)
		{
			tmpstr1[n - 1] = tmpstr2[n - 1];
			n--;
		}
	else
	{
		while (i < n)
		{
			tmpstr1[i] = tmpstr2[i];
			i++;
		}
	}
	return (str1);
}
