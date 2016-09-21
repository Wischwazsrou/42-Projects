/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 15:24:10 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/20 15:24:12 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	global_data(t_data *data)
{
	if (!(data->white = (int *)malloc(sizeof(int) * 4)))
		ft_error(-1);
	data->map_x = 500;
	data->map_y = 500;
	data->x = 0;
	data->lock = 0;
	data->iter_max = 50;
	data->zoom = 200;
	data->c = 0;
	data->img_x = (data->x2 - data->x1) * data->zoom;
	data->img_y = (data->y2 - data->y1) * data->zoom;
	data->white[0] = 255;
	data->white[1] = 255;
	data->white[2] = 255;
}
