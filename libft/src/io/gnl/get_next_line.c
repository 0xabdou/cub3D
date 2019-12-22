/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:30:09 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/06 18:48:56 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	extract_line(char **line, char *buf, char *new_line)
{
	int size;

	size = new_line - buf + 1;
	*line = malloc(size);
	if (!line)
		return (-1);
	gnl_strlcpy(*line, buf, size);
	gnl_strlcpy(buf, new_line + 1, gnl_strlen(buf) + 1);
	return (1);
}

static int	read_to_buf(int fd, char **buf)
{
	char	*tmp_buf;
	char	*tmp;
	int		size;

	tmp_buf = malloc(BUFFER_SIZE + 1);
	if (!tmp_buf)
		return (-1);
	size = read(fd, tmp_buf, BUFFER_SIZE);
	if (size >= 0)
	{
		tmp_buf[size] = 0;
		tmp = *buf;
		*buf = gnl_strjoin(*buf, tmp_buf);
		free(tmp);
		free(tmp_buf);
		if (!*buf)
			return (-1);
	}
	else
		free(tmp_buf);
	return (size);
}

static int	rest(char **line, char **buf)
{
	int	res;

	if (*buf && **buf)
	{
		*line = gnl_strdup(*buf);
		res = *line ? 1 : -1;
	}
	else
		res = 0;
	free(*buf);
	*buf = 0;
	return (res);
}

int			get_next_line(int fd, char **line)
{
	static char	*bufs[MAX_FD];
	char		*new_line;
	int			res;

	if (!line || fd < 0 || fd >= MAX_FD)
		return (-1);
	new_line = gnl_strchr(bufs[fd], '\n');
	if (new_line)
		return (extract_line(line, bufs[fd], new_line));
	res = read_to_buf(fd, &bufs[fd]);
	if (res > 0)
		return (get_next_line(fd, line));
	if (!res)
		return (rest(line, &bufs[fd]));
	free(bufs[fd]);
	bufs[fd] = 0;
	return (-1);
}
