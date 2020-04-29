/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:07:26 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:31:47 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Applies the function f to each character of the string passed as argument
** and passing its index as first argument. Each character is passed by
** address to f to be modified if necessary.
** In the while loop I call the function ita(which is in the main) inside
** my ft_striteri function to print out the string which I address through
** &s. I increament the index afte I return from the iter function and do
** the same step until I reach '\0'. I print out the index as well while
** through the functions.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}
