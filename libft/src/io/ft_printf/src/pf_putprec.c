/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putprec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:00:58 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/07 22:12:29 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	pf_putprec(t_printf *pf, unsigned long long ul)
{
	int	i;

	if (!pf->precised && !ul)
		return ;
	i = 0;
	while (pf->type != 'c' && i++ < pf->precision)
		ft_putchar('0');
	if (pf->type == 'c')
		ft_putchar(ul);
	else if (pf->type == '%')
		ft_putchar('%');
	else
		pf_putnbr(ul, pf);
}
