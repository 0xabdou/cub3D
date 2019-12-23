/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:07:37 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/23 23:21:08 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.h"

static void	sort_by_distance(int *order, int *distance)
{
	int	i;
	int	j;
	int	min;
	int	tmp;

	i = 0;
	while (i < g_num_sprites - 1)
	{
		j = i + 1;
		min = i;
		while (j < g_num_sprites)
		{
			if (distance[j] > distance[min])
				min = j;
			j++;
		}
		tmp = distance[i];
		distance[i] = distance[min];
		distance[min] = tmp;
		tmp = order[i];
		order[i] = order[min];
		order[min] = tmp;
		i++;
	}
}

static void	init_buffers(int *order, int *distance)
{
	int	i;

	i = 0;
	while (i < g_num_sprites)
	{
		order[i] = i;
		distance[i] = pow2(g_player.x - g_sprites[i].x)
			+ pow2(g_player.y - g_sprites[i].y);
		i++;
	}
	sort_by_distance(order, distance);
}

static void	init_sprite(t_sprite_info *si, int posx, int posy, double inv_det)
{
	double	sprite_x;
	double	sprite_y;
	int		h;
	int		w;

	h = g_scene.resolution.y;
	w = g_scene.resolution.x;
	sprite_x = posx - g_player.x + 0.5;
	sprite_y = posy - g_player.y + 0.5;
	si->projection.x = inv_det * (g_dir.y * sprite_x - g_dir.x * sprite_y);
	si->projection.y = inv_det * (-g_cam.y * sprite_x + g_cam.x * sprite_y);
	si->center_x = (w / 2) * (1 + si->projection.x / si->projection.y);
	si->dimensions.y = fabs(h / (si->projection.y));
	si->start.y = -si->dimensions.y / 2 + h / 2;
	si->start.y = si->start.y < 0 ? 0 : si->start.y;
	si->end.y = si->dimensions.y / 2 + h / 2;
	si->end.y = si->end.y >= h ? h - 1 : si->end.y;
	si->dimensions.x = fabs(h / si->projection.y);
	si->start.x = -si->dimensions.x / 2 + si->center_x;
	if (si->start.x < 0)
		si->start.x = 0;
	si->end.x = si->dimensions.x / 2 + si->center_x;
	if (si->end.x >= w)
		si->end.x = w - 1;
}

static void	actually_draw(t_sprite_info *si, int w, int h)
{
	int	x;
	int	y;
	int	tex_x;
	int	tex_y;
	int	c;

	x = si->start.x - 1;
	while (++x < si->end.x)
	{
		tex_x = (x - (si->center_x - si->dimensions.x / 2))
			* TEX_SIZE / si->dimensions.x;
		if (si->projection.y > 0 && x > 0
				&& x < w && si->projection.y < g_distances[x])
		{
			y = si->start.y - 1;
			while (++y < si->end.y)
			{
				tex_y = (y - (h - si->dimensions.y) / 2)
					* TEX_SIZE / si->dimensions.y;
				c = g_scene.sprite_texture.data[TEX_SIZE * tex_y + tex_x];
				if (c)
					g_window.image.data[x + y * g_window.image.line_size] = c;
			}
		}
	}
}

void		draw_sprites(void)
{
	int				order[g_num_sprites];
	int				distance[g_num_sprites];
	int				i;
	t_sprite_info	si;
	double			inv_det;

	init_buffers(order, distance);
	inv_det = 1.0 / (g_cam.x * g_dir.y - g_dir.x * g_cam.y);
	i = 0;
	while (i < g_num_sprites)
	{
		init_sprite(&si, g_sprites[order[i]].x, g_sprites[order[i]].y, inv_det);
		actually_draw(&si, g_scene.resolution.x, g_scene.resolution.y);
		i++;
	}
}
