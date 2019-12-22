/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:56:59 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/07 20:05:51 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	set_field(const char **format, t_printf *pf)
{
	const char *f;

	f = *format;
	pf->zero = *f == '0' ? True : pf->zero;
	pf->hash = *f == '#' ? True : pf->hash;
	pf->plus = *f == '+' ? True : pf->plus;
	pf->space = *f == ' ' ? True : pf->space;
	pf->minus = *f == '-' ? True : pf->minus;
	pf->apo = *f == '\'' ? True : pf->apo;
	if (ft_isdigit(*f) || *f == '.')
	{
		if (ft_isdigit(*f))
			pf->width = ft_atoi(f);
		else if (*f == '.')
		{
			pf->precision = ft_atoi(++f);
			pf->precised = pf->precision != 0;
			pf->period = True;
		}
		while (ft_isdigit(*f))
			f++;
		*format = f - 1;
		return ;
	}
}

static void	set_format(const char **format, t_printf *pf)
{
	const char	*f;

	f = *format;
	if (*f == 'l' && *(f + 1) == 'l')
	{
		pf->ll = True;
		f++;
	}
	else if (*f == 'l')
		pf->l = True;
	else if (*f == 'h' && *(f + 1) == 'h')
	{
		pf->hh = True;
		f++;
	}
	else if (*f == 'h')
		pf->h = True;
	*format = f;
}

static void	set_fields(const char **format, va_list *vl, t_printf *pf)
{
	const char	*f;

	f = *format;
	while (pf_isflag(*f) || ft_isdigit(*f) || *f == 'l' || *f == 'h')
	{
		if (*f == '*')
			pf->width = va_arg(*vl, int);
		else if (*f == '.' && *(f + 1) == '*')
		{
			pf->period = True;
			pf->precision = va_arg(*vl, int);
			pf->precised = pf->precision != 0;
			f++;
		}
		else if (*f == 'l' || *f == 'h')
			set_format(&f, pf);
		else
			set_field(&f, pf);
		f++;
	}
	pf->type = *f;
	*format = ++f;
}

static void	init(t_printf *p)
{
	p->type = 0;
	p->space = False;
	p->plus = False;
	p->minus = False;
	p->zero = False;
	p->period = False;
	p->hash = False;
	p->apo = False;
	p->width = 0;
	p->precision = 0;
	p->precised = True;
	p->ll = 0;
	p->l = 0;
	p->hh = 0;
	p->h = 0;
}

t_printf	*pf_parse(const char **format, va_list *vl)
{
	t_printf	*pf;

	pf = malloc(sizeof(t_printf));
	if (!pf)
		return (0);
	init(pf);
	set_fields(format, vl, pf);
	return (pf);
}
