/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cast->c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42->fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 21:30:35 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/22 21:35:06 by aouahib          ###   ########.fr       */
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
}
