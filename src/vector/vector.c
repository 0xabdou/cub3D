/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 20:58:04 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/18 20:39:23 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_dvector	new_dvector(double x, double y)
{
	t_dvector	dv;

	dv.x = x;
	dv.y = y;
	return (dv);
}

t_vector	new_vector(int x, int y)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	return (v);
}
