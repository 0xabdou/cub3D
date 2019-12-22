/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:12:31 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/25 18:12:54 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_count(char *f)
{
	int	count;

	count = 0;
	while (*f)
	{
		if (*f == '%')
		{
			count++;
			f++;
			while (pf_isflag(*f) || ft_isdigit(*f))
			{
				if (*f == '*')
					count++;
				f++;
			}
			if (*f == '%')
			{
				f++;
				count--;
			}
		}
		else
			f++;
	}
	return (count);
}
