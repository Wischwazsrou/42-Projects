/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:33:13 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/08/22 21:48:31 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdio.h>

static void		set_connect(char **list_room, t_room *room, t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < data->n_rooms && (ft_strcmp(room[i].name, list_room[0])) != 0)
		i++;
	if (i >= data->n_rooms)
		ft_error(-1);
	while (room[i].connections[j])
		j++;
	room[i].connections = ft_realloc(room[i].connections, 1);
	room[i].connections[j] = ft_strdup_free(list_room[1]);
	room[i].connections[j + 1] = NULL;
	i = 0;
	j = 0;
	while (i < data->n_rooms && (ft_strcmp(room[i].name, list_room[1])) != 0)
		i++;
	if (i >= data->n_rooms)
		ft_error(-1);
	while (room[i].connections[j])
		j++;
	room[i].connections = ft_realloc(room[i].connections, 1);
	room[i].connections[j] = ft_strdup_free(list_room[0]);
	room[i].connections[j + 1] = NULL;
}

int				set_room(char **list_room, t_room *room, int i, char *line)
{
	int count;

	count = 0;
	list_room = ft_strsplit(line, ' ');
	while (room[count].name != NULL)
	{
		if (ft_strcmp(room[count].name, list_room[0]) == 0)
			ft_error(-1);
		count++;
	}
	room[i].name = ft_strdup_free(list_room[0]);
	if (!(room[i].connections = (char **)malloc(sizeof(char *) * 1)))
		return (0);
	room[i].connections[0] = NULL;
	i++;
	return (i);
}

void			parse(t_data *data, t_room *room, char **tab_r)
{
	int			i;
	int			j;
	char		**list_room;

	i = 0;
	j = 0;
	data->ants = ft_atoi(tab_r[0]);
	while (tab_r[i])
	{
		if (ft_strcmp(tab_r[i], "##start") == 0)
			data->start = j;
		else if (ft_strcmp(tab_r[i], "##end") == 0)
			data->end = j;
		else if (ft_strchr(tab_r[i], '-') == 0 &&
					tab_r[i][0] != '#' && ft_strchr(tab_r[i], ' ') != 0)
			j = set_room(list_room, room, j, tab_r[i]);
		else if (ft_strchr(tab_r[i], '-') != 0 && tab_r[i][0] != '#')
		{
			list_room = ft_strsplit(tab_r[i], '-');
			set_connect(list_room, room, data);
		}
		i++;
	}
}

static char		**read_file(char **tab_rooms, int i)
{
	int			ret;
	char		*line;

	i = 0;
	while ((ret = get_next_line(0, &line) == 1))
	{
		if (ft_strcmp(line, "\0") == 0)
			break ;
		tab_rooms[i++] = ft_strdup(line);
		tab_rooms = ft_realloc(tab_rooms, 1);
	}
	tab_rooms[i] = NULL;
	if (tab_rooms[0] == NULL)
		ft_error(-1);
	return (tab_rooms);
}

t_room			*make_map(t_data *data, t_room *room)
{
	int			i;
	char		**tab_rooms;

	i = 0;
	if (!(tab_rooms = (char **)malloc(sizeof(char *) * 1)))
		return (NULL);
	tab_rooms = read_file(tab_rooms, i);
	data->n_rooms = count_rooms(tab_rooms, data);
	if (!(room = (t_room *)malloc(sizeof(t_room) * data->n_rooms)))
		return (NULL);
	if (!(room->map = (char **)malloc(sizeof(char *) * 1)))
		return (NULL);
	while (i < data->n_rooms)
		room[i++].name = NULL;
	i = 0;
	room->map = check_tab_room(tab_rooms);
	parse(data, room, room->map);
	return (room);
}
