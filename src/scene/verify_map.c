/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:29:18 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/23 23:03:49 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void	loop_over_line(char *m, int j)
{
	static int	l;
	int			i;
	int			k;

	i = 0;
	while (++i < g_scene.map_size.x)
	{
		k = i + j * g_scene.map_size.x;
		if (m[k] == 'N' || m[k] == 'S' || m[k] == 'W' || m[k] == 'E')
			init_player(i, j, m[k]);
		else if (m[k] == '2')
			g_sprites[l++] = (t_dvector){i, j};
		else if (m[k] != '1' && m[k] != '0')
		{
			g_error |= MAP_ERROR;
			return ;
		}
	}
}

void		verify_map(void)
{
	int		j;
	char	*m;

	if (!(m = g_scene.map))
		return ;
	g_sprites = malloc(g_num_sprites * sizeof(t_dvector));
	if (!g_sprites)
	{
		g_error |= MEMORY_ERROR;
		return ;
	}
	j = -1;
	while (++j < g_scene.map_size.y)
		loop_over_line(m, j);
	g_scene.canvas.x = g_scene.map_size.x * TILE_SIZE;
	g_scene.canvas.y = g_scene.map_size.y * TILE_SIZE;
}
