/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:30:25 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/26 12:10:39 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.h"

void	do_cast(t_cast *cast)
{
	while (1)
	{
		if (cast->sdx < cast->sdy)
		{
			cast->sdx += cast->ddx;
			cast->mapx += cast->stepx;
			cast->side = 0;
		}
		else
		{
			cast->sdy += cast->ddy;
			cast->mapy += cast->stepy;
			cast->side = 1;
		}
		if (g_scene.map[cast->mapx + cast->mapy * g_scene.map_size.x] == '1')
			break ;
	}
	cast->pdist = cast->side
		? (cast->mapy - g_player.y + (1 - cast->stepy) / 2) / cast->rdy
		: (cast->mapx - g_player.x + (1 - cast->stepx) / 2) / cast->rdx;
	g_distances[cast->index] = cast->pdist;
}
