/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 20:59:37 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/17 21:01:15 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;


typedef struct	s_dvector
{
	double	x;
	double	y;
}				t_dvector;

t_vector	new_vector(int x, int y);
t_dvector	new_dvector(double x, double y);

#endif
