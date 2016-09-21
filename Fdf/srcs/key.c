/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 12:13:52 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/02/10 12:50:23 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			my_key_funct(int k, t_gps *gps)
{
	t_data	*data;

	data = gps->data;
	data->h = k == 69 ? data->h + 1 : data->h + 0;
	data->h = k == 78 ? data->h - 1 : data->h - 0;
	data->scale = k == 88 ? data->scale + 1 : data->scale + 0;
	data->scale = k == 92 && data->scale > 1 ?
		data->scale - 1 : data->scale - 0;
	data->origine_y = k == 123 ? data->origine_y + 20 : data->origine_y + 0;
	data->origine_y = k == 124 ? data->origine_y - 20 : data->origine_y - 0;
	data->origine_y = k == 125 ? data->origine_y + 20 : data->origine_y + 0;
	data->origine_x = k == 125 ? data->origine_x + 20 : data->origine_x + 0;
	data->origine_y = k == 126 ? data->origine_y - 20 : data->origine_y - 0;
	data->origine_x = k == 126 ? data->origine_x - 20 : data->origine_x + 0;
	mlx_clear_window(gps->mlx, gps->win);
	mlx_destroy_image(gps->mlx, gps->img.adr);
	img_init(gps);
	take_your_fucking_map(gps);
	mlx_put_image_to_window(gps->mlx, gps->win, gps->img.adr, 0, 0);
	how_to_use_it(gps);
	if (k == 53)
		exit(0);
	return (0);
}
