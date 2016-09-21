/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 12:18:21 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/25 12:18:31 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_putcharf(unsigned char c)
{
	write(1, &c, 1);
	g_count++;
}

void			ft_putstrf(const char *str)
{
	while (*str)
	{
		ft_putcharf(*str);
		str++;
	}
}

static void		init_d(t_d *d)
{
	d->type = 0;
	d->sign = 0;
	d->zero = 0;
	d->side = 0;
	d->space = 0;
	d->width = 0;
	d->tmp_width = 0;
	d->dot = 0;
	d->pourcent = 0;
	d->preci = 0;
	d->diese = 0;
}

void			non_valid_conv(char c, t_d *d)
{
	if ((c == '%' && d->pourcent == 1) || c == '\0')
		return ;
	else if (c == '%')
		ft_putcharf('%');
	else if (d->side == 0)
	{
		while (d->width > 1)
		{
			d->zero == 1 ? ft_putcharf('0') : ft_putcharf(' ');
			d->width--;
		}
		ft_putcharf(c);
	}
	else
	{
		ft_putcharf(c);
		while (d->width > 1)
		{
			d->zero == 1 ? ft_putcharf('0') : ft_putcharf(' ');
			d->width--;
		}
	}
}

int				ft_printf(char *ptr, ...)
{
	t_d			d;
	va_list		ap;
	static char	*str;

	g_count = 0;
	va_start(ap, ptr);
	str = ptr;
	while (str && *str)
	{
		if (*str == '%')
		{
			init_d(&d);
			str++;
			if (*str == '\0')
				break ;
			str = check_flags(str, &d);
			check_convert(str, &d, ap);
			str++;
		}
		else
			ft_putcharf(*str++);
	}
	va_end(ap);
	return (g_count);
}
