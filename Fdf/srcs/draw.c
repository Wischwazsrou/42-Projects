/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 12:12:31 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/02/10 12:51:24 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	img_pixel_put(t_gps *gps, int x, int y, t_map *map)
{
	int	pos;

	if ((x < gps->map_x && y < gps->map_y && x >= 0 && y >= 0))
	{
		pos = (x * gps->img.bpp / 8) + (y * gps->img.sl);
		gps->img.img[pos] = map->color_b;
		gps->img.img[pos + 1] = map->color_g;
		gps->img.img[pos + 2] = map->color_r;
	}
}

void	draw_me_one_line(t_gps *gps, t_data *data, t_map *map)
{
	data->dh = gps->x_b - gps->x_a;
	data->dl = gps->y_b - gps->y_a;
	data->c = -1;
	data->m = abs(data->dh) > abs(data->dl) ? abs(data->dh) : abs(data->dl);
	while (++data->c < data->m)
		img_pixel_put(gps, gps->x_a + data->c * data->dh / data->m,
				gps->y_a + data->c * data->dl / data->m, map);
}

void	how_to_use_it(t_gps *gps)
{
	mlx_string_put(gps->mlx, gps->win, 10, 10, 0xFFFFFF,
			"9 / 6 : Zoom / Dezoom");
	mlx_string_put(gps->mlx, gps->win, 10, 30, 0xFFFFFF,
			"+ / - : + hateur / - hauteur");
	mlx_string_put(gps->mlx, gps->win, 10, 50, 0xFFFFFF,
			"up / down : Monter / Descendre");
	mlx_string_put(gps->mlx, gps->win, 10, 70, 0xFFFFFF,
			"left / right : Gauche / Droite");
}
