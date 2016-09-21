/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 20:07:21 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/08/22 21:29:51 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	init_file(t_c_file *c_file)
{
	c_file->line = ft_strnew(1);
	c_file->start_count = 0;
	c_file->end_count = 0;
	c_file->tab_line = ft_strsplit(c_file->line, ' ');
}

int		ft_tab_len_max(char **tab_line, int length_max)
{
	int	length;

	length = 0;
	while (tab_line[length])
		length++;
	if (length != length_max)
		return (0);
	else
		return (1);
}

char	**check_tab_room(char **tab_room)
{
	t_c_file	*c_file;
	int			i;

	i = 1;
	if (!(c_file = (t_c_file *)malloc(sizeof(t_c_file) * 1)))
		return (NULL);
	init_file(c_file);
	if ((ft_strisdigit(tab_room[0])) == 0)
		ft_error(-1);
	while (tab_room[i])
	{
		c_file->tab_line = ft_strsplit(tab_room[i], ' ');
		if (tab_room[i][0] == '#'
				|| ft_isroom(c_file->tab_line))
			i = check_cmd2(c_file, tab_room, i);
		else
		{
			tab_room = check_cmd3(c_file, tab_room, i);
			break ;
		}
	}
	if (c_file->start_count != 1 || c_file->end_count != 1)
		ft_error(-1);
	return (tab_room);
}
