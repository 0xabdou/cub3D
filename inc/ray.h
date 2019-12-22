/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:50:58 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/21 20:59:56 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "vector.h"
# include "scene.h"
# include <float.h>

typedef struct	s_ray
{
	double		angle;
	t_dvector	wall_hit;
	double		distance;
	int			facing_down;
	int			facing_right;
	int			hit_horizontally;
	char		wall_side;
	int			is_sprite;
	int			index;
	t_dvector	sprite_hit;
}				t_ray;

typedef struct	s_sprite_render
{
	int			start_x;
	int			end_x;
	int			started;
	double		distance;
	t_image		*texture;
}				t_sprite_render;

t_sprite_render	g_sprite_render;
t_ray			*g_rays;

void			init_rays(void);
t_ray			new_ray(double angle);
t_dvector		find_horz_wall(t_ray *ray);
t_dvector		find_vert_wall(t_ray *ray);
void			cast_ray(t_ray *ray);
void			cast_all_rays(void);
void			set_wall_side(t_ray *ray);
void            put_column(int x, int height, t_ray *ray);
void			free_rays(void);
void			check_sprite(double x, double y, t_ray *ray);

#endif
