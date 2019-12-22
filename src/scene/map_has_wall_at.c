/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_has_wall_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 21:21:54 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/18 20:35:57 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	map_has_wall_at(double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (x / TILE_SIZE);
	map_y = (y / TILE_SIZE);
	return (g_scene.map[map_x + map_y * g_scene.map_size.x] == '1');
}
