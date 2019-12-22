/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 15:57:32 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/08 21:45:37 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static int	rgb_from_split(char **s, char type, int *flags)
{
	*flags |= type == 'F' ? F_FLAG : C_FLAG;
	if (type == 'F')
	{
		g_scene.floor_color = RGB(ft_atoi(s[0]), ft_atoi(s[1]), ft_atoi(s[2]));
		*flags |= F_FLAG;
	}
	else
	{
		g_scene.ceil_color = RGB(ft_atoi(s[0]), ft_atoi(s[1]), ft_atoi(s[2]));
		*flags |= C_FLAG;
	}
	return (*flags);
}

int			set_color(char *line, int flags)
{
	char	**s;

	s = ft_split(line + 2, ',');
	if (!s)
	{
		g_error |= MEMORY_ERROR;
		return (flags);
	}
	if (!(s[0] && s[1] && s[2])
			|| !(is_num(s[0]) && is_num(s[1]) && is_num(s[2])))
		g_error |= line[0] == 'F' ? FLOOR_ERROR : CEIL_ERROR;
	else
		flags = rgb_from_split(s, line[0], &flags);
	free_split(s);
	return (flags);
}
