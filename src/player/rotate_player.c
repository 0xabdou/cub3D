/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:58:29 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/23 23:26:10 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	rotate_player(int key)
{
	double	old_dir_x;
	double	old_cam_x;

	if (key == K_LA)
	{
		old_dir_x = g_dir.x;
		g_dir.x = g_dir.x * cos(-ROT_STEP) - g_dir.y * sin(-ROT_STEP);
		g_dir.y = old_dir_x * sin(-ROT_STEP) + g_dir.y * cos(-ROT_STEP);
		old_cam_x = g_cam.x;
		g_cam.x = g_cam.x * cos(-ROT_STEP) - g_cam.y * sin(-ROT_STEP);
		g_cam.y = old_cam_x * sin(-ROT_STEP) + g_cam.y * cos(-ROT_STEP);
	}
	if (key == K_RA)
	{
		old_dir_x = g_dir.x;
		g_dir.x = g_dir.x * cos(ROT_STEP) - g_dir.y * sin(ROT_STEP);
		g_dir.y = old_dir_x * sin(ROT_STEP) + g_dir.y * cos(ROT_STEP);
		old_cam_x = g_cam.x;
		g_cam.x = g_cam.x * cos(ROT_STEP) - g_cam.y * sin(ROT_STEP);
		g_cam.y = old_cam_x * sin(ROT_STEP) + g_cam.y * cos(ROT_STEP);
	}
}
