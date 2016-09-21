/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 17:44:24 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/08/22 21:29:23 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	count_solutions(t_room *room, t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (room[data->start].connections[i])
		i++;
	while (room[data->end].connections[j])
		j++;
	if (j < i)
		data->max_sol = j;
	else
		data->max_sol = i;
}

int		count_rooms(char **tab_rooms, t_data *data)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (tab_rooms[i])
	{
		if (ft_strchr(tab_rooms[i], '-') == 0 && tab_rooms[i][0] != '#')
			j++;
		i++;
	}
	data->min_move = j / 2;
	return (j);
}

int		count_move(t_path *path)
{
	int i;

	i = 0;
	while (path->next != NULL)
	{
		i++;
		path = path->next;
	}
	return (i);
}
