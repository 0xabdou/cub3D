/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:42:49 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/22 18:04:41 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static void	set_orientation(char orientation)
{
	if (orientation == 'E')
	{
		g_dir = (t_dvector){1, 0};
		g_cam = (t_dvector){0, 0.66};
	}
	else if (orientation == 'S')
	{
		g_dir = (t_dvector){0, 1};
		g_cam = (t_dvector){-0.66, 0};
	}
	else if (orientation == 'W')
	{
		g_dir = (t_dvector){-1, 0};
		g_cam = (t_dvector){0, -0.66};
	}
	else
	{
		g_dir = (t_dvector){0 , -1};
		g_cam = (t_dvector){0.66, 0};
	}
}

void			init_player(int x, int y, char orientation)
{
	g_player.x = x;// + 0.5;
	g_player.y = y;// + 0.5 ;
	set_orientation(orientation);
}
