/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:29:18 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/18 20:37:42 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	verify_map(void)
{
	int		i;
	int		j;
	int		k;
	char	*m;

	if (!(m = g_scene.map))
		return ;
	j = -1;
	while (++j < g_scene.map_size.y)
	{
		i = 0;
		while (++i < g_scene.map_size.x)
		{
			k = i + j * g_scene.map_size.x;
			if (m[k] == 'N' || m[k] == 'S' || m[k] == 'W' || m[k] == 'E')
				init_player(i, j, m[k]);
			else if (m[k] != '1' && m[k] != '0' && m[k] != '2')
			{
				g_error |= MAP_ERROR;
				return ;
			}
		}
	}
	g_scene.canvas.x = g_scene.map_size.x * TILE_SIZE;
	g_scene.canvas.y = g_scene.map_size.y * TILE_SIZE;
}
