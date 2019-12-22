/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 20:53:15 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/22 21:04:51 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.h"

void	init_cast(t_cast *cast, double rdx, double rdy)
{

	int	mapX = g_player.x;
	int	mapY = g_player.y;

	cast->ddx = sqrt(1 + (rdy * rdy) / (rdx * rdx));
	cast->ddy = sqrt(1 + (rdx * rdx) / (rdy * rdy));	
	if (rdx < 0)
	{
		cast->stepx = -1;
		cast->sdx = (g_player.x - mapX) * cast->ddx;
	}
	else
	{
		cast->stepx = 1;
		cast->sdx = (mapX + 1.0 - g_player.x) * cast->ddx;
	}
	if (rdy < 0)
	{
		cast->stepy = -1;
		cast->sdy = (g_player.y - mapY) * cast->ddy;
	}
	else
	{
		cast->stepy = 1;
		cast->sdy = (mapY + 1.0 - g_player.y) * cast->ddy;
	}
}
