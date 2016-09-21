/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pourcent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 21:37:11 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/24 21:37:15 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_pourcent(t_d *d)
{
	if (d->dot == 1 && d->preci == 0)
		return ;
	else if (d->dot == 1 && d->preci == 1)
		while (d->width-- > 1)
			ft_putcharf('0');
	else
	{
		if (d->side == 0)
		{
			while (d->width-- > 1)
				d->zero == 0 ? ft_putcharf(' ') : ft_putcharf('0');
			ft_putcharf('%');
		}
		if (d->side == 1)
		{
			ft_putcharf('%');
			while (d->width-- > 1)
				ft_putcharf(' ');
		}
		d->pourcent = 1;
	}
}
