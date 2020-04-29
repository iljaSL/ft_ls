/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manager <manager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 13:32:25 by ismelich          #+#    #+#             */
/*   Updated: 2020/04/27 11:11:40 by manager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** This functions store's the files at the root before the recursion to the
** other directories happens.
*/

t_ls	*store_root_files(t_ls *ls, t_info *info, char *dir_path_str)
{
	struct dirent	*data;
	DIR				*dir;

	dir = opendir(dir_path_str);
	if (dir == NULL)
		return (ls);
	if (info->flags.a == true)
		while ((data = readdir(dir)) != NULL)
			ls = store_fn(ls, data->d_name);
	else if (info->flags.a == false)
		while ((data = readdir(dir)) != NULL)
			if (data->d_name[0] != '.')
				ls = store_fn(ls, data->d_name);
	if (dir != NULL)
		closedir(dir);
	merge_sort(&ls, info);
	return (ls);
}

void	initialize_tinfo(t_info *info)
{
	ft_bzero(&info->flags, sizeof(info->flags));
	info->var.tmp_i = 1;
	info->var.str_len = 0;
	info->var.dbl_break = false;
	info->pad_size = 0;
	info->pad_nlink = 0;
	info->total_blocks = 0;
}

int		main(int argc, char *argv[])
{
	t_ls	*ls;
	t_info	info;

	ls = NULL;
	ft_bzero(&info, sizeof(&info));
	info.argc = argc;
	info.argv = argv;
	if (argc == 1)
		one_arg(ls, &info, ".");
	else if (argc > 1)
		parse(ls, &info);
	if (ls)
		del_fname(&ls);
	return (0);
}
