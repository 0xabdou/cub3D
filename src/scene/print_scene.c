/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:41:06 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/23 11:56:02 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdio.h>
static void	print_map(void)
{
	int	i;
	int	j;

	j = 0;
	while (j < g_scene.map_size.y)
	{
		i = 0;
		while (i < g_scene.map_size.x)
		{
			if (!i)
				ft_putstr("\t\t{");
			ft_putchar(g_scene.map[j * g_scene.map_size.x + i]);
			i++;
		}
		ft_putstr("}\n");
		j++;
	}
}

void		print_scene(void)
{
	printf("g_scene : {\n");
	printf("\tres : {%i, %i},\n",
			g_scene.resolution.x, g_scene.resolution.y);
	//printf("\tno : %s,\n", g_scene.north_texture);
	//printf("\tso : %s,\n", g_scene.south_texture);
	//printf("\twe : %s,\n", g_scene.west_texture);
	//printf("\tea : %s,\n", g_scene.east_texture);
	//printf("\tsp : %s,\n", g_scene.sprite_texture);
	printf("\tf : #%x,\n", g_scene.floor_color);
	printf("\tc : #%x,\n", g_scene.ceil_color);
	printf("\tmap.x : %i,\n", g_scene.map_size.x);
	printf("\tmap.y : %i,\n", g_scene.map_size.y);
	printf("\tmap: {\n");
	print_map();
	printf("\t},\n");
	printf("\tcanvas.x = %i, canvas.y = %i,\n", g_scene.canvas.x, g_scene.canvas.y);
	printf("\tplayer.x = %.2f, player.y = %.2f\n", g_player.x, g_player.y);
	printf("\tdir.x = %.2f, dir.y = %.2f\n", g_dir.x, g_dir.y);
	printf("\tcam.x = %.2f, cam.y = %.2f\n", g_cam.x, g_cam.y);
	printf("\tnum_sprites = %i\n", g_num_sprites);
	for (int i = 0; i < g_num_sprites; i++)
	{
		printf("\tsprite%i: {%f, %f}\n", i, g_sprites[i].x, g_sprites[i].y);
	}
	printf("}\n");
}
