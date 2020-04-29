/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:38:08 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:33:35 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocates (with malloc) and returns a copy of the string given as argument
** wihtout whitespaces at the beginning or at the end of the string.
** If s has no whitespaces at the beginning or at the end, the function
** returns a copy of s. If the allocation fails the function returns NULL.
** Return Value is a fresh trimmed string or a copy of s.
** First we check the length of the string with ft_strlen, we store it in end.
** Now we check the whitespace at the start and str++ until we find a char.
** Now we check the whitespace at the end we end - 1, so we dont include '\0'.
** With the difference of end - start we can say how many characters we have
** in our array, with that we create a fresh string with ft_strnew.
** We copie the chars with ft_strncpy, res is our dst, s + start our src
** (thats we our string begins without whitespace) and end - len our len.
*/

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*res;

	if (!s)
	{
		return (NULL);
	}
	start = 0;
	end = ft_strlen(s);
	while (ft_isspace(s[start]))
		start++;
	while (ft_isspace(s[end - 1]))
		end--;
	if (end < start)
		end = start;
	res = ft_strnew(end - start);
	if (res == NULL)
		return (NULL);
	return (ft_strncpy(res, s + start, end - start));
}
