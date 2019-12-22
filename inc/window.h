/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:20:33 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/18 13:03:35 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include "image.h"
# include "scene.h"
# include "ray.h"
# include <mlx.h>

typedef struct	s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	image;
}				t_window;

t_window		g_window;

void			init_window(void);
void            load_texture(t_image *texture, char *texture_path);
void			init_textures(void);
void			render_walls(void);
void			hook_window(void);
int				handle_keys(int key, void *params);
int				refresh(void *params);

#endif
