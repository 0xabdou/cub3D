/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:28:55 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/22 16:24:13 by aouahib          ###   ########.fr       */
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

t_dvector		g_player;
t_dvector		g_dir;
t_dvector		g_cam;

void			init_player(int x, int y, char orientation);
void			rotate_player(int key);
void			move_player(int key);

#endif
