/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:46:29 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/18 17:02:25 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*udst;
	unsigned char	*usrc;

	if (!src && !dst)
		return (0);
	if (src < dst)
	{
		udst = (unsigned char *)dst + len - 1;
		usrc = (unsigned char *)src + len - 1;
		while (len--)
			*udst-- = *usrc--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
