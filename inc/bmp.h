/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 14:28:07 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/24 20:11:33 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H
# include "window.h"
# include <unistd.h>
# include <fcntl.h>
# pragma pack(push, 1)

typedef struct	s_bmph
{
	char	id[2];
	int		total_size;
	int		unused;
	int		offset;
	int		header_size;
	int		image_width;
	int		image_height;
	char	planes[2];
	char	bpp[2];
	int		compression;
	int		bitmap_bytes;
	int		resx;
	int		resy;
	int		number_of_colors;
	int		important_colors;
}				t_bmph;

void	save_bmp(void);

# pragma pack(pop)
#endif
