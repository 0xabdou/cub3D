/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:05:44 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/18 20:25:41 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

static int	closed_using_x(void *params)
{
	(void)params;
	game_over();
	return (0);
}

void		hook_window(void)
{
	mlx_hook(g_window.win_ptr, 2, 1L << 0, handle_keys, 0);
	mlx_hook(g_window.win_ptr, 17, 1L << 0, closed_using_x, 0);
	mlx_loop_hook(g_window.mlx_ptr, refresh, 0);
}
