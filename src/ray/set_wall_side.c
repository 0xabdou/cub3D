/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:09:20 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/18 20:34:28 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static char	get_wall_side(t_ray *ray)
{
	if (ray->facing_right)
	{
		if (ray->hit_horizontally)
		{
			if (ray->facing_down)
				return ('N');
			return ('S');
		}
		return ('W');
	}
	else
	{
		if (ray->hit_horizontally)
		{
			if (ray->facing_down)
				return ('N');
			return ('S');
		}
		return ('E');
	}
}

void		set_wall_side(t_ray *ray)
{
	ray->wall_side = get_wall_side(ray);
}
