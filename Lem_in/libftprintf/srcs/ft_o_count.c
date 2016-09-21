/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 12:19:01 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/25 12:19:03 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_o_count(unsigned int wc)
{
	int	o_init;

	o_init = 1;
	while (wc >>= 1)
		o_init++;
	return (o_init);
}

int		ft_nbr_octet(wchar_t wc)
{
	if (wc < 0x80)
		return (1);
	else if (wc >= 0x80 && wc < 0x800)
		return (2);
	else if (wc >= 0x800 && wc < 0x10000)
		return (3);
	else
		return (4);
}

void	ft_o_count_bis(wchar_t *str, t_d *d)
{
	wchar_t	*tmp;
	int		octet;

	tmp = str;
	octet = 0;
	while (d->tmp_width > 0)
	{
		octet += ft_nbr_octet(*tmp);
		if (d->tmp_width - octet < 0)
		{
			octet -= ft_nbr_octet(*tmp);
			break ;
		}
		d->tmp_width -= octet;
		tmp++;
	}
	d->tmp_width = octet;
}
