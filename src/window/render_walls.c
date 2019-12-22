/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:34:23 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/21 21:01:11 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include <stdio.h>

static void		draw_floor(void)
{
	int	*image;
	int	i;
	int	j;

	image = g_window.image.data;
	i = g_scene.resolution.y / 2;
	while (i < g_scene.resolution.y)
	{
		j = 0;
		while (j < g_scene.resolution.x)
		{
			image[j + i * g_window.image.line_size] = g_scene.floor_color;
			j++;
		}
		i++;
	}
}

static void		draw_ceil(void)
{
	int	*image;
	int	i;
	int	j;

	image = g_window.image.data;
	i = 0;
	while (i < g_scene.resolution.y / 2)
	{
		j = 0;
		while (j < g_scene.resolution.x)
		{
			image[j + i * g_window.image.line_size] = g_scene.ceil_color;
			j++;
		}
		i++;
	}
}

static double	get_wall_height(t_ray *ray)
{
	double	ray_dist;
	double	dist_to_plane;
	double	wall_height;
	double	wall_length;

	ray_dist = ray->distance * cos(ray->angle - g_player.angle);
	dist_to_plane = tan(FOV_ANGLE / 2) * (g_scene.canvas.x / 2);
	wall_length = g_scene.resolution.x / g_scene.map_size.x;
	wall_height = (wall_length * dist_to_plane) / ray_dist * 2.5;
	return (wall_height);
}

static double   get_wall_height2(t_ray *ray)
{
	double  ray_dist;
	double  dist_to_plane;
	double  wall_height;
	double  wall_length;

	ray_dist = distance(g_player.x, g_player.y, ray->sprite_hit.x, ray->sprite_hit.y);
	ray_dist = ray_dist * cos(-ray->angle + g_player.angle);
	dist_to_plane = tan(FOV_ANGLE / 2) * (g_scene.canvas.x / 2);
	wall_length = g_scene.resolution.x / g_scene.map_size.x;
	wall_height = (wall_length * dist_to_plane) / ray_dist * 2.5;
	return (wall_height);
}




static t_image  get_wall_texture(t_ray *ray)
{
	if (ray->is_sprite)
		return (g_scene.sprite_texture);
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


static int      get_pixel(t_ray *ray, int y, int height, int x)
{
	t_image texture;
	int     tex_x;
	int     tex_y;

	tex_x = ((double)(x - g_sprite_render.start_x) / (double)(g_sprite_render.end_x - g_sprite_render.start_x)) * TEX_SIZE;
//	tex_x = (int)ray->sprite_hit.x % TILE_SIZE * TEX_SIZE / TILE_SIZE;
	tex_y = y % height * TEX_SIZE / height;
	texture = get_wall_texture(ray);
	return (texture.data[tex_x + tex_y * TEX_SIZE]);
}


static void		put_sprite(int x, t_ray *ray)
{
	int	*img_data;
	int	line_size;
	int	start;
	int	end;
	int	i;
	int	height;

	(void)ray;
	height = get_wall_height2(ray);
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
		int pix = get_pixel(ray, i, height, x);
		if (pix != 0)
			img_data[x + start * line_size] = pix;
		start++;
		i++;
	}
	for (int i = 0; i < g_scene.resolution.y; i++)
	{
			img_data[g_sprite_render.start_x + i * line_size] = 0xFF00FF;
			img_data[g_sprite_render.end_x + i * line_size] = 0xFF00FF;
	}
	g_sprite_render.started = 0;
}

void			render_sprites(void)
{
	int	i;
	int	num_rays;
	t_ray ray;

	num_rays = g_scene.resolution.x;
	i = 0;
	while (i < num_rays)
	{
		ray = g_rays[i];
		if (ray.is_sprite && ray.distance > distance(g_player.x, g_player.y,
					ray.sprite_hit.x, ray.sprite_hit.y))
			put_sprite(i, &ray);
		i++;
	}
}

void			render_walls(void)
{
	int		i;
	int		num_rays;
	t_ray	ray;
	double	wall_height;

	draw_ceil();
	draw_floor();
	num_rays = g_scene.resolution.x;
	i = 0;
	while (i < num_rays)
	{
		ray = g_rays[i];
		wall_height = get_wall_height(&ray);
		put_column(i, wall_height, &ray);
		i++;
	}
	render_sprites();
	mlx_put_image_to_window(g_window.mlx_ptr,
			g_window.win_ptr,
			g_window.image.ptr,
			0, 0);
}
