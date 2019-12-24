/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:35:49 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/24 13:04:07 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void	skip_empty_lines(int fd, char **line)
{
	int	ret;

	while (**line == 0)
	{
		free(*line);
		ret = get_next_line(fd, line);
		if (ret <= 0)
			break ;
	}
	if (ret < 0)
		g_error |= MEMORY_ERROR;
}

static int	handle_line(char *line, int flags)
{
	if (*line == 'R')
		flags = set_resolution(line, flags);
	else if ((*line == 'F' || *line == 'C') && line[1] == ' ')
		flags = set_color(line, flags);
	else if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
		flags = set_path(line, flags);
	else if (flags == FULL_FLAG)
		return (flags);
	else if (*line != 0)
		g_error |= MISSING_CONFIG_ERROR;
	return (flags);
}

void		init_scene(char *scene_file)
{
	int		fd;
	char	*line;
	int		ret;
	int		flags;

	flags = 0;
	line = 0;
	fd = open(scene_file, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0 && flags != FULL_FLAG)
	{
		flags = handle_line(line, flags);
		if (g_error)
			break ;
		free(line);
	}
	if (ret == -1)
		g_error |= READ_ERROR;
	if (g_error)
	{
		free(line);
		return ;
	}
	skip_empty_lines(fd, &line);
	set_map(fd, line);
	g_distances = malloc(g_scene.resolution.x * sizeof(double));
}
