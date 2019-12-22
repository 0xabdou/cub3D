/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:58:29 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/17 15:44:15 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	rotate_player(int key)
{
	double	angle;

	angle = g_player.angle;
	if (key == K_LA)
		angle -= ROTATION_STEP;
	else if (key == K_RA)
		angle += ROTATION_STEP;
	g_player.angle = normalize_angle(angle);
}
