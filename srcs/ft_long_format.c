/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manager <manager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 10:47:35 by ismelich          #+#    #+#             */
/*   Updated: 2020/04/24 11:39:40 by manager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** Takes care of the month, date and time column.
** older than 6 months - year, month and day.
** younger than 6 months - month, day and time.
*/

void	mdt_column(struct stat meta)
{
	struct timespec	last_modified;
	time_t			seconds_since_epoch;
	char			*month_date;
	char			*time_or_year;
	char			*time_str;

	last_modified = meta.st_mtimespec;
	seconds_since_epoch = time(&seconds_since_epoch);
	time_str = ctime(&meta.st_mtimespec.tv_sec);
	month_date = malloc(sizeof(char) * (8));
	time_or_year = malloc(sizeof(char) * (8));
	if (month_date == NULL || time_or_year == NULL)
		return ;
	month_date[0] = 0;
	time_or_year[0] = 0;
	ft_printf("%s ", ft_strsub_start_end(month_date, time_str, 4, 6));
	if ((seconds_since_epoch - last_modified.tv_sec) < SIX_MONTHS)
		ft_printf("%s ", ft_strsub_start_end(time_or_year, time_str, 11, 5));
	else if ((seconds_since_epoch - last_modified.tv_sec) >= SIX_MONTHS)
		ft_printf("%5s ", ft_strsub_start_end(time_or_year, time_str, 20, 4));
	free(month_date);
	free(time_or_year);
}

/*
** Determanating the file type with the help of POSIX macros.
*/

char	perm_file_type(int file_mode)
{
	char type;

	if (S_ISDIR(file_mode))
		type = 'd';
	else if (S_ISCHR(file_mode))
		type = 'c';
	else if (S_ISBLK(file_mode))
		type = 'b';
	else if (S_ISFIFO(file_mode))
		type = 'p';
	else if (S_ISLNK(file_mode))
		type = 'l';
	else if (S_ISSOCK(file_mode))
		type = 's';
	else
		type = '-';
	return (type);
}

/*
** List extended attribute '@' of f/d/symblinks with the help of listxattr.
*/

char	extended_attrb(char *file_name)
{
	ssize_t xattr;
	char	character;

	xattr = 0;
	xattr = listxattr(file_name, NULL, 0, XATTR_NOFOLLOW);
	if (xattr > 0)
		character = '@';
	else
		character = ' ';
	return (character);
}

/*
** Prints out the permission state of the f/d.
*/

void	perm_column(struct stat meta, char *file_name)
{
	int		i;
	char	extended_character;
	char	permission[12];

	i = 0;
	extended_character = extended_attrb(file_name);
	permission[i++] = perm_file_type(meta.st_mode);
	permission[i++] = (meta.st_mode & S_IRUSR) ? 'r' : '-';
	permission[i++] = (meta.st_mode & S_IWUSR) ? 'w' : '-';
	permission[i++] = (meta.st_mode & S_IXUSR) ? 'x' : '-';
	permission[i++] = (meta.st_mode & S_IRGRP) ? 'r' : '-';
	permission[i++] = (meta.st_mode & S_IWGRP) ? 'w' : '-';
	permission[i++] = (meta.st_mode & S_IXGRP) ? 'x' : '-';
	permission[i++] = (meta.st_mode & S_IROTH) ? 'r' : '-';
	permission[i++] = (meta.st_mode & S_IWOTH) ? 'w' : '-';
	permission[i++] = (meta.st_mode & S_IXOTH) ? 'x' : '-';
	permission[i++] = extended_character;
	permission[i] = '\0';
	ft_printf("%s ", permission);
}

/*
** Prints out the number of hard links to the file, user ID of the owner
** of the file, group ID of owner and the total size of bytes.
*/

void	long_format(struct stat meta, char *file_name, t_info *info)
{
	perm_column(meta, file_name);
	ft_printf("%*d ", info->pad_nlink, meta.st_nlink);
	if (getpwuid(meta.st_uid)->pw_name)
		ft_printf("%s  ", getpwuid(meta.st_uid)->pw_name);
	if (getgrgid(meta.st_gid)->gr_name)
		ft_printf("%s  ", getgrgid(meta.st_gid)->gr_name);
	ft_printf("%*d ", info->pad_size, meta.st_size);
	mdt_column(meta);
}
