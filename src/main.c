/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:32:35 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/22 19:14:49 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "window.h"
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
		double cameraX = 2 * x / (double)(w) - 1; //x-coordinate in camera space
		double rayDirX = g_dir.x + g_cam.x * cameraX;
		double rayDirY = g_dir.y + g_cam.y * cameraX;

		//which box of the map we're in
		int mapX = (int)(g_player.x);
		int mapY = (int)(g_player.y);
		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (g_player.x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - g_player.x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (g_player.y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - g_player.y) * deltaDistY;
		}
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (g_scene.map[mapX + mapY * g_scene.map_size.x] == '1') hit = 1;
		} 
		//Calculate distance projected on camera direction
		//(Euclidean distance will give fisheye effect!)
		if (side == 0) perpWallDist = (mapX - g_player.x + (1 - stepX) / 2) / rayDirX;
		else           perpWallDist = (mapY - g_player.y + (1 - stepY) / 2) / rayDirY;
		///Calculate height of line to draw on screen
		int lineHeight = (int)(h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h)drawEnd = h - 1;
		double wallX; //where exactly the wall was hit
		if (side == 0) wallX = g_player.y + perpWallDist * rayDirY;
		else           wallX = g_player.x + perpWallDist * rayDirX;
		wallX -= floor((wallX));
		//x coordinate on the texture
		int texX = (int)(wallX * (double)(texWidth));
		if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
		if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;
		//draw the pixels of the stripe as a vertical line
		
		vert_line(x, drawStart, drawEnd, lineHeight, texX, side);
	}
	mlx_put_image_to_window(g_window.mlx_ptr,
			g_window.win_ptr,
			g_window.image.ptr,
			0, 0);
	return (0);
}
