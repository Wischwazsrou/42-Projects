/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:26:20 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/06/17 19:38:57 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_error(int i)
{
	if (i == -1)
		ft_putendl("ERROR");
	if (i == 2)
		ft_putendl("No solution found.");
	exit(1);
}

void	init_data(t_data *data)
{
	data->solution = 0;
	data->max_sol = 0;
	data->move = 1;
	data->ants = 0;
	data->count = 0;
	data->start = 0;
	data->end = 0;
	data->c = 0;
	data->max_move = 1;
	data->diff = 0;
	data->coups = 0;
	data->show_moves = 0;
	data->show_coups = 0;
	data->show_path = 0;
	data->color = 0;
	data->flag = 0;
}

int		controller(t_data *data)
{
	t_room	*room;
	t_path	**solution;

	if (!(data->shit = (char **)malloc(sizeof(char *) * 1)))
		return (0);
	data->shit[0] = NULL;
	if (!(room = (t_room *)malloc(sizeof(t_room) * 1)))
		return (0);
	room = make_map(data, room);
	count_solutions(room, data);
	if (data->max_sol == 0)
		ft_error(2);
	if (!(solution = (t_path **)malloc(sizeof(t_path *) * data->max_sol + 1)))
		return (0);
	solution = algo(room, data, solution);
	if (data->solution == 0)
		ft_error(2);
	solution = print(solution, data, room);
	print_bonus(solution, data);
	free(room);
	free(solution);
	return (0);
}

int		main(int ac, char **av)
{
	t_data *data;

	if (!(data = (t_data *)malloc(sizeof(t_data) * 1)))
		return (0);
	init_data(data);
	print_options();
	if (ac == 1)
		controller(data);
	else
	{
		check_bonus(ac, av, data);
		controller(data);
	}
	free(data);
}
