/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_uintmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 20:51:14 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/22 13:12:26 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	print(char *convert_n, char c, t_d *d, int i)
{
	int tmp;

	tmp = d->tmp_width;
	if ((d->diese == 1 && convert_n[0] != '0' && convert_n[0] != '\0')
			|| (c == 'p' && d->zero == 0))
	{
		c == 'X' ? ft_putstrf("0X") : ft_putstrf("0x");
		d->width = c == 'p' ? d->width : d->width - 2;
		d->diese = 0;
	}
	while (d->tmp_width > i)
	{
		ft_putcharf('0');
		d->tmp_width--;
		if (d->width > d->tmp_width && tmp > i)
			d->width--;
	}
	d->tmp_width = tmp != d->tmp_width ? tmp - d->tmp_width : d->tmp_width;
	ft_putstrf(convert_n);
	free(convert_n);
}

static	char	*convert(uint64_t nbr, char *convert_n, char c, t_d *d)
{
	uint64_t	value;
	int			i;

	i = 0;
	if (nbr == 0)
	{
		convert_n[i] = d->dot == 0 ? '0' : '\0';
		i++;
	}
	while (nbr > 0)
	{
		value = nbr % 16;
		if (value > 9)
			convert_n[i] = c == 'X' ? value - 10 + 'A' : value - 10 + 'a';
		else
			convert_n[i] = value + 48;
		nbr = nbr / 16;
		i++;
	}
	convert_n[i] = '\0';
	convert_n = ft_strrev(convert_n);
	return (convert_n);
}

static	void	check_side(char *convert_n, t_d *d, int i, char c)
{
	if (d->side == 0)
	{
		d->width = d->diese == 1 ? d->width - 2 : d->width;
		while (d->width > i && d->width-- > d->tmp_width)
		{
			if ((convert_n[0] == '\0' && c != 'p') || d->preci == 1)
				ft_putcharf(' ');
			else if (d->zero == 1 || (d->tmp_width == 0 && d->dot == 1))
				ft_putcharf('0');
			else
				ft_putcharf(' ');
		}
		print(convert_n, c, d, i);
		return ;
	}
	print(convert_n, c, d, i);
	if (d->width < d->tmp_width)
		return ;
	if (d->tmp_width > 0 && d->tmp_width > i)
		while (d->tmp_width-- > 0)
			ft_putcharf(' ');
	else
		while (d->width-- > i)
			d->tmp_width == 0 && d->preci == 0 && d->dot == 1 ?
				ft_putcharf('0') : ft_putcharf(' ');
}

static	int		check_flags_x(char c, t_d *d, int i)
{
	if (c == 'p')
	{
		if (d->zero == 1 || d->tmp_width > d->width ||
				(d->dot == 1 && d->tmp_width == 0))
		{
			ft_putstrf("0x");
			d->zero = 1;
			i = d->dot == 1 ? i - 2 : i;
		}
		i += 2;
	}
	if (d->width > 0 && ((d->diese == 1 && d->zero == 1) ||
			(d->diese == 1 && d->dot == 1)) && d->preci == 0)
	{
		if (d->dot == 1 && d->tmp_width > 0 && d->width > d->tmp_width
				&& d->side == 0)
			return (i);
		c == 'X' ? ft_putstrf("0X") : ft_putstrf("0x");
		d->diese = 0;
		d->width = d->dot == 1 && d->tmp_width == 0 ? d->width : d->width - 2;
	}
	return (i);
}

void			print_x_uintmax(uint64_t nbr, char c, t_d *d)
{
	char	*convert_n;
	char	*tmp;
	int		i;

	i = 0;
	if (d->side == 1 && d->dot == 1 && d->preci == 0 && d->tmp_width == 0)
		d->side = 0;
	d->preci = d->dot == 0 && d->preci == 1 ? 0 : d->preci;
	if (nbr == 0 && d->dot == 1 && c != 'p' && d->preci == 0 && d->zero == 0)
		return ;
	if (!(convert_n = (char *)malloc(sizeof(char) * 16)))
		return ;
	convert_n = convert(nbr, convert_n, c, d);
	tmp = convert_n;
	while (*tmp)
	{
		i++;
		tmp++;
	}
	i = check_flags_x(c, d, i);
	check_side(convert_n, d, i, c);
}
