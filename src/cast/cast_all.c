/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 22:29:28 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/23 13:54:04 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.h"

void	cast_all(void)
{
	t_cast cast;

	reset_image();
	int w = g_scene.resolution.x;
	for(int x = 0; x < w; x++)
	{
		init_cast(&cast, x);
		do_cast(&cast);
		draw_cast(&cast);
	}
	draw_sprites();
}
