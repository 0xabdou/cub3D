/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:09:11 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/23 11:53:13 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	sprites(void);

int	handle_keys(int key, void *params)
{
	(void)params;
	if (key == K_W || key == K_S || key == K_A || key == K_D)
	{
		move_player(key);
		rotate_player(key);
	}
	else if (key == K_LA || key == K_RA)
		rotate_player(key);
	else if (key == K_ESC)
		game_over();
	cast_all();
	sprites();
	mlx_put_image_to_window(g_window.mlx_ptr,
			g_window.win_ptr,
			g_window.image.ptr,
			0, 0);
	return (0);
}

void combSort(int *sprites)
{
	(void)sprites;
}

void	sprites(void)
{
	int w = g_scene.resolution.x;
	int h = g_scene.resolution.y;
	int spriteOrder[g_num_sprites];
	int	spriteDistance[g_num_sprites];
	for(int i = 0; i < g_num_sprites; i++)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = ((g_player.x - g_sprites[i].x) * (g_player.x - g_sprites[i].x)
				+ (g_player.y - g_sprites[i].y) * (g_player.y - g_sprites[i].y)); //sqrt not taken, unneeded
	}
	combSort(spriteOrder);	

	for(int i = 0; i < g_num_sprites; i++)
	{
		double spriteX = g_sprites[spriteOrder[i]].x - g_player.x;
		double spriteY = g_sprites[spriteOrder[i]].y - g_player.y;
		double invDet = 1.0 / (g_cam.x * g_dir.y - g_dir.x * g_cam.y);
		double transformX = invDet * (g_dir.y * spriteX - g_dir.x * spriteY);
		double transformY = invDet * (-g_cam.y * spriteX + g_cam.x * spriteY);
		int spriteScreenX = (w / 2) * (1 + transformX / transformY);
		int spriteHeight = fabs(h / (transformY));
		int drawStartY = -spriteHeight / 2 + h / 2;
		if(drawStartY < 0) drawStartY = 0;
		int drawEndY = spriteHeight / 2 + h / 2;
		if(drawEndY >= h) drawEndY = h - 1;
		int spriteWidth = fabs(h / transformY);
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= w) drawEndX = w - 1;
		for(int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX = 256 * (stripe - (-spriteWidth / 2 + spriteScreenX))
					* TEX_SIZE / spriteWidth / 256;
			if(transformY > 0 && stripe > 0 && stripe < w && transformY < g_distances[stripe])
				for(int y = drawStartY; y < drawEndY; y++)
				{
					int d = (y) * 256 - h * 128 + spriteHeight * 128;
					int texY = ((d * TEX_SIZE) / spriteHeight) / 256;
					int color = g_scene.sprite_texture.data[TEX_SIZE * texY + texX];
					if((color & 0x00FFFFFF) != 0)
						//buffer[y][stripe] = color;
						g_window.image.data[stripe + y * g_window.image.line_size] = color;
				}
		}
	}
}
