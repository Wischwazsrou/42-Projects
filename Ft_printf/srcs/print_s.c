/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:50:50 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/18 12:52:08 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	print_s_low_bis(char *str, t_d *d, int i)
{
	if (d->dot == 1)
	{
		if (d->tmp_width > 0)
		{
			while (d->width > d->tmp_width || d->width > i)
			{
				ft_putcharf(' ');
				d->width--;
			}
			d->tmp_width = 0;
		}
		while (*str && d->width-- > 0)
			ft_putwchar(*str++);
	}
	else
		while (*str)
		{
			if (d->width-- > i)
				d->zero == 1 ? ft_putcharf('0') : ft_putcharf(' ');
			else
				ft_putwchar(*str++);
		}
}

static	void	check_side_bis(char *str, t_d *d, int i)
{
	if (d->tmp_width > d->width && i > d->width)
		while (*str && d->tmp_width > 0)
		{
			ft_putcharf(*str);
			d->tmp_width--;
			str++;
		}
	else if (*str == '\0' && d->dot == 0)
		while (d->width-- > 0)
			ft_putcharf(' ');
	else
		print_s_low_bis(str, d, i);
}

static	void	check_side(char *str, t_d *d, int i)
{
	int tmp;

	tmp = d->tmp_width == 0 ? d->width : d->tmp_width;
	if (d->preci == 1)
		while (d->width-- > 0)
			ft_putcharf(' ');
	else if (d->side == 1)
	{
		if (d->dot == 0)
			while (d->width-- > 0)
				*str ? ft_putcharf(*str++) : ft_putcharf(' ');
		else
		{
			while (*str && tmp-- > 0 && d->width--)
				ft_putcharf(*str++);
			if (d->dot == 1 && d->tmp_width == 0 && d->preci == 0)
				return ;
			while (d->width-- > 0)
				ft_putcharf(' ');
		}
	}
	else
		check_side_bis(str, d, i);
}

void			print_s_low(char *str, t_d *d)
{
	char	*tmp;
	int		i;

	if (d->dot == 0)
		d->preci = 0;
	i = 0;
	tmp = str;
	if (str == NULL)
	{
		if (d->dot == 0)
			ft_putstrf("(null)");
		if (d->dot == 1)
			while (d->width-- > 0)
				ft_putcharf('0');
		return ;
	}
	while (*tmp)
	{
		i++;
		tmp++;
	}
	check_side(str, d, i);
}
