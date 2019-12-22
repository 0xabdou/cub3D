/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lcprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:42:23 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/06 14:55:02 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	pf_lcprint_n_clear(t_linked_char **lc)
{
	t_linked_char	*tmp1;
	t_linked_char	*tmp2;

	if (!lc)
		return ;
	tmp1 = *lc;
	while (tmp1)
	{
		tmp2 = tmp1;
		ft_putchar(tmp1->c);
		tmp1 = tmp1->next;
		free(tmp2);
	}
	*lc = 0;
}
