/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:02:27 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/18 13:54:53 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	init_textures(void)
{
	load_texture(&g_scene.north_texture, g_scene.north_path);
	load_texture(&g_scene.south_texture, g_scene.south_path);
	load_texture(&g_scene.east_texture, g_scene.east_path);
	load_texture(&g_scene.west_texture, g_scene.west_path);
	load_texture(&g_scene.sprite_texture, g_scene.sprite_path);
}
