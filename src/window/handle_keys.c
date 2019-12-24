/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:09:11 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/24 13:08:57 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

int	handle_keys(int key, void *params)
{
	(void)params;
	if (key == K_W || key == K_S || key == K_A || key == K_D)
		move_player(key);
	else if (key == K_LA || key == K_RA)
		rotate_player(key);
	else if (key == K_ESC)
		game_over();
	cast_all();
	if (g_scene.save)
	{
		save_bmp();
		g_scene.save = 0;
	}
	mlx_put_image_to_window(g_window.mlx_ptr,
			g_window.win_ptr,
			g_window.image.ptr,
			0, 0);
	return (0);
}
