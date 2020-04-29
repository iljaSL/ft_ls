/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:55:56 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:23:14 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Duplicates a string. It returns a pointer to null terminated byte string.
*/

char	*ft_strdup(const char *src)
{
	int		i;
	char	*c;

	i = 0;
	while (src[i])
	{
		i++;
	}
	if (!(c = (char *)malloc(sizeof(*c) * (i + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		c[i] = src[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
