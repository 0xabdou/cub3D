/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:09:11 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/22 19:14:20 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

int	handle_keys(int key, void *params)
{
	(void)params;
	if (key == K_W || key == K_S || key == K_A || key == K_D)
	{
		move_player(key);
		rotate_player(key);
	}
	else if (key == K_LA || key == K_RA)
		rotate_player(key);
	else if (key == K_ESC)
		game_over();
	return (0);
}
