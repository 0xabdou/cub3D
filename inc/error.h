/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 12:19:50 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/09 14:27:43 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# define MEMORY_ERROR 1
# define RES_ERROR 2
# define FLOOR_ERROR 4
# define CEIL_ERROR 8
# define TEXTURE_ERROR 16
# define MAP_ERROR 32
# define MISSING_CONFIG_ERROR 64
# define READ_ERROR 128
# define MLX_ERROR 256
# include "libft.h"

int	g_error;

void	print_error(void);

#endif
