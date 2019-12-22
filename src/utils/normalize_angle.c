/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:23:33 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/18 20:39:55 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	normalize_angle(double angle)
{
	angle = fmod(angle, M_PI * 2);
	angle += angle < 0 ? M_PI * 2 : 0;
	return (angle);
}
