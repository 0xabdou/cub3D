/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:04:37 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/21 21:00:29 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	cast_all_rays(void)
{
	double	ray_angle;
	int		num_rays;
	int		i;

	ray_angle = g_player.angle - FOV_ANGLE / 2;
	num_rays = g_scene.resolution.x;
	i = 0;
	while (i < num_rays)
	{
		g_rays[i] = new_ray(ray_angle);
		g_rays[i].index = i;
		cast_ray(g_rays + i);
		ray_angle += FOV_ANGLE / num_rays;
		i++;
	}
}
