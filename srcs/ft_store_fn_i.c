/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_fn_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manager <manager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 14:09:52 by ismelich          #+#    #+#             */
/*   Updated: 2020/04/23 12:17:18 by manager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** https://stackoverflow.com/questions/2589533/what-is-a-cursor-linked-list-c
** An array version of a linked list.
*/

t_ls	*create_index(char *valid_filepth, int index)
{
	t_ls	*new_node;

	new_node = malloc(sizeof(t_ls));
	if (new_node == NULL)
		exit(EXIT_SUCCESS);
	new_node->file_name = ft_strdup(valid_filepth);
	new_node->slash_index = index;
	new_node->next = NULL;
	return (new_node);
}

/*
** We are creating an array version of a Linked List.  Essentially you have an
** array of list nodes but instead of each node containing a pointer to the
** next item in the linked list, each node element in the array contains the
** index for the next node element.
*/

t_ls	*append_index(t_ls *head, char *valid_filepth, int index)
{
	t_ls	*cursor;
	t_ls	*new_node;

	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	new_node = create_index(valid_filepth, index);
	cursor->next = new_node;
	return (head);
}

/*
** Dispatcher for create_index and append_index, for storing
** file names in a linked list with a slash index srcs/.
*/

t_ls	*store_fn_i(t_ls *ls, char *fname, int index)
{
	if (ls == NULL)
		ls = create_index(fname, index);
	else
		ls = append_index(ls, fname, index);
	return (ls);
}
