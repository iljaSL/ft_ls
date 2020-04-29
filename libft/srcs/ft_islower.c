/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:31:00 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:28:23 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Checks wheter the passed char is a lowercase letter.
*/

int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
