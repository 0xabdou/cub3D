/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_getdignum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:42:36 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/02 21:29:29 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	signed_case(long long n, int base)
{
	int size;

	size = 0;
	while (n)
	{
		size++;
		n /= base;
	}
	return (size);
}

static int	unsigned_case(unsigned long long n, int base)
{
	int size;

	size = 0;
	while (n)
	{
		size++;
		n /= base;
	}
	return (size);
}

int			pf_getdignum(unsigned long long n, int base, char type)
{
	if (!n)
		return (1);
	return (type == 'u' ? unsigned_case(n, base) : signed_case(n, base));
}
