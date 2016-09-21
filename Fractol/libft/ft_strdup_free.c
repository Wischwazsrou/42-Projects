/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:12:50 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/12/17 14:23:20 by ffrimpon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup_free(const char *str)
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
	free((void *)str);
	return (cpy_str);
}
