/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 00:00:03 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/12/11 11:26:30 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		check_line(char *tetri)
{
	int i;

	i = 0;
	while (tetri[i] != 0)
	{
		if ((i == 4 || i == 9 || i == 14 || i == 19) && tetri[i] != '\n')
			return (0);
		if (tetri[i] != '.' && tetri[i] != '\n' && tetri[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

int		check_placement(char *tetri)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetri[i] != 0)
	{
		if (tetri[i] == '#' && tetri[i + 1] == '#')
			j++;
		if (tetri[i] == '#' && tetri[i - 1] == '#')
			j++;
		if (tetri[i] == '#' && tetri[i + 5] == '#')
			j++;
		if (tetri[i] == '#' && tetri[i - 5] == '#')
			j++;
		i++;
	}
	if (j >= 6)
		return (1);
	return (0);
}

int		check_d(char *tetri)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetri[i] != 0)
	{
		if (tetri[i] == '#')
			j++;
		i++;
	}
	if (j == 4)
		return (1);
	return (0);
}

int		you_shall_not_pass(char **tetra_box, size_t n_tetra)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (i < n_tetra)
	{
		if ((ft_strlen(tetra_box[i]) == 20 && i == n_tetra - 1)
			|| (ft_strlen(tetra_box[i]) == 21 && i != n_tetra - 1))
		{
			if (check_line(tetra_box[i]) == 1)
			{
				if (check_d(tetra_box[i]) == 1)
				{
					if (check_placement(tetra_box[i]) == 1)
						j++;
				}
			}
		}
		i++;
	}
	if (j == n_tetra)
		return (1);
	free(tetra_box);
	return (0);
}
