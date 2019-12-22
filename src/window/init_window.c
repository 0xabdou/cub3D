/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:22:28 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/18 13:54:35 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

static void	init_image(void)
{
	g_window.image.ptr = mlx_new_image(g_window.mlx_ptr,
			g_scene.resolution.x, g_scene.resolution.y);
	if (!g_window.image.ptr)
	{
		g_error |= MLX_ERROR;
		return ;
	}
	g_window.image.data = (int *)mlx_get_data_addr(g_window.image.ptr,
			&(g_window.image.bpp), &(g_window.image.line_size),
			&(g_window.image.endian));
	g_window.image.line_size /= 4;
}

void		init_window(void)
{
	g_window.mlx_ptr = mlx_init();
	if (!g_window.mlx_ptr)
	{
		g_error |= MLX_ERROR;
		return ;
	}
	g_window.win_ptr = mlx_new_window(
			g_window.mlx_ptr,
			g_scene.resolution.x,
			g_scene.resolution.y,
			"cub3D");
	if (!g_window.win_ptr)
	{
		g_error |= MLX_ERROR;
		return ;
	}
	init_textures();
	if (g_error)
		return ;
	init_image();
}
