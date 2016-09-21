/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_intmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 12:24:50 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/22 13:09:50 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		print(int64_t nbr, t_d *d, int i)
{
	if (nbr < -9223372036854775807)
		ft_putstrf("-9223372036854775808");
	if (d->sign == 1 && nbr >= 0)
	{
		ft_putcharf('+');
		d->sign = 0;
	}
	if (nbr < 0 && nbr >= -9223372036854775807)
	{
		nbr = -nbr;
		ft_putcharf('-');
		d->sign = 0;
	}
	if (d->dot == 1)
		while (d->tmp_width-- > i)
			ft_putcharf('0');
	if (nbr >= 10)
	{
		print(nbr / 10, d, i);
		print(nbr % 10, d, i);
	}
	if (nbr >= 0 && nbr < 10)
		ft_putcharf(nbr + 48);
}

static void		check_side_bis(int64_t nbr, t_d *d, int i)
{
	d->width = d->sign == 1 && nbr >= 0 ? d->width - 1 : d->width;
	while (d->dot == 1 && d->tmp_width-- > i && d->width-- >= 0)
		ft_putcharf('0');
	print(nbr, d, i);
	while (d->width > i++)
		ft_putcharf(' ');
}

static void		check_side(int64_t nbr, t_d *d, int i)
{
	if (d->side == 0)
	{
		d->width = d->sign == 1 && nbr >= 0 ? d->width - 1 : d->width;
		if (d->width > d->tmp_width && nbr < 0 && d->tmp_width > i)
			d->width--;
		d->width = nbr < 0 && d->tmp_width < i && d->tmp_width > 0 ?
			d->width - 1 : d->width;
		while (d->width > d->tmp_width && d->width-- > i)
		{
			if ((d->zero == 1 && d->dot == 0) || (d->tmp_width == 0
					&& d->dot == 1 && d->preci == 0) || d->tmp_width == i)
			{
				nbr < 0 ? ft_putcharf('-') : 0;
				d->sign = nbr < 0 ? 0 : d->sign;
				nbr = nbr < 0 ? -nbr : nbr;
				ft_putcharf('0');
			}
			else
				ft_putcharf(' ');
		}
		d->width--;
		print(nbr, d, i);
	}
	else
		check_side_bis(nbr, d, i);
}

static	void	check_flags_d(int64_t nbr, t_d *d, int i)
{
	if (nbr == 0)
		i++;
	if (nbr >= 0 && d->sign == 1 && (d->zero == 1 || d->side == 1))
	{
		ft_putcharf('+');
		d->width = d->tmp_width < d->width ? d->width - 1 : i;
		d->sign = 0;
	}
	if (nbr < 0 && (d->dot == 1 || d->zero == 1) &&
		(d->width < i || d->side == 1))
	{
		nbr = -nbr;
		d->sign = 0;
		ft_putcharf('-');
		d->width = d->dot == 1 && d->tmp_width != 0 ? d->width - 1 : d->width;
	}
	check_side(nbr, d, i);
}

void			print_d_intmax(int64_t nbr, t_d *d)
{
	int			i;
	int64_t		tmp;

	tmp = nbr;
	i = 0;
	if (d->space == 1 && d->sign == 0 && nbr >= 0)
	{
		if (d->dot == 0 || (d->width > d->tmp_width && d->tmp_width != 0))
			d->width--;
		ft_putcharf(' ');
	}
	if (nbr == 0 && d->width > 0 && d->tmp_width == 0 && d->dot == 1)
	{
		while (d->width-- > 0)
			ft_putcharf(' ');
		return ;
	}
	i = tmp < 0 && d->dot == 0 ? i + 1 : i;
	tmp = tmp < 0 ? -tmp : tmp;
	while (tmp > 0)
	{
		tmp /= 10;
		i++;
	}
	check_flags_d(nbr, d, i);
}
