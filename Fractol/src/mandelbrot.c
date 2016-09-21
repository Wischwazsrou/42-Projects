/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 15:25:31 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/20 15:25:33 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static	void	mandel_calcul(t_data *data)
{
	data->c_r = data->x / data->zoom + data->x1;
	data->c_i = data->y / data->zoom + data->y1;
	data->z_r = 0;
	data->z_i = 0;
	data->i = 0;
}

void			mandel_process(t_data *data)
{
	data->x = 0;
	while (data->x < data->img_x)
	{
		data->y = 0;
		while (data->y < data->img_y)
		{
			mandel_calcul(data);
			while ((data->z_r * data->z_r + data->z_i * data->z_i)
			< 4 && data->i < data->iter_max)
			{
				data->tmp = data->z_r;
				data->z_r = data->z_r * data->z_r - data->z_i *
					data->z_i + data->c_r;
				data->z_i = 2 * data->z_i * data->tmp + data->c_i;
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

void			mandelbrot(t_data *data)
{
	data->fractal = 1;
	data->x1 = -2.1;
	data->x2 = 2.1;
	data->y1 = -1.2;
	data->y2 = 1.3;
	global_data(data);
	init_mlx(data);
	draw(data);
}
