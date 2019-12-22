/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 21:57:10 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/22 22:24:04 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.h"

static void	vert_line(int x, int height, int tex_x)
{
	int	start;
	int	end;
	int	y;
	int	tex_y;
	int	d;
	int	color;

	start  = -height / 2 + g_scene.resolution.y / 2;
	if (start < 0)
		start = 0;
	end = height / 2 + g_scene.resolution.y / 2;
	if (end >= g_scene.resolution.y)
		end = g_scene.resolution.y - 1;
	for(y = start; y< end; y++)
	{
		d = y * 256 - g_scene.resolution.y * 128 + height * 128;
		tex_y  = (d * TEX_SIZE / height) / 256;
		color = g_scene.north_texture.data[tex_x + tex_y * TEX_SIZE];
		g_window.image.data[x + y * g_window.image.line_size] = color;
	}
}

void	draw_cast(t_cast *cast)
{
	int	height;
	int	tex_x;
	double	wall_x;

	height = g_scene.resolution.y / cast->pdist;
	wall_x  = cast->side
		? wall_x = g_player.x + cast->pdist * cast->rdx
		: g_player.y + cast->pdist * cast->rdy;
	wall_x -= floor(wall_x);
	tex_x = wall_x * (double)TEX_SIZE;
	if(cast->side == 0 && cast->rdx > 0)
		tex_x = TEX_SIZE - tex_x - 1;
	if(cast->side == 1 && cast->rdy < 0)
		tex_x = TEX_SIZE - tex_x - 1;
	vert_line(cast->index, height, tex_x);
}
