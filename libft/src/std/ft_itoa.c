/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:57:35 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/18 21:45:01 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*case_zero(void)
{
	char	*str;

	str = malloc(2);
	if (str)
	{
		str[0] = '0';
		str[1] = 0;
	}
	return (str);
}

static int	get_size(int n)
{
	int	size;

	size = 1 + (n < 0);
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*str;

	if (!n)
		return (case_zero());
	size = get_size(n);
	str = malloc(size);
	if (!str)
		return (0);
	str[--size] = 0;
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		str[--size] = ABS(n % 10) + '0';
		n /= 10;
	}
	return (str);
}
