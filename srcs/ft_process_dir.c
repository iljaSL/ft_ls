/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manager <manager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 11:44:04 by ismelich          #+#    #+#             */
/*   Updated: 2020/06/02 14:22:46 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	files_from_dir(t_ls *ls, t_ls *tmp_ls, t_info *info)
{
	int	nbr_nodes;

	nbr_nodes = get_count(tmp_ls);
	while (tmp_ls)
	{
		(info->var.new_line == true) && (write(1, "\n", 1));
		(nbr_nodes == 2) && (ft_printf("%s:\n", tmp_ls->file_name));
		one_arg(ls, info, tmp_ls->file_name);
		info->var.new_line = true;
		tmp_ls = tmp_ls->next;
	}
}

/*
** Storing valid directories, including the one with permission denied.
*/

t_ls	*store_dir(t_ls *tmp_ls, t_info *info)
{
	struct stat	meta;
	DIR			*dir;

	while (info->var.i < info->argc)
	{
		dir = opendir(info->argv[info->var.i]);
		if (stat(info->argv[info->var.i], &meta) == 0)
			if (S_ISDIR(meta.st_mode) == 1)
				tmp_ls = store_fn(tmp_ls, info->argv[info->var.i]);
		(dir != NULL) && (closedir(dir));
		info->var.i++;
	}
	return (tmp_ls);
}

/*
** Stores the names of directories in a linked list and sorted with sort merge.
** The names will be passed through files_from_dir, so all the content of each
** directory can be printed.
*/

void	process_dir_valid(t_ls *ls, t_info *info)
{
	t_ls	*tmp_dir;

	tmp_dir = NULL;
	tmp_dir = store_dir(tmp_dir, info);
	merge_sort(&tmp_dir, info);
	if (info->flags.cap_r == false)
	{
		files_from_dir(ls, tmp_dir, info);
		del_fname(&tmp_dir);
	}
	else if (info->flags.cap_r == true)
	{
		info->var.new_line = false;
		if (get_count(tmp_dir) == 2)
			info->print_path = true;
		else
			info->print_path = false;
		recursive_call(tmp_dir, info);
		del_fname(&tmp_dir);
	}
}

/*
** The dispatcher function in order to process the directories and files
** inside it.
*/

void	process_dir(t_ls *ls, t_info *info)
{
	info->var.new_line = false;
	info->print_path = false;
	info->var.i = info->var.tmp_i;
	process_invalid_file(ls, info);
	info->var.i = info->var.tmp_i;
	process_valid_file(ls, info);
	info->var.i = info->var.tmp_i;
	process_dir_valid(ls, info);
}
