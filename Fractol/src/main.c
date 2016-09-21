/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 15:25:21 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/03/20 15:25:23 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_error(int i)
{
	if (i == 1)
	{
		ft_putendl("Veuillez mettre l'un des arguments suivant : julia");
		ft_putendl("                                             mandelbrot");
		ft_putendl("                                             burningship");
		ft_putendl("                                             tree");
		ft_putendl("                                             galaxy");
	}
	if (i == 2)
		ft_putendl("error in mandelbrot()");
	if (i == -1)
		ft_putendl("error mlx_init");
	exit(1);
}

int		main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
		ft_error(1);
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		mandelbrot(&data);
	else if (ft_strcmp(argv[1], "julia") == 0)
		julia(&data);
	else if (ft_strcmp(argv[1], "burningship") == 0)
		burningship(&data);
	else if (ft_strcmp(argv[1], "tree") == 0)
		tree(&data);
	else if (ft_strcmp(argv[1], "galaxy") == 0)
		galaxy(&data);
	else
		ft_error(1);
	free(data.white);
	return (0);
}
