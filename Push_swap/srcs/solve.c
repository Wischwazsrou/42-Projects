/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:55:50 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/31 15:55:51 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			opti_solve(t_data *d)
{
	int top;
	int count;
	int max;

	top = d->top_a;
	count = 0;
	max = d->stack_a[d->top_a];
	while (top >= 0)
	{
		if (d->stack_a[top] > max)
			max = d->stack_a[top];
		if (d->stack_a[top] < max)
			count++;
		top--;
	}
	if (d->top_a == 2 && count > 0)
		return (solve_three(d));
	if (count == 1)
		return (one_swap(d));
	if (count == 0)
		return (0);
	return (1);
}

void		brute_solve(t_data *d)
{
	int min;
	int ptr;
	int pos;

	ptr = d->top_a;
	min = d->stack_a[ptr];
	pos = ptr;
	while (d->top_a > 0)
	{
		if (d->stack_a[ptr] < min)
		{
			min = d->stack_a[ptr];
			pos = ptr;
		}
		if (ptr == 0)
		{
			pb_smallest(d, pos, min);
			ptr = d->top_a + 1;
			min = d->stack_a[ptr - 1];
		}
		ptr--;
	}
	while (d->top_b >= 0)
		f_pa(d);
	ft_putchar('\n');
}
