/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:04:45 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/14 11:43:13 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	init_rays(void)
{
	double	ray_angle;
	int		num_rays;
	int		i;

	num_rays = g_scene.resolution.x;
	g_rays = malloc(num_rays * sizeof(t_ray));
	if (!g_rays)
	{
		g_error |= MEMORY_ERROR;
		return ;
	}
	i = 0;
	ray_angle = g_player.angle - FOV_ANGLE / 2;
	while (i < num_rays)
	{
		g_rays[i] = new_ray(ray_angle);
		ray_angle += FOV_ANGLE / num_rays;
		i++;
	}
}
