/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:31:25 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/07 22:09:14 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	pf_order(t_printf *pf, unsigned long long l)
{
	int	flag;

	flag = 1;
	if (pf->minus)
	{
		pf_putprefix(pf, &l);
		pf_putprec(pf, l);
		pf_putwidth(pf->width, pf->zero);
	}
	else
	{
		if (pf->zero)
		{
			pf_putprefix(pf, &l);
			flag = 0;
		}
		pf_putwidth(pf->width, pf->zero);
		if (flag)
			pf_putprefix(pf, &l);
		pf_putprec(pf, l);
	}
}
