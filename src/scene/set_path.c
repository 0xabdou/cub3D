/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 15:58:13 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/18 20:38:21 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void	north_south(char type, char *texture, int *flags)
{
	if (type == 'N')
	{
		g_scene.north_path = ft_strdup(texture);
		*flags |= NO_FLAG;
	}
	else
	{
		g_scene.south_path = ft_strdup(texture);
		*flags |= SO_FLAG;
	}
}

static void	east_west(char type, char *texture, int *flags)
{
	if (type == 'E')
	{
		g_scene.east_path = ft_strdup(texture);
		*flags |= EA_FLAG;
	}
	else
	{
		g_scene.west_path = ft_strdup(texture);
		*flags |= WE_FLAG;
	}
}

int			set_path(char *line, int flags)
{
	char	**s;

	s = ft_split(line, ' ');
	if (!s)
	{
		g_error |= MEMORY_ERROR;
		return (flags);
	}
	if (!(s[0] && s[1]))
		g_error |= TEXTURE_ERROR;
	else if (!ft_strncmp(s[0], "NO", 3) || !ft_strncmp(s[0], "SO", 3))
		north_south(s[0][0], s[1], &flags);
	else if (!ft_strncmp(s[0], "EA", 3) || !ft_strncmp(s[0], "WE", 3))
		east_west(s[0][0], s[1], &flags);
	else if (!ft_strncmp(s[0], "S", 2))
	{
		g_scene.sprite_path = ft_strdup(s[1]);
		flags |= SP_FLAG;
	}
	else
		g_error |= TEXTURE_ERROR;
	free_split(s);
	return (flags);
}
