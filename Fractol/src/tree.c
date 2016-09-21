/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 15:23:29 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/20 15:25:38 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	draw_tree(t_data *data, int x, int y, int angle)
{
	int x1;
	int y1;
	int depth_local;

	depth_local = data->dep;
	if (data->dep >= 0)
	{
		x1 = x + cos(angle * (3.14159 / 180)) * data->dep * 5;
		y1 = y + sin(angle * (3.14159 / 180)) * data->dep * 5;
		data->white[2] = 153 - (data->depth_max - data->dep) * 10;
		data->white[1] = 102 + (data->depth_max - data->dep) * 2;
		data->white[0] = 51;
		data->x1 = x1;
		data->y1 = y1;
		draw_line(data, x, y);
		data->dep -= 1;
		draw_tree(data, x1, y1, angle + 20);
		data->dep = depth_local - 1;
		draw_tree(data, x1, y1, angle - 20);
	}
}

void		tree_process(t_data *data)
{
	data->depth_max = data->dep;
	draw_tree(data, (int)data->x2, (int)data->y2, data->angle);
	data->dep = data->depth_max;
}

void		tree(t_data *data)
{
	data->fractal = 4;
	data->x2 = 250;
	data->y2 = 500;
	data->angle = -90;
	data->dep = 9;
	global_data(data);
	init_mlx(data);
	draw(data);
}
