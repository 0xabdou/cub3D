/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:32:41 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/22 22:54:17 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "libft.h"
# include "error.h"
# include "scene.h"
# include <math.h>
# define RGB(r, g, b) ((r) << 16 | (g) << 8 | (b))

int		is_num(char *s);
void	free_split(char **s);
double	distance(double x1, double y1, double x2, double y2);
double	normalize_angle(double angle);
void	game_over(void);

#endif
