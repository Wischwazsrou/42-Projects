/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 12:13:31 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/02/10 12:13:40 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	init(t_map *map, t_gps *gps, t_data *data)
{
	gps->x_a = data->origine_x + (map->x * data->scale) - map->z * data->h;
	gps->y_a = data->origine_y + (map->y * data->scale) - map->z * data->h;
	gps->x_a = gps->x_a - gps->y_a;
	gps->y_a = (gps->x_a + gps->y_a) / 2 + map->y * data->scale;
}

static void	convertb(t_map *map, t_gps *gps, t_data *data)
{
	gps->x_b = data->origine_x + (map->next->x * data->scale) -
		map->next->z * data->h;
	gps->y_b = data->origine_y + (map->next->y * data->scale) -
		map->next->z * data->h;
	gps->x_b = gps->x_b - gps->y_b;
	gps->y_b = (gps->x_b + gps->y_b) / 2 + map->y * data->scale;
}

static void	converta(t_map *under, t_gps *gps, t_data *data)
{
	gps->x_b = data->origine_x + (under->x * data->scale) -
		under->z * data->h;
	gps->y_b = data->origine_y + (under->y * data->scale) -
		under->z * data->h;
	gps->x_b = gps->x_b - gps->y_b;
	gps->y_b = (gps->x_b + gps->y_b) / 2 + under->y * data->scale;
}

void		convert_to_iso(t_map *under, t_map *map, t_gps *gps, t_data *data)
{
	while (map->next != NULL)
	{
		init(map, gps, data);
		if (map->y == map->next->y)
		{
			convertb(map, gps, data);
			draw_me_one_line(gps, data, map);
		}
		if (under->next != NULL)
		{
			converta(under, gps, data);
			draw_me_one_line(gps, data, map);
			under = under->next;
		}
		map = map->next;
	}
}

void		take_your_fucking_map(t_gps *gps)
{
	int		i;
	t_map	*under;
	t_map	*map;
	t_data	*data;

	data = gps->data;
	map = data->first;
	under = map;
	i = data->lenght_line + 1;
	while (--i > 0)
		under = under->next;
	convert_to_iso(under, map, gps, data);
}
