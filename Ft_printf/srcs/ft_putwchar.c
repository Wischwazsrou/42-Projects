/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 12:19:18 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/25 12:19:20 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_putwchar(unsigned int wc)
{
	int		o_init;

	o_init = ft_o_count(wc);
	if (o_init > 7)
	{
		if (o_init > 11)
		{
			if (o_init > 16)
			{
				ft_putcharf(((wc >> 18) & 7) | 240);
				ft_putcharf(((wc >> 12) & 63) | 128);
			}
			else
				ft_putcharf(((wc >> 12) & 15) | 224);
			ft_putcharf(((wc >> 6) & 63) | 128);
		}
		else
			ft_putcharf(((wc >> 6) & 31) | 192);
		ft_putcharf((wc & 63) | 128);
	}
	else
		ft_putcharf(wc);
}
