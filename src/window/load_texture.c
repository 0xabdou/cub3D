/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:20:44 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/18 20:26:21 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	load_texture(t_image *texture, char *texture_path)
{
	int	h;
	int	w;

	if (g_error)
		return ;
	h = TEX_SIZE;
	w = TEX_SIZE;
	texture->ptr = mlx_xpm_file_to_image(
			g_window.mlx_ptr, texture_path, &w, &h);
	if (!texture->ptr)
	{
		g_error |= TEXTURE_ERROR;
		return ;
	}
	texture->data = (int *)mlx_get_data_addr(
			texture->ptr,
			&texture->bpp,
			&texture->line_size,
			&texture->endian);
	if (!texture->data)
		g_error |= TEXTURE_ERROR;
}
