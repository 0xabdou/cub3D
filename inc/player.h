/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:28:55 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/22 19:09:49 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "player.h"
# include "scene.h"
# include "keys.h"
# include <math.h>
# define ROT_STEP 0.1
# define MOVE_STEP 0.3

t_dvector		g_player;
t_dvector		g_dir;
t_dvector		g_cam;

void			init_player(int x, int y, char orientation);
void			rotate_player(int key);
void			move_player(int key);

#endif
