/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:56:02 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/31 15:56:03 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	f_ra(t_data *d)
{
	int tmp;
	int i;

	i = d->top_a;
	tmp = d->stack_a[d->top_a];
	while (i >= 0)
	{
		d->stack_a[i] = d->stack_a[i - 1];
		i--;
	}
	d->stack_a[0] = tmp;
	if (d->space == 1)
		ft_putstr("\x1B[35m ra\033[0m");
	else
	{
		ft_putstr("\x1B[35mra\033[0m");
		d->space = 1;
	}
	d->nbr_mv++;
}

void	f_rb(t_data *d)
{
	int tmp;
	int i;

	i = d->top_b;
	tmp = d->stack_b[d->top_b];
	while (i >= 0)
	{
		d->stack_b[i] = d->stack_b[i - 1];
		i--;
	}
	d->stack_b[0] = tmp;
	if (d->space == 1)
		ft_putstr(" rb");
	else
	{
		ft_putstr("rb");
		d->space = 1;
	}
	d->nbr_mv++;
}

void	ff_rr(t_data *d)
{
	f_ra(d);
	f_rb(d);
}
