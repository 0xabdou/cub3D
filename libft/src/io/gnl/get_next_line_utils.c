/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:30:31 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/06 18:48:18 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	const char	*tmp;

	if (!s)
		return (0);
	tmp = s;
	while (*tmp)
		tmp++;
	return (tmp - s);
}

char	*gnl_strchr(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (0);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!src)
	{
		*dst = 0;
		return (0);
	}
	i = 0;
	while (i + 1 < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = 0;
	return (gnl_strlen(src));
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	size;

	size = gnl_strlen(s1) + gnl_strlen(s2) + 1;
	join = malloc(size);
	if (join)
	{
		gnl_strlcpy(join, s1, size);
		gnl_strlcpy(join + gnl_strlen(s1), s2, size);
	}
	return (join);
}

char	*gnl_strdup(const char *s1)
{
	char	*dup;
	size_t	size;

	size = gnl_strlen(s1) + 1;
	dup = malloc(size);
	if (dup)
		gnl_strlcpy(dup, s1, size);
	return (dup);
}
