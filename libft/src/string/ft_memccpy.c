/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:48:53 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/17 19:58:21 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*usrc;
	unsigned char		*udst;

	usrc = src;
	udst = dst;
	while (n--)
	{
		*udst++ = *usrc;
		if (*usrc == (unsigned char)c)
			return (udst);
		usrc++;
	}
	return (0);
}
