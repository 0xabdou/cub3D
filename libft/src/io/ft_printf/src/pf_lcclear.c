/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lcclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:53:31 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/06 15:27:46 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_lcclear(t_linked_char **lc)
{
	t_linked_char	*tmp1;
	t_linked_char	*tmp2;

	if (!lc)
		return (-1);
	tmp1 = *lc;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
	}
	*lc = 0;
	return (-1);
}
