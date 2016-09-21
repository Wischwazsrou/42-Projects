/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_low.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 17:32:57 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/27 19:58:41 by vklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_c_low(unsigned char c, t_d *d)
{
	if (d->dot == 0)
		d->preci = 0;
	if (d->preci == 1)
	{
		while (d->width-- > 1)
			d->zero == 1 ? ft_putcharf('0') : ft_putcharf(' ');
		ft_putcharf(c);
	}
	else if (d->side == 0)
	{
		while (d->width-- > 1 && d->dot == 0)
			d->zero == 1 ? ft_putcharf('0') : ft_putcharf(' ');
		ft_putcharf(c);
	}
	else
	{
		ft_putcharf(c);
		while (d->width-- > 1)
			ft_putcharf(' ');
	}
}

void	print_c_upp(wchar_t c, t_d *d)
{
	d->width--;
	if (d->side == 0)
	{
		while (d->width-- > 1 && d->dot == 0)
			d->zero == 1 ? ft_putcharf('0') : ft_putcharf(' ');
		ft_putwchar(c);
	}
	else
	{
		ft_putwchar(c);
		while (d->width-- > 1)
			ft_putcharf(' ');
	}
}
