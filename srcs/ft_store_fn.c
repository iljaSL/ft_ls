/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_fn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manager <manager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:04:41 by ismelich          #+#    #+#             */
/*   Updated: 2020/04/27 11:17:49 by manager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ls	*append(t_ls *head, char *valid_file_pth)
{
	t_ls	*cursor;
	t_ls	*new_node;

	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	new_node = create(valid_file_pth);
	cursor->next = new_node;
	return (head);
}

t_ls	*create(char *valid_file_pth)
{
	t_ls	*new_node;

	new_node = malloc(sizeof(t_ls));
	if (new_node == NULL)
		exit(EXIT_SUCCESS);
	new_node->file_name = ft_strdup(valid_file_pth);
	new_node->next = NULL;
	return (new_node);
}

/*
** Stores the file names wihtout an index in a linked list. Append's and
** creates the file names with the help of an array version of a
** linked list.
*/

t_ls	*store_fn(t_ls *ls, char *fn)
{
	if (ls == NULL)
		ls = create(fn);
	else
		ls = append(ls, fn);
	return (ls);
}
