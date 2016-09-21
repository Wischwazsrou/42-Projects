/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:28:44 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/12/17 14:16:06 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin_free(const char *str1, const char *str2)
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
	free((void *)str1);
	dest[i] = '\0';
	return (dest);
}
