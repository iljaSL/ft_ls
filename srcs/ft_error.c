/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manager <manager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 14:03:20 by ismelich          #+#    #+#             */
/*   Updated: 2020/04/27 10:50:16 by manager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	exit_false_option(char c)
{
	ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_printf("usage: ft_ls [-GRalrt] [file ...]\n");
	exit(EXIT_SUCCESS);
}

void	false_dash_usage(t_ls *ls, t_info *info)
{
	int i;

	i = 1;
	if (info->argv[i][0] != '-')
		process_dir(ls, info);
	else if (info->argv[i][0] == '-' && info->argv[i][1] == '\0')
		process_dir(ls, info);
}

/*
** perror handles following error's: No such file or directory, and
** Permission denied
*/

void	perm_denied(char *str)
{
	ft_printf("ft_ls: ");
	perror(str);
}
