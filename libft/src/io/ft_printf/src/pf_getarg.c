/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_getarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 20:07:57 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/07 21:48:15 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static unsigned long long	unsigned_case(t_printf *pf, va_list *vl)
{
	unsigned long long l;

	l = va_arg(*vl, unsigned long long);
	if (pf->ll)
		return (l);
	else if (pf->l)
		return ((unsigned long)l);
	else if (pf->h)
		return ((unsigned short)l);
	else if (pf->hh)
		return ((unsigned char)l);
	return ((unsigned)l);
}

static long long			signed_case(t_printf *pf, va_list *vl)
{
	long long l;

	l = va_arg(*vl, long long);
	if (pf->ll)
		return (l);
	else if (pf->l)
		return ((long)l);
	else if (pf->h)
		return ((short)l);
	else if (pf->hh)
		return ((char)l);
	else
		return ((int)l);
}

unsigned long long			pf_getarg(t_printf *pf, va_list *vl)
{
	if (pf->type == 'p')
		pf->ll = True;
	if (pf->type == 'c' || pf->type == 'u' || pf->type == 'p'
			|| pf->type == 'x' || pf->type == 'X')
		return (unsigned_case(pf, vl));
	else
		return (signed_case(pf, vl));
}
