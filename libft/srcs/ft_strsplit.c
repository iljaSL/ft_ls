/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:05:06 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:33:22 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocates (with malloc) and returns and array of fresh strings
** (all ending with '\0', including the array itself) obtained by spliting
** s using the character c as a delimiter (example ','). If the allocation
** fails the function returns NULL. Return would be the string
** representing the integer passed as argument.
** We count the strings in count_strings, we go through the index of the array
** as well, we return the nbr_str to ft_strsplit and allocate the space we
** need. After that we go again through the string and the index to detect
** if there is any c chars, now we duplicate the result we have got from the
** while loops in strndup with the amount of s we have and the len of the
** index without the c char '*' (in our example case). We save the duplication
** in result[l], we check one last time if there are no '*' in our s. We return
** the result.
*/

static int	count_strings(char *str, char c)
{
	int		nbr_strs;

	nbr_strs = 0;
	while (*str)
	{
		while (*str == c && *str)
		{
			str++;
		}
		if (*str != c && *str)
		{
			nbr_strs++;
		}
		while (*str != c && *str)
		{
			str++;
		}
	}
	return (nbr_strs);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	nbr_strs;
	char	**result;
	size_t	i;
	size_t	l;

	if (!s)
		return (NULL);
	l = 0;
	nbr_strs = count_strings((char*)s, c);
	if (!(result = (char**)malloc(sizeof(char*) * nbr_strs + 1)))
		return (NULL);
	while (l < nbr_strs)
	{
		i = 0;
		while (*s == c && *s)
			s++;
		while (s[i] != c && s[i])
			i++;
		result[l] = ft_strndup((char*)s, i);
		l++;
		while (*s != c && *s)
			s++;
	}
	result[l] = NULL;
	return (result);
}
