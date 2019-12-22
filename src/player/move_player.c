/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:05:35 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/22 19:10:33 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	move_player(int key)
{
	if (key == K_W)
	{
		if(g_scene.map[(int)(g_player.x + g_dir.x * MOVE_STEP)
				+ g_scene.map_size.x * (int)g_player.y] != '1')
			g_player.x += g_dir.x * MOVE_STEP;
		if(g_scene.map[(int)g_player.x +
				(int)(g_player.y + g_dir.y * MOVE_STEP) * g_scene.map_size.x] != '1')
			g_player.y += g_dir.y * MOVE_STEP;
	}
	if (key == K_S)
	{
		if(g_scene.map[(int)(g_player.x - g_dir.x * MOVE_STEP)
				+ (int)g_player.y * g_scene.map_size.x] == '0')
			g_player.x -= g_dir.x * MOVE_STEP;
		if(g_scene.map[(int)(g_player.x) +
				(int)(g_player.y - g_dir.y * MOVE_STEP) * g_scene.map_size.x] == '0')
			g_player.y -= g_dir.y * MOVE_STEP;
	}
}
