/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 23:08:46 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/12/16 12:35:29 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * (sizeof(char)));
	if (dest == 0)
		return (NULL);
	while (str1[i] != '\0')
	{
		dest[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		dest[i] = str2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
