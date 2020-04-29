/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_calls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manager <manager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 10:55:27 by ismelich          #+#    #+#             */
/*   Updated: 2020/04/28 10:37:43 by manager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** Source of the logic in the Readme file.
*/

t_ls	*store_inner_file_rec(t_ls *temp_ls, t_info *info, DIR *dir)
{
	struct dirent *dr;

	if (info->flags.a == true)
		while ((dr = readdir(dir)) != NULL)
			temp_ls = store_fn(temp_ls, dr->d_name);
	else if (info->flags.a == false)
		while ((dr = readdir(dir)) != NULL)
			if (dr->d_name[0] != '.')
				temp_ls = store_fn(temp_ls, dr->d_name);
	if (dir != NULL)
		closedir(dir);
	return (temp_ls);
}

void	print_dirpth_rec(t_info *info, char *path)
{
	if (info->skip_print == false)
	{
		if (info->no_dot_slash == false)
			ft_printf("\n./%s:\n", path);
		else if (info->no_dot_slash == true)
			ft_printf("\n%s:\n", path);
	}
	else if (info->print_path == true)
		ft_printf("%s:\n", path);
}

t_ls	*store_file_rec(t_info *info, char *path)
{
	DIR		*dir;
	t_ls	*temp_ls;
	t_ls	*new_ls;

	temp_ls = NULL;
	new_ls = NULL;
	dir = opendir(path);
	if (dir == NULL)
	{
		(info->no_dot_slash == false) && (ft_printf(BG_RED"\n./%s\n"RESET, path));
		(info->no_dot_slash == true) && (ft_printf(BG_RED"\n%s\n"RESET, path));
		perm_denied(path + find_last_slash(path));
		return (NULL);
	}
	else if (info->skip_print == false || info->print_path == true)
		print_dirpth_rec(info, path);
	temp_ls = store_inner_file_rec(temp_ls, info, dir);
	(temp_ls != NULL) && (new_ls = append_slash(new_ls, temp_ls, path));
	del_fname(&temp_ls);
	merge_sort(&new_ls, info);
	return (new_ls);
}

void	handle_inner_dir(t_ls *inner_dir, t_info *info, char *ref_str)
{
	if (info->flags.a == false && ref_str[0] != '.')
		inner_dir = store_file_rec(info, ref_str);
	else if (info->flags.a == true)
		inner_dir = store_file_rec(info, ref_str);
	info->skip_print = false;
	if (inner_dir != NULL)
	{
		recursive_call(inner_dir, info);
		del_fname(&inner_dir);
	}
}

/*
** A recursive call when the -R flag appears. The Program is going through the
** directories and subdirectories recursively and stores the files in a linked
** list. It stores them, prints, frees the linked list and moves on to the next
** directory. Skip_print is used to avoid printing a valid directory straight
** in the beginning.
*/

int		recursive_call(t_ls *temp_ls, t_info *info)
{
	t_ls		*inner_dir;
	struct stat	meta;
	char		*ref_str;

	inner_dir = NULL;
	if (temp_ls != NULL && temp_ls->file_name && info->skip_print == false)
		print_fn(temp_ls, info);
	while (temp_ls != NULL)
	{
		ref_str = temp_ls->file_name;
		if (ft_strcmp(ref_str, ".") != 0 && ft_strcmp(ref_str, "..") != 0)
			if (stat(ref_str, &meta) == 0 && S_ISDIR(meta.st_mode))
				handle_inner_dir(inner_dir, info, ref_str);
		temp_ls = temp_ls->next;
	}
	return (0);
}
