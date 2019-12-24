/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 13:09:32 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/24 23:29:11 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"

t_bmph	get_header(void)
{
	int		height;
	int		width;
	t_bmph	bmph;

	width = g_scene.resolution.x;
	height = g_scene.resolution.y;
	bmph.id[0] = 'B';
	bmph.id[1] = 'M';
	bmph.bmp_file_size = sizeof(t_bmph) + 4 * width * height;
	bmph.unused = 0;
	bmph.offset = sizeof(t_bmph);
	bmph.dib = sizeof(t_bmph) - 14;
	bmph.width = width;
	bmph.height = -height;
	bmph.plane[0] = 1;
	bmph.plane[1] = 0;
	bmph.bpp[0] = 32;
	bmph.bpp[1] = 0;
	bmph.compression = 0;
	bmph.raw_bitmap_size = width * height * 4;
	bmph.resx = width;
	bmph.resy = height;
	bmph.number_of_colors = 0;
	bmph.important_colors = 0;
	return (bmph);
}

void	save_bmp(void)
{
	t_bmph	bmph;
	int		fd;

	fd = open("image.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	bmph = get_header();
	write(fd, &bmph, 54);
	write(fd, g_window.image.data, bmph.raw_bitmap_size);
	close(fd);
}
