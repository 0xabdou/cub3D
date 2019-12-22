/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:54:34 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/09 14:29:06 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	print_error(void)
{
	if (g_error & MEMORY_ERROR)
		ft_putstr("Memory error\n");
	if (g_error & MAP_ERROR)
		ft_putstr("Map error\n");
	if (g_error & RES_ERROR)
		ft_putstr("Resolution error\n");
	if (g_error & FLOOR_ERROR)
		ft_putstr("Floor color error\n");
	if (g_error & CEIL_ERROR)
		ft_putstr("Ceiling color error\n");
	if (g_error & TEXTURE_ERROR)
		ft_putstr("Texture error\n");
	if (g_error & MISSING_CONFIG_ERROR)
		ft_putstr("Missing config error\n");
	if (g_error & MLX_ERROR)
		ft_putstr("MLX error\n");
}
