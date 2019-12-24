/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 14:28:07 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/24 23:29:36 by aouahib          ###   ########.fr       */
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
	int		bmp_file_size;
	int		unused;
	int		offset;
	int		dib;
	int		width;
	int		height;
	char	plane[2];
	char	bpp[2];
	int		compression;
	int		raw_bitmap_size;
	int		resx;
	int		resy;
	int		number_of_colors;
	int		important_colors;
}				t_bmph;

void			save_bmp(void);

# pragma pack(pop)
#endif
