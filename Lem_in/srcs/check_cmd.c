/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 20:16:04 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/08/22 21:32:14 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_isroom(char **tab_line)
{
	if (ft_tab_len_max(tab_line, 3))
	{
		if (ft_strisdigit(tab_line[1]) && ft_strisdigit(tab_line[2]))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int		ft_pass_comment(char **tab_room, int i)
{
	while (tab_room[i] && tab_room[i][0] == '#' &&
			(ft_strcmp(tab_room[i], "##end") != 0)
				&& (ft_strcmp(tab_room[i], "##start") != 0))
		i++;
	return (i);
}

int		check_cmd1(t_c_file *c_file, char **tab_room, int i)
{
	if (ft_strcmp(tab_room[i], "##start") == 0)
	{
		if (c_file->start_count > 1)
			ft_error(-1);
		if (!(tab_room[++i]))
			ft_error(-1);
		i = ft_pass_comment(tab_room, i);
		c_file->tab_line = ft_strsplit(tab_room[i], ' ');
		if (!(ft_isroom(c_file->tab_line)))
			ft_error(-1);
	}
	else if (ft_strcmp(tab_room[i], "##end") == 0)
	{
		if (c_file->end_count > 1)
			ft_error(-1);
		if (!(tab_room[++i]))
			ft_error(-1);
		i = ft_pass_comment(tab_room, i);
		c_file->tab_line = ft_strsplit(tab_room[i], ' ');
		if (!(ft_isroom(c_file->tab_line)))
			ft_error(-1);
	}
	return (i);
}

int		check_cmd2(t_c_file *c_file, char **tab_room, int i)
{
	if (ft_strcmp(tab_room[i], "##start") == 0)
	{
		c_file->start_count++;
		i = check_cmd1(c_file, tab_room, i);
	}
	else if (ft_strcmp(tab_room[i], "##end") == 0)
	{
		c_file->end_count++;
		i = check_cmd1(c_file, tab_room, i);
	}
	i++;
	return (i);
}

char	**check_cmd3(t_c_file *c_file, char **tab_room, int i)
{
	while (tab_room[i])
	{
		i = ft_pass_comment(tab_room, i);
		if (tab_room[i] == NULL)
			break ;
		c_file->tab_line = ft_strsplit(tab_room[i], '-');
		if (ft_tab_len_max(c_file->tab_line, 2))
			i++;
		else
			tab_room[i] = NULL;
	}
	return (tab_room);
}
