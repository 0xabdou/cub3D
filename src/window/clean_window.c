/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 23:13:03 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/23 23:14:39 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	clean_window(void)
{
	if (g_window.win_ptr)
		mlx_destroy_window(g_window.mlx_ptr, g_window.win_ptr);
	if (g_window.image.ptr)
		mlx_destroy_image(g_window.mlx_ptr, g_window.image.ptr);
}
