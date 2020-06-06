/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 11:24:55 by ismelich          #+#    #+#             */
/*   Updated: 2020/06/04 17:28:41 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		get_count(t_ls *ls)
{
	int count;

	count = 0;
	if (ls)
		while (ls)
		{
			ls = ls->next;
			count++;
			if (count == 2)
				break ;
		}
	return (count);
}

char	*ft_strsub_ls(char *dest, char *source, int start)
{
	int i;

	i = 0;
	if (source)
		while (source[start])
			dest[i++] = source[start++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strsub_start_end(char *dest, char *source, int start, int end)
{
	int i;

	i = 0;
	if (source)
		while (end && source[start])
		{
			dest[i++] = source[start++];
			end--;
		}
	dest[i] = '\0';
	return (dest);
}

/*
** Prints out the invalid file name.
*/

void	print_invalidfn(t_ls *ls)
{
	char	*invalid_str;

	while (ls)
	{
		invalid_str = ls->file_name;
		ft_printf("ft_ls: ");
		perror(invalid_str);
		ls = ls->next;
	}
}

void	get_total_for_long_listing(t_ls *ls)
{
	struct stat	meta;
	int			total;

	total = 0;
	while (ls)
	{
		stat(ls->file_name, &meta);
		total = total + meta.st_blocks;
		ls = ls->next;
	}
	ft_printf("total %d\n", total);
}
