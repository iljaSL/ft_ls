/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 13:47:31 by ismelich          #+#    #+#             */
/*   Updated: 2020/06/02 14:51:51 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** In case of two arguments with an existing -R flag. It will recursively enter
** the directories/subdirectories, store the file names in a linked list, sort
** them, print them out, and move to the next directory until it can not find
** any other directories to treverse through.
*/

void	two_args(t_ls *ls, t_ls *temp_ls, t_info *info, char *path)
{
	if (info->flags.cap_r == false)
		one_arg(ls, info, path);
	else if (info->flags.cap_r == true)
	{
		temp_ls = store_root_files(temp_ls, info, path);
		info->skip_print = false;
		recursive_call(temp_ls, info);
		del_fname(&temp_ls);
	}
}

/*
** In a case of more arguments.
*/

void	more_args(t_ls *ls, t_info *info, int i)
{
	info->skip_print = true;
	info->no_dt_sl = true;
	info->var.tmp_i = i;
	process_dir(ls, info);
}

/*
** Analyzing for flags, initializing the info struct and error handling the
** false ussage of '-'.
*/

void	parse(t_ls *ls, t_info *info)
{
	t_ls	*temp_ls;
	int		i;
	int		j;
	char	current;

	i = 1;
	j = 1;
	current = info->argv[i][0];
	temp_ls = NULL;
	initialize_tinfo(info);
	if ((current != '-') || (current == '-' && info->argv[i][1] == '\0'))
		false_dash_usage(ls, info);
	else if (info->argv[i][0] == '-' && info->argv[i][1] != '\0')
	{
		i = gather_flags(info, i, j);
		if (i == info->argc && (set_flags(info) == false))
			one_arg(ls, info, ".");
		else if (i == 2 && info->argc == 2 && set_flags(info) == true)
			two_args(ls, temp_ls, info, ".");
		else if (i < info->argc)
			more_args(ls, info, i);
	}
}

/*
** A dispatcher function for mergin. deleting and appending the index
** with a '/' case.
*/

void	mda_slash(t_ls *ls, t_info *info, char *dir_path_str)
{
	t_ls *new_ls;

	new_ls = NULL;
	if (ls != NULL)
		new_ls = append_slash(new_ls, ls, dir_path_str);
	del_fname(&ls);
	merge_sort(&new_ls, info);
	print_fn(new_ls, info);
	del_fname(&new_ls);
}

/*
** One argument case function, acting as if it had been invoked with a
** single argument of `.'. By default -ls is sorted alphabetically.
*/

void	one_arg(t_ls *ls, t_info *info, char *dir_path_str)
{
	struct dirent	*data;
	DIR				*dir;

	dir = opendir(dir_path_str);
	if (dir == NULL)
		perm_denied(dir_path_str);
	else if (dir != NULL)
	{
		if (info->flags.a == true)
			while ((data = readdir(dir)) != NULL)
				ls = store_fn_i(ls, data->d_name, 0);
		else if (info->flags.a == false)
			while ((data = readdir(dir)) != NULL)
				if (data->d_name[0] != '.')
					ls = store_fn_i(ls, data->d_name, 0);
	}
	if (dir != NULL)
	{
		closedir(dir);
		mda_slash(ls, info, dir_path_str);
	}
}
