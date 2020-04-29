/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:35:56 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/28 13:34:08 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Subjoi appends a single line into our line variable, in order to do so we
** need to find the len of the line. We readjust the stored data in str by
** creating a tmp, that stores the rest of the data after the newline.
** Now we free the stored data to update the current address, we already
** appended a line from it, thats why we need to free it. Thats done by
** freeing *str and set it equal to the tmp that stored the rest of the data.
** In the end the data in str is freed, it is not needed anymore.
*/

static int		subjoin(char **str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\n')
	{
		*line = ft_strsub(*str, 0, i);
		tmp = ft_strdup(&((*str)[i + 1]));
		free(*str);
		*str = tmp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

/*
** Reads a file and returns the new line ending with a newline character
** from a fd. In the while loop we read more of the line and join them
** togther using a tmp. This tmp will replace the stored data each iteration,
** so we can keep track of how much is read. This is needed because of the
** given BUFF_SIZE. The loop breaks when a newline is spotted. The '\n'
** is our delimeter for strchr. Finally we call subjoi to se what to return.
*/

int				get_next_line(const int fd, char **line)
{
	int				res;
	static char		*str[FD_SIZE];
	char			buff[BUFF_SIZE + 1];
	char			*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(0);
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (res < 0)
		return (-1);
	else if (res == 0 && str[fd] == NULL)
		return (0);
	else
		return (subjoin(&str[fd], line));
}
