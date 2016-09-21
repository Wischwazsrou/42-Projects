/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 12:13:05 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/02/10 12:13:09 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_error(int i)
{
	if (i == -1)
	{
		ft_putendl("error");
		exit(1);
	}
}

void	mapping(t_data *data, t_map *map)
{
	int ret;

	while ((ret = get_next_line(data->fd, &data->line) == 1))
	{
		data->table = ft_strsplit(data->line, ' ');
		data->x = -1;
		while (data->table[++data->x] != NULL)
		{
			map->next = init_map();
			map->z = ft_atoi(data->table[data->x]);
			if (map->z > data->z_max)
				data->z_max = map->z;
			map->x = data->x;
			map->y = data->y;
			map = map->next;
		}
		data->y++;
	}
	if (ret != 0)
		ft_error(-1);
}

int		how_does_it_look_like(char *file, t_data *data)
{
	t_map	*map;

	data->z_max = 0;
	if ((map = (t_map *)malloc(sizeof(*map))) == NULL)
		ft_error(-1);
	data->first = map;
	if ((data->fd = open(file, O_RDWR)) == -1)
		ft_error(-1);
	data->y = 0;
	mapping(data, map);
	map = data->first;
	while (map->next != NULL)
	{
		map->z_max = data->z_max;
		map = map->next;
	}
	data->lenght_line = data->x;
	if (close(data->fd) == -1)
		ft_error(-1);
	return (0);
}
