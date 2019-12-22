/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:50:23 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/07 22:08:28 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	pf_putprefix(t_printf *pf, unsigned long long *ul)
{
	if (pf->type != 'u' && (long long)*ul < 0)
	{
		ft_putchar('-');
		*ul *= -1;
	}
	else if (pf->plus)
		ft_putchar('+');
	else if (pf->space)
		ft_putchar(' ');
	pf->plus = 0;
	pf->space = 0;
}
