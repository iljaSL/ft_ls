/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort_time.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manager <manager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 11:47:04 by ismelich          #+#    #+#             */
/*   Updated: 2020/04/27 11:19:14 by manager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** Based on the Merge Sort algorithm for Linked List.
** https://www.geeksforgeeks.org/merge-sort-for-linked-list/
*/

t_ls	*sorted_merge_time_nano_sec_rev(t_ls *a, t_ls *b)
{
	t_ls		*result;
	struct stat meta1;
	struct stat meta2;

	result = NULL;
	lstat(a->file_name, &meta1);
	lstat(b->file_name, &meta2);
	if (meta1.st_mtimespec.tv_nsec < meta2.st_mtimespec.tv_nsec)
	{
		result = a;
		result->next = sorted_merge_time_rev(a->next, b);
	}
	else
	{
		result = b;
		result->next = sorted_merge_time_rev(a, b->next);
	}
	return (result);
}

t_ls	*sorted_merge_time_rev(t_ls *a, t_ls *b)
{
	t_ls		*result;
	struct stat meta1;
	struct stat meta2;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	lstat(a->file_name, &meta1);
	lstat(b->file_name, &meta2);
	if (meta1.st_mtimespec.tv_sec < meta2.st_mtimespec.tv_sec)
	{
		result = a;
		result->next = sorted_merge_time_rev(a->next, b);
	}
	else if (meta1.st_mtimespec.tv_sec == meta2.st_mtimespec.tv_sec)
		result = sorted_merge_time_nano_sec_rev(a, b);
	else
	{
		result = b;
		result->next = sorted_merge_time_rev(a, b->next);
	}
	return (result);
}

t_ls	*sorted_merge_time_nano_sec(t_ls *a, t_ls *b)
{
	t_ls		*result;
	struct stat	meta1;
	struct stat	meta2;

	result = NULL;
	lstat(a->file_name, &meta1);
	lstat(b->file_name, &meta2);
	if (meta1.st_mtimespec.tv_nsec >= meta2.st_mtimespec.tv_nsec)
	{
		result = a;
		result->next = sorted_merge_time(a->next, b);
	}
	else
	{
		result = b;
		result->next = sorted_merge_time(a, b->next);
	}
	return (result);
}

t_ls	*sorted_merge_time(t_ls *a, t_ls *b)
{
	t_ls		*result;
	struct stat meta1;
	struct stat meta2;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	lstat(a->file_name, &meta1);
	lstat(b->file_name, &meta2);
	if (meta1.st_mtimespec.tv_sec > meta2.st_mtimespec.tv_sec)
	{
		result = a;
		result->next = sorted_merge_time(a->next, b);
	}
	else if (meta1.st_mtimespec.tv_sec == meta2.st_mtimespec.tv_sec)
		result = sorted_merge_time_nano_sec(a, b);
	else
	{
		result = b;
		result->next = sorted_merge_time(a, b->next);
	}
	return (result);
}
