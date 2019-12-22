/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_has_sprite_at.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:10:30 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/21 21:01:42 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	check_sprite(double x, double y, t_ray *ray)
{
	int	map_x;
	int	map_y;

	map_x = x / TILE_SIZE;
	map_y = y / TILE_SIZE;

	if (g_scene.map[map_x + map_y * g_scene.map_size.x] == '2')
	{
		ray->is_sprite = 1;
		ray->sprite_hit.x = map_x * TILE_SIZE + TILE_SIZE / 2;
		ray->sprite_hit.y = map_y * TILE_SIZE + TILE_SIZE / 2;
		if (!g_sprite_render.started)
		{
			g_sprite_render.start_x = ray->index;
			g_sprite_render.started = 1;
		}
		else
			g_sprite_render.end_x = ray->index;
		g_sprite_render.distance = distance(g_player.x, g_player.y, ray->sprite_hit.x, ray->sprite_hit.y);
		g_sprite_render.texture = &g_scene.sprite_texture;
	}
}
