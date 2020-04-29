/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manager <manager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:53:25 by ismelich          #+#    #+#             */
/*   Updated: 2020/04/27 10:57:02 by manager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** Check's if the flags are valid acording to our FLAGS defined macro.
*/

bool	is_flag_valid(char c)
{
	int i;

	i = 0;
	while (FLAGS[i])
	{
		if (FLAGS[i] == c)
			return (true);
		i++;
	}
	return (false);
}

bool	set_flags(t_info *info)
{
	if (info->flags.l == true || info->flags.a == true || info->flags.t == true)
		return (true);
	else if (info->flags.r == true || info->flags.cap_r == true)
		return (true);
	else if (info->flags.cap_g == true)
		return (true);
	return (false);
}

/*
** A "switch" function, to determine which flags are used.
*/

void	collect_flags(t_info *info, char c)
{
	if (c == 'l')
		info->flags.l = true;
	else if (c == 'a')
		info->flags.a = true;
	else if (c == 't')
		info->flags.t = true;
	else if (c == 'r')
		info->flags.r = true;
	else if (c == 'R')
		info->flags.cap_r = true;
	else if (c == 'G')
		info->flags.cap_g = true;
}

/*
** Checks if the flags are valid or not.
*/

void	check_flag_option(t_info *info, int i, int j)
{
	if (is_flag_valid(info->argv[i][j]) == true)
		collect_flags(info, info->argv[i][j]);
	else if (is_flag_valid(info->argv[i][j]) == false)
		exit_false_option(info->argv[i][j]);
}

/*
** Gathers the characters after the '-' and returns it.
*/

int		gather_flags(t_info *info, int i, int j)
{
	while (i < info->argc)
	{
		info->var.str_len = ft_strlen(info->argv[i]);
		while (j < info->var.str_len)
		{
			if (info->argv[i][0] == '-')
			{
				(j == 0) && (j = 1);
				check_flag_option(info, i, j);
			}
			else if (info->argv[i][0] != '-')
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (i);
}
