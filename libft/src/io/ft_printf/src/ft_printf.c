/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:46:44 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/07 21:22:37 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	put_printf(t_printf *pf, va_list *vl, int res)
{
	char	c;

	c = pf->type;
	if (!pf_istype(c))
	{
		pf_lcprint_n_clear(&(pf->before));
		ft_putchar(c);
		return (1);
	}
	if (c == 's')
		return (pf_putstr(pf, vl));
	else if (c == '%' || c == 'c' || c == 'd' || c == 'i' || c == 'u')
		return (pf_putint(pf, vl));
	else if (c == 'p' || c == 'x' || c == 'X')
		return (pf_puthex(pf, vl));
	else if (c == 'n')
		return (pf_write_data(pf, vl, res));
	return (0);
}

static int	append(t_linked_char **lc, char c)
{
	static t_linked_char	*cur;
	t_linked_char			*new;

	new = pf_lcnew(c);
	if (!new)
		return (0);
	if (!*lc)
	{
		*lc = new;
		cur = new;
	}
	else
	{
		cur->next = new;
		cur = new;
	}
	return (1);
}

static int	helper(const char **f, t_linked_char **lc, va_list *vl, int res)
{
	t_printf				*pf;
	const char				*format;
	int						ret;

	format = *f;
	if (*format == '%')
	{
		format++;
		if (!(pf = pf_parse(&format, vl)))
			return (pf_lcclear(lc));
		pf->before = *lc;
		ret = put_printf(pf, vl, res);
		free(pf);
		if (res == -1)
			return (pf_lcclear(lc));
		*lc = 0;
	}
	else
	{
		if (!append(lc, *format++))
			return (pf_lcclear(lc));
		ret = 1;
	}
	*f = format;
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list			valist;
	t_linked_char	*lc;
	int				ret;
	int				res;

	va_start(valist, format);
	ret = 0;
	lc = 0;
	while (*format)
	{
		res = helper(&format, &lc, &valist, ret);
		if (res == -1)
			return (-1);
		ret += res;
	}
	pf_lcprint_n_clear(&lc);
	return (ret);
}
