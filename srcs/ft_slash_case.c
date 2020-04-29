/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slash_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manager <manager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 10:52:33 by ismelich          #+#    #+#             */
/*   Updated: 2020/04/28 10:00:46 by manager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** Returns the index of the last occured '/' in the file path.
*/

int		find_last_slash(char *file_path_with_slash)
{
	int len;

	len = 0;
	len = ft_strlen(file_path_with_slash) - 1;
	if (len <= 0)
		return (0);
	while (len)
	{
		if (file_path_with_slash[len] == '/')
			return (len + 1);
		len--;
	}
	return (0);
}

/*
** Create's a new list with the full str path and the index after '/'.
*/

t_ls	*get_new_ls(t_ls *new_ls, t_ls *temp_ls, char *full_path, int slash_i)
{
	char	*ref_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (temp_ls && temp_ls->file_name)
	{
		ref_str = temp_ls->file_name;
		i = slash_i;
		j = 0;
		if (ft_strcmp(ref_str, ".") == 0 || ft_strcmp(ref_str, "..") == 0)
			new_ls = store_fn_i(new_ls, ref_str, 0);
		else
		{
			while (ref_str[j])
				full_path[i++] = ref_str[j++];
			full_path[i] = '\0';
			new_ls = store_fn_i(new_ls, full_path, slash_i);
		}
		temp_ls = temp_ls->next;
	}
	return (new_ls);
}

/*
** Append's the index after '/' with the allocated space and
** limit permitted by POSIX for the max number of bytes in a
** file name. _POSIX_PATH_MAX = 256.
*/

t_ls	*append_slash(t_ls *new_ls, t_ls *temp_ls, char *path)
{
	char	*full_path;
	int		i;
	int		j;
	int		slash_i;

	full_path = malloc(sizeof(char) * (_POSIX_PATH_MAX));
	i = 0;
	j = 0;
	slash_i = 0;
	full_path[0] = 0;
	if (path)
	{
		while (path[j])
			full_path[i++] = path[j++];
		(full_path[i - 1] != '/') && (full_path[i++] = '/');
		full_path[i] = '\0';
	}
	slash_i = i;
	new_ls = get_new_ls(new_ls, temp_ls, full_path, slash_i);
	free(full_path);
	return (new_ls);
}
