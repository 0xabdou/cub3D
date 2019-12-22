/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 15:56:40 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/09 11:31:54 by aouahib          ###   ########.fr       */
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
	free_split(s);
	return (flags);
}
