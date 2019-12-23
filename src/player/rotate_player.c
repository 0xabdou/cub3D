/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:58:29 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/23 16:22:46 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	rotate_player(int key)
{
	if (key == K_LA)
	{
		double oldDirX = g_dir.x;
		g_dir.x = g_dir.x * cos(-ROT_STEP) - g_dir.y * sin(-ROT_STEP);
		g_dir.y = oldDirX * sin(-ROT_STEP) + g_dir.y * cos(-ROT_STEP);
		double oldPlaneX = g_cam.x;
		g_cam.x = g_cam.x * cos(-ROT_STEP) - g_cam.y * sin(-ROT_STEP);
		g_cam.y = oldPlaneX * sin(-ROT_STEP) + g_cam.y * cos(-ROT_STEP);
	}
	if (key == K_RA)
	{
		double oldDirX = g_dir.x;
		g_dir.x = g_dir.x * cos(ROT_STEP) - g_dir.y * sin(ROT_STEP);
		g_dir.y = oldDirX * sin(ROT_STEP) + g_dir.y * cos(ROT_STEP);
		double oldPlaneX = g_cam.x;
		g_cam.x = g_cam.x * cos(ROT_STEP) - g_cam.y * sin(ROT_STEP);
		g_cam.y = oldPlaneX * sin(ROT_STEP) + g_cam.y * cos(ROT_STEP);
	}
}
