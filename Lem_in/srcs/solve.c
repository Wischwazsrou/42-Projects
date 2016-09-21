/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 16:19:24 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/06/01 20:02:04 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_path	**algo(t_room *room, t_data *data, t_path **solution)
{
	t_path *path;

	while (data->solution < data->max_sol)
	{
		data->current_solution = 0;
		if (!(path = (t_path *)malloc(sizeof(t_path) * 1)))
			return (0);
		lst_init(path, room, data);
		data->min_move = data->solution == 1 ? data->move - 1 : data->min_move;
		data->move = 1;
		data->max_move = 1;
		solve(room, data, data->start, path);
		if (data->current_solution == 0)
			break ;
		solution[data->solution - 1] = lst_new(room[data->start].name, path);
		while (data->shit[data->count])
		{
			path = lst_add(solution[data->solution - 1],
				data->shit[data->count]);
			data->count++;
		}
		path = lst_add(solution[data->solution - 1], room[data->end].name);
	}
	solution[data->solution] = NULL;
	return (solution);
}

void	put_in_lst(t_room *room, t_data *data, t_path *path, int i)
{
	int k;

	k = 0;
	path = lst_add(path, room[i].name);
	data->shit = ft_realloc(data->shit, data->max_move);
	while (data->shit[k])
		k++;
	while (path->next != NULL)
	{
		if (ft_strcmp(path->room, room[data->start].name) != 0)
		{
			data->shit[k] = path->room;
			k++;
		}
		path = path->next;
	}
	data->shit[k] = NULL;
}

int		find_solution(t_room *room, t_data *data, t_path *path)
{
	int connect;

	connect = check_connection(room, data->connection);
	if (data->move > 1)
	{
		data->move--;
		path = lst_add(path, data->connection);
		if ((solve(room, data, connect, path)) == 1)
		{
			data->solution++;
			data->current_solution++;
			lst_delone(path);
		}
		else
			lst_delone(path);
		data->move++;
	}
	else if (connect == data->end)
	{
		put_in_lst(room, data, path, connect);
		return (1);
	}
	return (0);
}

int		solve(t_room *room, t_data *data, int i, t_path *path)
{
	int j;

	j = 0;
	if (data->move > (data->min_move * 2) + 1)
		return (0);
	while (room[i].connections[j])
	{
		if (data->current_solution != 0)
			return (0);
		if (check_room(room[i].connections[j], data, path) == 0)
		{
			data->connection = ft_strdup(room[i].connections[j]);
			if (find_solution(room, data, path) == 1)
				return (1);
		}
		j++;
	}
	if (data->solution != data->max_sol && i == data->start &&
			data->move == data->max_move)
	{
		data->move++;
		data->max_move = data->move;
		solve(room, data, i, path);
	}
	return (0);
}
