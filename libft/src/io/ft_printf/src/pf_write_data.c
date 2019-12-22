/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_write_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:16:26 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/05 22:46:48 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_write_data(t_printf *pf, va_list *vl, int val)
{
	int	*addr;

	pf_lcprint_n_clear(&(pf->before));
	addr = va_arg(*vl, int *);
	*addr = val;
	return (0);
}
