/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 15:56:40 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/25 16:05:53 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	set_resolution(char *line, int flags)
{
	char	**s;

	s = ft_split(line + 2, ' ');
	if (!s)
	{
		g_error |= MEMORY_ERROR;
		return (flags);
	}
	if (!(s[0] && s[1]) || !(is_num(s[0]) && is_num(s[1])))
		g_error |= RES_ERROR;
	else
	{
		g_scene.resolution = new_vector(ft_atoi(s[0]), ft_atoi(s[1]));
		flags |= RES_FLAG;
	}
	if (g_scene.resolution.x < MIN_RES_X)
		g_scene.resolution.x = MIN_RES_X;
	else if (g_scene.resolution.x > MAX_RES_X)
		g_scene.resolution.x = MAX_RES_X;
	if (g_scene.resolution.y < MIN_RES_Y)
		g_scene.resolution.y = MIN_RES_Y;
	else if (g_scene.resolution.y > MAX_RES_Y)
		g_scene.resolution.y = MAX_RES_Y;
	free_split(s);
	return (flags);
}
