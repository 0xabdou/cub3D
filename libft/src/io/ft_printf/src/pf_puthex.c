/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:55:47 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/27 15:24:31 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	put_hex(unsigned long h, char type)
{
	char *hex;

	if (!h)
		return ;
	hex = type == 'X'
		? "0123456789ABCDEF"
		: "0123456789abcdef";
	put_hex(h / 16, type);
	ft_putchar(hex[h % 16]);
}

static void	put_width(int width, int zero)
{
	int	i;

	i = 0;
	while (i++ < width)
		ft_putchar(zero ? '0' : ' ');
}

static void	put_prec_nbr(t_printf *pf, unsigned long n)
{
	int	i;

	if (!pf->precised && !n)
		return ;
	i = 0;
	while (i++ < pf->precision)
		ft_putchar('0');
	if (!n)
		ft_putchar('0');
	else
		put_hex(n, pf->type);
}

static void	priority(t_printf *pf, unsigned long h)
{
	if (pf->minus)
	{
		if (pf->hash)
			ft_putstr("0x");
		put_prec_nbr(pf, h);
		put_width(pf->width, pf->zero);
	}
	else
	{
		if (pf->zero && pf->hash)
		{
			ft_putstr(pf->type == 'X' ? "0X" : "0x");
			pf->hash = False;
		}
		put_width(pf->width, pf->zero);
		if (pf->hash)
			ft_putstr(pf->type == 'X' ? "0X" : "0x");
		put_prec_nbr(pf, h);
	}
}

int			pf_puthex(t_printf *pf, va_list *vl)
{
	unsigned long long	h;
	int					size;

	h = pf_getarg(pf, vl);
	if (!pf->precised && !h)
		size = 0;
	else
		size = pf_getdignum(h, 16, 'u');
	pf->zero = pf->zero && !pf->period && !pf->minus;
	pf->precision = pf->precision - size;
	pf->precision = pf->precision < 0 ? 0 : pf->precision;
	pf->hash = (pf->hash && h) || pf->type == 'p';
	if (pf->hash)
		size += 2;
	if (pf->width < 0)
	{
		pf->width *= -1;
		pf->minus = True;
	}
	pf->width = pf->width - pf->precision - size;
	pf->width = pf->width < 0 ? 0 : pf->width;
	pf_lcprint_n_clear(&(pf->before));
	priority(pf, h);
	return (size + pf->width + pf->precision);
}
