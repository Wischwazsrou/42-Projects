/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:49:05 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/06/01 19:10:13 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_connection(t_room *room, char *connection)
{
	int i;

	i = 0;
	while ((ft_strcmp(room[i].name, connection)) != 0)
		i++;
	return (i);
}

int		check_room(char *room, t_data *data, t_path *path)
{
	int i;

	i = 0;
	while (data->shit[i])
	{
		if (ft_strcmp(room, data->shit[i]) == 0)
			return (1);
		i++;
	}
	while (path->next != NULL)
	{
		if (ft_strcmp(room, path->room) != 0)
			return (0);
		path = path->next;
	}
	if (path->next == NULL && ft_strcmp(room, path->room) == 0)
		return (1);
	return (0);
}
