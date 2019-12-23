/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:43:33 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/23 22:59:55 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	clean_scene(void)
{
	free(g_scene.map);
	free(g_scene.north_path);
	free(g_scene.south_path);
	free(g_scene.east_path);
	free(g_scene.west_path);
	free(g_scene.sprite_path);
	free(g_distances);
	free(g_sprites);
}
