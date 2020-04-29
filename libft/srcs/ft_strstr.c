/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:06:22 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:33:26 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Finds the first occurrence of the substring search_string in the string str.
** The terminating '\0' characters are not compared.
** Returns a pointer to the first occurrence in str of any of the entire
** sequence of characters sppecified in search_string, or a null pointer
** if the sequence is not present in str.
** The index inside the loop in the while loop will be seacherd for common
** chars in all strings, the str[i + j] adds the incresed j to the i we
** got from strlen to move through the index from str.
** After the matching string is found and
** stored in [i], str wil be addressed with & and with strlen we create the
** amount of space we need to print out the matching search_string.
*/

char	*ft_strstr(const char *str, const char *search_string)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*search_string == '\0')
	{
		return ((char*)str);
	}
	while (str[i] != 0)
	{
		j = 0;
		while (str[i + j] == search_string[j] && str[i + j] != 0)
		{
			j++;
		}
		if (j == ft_strlen(search_string))
		{
			return ((char*)&str[i]);
		}
		i++;
	}
	return (NULL);
}
