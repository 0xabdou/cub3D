/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:39:39 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/16 20:47:20 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*tmp;
	char		ch;

	ch = c;
	tmp = ft_strchr(s, 0);
	while (s <= tmp)
	{
		if (*tmp == c)
			return ((char *)tmp);
		tmp--;
	}
	return (0);
}
