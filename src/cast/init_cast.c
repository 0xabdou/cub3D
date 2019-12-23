/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 20:53:15 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/23 16:34:06 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.h"

static void	x_wise(t_cast *cast)
{
	if (cast->rdx < 0)
	{
		cast->stepx = -1;
		cast->sdx = (g_player.x - cast->mapx) * cast->ddx;
	}
	else
	{
		cast->stepx = 1;
		cast->sdx = (cast->mapx + 1.0 - g_player.x) * cast->ddx;
	}
}

static void	y_wise(t_cast *cast)
{
	if (cast->rdy < 0)
	{
		cast->stepy = -1;
		cast->sdy = (g_player.y - cast->mapy) * cast->ddy;
	}
	else
	{
		cast->stepy = 1;
		cast->sdy = (cast->mapy + 1.0 - g_player.y) * cast->ddy;
	}
}

void		init_cast(t_cast *cast, int x)
{
	double	camx;

	camx = 2 * x / (double)g_scene.resolution.x - 1;
	cast->rdx = g_dir.x + g_cam.x * camx;
	cast->rdy = g_dir.y + g_cam.y * camx;
	cast->mapx = g_player.x;
	cast->mapy = g_player.y;
	cast->ddx = sqrt(1 + (cast->rdy * cast->rdy) / (cast->rdx * cast->rdx));
	cast->ddy = sqrt(1 + (cast->rdx * cast->rdx) / (cast->rdy * cast->rdy));
	x_wise(cast);
	y_wise(cast);
	cast->index = x;
}
