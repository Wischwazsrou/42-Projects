/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 17:48:57 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/02/10 12:50:10 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_map			*init_map(void)
{
	t_map	*new;

	if ((new = (t_map *)malloc(sizeof(*new))) == NULL)
		ft_error(-1);
	new->next = NULL;
	return (new);
}

void			img_init(t_gps *gps)
{
	if ((gps->img.adr =
			mlx_new_image(gps->mlx, gps->map_x, gps->map_y)) == NULL)
		ft_error(-1);
	if ((gps->img.img = mlx_get_data_addr(gps->img.adr, &gps->img.bpp,
			&gps->img.sl, &gps->img.endian)) == NULL)
		ft_error(-1);
}

static void		adapt_options(t_data *data, t_gps *gps)
{
	gps->map_x = 1200;
	gps->map_y = 1000;
	if (data->lenght_line > 50 &&
			data->lenght_line < 90)
	{
		data->scale = 5;
		data->h = 5;
	}
	else if (data->lenght_line >= 0 &&
			data->lenght_line <= 50)
	{
		data->scale = 30;
		data->h = 10;
	}
	else
	{
		data->scale = 2;
		data->h = 1;
	}
	data->origine_x = 300;
	data->origine_y = -250;
}

int				main(int argc, char **argv)
{
	t_gps	gps;
	t_data	data;

	if (argc != 2)
		ft_error(-1);
	how_does_it_look_like(argv[1], &data);
	adapt_options(&data, &gps);
	if ((gps.mlx = mlx_init()) == NULL)
		ft_error(-1);
	if ((gps.win = mlx_new_window(gps.mlx, gps.map_x, gps.map_y,
			"J'suis la carte")) == NULL)
		ft_error(-1);
	img_init(&gps);
	mlx_hook(gps.win, 2, 1, my_key_funct, &gps);
	gps.data = &data;
	color_s(&data);
	take_your_fucking_map(&gps);
	mlx_put_image_to_window(gps.mlx, gps.win, gps.img.adr, 0, 0);
	how_to_use_it(&gps);
	mlx_loop(gps.mlx);
}
