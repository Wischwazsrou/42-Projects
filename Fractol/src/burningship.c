/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 12:19:55 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/02/22 12:19:56 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static	void	burning_calcul(t_data *data)
{
	data->c_r = data->x / data->zoom + data->x1;
	data->c_i = data->y / data->zoom + data->y1;
	data->z_r = 0;
	data->z_i = 0;
	data->i = 0;
}

void			burning_process(t_data *data)
{
	data->x = 0;
	while (data->x < data->img_x)
	{
		data->y = 0;
		while (data->y < data->img_y)
		{
			burning_calcul(data);
			while ((data->z_r * data->z_r + data->z_i *
				data->z_i) < 4 && data->i < data->iter_max)
			{
				data->tmp = data->z_r;
				data->z_r = data->z_r * data->z_r - data->z_i *
					data->z_i + data->c_r;
				data->z_i = 2 * fabs(data->z_i * data->tmp) + data->c_i;
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

void			burningship(t_data *data)
{
	data->fractal = 3;
	data->x1 = -2.1;
	data->x2 = 0.6;
	data->y1 = -1.2;
	data->y2 = 2;
	global_data(data);
	init_mlx(data);
	draw(data);
}
