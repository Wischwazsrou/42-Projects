/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:45:28 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/11/30 21:30:28 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*cpy_str;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str);
	cpy_str = (char*)malloc((j + 1) * sizeof(str));
	if (cpy_str == 0)
		return (NULL);
	if (cpy_str != '\0')
	{
		while (str[i] != '\0')
		{
			cpy_str[i] = str[i];
			i++;
		}
	}
	cpy_str[i] = '\0';
	return (cpy_str);
}
