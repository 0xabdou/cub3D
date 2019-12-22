/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:32:35 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/22 22:23:50 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "window.h"
#include "cast.h"
#include <stdio.h>
#define texHeight 64
#define texWidth 64
#define false 0
#define true 1

int	cast_rays(void *params);

int			main(int c, char **v)
{
	if (c != 2)
		return (1);
	init_scene(v[1]);
	if (g_error)
	{
		print_error();
		return (0);
	}
	init_window();
	if (g_error)
	{
		print_error();
		return (0);
	}
	print_scene();
	mlx_loop_hook(g_window.mlx_ptr, cast_rays, 0);
	mlx_hook(g_window.win_ptr, 2, 1L << 0, handle_keys, 0);
	mlx_loop(g_window.mlx_ptr);
	return (0);
}

void	vert_line(int x, int start, int end, int lineHeight, int texX)
{
	int	*image_data;
	int	line_size;

	image_data = g_window.image.data;
	line_size = g_window.image.line_size;
	int h = g_scene.resolution.y;
	for(int y = start; y< end; y++)
	{
		int d = y * 256 - h * 128 + lineHeight * 128;
		int texY = ((d * texHeight) / lineHeight) / 256;
		int color = g_scene.north_texture.data[texHeight * texY + texX];
		image_data[x + y * line_size] = color;
	}
}

void     resetimg(void)
{
	int *image;
	int i;
	int j;

	image = g_window.image.data;
	i = 0;
	while (i < g_scene.resolution.y)
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



int cast_rays(void *params)
{
	t_cast cast;

	(void)params;

	resetimg();
	int w = g_scene.resolution.x;
	for(int x = 0; x < w; x++)
	{
		//calculate step and initial sideDist
		init_cast(&cast, x);
		do_cast(&cast);
		draw_cast(&cast);
	}
	mlx_put_image_to_window(g_window.mlx_ptr,
			g_window.win_ptr,
			g_window.image.ptr,
			0, 0);
	return (0);
}
