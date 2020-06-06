/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_and_del.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manager <manager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 10:01:07 by ismelich          #+#    #+#             */
/*   Updated: 2020/06/02 14:21:34 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
**  Delte's the linked list which is storing the file name.
*/

void	del_fname(t_ls **head_ref)
{
	t_ls *crnt_node;
	t_ls *next_node;

	crnt_node = *head_ref;
	while (crnt_node != NULL)
	{
		next_node = crnt_node->next;
		if (crnt_node->file_name)
			free(crnt_node->file_name);
		if (crnt_node)
			free(crnt_node);
		crnt_node = next_node;
	}
	*head_ref = NULL;
}

int		max(int nbr1, int nbr2)
{
	if (nbr1 > nbr2)
		return (nbr1);
	return (nbr2);
}

/*
** Print's out the total number of BLOCKS. Meaning, the total disk
** allocation for all files in that directory.
*/

void	padding_and_blocks(t_ls *ls, int *pad_nlink, int *pad_size)
{
	struct stat	meta;
	int			total;

	total = 0;
	while (ls)
	{
		stat(ls->file_name, &meta);
		total = total + meta.st_blocks;
		*pad_nlink = max(ft_nbrlen(meta.st_nlink, D), *pad_nlink);
		*pad_size = max(ft_nbrlen(meta.st_size, D), *pad_size);
		ls = ls->next;
	}
	if (total > 0)
		ft_printf("total %d\n", total);
}
