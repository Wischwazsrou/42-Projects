/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 19:21:19 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/24 21:28:04 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_o_str_count(const wchar_t *s)
{
	int	octet;

	octet = 0;
	while (*s)
		octet += ft_nbr_octet(*s++);
	return (octet);
}

static void		print_bis(wchar_t *str, t_d *d, int i)
{
	if (d->side == 0)
		while (*str)
		{
			if (d->width > i && d->zero == 0)
				ft_putcharf(' ');
			else if (d->zero == 1 && d->width > i)
				ft_putcharf('0');
			else
				ft_putwchar(*str++);
			d->width--;
		}
	else
	{
		if (d->dot == 1 && d->preci == 0 && d->tmp_width == 0)
			d->tmp_width = d->width;
		while (*str && d->tmp_width-- > 0)
		{
			d->width -= ft_nbr_octet(*str);
			ft_putwchar(*str++);
		}
		while (d->width-- > 0)
			d->zero == 0 ? ft_putcharf(' ') : ft_putcharf('0');
	}
}

static void		print(wchar_t *str, t_d *d, int i)
{
	if (d->dot == 1 && d->side == 0)
	{
		if (d->tmp_width > 0)
		{
			ft_o_count_bis(str, d);
			while (d->width > d->tmp_width)
			{
				ft_putcharf(' ');
				d->width--;
			}
			d->tmp_width = 0;
		}
		while (*str && d->width >= ft_nbr_octet(*str))
		{
			d->width -= ft_nbr_octet(*str);
			ft_putwchar(*str++);
		}
	}
	else
		print_bis(str, d, i);
}

static void		check_side(wchar_t *str, t_d *d, int i)
{
	if (d->preci == 1)
		while (d->width-- > 0)
			d->zero == 0 ? ft_putcharf(' ') : ft_putcharf('0');
	else if (d->tmp_width > d->width && i > d->width)
		while (*str && d->tmp_width > 0)
		{
			ft_putwchar(*str);
			d->tmp_width -= ft_nbr_octet(*str);
			str++;
		}
	else
		print(str, d, i);
}

void			ft_putwstr(wchar_t *str, t_d *d)
{
	int		i;

	if (d->dot == 0 && d->side == 1 && d->tmp_width == 0)
		d->tmp_width = d->width;
	if (d->dot == 0)
		d->preci = 0;
	i = 0;
	if (str == NULL)
	{
		if (d->dot == 0)
			ft_putstrf("(null)");
		if (d->dot == 1)
			while (d->width-- > 0)
				ft_putcharf('0');
		return ;
	}
	i = ft_o_str_count(str);
	check_side(str, d, i);
}
