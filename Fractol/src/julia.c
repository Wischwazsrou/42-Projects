/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 12:19:47 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/02/22 12:19:50 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static	void	julia_calcul(t_data *data)
{
	data->c_r = (data->mouse_x - data->mouse_y) / 100;
	data->c_i = (data->mouse_x - data->mouse_y) / 100;
	data->z_r = data->x / data->zoom + data->x1;
	data->z_i = data->y / data->zoom + data->y1;
	data->i = 0;
}

void			julia_process(t_data *data)
{
	data->x = 0;
	while (data->x < data->img_x)
	{
		data->y = 0;
		while (data->y < data->img_y)
		{
			julia_calcul(data);
			while ((data->z_r * data->z_r + data->z_i * data->z_i)
				< 4 && data->i < data->iter_max)
			{
				data->tmp = data->z_r;
				data->z_r = data->z_r * data->z_r - data->z_i *
					data->z_i + data->c_r;
				data->z_i = 2 * (data->z_i * data->tmp) + data->c_i;
				data->i++;
			}
			if (data->i == data->iter_max)
				img_pixel_put(data, data->x, data->y, data->white);
			else
				img_pixel_put(data, data->x, data->y,
					color(data->i, data->iter_max, data));
			data->y++;
		}
		data->x++;
	}
}

void			julia(t_data *data)
{
	data->mouse_x = 0;
	data->mouse_y = 0;
	data->fractal = 2;
	data->x1 = -1.2;
	data->x2 = 1.5;
	data->y1 = -1.2;
	data->y2 = 1.5;
	data->c_r = 0.285;
	global_data(data);
	init_mlx(data);
	draw(data);
}
