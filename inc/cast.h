/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 20:49:07 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/22 21:38:50 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_H
# define CAST_H
# include "player.h"
#include "scene.h"

typedef struct	s_cast
{
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

#endif
