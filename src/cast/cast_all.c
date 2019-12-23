/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 22:29:28 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/23 16:35:39 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.h"

void	cast_all(void)
{
	t_cast	cast;
	int		x;

	reset_image();
	x = 0;
	while (x < g_scene.resolution.x)
	{
		init_cast(&cast, x);
		do_cast(&cast);
		draw_cast(&cast);
		x++;
	}
	draw_sprites();
}
