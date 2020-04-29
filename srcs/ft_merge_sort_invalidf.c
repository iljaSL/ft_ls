/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort_invalidf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manager <manager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:17:39 by ismelich          #+#    #+#             */
/*   Updated: 2020/04/27 11:21:43 by manager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** Based on the Merge Sort algorithm for Linked List.
** https://www.geeksforgeeks.org/merge-sort-for-linked-list/
*/

t_ls	*msorted_invalid_fn(t_ls *a, t_ls *b)
{
	t_ls *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->file_name, b->file_name) <= 0)
	{
		result = a;
		result->next = msorted_invalid_fn(a->next, b);
	}
	else
	{
		result = b;
		result->next = msorted_invalid_fn(a, b->next);
	}
	return (result);
}

/*
** We need this separe sort merge for invalid files, because they are
** always sorted in lexical order, regardless of the type of the flags.
*/

void	sort_merge_invalid_file(t_ls **head_ref)
{
	t_ls *head;
	t_ls *a;
	t_ls *b;

	head = *head_ref;
	if (head == NULL || head->next == NULL)
		return ;
	front_back_split(head, &a, &b);
	sort_merge_invalid_file(&a);
	sort_merge_invalid_file(&b);
	*head_ref = msorted_invalid_fn(a, b);
}
