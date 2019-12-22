/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lcnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:33:32 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/06 16:48:10 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_linked_char	*pf_lcnew(char c)
{
	t_linked_char	*lc;

	lc = malloc(sizeof(t_linked_char));
	if (!lc)
		return (0);
	lc->c = c;
	lc->next = 0;
	return (lc);
}
