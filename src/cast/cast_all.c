/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 22:29:28 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/22 22:31:49 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.h"

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


void	cast_all(void)
{
	t_cast cast;

	resetimg();
	int w = g_scene.resolution.x;
	for(int x = 0; x < w; x++)
	{
		init_cast(&cast, x);
		do_cast(&cast);
		draw_cast(&cast);
	}
	mlx_put_image_to_window(g_window.mlx_ptr,
			g_window.win_ptr,
			g_window.image.ptr,
			0, 0);
	//	return (0);
}
