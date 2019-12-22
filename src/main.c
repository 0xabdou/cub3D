/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:32:35 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/22 21:35:37 by aouahib          ###   ########.fr       */
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

void	vert_line(int x, int start, int end, int lineHeight, int texX, int side)
{
	int	*image_data;
	int	line_size;

	image_data = g_window.image.data;
	line_size = g_window.image.line_size;
	int h = g_scene.resolution.y;
	for(int y = start; y< end; y++)
	{
		//256 and 128 factors to avoid floats
		int d = y * 256 - h * 128 + lineHeight * 128;
		// TODO: avoid the division to speed this up
		int texY = ((d * texHeight) / lineHeight) / 256;
		int color = g_scene.north_texture.data[texHeight * texY + texX];
		//make color darker for y-sides: R, G and B byte each divided through
		//two with a "shift" and an "and"
		if(side == 1) color = (color >> 1) & 8355711;

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
	(void)params;

	resetimg();
	int w = g_scene.resolution.x;
	int h = g_scene.resolution.y;
	for(int x = 0; x < w; x++)
	{
		double perpWallDist;

		//calculate step and initial sideDist
		t_cast cast;
		init_cast(&cast, x);
		do_cast(&cast);
		//Calculate distance projected on camera direction
		//(Euclidean distance will give fisheye effect!)
		if (cast.side == 0) perpWallDist = (cast.mapx - g_player.x + (1 - cast.stepx) / 2) / cast.rdx;
		else           perpWallDist = (cast.mapy - g_player.y + (1 - cast.stepy) / 2) / cast.rdy;
		///Calculate height of line to draw on screen
		int lineHeight = h / perpWallDist;

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h)drawEnd = h - 1;
		double wallX; //where exactly the wall was hit
		if (cast.side == 0) wallX = g_player.y + perpWallDist * cast.rdy;
		else           wallX = g_player.x + perpWallDist * cast.rdx;
		wallX -= floor(wallX);
		//x coordinate on the texture
		int texX = wallX * (double)(texWidth);
		if(cast.side == 0 && cast.rdx > 0) texX = texWidth - texX - 1;
		if(cast.side == 1 && cast.rdy < 0) texX = texWidth - texX - 1;
		//draw the pixels of the stripe as a vertical line

		vert_line(x, drawStart, drawEnd, lineHeight, texX, cast.side);
	}
	mlx_put_image_to_window(g_window.mlx_ptr,
			g_window.win_ptr,
			g_window.image.ptr,
			0, 0);
	return (0);
}
