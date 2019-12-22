/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:45:27 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/29 14:01:29 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**clear(char **s)
{
	while (*s)
		free(*s);
	free(s);
	return (0);
}

static char	**fill(char **split, const char *s, char c, int count)
{
	int	i;
	int	j;
	int	start;
	int	len;

	i = 0;
	j = 0;
	while (j < count)
	{
		while (s[i] == c)
			i++;
		start = i;
		len = 0;
		while (s[i] && s[i] != c)
		{
			len++;
			i++;
		}
		split[j] = ft_substr(s, start, len);
		if (!split[j])
			return (clear(split));
		j++;
	}
	split[count] = 0;
	return (split);
}

char		**ft_split(const char *s, char c)
{
	char	**split;
	int		i;
	int		count;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			count++;
		i++;
	}
	split = malloc((count + 1) * sizeof(char *));
	if (!split)
		return (0);
	return (fill(split, s, c, count));
}
