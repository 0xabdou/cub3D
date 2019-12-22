/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:05:35 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/22 16:26:10 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	move_player(int key)
{
	//double		new_x;
	//double		new_y;
	//int			step;

	//step = 0;
	//if (key == K_W || key == K_D)
	//	step = MOVE_STEP;
	//else if (key == K_S || key == K_A)
	//	step = -MOVE_STEP;
	//if (key == K_W || key == K_S)
	//{
	//	new_x = g_player.x + step * cos(g_player.angle);
	//	new_y = g_player.y + step * sin(g_player.angle);
	//}
	//else
	//{
	//	new_x = g_player.x + step * cos(g_player.angle + M_PI / 2);
	//	new_y = g_player.y + step * sin(g_player.angle + M_PI / 2);
	//}
	//if (!map_has_wall_at(new_x, new_y))
	//{
	//	g_player.x = new_x;
	//	g_player.y = new_y;
	//}
	(void)key;
}
