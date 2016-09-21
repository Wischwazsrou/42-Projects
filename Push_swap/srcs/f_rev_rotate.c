/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_rev_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:55:13 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/31 15:55:15 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	f_rra(t_data *d)
{
	int tmp;
	int i;

	tmp = d->stack_a[0];
	i = 0;
	while (i < d->top_a)
	{
		d->stack_a[i] = d->stack_a[i + 1];
		i++;
	}
	d->stack_a[i] = tmp;
	if (d->space == 1)
		ft_putstr("\x1B[31m rra\033[0m");
	else
	{
		ft_putstr("\x1B[31mrra\033[0m");
		d->space = 1;
	}
	d->nbr_mv++;
}

void	f_rrb(t_data *d)
{
	int tmp;
	int i;

	tmp = d->stack_b[0];
	i = 0;
	while (i < d->top_b)
	{
		d->stack_b[i] = d->stack_b[i + 1];
		i++;
	}
	d->stack_b[i] = tmp;
	if (d->space == 1)
		ft_putstr(" rrb");
	else
	{
		ft_putstr("rrb");
		d->space = 1;
	}
	d->nbr_mv++;
}

void	f_rrr(t_data *d)
{
	f_rra(d);
	f_rrb(d);
}
