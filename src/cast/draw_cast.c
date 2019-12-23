/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 21:57:10 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/23 16:53:35 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.h"

static void		vert_line(int x, int height, int tex_x, t_image texture)
{
	int	start;
	int	end;
	int	y;
	int	tex_y;
	int	color;
	int	i;

	start  = -height / 2 + g_scene.resolution.y / 2;
	i = 0;
	if (start < 0)
	{
		i = -start;
		start = 0;
	}
	end = height / 2 + g_scene.resolution.y / 2;
	if (end >= g_scene.resolution.y)
		end = g_scene.resolution.y - 1;
	for(y = start; y< end; y++)
	{
		tex_y = i * TEX_SIZE / height;
		color = texture.data[tex_x + tex_y * TEX_SIZE];
		g_window.image.data[x + y * g_window.image.line_size] = color;
		i++;
	}
}

static t_image	get_texture(t_cast *cast)
{
	if (cast->rdx > 0)
	{
		if (cast->side)
		{
			if (cast->rdy < 0)
				return (g_scene.south_texture);
			return (g_scene.north_texture);
		}
		return (g_scene.east_texture);

	}
	else
	{
		if (cast->side)
		{
			if (cast->rdy < 0)
				return (g_scene.south_texture);
			return (g_scene.north_texture);
		}
		return (g_scene.west_texture);
	}
}

void			draw_cast(t_cast *cast)
{
	int		height;
	int		tex_x;
	double	wall_x;
	t_image	texture;

	texture = get_texture(cast);
	height = g_scene.resolution.y / cast->pdist;
	wall_x  = cast->side
		? wall_x = g_player.x + cast->pdist * cast->rdx
		: g_player.y + cast->pdist * cast->rdy;
	wall_x -= floor(wall_x);
	tex_x = wall_x * (double)TEX_SIZE;
	vert_line(cast->index, height, tex_x, texture);
}
