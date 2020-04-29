/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:50:50 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:33:31 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocates (with malloc) and returns a fresh substirng from the string given
** as a argument. The substring begins at indexstart and is of size len.
** If start and len are not refering to a valid substring, the behavior is
** undefined. If the allocation fails, the function returns NULL.
** The substring will be Returned.
** First we create a fresh allocated string in ft_strnew. With that string
** we will return to our ft_strsub function and start to copie the chars to
** our substring result with increasing i and start until we reache the
** max len or '\0'.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s)
	{
		return (NULL);
	}
	i = 0;
	result = ft_strnew(len);
	if (!result)
	{
		return (NULL);
	}
	while (i < len)
	{
		result[i] = s[start];
		i++;
		start++;
	}
	return (result);
}
