/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:32:35 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/24 13:04:12 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "window.h"
#include "cast.h"

static int	args_error(void)
{
		g_error |= ARGS_ERROR;
		return (print_error());
}

int			main(int c, char **v)
{
	if (c < 2 || c > 3)
		return (args_error());
	if (c == 3 && ft_strncmp(v[2], "--save", 7))
		return (args_error());
	if (c == 3)
		g_scene.save =1;
	init_scene(v[1]);
	if (g_error)
		return (print_error());
	init_window();
	if (g_error)
		return (print_error());
	handle_keys(-1, 0);
	mlx_hook(g_window.win_ptr, 2, 1L << 0, handle_keys, 0);
	mlx_loop(g_window.mlx_ptr);
	return (0);
}
