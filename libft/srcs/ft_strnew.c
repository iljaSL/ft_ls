/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:36:45 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:33:07 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocates (with malloc) and returns a fresh string ending with '\0'.
** Each character of the string is initialized at '\0'. If the allocation
** fails the function returns NULL.
*/

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char*)malloc(sizeof(char) * size + 1);
	if (!str)
	{
		return (NULL);
	}
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
