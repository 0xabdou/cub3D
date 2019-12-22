/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:13:27 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/27 15:27:29 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	adjust_flags(t_printf *pf, int *size, unsigned long long n)
{
	pf->space = pf->type == 'u' || pf->type == 'c' ? 0 : pf->space;
	pf->space = pf->type == '%' ? 0 : pf->space;
	pf->plus = pf->type == 'u' || pf->type == 'c' ? 0 : pf->plus;
	pf->plus = pf->type != 'u' && (long long)n < 0 ? 0 : pf->plus;
	pf->plus = pf->type == '%' ? 0 : pf->plus;
	pf->precision = pf->precision < 0 || pf->type == 'c'
		|| pf->type == '%' ? 0 : pf->precision;
	pf->zero = pf->zero && (!pf->precision || pf->type == 'c') && !pf->minus;
	*size += pf->apo ? *size / 3 : 0;
	pf->precision = pf->precision - *size;
	pf->precision = pf->precision < 0 ? 0 : pf->precision;
	*size += (pf->type != 'u' && ((long long)n < 0)) || pf->plus || pf->space;
	if (pf->width < 0)
	{
		pf->width *= -1;
		pf->minus = True;
	}
	pf->width = pf->width - pf->precision - *size;
	pf->width = pf->width < 0 ? 0 : pf->width;
}

int			pf_putint(t_printf *pf, va_list *vl)
{
	int					size;
	unsigned long long	n;

	if (pf->type == '%')
		n = '%';
	else
		n = pf_getarg(pf, vl);
	if (pf->type == 'c' && pf->l && n > 255)
		return (-1);
	if (pf->type == 'c' || pf->type == '%')
		size = 1;
	else if (!pf->precised && !n)
		size = 0;
	else
		size = pf_getdignum(n, 10, pf->type);
	adjust_flags(pf, &size, n);
	pf_lcprint_n_clear(&(pf->before));
	pf_order(pf, n);
	return (size + pf->width + pf->precision + pf->space);
}
