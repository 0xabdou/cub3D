/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:34:40 by aouahib           #+#    #+#             */
/*   Updated: 2019/11/02 16:36:44 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	helper(unsigned long long ul)
{
	if (!ul)
		return ;
	helper(ul / 10);
	ft_putchar(ul % 10 + '0');
}

void	ft_putnbr_unsigned(unsigned long long ul)
{
	if (!ul)
	{
		ft_putchar('0');
		return ;
	}
	helper(ul);
}
