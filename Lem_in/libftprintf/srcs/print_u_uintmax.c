/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_uintmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 12:25:26 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/17 12:44:22 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	print_u_uintmax_bis(uint64_t nbr, t_d *d, int i)
{
	if (d->dot == 1)
	{
		while (d->tmp_width-- > i)
			ft_putcharf('0');
	}
	if (nbr >= 10)
	{
		print_u_uintmax_bis(nbr / 10, d, i);
		print_u_uintmax_bis(nbr % 10, d, i);
	}
	if (nbr < 10)
		ft_putcharf(nbr + 48);
}

static	void	check_side(uint64_t nbr, t_d *d, int i)
{
	if (d->side == 0)
	{
		while (d->width > i && d->width > d->tmp_width)
		{
			if (d->zero == 1 || (d->tmp_width == 0 && d->dot == 1
					&& d->preci == 0))
				ft_putcharf('0');
			else
				ft_putcharf(' ');
			d->width--;
		}
		print_u_uintmax_bis(nbr, d, i);
	}
	else
	{
		while (d->tmp_width > i)
		{
			ft_putcharf('0');
			d->tmp_width--;
			d->width--;
		}
		print_u_uintmax_bis(nbr, d, i);
		while (d->width-- > i)
			ft_putcharf(' ');
	}
}

void			print_u_uintmax(uint64_t nbr, t_d *d)
{
	int			i;
	uint64_t	tmp;

	tmp = nbr;
	i = 0;
	while (tmp > 0)
	{
		tmp /= 10;
		i++;
	}
	check_side(nbr, d, i);
}
