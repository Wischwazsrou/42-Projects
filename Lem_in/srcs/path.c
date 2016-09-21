/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 16:46:43 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/05/31 17:12:48 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	lst_init(t_path *path, t_room *room, t_data *data)
{
	path->room = ft_strdup(room[data->start].name);
	path->ant = data->ants;
	path->next = NULL;
}

t_path	*lst_new(char *room, t_path *previous)
{
	t_path *path;

	if (!(path = (t_path *)malloc(sizeof(t_path) * 1)))
		return (0);
	path->room = ft_strdup(room);
	path->ant = 0;
	path->next = NULL;
	path->previous = previous;
	return (path);
}

t_path	*lst_add(t_path *path, char *room)
{
	t_path	*begin;

	begin = path;
	while (path->next != NULL)
		path = path->next;
	path->next = lst_new(room, path);
	path = begin;
	return (path);
}

void	lst_delone(t_path *path)
{
	t_path *tmp;

	tmp = path;
	while (tmp->next != NULL)
	{
		path = tmp;
		tmp = tmp->next;
	}
	free(tmp);
	tmp = NULL;
	path->next = NULL;
}
