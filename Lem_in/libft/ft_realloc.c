/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:28:10 by ffrimpon          #+#    #+#             */
/*   Updated: 2016/06/17 20:26:00 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloc(char **tab, int size)
{
	int		i;
	int		j;
	char	**new_tab;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	new_tab = (char **)malloc(sizeof(char *) * (i + size + 1));
	while (j < i)
	{
		new_tab[j] = tab[j];
		j++;
	}
	new_tab[j] = NULL;
	free(tab);
	return (new_tab);
}
