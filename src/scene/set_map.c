/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:47:29 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/27 13:13:50 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static int	check_all(char *line)
{
	int	i;

	i = 0;
	while (line[i] == '1')
		i++;
	if ((int)ft_strlen(line) == g_scene.map_size.x && line[i] == 0)
		return (0);
	g_error |= MAP_ERROR;
	return (1);
}

static int	check_ends(char *line)
{
	int	len;

	len = 0;
	while (line[len])
		if (line[len++] == '2')
			g_num_sprites++;
	if (len == g_scene.map_size.x
			&& *line == '1'
			&& line[len - 1] == '1')
		return (0);
	g_error |= MAP_ERROR;
	return (1);
}

static char	*join(char *map, char *line)
{
	char	*tmp;

	tmp = map;
	map = ft_strjoin(map, line);
	free(tmp);
	free(line);
	return (map);
}

static char	*read_map(int fd, char *line)
{
	char	*map;
	int		first;
	int		error;
	int		ret;

	first = 1;
	map = ft_strdup("");
	error = 0;
	while (first || (ret = get_next_line(fd, &line)) > 0)
	{
		g_scene.map_size.x = g_scene.map_size.x == 0
			? ft_strlen(line)
			: g_scene.map_size.x;
		error = first ? check_all(line) : check_ends(line);
		map = join(map, line);
		error = map == 0 ? 1 : error;
		if (error)
			break ;
		first = 0;
		g_scene.map_size.y++;
	}
	g_error |= ret == -1 ? READ_ERROR : 0;
	error = check_all(map + g_scene.map_size.x * (g_scene.map_size.y - 1))
		? 1 : error;
	return (map);
}

void		set_map(int fd, char *line)
{
	char	*map;
	int		i;

	i = 0;
	map = read_map(fd, line);
	if (!map)
		g_error |= MEMORY_ERROR;
	if (g_error)
	{
		free(map);
		return ;
	}
	g_scene.map = map;
	verify_map();
}
