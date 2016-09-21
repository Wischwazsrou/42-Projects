/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:56:10 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/10 15:56:14 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			char_e(char *str, char c, t_d *d)
{
	if (c == 's')
		print_s_low(str, d);
}

void			intmax(int64_t nbr, char c, t_d *d)
{
	if (nbr == 0 && d->dot == 1 && c != 'c' && d->width == 0)
		return ;
	else if (d->type == 2 && c != 'D' && c != 'c')
	{
		if (c == 'd' || c == 'i')
			print_d_intmax((signed char)nbr, d);
	}
	else if (d->type == 1 && c != 'D' && c != 'c')
	{
		if (c == 'd' || c == 'i')
			print_d_intmax((short)nbr, d);
	}
	else
	{
		if (c == 'd' || c == 'i' || c == 'D')
			print_d_intmax(nbr, d);
		if (c == 'c')
			print_c_low((unsigned char)nbr, d);
	}
}

static	void	u_intmax_bis(uint64_t nbr, char c, t_d *d)
{
	if (c == 'u' || c == 'U')
		print_u_uintmax(nbr, d);
	if (c == 'x' || c == 'X' || c == 'p')
		print_x_uintmax(nbr, c, d);
	if (c == 'o' || c == 'O')
		print_o_uintmax(nbr, d);
}

void			u_intmax(uint64_t nbr, char c, t_d *d)
{
	if (nbr == 0 && d->dot == 1 && c == 'u')
		return ;
	if ((d->type != 1 && d->type != 2)
			|| c == 'O' || c == 'U' || c == 'p')
		u_intmax_bis(nbr, c, d);
	if (d->type == 2 && c != 'U' && c != 'p' && c != 'O')
	{
		if (c == 'u')
			print_u_uintmax((unsigned char)nbr, d);
		if (c == 'x' || c == 'X')
			print_x_uintmax((unsigned char)nbr, c, d);
		if (c == 'o')
			print_o_uintmax((unsigned char)nbr, d);
	}
	else if (d->type == 1 && c != 'U' && c != 'p' && c != 'O')
	{
		if (c == 'u')
			print_u_uintmax((unsigned short)nbr, d);
		if (c == 'x' || c == 'X')
			print_x_uintmax((unsigned short)nbr, c, d);
		if (c == 'o')
			print_o_uintmax((unsigned short)nbr, d);
	}
}
