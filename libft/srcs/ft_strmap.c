/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:35:41 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:32:06 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Applies the function f (in my case the map function in main) to each
** character of the string given as argument to create a fresh new string
** (with malloc) resulting from the successive applications of f.
** Returns the fresh string created from the successive applications of f.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	len;
	unsigned int	i;
	char			*str;

	if (!s || !f)
	{
		return (NULL);
	}
	i = 0;
	len = ft_strlen(s);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
	{
		return (NULL);
	}
	while (s[i])
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
