/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 15:56:21 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/08/22 21:33:03 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_room(t_path **solution, t_data *data, int i)
{
	if (data->color == 1)
	{
		if (data->c % 3 == 3 || data->c % 3 == 0)
		{
			ft_printf("\033[1;32mL%d-\033[0m", i);
			ft_putstr(solution[data->c]->room);
			ft_putchar(' ');
		}
		else if (data->c % 3 == 1)
		{
			ft_printf("\033[1;33mL%d-\033[0m", i);
			ft_putstr(solution[data->c]->room);
			ft_putchar(' ');
		}
		else
		{
			ft_printf("\033[1;31mL%d-\033[0m", i);
			ft_putstr(solution[data->c]->room);
			ft_putchar(' ');
		}
	}
	else
		ft_printf("L%d-%s ", i, solution[data->c]->room);
}

void	print_map(t_room *room)
{
	int		i;

	i = 0;
	while (room->map[i])
	{
		ft_printf("%s\n", room->map[i]);
		i++;
	}
	ft_putchar('\n');
}

void	print_ter(t_path **solution, t_data *d, int n, int i)
{
	int j;

	j = n;
	d->flag = 0;
	while (solution[d->c]->next != NULL && j-- > 0)
		solution[d->c] = solution[d->c]->next;
	j = n >= d->moves[d->c] ? d->moves[d->c] : n;
	n = n <= d->moves[d->c] ? 1 + d->c : i - 2;
	if (d->solution != 1)
		n = n <= d->moves[d->c] ? 1 + d->c : i - 4 + d->c + (d->solution - 2);
	if (d->c != 0)
		n = n <= d->moves[d->c] ? 1 + d->c : i -
			(((d->moves[d->c] - 1) * d->solution) - d->c);
	while (j-- > 0)
	{
		if (n <= d->ants)
		{
			print_room(solution, d, n);
			solution[d->c] = solution[d->c]->previous;
			n += d->solution;
			d->flag = 1;
		}
	}
}

t_path	**print_bis(t_path **solution, t_data *data, int n_sol, t_path **begin)
{
	begin[data->solution] = NULL;
	if (!(data->moves = (int *)malloc(sizeof(int) * n_sol)))
		return (NULL);
	while (--n_sol > 0)
		begin[n_sol - 1] = solution[n_sol - 1];
	while (data->c < data->solution)
	{
		data->moves[data->c] = count_move(solution[data->c]);
		data->c++;
	}
	data->max_move = data->c - 1;
	data->diff = data->moves[data->c - 1] - data->moves[0];
	return (begin);
}

t_path	**print(t_path **solution, t_data *data, t_room *room)
{
	int		i;
	int		n;
	int		n_sol;
	t_path	**begin;

	i = 1;
	n = 1;
	print_map(room);
	if (!(begin = (t_path **)malloc(sizeof(t_path *) * data->solution + 1)))
		return (NULL);
	begin = print_bis(solution, data, data->solution + 1, begin);
	while (i <= data->ants + 2 * data->solution + data->diff * data->moves[0])
	{
		n_sol = data->solution + 1;
		data->c = -1;
		while (--n_sol > 0)
			solution[n_sol - 1] = begin[n_sol - 1];
		while (++data->c < data->solution)
			print_ter(solution, data, n, i);
		data->flag == 1 ? ft_putchar('\n') : 0;
		data->flag == 1 ? data->coups++ : 0;
		i += data->solution;
		n++;
	}
	return (begin);
}
