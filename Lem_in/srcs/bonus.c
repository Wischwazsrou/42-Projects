/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 19:11:59 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/06/09 19:12:00 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	check_bonus(int ac, char **av, t_data *data)
{
	int i;

	i = 1;
	while (i < ac)
	{
		data->color = ft_strcmp(av[i], "-c") == 0 ? 1 : data->color;
		data->show_moves = ft_strcmp(av[i], "-m") == 0 ? 1 : data->show_moves;
		data->show_coups = ft_strcmp(av[i], "-v") == 0 ? 1 : data->show_coups;
		data->show_path = ft_strcmp(av[i], "-p") == 0 ? 1 : data->show_path;
		i++;
	}
}

void	print_bonus(t_path **solution, t_data *data)
{
	int i;

	i = 0;
	ft_putchar('\n');
	if (data->show_moves == 1)
		while (i < data->solution)
		{
			ft_printf("Solution %d : %d move(s) has been done.\n",
						i + 1, data->moves[i]);
			i++;
		}
	i = 0;
	if (data->show_path == 1)
		while (solution[i])
		{
			ft_printf("Path %d : ", i + 1);
			while (solution[i]->next != NULL)
			{
				ft_printf("%s->", solution[i]->room);
				solution[i] = solution[i]->next;
			}
			ft_printf("%s\n", solution[i++]->room);
		}
	if (data->show_coups == 1)
		ft_printf("Nombre de coups : %d\n", data->coups);
}

void	print_options(void)
{
	ft_printf("\nYou can choose some options to see more details.\n");
	ft_printf("\t-c : To put some colors.\n");
	ft_printf("\t-v : To see in how many moves all the ants ended\n");
	ft_printf("\t-p : To see more clearly the paths of each solutions.\n");
	ft_printf("\t-m : To see how many moves each solutions has done.\n\n");
}
