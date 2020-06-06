/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 11:15:10 by ismelich          #+#    #+#             */
/*   Updated: 2020/06/02 14:49:49 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** Based on the Merge Sort algorithm for Linked List.
** https://www.geeksforgeeks.org/merge-sort-for-linked-list/
*/

t_ls	*sorted_merge_rev(t_ls *a, t_ls *b)
{
	t_ls *res;

	res = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(b->file_name, a->file_name) > 0)
	{
		res = b;
		res->next = sorted_merge_rev(a, b->next);
	}
	else
	{
		res = a;
		res->next = sorted_merge_rev(a->next, b);
	}
	return (res);
}

t_ls	*sorted_merge(t_ls *a, t_ls *b)
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
		result->next = sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next);
	}
	return (result);
}

void	front_back_split(t_ls *src, t_ls **front_ref, t_ls **back_ref)
{
	t_ls *fast;
	t_ls *slow;

	slow = src;
	fast = src->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_ref = src;
	*back_ref = slow->next;
	slow->next = NULL;
}

/*
** The dispatcher function for our Merge Sort algorithm for Linked List.
** With different flag cases.
*/

void	merge_sort(t_ls **head_ref, t_info *info)
{
	t_ls *head;
	t_ls *a;
	t_ls *b;

	head = *head_ref;
	if (head == NULL || head->next == NULL)
		return ;
	front_back_split(head, &a, &b);
	merge_sort(&a, info);
	merge_sort(&b, info);
	if (info->flags.r == false && info->flags.t == false)
		*head_ref = sorted_merge(a, b);
	else if (info->flags.r == true && info->flags.t == false)
		*head_ref = sorted_merge_rev(a, b);
	else if (info->flags.t == true && info->flags.r == false)
		*head_ref = sorted_merge_time(a, b);
	else if (info->flags.t == true && info->flags.r == true)
		*head_ref = sorted_merge_time_rev(a, b);
}
