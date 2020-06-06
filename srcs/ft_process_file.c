/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 11:50:55 by ismelich          #+#    #+#             */
/*   Updated: 2020/06/04 17:24:17 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** Checks if the file is regular or not, plus if it's a directory with the
** help of S_ISREG. Valid files are files that maybe don't have a file extens
** like main.c/main.o or just simply called main. It will be stored in a
** linked list, sorted with the merge sort alg, and finnaly will be printed.
*/

void	process_valid_file(t_ls *ls, t_info *info)
{
	struct stat	meta;
	char		**arg_str;
	int			arg_count;
	int			i;

	arg_str = info->argv;
	arg_count = info->argc;
	i = info->var.i;
	while (i < arg_count)
	{
		if ((stat(arg_str[i], &meta) == 0) && (S_ISREG(meta.st_mode)))
			ls = store_fn(ls, arg_str[i]);
		i++;
	}
	if (ls != NULL)
	{
		merge_sort(&ls, info);
		print_fn(ls, info);
		del_fname(&ls);
		info->var.new_line = true;
		info->print_path = true;
		info->no_dt_sl = true;
	}
}

/*
** Stores file that do not exist inside linked list, sorts them in lexical
** order and print's them out.
*/

void	process_invalid_file(t_ls *ls, t_info *info)
{
	struct stat	meta;
	int			file_status;
	int			i;
	int			arg_count;
	char		**arg_str;

	arg_str = info->argv;
	arg_count = info->argc;
	i = info->var.i;
	while (i < arg_count)
	{
		file_status = stat(arg_str[i], &meta);
		if (file_status == -1)
			ls = store_fn(ls, arg_str[i]);
		i++;
	}
	if (ls != NULL)
	{
		sort_merge_invalid_file(&ls);
		print_invalidfn(ls);
		del_fname(&ls);
		info->print_path = true;
		info->no_dt_sl = true;
	}
}
