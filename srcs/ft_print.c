/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manager <manager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 09:54:51 by ismelich          #+#    #+#             */
/*   Updated: 2020/04/28 10:06:14 by manager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** Determines if file is a link and prints out the path of the link.
*/

void	file_is_link(char *link_str, char *ls_file_name, char *str)
{
	ft_bzero(link_str, _POSIX_PATH_MAX);
	readlink(ls_file_name, link_str, _POSIX_PATH_MAX);
	ft_printf("%s -> %s\n", str, link_str);
}

/*
** Flag -G case function. Takes in the file name with the file path, plus
** the meta information inside the stat struct. Directory will be printed
** blue and an executable file in red.
** st_mode -> File type and mode. S_ISDIR-> directory?
*/

void	print_cap_g(char *str, struct stat meta)
{
	if (S_ISDIR(meta.st_mode))
		ft_printf(BLUE"%s\n"RESET, str);
	else if (meta.st_mode & S_IXUSR)
		ft_printf(RED"%s\n"RESET, str);
	else
		ft_printf("%s\n", str);
}

/*
** Another iterating dispatcher function for printing out the file name's.
*/

void	format_and_print(t_ls *ls, t_info *info, char *str, char *link_str)
{
	struct stat	meta;

	while (ls)
	{
		lstat(ls->file_name, &meta);
		str[0] = 0;
		if (ls->slash_index >= 0)
			ft_strsub_ls(str, ls->file_name, ls->slash_index);
		else if (ls->slash_index < 0)
			ft_strcpy(str, ls->file_name);
		if (info->flags.l == true)
			long_format(meta, ls->file_name, info);
		if (S_ISLNK(meta.st_mode) && info->flags.l == true)
			file_is_link(link_str, ls->file_name, str);
		else if (info->flags.cap_g == true)
			print_cap_g(str, meta);
		else
			ft_printf("%s\n", str);
		ls = ls->next;
	}
}

/*
** Dispatcher function for printing and formatting.
*/

void	print_fn(t_ls *ls, t_info *info)
{
	char	*str;
	char	*link_str;

	info->pad_size = 0;
	info->pad_nlink = 0;
	link_str = NULL;
	str = malloc(sizeof(char) * (_POSIX_PATH_MAX));
	if (str == NULL)
		return ;
	if (info->flags.l == true)
	{
		link_str = malloc(sizeof(char) * (_POSIX_PATH_MAX));
		padding_and_blocks(ls, &info->pad_nlink, &info->pad_size);
	}
	format_and_print(ls, info, str, link_str);
	free(str);
	if (info->flags.l == true)
		free(link_str);
}
