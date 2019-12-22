/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:40:19 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/18 11:52:30 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "vector.h"
# include "image.h"
# include "error.h"
# include "utils.h"
# include "player.h"
# include "window.h"
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# define TILE_SIZE 32
# define TEX_SIZE 64
# define RES_FLAG 1
# define NO_FLAG 2
# define SO_FLAG 4
# define WE_FLAG 8
# define EA_FLAG 16
# define SP_FLAG 32
# define F_FLAG 64
# define C_FLAG 128
# define FULL_FLAG 255
# define MAP_FLAG 256

typedef struct	s_scene
{
	t_vector	resolution;
	char		*north_path;
	char		*south_path;
	char		*west_path;
	char		*east_path;
	char		*sprite_path;
	int			floor_color;
	int			ceil_color;
	t_vector	map_size;
	char		*map;
	t_vector	canvas;
	t_image		north_texture;
	t_image		south_texture;
	t_image		west_texture;
	t_image		east_texture;
	t_image		sprite_texture;
}				t_scene;

t_scene			g_scene;

void			init_scene(char *scene_path);
int				set_color(char *line, int flags);
int				set_path(char *line, int flags);
int				set_resolution(char *line, int flags);
void			set_map(int fd, char *line);
void			verify_map();
void			print_scene(void);
void			clean_scene(void);
int				map_has_wall_at(double x, double y);

#endif
