/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 13:09:32 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/24 22:23:04 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"

void	save_bmp(void)
{
	int fd = open("image.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0666);

	int header_size = 54;
	int	width = g_scene.resolution.x, height = -g_scene.resolution.y;

	write(fd, "BM", 2);

	int	bmp_file_size = 54 + width * height * 4;
	write(fd, &bmp_file_size, 4);

	int	unused = 0;
	write(fd, &unused, 4);

	int offset = header_size;
	write(fd, &offset, 4);

	int dib = header_size - 14;
	write(fd, &dib, 4);
	
	write(fd, &width, 4);

	write(fd, &height, 4);

	char plane[2] = {1, 0};
	write(fd, plane, 2);

	char bpp[2] = {32, 0};
	write(fd, bpp, 2);

	int compression = 0;
	write(fd, &compression, 4);

	int raw_bitmap = width * height * 4;
	write(fd, &raw_bitmap, 4);

	int resolution_x = width;
	write(fd, &resolution_x, 4);

	int resolution_y = height;
	write(fd, &resolution_y, 4);

	int number_of_colors = 0;
	write(fd, &number_of_colors, 4);

	int important_colors = 0;
	write(fd, &important_colors, 4);

	for (int i = 0; i < g_scene.resolution.y; i++)
	{
		for (int j = 0; j < g_scene.resolution.x; j++)
		{
			int color = g_window.image.data[j + i * g_window.image.line_size];
			write(fd, &color, 4);
		}
	}
	close (fd);
}
