/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 20:49:07 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/22 21:03:36 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_H
# define CAST_H
# include "player.h"

typedef struct	s_cast
{
	double	sdx;
	double	sdy;
	double	ddx;
	double	ddy;
	int		stepx;
	int		stepy;
}				t_cast;

void	init_cast(t_cast *cast, double rdx, double rdy);

#endif
