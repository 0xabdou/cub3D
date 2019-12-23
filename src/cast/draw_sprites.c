/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:07:37 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/23 13:56:01 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.h"
#include <stdio.h>

void	sort_by_distance(int *order, int *distance)
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

void	init_buffers(int *order, int *distance)
{
	int	i;

	i = 0;
	while (i < g_num_sprites)
	{
		order[i] = i;
		distance[i] = (g_player.x - g_sprites[i].x) * (g_player.x - g_sprites[i].x)
			+ (g_player.y - g_sprites[i].y) * (g_player.y - g_sprites[i].y);
		i++;
	}
	sort_by_distance(order, distance);
}

void		init_sprite(t_sprite_info *si, double spriteX, double spriteY, double invDet)
{
	int h = g_scene.resolution.y;	
	int w = g_scene.resolution.x;	
	si->projection.x = invDet * (g_dir.y * spriteX - g_dir.x * spriteY);
	si->projection.y = invDet * (-g_cam.y * spriteX + g_cam.x * spriteY);
	si->center_x = (w / 2) * (1 + si->projection.x / si->projection.y);
	si->dimensions.y = fabs(h / (si->projection.y));
	si->start.y = -si->dimensions.y / 2 + h / 2;
	if(si->start.y < 0)
		si->start.y = 0;
	si->end.y = si->dimensions.y / 2 + h / 2;
	if(si->end.y >= h)
		si->end.y = h - 1;
	si->dimensions.x = fabs(h / si->projection.y);
	si->start.x = -si->dimensions.x / 2 + si->center_x;
	if(si->start.x < 0)
		si->start.x = 0;
	si->end.x = si->dimensions.x / 2 + si->center_x;
	if(si->end.x >= w)
		si->end.x = w - 1;
}

void	draw_sprites(void)
{
	int		order[g_num_sprites];
	int		distance[g_num_sprites];
	int		i;
	int		x;
	int		y;
	t_sprite_info si;

	int h = g_scene.resolution.y;	
	int w = g_scene.resolution.x;	
	init_buffers(order, distance);	
	i = 0;
	while (i < g_num_sprites)
	{
		double spriteX = g_sprites[order[i]].x - g_player.x;
		double spriteY = g_sprites[order[i]].y - g_player.y;
		double invDet = 1.0 / (g_cam.x * g_dir.y - g_dir.x * g_cam.y);
		init_sprite(&si, spriteX, spriteY, invDet);
		x = si.start.x;
		while (x < si.end.x)
		{
			int texX = 256 * (x - (-si.dimensions.x / 2 + si.center_x))
				        * TEX_SIZE / si.dimensions.x / 256;
			if(si.projection.y > 0 && x > 0 && x < w && si.projection.y < g_distances[x])
			{
				y = si.start.y;
				while (y < si.end.y)
				{
					int d = (y) * 256 - h * 128 + si.dimensions.y * 128;
					int texY = ((d * TEX_SIZE) / si.dimensions.y) / 256;
					int color = g_scene.sprite_texture.data[TEX_SIZE * texY + texX];
					if((color & 0x00FFFFFF) != 0)
						g_window.image.data[x + y * g_window.image.line_size] = color;
					y++;
				}
			}
			x++;
		}
		i++;
	}
}
