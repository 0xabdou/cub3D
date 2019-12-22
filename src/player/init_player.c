/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:42:49 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/15 13:22:36 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static double	get_player_angle(char orientation)
{
	if (orientation == 'E')
		return (0);
	if (orientation == 'S')
		return (0.5 * M_PI);
	if (orientation == 'W')
		return (2 * M_PI);
	return (1.5 * M_PI);
}

void			init_player(int x, int y, char orientation)
{
	g_player.x = x * TILE_SIZE + TILE_SIZE / 2;
	g_player.y = y * TILE_SIZE + TILE_SIZE / 2;
	g_player.angle = get_player_angle(orientation);
}
