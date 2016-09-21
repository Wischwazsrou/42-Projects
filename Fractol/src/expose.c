/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 12:56:37 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/02/22 12:56:38 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		expose_hook(t_data *data)
{
	img_init(data);
	if (data->fractal == 1)
		mandel_process(data);
	if (data->fractal == 2)
		julia_process(data);
	if (data->fractal == 3)
		burning_process(data);
	if (data->fractal == 4)
		tree_process(data);
	if (data->fractal == 5)
		galaxy_process(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.adr, 0, 0);
	return (0);
}

int		move(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	expose_hook(data);
	return (0);
}
