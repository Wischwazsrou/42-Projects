/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:22:32 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/12/04 20:04:41 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char	*copy_motherfucker(char *tetriminos, char *tetra_box)
{
	int i;

	i = 0;
	while (tetriminos[i] != '\0')
	{
		tetra_box[i] = tetriminos[i];
		i++;
	}
	tetra_box[i] = '\0';
	return (tetra_box);
}

char	**give_me_tetra(char *av, char **tetra_box)
{
	size_t	i;
	int		fd;
	char	tetriminos[BUF_SIZE];
	int		ret;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, tetriminos, BUF_SIZE)))
	{
		tetriminos[ret] = '\0';
		tetra_box[i] = copy_motherfucker(tetriminos, tetra_box[i]);
		i++;
	}
	if (close(fd) == -1)
		return (0);
	return (tetra_box);
}

char	**feed_me_pliizzz(char **no_go_zone, size_t size, size_t x, size_t y)
{
	while (y < size - 1)
	{
		while (x < size - 1)
		{
			no_go_zone[y][x] = '.';
			x++;
		}
		no_go_zone[y][x] = '\0';
		x = 0;
		y++;
	}
	if (y == size - 1)
	{
		while (x < size - 1)
		{
			no_go_zone[y][x] = '\0';
			x++;
		}
		y++;
	}
	return (no_go_zone);
}

size_t	opti_size_box(size_t nbr_tetr)
{
	unsigned int	nbr_case;
	unsigned int	i;

	nbr_case = nbr_tetr * 4;
	i = 2;
	while (i * i < nbr_case)
		i++;
	return (i);
}

char	**alloc_me_pliizzz(size_t size)
{
	char	**no_go_zone;
	size_t	i;

	i = 0;
	if (!(no_go_zone = (char **)malloc((size + 1) * (sizeof(char*)))))
		return (NULL);
	while (i < size && size <= 26)
	{
		if (!(no_go_zone[i] = (char *)malloc(BUF_SIZE * (sizeof(char)))))
			return (NULL);
		i++;
	}
	if (size > 26)
	{
		size = size - 26;
		while (i < size)
		{
			if (!(no_go_zone[i] = (char *)malloc((size + 1) * (sizeof(char)))))
				return (NULL);
			i++;
		}
		no_go_zone = feed_me_pliizzz(no_go_zone, size, 0, 0);
	}
	return (no_go_zone);
}
