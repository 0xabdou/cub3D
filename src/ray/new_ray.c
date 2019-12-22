/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:06:14 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/21 13:37:26 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	new_ray(double angle)
{
	t_ray	new_ray;

	angle = normalize_angle(angle);
	new_ray.angle = angle;
	new_ray.wall_hit = new_dvector(0, 0);
	new_ray.sprite_hit = new_dvector(0, 0);
	new_ray.is_sprite = 0;
	new_ray.distance = 0.0;
	new_ray.facing_down = angle >= 0 && angle < M_PI;
	new_ray.facing_right = angle >= 1.5 * M_PI || angle < 0.5 * M_PI;
	return (new_ray);
}
