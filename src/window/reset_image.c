/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 22:42:50 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/23 23:09:47 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

static void	set_ceil(void)
{
	int *image;
	int i;
	int j;

	image = g_window.image.data;
	i = 0;
	while (i < g_scene.resolution.y / 2)
	{
		j = 0;
		while (j < g_scene.resolution.x)
		{
			image[j + i * g_window.image.line_size] = g_scene.ceil_color;
			j++;
		}
		i++;
	}
}

static void	set_floor(void)
{
	int *image;
	int i;
	int j;

	image = g_window.image.data;
	i = g_scene.resolution.y / 2;
	while (i < g_scene.resolution.y)
	{
		j = 0;
		while (j < g_scene.resolution.x)
		{
			image[j + i * g_window.image.line_size] = g_scene.floor_color;
			j++;
		}
		i++;
	}
}

void		reset_image(void)
{
	set_floor();
	set_ceil();
}
