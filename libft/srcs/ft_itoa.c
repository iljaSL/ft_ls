/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:06:08 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:28:53 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Converts int data type to string data type.
** len-- - 1: We start from the end of the array and skip '\0' with -1.
** n(21) % 10 + 48(ascii 0) = 50.1, we just have space for 1 char in our
** array so 1 would be save in str. With n / 10 we take the 1 away and do
** the math with 2 again, 48.2 would be the result, we place 2 in the array
** the returned str would be 21.
** In case of a minus int: The minus would be stored in the array as a char
** on str[0] and removed from the int with -n.
*/

static int		length(int n)
{
	int len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		len = 1;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = length(n);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[len-- - 1] = '8';
			n = n / 10;
		}
		n = -n;
	}
	while (n != 0 && len >= 0)
	{
		str[len-- - 1] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
