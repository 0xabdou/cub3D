/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:34:37 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/17 20:06:36 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*usrc;
	unsigned char		*udst;

	if (!src && !dst)
		return (0);
	usrc = src;
	udst = dst;
	while (n--)
		*udst++ = *usrc++;
	return (dst);
}
