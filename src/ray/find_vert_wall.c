/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_horz_dist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:51:22 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/21 13:14:33 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	dda(t_ray *ray, double xintercept,
		double yintercept, t_dvector *wall)
{
	double	next_x;
	double	next_y;
	double	xstep;
	double	ystep;

	xstep = TILE_SIZE * (ray->facing_right ? 1 : -1);
	ystep = TILE_SIZE * tan(ray->angle);
	ystep *= ray->facing_down && ystep < 0 ? -1 : 1;
	ystep *= !ray->facing_down && ystep > 0 ? -1 : 1;
	next_x = xintercept;
	next_y = yintercept;
	while (next_x > 0 && next_y > 0
			&& next_x < g_scene.canvas.x && next_y < g_scene.canvas.y)
	{
		check_sprite(next_x + (ray->facing_right ? 1 : -1), next_y, ray);
		if (map_has_wall_at(next_x + (ray->facing_right ? 1 : -1), next_y))
		{
			wall->x = next_x;
			wall->y = next_y;
			return ;
		}
		next_x += xstep;
		next_y += ystep;
	}
	wall->x = -1;
	wall->y = -1;
}

t_dvector	find_vert_wall(t_ray *ray)
{
	double		xintercept;
	double		yintercept;
	t_dvector	wall;

	xintercept = floor(g_player.x / TILE_SIZE) * TILE_SIZE;
	xintercept += ray->facing_right ? TILE_SIZE : 0;
	yintercept = g_player.y + (xintercept - g_player.x) * tan(ray->angle);
	dda(ray, xintercept, yintercept, &wall);
	return (wall);
}
