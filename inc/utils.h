/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:32:41 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/27 13:30:04 by aouahib          ###   ########.fr       */
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
double	pow2(double x);
void	game_over(void);

#endif
