/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:44:53 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/27 15:34:02 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	put_width(int width)
{
	while (width--)
		ft_putchar(' ');
}

static void	putnstr(char *s, int n)
{
	while (n && *s)
	{
		ft_putchar(*s++);
		n--;
	}
}

int			pf_putstr(t_printf *pf, va_list *vl)
{
	char	*str;
	int		len;
	int		width;

	str = va_arg(*vl, char *);
	if (pf->l && str && !pf->period)
		return (-1);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	pf->precision = pf->precision < 0 ? len : pf->precision;
	len = pf->period && len > pf->precision ? pf->precision : len;
	if (pf->width < 0)
	{
		pf->width *= -1;
		pf->minus = True;
	}
	width = pf->width - len;
	width = width < 0 ? 0 : width;
	pf_lcprint_n_clear(&(pf->before));
	pf->minus ? putnstr(str, len) : put_width(width);
	!pf->minus ? putnstr(str, len) : put_width(width);
	return (width + len);
}
