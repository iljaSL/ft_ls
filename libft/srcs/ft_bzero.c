/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:44:57 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:25:50 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Places n zero valued bytes in the area pointed to by s.
** n = 5 "Hello" -> '\0''\0''\0''\0''\0''\0'
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
