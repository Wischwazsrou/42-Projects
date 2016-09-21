/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:56:22 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/22 13:37:59 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*check_width(char *str, t_d *d)
{
	int		j;
	int		nbr;
	char	width[16];

	if (d->dot == 0 && d->width == 0)
		d->preci = 1;
	if (d->dot == 1 && d->width != 0)
		d->preci = 0;
	j = 0;
	while (*str >= '0' && *str <= '9')
	{
		width[j] = *str;
		str++;
		j++;
	}
	width[j] = '\0';
	nbr = ft_atoi(width);
	if (d->width != 0)
		d->tmp_width = nbr;
	else
		d->width = nbr;
	str--;
	return (str);
}

static	void	check_attribut(char *str, t_d *d)
{
	d->diese = *str == '#' ? 1 : d->diese;
	d->sign = *str == '+' ? 1 : d->sign;
	d->zero = *str == '0' ? 1 : d->zero;
	d->side = *str == '-' ? 1 : d->side;
	d->space = *str == ' ' ? 1 : d->space;
	d->dot = *str == '.' ? 1 : d->dot;
}

static int		check_valid_conv(char c)
{
	if (c != 'z' && c != 'j' && c != 'l' && c != 'h' && c != 'c' && c != 'C'
		&& c != 'o' && c != 'O' && c != 'x' && c != 'X' && c != 'd' && c != 'D'
		&& c != 's' && c != 's' && c != 'u' && c != 'U' && c != 'p' && c != 'p'
		&& (c < '0' || c > '9') && c != '#' && c != '+' && c != '-' && c != ' '
		&& c != '.')
		return (1);
	return (0);
}

static void		check_length(char *str, t_d *d)
{
	if (*str == 'h' && d->type == 0)
	{
		str++;
		if (*str == 'h')
			d->type = 2;
		else
			d->type = 1;
		str--;
	}
	if (*str == 'l' && d->type == 0)
	{
		str++;
		if (*str == 'l')
			d->type = 4;
		else
			d->type = 3;
		str--;
	}
	d->type = *str == 'j' && d->type == 0 ? 5 : d->type;
	d->type = *str == 'z' && d->type == 0 ? 6 : d->type;
}

char			*check_flags(char *str, t_d *d)
{
	while (*str && *str != 'd' && *str != 's' && *str != 'c' && *str != 'i' &&
				*str != 'D' && *str != 'u' && *str != 'x' && *str != 'X'
				&& *str != 'o' && *str != 'U' && *str != 'O' && *str != 'p'
				&& *str != 'C')
	{
		if (*str == '%')
			print_pourcent(d);
		check_attribut(str, d);
		str = *str >= '0' && *str <= '9' ? check_width(str, d) : str;
		check_length(str, d);
		if ((check_valid_conv(*str) == 1))
			break ;
		str++;
	}
	return (str);
}
