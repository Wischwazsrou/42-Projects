/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_for_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:54:59 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/31 15:55:01 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		pb_smallest(t_data *d, int pos, int min)
{
	if (pos >= d->top_a / 2)
		while (d->stack_a[d->top_a] != min)
			f_ra(d);
	else
		while (d->stack_a[d->top_a] != min)
			f_rra(d);
	f_pb(d);
}

static void	swap(t_data *d, int pos)
{
	int j;

	j = d->top_a - pos + 1;
	if (pos >= d->top_a / 2)
		while (j-- > 0)
			f_rra(d);
	else
		while (d->stack_a[d->top_a] < d->stack_a[d->top_a - 1])
			f_ra(d);
	f_sa(d);
	if (d->stack_a[0] > d->stack_a[d->top_a])
		swap(d, d->top_a);
	j = d->top_a - pos + 1;
	if (pos >= d->top_a / 2)
		while (j-- > 0)
			f_ra(d);
	else
		while (j++ <= d->top_a)
			f_rra(d);
}

int			one_swap(t_data *d)
{
	int i;

	i = 0;
	if (d->stack_a[d->top_a] > d->stack_a[d->top_a - 1])
	{
		f_sa(d);
		ft_putchar('\n');
		return (0);
	}
	if (d->stack_a[d->top_a] > d->stack_a[0])
	{
		f_rra(d);
		ft_putchar('\n');
		return (0);
	}
	while (d->stack_a[d->top_a - i] < d->stack_a[d->top_a - i - 1])
		i++;
	swap(d, i);
	ft_putchar('\n');
	return (0);
}

int			solve_three(t_data *d)
{
	if (d->stack_a[2] < d->stack_a[1] &&
			d->stack_a[1] > d->stack_a[0] && d->stack_a[2] < d->stack_a[0])
		f_ra(d);
	if (d->stack_a[2] > d->stack_a[1] && d->stack_a[1] > d->stack_a[0])
		f_sa(d);
	if (d->stack_a[2] > d->stack_a[1] &&
			d->stack_a[1] < d->stack_a[0] && d->stack_a[2] > d->stack_a[0])
		f_ra(d);
	if (d->stack_a[2] < d->stack_a[1] && d->stack_a[1] > d->stack_a[0])
		f_rra(d);
	if (d->stack_a[2] > d->stack_a[1] && d->stack_a[1] < d->stack_a[0])
		f_sa(d);
	ft_putchar('\n');
	return (0);
}
