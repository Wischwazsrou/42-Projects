/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:29:38 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/27 19:49:18 by vklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			signed_convert(char *str, t_d *d, va_list ap)
{
	if (*str == 's')
		char_e(va_arg(ap, char *), *str, d);
	else if (*str == 'd' || *str == 'c' || *str == 'i')
	{
		d->type == 0 || d->type == 1 || d->type == 2 ?
			intmax(va_arg(ap, int), *str, d) : 0;
		d->type == 3 ? intmax(va_arg(ap, long), *str, d) : 0;
		d->type == 4 ? intmax(va_arg(ap, long long), *str, d) : 0;
		d->type == 5 || d->type == 6 ?
			intmax(va_arg(ap, intmax_t), *str, d) : 0;
	}
	else if (*str == 'D')
		intmax(va_arg(ap, long), *str, d);
}

static void			unsigned_convert(char *str, t_d *d, va_list ap)
{
	if (*str == 'C' || *str == 'S')
	{
		if (*str == 'C')
			print_c_upp(va_arg(ap, wchar_t), d);
		if (*str == 'S')
			ft_putwstr(va_arg(ap, wchar_t *), d);
	}
	else if (*str == 'u' || *str == 'x' || *str == 'X' || *str == 'o')
	{
		d->type == 0 || d->type == 1 || d->type == 2 ?
			u_intmax(va_arg(ap, unsigned int), *str, d) : 0;
		d->type == 3 || d->type == 6 ?
			u_intmax(va_arg(ap, unsigned long), *str, d) : 0;
		d->type == 4 ? u_intmax(va_arg(ap, unsigned long long), *str, d) : 0;
		d->type == 5 ? u_intmax(va_arg(ap, uintmax_t), *str, d) : 0;
	}
	else if (*str == 'U' || *str == 'O' || *str == 'p')
		u_intmax(va_arg(ap, unsigned long), *str, d);
}

void				check_convert(char *str, t_d *d, va_list ap)
{
	if (*str == 'c' && d->type == 3)
		print_c_upp(va_arg(ap, wchar_t), d);
	else if (*str == 's' && d->type == 3)
		ft_putwstr(va_arg(ap, wchar_t *), d);
	else if (*str == 's' || *str == 'c' || *str == 'i' || *str == 'd' ||
		*str == 'D')
		signed_convert(str, d, ap);
	else if (*str == 'S' || *str == 'C' || *str == 'u' || *str == 'U' ||
		*str == 'x' || *str == 'X' || *str == 'o' || *str == 'O' || *str == 'p')
		unsigned_convert(str, d, ap);
	else
		non_valid_conv(*str, d);
}
