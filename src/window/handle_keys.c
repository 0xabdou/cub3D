/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:09:11 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/25 16:52:05 by aouahib          ###   ########.fr       */
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
	reset_image();
	cast_all();
	if (g_scene.save)
	{
		save_bmp();
		game_over();
	}
	mlx_put_image_to_window(g_window.mlx_ptr,
			g_window.win_ptr,
			g_window.image.ptr,
			0, 0);
	return (0);
}
