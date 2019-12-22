/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 20:49:07 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/22 22:29:21 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_H
# define CAST_H
# include "player.h"
#include "scene.h"

typedef struct	s_cast
{
	int		index;
	double	rdx;
	double	rdy;
	double	sdx;
	double	sdy;
	double	ddx;
	double	ddy;
	int		stepx;
	int		stepy;
	int		mapx;
	int		mapy;
	int		side;
	double	pdist;
}				t_cast;

void	init_cast(t_cast *cast, int x);
void	do_cast(t_cast *cast);
void	draw_cast(t_cast *cast);
void	cast_all(void);

#endif
