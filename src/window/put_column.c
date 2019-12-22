/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:34:55 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/21 13:24:04 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

static t_image	get_wall_texture(t_ray *ray)
{
	if (ray->wall_side == 'N')
		return (g_scene.north_texture);
	if (ray->wall_side == 'S')
		return (g_scene.south_texture);
	if (ray->wall_side == 'W')
		return (g_scene.west_texture);
	if (ray->wall_side == 'E')
		return (g_scene.east_texture);
	return (g_scene.north_texture);
}

static int		get_pixel(t_ray *ray, int y, int height)
{
	t_image	texture;
	int		tex_x;
	int		tex_y;

	tex_x = ray->hit_horizontally
		? (int)ray->wall_hit.x % TILE_SIZE * TEX_SIZE / TILE_SIZE
		: (int)ray->wall_hit.y % TILE_SIZE * TEX_SIZE / TILE_SIZE;
	tex_y = y % height * TEX_SIZE / height;
	texture = get_wall_texture(ray);
	return (texture.data[tex_x + tex_y * TEX_SIZE]);
}

void			put_column(int x, int height, t_ray *ray)
{
	int	*img_data;
	int	line_size;
	int	start;
	int end;
	int	i;

	img_data = g_window.image.data;
	line_size = g_window.image.line_size;
	start = g_scene.resolution.y / 2 - height / 2;
	end = g_scene.resolution.y / 2 + height / 2;
	if (end >= g_scene.resolution.y)
		end = g_scene.resolution.y - 1;
	i = start < 0 ? -start : 0;
	start = start < 0 ? 0 : start;
	while (start <= end)
	{
		if (start >= 0)
			img_data[x + start * line_size] = get_pixel(ray, i, height);
		start++;
		i++;
	}
}
