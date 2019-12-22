/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:10:32 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/07 22:21:03 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	signed_case(long long n, int size, int cur, int apo)
{
	if (!n)
		return ;
	signed_case(n / 10, size, cur - 1, apo);
	ft_putchar(n % 10 + '0');
	if (apo && size != cur && (size - cur) % 3 == 0)
		ft_putchar(',');
}

static void	unsigned_case(unsigned long long n, int size, int cur, int apo)
{
	if (!n)
		return ;
	signed_case(n / 10, size, cur - 1, apo);
	ft_putchar(n % 10 + '0');
	if (apo && size != cur && (size - cur) % 3 == 0)
		ft_putchar(',');
}

void		pf_putnbr(unsigned long long n, t_printf *pf)
{
	int		size;

	if (!n)
	{
		ft_putchar('0');
		return ;
	}
	size = pf_getdignum(n, 10, pf->type);
	if (pf->type == 'u')
		unsigned_case(n, size, size, pf->apo);
	else
		signed_case(n, size, size, pf->apo);
}
