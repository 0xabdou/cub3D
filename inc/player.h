/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:28:55 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/18 11:57:19 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "player.h"
# include "scene.h"
# include "keys.h"
# include <math.h>
# define FOV_ANGLE (66 * (M_PI / 180))
# define ROTATION_STEP (5 * (M_PI / 180))
# define MOVE_STEP 8

typedef struct	s_player
{
	double	angle;
	double	x;
	double	y;
}				t_player;

t_player		g_player;

void			init_player(int x, int y, char orientation);
void			rotate_player(int key);
void			move_player(int key);

#endif
