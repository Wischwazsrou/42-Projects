/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 15:22:27 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/20 15:32:06 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "stdlib.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_img
{
	void			*adr;
	char			*img;
	int				bpp;
	int				sl;
	int				endian;
}					t_img;

typedef struct		s_data
{
	float			mouse_x;
	float			mouse_y;
	void			*mlx;
	void			*win;
	int				map_x;
	int				map_y;
	float			x;
	float			y;
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	float			zoom;
	float			iter_max;
	float			img_x;
	float			img_y;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	float			i;
	float			tmp;
	int				c;
	int				angle;
	int				dep;
	int				depth_max;
	int				*white;
	int				fractal;
	int				lock;
	t_img			img;
}					t_data;

void				init_mlx(t_data *data);
void				draw_line(t_data *data, int x, int y);
void				img_pixel_put(t_data *data, int x, int y, int *color);
void				img_init(t_data *data);
void				mandelbrot(t_data *data);
void				julia(t_data *data);
void				galaxy(t_data *data);
void				burningship(t_data *data);
void				tree(t_data *data);
void				mandel_process(t_data *data);
void				julia_process(t_data *data);
void				galaxy_process(t_data *data);
void				burning_process(t_data *data);
void				tree_process(t_data *data);
void				data_mandel(t_data *data);
void				data_julia(t_data *data);
void				data_galaxy(t_data *data);
void				data_burning(t_data *data);
void				data_tree(t_data *data);
void				ft_error(int i);
void				draw(t_data *data);
void				global_data(t_data *data);
int					mouse_zoom(int click, int x, int y, t_data *data);
int					my_key_funct(int k, t_data *data);
int					*color(int i, int inter_max, t_data *data);
int					my_mouse_funct(int x, int y, t_data *data);
int					expose_hook(t_data *data);
int					move(t_data *data);

#endif
