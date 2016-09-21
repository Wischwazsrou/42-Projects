/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o_uintmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 12:23:31 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/17 12:23:32 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	print(char *convert_n, t_d *d, int i)
{
	int tmp;

	tmp = d->tmp_width;
	if (d->diese == 1 && convert_n[0] != '0' && convert_n[0] != '\0')
	{
		ft_putcharf('0');
		d->width--;
		d->diese = 0;
	}
	while (d->tmp_width > i)
	{
		ft_putcharf('0');
		i++;
	}
	d->tmp_width = tmp != d->tmp_width ? tmp - d->tmp_width : d->tmp_width;
	ft_putstrf(convert_n);
	free(convert_n);
}

static	char	*convert(uint64_t nbr, char *convert_n, t_d *d)
{
	uint64_t	value;
	int			i;

	i = 0;
	if (nbr == 0)
	{
		convert_n[i] = d->diese == 1 || d->dot == 0 ? '0' : '\0';
		i++;
	}
	while (nbr > 0)
	{
		value = nbr % 8;
		nbr = nbr / 8;
		convert_n[i] = value + 48;
		i++;
	}
	convert_n[i] = '\0';
	convert_n = ft_strrev(convert_n);
	return (convert_n);
}

static	void	check_side(char *convert_n, t_d *d, int i)
{
	if (d->side == 0)
	{
		i = d->diese == 1 ? i + 1 : i;
		while (d->width > i && d->width-- > d->tmp_width)
		{
			if (d->preci == 1 || convert_n[0] == '\0')
				ft_putcharf(' ');
			else if (d->zero == 1 || (d->tmp_width == 0 && d->dot == 1))
				ft_putcharf('0');
			else
				ft_putcharf(' ');
		}
	}
	print(convert_n, d, i);
	if (d->side == 1)
	{
		if (d->width < d->tmp_width)
			return ;
		if (d->tmp_width > i)
			while (d->tmp_width-- > 0)
				ft_putcharf(' ');
		else
			while (d->width-- > i)
				ft_putcharf(' ');
	}
}

static	int		check_flags_o(t_d *d, int i)
{
	if (d->width > 0 && ((d->diese == 1 && d->zero == 1) ||
			(d->diese == 1 && d->dot == 1)) && d->preci == 0 && d->side == 1)
	{
		ft_putcharf('0');
		d->diese = 0;
		i++;
	}
	return (i);
}

void			print_o_uintmax(uint64_t nbr, t_d *d)
{
	char	*convert_n;
	char	*tmp;
	int		i;

	i = 0;
	if (d->side == 1 && d->dot == 1 && d->preci == 0 && d->tmp_width == 0)
		d->side = 0;
	d->preci = d->dot == 0 && d->preci == 1 ? 0 : d->preci;
	if (nbr == 0 && d->dot == 1 && d->preci == 0 && d->diese == 0
		&& d->zero == 0)
		return ;
	if (!(convert_n = (char *)malloc(sizeof(char) * 32)))
		return ;
	convert_n = convert(nbr, convert_n, d);
	tmp = convert_n;
	while (*tmp)
	{
		i++;
		tmp++;
	}
	i = check_flags_o(d, i);
	check_side(convert_n, d, i);
}
