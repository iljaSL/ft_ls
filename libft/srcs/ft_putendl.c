/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:48:09 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:30:24 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Outputs the string to the standard outut followed by a new line.
*/

void	ft_putendl(char	const *str)
{
	if (!str)
		return ;
	ft_putstr(str);
	ft_putchar('\n');
}
