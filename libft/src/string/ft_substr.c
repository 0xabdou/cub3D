/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:18:56 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/30 15:06:27 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	max_len;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	max_len = slen - start + 1;
	if (max_len < len)
		len = max_len;
	if (start > slen)
		return (ft_strdup(""));
	sub = malloc(len + 1);
	if (sub)
		ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
