/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:05:54 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/18 20:33:22 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static double	get_distance(t_dvector wall)
{
	if (wall.x == -1)
		return (DBL_MAX);
	return (distance(g_player.x, g_player.y, wall.x, wall.y));
}

void			cast_ray(t_ray *ray)
{
	t_dvector	horz;
	t_dvector	vert;
	double		horz_dist;
	double		vert_dist;

	horz = find_horz_wall(ray);
	vert = find_vert_wall(ray);
	horz_dist = get_distance(horz);
	vert_dist = get_distance(vert);
	if (horz_dist < vert_dist)
	{
		ray->distance = horz_dist;
		ray->wall_hit = horz;
		ray->hit_horizontally = 1;
	}
	else
	{
		ray->distance = vert_dist;
		ray->wall_hit = vert;
		ray->hit_horizontally = 0;
	}
	set_wall_side(ray);
}
