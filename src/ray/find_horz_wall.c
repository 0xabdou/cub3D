/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_horz_dist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:51:22 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/21 13:15:10 by aouahib          ###   ########.fr       */
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

	next_x = xintercept;
	next_y = yintercept;
	ystep = TILE_SIZE * (ray->facing_down ? 1 : -1);
	xstep = TILE_SIZE / tan(ray->angle);
	xstep *= ray->facing_right && xstep < 0 ? -1 : 1;
	xstep *= !ray->facing_right && xstep > 0 ? -1 : 1;
	while (next_x > 0 && next_y > 0
			&& next_x < g_scene.canvas.x && next_y < g_scene.canvas.y)
	{

		check_sprite(next_x, next_y + (ray->facing_down ? 1 : -1), ray);
		if (map_has_wall_at(next_x, next_y + (ray->facing_down ? 1 : -1)))
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

t_dvector	find_horz_wall(t_ray *ray)
{
	double		xintercept;
	double		yintercept;
	t_dvector	wall;

	yintercept = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
	yintercept += ray->facing_down ? TILE_SIZE : 0;
	xintercept = g_player.x + (yintercept - g_player.y) / tan(ray->angle);
	dda(ray, xintercept, yintercept, &wall);
	return (wall);
}
